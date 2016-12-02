/*******************************************************************************
* File Name: ADC_SAR_Seq_X_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_SAR_Seq_X.h"
#include "ADC_SAR_Seq_X_SAR.h"
#if(ADC_SAR_Seq_X_CLOCK_SOURCE == ADC_SAR_Seq_X_CLOCK_INTERNAL)
    #include "ADC_SAR_Seq_X_IntClock.h"
#endif   /* ADC_SAR_Seq_X_CLOCK_SOURCE == ADC_SAR_Seq_X_CLOCK_INTERNAL */


/*******************************************************************************
* Function Name: ADC_SAR_Seq_X_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_SAR_Seq_X_Sleep(void)
{
    ADC_SAR_Seq_X_SAR_Stop();
    ADC_SAR_Seq_X_SAR_Sleep();
    ADC_SAR_Seq_X_Disable();

    #if(ADC_SAR_Seq_X_CLOCK_SOURCE == ADC_SAR_Seq_X_CLOCK_INTERNAL)
        ADC_SAR_Seq_X_IntClock_Stop();
    #endif   /* ADC_SAR_Seq_X_CLOCK_SOURCE == ADC_SAR_Seq_X_CLOCK_INTERNAL */
}


/*******************************************************************************
* Function Name: ADC_SAR_Seq_X_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers. This should
*  be called just after awaking from sleep mode
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_SAR_Seq_X_Wakeup(void)
{
    ADC_SAR_Seq_X_SAR_Wakeup();
    ADC_SAR_Seq_X_SAR_Enable();

    #if(ADC_SAR_Seq_X_CLOCK_SOURCE == ADC_SAR_Seq_X_CLOCK_INTERNAL)
        ADC_SAR_Seq_X_IntClock_Start();
    #endif   /* ADC_SAR_Seq_X_CLOCK_SOURCE == ADC_SAR_Seq_X_CLOCK_INTERNAL */

    /* The block is ready to use 10 us after the SAR enable signal is set high. */
    CyDelayUs(10u);
    
    ADC_SAR_Seq_X_Enable();

    #if(ADC_SAR_Seq_X_SAMPLE_MODE == ADC_SAR_Seq_X_SAMPLE_MODE_FREE_RUNNING)
        ADC_SAR_Seq_X_SAR_StartConvert();
    #endif /* (ADC_SAR_Seq_X_SAMPLE_MODE == ADC_SAR_Seq_X_SAMPLE_MODE_FREE_RUNNING) */

    (void) CY_GET_REG8(ADC_SAR_Seq_X_STATUS_PTR);
}


/*******************************************************************************
* Function Name: ADC_SAR_Seq_X_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_SAR_Seq_X_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: ADC_SAR_Seq_X_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_SAR_Seq_X_RestoreConfig(void)
{

}


/* [] END OF FILE */
