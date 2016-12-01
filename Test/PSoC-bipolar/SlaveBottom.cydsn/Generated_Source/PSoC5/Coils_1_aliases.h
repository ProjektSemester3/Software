/*******************************************************************************
* File Name: Coils_1.h  
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

#if !defined(CY_PINS_Coils_1_ALIASES_H) /* Pins Coils_1_ALIASES_H */
#define CY_PINS_Coils_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Coils_1_0			(Coils_1__0__PC)
#define Coils_1_0_INTR	((uint16)((uint16)0x0001u << Coils_1__0__SHIFT))

#define Coils_1_1			(Coils_1__1__PC)
#define Coils_1_1_INTR	((uint16)((uint16)0x0001u << Coils_1__1__SHIFT))

#define Coils_1_2			(Coils_1__2__PC)
#define Coils_1_2_INTR	((uint16)((uint16)0x0001u << Coils_1__2__SHIFT))

#define Coils_1_3			(Coils_1__3__PC)
#define Coils_1_3_INTR	((uint16)((uint16)0x0001u << Coils_1__3__SHIFT))

#define Coils_1_4			(Coils_1__4__PC)
#define Coils_1_4_INTR	((uint16)((uint16)0x0001u << Coils_1__4__SHIFT))

#define Coils_1_5			(Coils_1__5__PC)
#define Coils_1_5_INTR	((uint16)((uint16)0x0001u << Coils_1__5__SHIFT))

#define Coils_1_6			(Coils_1__6__PC)
#define Coils_1_6_INTR	((uint16)((uint16)0x0001u << Coils_1__6__SHIFT))

#define Coils_1_7			(Coils_1__7__PC)
#define Coils_1_7_INTR	((uint16)((uint16)0x0001u << Coils_1__7__SHIFT))

#define Coils_1_INTR_ALL	 ((uint16)(Coils_1_0_INTR| Coils_1_1_INTR| Coils_1_2_INTR| Coils_1_3_INTR| Coils_1_4_INTR| Coils_1_5_INTR| Coils_1_6_INTR| Coils_1_7_INTR))

#endif /* End Pins Coils_1_ALIASES_H */


/* [] END OF FILE */
