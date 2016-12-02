#include "project.h"
#include <stdio.h>


uint8 xStep = 0b1100; // Start position for motor - global variable
uint8 yStep = 0b1100; // Start position for motor - global variable
uint16 xStepCount = 0;
uint16 yStepCount = 0;
uint8 xStop = 0;
uint8 yStop = 0;
uint8 zStop = 0;
uint16 screwCount = 0;
uint16 openCount = 0;
uint8 enabled = 0x30;
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
    
    // Commands from DK8k to PSoC
    GET_STATUS      = 0x00,
    LOCATE_BOTTLE   = 0x01,
    OPEN_BOTTLE     = 0x02,
    
    // Feedback messages from PSoC-master to DK8k
    VALID_TYPE      = 0x10,
    READY_TO_DRINK  = 0x12,
    INVALID_TYPE    = 0x20,
    NO_BOTTLE       = 0x21,
    DEFAULT         = 0x30,
    WRONG_COMMAND   = 0x31,
    WRONG_DEVICE    = 0x32,
    IN_PROCESS      = 0x33,
};

enum bottleInfo {
    MIN_WIDTH       = 2,        // Random value
    MAX_WIDTH       = 5,        // Random value
    OFF_EDGE        = 10,       // Random value
    SCREW_THROUGH   = 100,      // Random value
    OPENED          = 100,      // Random value
};

enum voltageBoundary {
    LOW             = 100,      // Output voltage from sensor when not detecting an object
};

enum axes {
    X               = 0,
    Y               = 1,
    Z               = 2,
};

enum operation {
    MOTOR_RUN       = 0,
    MOTOR_STOP      = 1,
};

enum dir {
    FW              = 0,
    BW              = 1,
};

CY_ISR(isr_1)
{
    uint16 rxvalue;
	uint8 cmd;
	uint8 addr;
    
    rxvalue = SPIS_1_ReadRxData(); // This also clears Rx Status Register
    SPIS_1_ClearRxBuffer();
    
    /* Protocol - Write 8-bit: 
	 * |CMD|  ADDR  |    DATA    |
	 *  1 1 1      8 7          0
	 *	5 4 3
	 */

	/* Protocol - Read 16-bit: 
	 * |CMD|  ADDR  |  Not Used  |       |           DATA          |
	 *  1 1 1      8 7          0         1                       0
	 *	5 4 3                             5
	 */
    
    cmd = (rxvalue >> 14) & 0x3;  // cmd = rdvalue[15:14]
	addr = (rxvalue >> 8) & 0x3f; // addr = rdvalue[13:8]
    
    switch (addr) {
		case 0x01:
			switch(cmd) {
                
                // Write status of bottle to DK8k
				case GET_STATUS:
					updateStatus(status);
                    
                    if(status != IN_PROCESS || status != VALID_TYPE) {
                        status = DEFAULT;
                    }
					break;
                
                // Registrate bottle
				case LOCATE_BOTTLE:
                    updateStatus(IN_PROCESS);
                    
                    // Validate thickness of bottle neck
                    enabled = cmd;
					break;
                
                // Open bottle
                case OPEN_BOTTLE:
                    updateStatus(IN_PROCESS);
                    
                    // Open bottle
                    enabled = cmd;
                    break;
                
                // Unidentified command
                default:
                    updateStatus(WRONG_COMMAND);
                    break;
            }
			break;
        
        // Unidentified address
		default:
			updateStatus(WRONG_DEVICE);
			break;
	}
}

int main()
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
            case LOCATE_BOTTLE:
                updateStatus(IN_PROCESS);
                
                if(locateX() || locateY()) {
                    updateStatus(INVALID_TYPE);
                    reset();
                    enabled = DEFAULT;
                    break;
                }
                
        }           
    }
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
    Direction_1_Write(FW);
    Enable_1_Write(MOTOR_RUN);
    do {
        ADCResultX = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(X));
        CyDelay(25);
        xStepCount++;
    } while((ADCResultX < LOW) && (xStepCount < OFF_EDGE));
    
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

void reset(uint8 axis)
{
    
    Direction_1_Write(BW);
    Enable_1_Write(0);
    
    // Wait for interrupt - z_home
    while(!zStop) {}
    
    // Wait for interrupt - y_home
    while(!yStop) {
        motorRunRight(Y);
    }
    
    // Wait for interrupt - x_home
    while(!xStop) {
        motorRunRight(X);
    }
    
    xStop = 0;
    yStop = 0;
    zStop = 0;
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

// Update status of master-PSoC/message to be sent to DK8k
void updateStatus(uint8 stat)
{
    status = stat;
    SPIS_1_ClearTxBuffer();
    SPIS_1_WriteTxData(status);
}

/* [] END OF FILE */
