.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* SS_1 */
.set SS_1__0__INTTYPE, CYREG_PICU15_INTTYPE2
.set SS_1__0__MASK, 0x04
.set SS_1__0__PC, CYREG_IO_PC_PRT15_PC2
.set SS_1__0__PORT, 15
.set SS_1__0__SHIFT, 2
.set SS_1__AG, CYREG_PRT15_AG
.set SS_1__AMUX, CYREG_PRT15_AMUX
.set SS_1__BIE, CYREG_PRT15_BIE
.set SS_1__BIT_MASK, CYREG_PRT15_BIT_MASK
.set SS_1__BYP, CYREG_PRT15_BYP
.set SS_1__CTL, CYREG_PRT15_CTL
.set SS_1__DM0, CYREG_PRT15_DM0
.set SS_1__DM1, CYREG_PRT15_DM1
.set SS_1__DM2, CYREG_PRT15_DM2
.set SS_1__DR, CYREG_PRT15_DR
.set SS_1__INP_DIS, CYREG_PRT15_INP_DIS
.set SS_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU15_BASE
.set SS_1__LCD_COM_SEG, CYREG_PRT15_LCD_COM_SEG
.set SS_1__LCD_EN, CYREG_PRT15_LCD_EN
.set SS_1__MASK, 0x04
.set SS_1__PORT, 15
.set SS_1__PRT, CYREG_PRT15_PRT
.set SS_1__PRTDSI__CAPS_SEL, CYREG_PRT15_CAPS_SEL
.set SS_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT15_DBL_SYNC_IN
.set SS_1__PRTDSI__OE_SEL0, CYREG_PRT15_OE_SEL0
.set SS_1__PRTDSI__OE_SEL1, CYREG_PRT15_OE_SEL1
.set SS_1__PRTDSI__OUT_SEL0, CYREG_PRT15_OUT_SEL0
.set SS_1__PRTDSI__OUT_SEL1, CYREG_PRT15_OUT_SEL1
.set SS_1__PRTDSI__SYNC_OUT, CYREG_PRT15_SYNC_OUT
.set SS_1__PS, CYREG_PRT15_PS
.set SS_1__SHIFT, 2
.set SS_1__SLW, CYREG_PRT15_SLW

