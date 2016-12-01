#include "project.h"

uint16 zStepCount = 0;
uint8 step = 0b1100; // Start position for motor - global variabel
uint8 enabled = 0;
uint8 zDirection;

void moveC();
void moveCC();

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
    NO = 0,
    FW = 1,
    BW = 2,
};

CY_ISR(isr_RxD)
{
    uint8 rxCmd;
    UART_1_ClearTxBuffer();
    
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
            zDirection = NO;
            enabled = STOP;
            break;
            
        default:
            break;
    }
}

uint8 rotateRight(uint8 value)      // Shifter bit en til højre
{
    return  (value >> 1) | ( (value << 3) & 15);
}

uint8 rotateLeft(uint8 value)      // Shifter bit en til venstre
{
    return  (value >> 3) | ( (value << 1) & 15);
}

int main(void)
{
    CyGlobalIntEnable;

    UART_1_Start();
    isr_RxD_StartEx(isr_RxD);

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
            
            default:
                break;
        }
    }
    
    return 0;
}

void moveC()
{
    while(zDirection == BW) {
        step = rotateRight(step);
        Coils_1_Write((step << 4) | step);              // Skriver til pins fra TopDesign (Coils)
        CyDelay(2);
    }
}

void moveCC()
{
    while(zDirection == FW) {
        step = rotateLeft(step);
        Coils_1_Write((step << 4) | step);              // Skriver til pins fra TopDesign (Coils)
        CyDelay(2);
    }
}

/* [] END OF FILE */
