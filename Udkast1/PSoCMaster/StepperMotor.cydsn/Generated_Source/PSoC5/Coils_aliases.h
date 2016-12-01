/*******************************************************************************
* File Name: Coils.h  
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

#if !defined(CY_PINS_Coils_ALIASES_H) /* Pins Coils_ALIASES_H */
#define CY_PINS_Coils_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Coils_0			(Coils__0__PC)
#define Coils_0_INTR	((uint16)((uint16)0x0001u << Coils__0__SHIFT))

#define Coils_1			(Coils__1__PC)
#define Coils_1_INTR	((uint16)((uint16)0x0001u << Coils__1__SHIFT))

#define Coils_2			(Coils__2__PC)
#define Coils_2_INTR	((uint16)((uint16)0x0001u << Coils__2__SHIFT))

#define Coils_3			(Coils__3__PC)
#define Coils_3_INTR	((uint16)((uint16)0x0001u << Coils__3__SHIFT))

#define Coils_INTR_ALL	 ((uint16)(Coils_0_INTR| Coils_1_INTR| Coils_2_INTR| Coils_3_INTR))

#endif /* End Pins Coils_ALIASES_H */


/* [] END OF FILE */
