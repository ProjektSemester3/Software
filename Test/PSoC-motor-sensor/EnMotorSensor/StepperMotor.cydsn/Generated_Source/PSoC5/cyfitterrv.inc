    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; Rx_1
Rx_1__0__INTTYPE EQU CYREG_PICU12_INTTYPE6
Rx_1__0__MASK EQU 0x40
Rx_1__0__PC EQU CYREG_PRT12_PC6
Rx_1__0__PORT EQU 12
Rx_1__0__SHIFT EQU 6
Rx_1__AG EQU CYREG_PRT12_AG
Rx_1__BIE EQU CYREG_PRT12_BIE
Rx_1__BIT_MASK EQU CYREG_PRT12_BIT_MASK
Rx_1__BYP EQU CYREG_PRT12_BYP
Rx_1__DM0 EQU CYREG_PRT12_DM0
Rx_1__DM1 EQU CYREG_PRT12_DM1
Rx_1__DM2 EQU CYREG_PRT12_DM2
Rx_1__DR EQU CYREG_PRT12_DR
Rx_1__INP_DIS EQU CYREG_PRT12_INP_DIS
Rx_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
Rx_1__MASK EQU 0x40
Rx_1__PORT EQU 12
Rx_1__PRT EQU CYREG_PRT12_PRT
Rx_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
Rx_1__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
Rx_1__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
Rx_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
Rx_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
Rx_1__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
Rx_1__PS EQU CYREG_PRT12_PS
Rx_1__SHIFT EQU 6
Rx_1__SIO_CFG EQU CYREG_PRT12_SIO_CFG
Rx_1__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
Rx_1__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
Rx_1__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
Rx_1__SLW EQU CYREG_PRT12_SLW

; Tx_1
Tx_1__0__INTTYPE EQU CYREG_PICU12_INTTYPE7
Tx_1__0__MASK EQU 0x80
Tx_1__0__PC EQU CYREG_PRT12_PC7
Tx_1__0__PORT EQU 12
Tx_1__0__SHIFT EQU 7
Tx_1__AG EQU CYREG_PRT12_AG
Tx_1__BIE EQU CYREG_PRT12_BIE
Tx_1__BIT_MASK EQU CYREG_PRT12_BIT_MASK
Tx_1__BYP EQU CYREG_PRT12_BYP
Tx_1__DM0 EQU CYREG_PRT12_DM0
Tx_1__DM1 EQU CYREG_PRT12_DM1
Tx_1__DM2 EQU CYREG_PRT12_DM2
Tx_1__DR EQU CYREG_PRT12_DR
Tx_1__INP_DIS EQU CYREG_PRT12_INP_DIS
Tx_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
Tx_1__MASK EQU 0x80
Tx_1__PORT EQU 12
Tx_1__PRT EQU CYREG_PRT12_PRT
Tx_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
Tx_1__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
Tx_1__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
Tx_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
Tx_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
Tx_1__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
Tx_1__PS EQU CYREG_PRT12_PS
Tx_1__SHIFT EQU 7
Tx_1__SIO_CFG EQU CYREG_PRT12_SIO_CFG
Tx_1__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
Tx_1__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
Tx_1__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
Tx_1__SLW EQU CYREG_PRT12_SLW

; Pin_1
Pin_1__0__INTTYPE EQU CYREG_PICU0_INTTYPE7
Pin_1__0__MASK EQU 0x80
Pin_1__0__PC EQU CYREG_PRT0_PC7
Pin_1__0__PORT EQU 0
Pin_1__0__SHIFT EQU 7
Pin_1__AG EQU CYREG_PRT0_AG
Pin_1__AMUX EQU CYREG_PRT0_AMUX
Pin_1__BIE EQU CYREG_PRT0_BIE
Pin_1__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Pin_1__BYP EQU CYREG_PRT0_BYP
Pin_1__CTL EQU CYREG_PRT0_CTL
Pin_1__DM0 EQU CYREG_PRT0_DM0
Pin_1__DM1 EQU CYREG_PRT0_DM1
Pin_1__DM2 EQU CYREG_PRT0_DM2
Pin_1__DR EQU CYREG_PRT0_DR
Pin_1__INP_DIS EQU CYREG_PRT0_INP_DIS
Pin_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
Pin_1__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Pin_1__LCD_EN EQU CYREG_PRT0_LCD_EN
Pin_1__MASK EQU 0x80
Pin_1__PORT EQU 0
Pin_1__PRT EQU CYREG_PRT0_PRT
Pin_1__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Pin_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Pin_1__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Pin_1__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Pin_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Pin_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Pin_1__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Pin_1__PS EQU CYREG_PRT0_PS
Pin_1__SHIFT EQU 7
Pin_1__SLW EQU CYREG_PRT0_SLW

