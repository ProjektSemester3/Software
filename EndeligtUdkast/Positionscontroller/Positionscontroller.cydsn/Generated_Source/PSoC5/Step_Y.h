/*******************************************************************************
* File Name: Step_Y.h  
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

#if !defined(CY_PINS_Step_Y_H) /* Pins Step_Y_H */
#define CY_PINS_Step_Y_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Step_Y_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Step_Y__PORT == 15 && ((Step_Y__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Step_Y_Write(uint8 value);
void    Step_Y_SetDriveMode(uint8 mode);
uint8   Step_Y_ReadDataReg(void);
uint8   Step_Y_Read(void);
void    Step_Y_SetInterruptMode(uint16 position, uint16 mode);
uint8   Step_Y_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Step_Y_SetDriveMode() function.
     *  @{
     */
        #define Step_Y_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Step_Y_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Step_Y_DM_RES_UP          PIN_DM_RES_UP
        #define Step_Y_DM_RES_DWN         PIN_DM_RES_DWN
        #define Step_Y_DM_OD_LO           PIN_DM_OD_LO
        #define Step_Y_DM_OD_HI           PIN_DM_OD_HI
        #define Step_Y_DM_STRONG          PIN_DM_STRONG
        #define Step_Y_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Step_Y_MASK               Step_Y__MASK
#define Step_Y_SHIFT              Step_Y__SHIFT
#define Step_Y_WIDTH              1u

/* Interrupt constants */
#if defined(Step_Y__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Step_Y_SetInterruptMode() function.
     *  @{
     */
        #define Step_Y_INTR_NONE      (uint16)(0x0000u)
        #define Step_Y_INTR_RISING    (uint16)(0x0001u)
        #define Step_Y_INTR_FALLING   (uint16)(0x0002u)
        #define Step_Y_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Step_Y_INTR_MASK      (0x01u) 
#endif /* (Step_Y__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Step_Y_PS                     (* (reg8 *) Step_Y__PS)
/* Data Register */
#define Step_Y_DR                     (* (reg8 *) Step_Y__DR)
/* Port Number */
#define Step_Y_PRT_NUM                (* (reg8 *) Step_Y__PRT) 
/* Connect to Analog Globals */                                                  
#define Step_Y_AG                     (* (reg8 *) Step_Y__AG)                       
/* Analog MUX bux enable */
#define Step_Y_AMUX                   (* (reg8 *) Step_Y__AMUX) 
/* Bidirectional Enable */                                                        
#define Step_Y_BIE                    (* (reg8 *) Step_Y__BIE)
/* Bit-mask for Aliased Register Access */
#define Step_Y_BIT_MASK               (* (reg8 *) Step_Y__BIT_MASK)
/* Bypass Enable */
#define Step_Y_BYP                    (* (reg8 *) Step_Y__BYP)
/* Port wide control signals */                                                   
#define Step_Y_CTL                    (* (reg8 *) Step_Y__CTL)
/* Drive Modes */
#define Step_Y_DM0                    (* (reg8 *) Step_Y__DM0) 
#define Step_Y_DM1                    (* (reg8 *) Step_Y__DM1)
#define Step_Y_DM2                    (* (reg8 *) Step_Y__DM2) 
/* Input Buffer Disable Override */
#define Step_Y_INP_DIS                (* (reg8 *) Step_Y__INP_DIS)
/* LCD Common or Segment Drive */
#define Step_Y_LCD_COM_SEG            (* (reg8 *) Step_Y__LCD_COM_SEG)
/* Enable Segment LCD */
#define Step_Y_LCD_EN                 (* (reg8 *) Step_Y__LCD_EN)
/* Slew Rate Control */
#define Step_Y_SLW                    (* (reg8 *) Step_Y__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Step_Y_PRTDSI__CAPS_SEL       (* (reg8 *) Step_Y__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Step_Y_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Step_Y__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Step_Y_PRTDSI__OE_SEL0        (* (reg8 *) Step_Y__PRTDSI__OE_SEL0) 
#define Step_Y_PRTDSI__OE_SEL1        (* (reg8 *) Step_Y__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Step_Y_PRTDSI__OUT_SEL0       (* (reg8 *) Step_Y__PRTDSI__OUT_SEL0) 
#define Step_Y_PRTDSI__OUT_SEL1       (* (reg8 *) Step_Y__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Step_Y_PRTDSI__SYNC_OUT       (* (reg8 *) Step_Y__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Step_Y__SIO_CFG)
    #define Step_Y_SIO_HYST_EN        (* (reg8 *) Step_Y__SIO_HYST_EN)
    #define Step_Y_SIO_REG_HIFREQ     (* (reg8 *) Step_Y__SIO_REG_HIFREQ)
    #define Step_Y_SIO_CFG            (* (reg8 *) Step_Y__SIO_CFG)
    #define Step_Y_SIO_DIFF           (* (reg8 *) Step_Y__SIO_DIFF)
#endif /* (Step_Y__SIO_CFG) */

/* Interrupt Registers */
#if defined(Step_Y__INTSTAT)
    #define Step_Y_INTSTAT            (* (reg8 *) Step_Y__INTSTAT)
    #define Step_Y_SNAP               (* (reg8 *) Step_Y__SNAP)
    
	#define Step_Y_0_INTTYPE_REG 		(* (reg8 *) Step_Y__0__INTTYPE)
#endif /* (Step_Y__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Step_Y_H */


/* [] END OF FILE */
