/*******************************************************************************
* File Name: Coils_X.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Coils_X_H) /* Pins Coils_X_H */
#define CY_PINS_Coils_X_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Coils_X_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Coils_X__PORT == 15 && ((Coils_X__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Coils_X_Write(uint8 value);
void    Coils_X_SetDriveMode(uint8 mode);
uint8   Coils_X_ReadDataReg(void);
uint8   Coils_X_Read(void);
void    Coils_X_SetInterruptMode(uint16 position, uint16 mode);
uint8   Coils_X_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Coils_X_SetDriveMode() function.
     *  @{
     */
        #define Coils_X_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Coils_X_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Coils_X_DM_RES_UP          PIN_DM_RES_UP
        #define Coils_X_DM_RES_DWN         PIN_DM_RES_DWN
        #define Coils_X_DM_OD_LO           PIN_DM_OD_LO
        #define Coils_X_DM_OD_HI           PIN_DM_OD_HI
        #define Coils_X_DM_STRONG          PIN_DM_STRONG
        #define Coils_X_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Coils_X_MASK               Coils_X__MASK
#define Coils_X_SHIFT              Coils_X__SHIFT
#define Coils_X_WIDTH              4u

/* Interrupt constants */
#if defined(Coils_X__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Coils_X_SetInterruptMode() function.
     *  @{
     */
        #define Coils_X_INTR_NONE      (uint16)(0x0000u)
        #define Coils_X_INTR_RISING    (uint16)(0x0001u)
        #define Coils_X_INTR_FALLING   (uint16)(0x0002u)
        #define Coils_X_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Coils_X_INTR_MASK      (0x01u) 
#endif /* (Coils_X__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Coils_X_PS                     (* (reg8 *) Coils_X__PS)
/* Data Register */
#define Coils_X_DR                     (* (reg8 *) Coils_X__DR)
/* Port Number */
#define Coils_X_PRT_NUM                (* (reg8 *) Coils_X__PRT) 
/* Connect to Analog Globals */                                                  
#define Coils_X_AG                     (* (reg8 *) Coils_X__AG)                       
/* Analog MUX bux enable */
#define Coils_X_AMUX                   (* (reg8 *) Coils_X__AMUX) 
/* Bidirectional Enable */                                                        
#define Coils_X_BIE                    (* (reg8 *) Coils_X__BIE)
/* Bit-mask for Aliased Register Access */
#define Coils_X_BIT_MASK               (* (reg8 *) Coils_X__BIT_MASK)
/* Bypass Enable */
#define Coils_X_BYP                    (* (reg8 *) Coils_X__BYP)
/* Port wide control signals */                                                   
#define Coils_X_CTL                    (* (reg8 *) Coils_X__CTL)
/* Drive Modes */
#define Coils_X_DM0                    (* (reg8 *) Coils_X__DM0) 
#define Coils_X_DM1                    (* (reg8 *) Coils_X__DM1)
#define Coils_X_DM2                    (* (reg8 *) Coils_X__DM2) 
/* Input Buffer Disable Override */
#define Coils_X_INP_DIS                (* (reg8 *) Coils_X__INP_DIS)
/* LCD Common or Segment Drive */
#define Coils_X_LCD_COM_SEG            (* (reg8 *) Coils_X__LCD_COM_SEG)
/* Enable Segment LCD */
#define Coils_X_LCD_EN                 (* (reg8 *) Coils_X__LCD_EN)
/* Slew Rate Control */
#define Coils_X_SLW                    (* (reg8 *) Coils_X__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Coils_X_PRTDSI__CAPS_SEL       (* (reg8 *) Coils_X__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Coils_X_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Coils_X__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Coils_X_PRTDSI__OE_SEL0        (* (reg8 *) Coils_X__PRTDSI__OE_SEL0) 
#define Coils_X_PRTDSI__OE_SEL1        (* (reg8 *) Coils_X__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Coils_X_PRTDSI__OUT_SEL0       (* (reg8 *) Coils_X__PRTDSI__OUT_SEL0) 
#define Coils_X_PRTDSI__OUT_SEL1       (* (reg8 *) Coils_X__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Coils_X_PRTDSI__SYNC_OUT       (* (reg8 *) Coils_X__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Coils_X__SIO_CFG)
    #define Coils_X_SIO_HYST_EN        (* (reg8 *) Coils_X__SIO_HYST_EN)
    #define Coils_X_SIO_REG_HIFREQ     (* (reg8 *) Coils_X__SIO_REG_HIFREQ)
    #define Coils_X_SIO_CFG            (* (reg8 *) Coils_X__SIO_CFG)
    #define Coils_X_SIO_DIFF           (* (reg8 *) Coils_X__SIO_DIFF)
#endif /* (Coils_X__SIO_CFG) */

/* Interrupt Registers */
#if defined(Coils_X__INTSTAT)
    #define Coils_X_INTSTAT            (* (reg8 *) Coils_X__INTSTAT)
    #define Coils_X_SNAP               (* (reg8 *) Coils_X__SNAP)
    
	#define Coils_X_0_INTTYPE_REG 		(* (reg8 *) Coils_X__0__INTTYPE)
	#define Coils_X_1_INTTYPE_REG 		(* (reg8 *) Coils_X__1__INTTYPE)
	#define Coils_X_2_INTTYPE_REG 		(* (reg8 *) Coils_X__2__INTTYPE)
	#define Coils_X_3_INTTYPE_REG 		(* (reg8 *) Coils_X__3__INTTYPE)
#endif /* (Coils_X__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Coils_X_H */


/* [] END OF FILE */