; UART_1_BUART
UART_1_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB11_ACTL
UART_1_BUART_sRX_RxBitCounter__CONTROL_REG EQU CYREG_B1_UDB11_CTL
UART_1_BUART_sRX_RxBitCounter__CONTROL_ST_REG EQU CYREG_B1_UDB11_ST_CTL
UART_1_BUART_sRX_RxBitCounter__COUNT_REG EQU CYREG_B1_UDB11_CTL
UART_1_BUART_sRX_RxBitCounter__COUNT_ST_REG EQU CYREG_B1_UDB11_ST_CTL
UART_1_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB11_MSK_ACTL
UART_1_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB11_MSK_ACTL
UART_1_BUART_sRX_RxBitCounter__PERIOD_REG EQU CYREG_B1_UDB11_MSK
UART_1_BUART_sRX_RxBitCounter_ST__MASK_REG EQU CYREG_B1_UDB11_MSK
UART_1_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB11_MSK_ACTL
UART_1_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB11_MSK_ACTL
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB11_ACTL
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG EQU CYREG_B1_UDB11_ST_CTL
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B1_UDB11_ST_CTL
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_REG EQU CYREG_B1_UDB11_ST
UART_1_BUART_sRX_RxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB08_09_A0
UART_1_BUART_sRX_RxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB08_09_A1
UART_1_BUART_sRX_RxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB08_09_D0
UART_1_BUART_sRX_RxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB08_09_D1
UART_1_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB08_09_ACTL
UART_1_BUART_sRX_RxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB08_09_F0
UART_1_BUART_sRX_RxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB08_09_F1
UART_1_BUART_sRX_RxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB08_A0_A1
UART_1_BUART_sRX_RxShifter_u0__A0_REG EQU CYREG_B0_UDB08_A0
UART_1_BUART_sRX_RxShifter_u0__A1_REG EQU CYREG_B0_UDB08_A1
UART_1_BUART_sRX_RxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB08_D0_D1
UART_1_BUART_sRX_RxShifter_u0__D0_REG EQU CYREG_B0_UDB08_D0
UART_1_BUART_sRX_RxShifter_u0__D1_REG EQU CYREG_B0_UDB08_D1
UART_1_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB08_ACTL
UART_1_BUART_sRX_RxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB08_F0_F1
UART_1_BUART_sRX_RxShifter_u0__F0_REG EQU CYREG_B0_UDB08_F0
UART_1_BUART_sRX_RxShifter_u0__F1_REG EQU CYREG_B0_UDB08_F1
UART_1_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB08_09_ACTL
UART_1_BUART_sRX_RxSts__16BIT_STATUS_REG EQU CYREG_B1_UDB08_09_ST
UART_1_BUART_sRX_RxSts__3__MASK EQU 0x08
UART_1_BUART_sRX_RxSts__3__POS EQU 3
UART_1_BUART_sRX_RxSts__4__MASK EQU 0x10
UART_1_BUART_sRX_RxSts__4__POS EQU 4
UART_1_BUART_sRX_RxSts__5__MASK EQU 0x20
UART_1_BUART_sRX_RxSts__5__POS EQU 5
UART_1_BUART_sRX_RxSts__MASK EQU 0x38
UART_1_BUART_sRX_RxSts__MASK_REG EQU CYREG_B1_UDB08_MSK
UART_1_BUART_sRX_RxSts__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB08_ACTL
UART_1_BUART_sRX_RxSts__STATUS_REG EQU CYREG_B1_UDB08_ST
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG EQU CYREG_B0_UDB14_15_A0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG EQU CYREG_B0_UDB14_15_A1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG EQU CYREG_B0_UDB14_15_D0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG EQU CYREG_B0_UDB14_15_D1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB14_15_ACTL
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG EQU CYREG_B0_UDB14_15_F0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG EQU CYREG_B0_UDB14_15_F1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG EQU CYREG_B0_UDB14_A0_A1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG EQU CYREG_B0_UDB14_A0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG EQU CYREG_B0_UDB14_A1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG EQU CYREG_B0_UDB14_D0_D1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG EQU CYREG_B0_UDB14_D0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG EQU CYREG_B0_UDB14_D1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG EQU CYREG_B0_UDB14_ACTL
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG EQU CYREG_B0_UDB14_F0_F1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG EQU CYREG_B0_UDB14_F0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG EQU CYREG_B0_UDB14_F1
UART_1_BUART_sTX_TxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB12_13_A0
UART_1_BUART_sTX_TxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB12_13_A1
UART_1_BUART_sTX_TxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB12_13_D0
UART_1_BUART_sTX_TxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB12_13_D1
UART_1_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB12_13_ACTL
UART_1_BUART_sTX_TxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB12_13_F0
UART_1_BUART_sTX_TxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB12_13_F1
UART_1_BUART_sTX_TxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB12_A0_A1
UART_1_BUART_sTX_TxShifter_u0__A0_REG EQU CYREG_B0_UDB12_A0
UART_1_BUART_sTX_TxShifter_u0__A1_REG EQU CYREG_B0_UDB12_A1
UART_1_BUART_sTX_TxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB12_D0_D1
UART_1_BUART_sTX_TxShifter_u0__D0_REG EQU CYREG_B0_UDB12_D0
UART_1_BUART_sTX_TxShifter_u0__D1_REG EQU CYREG_B0_UDB12_D1
UART_1_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB12_ACTL
UART_1_BUART_sTX_TxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB12_F0_F1
UART_1_BUART_sTX_TxShifter_u0__F0_REG EQU CYREG_B0_UDB12_F0
UART_1_BUART_sTX_TxShifter_u0__F1_REG EQU CYREG_B0_UDB12_F1
UART_1_BUART_sTX_TxSts__0__MASK EQU 0x01
UART_1_BUART_sTX_TxSts__0__POS EQU 0
UART_1_BUART_sTX_TxSts__1__MASK EQU 0x02
UART_1_BUART_sTX_TxSts__1__POS EQU 1
UART_1_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB12_13_ACTL
UART_1_BUART_sTX_TxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB12_13_ST
UART_1_BUART_sTX_TxSts__2__MASK EQU 0x04
UART_1_BUART_sTX_TxSts__2__POS EQU 2
UART_1_BUART_sTX_TxSts__3__MASK EQU 0x08
UART_1_BUART_sTX_TxSts__3__POS EQU 3
UART_1_BUART_sTX_TxSts__MASK EQU 0x0F
UART_1_BUART_sTX_TxSts__MASK_REG EQU CYREG_B0_UDB12_MSK
UART_1_BUART_sTX_TxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB12_ACTL
UART_1_BUART_sTX_TxSts__STATUS_REG EQU CYREG_B0_UDB12_ST

