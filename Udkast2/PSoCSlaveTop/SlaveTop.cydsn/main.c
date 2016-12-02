#include "project.h"

uint8 xStep = 0b1100; // Start position for motor - global variable
uint8 yStep = 0b1100; // Start position for motor - global variable
uint16 xStepCount = 0;
uint16 yStepCount = 0;
uint8 xStop = 0;
uint8 yStop = 0;
uint16 screwCount = 0;
uint16 openCount = 0;
uint8 enabled = 0;
uint8 screwDirection;
uint8 openDirection;
uint8 status;

int8 locateX();
int8 locateY();
void openBottle();
void reset();
void dispenseCork();
void motorRunLeft(uint8);
void motorRunRight(uint8);
void updateStatus(uint8);

enum SPI_protocol {
    
    // Commands from PSoC-master to -slave
    GET_STATUS = 0x00,
    LOCATE_XY = 0x01,
    LOCATE_Z_1 = 0x02,
    LOCATE_Z_2 = 0x03,
    OPEN_BOTTLE = 0x04,
    RESET = 0x05,
    DISPENSE_CORK = 0x06,
    
    // Feedback messages from PSoC-slave to -master
    VALID_XY = 0x10,
    INVALID_XY = 0x20,
    RESET_XY_ON_SUCCESS = 0x35, // Only if bottle has been opened
    VALID_Z = 0x13,
    VALID_TYPE = 0x14,
    INVALID_TYPE = 0x21,
    NO_BOTTLE = 0x22,
    OPENING_SUCCESSFUL = 0x15,
    CORK_DISPENSED = 0x16,
    DEFAULT = 0x30,
    WRONG_COMMAND = 0x31,
    IN_PROCESS = 0x33,
};

enum bottleInfo {
    MIN_WIDTH = 2,          // Random value
    MAX_WIDTH = 5,          // Random value
    OFF_EDGE = 10,          // Random value
    SCREW_THROUGH = 100,    // Random value
    OPENED = 100,           // Random value
};

enum voltageBoundary {
    LOW = 72,          // Output voltage from sensor when not detecting an object
};

enum axes {
    X = 0,
    Y = 1,
};

enum operation {
    SEARCH_XY = 1,
    SEARCH_Z_1 = 2,
    SEARCH_Z_2 = 3,
    OPEN = 4,
    RESET_AXES = 5,
    DISPENSE = 6,
};

enum dir
{
    FW = 0,
    BW = 1,
};

CY_ISR(isr_1)
{
    uint8 cmd;
    
    cmd = SPIS_1_ReadRxData(); // This also clears Rx Status Register
    SPIS_1_ClearRxBuffer();
    
	switch(cmd) {
        
        // Write status of bottle to master-PSoC
		case GET_STATUS:
			updateStatus(status);
			break;
        
        // Find centre of bottle
		case LOCATE_XY:
            enabled = SEARCH_XY;
			break;
        
        // Check that top of bottle is detected
        case LOCATE_Z_1:
            enabled = SEARCH_Z_1;
            break;
        
        // Check that top of bottle is not detected 
        case LOCATE_Z_2:
            enabled = SEARCH_Z_2;
            break;
        
        // Open bottle
        case OPEN_BOTTLE:
            enabled = OPEN;
            break;
        
        // Position x- and y-sensor to start-positions on respectively x- and y-axes
        case RESET:
            enabled = RESET_AXES;
            break;
        
        // Dispense of cork
        case DISPENSE_CORK:
            enabled = DISPENSE;
            break;
        
        // Unidentified command
        default:
            updateStatus(WRONG_COMMAND);
            break;
    }
}

CY_ISR(pwm_isr_1)
{
    PWM_1_ReadStatusRegister();
    uint8 step;
    step = stepindex_1_Read();
    if(screwDirection == FW) {
        if(step >= 0x03) {
            stepindex_1_Write(0);
        }
        else {
            stepindex_1_Write(step + 1);
        }
        ++screwCount;
    }
    else { //direction == BW
        if(step <= 0) {
            stepindex_1_Write(0x03);
        }
        else {
            stepindex_1_Write(step-1);
        }
        --screwCount;
    }
}