/* PWM_1_PWMUDB */
.set PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG, CYREG_B1_UDB05_06_ACTL
.set PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG, CYREG_B1_UDB05_06_CTL
.set PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG, CYREG_B1_UDB05_06_CTL
.set PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG, CYREG_B1_UDB05_06_CTL
.set PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG, CYREG_B1_UDB05_06_CTL
.set PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG, CYREG_B1_UDB05_06_MSK
.set PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG, CYREG_B1_UDB05_06_MSK
.set PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG, CYREG_B1_UDB05_06_MSK
.set PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG, CYREG_B1_UDB05_06_MSK
.set PWM_1_PWMUDB_genblk1_ctrlreg__7__MASK, 0x80
.set PWM_1_PWMUDB_genblk1_ctrlreg__7__POS, 7
.set PWM_1_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG, CYREG_B1_UDB05_ACTL
.set PWM_1_PWMUDB_genblk1_ctrlreg__CONTROL_REG, CYREG_B1_UDB05_CTL
.set PWM_1_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG, CYREG_B1_UDB05_ST_CTL
.set PWM_1_PWMUDB_genblk1_ctrlreg__COUNT_REG, CYREG_B1_UDB05_CTL
.set PWM_1_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG, CYREG_B1_UDB05_ST_CTL
.set PWM_1_PWMUDB_genblk1_ctrlreg__MASK, 0x80
.set PWM_1_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG, CYREG_B1_UDB05_MSK_ACTL
.set PWM_1_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG, CYREG_B1_UDB05_MSK_ACTL
.set PWM_1_PWMUDB_genblk1_ctrlreg__PERIOD_REG, CYREG_B1_UDB05_MSK
.set PWM_1_PWMUDB_genblk8_stsreg__0__MASK, 0x01
.set PWM_1_PWMUDB_genblk8_stsreg__0__POS, 0
.set PWM_1_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG, CYREG_B1_UDB05_06_ACTL
.set PWM_1_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG, CYREG_B1_UDB05_06_ST
.set PWM_1_PWMUDB_genblk8_stsreg__2__MASK, 0x04
.set PWM_1_PWMUDB_genblk8_stsreg__2__POS, 2
.set PWM_1_PWMUDB_genblk8_stsreg__3__MASK, 0x08
.set PWM_1_PWMUDB_genblk8_stsreg__3__POS, 3
.set PWM_1_PWMUDB_genblk8_stsreg__MASK, 0x0D
.set PWM_1_PWMUDB_genblk8_stsreg__MASK_REG, CYREG_B1_UDB05_MSK
.set PWM_1_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG, CYREG_B1_UDB05_MSK_ACTL
.set PWM_1_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG, CYREG_B1_UDB05_MSK_ACTL
.set PWM_1_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG, CYREG_B1_UDB05_ACTL
.set PWM_1_PWMUDB_genblk8_stsreg__STATUS_CNT_REG, CYREG_B1_UDB05_ST_CTL
.set PWM_1_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG, CYREG_B1_UDB05_ST_CTL
.set PWM_1_PWMUDB_genblk8_stsreg__STATUS_REG, CYREG_B1_UDB05_ST
.set PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG, CYREG_B1_UDB04_05_A0
.set PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG, CYREG_B1_UDB04_05_A1
.set PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG, CYREG_B1_UDB04_05_D0
.set PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG, CYREG_B1_UDB04_05_D1
.set PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG, CYREG_B1_UDB04_05_ACTL
.set PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG, CYREG_B1_UDB04_05_F0
.set PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG, CYREG_B1_UDB04_05_F1
.set PWM_1_PWMUDB_sP16_pwmdp_u0__A0_A1_REG, CYREG_B1_UDB04_A0_A1
.set PWM_1_PWMUDB_sP16_pwmdp_u0__A0_REG, CYREG_B1_UDB04_A0
.set PWM_1_PWMUDB_sP16_pwmdp_u0__A1_REG, CYREG_B1_UDB04_A1
.set PWM_1_PWMUDB_sP16_pwmdp_u0__D0_D1_REG, CYREG_B1_UDB04_D0_D1
.set PWM_1_PWMUDB_sP16_pwmdp_u0__D0_REG, CYREG_B1_UDB04_D0
.set PWM_1_PWMUDB_sP16_pwmdp_u0__D1_REG, CYREG_B1_UDB04_D1
.set PWM_1_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG, CYREG_B1_UDB04_ACTL
.set PWM_1_PWMUDB_sP16_pwmdp_u0__F0_F1_REG, CYREG_B1_UDB04_F0_F1
.set PWM_1_PWMUDB_sP16_pwmdp_u0__F0_REG, CYREG_B1_UDB04_F0
.set PWM_1_PWMUDB_sP16_pwmdp_u0__F1_REG, CYREG_B1_UDB04_F1
.set PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_A0_REG, CYREG_B1_UDB05_06_A0
.set PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_A1_REG, CYREG_B1_UDB05_06_A1
.set PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_D0_REG, CYREG_B1_UDB05_06_D0
.set PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_D1_REG, CYREG_B1_UDB05_06_D1
.set PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_DP_AUX_CTL_REG, CYREG_B1_UDB05_06_ACTL
.set PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_F0_REG, CYREG_B1_UDB05_06_F0
.set PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_F1_REG, CYREG_B1_UDB05_06_F1
.set PWM_1_PWMUDB_sP16_pwmdp_u1__A0_A1_REG, CYREG_B1_UDB05_A0_A1
.set PWM_1_PWMUDB_sP16_pwmdp_u1__A0_REG, CYREG_B1_UDB05_A0
.set PWM_1_PWMUDB_sP16_pwmdp_u1__A1_REG, CYREG_B1_UDB05_A1
.set PWM_1_PWMUDB_sP16_pwmdp_u1__D0_D1_REG, CYREG_B1_UDB05_D0_D1
.set PWM_1_PWMUDB_sP16_pwmdp_u1__D0_REG, CYREG_B1_UDB05_D0
.set PWM_1_PWMUDB_sP16_pwmdp_u1__D1_REG, CYREG_B1_UDB05_D1
.set PWM_1_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG, CYREG_B1_UDB05_ACTL
.set PWM_1_PWMUDB_sP16_pwmdp_u1__F0_F1_REG, CYREG_B1_UDB05_F0_F1
.set PWM_1_PWMUDB_sP16_pwmdp_u1__F0_REG, CYREG_B1_UDB05_F0
.set PWM_1_PWMUDB_sP16_pwmdp_u1__F1_REG, CYREG_B1_UDB05_F1
.set PWM_1_PWMUDB_sP16_pwmdp_u1__MSK_DP_AUX_CTL_REG, CYREG_B1_UDB05_MSK_ACTL
.set PWM_1_PWMUDB_sP16_pwmdp_u1__PER_DP_AUX_CTL_REG, CYREG_B1_UDB05_MSK_ACTL

