/*******************************************************************************
* File Name: Coils_X.h  
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

#if !defined(CY_PINS_Coils_X_ALIASES_H) /* Pins Coils_X_ALIASES_H */
#define CY_PINS_Coils_X_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Coils_X_0			(Coils_X__0__PC)
#define Coils_X_0_INTR	((uint16)((uint16)0x0001u << Coils_X__0__SHIFT))

#define Coils_X_1			(Coils_X__1__PC)
#define Coils_X_1_INTR	((uint16)((uint16)0x0001u << Coils_X__1__SHIFT))

#define Coils_X_2			(Coils_X__2__PC)
#define Coils_X_2_INTR	((uint16)((uint16)0x0001u << Coils_X__2__SHIFT))

#define Coils_X_3			(Coils_X__3__PC)
#define Coils_X_3_INTR	((uint16)((uint16)0x0001u << Coils_X__3__SHIFT))

#define Coils_X_INTR_ALL	 ((uint16)(Coils_X_0_INTR| Coils_X_1_INTR| Coils_X_2_INTR| Coils_X_3_INTR))

#endif /* End Pins Coils_X_ALIASES_H */


/* [] END OF FILE */
