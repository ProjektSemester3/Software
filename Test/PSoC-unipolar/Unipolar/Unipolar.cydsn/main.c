#include "project.h"

uint8 step = 0b1100; // Start position for motor - global variabel
uint8 enabled = 0;

CY_ISR(isr_RxD)
{
    enabled = !enabled;
}

uint8 rotateRight(uint8 value)      // Shifter bit en til højre
{
    return  (value >> 1) | ( (value << 3) & 15);
}

uint8 rotateLeft(uint8 value)      // Shifter bit en til venstre
{
    return  (value >> 3) | ( (value << 1) & 15);
}

void motorRunLeft()
{
    step = rotateLeft(step);
    Coils_1_Write(step);              // Skriver til pins fra TopDesign (Coils)
    CyDelay(2);
}

void motorRunRight()
{
    step = rotateRight(step);
    Coils_1_Write(step);              // Skriver til pins fra TopDesign (Coils)
    CyDelay(2);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_1_Start();
    isr_RxD_StartEx(isr_RxD);
 
    for(;;)
    {
        while(enabled) {
            motorRunRight();
        }
    }
}

/* [] END OF FILE */
