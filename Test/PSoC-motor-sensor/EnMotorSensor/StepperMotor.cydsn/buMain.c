#include "project.h"
#include <stdio.h>

uint8 right = 0;
uint8 step = 0b1100; // Start position for motor - global variabel
void MotorRunLeft();
void MotorRunRight();
void Stop();

CY_ISR(isr_RxD)
{
    uint8 rxCmd;
    uint8 numCh, i;
    
    numCh = UART_1_GetRxBufferSize(); //numCh modtager antal bits (uint8 eller uint16)
    
    for (i = 0; i < numCh; i++)
    {
        rxCmd = UART_1_ReadRxData();    //rxCmd læser karakteren
        
        switch (rxCmd)
        {
            case 'r' :
                UART_1_WriteTxData(rxCmd); //Skriver det samme tilbage til terminalen som der sendes
                right = 2;
                break;
            case 'l' :
                UART_1_WriteTxData(rxCmd); //Skriver det samme tilbage til terminalen som der sendes
                right = 1;
                break;
            case 's' :
                UART_1_WriteTxData(rxCmd); //Skriver det samme tilbage til terminalen som der sendes
                right = 0;
        }
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


int main()
{
    CyGlobalIntEnable;

    UART_1_Start();
    isr_RxD_StartEx(isr_RxD);

    for(;;)
    {
        switch(right) 
        {
            case 0:
                break;
            case 1:
                step = rotateLeft(step);
                Coils_Write(step);  
                break;
            case 2:
                step = rotateRight(step);
                Coils_Write(step);  
                break;
        }
        CyDelay(2);
    }
    
    return 0;
}


void MotorRunRight()
{
    while (right == 2) 
    {
        step = rotateRight(step);
        Coils_Write(step);          // Skriver til pins fra TopDesign (Coils)
        CyDelay(2);
    }
}

void MotorRunLeft()
{
    while (right == 1) 
    {
        step = rotateLeft(step);
        Coils_Write(step);              // Skriver til pins fra TopDesign (Coils)
        CyDelay(2);
    }
}

void Stop()
{
    while (right == 0)
    {
    };
}