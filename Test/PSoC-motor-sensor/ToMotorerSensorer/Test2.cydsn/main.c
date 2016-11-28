#include "project.h"
#include <stdio.h>

uint8 xStep = 0b1100; // Start position for motor - global variable
uint8 yStep = 0b1100; // Start position for motor - global variable
uint16 xStepCount = 0;
uint16 yStepCount = 0;
uint8 xStop = 0;
uint8 yStop = 0;
uint8 enabled = 0;
uint8 status;

int8 locateX();
int8 locateY();
void reset();
void motorRunLeft(uint8);
void motorRunRight(uint8);
void updateStatus(uint8);

enum SPI_protocol {
    
    // Commands from PSoC-master to -slave
    GET_STATUS = 0x00,
    LOCATE_XY = 0x01,
    RESET = 0x05,
    
    // Feedback messages from PSoC-slave to -master
    VALID_XY = 0x10,
    INVALID_XY = 0x20,
    RESET_XY_ON_SUCCESS = 0x35, // Only if bottle has been opened
    INVALID_TYPE = 0x21,
    NO_BOTTLE = 0x22,
    DEFAULT = 0x30,
    WRONG_COMMAND = 0x31,
    IN_PROCESS = 0x33,
};

enum bottleInfo {
    MIN_WIDTH = 2,      // Random value
    MAX_WIDTH = 5,      // Random value
    OFF_EDGE = 10,      // Random value
};

enum voltageBoundary {
    LOW = 72,          // Random value
};

enum axes {
    X = 0,
    Y = 1,
};

enum operation {
    SEARCH_XY = 1,
    RESET_AXES = 5,
};

CY_ISR(isr_RxD)
{
    uint8 rxCmd;
    
    rxCmd = UART_1_ReadRxData();
    UART_1_ClearRxBuffer();
    
    rxCmd -= 0x30;
    
    switch(rxCmd) {
        
        // Write status of bottle to master-PSoC
		case GET_STATUS:
			updateStatus(status);
			break;
        
        // Find centre of bottle
		case LOCATE_XY:
            enabled = SEARCH_XY;
			break;
        
        // Position x- and y-sensor to start-positions on respectively x- and y-axes
        case RESET:
            enabled = RESET_AXES;
            break;
        
        // Unidentified command
        default:
            updateStatus(WRONG_COMMAND);
            break;
    }
}

/*CY_ISR(isr_x)
{
    xStop = 1;
    Pin_int_x_ClearInterrupt();
}

CY_ISR(isr_y)
{
    yStop = 1;
    Pin_int_y_ClearInterrupt();
}*/

uint8 rotateRight(uint8 step)      // Shifter bit en til højre
{
    return  (step >> 1) | ( (step << 3) & 15);
}

uint8 rotateLeft(uint8 step)      // Shifter bit en til venstre
{
    return  (step >> 3) | ( (step << 1) & 15);
}


int main()
{
    updateStatus(DEFAULT);
    CyGlobalIntEnable;

    UART_1_Start();
    isr_RxD_StartEx(isr_RxD);
    //isr_x_StartEx(isr_x);
    //isr_y_StartEx(isr_y);

    for(;;)
    {
        switch(enabled) {
            
            // Find centre of bottle
            case SEARCH_XY:
                updateStatus(IN_PROCESS);
                
                // Locate bottle on x-axis - discontinue search on failure
                if(locateX()) {
                    break;
                }
                
                // Locate bottle on y-axis - update status on success
                if(!locateY()) {
                    updateStatus(VALID_XY);
                }
                break;
            
            // Reset to start-position
            case RESET_AXES:
                updateStatus(IN_PROCESS);
                reset();
                break;
            
            default:
                break;
        }
        enabled = 0;
    }
    
    return 0;
}

