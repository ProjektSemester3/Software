/*******************************************************************************
* File Name: MotorOut.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MotorOut_ALIASES_H) /* Pins MotorOut_ALIASES_H */
#define CY_PINS_MotorOut_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define MotorOut_0			(MotorOut__0__PC)
#define MotorOut_0_INTR	((uint16)((uint16)0x0001u << MotorOut__0__SHIFT))

#define MotorOut_1			(MotorOut__1__PC)
#define MotorOut_1_INTR	((uint16)((uint16)0x0001u << MotorOut__1__SHIFT))

#define MotorOut_2			(MotorOut__2__PC)
#define MotorOut_2_INTR	((uint16)((uint16)0x0001u << MotorOut__2__SHIFT))

#define MotorOut_3			(MotorOut__3__PC)
#define MotorOut_3_INTR	((uint16)((uint16)0x0001u << MotorOut__3__SHIFT))

#define MotorOut_INTR_ALL	 ((uint16)(MotorOut_0_INTR| MotorOut_1_INTR| MotorOut_2_INTR| MotorOut_3_INTR))

#endif /* End Pins MotorOut_ALIASES_H */


/* [] END OF FILE */