/* isr_1 */
.set isr_1__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set isr_1__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set isr_1__INTC_MASK, 0x01
.set isr_1__INTC_NUMBER, 0
.set isr_1__INTC_PRIOR_NUM, 7
.set isr_1__INTC_PRIOR_REG, CYREG_NVIC_PRI_0
.set isr_1__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set isr_1__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* MISO_1 */
.set MISO_1__0__INTTYPE, CYREG_PICU12_INTTYPE3
.set MISO_1__0__MASK, 0x08
.set MISO_1__0__PC, CYREG_PRT12_PC3
.set MISO_1__0__PORT, 12
.set MISO_1__0__SHIFT, 3
.set MISO_1__AG, CYREG_PRT12_AG
.set MISO_1__BIE, CYREG_PRT12_BIE
.set MISO_1__BIT_MASK, CYREG_PRT12_BIT_MASK
.set MISO_1__BYP, CYREG_PRT12_BYP
.set MISO_1__DM0, CYREG_PRT12_DM0
.set MISO_1__DM1, CYREG_PRT12_DM1
.set MISO_1__DM2, CYREG_PRT12_DM2
.set MISO_1__DR, CYREG_PRT12_DR
.set MISO_1__INP_DIS, CYREG_PRT12_INP_DIS
.set MISO_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set MISO_1__MASK, 0x08
.set MISO_1__PORT, 12
.set MISO_1__PRT, CYREG_PRT12_PRT
.set MISO_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set MISO_1__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set MISO_1__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set MISO_1__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set MISO_1__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set MISO_1__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set MISO_1__PS, CYREG_PRT12_PS
.set MISO_1__SHIFT, 3
.set MISO_1__SIO_CFG, CYREG_PRT12_SIO_CFG
.set MISO_1__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set MISO_1__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set MISO_1__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set MISO_1__SLW, CYREG_PRT12_SLW

/* MOSI_1 */
.set MOSI_1__0__INTTYPE, CYREG_PICU12_INTTYPE2
.set MOSI_1__0__MASK, 0x04
.set MOSI_1__0__PC, CYREG_PRT12_PC2
.set MOSI_1__0__PORT, 12
.set MOSI_1__0__SHIFT, 2
.set MOSI_1__AG, CYREG_PRT12_AG
.set MOSI_1__BIE, CYREG_PRT12_BIE
.set MOSI_1__BIT_MASK, CYREG_PRT12_BIT_MASK
.set MOSI_1__BYP, CYREG_PRT12_BYP
.set MOSI_1__DM0, CYREG_PRT12_DM0
.set MOSI_1__DM1, CYREG_PRT12_DM1
.set MOSI_1__DM2, CYREG_PRT12_DM2
.set MOSI_1__DR, CYREG_PRT12_DR
.set MOSI_1__INP_DIS, CYREG_PRT12_INP_DIS
.set MOSI_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set MOSI_1__MASK, 0x04
.set MOSI_1__PORT, 12
.set MOSI_1__PRT, CYREG_PRT12_PRT
.set MOSI_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set MOSI_1__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set MOSI_1__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set MOSI_1__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set MOSI_1__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set MOSI_1__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set MOSI_1__PS, CYREG_PRT12_PS
.set MOSI_1__SHIFT, 2
.set MOSI_1__SIO_CFG, CYREG_PRT12_SIO_CFG
.set MOSI_1__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set MOSI_1__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set MOSI_1__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set MOSI_1__SLW, CYREG_PRT12_SLW