; UART_1_IntClock
UART_1_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG1_CFG0
UART_1_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG1_CFG1
UART_1_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG1_CFG2
UART_1_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
UART_1_IntClock__INDEX EQU 0x01
UART_1_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
UART_1_IntClock__PM_ACT_MSK EQU 0x02
UART_1_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
UART_1_IntClock__PM_STBY_MSK EQU 0x02

; Coils_1
Coils_1__0__INTTYPE EQU CYREG_PICU2_INTTYPE4
Coils_1__0__MASK EQU 0x10
Coils_1__0__PC EQU CYREG_PRT2_PC4
Coils_1__0__PORT EQU 2
Coils_1__0__SHIFT EQU 4
Coils_1__1__INTTYPE EQU CYREG_PICU2_INTTYPE5
Coils_1__1__MASK EQU 0x20
Coils_1__1__PC EQU CYREG_PRT2_PC5
Coils_1__1__PORT EQU 2
Coils_1__1__SHIFT EQU 5
Coils_1__2__INTTYPE EQU CYREG_PICU2_INTTYPE6
Coils_1__2__MASK EQU 0x40
Coils_1__2__PC EQU CYREG_PRT2_PC6
Coils_1__2__PORT EQU 2
Coils_1__2__SHIFT EQU 6
Coils_1__3__INTTYPE EQU CYREG_PICU2_INTTYPE7
Coils_1__3__MASK EQU 0x80
Coils_1__3__PC EQU CYREG_PRT2_PC7
Coils_1__3__PORT EQU 2
Coils_1__3__SHIFT EQU 7
Coils_1__AG EQU CYREG_PRT2_AG
Coils_1__AMUX EQU CYREG_PRT2_AMUX
Coils_1__BIE EQU CYREG_PRT2_BIE
Coils_1__BIT_MASK EQU CYREG_PRT2_BIT_MASK
Coils_1__BYP EQU CYREG_PRT2_BYP
Coils_1__CTL EQU CYREG_PRT2_CTL
Coils_1__DM0 EQU CYREG_PRT2_DM0
Coils_1__DM1 EQU CYREG_PRT2_DM1
Coils_1__DM2 EQU CYREG_PRT2_DM2
Coils_1__DR EQU CYREG_PRT2_DR
Coils_1__INP_DIS EQU CYREG_PRT2_INP_DIS
Coils_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
Coils_1__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
Coils_1__LCD_EN EQU CYREG_PRT2_LCD_EN
Coils_1__MASK EQU 0xF0
Coils_1__PORT EQU 2
Coils_1__PRT EQU CYREG_PRT2_PRT
Coils_1__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
Coils_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
Coils_1__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
Coils_1__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
Coils_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
Coils_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
Coils_1__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
Coils_1__PS EQU CYREG_PRT2_PS
Coils_1__SHIFT EQU 4
Coils_1__SLW EQU CYREG_PRT2_SLW

