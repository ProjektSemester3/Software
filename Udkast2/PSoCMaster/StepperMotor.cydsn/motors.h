#ifndef _MOTORS_H
#define _MOTORS_H
#include "project.h"
#include "switches.h"

static uint16 xStepCount = 0;
static uint16 yStepCount = 0;
static uint16 zStepCount = 0;
static uint16 screwCount = 0;

// Find mid-point of bottle on x-axis
int8 locateX(void)
{
    uint16 ADCResultX;
    uint8 i;
    uint16 xPosRight;
    uint16 xPosLeft;
    uint16 xCentre;
    
    // Start sensor
    ADC_SAR_Seq_Start();
    ADC_SAR_Seq_StartConvert();
    ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_WAIT_FOR_RESULT);
    
    // Find right edge of bottle
    Direction_X_Write(BW);
    Enable_X_Write(MOTOR_RUN);
    do {
        ADCResultX = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(X));
        CyDelay(STEPS);
        xStepCount++;
    } while((ADCResultX < LOW) && !xyEndStop);
    Enable_X_Write(MOTOR_STOP);
    
    // Bottle not detected - stop sensor
    if(xyEndStop) {
        ADC_SAR_Seq_Stop();
        updateStatus(NO_BOTTLE);
        xyEndStop = 0;
        return -1;
    }
    
    // Save position
    xPosRight = xStepCount;
    
    // Find left edge of bottle
    Enable_X_Write(MOTOR_RUN);
    do {
        ADCResultX = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(X));
        CyDelay(STEPS);
        xStepCount++;
    } while((ADCResultX > LOW) && !xyEndStop);
    Enable_X_Write(MOTOR_STOP);
    
    // Invalid object inserted - stop sensor
    if(xyEndStop) {
        ADC_SAR_Seq_Stop();
        updateStatus(INVALID_TYPE);
        xyEndStop = 0;
        return -1;
    }
    
    // Save position
    xPosLeft = xStepCount;
    
    // Stop sensor
    ADC_SAR_Seq_Stop();
    
    // Calculate no. of steps to centre of bottle
    xCentre = (xPosLeft - xPosRight)/2;
    
    /*// Bottle of incorrect type
    if((2*xCentre < MIN_WIDTH) || (2*xCentre > MAX_WIDTH)) {
        updateStatus(INVALID_TYPE);
        return -1;
    }*/
    
    // Find centre of bottle
    Direction_X_Write(FW);
    Enable_X_Write(MOTOR_RUN);
    for(i = xCentre; i > 0; --i) {
        CyDelay(STEPS);
    }
    Enable_X_Write(MOTOR_STOP);
    
    // Success
    return 0;
}

// Find mid-point of bottle on y-axis
int8 locateY(void)
{
    uint16 ADCResultY;
    uint8 i;
    uint16 yPosRight;
    uint16 yPosLeft;
    uint16 yCentre;
    
    // Start sensor
    ADC_SAR_Seq_Start();
    ADC_SAR_Seq_StartConvert();
    ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_WAIT_FOR_RESULT);
    
    // Find right edge of bottle
    Direction_Y_Write(BW);
    Enable_Y_Write(MOTOR_RUN);
    do {
        ADCResultY = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(Y));
        CyDelay(STEPS);
        yStepCount++;
    } while((ADCResultY < LOW) && !xyEndStop);
    Enable_Y_Write(MOTOR_STOP);
    
    // Bottle not detected - stop sensor
    if(xyEndStop) {
        ADC_SAR_Seq_Stop();
        updateStatus(NO_BOTTLE);
        xyEndStop = 0;
        return -1;
    }
    
    // Save position
    yPosRight = yStepCount;
    
    // Find left edge of bottle
    Enable_Y_Write(MOTOR_RUN);
    do {
        ADCResultY = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(Y));
        CyDelay(STEPS);
        yStepCount++;
    } while((ADCResultY > LOW) && !xyEndStop);
    Enable_Y_Write(MOTOR_STOP);
    
    // Invalid object inserted - stop sensor
    if(xyEndStop) {
        ADC_SAR_Seq_Stop();
        updateStatus(INVALID_TYPE);
        xyEndStop = 0;
        return -1;
    }
    
    // Save position
    yPosLeft = yStepCount;
    
    // Stop sensor
    ADC_SAR_Seq_Stop();
    
    // Calculate no. of steps to centre of bottle
    yCentre = (yPosLeft - yPosRight)/2;
    
    /*// Bottle of incorrect type
    if((2*yCentre < MIN_WIDTH) || (2*yCentre > MAX_WIDTH)) {
        updateStatus(INVALID_TYPE);
        return -1;
    }*/
    
    // Find centre of bottle
    Direction_Y_Write(FW);
    Enable_Y_Write(MOTOR_RUN);
    for(i = yCentre; i > 0; --i) {
        CyDelay(STEPS);
    }
    Enable_Y_Write(MOTOR_STOP);
    
    // Success
    return 0;
}

// Confirm that height of bottle is valid
int8 confirmHeight(void)
{
    uint16 ADCResultZ;
    
    // Start sensor
    ADC_SAR_Seq_Start();
    ADC_SAR_Seq_StartConvert();
    ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_WAIT_FOR_RESULT);
    
    // Find right edge of bottle
    Direction_Z_Write(FW);
    Enable_Z_Write(MOTOR_RUN);
    do {
        ADCResultZ = ADC_SAR_Seq_CountsTo_mVolts(ADC_SAR_Seq_GetResult16(X));
        CyDelay(STEPS);
        zStepCount++;
    } while((ADCResultZ < LOW) && !zEndStop);
    Enable_Z_Write(MOTOR_STOP);
    
    // Stop sensor
    ADC_SAR_Seq_Stop();
    
    /*// Invalid object inserted
    if(zEndStop || (zStepCount != HEIGHT)) {
        updateStatus(INVALID_TYPE);
        zEndStop = 0;
        return -1;
    }*/
    
    // Success
    updateStatus(VALID_TYPE);
    return 0;
}   

// Reset system to home position
void reset(void)
{
    // Reset z-motors
    Direction_Z_Write(BW);
    Enable_Z_Write(MOTOR_RUN);
    while(!zHomeStop) {
        // Do nothing
    }
    Enable_Z_Write(MOTOR_STOP);
    // Reset y-motory
    Direction_Y_Write(BW);
    Enable_Y_Write(MOTOR_RUN);
    while(!yHomeStop) {
        // Do nothing
    }
    Enable_Y_Write(MOTOR_STOP);
    
    // Reset x-motor
    Direction_X_Write(BW);
    Enable_X_Write(MOTOR_RUN);
    while(!xHomeStop) {
        // Do nothing
    }
    Enable_X_Write(MOTOR_STOP);
    
    zHomeStop = 0;
    yHomeStop = 0;
    xHomeStop = 0;
    
    xStepCount = 0;
    yStepCount = 0;
    zStepCount = 0;
}

#endif // _MOTORS_H