/* SCLK_1 */
.set SCLK_1__0__INTTYPE, CYREG_PICU15_INTTYPE0
.set SCLK_1__0__MASK, 0x01
.set SCLK_1__0__PC, CYREG_IO_PC_PRT15_PC0
.set SCLK_1__0__PORT, 15
.set SCLK_1__0__SHIFT, 0
.set SCLK_1__AG, CYREG_PRT15_AG
.set SCLK_1__AMUX, CYREG_PRT15_AMUX
.set SCLK_1__BIE, CYREG_PRT15_BIE
.set SCLK_1__BIT_MASK, CYREG_PRT15_BIT_MASK
.set SCLK_1__BYP, CYREG_PRT15_BYP
.set SCLK_1__CTL, CYREG_PRT15_CTL
.set SCLK_1__DM0, CYREG_PRT15_DM0
.set SCLK_1__DM1, CYREG_PRT15_DM1
.set SCLK_1__DM2, CYREG_PRT15_DM2
.set SCLK_1__DR, CYREG_PRT15_DR
.set SCLK_1__INP_DIS, CYREG_PRT15_INP_DIS
.set SCLK_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU15_BASE
.set SCLK_1__LCD_COM_SEG, CYREG_PRT15_LCD_COM_SEG
.set SCLK_1__LCD_EN, CYREG_PRT15_LCD_EN
.set SCLK_1__MASK, 0x01
.set SCLK_1__PORT, 15
.set SCLK_1__PRT, CYREG_PRT15_PRT
.set SCLK_1__PRTDSI__CAPS_SEL, CYREG_PRT15_CAPS_SEL
.set SCLK_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT15_DBL_SYNC_IN
.set SCLK_1__PRTDSI__OE_SEL0, CYREG_PRT15_OE_SEL0
.set SCLK_1__PRTDSI__OE_SEL1, CYREG_PRT15_OE_SEL1
.set SCLK_1__PRTDSI__OUT_SEL0, CYREG_PRT15_OUT_SEL0
.set SCLK_1__PRTDSI__OUT_SEL1, CYREG_PRT15_OUT_SEL1
.set SCLK_1__PRTDSI__SYNC_OUT, CYREG_PRT15_SYNC_OUT
.set SCLK_1__PS, CYREG_PRT15_PS
.set SCLK_1__SHIFT, 0
.set SCLK_1__SLW, CYREG_PRT15_SLW

