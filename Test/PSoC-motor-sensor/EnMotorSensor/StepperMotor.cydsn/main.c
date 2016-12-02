#include "project.h"
#include <stdio.h>

uint8 step = 0b1100; // Start position for motor - global variabel
uint16 stepCount = 0;
uint8 enabled = 0;
void motorRunLeft();
void motorRunRight();

enum voltageBoundary {
    LOW = 72,       // Bottle not detected
};

CY_ISR(isr_RxD)
{
    uint8 rxCmd;
    
    rxCmd = UART_1_ReadRxData();
    
    if(rxCmd == 48) {
        
        // Start sensor
        ADC_SAR_Seq_1_Start();
        ADC_SAR_Seq_1_StartConvert();
        ADC_SAR_Seq_1_IsEndConversion(ADC_SAR_Seq_1_WAIT_FOR_RESULT);
        
        // Enables bottle-search
        enabled = 1;
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
    uint16 ADCResult;
    uint16 i;
    uint16 posRight;    // Right edge of bottle in no. of steps
    uint16 posLeft;     // Left edge of bottle in no. of steps
    uint16 width;       // Width of bottle in no. of steps
    CyGlobalIntEnable;

    UART_1_Start();
    isr_RxD_StartEx(isr_RxD);

    for(;;)
    {
        if(enabled) {
            /*
            // Find right edge of bottle
            do {
                //ADCResult = ADC_SAR_Seq_1_GetResult16(0);
                
                motorRunLeft();
            } while(1);
            
            posRight = stepCount;
            
            // Find left edge of bottle
            do {
                ADCResult = ADC_SAR_Seq_1_GetResult16(0);
                
                motorRunLeft();
            } while(ADCResult > LOW);
            
            posLeft = stepCount;
            
            ADC_SAR_Seq_1_Stop();
            
            // Calculate number of steps to middle of bottle
            width = (posLeft - posRight)/2;
            
            // Find middle of bottle
            for(i = width; i > 0; --i) {
                motorRunRight();
            }
            
            // Stop bottle-search
            enabled = 0;*/
            int a, b;
            
            for(a = 0; a < 100000; a++) {
                motorRunLeft();
            }
            for(b = 0; b < 100000; b++) {
                motorRunRight();
            }
            enabled = 0;
        }
    }
    
    return 0;
}

void motorRunLeft()
{
    int i;
    for(i = 0; i < 10; i++) {
        step = rotateLeft(step);
        Coils_1_Write(step);              // Skriver til pins fra TopDesign (Coils)
        CyDelay(2);
    }
    ++stepCount;
}

void motorRunRight()
{
    int i;
    for(i = 0; i < 10; i++) {
        step = rotateRight(step);
        Coils_1_Write(step);              // Skriver til pins fra TopDesign (Coils)
        CyDelay(2);
    }
    --stepCount;
}