CY_ISR(pwm_isr_2)
{
    PWM_2_ReadStatusRegister();
    uint8 step;
    step = stepindex_2_Read();
    if(openDirection == FW) {
        if(step >= 0x03) {
            stepindex_2_Write(0);
        }
        else {
            stepindex_2_Write(step + 1);
        }
        ++openCount;
    }
    else { //direction == BW
        if(step <= 0) {
            stepindex_2_Write(0x03);
        }
        else {
            stepindex_2_Write(step-1);
        }
        --openCount;
    }
}

CY_ISR(isr_x)
{
    xStop = 1;
    Pin_int_x_ClearInterrupt();
}

CY_ISR(isr_y)
{
    yStop = 1;
    Pin_int_y_ClearInterrupt();
}

// Shifter bit en til højre
uint8 rotateRight(uint8 step)
{
    return  (step >> 1) | ( (step << 3) & 15);
}

// Shifter bit en til venstre
uint8 rotateLeft(uint8 step)
{
    return  (step >> 3) | ( (step << 1) & 15);
}

int main(void)
{
    updateStatus(DEFAULT);
    CyGlobalIntEnable;
    
    SPIS_1_Start();
	SPIS_1_EnableRxInt();
    isr_1_StartEx(isr_1);
	SPIS_1_ClearFIFO();
	SPIS_1_ClearTxBuffer();

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
            
            // Check that bottle is detected
            case SEARCH_Z_1:
                updateStatus(IN_PROCESS);
                
                // Start sensor
                ADC_SAR_Seq_Start();
                ADC_SAR_Seq_StartConvert();
                ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_WAIT_FOR_RESULT);
                
                // Bottle detected
                if(ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(X)) > LOW) {
                    updateStatus(VALID_Z);
                }
                
                // Invalid object inserted
                else {
                    updateStatus(INVALID_TYPE);
                }
                
                // Stop sensor
                ADC_SAR_Seq_Stop();
                break;
            
            // Check that bottle is not detected
            case SEARCH_Z_2:
                updateStatus(IN_PROCESS);
                
                // Start sensor
                ADC_SAR_Seq_Start();
                ADC_SAR_Seq_StartConvert();
                ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_WAIT_FOR_RESULT);
                
                // Bottle not detected
                if(ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(X)) < LOW) {
                    updateStatus(VALID_TYPE);
                }
                
                // Invalid object inserted
                else {
                    updateStatus(INVALID_TYPE);
                }
                
                // Stop sensor
                ADC_SAR_Seq_Stop();
                break;
            
            // Open bottle
            case OPEN:
                updateStatus(IN_PROCESS);
                openBottle();
                break;
            
            // Reset to start-position
            case RESET_AXES:
                updateStatus(IN_PROCESS);
                reset();
                break;
            
            // Dispense of cork
            case DISPENSE:
                updateStatus(IN_PROCESS);
                dispenseCork();
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
    uint16 ADCResultX;
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
        ADCResultX = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(X));
        motorRunLeft(X);
    } while((ADCResultX < LOW) || (xStepCount < OFF_EDGE));
    
    // Bottle not detected - stop sensor
    if(xStepCount >= OFF_EDGE) {
        ADC_SAR_Seq_Stop();
        updateStatus(NO_BOTTLE);
        return -1;
    }
    
    // Save position
    xPosRight = xStepCount;
    
    // Find left edge of bottle
    do {
        ADCResultX = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(X));
        motorRunLeft(X);
    } while((ADCResultX > LOW) || (xStepCount < OFF_EDGE));
    
    // Invalid object inserted - stop sensor
    if(xStepCount >= OFF_EDGE) {
        ADC_SAR_Seq_Stop();
        updateStatus(INVALID_TYPE);
        return -1;
    }
    
    // Save position
    xPosLeft = xStepCount;
    
    // Stop sensor
    ADC_SAR_Seq_Stop();
    
    // Calculate no. of steps to centre of bottle
    xWidth = (xPosLeft - xPosRight)/2;
    
    // Bottle of incorrect type
    if((2*xWidth < MIN_WIDTH) || (2*xWidth > MAX_WIDTH)) {
        updateStatus(INVALID_TYPE);
        return -1;
    }
    
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
    } while((ADCResultY < LOW) || (yStepCount < OFF_EDGE));
    
    // No bottle detected - stop sensor
    if(yStepCount >= OFF_EDGE) {
        ADC_SAR_Seq_Stop();
        updateStatus(NO_BOTTLE);
        return -1;
    }
    
    // Save position
    yPosRight = yStepCount;
    
    // Find left edge of bottle
    do {
        ADCResultY = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(Y));
        motorRunLeft(Y);
    } while((ADCResultY > LOW) || (yStepCount < OFF_EDGE));
    
    // Invalid object inserted - stop sensor
    if(yStepCount >= OFF_EDGE) {
        ADC_SAR_Seq_Stop();
        updateStatus(INVALID_TYPE);
        return -1;
    }
    
    // Save position
    yPosLeft = yStepCount;
    
    // Stop sensor
    ADC_SAR_Seq_Stop();
    
    // Calculate no. of steps to centre of bottle
    yWidth = (yPosLeft - yPosRight)/2;
    
    // Bottle of incorrect type
    if((2*yWidth < MIN_WIDTH) || (2*yWidth > MAX_WIDTH)) {
        updateStatus(INVALID_TYPE);
        return -1;
    }
    
    // Find centre of bottle
    for(i = yWidth; i > 0; --i) {
        motorRunRight(Y);
    }
    
    // Success
    return 0;
}