/* SPIS_1_BSPIS */
.set SPIS_1_BSPIS_BitCounter__16BIT_CONTROL_AUX_CTL_REG, CYREG_B1_UDB06_07_ACTL
.set SPIS_1_BSPIS_BitCounter__16BIT_CONTROL_CONTROL_REG, CYREG_B1_UDB06_07_CTL
.set SPIS_1_BSPIS_BitCounter__16BIT_CONTROL_COUNT_REG, CYREG_B1_UDB06_07_CTL
.set SPIS_1_BSPIS_BitCounter__16BIT_COUNT_CONTROL_REG, CYREG_B1_UDB06_07_CTL
.set SPIS_1_BSPIS_BitCounter__16BIT_COUNT_COUNT_REG, CYREG_B1_UDB06_07_CTL
.set SPIS_1_BSPIS_BitCounter__16BIT_MASK_MASK_REG, CYREG_B1_UDB06_07_MSK
.set SPIS_1_BSPIS_BitCounter__16BIT_MASK_PERIOD_REG, CYREG_B1_UDB06_07_MSK
.set SPIS_1_BSPIS_BitCounter__16BIT_PERIOD_MASK_REG, CYREG_B1_UDB06_07_MSK
.set SPIS_1_BSPIS_BitCounter__16BIT_PERIOD_PERIOD_REG, CYREG_B1_UDB06_07_MSK
.set SPIS_1_BSPIS_BitCounter__CONTROL_AUX_CTL_REG, CYREG_B1_UDB06_ACTL
.set SPIS_1_BSPIS_BitCounter__CONTROL_REG, CYREG_B1_UDB06_CTL
.set SPIS_1_BSPIS_BitCounter__CONTROL_ST_REG, CYREG_B1_UDB06_ST_CTL
.set SPIS_1_BSPIS_BitCounter__COUNT_REG, CYREG_B1_UDB06_CTL
.set SPIS_1_BSPIS_BitCounter__COUNT_ST_REG, CYREG_B1_UDB06_ST_CTL
.set SPIS_1_BSPIS_BitCounter__MASK_CTL_AUX_CTL_REG, CYREG_B1_UDB06_MSK_ACTL
.set SPIS_1_BSPIS_BitCounter__PER_CTL_AUX_CTL_REG, CYREG_B1_UDB06_MSK_ACTL
.set SPIS_1_BSPIS_BitCounter__PERIOD_REG, CYREG_B1_UDB06_MSK
.set SPIS_1_BSPIS_BitCounter_ST__16BIT_STATUS_AUX_CTL_REG, CYREG_B1_UDB06_07_ACTL
.set SPIS_1_BSPIS_BitCounter_ST__16BIT_STATUS_REG, CYREG_B1_UDB06_07_ST
.set SPIS_1_BSPIS_BitCounter_ST__MASK_REG, CYREG_B1_UDB06_MSK
.set SPIS_1_BSPIS_BitCounter_ST__MASK_ST_AUX_CTL_REG, CYREG_B1_UDB06_MSK_ACTL
.set SPIS_1_BSPIS_BitCounter_ST__PER_ST_AUX_CTL_REG, CYREG_B1_UDB06_MSK_ACTL
.set SPIS_1_BSPIS_BitCounter_ST__STATUS_AUX_CTL_REG, CYREG_B1_UDB06_ACTL
.set SPIS_1_BSPIS_BitCounter_ST__STATUS_CNT_REG, CYREG_B1_UDB06_ST_CTL
.set SPIS_1_BSPIS_BitCounter_ST__STATUS_CONTROL_REG, CYREG_B1_UDB06_ST_CTL
.set SPIS_1_BSPIS_BitCounter_ST__STATUS_REG, CYREG_B1_UDB06_ST
.set SPIS_1_BSPIS_RxStsReg__16BIT_STATUS_AUX_CTL_REG, CYREG_B0_UDB07_08_ACTL
.set SPIS_1_BSPIS_RxStsReg__16BIT_STATUS_REG, CYREG_B0_UDB07_08_ST
.set SPIS_1_BSPIS_RxStsReg__3__MASK, 0x08
.set SPIS_1_BSPIS_RxStsReg__3__POS, 3
.set SPIS_1_BSPIS_RxStsReg__4__MASK, 0x10
.set SPIS_1_BSPIS_RxStsReg__4__POS, 4
.set SPIS_1_BSPIS_RxStsReg__5__MASK, 0x20
.set SPIS_1_BSPIS_RxStsReg__5__POS, 5
.set SPIS_1_BSPIS_RxStsReg__6__MASK, 0x40
.set SPIS_1_BSPIS_RxStsReg__6__POS, 6
.set SPIS_1_BSPIS_RxStsReg__MASK, 0x78
.set SPIS_1_BSPIS_RxStsReg__MASK_REG, CYREG_B0_UDB07_MSK
.set SPIS_1_BSPIS_RxStsReg__STATUS_AUX_CTL_REG, CYREG_B0_UDB07_ACTL
.set SPIS_1_BSPIS_RxStsReg__STATUS_REG, CYREG_B0_UDB07_ST
.set SPIS_1_BSPIS_sR8_Dp_u0__16BIT_A0_REG, CYREG_B0_UDB06_07_A0
.set SPIS_1_BSPIS_sR8_Dp_u0__16BIT_A1_REG, CYREG_B0_UDB06_07_A1
.set SPIS_1_BSPIS_sR8_Dp_u0__16BIT_D0_REG, CYREG_B0_UDB06_07_D0
.set SPIS_1_BSPIS_sR8_Dp_u0__16BIT_D1_REG, CYREG_B0_UDB06_07_D1
.set SPIS_1_BSPIS_sR8_Dp_u0__16BIT_DP_AUX_CTL_REG, CYREG_B0_UDB06_07_ACTL
.set SPIS_1_BSPIS_sR8_Dp_u0__16BIT_F0_REG, CYREG_B0_UDB06_07_F0
.set SPIS_1_BSPIS_sR8_Dp_u0__16BIT_F1_REG, CYREG_B0_UDB06_07_F1
.set SPIS_1_BSPIS_sR8_Dp_u0__A0_A1_REG, CYREG_B0_UDB06_A0_A1
.set SPIS_1_BSPIS_sR8_Dp_u0__A0_REG, CYREG_B0_UDB06_A0
.set SPIS_1_BSPIS_sR8_Dp_u0__A1_REG, CYREG_B0_UDB06_A1
.set SPIS_1_BSPIS_sR8_Dp_u0__D0_D1_REG, CYREG_B0_UDB06_D0_D1
.set SPIS_1_BSPIS_sR8_Dp_u0__D0_REG, CYREG_B0_UDB06_D0
.set SPIS_1_BSPIS_sR8_Dp_u0__D1_REG, CYREG_B0_UDB06_D1
.set SPIS_1_BSPIS_sR8_Dp_u0__DP_AUX_CTL_REG, CYREG_B0_UDB06_ACTL
.set SPIS_1_BSPIS_sR8_Dp_u0__F0_F1_REG, CYREG_B0_UDB06_F0_F1
.set SPIS_1_BSPIS_sR8_Dp_u0__F0_REG, CYREG_B0_UDB06_F0
.set SPIS_1_BSPIS_sR8_Dp_u0__F1_REG, CYREG_B0_UDB06_F1
.set SPIS_1_BSPIS_TxStsReg__0__MASK, 0x01
.set SPIS_1_BSPIS_TxStsReg__0__POS, 0
.set SPIS_1_BSPIS_TxStsReg__1__MASK, 0x02
.set SPIS_1_BSPIS_TxStsReg__1__POS, 1
.set SPIS_1_BSPIS_TxStsReg__16BIT_STATUS_AUX_CTL_REG, CYREG_B1_UDB07_08_ACTL
.set SPIS_1_BSPIS_TxStsReg__16BIT_STATUS_REG, CYREG_B1_UDB07_08_ST
.set SPIS_1_BSPIS_TxStsReg__2__MASK, 0x04
.set SPIS_1_BSPIS_TxStsReg__2__POS, 2
.set SPIS_1_BSPIS_TxStsReg__6__MASK, 0x40
.set SPIS_1_BSPIS_TxStsReg__6__POS, 6
.set SPIS_1_BSPIS_TxStsReg__MASK, 0x47
.set SPIS_1_BSPIS_TxStsReg__MASK_REG, CYREG_B1_UDB07_MSK
.set SPIS_1_BSPIS_TxStsReg__STATUS_AUX_CTL_REG, CYREG_B1_UDB07_ACTL
.set SPIS_1_BSPIS_TxStsReg__STATUS_REG, CYREG_B1_UDB07_ST

