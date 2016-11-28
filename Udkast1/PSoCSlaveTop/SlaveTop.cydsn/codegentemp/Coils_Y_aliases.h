/*******************************************************************************
* File Name: Coils_Y.h  
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

#if !defined(CY_PINS_Coils_Y_ALIASES_H) /* Pins Coils_Y_ALIASES_H */
#define CY_PINS_Coils_Y_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Coils_Y_0			(Coils_Y__0__PC)
#define Coils_Y_0_INTR	((uint16)((uint16)0x0001u << Coils_Y__0__SHIFT))

#define Coils_Y_1			(Coils_Y__1__PC)
#define Coils_Y_1_INTR	((uint16)((uint16)0x0001u << Coils_Y__1__SHIFT))

#define Coils_Y_2			(Coils_Y__2__PC)
#define Coils_Y_2_INTR	((uint16)((uint16)0x0001u << Coils_Y__2__SHIFT))

#define Coils_Y_3			(Coils_Y__3__PC)
#define Coils_Y_3_INTR	((uint16)((uint16)0x0001u << Coils_Y__3__SHIFT))

#define Coils_Y_INTR_ALL	 ((uint16)(Coils_Y_0_INTR| Coils_Y_1_INTR| Coils_Y_2_INTR| Coils_Y_3_INTR))

#endif /* End Pins Coils_Y_ALIASES_H */


/* [] END OF FILE */