void openBottle()
{
    
    // Screw the cork
    screwDirection = FW;
    
    Enable_1_Write(1);
    
    PWM_1_Start();
    pwm_isr_1_StartEx(pwm_isr_1);
    stepindex_1_Write(1); //Start på 1, fordi fullstep.
    
    while(screwCount < SCREW_THROUGH) {}
    
    PWM_1_Stop();
    Enable_1_Write(0);
    
    // Open the bottle
    openDirection = FW;
    
    Enable_2_Write(1);
    
    PWM_2_Start();
    pwm_isr_2_StartEx(pwm_isr_2);
    stepindex_2_Write(1); //Start på 1, fordi fullstep.
    
    while(openCount < OPENED) {}
    
    PWM_2_Stop();
    Enable_2_Write(0);
    
    updateStatus(OPENING_SUCCESSFUL);
}

void reset()
{
    
    // Wait for interrupt
    while(!yStop) {
        motorRunRight(Y);
    }
    
    // Wait for interrupt
    while(!xStop) {
        motorRunRight(X);
    }
    
    xStop = 0;
    yStop = 0;
    
    if(status == OPENING_SUCCESSFUL) {
        updateStatus(RESET_XY_ON_SUCCESS);
    }
}

void dispenseCork()
{
    
    // Unscrew the cork
    screwDirection = BW;
    
    Enable_1_Write(1);
    
    PWM_1_Start();
    pwm_isr_1_StartEx(pwm_isr_1);
    stepindex_1_Write(1); //Start på 1, fordi fullstep.
    
    while(screwCount > 0) {}
    
    PWM_1_Stop();
    Enable_1_Write(0);
    
    // Reset cork-pulling mechanism
    openDirection = BW;
    
    Enable_2_Write(1);
    
    PWM_2_Start();
    pwm_isr_2_StartEx(pwm_isr_2);
    stepindex_2_Write(1); //Start på 1, fordi fullstep.
    
    while(openCount > 0) {}
    
    PWM_2_Stop();
    Enable_2_Write(0);
    
    updateStatus(CORK_DISPENSED);
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
    SPIS_1_ClearTxBuffer();
    SPIS_1_WriteTxData(status);
}

/* [] END OF FILE */