// Find mid-point of bottle on x-axis
int8 locateX()
{
    uint32 ADCResultX;
    uint8 i;
    uint16 xPosRight;
    uint16 xPosLeft;
    uint16 xWidth;
    
    // Start sensor
    ADC_SAR_Seq_Start();
    ADC_SAR_Seq_StartConvert();
    ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_WAIT_FOR_RESULT);
    
    // Find right edge of bottle
    do {
        ADCResultX = ADC_SAR_Seq_GetResult16(X);
        UART_1_WriteTxData(ADCResultX);
        ADCResultX = ADC_SAR_Seq_CountsTo_mVolts(ADCResultX);
        UART_1_WriteTxData(ADCResultX);
        motorRunLeft(X);
    } while(1);
    
    // Save position
    xPosRight = xStepCount;
    
    // Find left edge of bottle
    do {
        ADCResultX = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(X));
        motorRunLeft(X);
    } while(ADCResultX > LOW);
    
    // Save position
    xPosLeft = xStepCount;
    
    // Stop sensor
    ADC_SAR_Seq_Stop();
    
    // Calculate no. of steps to centre of bottle
    xWidth = (xPosLeft - xPosRight)/2;
    
    // Find centre of bottle
    for(i = xWidth; i > 0; --i) {
        motorRunRight(X);
    }
    
    // Success
    return 0;
}

// Find mid-point of bottle on y-axis
int8 locateY()
{
    uint16 ADCResultY;
    uint8 i;
    uint16 yPosRight;
    uint16 yPosLeft;
    uint16 yWidth;
    
    // Start sensor
    ADC_SAR_Seq_Start();
    ADC_SAR_Seq_StartConvert();
    ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_WAIT_FOR_RESULT);
    
    // Find right edge of bottle
    do {
        ADCResultY = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(Y));
        motorRunLeft(Y);
    } while(ADCResultY < LOW);
    
    // Save position
    yPosRight = yStepCount;
    
    // Find left edge of bottle
    do {
        ADCResultY = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(Y));
        motorRunLeft(Y);
    } while(ADCResultY > LOW);
    
    // Save position
    yPosLeft = yStepCount;
    
    // Stop sensor
    ADC_SAR_Seq_Stop();
    
    // Calculate no. of steps to centre of bottle
    yWidth = (yPosLeft - yPosRight)/2;
    
    // Find centre of bottle
    for(i = yWidth; i > 0; --i) {
        motorRunRight(Y);
    }
    
    // Success
    return 0;
}

void reset()
{
    /*uint8 i;
    
    for(i = yStepCount; i > 0; --i) {
        motorRunRight(Y);
    }
    
    for(i = xStepCount; i > 0; --i) {
        motorRunRight(X);
    }*/
    
    while(!yStop) {
        motorRunRight(Y);
    }
    
    while(!xStop) {
        motorRunRight(X);
    }
    
    xStop = 0;
    yStop = 0;
    
    updateStatus(RESET_XY_ON_SUCCESS);
}

void motorRunLeft(uint8 axis)
{
    int i;
    if(axis == X) {
        for(i = 0; i < 10; ++i) {               // Value 10 chosen arbitrarily
            xStep = rotateLeft(xStep);
            Coils_X_Write(xStep);               // Skriver til pins fra TopDesign (Coils)
            CyDelay(2);
        }
        ++xStepCount;
    }
    else {
        for(i = 0; i < 10; ++i) {               // Value 10 chosen arbitrarily
            yStep = rotateLeft(yStep);
            Coils_Y_Write(yStep);               // Skriver til pins fra TopDesign (Coils)
            CyDelay(2);
        }
        ++yStepCount;
    }
}

void motorRunRight(uint8 axis)
{
    int i;
    if(axis == X) {
        for(i = 0; i < 10; ++i) {               // Value 10 chosen arbitrarily
            xStep = rotateRight(xStep);
            Coils_X_Write(xStep);               // Skriver til pins fra TopDesign (Coils)
            CyDelay(2);
        }
        --xStepCount;
    }
    else {
        for(i = 0; i < 10; ++i) {               // Value 10 chosen arbitrarily
            yStep = rotateRight(yStep);
            Coils_Y_Write(yStep);               // Skriver til pins fra TopDesign (Coils)
            CyDelay(2);
        }
        --yStepCount;
    }
}

// Update status of slave-PSoC/message to be sent to master-PSoC
void updateStatus(uint8 stat)
{
    status = stat;
    UART_1_ClearTxBuffer();
    UART_1_WriteTxData(status);
}
