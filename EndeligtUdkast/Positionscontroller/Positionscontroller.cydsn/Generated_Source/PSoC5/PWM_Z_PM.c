/*******************************************************************************
* File Name: PWM_Z_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_Z.h"

static PWM_Z_backupStruct PWM_Z_backup;


/*******************************************************************************
* Function Name: PWM_Z_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Z_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Z_SaveConfig(void) 
{

    #if(!PWM_Z_UsingFixedFunction)
        #if(!PWM_Z_PWMModeIsCenterAligned)
            PWM_Z_backup.PWMPeriod = PWM_Z_ReadPeriod();
        #endif /* (!PWM_Z_PWMModeIsCenterAligned) */
        PWM_Z_backup.PWMUdb = PWM_Z_ReadCounter();
        #if (PWM_Z_UseStatus)
            PWM_Z_backup.InterruptMaskValue = PWM_Z_STATUS_MASK;
        #endif /* (PWM_Z_UseStatus) */

        #if(PWM_Z_DeadBandMode == PWM_Z__B_PWM__DBM_256_CLOCKS || \
            PWM_Z_DeadBandMode == PWM_Z__B_PWM__DBM_2_4_CLOCKS)
            PWM_Z_backup.PWMdeadBandValue = PWM_Z_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Z_KillModeMinTime)
             PWM_Z_backup.PWMKillCounterPeriod = PWM_Z_ReadKillTime();
        #endif /* (PWM_Z_KillModeMinTime) */

        #if(PWM_Z_UseControl)
            PWM_Z_backup.PWMControlRegister = PWM_Z_ReadControlRegister();
        #endif /* (PWM_Z_UseControl) */
    #endif  /* (!PWM_Z_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Z_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Z_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Z_RestoreConfig(void) 
{
        #if(!PWM_Z_UsingFixedFunction)
            #if(!PWM_Z_PWMModeIsCenterAligned)
                PWM_Z_WritePeriod(PWM_Z_backup.PWMPeriod);
            #endif /* (!PWM_Z_PWMModeIsCenterAligned) */

            PWM_Z_WriteCounter(PWM_Z_backup.PWMUdb);

            #if (PWM_Z_UseStatus)
                PWM_Z_STATUS_MASK = PWM_Z_backup.InterruptMaskValue;
            #endif /* (PWM_Z_UseStatus) */

            #if(PWM_Z_DeadBandMode == PWM_Z__B_PWM__DBM_256_CLOCKS || \
                PWM_Z_DeadBandMode == PWM_Z__B_PWM__DBM_2_4_CLOCKS)
                PWM_Z_WriteDeadTime(PWM_Z_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Z_KillModeMinTime)
                PWM_Z_WriteKillTime(PWM_Z_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Z_KillModeMinTime) */

            #if(PWM_Z_UseControl)
                PWM_Z_WriteControlRegister(PWM_Z_backup.PWMControlRegister);
            #endif /* (PWM_Z_UseControl) */
        #endif  /* (!PWM_Z_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Z_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Z_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Z_Sleep(void) 
{
    #if(PWM_Z_UseControl)
        if(PWM_Z_CTRL_ENABLE == (PWM_Z_CONTROL & PWM_Z_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Z_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Z_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Z_UseControl) */

    /* Stop component */
    PWM_Z_Stop();

    /* Save registers configuration */
    PWM_Z_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Z_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Z_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Z_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Z_RestoreConfig();

    if(PWM_Z_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Z_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
