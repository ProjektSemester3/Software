/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#ifndef UNIMOTOR_H
#define UNIMOTOR_H
#include "project.h"
#include <stdio.h>

struct {
    uint8 (*rotateRight)(uint8 value);
    uint8 (*rotateLeft)(uint8 value);
    
    void (*motorRunRight)(void);
    void (*motorRunLeft)(void);
    
    uint8 step;
    uint16 stepCount;
} UniMotor;

uint8 motorRotateRight(uint8 value)      // Shifter bit en til højre
{
    return  (value >> 1) | ( (value << 3) & 15);
}

uint8 motorRotateLeft(uint8 value)      // Shifter bit en til venstre
{
    return  (value >> 3) | ( (value << 1) & 15);
}

#endif /* UNIMOTOR_H */   

/* [] END OF FILE */