; isr_RxD
isr_RxD__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
isr_RxD__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
isr_RxD__INTC_MASK EQU 0x02
isr_RxD__INTC_NUMBER EQU 1
isr_RxD__INTC_PRIOR_NUM EQU 7
isr_RxD__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_1
isr_RxD__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
isr_RxD__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; ADC_SAR_Seq_1_bSAR_SEQ
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB10_11_ACTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB10_11_CTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB10_11_CTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB10_11_CTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB10_11_CTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB10_11_MSK
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB10_11_MSK
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB10_11_MSK
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB10_11_MSK
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB10_ACTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__CONTROL_REG EQU CYREG_B0_UDB10_CTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__CONTROL_ST_REG EQU CYREG_B0_UDB10_ST_CTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__COUNT_REG EQU CYREG_B0_UDB10_CTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__COUNT_ST_REG EQU CYREG_B0_UDB10_ST_CTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB10_MSK_ACTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB10_MSK_ACTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter__PERIOD_REG EQU CYREG_B0_UDB10_MSK
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB10_11_ACTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter_ST__16BIT_STATUS_REG EQU CYREG_B0_UDB10_11_ST
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter_ST__MASK_REG EQU CYREG_B0_UDB10_MSK
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB10_MSK_ACTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB10_MSK_ACTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB10_ACTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter_ST__STATUS_CNT_REG EQU CYREG_B0_UDB10_ST_CTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter_ST__STATUS_CONTROL_REG EQU CYREG_B0_UDB10_ST_CTL
ADC_SAR_Seq_1_bSAR_SEQ_ChannelCounter_ST__STATUS_REG EQU CYREG_B0_UDB10_ST
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__0__MASK EQU 0x01
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__0__POS EQU 0
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__1__MASK EQU 0x02
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__1__POS EQU 1
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB13_14_CTL
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB13_14_CTL
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB13_14_CTL
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB13_14_CTL
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB13_14_MSK
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB13_14_MSK
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB13_14_MSK
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB13_14_MSK
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__CONTROL_REG EQU CYREG_B0_UDB13_CTL
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__CONTROL_ST_REG EQU CYREG_B0_UDB13_ST_CTL
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__COUNT_REG EQU CYREG_B0_UDB13_CTL
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__COUNT_ST_REG EQU CYREG_B0_UDB13_ST_CTL
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__MASK EQU 0x03
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
ADC_SAR_Seq_1_bSAR_SEQ_CtrlReg__PERIOD_REG EQU CYREG_B0_UDB13_MSK
ADC_SAR_Seq_1_bSAR_SEQ_EOCSts__0__MASK EQU 0x01
ADC_SAR_Seq_1_bSAR_SEQ_EOCSts__0__POS EQU 0
ADC_SAR_Seq_1_bSAR_SEQ_EOCSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB08_09_ACTL
ADC_SAR_Seq_1_bSAR_SEQ_EOCSts__16BIT_STATUS_REG EQU CYREG_B0_UDB08_09_ST
ADC_SAR_Seq_1_bSAR_SEQ_EOCSts__MASK EQU 0x01
ADC_SAR_Seq_1_bSAR_SEQ_EOCSts__MASK_REG EQU CYREG_B0_UDB08_MSK
ADC_SAR_Seq_1_bSAR_SEQ_EOCSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB08_ACTL
ADC_SAR_Seq_1_bSAR_SEQ_EOCSts__STATUS_REG EQU CYREG_B0_UDB08_ST

