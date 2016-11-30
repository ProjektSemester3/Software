#include "project.h"

uint16 zStepCount = 0;
uint8 enabled = 0;
uint8 zDirection;

void moveC();
void moveCC();
void stop();

enum SPI_protocol {
    
    // Command from PSoC-master to -slave
    MOVE_CLOCKWISE = 0x01,
    MOVE_COUNTERCLOCKWISE = 0x02,
    STOP_MOVING = 0x03,
};

enum bottleInfo {
    BELOW_TOP = 10,             // Random value
    ABOVE_TOP = 11,             // Random value
};

enum operation {
    CLOCK = 1,
    COUNTERCLOCK = 2,
    STOP = 3,
};

enum dir
{
    FW = 0,
    BW = 1,
};

CY_ISR(isr_RxD)
{
    uint8 rxCmd;
    uint8 enpin;
    enpin = Enable_1_Read();
    UART_1_ClearTxBuffer();
    UART_1_WriteTxData(enpin);
    zDirection = 3;
    
    rxCmd = UART_1_ReadRxData();
    UART_1_ClearRxBuffer();
    
    rxCmd -= 0x30;
    
    switch(rxCmd) {
        
        // Position x-sensor to just under top of bottle
        case MOVE_CLOCKWISE:
            zDirection = BW;
            enabled = CLOCK;
            break;
        
        // Position x-sensor to just over top of bottle
        case MOVE_COUNTERCLOCKWISE:
            zDirection = FW;
            enabled = COUNTERCLOCK;
            break;
        
        // Position x- and y-sensor to start-positions on respectively x- and y-axes
        case STOP_MOVING:
            enabled = STOP;
            break;
            
        default:
            break;
    }
}

/*CY_ISR(pwm_isr_1)
{
    PWM_1_ReadStatusRegister();
    uint8 step;
    step = stepindex_1_Read();
    if(zDirection == FW) {
        if(step >= 0x01) {
            stepindex_1_Write(0x00);
        }
        else {
            stepindex_1_Write(step + 0x01);
        }
        ++zStepCount;
    }
    else { //direction == BW
        if(step <= 0x00) {
            stepindex_1_Write(0x01);
        }
        else {
            stepindex_1_Write(step-0x01);
        }
        --zStepCount;
    }
    //CyDelay(2);
}*/

int main(void)
{
    CyGlobalIntEnable;

    UART_1_Start();
    isr_RxD_StartEx(isr_RxD);
    stepindex_1_Write(0b01); //Start på 1, fordi fullstep.

    for(;;)
    {
        switch(enabled) {
            
            // Position x-sensor to just under top of bottle
            case CLOCK:
                moveC();
                break;
            
            // Position x-sensor to just over top of bottle
            case COUNTERCLOCK:
                moveCC();
                break;
            
            // Reset to start-position
            case STOP:
                stop();
                break;
            
            default:
                break;
        }
    }
    
    return 0;
}

void moveC()
{
    /*zDirection = FW;
    
    Enable_1_Write(1);
    
    //PWM_1_Start();
    //pwm_isr_1_StartEx(pwm_isr_1);
    stepindex_1_Write(1); //Start på 1, fordi fullstep.*/
    
    //zDirection = BW;
    uint8 step;
    
    Enable_1_Write(1);
    while(zDirection == BW) {
        
        step = stepindex_1_Read();
        if(step <= 0b00) {
            stepindex_1_Write(0b11);
        }
        else {
            stepindex_1_Write(step - 0b01);
        }
        --zStepCount;
        CyDelay(2);
    }
    Enable_1_Write(0);
}

void moveCC()
{
    //zDirection = FW;
    uint8 step;
    
    Enable_1_Write(1);
    stepindex_1_Write(0b01); //Start på 1, fordi fullstep.
    while(zDirection == FW) {
        
        step = stepindex_1_Read();
        if(step >= 0b11) {
            stepindex_1_Write(0b00);
        }
        else {
            stepindex_1_Write(step + 0b01);
        }
        ++zStepCount;
        CyDelay(2);
    }
    Enable_1_Write(0);
}

void stop()
{
    //PWM_1_Stop();
    Enable_1_Write(0);
}

/* [] END OF FILE */