/* SPIS_1_IntClock */
.set SPIS_1_IntClock__CFG0, CYREG_CLKDIST_DCFG0_CFG0
.set SPIS_1_IntClock__CFG1, CYREG_CLKDIST_DCFG0_CFG1
.set SPIS_1_IntClock__CFG2, CYREG_CLKDIST_DCFG0_CFG2
.set SPIS_1_IntClock__CFG2_SRC_SEL_MASK, 0x07
.set SPIS_1_IntClock__INDEX, 0x00
.set SPIS_1_IntClock__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set SPIS_1_IntClock__PM_ACT_MSK, 0x01
.set SPIS_1_IntClock__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set SPIS_1_IntClock__PM_STBY_MSK, 0x01

/* Step_1 */
.set Step_1__0__INTTYPE, CYREG_PICU3_INTTYPE6
.set Step_1__0__MASK, 0x40
.set Step_1__0__PC, CYREG_PRT3_PC6
.set Step_1__0__PORT, 3
.set Step_1__0__SHIFT, 6
.set Step_1__AG, CYREG_PRT3_AG
.set Step_1__AMUX, CYREG_PRT3_AMUX
.set Step_1__BIE, CYREG_PRT3_BIE
.set Step_1__BIT_MASK, CYREG_PRT3_BIT_MASK
.set Step_1__BYP, CYREG_PRT3_BYP
.set Step_1__CTL, CYREG_PRT3_CTL
.set Step_1__DM0, CYREG_PRT3_DM0
.set Step_1__DM1, CYREG_PRT3_DM1
.set Step_1__DM2, CYREG_PRT3_DM2
.set Step_1__DR, CYREG_PRT3_DR
.set Step_1__INP_DIS, CYREG_PRT3_INP_DIS
.set Step_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU3_BASE
.set Step_1__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set Step_1__LCD_EN, CYREG_PRT3_LCD_EN
.set Step_1__MASK, 0x40
.set Step_1__PORT, 3
.set Step_1__PRT, CYREG_PRT3_PRT
.set Step_1__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set Step_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set Step_1__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set Step_1__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set Step_1__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set Step_1__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set Step_1__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set Step_1__PS, CYREG_PRT3_PS
.set Step_1__SHIFT, 6
.set Step_1__SLW, CYREG_PRT3_SLW

/* Clock_1 */
.set Clock_1__CFG0, CYREG_CLKDIST_DCFG1_CFG0
.set Clock_1__CFG1, CYREG_CLKDIST_DCFG1_CFG1
.set Clock_1__CFG2, CYREG_CLKDIST_DCFG1_CFG2
.set Clock_1__CFG2_SRC_SEL_MASK, 0x07
.set Clock_1__INDEX, 0x01
.set Clock_1__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set Clock_1__PM_ACT_MSK, 0x02
.set Clock_1__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set Clock_1__PM_STBY_MSK, 0x02