; ADC_SAR_Seq_1_FinalBuf
ADC_SAR_Seq_1_FinalBuf__DRQ_CTL EQU CYREG_IDMUX_DRQ_CTL0
ADC_SAR_Seq_1_FinalBuf__DRQ_NUMBER EQU 0
ADC_SAR_Seq_1_FinalBuf__NUMBEROF_TDS EQU 0
ADC_SAR_Seq_1_FinalBuf__PRIORITY EQU 2
ADC_SAR_Seq_1_FinalBuf__TERMIN_EN EQU 0
ADC_SAR_Seq_1_FinalBuf__TERMIN_SEL EQU 0
ADC_SAR_Seq_1_FinalBuf__TERMOUT0_EN EQU 1
ADC_SAR_Seq_1_FinalBuf__TERMOUT0_SEL EQU 0
ADC_SAR_Seq_1_FinalBuf__TERMOUT1_EN EQU 0
ADC_SAR_Seq_1_FinalBuf__TERMOUT1_SEL EQU 0

; ADC_SAR_Seq_1_IntClock
ADC_SAR_Seq_1_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
ADC_SAR_Seq_1_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
ADC_SAR_Seq_1_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
ADC_SAR_Seq_1_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
ADC_SAR_Seq_1_IntClock__INDEX EQU 0x00
ADC_SAR_Seq_1_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
ADC_SAR_Seq_1_IntClock__PM_ACT_MSK EQU 0x01
ADC_SAR_Seq_1_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
ADC_SAR_Seq_1_IntClock__PM_STBY_MSK EQU 0x01

; ADC_SAR_Seq_1_IRQ
ADC_SAR_Seq_1_IRQ__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
ADC_SAR_Seq_1_IRQ__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
ADC_SAR_Seq_1_IRQ__INTC_MASK EQU 0x01
ADC_SAR_Seq_1_IRQ__INTC_NUMBER EQU 0
ADC_SAR_Seq_1_IRQ__INTC_PRIOR_NUM EQU 7
ADC_SAR_Seq_1_IRQ__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
ADC_SAR_Seq_1_IRQ__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
ADC_SAR_Seq_1_IRQ__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; ADC_SAR_Seq_1_SAR_ADC_SAR
ADC_SAR_Seq_1_SAR_ADC_SAR__CLK EQU CYREG_SAR0_CLK
ADC_SAR_Seq_1_SAR_ADC_SAR__CSR0 EQU CYREG_SAR0_CSR0
ADC_SAR_Seq_1_SAR_ADC_SAR__CSR1 EQU CYREG_SAR0_CSR1
ADC_SAR_Seq_1_SAR_ADC_SAR__CSR2 EQU CYREG_SAR0_CSR2
ADC_SAR_Seq_1_SAR_ADC_SAR__CSR3 EQU CYREG_SAR0_CSR3
ADC_SAR_Seq_1_SAR_ADC_SAR__CSR4 EQU CYREG_SAR0_CSR4
ADC_SAR_Seq_1_SAR_ADC_SAR__CSR5 EQU CYREG_SAR0_CSR5
ADC_SAR_Seq_1_SAR_ADC_SAR__CSR6 EQU CYREG_SAR0_CSR6
ADC_SAR_Seq_1_SAR_ADC_SAR__PM_ACT_CFG EQU CYREG_PM_ACT_CFG11
ADC_SAR_Seq_1_SAR_ADC_SAR__PM_ACT_MSK EQU 0x01
ADC_SAR_Seq_1_SAR_ADC_SAR__PM_STBY_CFG EQU CYREG_PM_STBY_CFG11
ADC_SAR_Seq_1_SAR_ADC_SAR__PM_STBY_MSK EQU 0x01
ADC_SAR_Seq_1_SAR_ADC_SAR__SW0 EQU CYREG_SAR0_SW0
ADC_SAR_Seq_1_SAR_ADC_SAR__SW2 EQU CYREG_SAR0_SW2
ADC_SAR_Seq_1_SAR_ADC_SAR__SW3 EQU CYREG_SAR0_SW3
ADC_SAR_Seq_1_SAR_ADC_SAR__SW4 EQU CYREG_SAR0_SW4
ADC_SAR_Seq_1_SAR_ADC_SAR__SW6 EQU CYREG_SAR0_SW6
ADC_SAR_Seq_1_SAR_ADC_SAR__TR0 EQU CYREG_SAR0_TR0
ADC_SAR_Seq_1_SAR_ADC_SAR__WRK0 EQU CYREG_SAR0_WRK0
ADC_SAR_Seq_1_SAR_ADC_SAR__WRK1 EQU CYREG_SAR0_WRK1

