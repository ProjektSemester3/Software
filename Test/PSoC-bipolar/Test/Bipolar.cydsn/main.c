#include "project.h"

uint16 zStepCount = 0;
uint8 enabled = 0;
uint8 zDirection;
uint8 zStop = 0;

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
    enabled = 1;
    /*uint8 rxCmd;
    
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
    */
}

CY_ISR(isr_x_home)
{
    zStop = 1;
    Pin_int_x_home_ClearInterrupt();
}

int main(void)
{
    updateStatus(DEFAULT);
    CyGlobalIntEnable;

    UART_1_Start();
    isr_RxD_StartEx(isr_RxD);
    isr_x_home_StartEx(isr_x_home);
    
    PWM_1_Start();
    enabled = DEFAULT;

    for(;;)
    {
        switch(enabled) {
            case 1: {
            uint16 ADCResultX;
            uint8 i;
            uint16 zPosRight;
            uint16 zPosLeft;
            uint16 zWidth;
            Direction_1_Write(FW);
            
            // Start sensor
            ADC_SAR_Seq_Start();
            ADC_SAR_Seq_StartConvert();
            ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_WAIT_FOR_RESULT);
            
            // Find right edge of bottle
            Enable_1_Write(0);
            do {
                ADCResultX = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(0));
                CyDelay(25);
                zStepCount++;
            } while((ADCResultX < 100) && (zStop == 0));
            Enable_1_Write(1);
            
            zPosRight = zStepCount;
            
            /*if(zStop == 1) {
                zStop = 0;
                enabled = 0;
                break;
            }*/
            
            if(!isr_x_home_GetState()) {
                isr_x_home_Enable();
            }
            
            // Find left edge of bottle
            Enable_1_Write(0);
            do {
                ADCResultX = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(0));
                CyDelay(25);
                zStepCount++;
            } while((ADCResultX > 100) && (zStop == 0));
            Enable_1_Write(1);
            
            zPosLeft = zStepCount;
            
            UART_1_WriteTxData(zPosLeft);
            
            ADC_SAR_Seq_Stop();
            
            zWidth = (zPosLeft - zPosRight)/2;
            
            Direction_1_Write(BW);
            
            // Find centre of bottle
            Enable_1_Write(0);
            for(i = zWidth; i > 0; --i) {
                CyDelay(25);
            }
            Enable_1_Write(1);
            
            enabled = 0;
        }
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