/* Enable_1 */
.set Enable_1__0__INTTYPE, CYREG_PICU1_INTTYPE2
.set Enable_1__0__MASK, 0x04
.set Enable_1__0__PC, CYREG_PRT1_PC2
.set Enable_1__0__PORT, 1
.set Enable_1__0__SHIFT, 2
.set Enable_1__AG, CYREG_PRT1_AG
.set Enable_1__AMUX, CYREG_PRT1_AMUX
.set Enable_1__BIE, CYREG_PRT1_BIE
.set Enable_1__BIT_MASK, CYREG_PRT1_BIT_MASK
.set Enable_1__BYP, CYREG_PRT1_BYP
.set Enable_1__CTL, CYREG_PRT1_CTL
.set Enable_1__DM0, CYREG_PRT1_DM0
.set Enable_1__DM1, CYREG_PRT1_DM1
.set Enable_1__DM2, CYREG_PRT1_DM2
.set Enable_1__DR, CYREG_PRT1_DR
.set Enable_1__INP_DIS, CYREG_PRT1_INP_DIS
.set Enable_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU1_BASE
.set Enable_1__LCD_COM_SEG, CYREG_PRT1_LCD_COM_SEG
.set Enable_1__LCD_EN, CYREG_PRT1_LCD_EN
.set Enable_1__MASK, 0x04
.set Enable_1__PORT, 1
.set Enable_1__PRT, CYREG_PRT1_PRT
.set Enable_1__PRTDSI__CAPS_SEL, CYREG_PRT1_CAPS_SEL
.set Enable_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT1_DBL_SYNC_IN
.set Enable_1__PRTDSI__OE_SEL0, CYREG_PRT1_OE_SEL0
.set Enable_1__PRTDSI__OE_SEL1, CYREG_PRT1_OE_SEL1
.set Enable_1__PRTDSI__OUT_SEL0, CYREG_PRT1_OUT_SEL0
.set Enable_1__PRTDSI__OUT_SEL1, CYREG_PRT1_OUT_SEL1
.set Enable_1__PRTDSI__SYNC_OUT, CYREG_PRT1_SYNC_OUT
.set Enable_1__PS, CYREG_PRT1_PS
.set Enable_1__SHIFT, 2
.set Enable_1__SLW, CYREG_PRT1_SLW

/* pwm_isr_1 */
.set pwm_isr_1__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set pwm_isr_1__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set pwm_isr_1__INTC_MASK, 0x02
.set pwm_isr_1__INTC_NUMBER, 1
.set pwm_isr_1__INTC_PRIOR_NUM, 7
.set pwm_isr_1__INTC_PRIOR_REG, CYREG_NVIC_PRI_1
.set pwm_isr_1__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set pwm_isr_1__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* Direction_1 */
.set Direction_1__0__INTTYPE, CYREG_PICU0_INTTYPE1
.set Direction_1__0__MASK, 0x02
.set Direction_1__0__PC, CYREG_PRT0_PC1
.set Direction_1__0__PORT, 0
.set Direction_1__0__SHIFT, 1
.set Direction_1__AG, CYREG_PRT0_AG
.set Direction_1__AMUX, CYREG_PRT0_AMUX
.set Direction_1__BIE, CYREG_PRT0_BIE
.set Direction_1__BIT_MASK, CYREG_PRT0_BIT_MASK
.set Direction_1__BYP, CYREG_PRT0_BYP
.set Direction_1__CTL, CYREG_PRT0_CTL
.set Direction_1__DM0, CYREG_PRT0_DM0
.set Direction_1__DM1, CYREG_PRT0_DM1
.set Direction_1__DM2, CYREG_PRT0_DM2
.set Direction_1__DR, CYREG_PRT0_DR
.set Direction_1__INP_DIS, CYREG_PRT0_INP_DIS
.set Direction_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set Direction_1__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set Direction_1__LCD_EN, CYREG_PRT0_LCD_EN
.set Direction_1__MASK, 0x02
.set Direction_1__PORT, 0
.set Direction_1__PRT, CYREG_PRT0_PRT
.set Direction_1__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set Direction_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set Direction_1__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set Direction_1__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set Direction_1__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set Direction_1__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set Direction_1__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set Direction_1__PS, CYREG_PRT0_PS
.set Direction_1__SHIFT, 1
.set Direction_1__SLW, CYREG_PRT0_SLW

