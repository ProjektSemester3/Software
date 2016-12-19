#ifndef _MOTORSZ_H
#define _MOTORSZ_H
#include "project.h"
#include "switches.h"

// Confirm that height of bottle is valid
int8 confirmHeight(void)
{
    uint16 ADCResultZ;
    uint8 i;
    
    // Start sensor
    ADC_SAR_Seq_Start();
    ADC_SAR_Seq_StartConvert();
    ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_WAIT_FOR_RESULT);
    
    // Find part of bottle under top
    Direction_Z_Write(FW);
    Enable_Z_Write(MOTOR_RUN);
    
    for(i = UNDER_TOP; i > 0; --i) {
        CyDelay(STEPS);
    }
    
    Enable_Z_Write(MOTOR_STOP);
    
    ADCResultZ = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(Y));
    
    if(ADCResultZ < LOW) {
        ADC_SAR_Seq_Stop();
        updateStatus(INVALID_TYPE);
        return -1;
    }
    
    Enable_Z_Write(MOTOR_RUN);
    
    for(i = ABOVE_TOP; i > 0; --i) {
        CyDelay(STEPS);
    }
    
    Enable_Z_Write(MOTOR_STOP);
    
    ADCResultZ = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(Y));
    
    if(ADCResultZ > LOW) {
        ADC_SAR_Seq_Stop();
        updateStatus(INVALID_TYPE);
        return -1;
    }
    
    ADC_SAR_Seq_Stop();
    
    updateStatus(VALID_TYPE);
    return 0;
}

void lockBottle()
{
    // Reset z-motors
    Direction_Z_Write(FW);
    Enable_Z_Write(MOTOR_RUN);
    while(!zEndStop) {
        // Do nothing
    }
    Enable_Z_Write(MOTOR_STOP);
    
    zEndStop = 0;
}

// Reset system to home position
void resetZ(void)
{
    // Reset z-motors
    Direction_Z_Write(BW);
    Enable_Z_Write(MOTOR_RUN);
    while(!zHomeStop) {
        // Do nothing
    }
    Enable_Z_Write(MOTOR_STOP);
    
    zHomeStop = 0;
}

#endif // _MOTORSZ_H
