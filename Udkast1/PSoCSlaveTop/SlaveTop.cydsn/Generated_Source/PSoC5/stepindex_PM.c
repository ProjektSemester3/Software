/*******************************************************************************
* File Name: stepindex_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "stepindex.h"

/* Check for removal by optimization */
#if !defined(stepindex_Sync_ctrl_reg__REMOVED)

static stepindex_BACKUP_STRUCT  stepindex_backup = {0u};

    
/*******************************************************************************
* Function Name: stepindex_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void stepindex_SaveConfig(void) 
{
    stepindex_backup.controlState = stepindex_Control;
}


/*******************************************************************************
* Function Name: stepindex_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void stepindex_RestoreConfig(void) 
{
     stepindex_Control = stepindex_backup.controlState;
}


/*******************************************************************************
* Function Name: stepindex_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void stepindex_Sleep(void) 
{
    stepindex_SaveConfig();
}


/*******************************************************************************
* Function Name: stepindex_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void stepindex_Wakeup(void)  
{
    stepindex_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
