/*******************************************************************************
* File Name: Coils.h  
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

#if !defined(CY_PINS_Coils_H) /* Pins Coils_H */
#define CY_PINS_Coils_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Coils_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Coils__PORT == 15 && ((Coils__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Coils_Write(uint8 value);
void    Coils_SetDriveMode(uint8 mode);
uint8   Coils_ReadDataReg(void);
uint8   Coils_Read(void);
void    Coils_SetInterruptMode(uint16 position, uint16 mode);
uint8   Coils_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Coils_SetDriveMode() function.
     *  @{
     */
        #define Coils_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Coils_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Coils_DM_RES_UP          PIN_DM_RES_UP
        #define Coils_DM_RES_DWN         PIN_DM_RES_DWN
        #define Coils_DM_OD_LO           PIN_DM_OD_LO
        #define Coils_DM_OD_HI           PIN_DM_OD_HI
        #define Coils_DM_STRONG          PIN_DM_STRONG
        #define Coils_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Coils_MASK               Coils__MASK
#define Coils_SHIFT              Coils__SHIFT
#define Coils_WIDTH              4u

/* Interrupt constants */
#if defined(Coils__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Coils_SetInterruptMode() function.
     *  @{
     */
        #define Coils_INTR_NONE      (uint16)(0x0000u)
        #define Coils_INTR_RISING    (uint16)(0x0001u)
        #define Coils_INTR_FALLING   (uint16)(0x0002u)
        #define Coils_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Coils_INTR_MASK      (0x01u) 
#endif /* (Coils__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Coils_PS                     (* (reg8 *) Coils__PS)
/* Data Register */
#define Coils_DR                     (* (reg8 *) Coils__DR)
/* Port Number */
#define Coils_PRT_NUM                (* (reg8 *) Coils__PRT) 
/* Connect to Analog Globals */                                                  
#define Coils_AG                     (* (reg8 *) Coils__AG)                       
/* Analog MUX bux enable */
#define Coils_AMUX                   (* (reg8 *) Coils__AMUX) 
/* Bidirectional Enable */                                                        
#define Coils_BIE                    (* (reg8 *) Coils__BIE)
/* Bit-mask for Aliased Register Access */
#define Coils_BIT_MASK               (* (reg8 *) Coils__BIT_MASK)
/* Bypass Enable */
#define Coils_BYP                    (* (reg8 *) Coils__BYP)
/* Port wide control signals */                                                   
#define Coils_CTL                    (* (reg8 *) Coils__CTL)
/* Drive Modes */
#define Coils_DM0                    (* (reg8 *) Coils__DM0) 
#define Coils_DM1                    (* (reg8 *) Coils__DM1)
#define Coils_DM2                    (* (reg8 *) Coils__DM2) 
/* Input Buffer Disable Override */
#define Coils_INP_DIS                (* (reg8 *) Coils__INP_DIS)
/* LCD Common or Segment Drive */
#define Coils_LCD_COM_SEG            (* (reg8 *) Coils__LCD_COM_SEG)
/* Enable Segment LCD */
#define Coils_LCD_EN                 (* (reg8 *) Coils__LCD_EN)
/* Slew Rate Control */
#define Coils_SLW                    (* (reg8 *) Coils__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Coils_PRTDSI__CAPS_SEL       (* (reg8 *) Coils__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Coils_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Coils__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Coils_PRTDSI__OE_SEL0        (* (reg8 *) Coils__PRTDSI__OE_SEL0) 
#define Coils_PRTDSI__OE_SEL1        (* (reg8 *) Coils__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Coils_PRTDSI__OUT_SEL0       (* (reg8 *) Coils__PRTDSI__OUT_SEL0) 
#define Coils_PRTDSI__OUT_SEL1       (* (reg8 *) Coils__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Coils_PRTDSI__SYNC_OUT       (* (reg8 *) Coils__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Coils__SIO_CFG)
    #define Coils_SIO_HYST_EN        (* (reg8 *) Coils__SIO_HYST_EN)
    #define Coils_SIO_REG_HIFREQ     (* (reg8 *) Coils__SIO_REG_HIFREQ)
    #define Coils_SIO_CFG            (* (reg8 *) Coils__SIO_CFG)
    #define Coils_SIO_DIFF           (* (reg8 *) Coils__SIO_DIFF)
#endif /* (Coils__SIO_CFG) */

/* Interrupt Registers */
#if defined(Coils__INTSTAT)
    #define Coils_INTSTAT            (* (reg8 *) Coils__INTSTAT)
    #define Coils_SNAP               (* (reg8 *) Coils__SNAP)
    
	#define Coils_0_INTTYPE_REG 		(* (reg8 *) Coils__0__INTTYPE)
	#define Coils_1_INTTYPE_REG 		(* (reg8 *) Coils__1__INTTYPE)
	#define Coils_2_INTTYPE_REG 		(* (reg8 *) Coils__2__INTTYPE)
	#define Coils_3_INTTYPE_REG 		(* (reg8 *) Coils__3__INTTYPE)
#endif /* (Coils__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Coils_H */


/* [] END OF FILE */