/* Miscellaneous */
.set BCLK__BUS_CLK__HZ, 24000000
.set BCLK__BUS_CLK__KHZ, 24000
.set BCLK__BUS_CLK__MHZ, 24
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PSOC4A, 12
.set CYDEV_CHIP_DIE_PSOC5LP, 19
.set CYDEV_CHIP_DIE_PSOC5TM, 20
.set CYDEV_CHIP_DIE_TMA4, 2
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_FM0P, 4
.set CYDEV_CHIP_FAMILY_FM3, 5
.set CYDEV_CHIP_FAMILY_FM4, 6
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E161069
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 12
.set CYDEV_CHIP_MEMBER_4C, 18
.set CYDEV_CHIP_MEMBER_4D, 8
.set CYDEV_CHIP_MEMBER_4E, 4
.set CYDEV_CHIP_MEMBER_4F, 13
.set CYDEV_CHIP_MEMBER_4G, 2
.set CYDEV_CHIP_MEMBER_4H, 11
.set CYDEV_CHIP_MEMBER_4I, 17
.set CYDEV_CHIP_MEMBER_4J, 9
.set CYDEV_CHIP_MEMBER_4K, 10
.set CYDEV_CHIP_MEMBER_4L, 16
.set CYDEV_CHIP_MEMBER_4M, 15
.set CYDEV_CHIP_MEMBER_4N, 6
.set CYDEV_CHIP_MEMBER_4O, 5
.set CYDEV_CHIP_MEMBER_4P, 14
.set CYDEV_CHIP_MEMBER_4Q, 7
.set CYDEV_CHIP_MEMBER_4U, 3
.set CYDEV_CHIP_MEMBER_5A, 20
.set CYDEV_CHIP_MEMBER_5B, 19
.set CYDEV_CHIP_MEMBER_FM3, 24
.set CYDEV_CHIP_MEMBER_FM4, 25
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1, 21
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2, 22
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3, 23
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES0, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES1, 1
.set CYDEV_CHIP_REV_PSOC5TM_PRODUCTION, 1
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4C_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4P_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Q_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM4_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_DMA, 0
.set CYDEV_CONFIGURATION_ECC, 1
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS_SWD_SWV, 6
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD_SWV
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_XRES, 0
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 0
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_INSTRUCT_CACHE_ENABLED, 1
.set CYDEV_INTR_RISING, 0x00000003
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x0800
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3_MV, 5000
.set CYIPBLOCK_ARM_CM3_VERSION, 0
.set CYIPBLOCK_P3_ANAIF_VERSION, 0
.set CYIPBLOCK_P3_CAN_VERSION, 0
.set CYIPBLOCK_P3_CAPSENSE_VERSION, 0
.set CYIPBLOCK_P3_COMP_VERSION, 0
.set CYIPBLOCK_P3_DECIMATOR_VERSION, 0
.set CYIPBLOCK_P3_DFB_VERSION, 0
.set CYIPBLOCK_P3_DMA_VERSION, 0
.set CYIPBLOCK_P3_DRQ_VERSION, 0
.set CYIPBLOCK_P3_DSM_VERSION, 0
.set CYIPBLOCK_P3_EMIF_VERSION, 0
.set CYIPBLOCK_P3_I2C_VERSION, 0
.set CYIPBLOCK_P3_LCD_VERSION, 0
.set CYIPBLOCK_P3_LPF_VERSION, 0
.set CYIPBLOCK_P3_OPAMP_VERSION, 0
.set CYIPBLOCK_P3_PM_VERSION, 0
.set CYIPBLOCK_P3_SCCT_VERSION, 0
.set CYIPBLOCK_P3_TIMER_VERSION, 0
.set CYIPBLOCK_P3_USB_VERSION, 0
.set CYIPBLOCK_P3_VIDAC_VERSION, 0
.set CYIPBLOCK_P3_VREF_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 0
.set CYIPBLOCK_S8_IRQ_VERSION, 0
.set CYIPBLOCK_S8_SAR_VERSION, 0
.set CYIPBLOCK_S8_SIO_VERSION, 0
.set CYIPBLOCK_S8_UDB_VERSION, 0
.set DMA_CHANNELS_USED__MASK0, 0x00000000
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif
