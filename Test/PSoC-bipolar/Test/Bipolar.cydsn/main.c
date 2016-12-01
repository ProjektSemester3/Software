#include "project.h"

uint16 zStepCount = 0;
uint8 enabled = 0;
uint8 zDirection;

uint8 status;

void moveZ(uint8);
void reset();
void updateStatus(uint8);
int8 command = 1;

enum SPI_protocol {
    
    // Command from PSoC-master to -slave
    GET_STATUS = 0x00,
    LOCATE_Z_1 = 0x02,
    LOCATE_Z_2 = 0x03,
    RESET = 0x05,
    
    // Feedback messages from PSoC-slave to -master
    MOVED_Z_1 = 0x11,
    MOVED_Z_2 = 0x12,
    RESET_Z = 0x34,
    DEFAULT = 0x30,
    WRONG_COMMAND = 0x31,
    IN_PROCESS = 0x33,
};

enum bottleInfo {
    BELOW_TOP = 10,             // Random value
    ABOVE_TOP = 11,             // Random value
};

enum operation {
    POSITION_Z_1 = 1,
    STOP_1 = 2,
    POSITION_Z_2 = 5,
    RESET_AXIS = 3,
    STOP_2 = 4,
};

enum dir
{
    FW = 0,
    BW = 1,
};

CY_ISR(isr_RxD)
{
    uint8 rxCmd;
    
    rxCmd = UART_1_ReadRxData();
    
    if(command == STOP_1 || command == STOP_2) {
        Enable_1_Write(1);
    }
    else if(command == POSITION_Z_1) {
        Direction_1_Write(FW);
        Enable_1_Write(0);
    }
    else {
        Direction_1_Write(BW);
        Enable_1_Write(0);
    }
    //enabled = POSITION_Z_1;
    
    //enabled = command;
    command = (command % 4) + 1;
        
    //rxCmd -= 0x76;
    /*
	switch(rxCmd) {
        
        // Write status of bottle to master-PSoC
		case GET_STATUS:
			updateStatus(status);
			break;
        
        // Position x-sensor to just under top of bottle
        case LOCATE_Z_1:
            zDirection = FW;
            enabled = POSITION_Z_1;
            break;
        
        // Position x-sensor to just over top of bottle
        case LOCATE_Z_2:
            zDirection = FW;
            enabled = POSITION_Z_2;
            break;
        
        // Position x- and y-sensor to start-positions on respectively x- and y-axes
        case RESET:
            zDirection = BW;
            enabled = RESET_AXIS;
            break;
        
        // Unidentified command
        default:
            updateStatus(WRONG_COMMAND);
            break;
    }
    */
}

CY_ISR(pwm_isr_1)
{
    PWM_1_ReadStatusRegister();
    
    if(zDirection == FW) {
        ++zStepCount;
    }
    else { //direction == BW
        --zStepCount;
    }
}

int main(void)
{
    updateStatus(DEFAULT);
    CyGlobalIntEnable;

    UART_1_Start();
    isr_RxD_StartEx(isr_RxD);
    
    PWM_1_Start();
    //pwm_isr_1_StartEx(pwm_isr_1);
    //pwm_isr_1_Disable();
    enabled = DEFAULT;

    for(;;)
    {
        switch(enabled) {
            
            // Position x-sensor to just under top of bottle
            case POSITION_Z_1:
                updateStatus(IN_PROCESS);
                moveZ(BELOW_TOP);
                updateStatus(MOVED_Z_1);
                break;
            
            // Position x-sensor to just over top of bottle
            case POSITION_Z_2:
                updateStatus(IN_PROCESS);
                moveZ(ABOVE_TOP);
                updateStatus(MOVED_Z_2);
                break;
            
            // Reset to start-position
            case RESET_AXIS:
                updateStatus(IN_PROCESS);
                reset();
                break;
            
            default:
                break;
        }
    }
    
    return 0;
}

void moveZ(uint8 bound)
{
    Direction_1_Write(FW);
    
    //pwm_isr_1_Enable();
    
    Enable_1_Write(0);
    
    while(zDirection == FW) {}
    
    Enable_1_Write(1);
    //pwm_isr_1_Disable();
    
    enabled = DEFAULT;
}

void reset()
{
    Direction_1_Write(BW);
    
    //pwm_isr_1_Enable();
    
    Enable_1_Write(0);
    
    while(zDirection == BW) {}
    
    Enable_1_Write(1);
    //pwm_isr_1_Disable();
    
    enabled = DEFAULT;
}

// Update status of slave-PSoC/message to be sent to master-PSoC
void updateStatus(uint8 stat)
{
    status = stat;
    UART_1_ClearTxBuffer();
    UART_1_WriteTxData(status);
}

/* [] END OF FILE */
