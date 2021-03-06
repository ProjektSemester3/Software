/*******************************************************************************
* File Name: MotorOut_1.h  
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

#if !defined(CY_PINS_MotorOut_1_ALIASES_H) /* Pins MotorOut_1_ALIASES_H */
#define CY_PINS_MotorOut_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define MotorOut_1_0			(MotorOut_1__0__PC)
#define MotorOut_1_0_INTR	((uint16)((uint16)0x0001u << MotorOut_1__0__SHIFT))

#define MotorOut_1_1			(MotorOut_1__1__PC)
#define MotorOut_1_1_INTR	((uint16)((uint16)0x0001u << MotorOut_1__1__SHIFT))

#define MotorOut_1_2			(MotorOut_1__2__PC)
#define MotorOut_1_2_INTR	((uint16)((uint16)0x0001u << MotorOut_1__2__SHIFT))

#define MotorOut_1_3			(MotorOut_1__3__PC)
#define MotorOut_1_3_INTR	((uint16)((uint16)0x0001u << MotorOut_1__3__SHIFT))

#define MotorOut_1_INTR_ALL	 ((uint16)(MotorOut_1_0_INTR| MotorOut_1_1_INTR| MotorOut_1_2_INTR| MotorOut_1_3_INTR))

#endif /* End Pins MotorOut_1_ALIASES_H */


/* [] END OF FILE */