; ADC_SAR_Seq_1_TempBuf
ADC_SAR_Seq_1_TempBuf__DRQ_CTL EQU CYREG_IDMUX_DRQ_CTL0
ADC_SAR_Seq_1_TempBuf__DRQ_NUMBER EQU 1
ADC_SAR_Seq_1_TempBuf__NUMBEROF_TDS EQU 0
ADC_SAR_Seq_1_TempBuf__PRIORITY EQU 2
ADC_SAR_Seq_1_TempBuf__TERMIN_EN EQU 0
ADC_SAR_Seq_1_TempBuf__TERMIN_SEL EQU 0
ADC_SAR_Seq_1_TempBuf__TERMOUT0_EN EQU 1
ADC_SAR_Seq_1_TempBuf__TERMOUT0_SEL EQU 1
ADC_SAR_Seq_1_TempBuf__TERMOUT1_EN EQU 0
ADC_SAR_Seq_1_TempBuf__TERMOUT1_SEL EQU 0

; Miscellaneous
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 12
CYDEV_CHIP_DIE_PSOC5LP EQU 19
CYDEV_CHIP_DIE_PSOC5TM EQU 20
CYDEV_CHIP_DIE_TMA4 EQU 2
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 4
CYDEV_CHIP_FAMILY_FM3 EQU 5
CYDEV_CHIP_FAMILY_FM4 EQU 6
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E161069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 12
CYDEV_CHIP_MEMBER_4C EQU 18
CYDEV_CHIP_MEMBER_4D EQU 8
CYDEV_CHIP_MEMBER_4E EQU 4
CYDEV_CHIP_MEMBER_4F EQU 13
CYDEV_CHIP_MEMBER_4G EQU 2
CYDEV_CHIP_MEMBER_4H EQU 11
CYDEV_CHIP_MEMBER_4I EQU 17
CYDEV_CHIP_MEMBER_4J EQU 9
CYDEV_CHIP_MEMBER_4K EQU 10
CYDEV_CHIP_MEMBER_4L EQU 16
CYDEV_CHIP_MEMBER_4M EQU 15
CYDEV_CHIP_MEMBER_4N EQU 6
CYDEV_CHIP_MEMBER_4O EQU 5
CYDEV_CHIP_MEMBER_4P EQU 14
CYDEV_CHIP_MEMBER_4Q EQU 7
CYDEV_CHIP_MEMBER_4U EQU 3
CYDEV_CHIP_MEMBER_5A EQU 20
CYDEV_CHIP_MEMBER_5B EQU 19
CYDEV_CHIP_MEMBER_FM3 EQU 24
CYDEV_CHIP_MEMBER_FM4 EQU 25
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 21
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 22
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 23
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4C_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000003
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000003
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END
