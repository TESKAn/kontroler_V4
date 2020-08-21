/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name: initconfig.h$
*
* $Date:      Jun-25-2013$
*
* $Version:   2.5.39.0$
*
* Description: This file is used to collect statistics about modules configured
*              in the "appconfig.h" file. The information is used to optimize 
*              initialization function of each peripheral module.
*
******************************************************************************/

#ifndef __INITCONFIG_H
#define __INITCONFIG_H

#if defined (ADC_A_ADCCAL_INIT) || \
    defined (ADC_A_ADCPOWER_INIT) || \
    defined (ADC_A_ADCR1_INIT) || \
    defined (ADC_A_ADCR2_INIT) || \
    defined (ADC_A_ADHLMT0_INIT) || \
    defined (ADC_A_ADHLMT1_INIT) || \
    defined (ADC_A_ADHLMT2_INIT) || \
    defined (ADC_A_ADHLMT3_INIT) || \
    defined (ADC_A_ADHLMT4_INIT) || \
    defined (ADC_A_ADHLMT5_INIT) || \
    defined (ADC_A_ADHLMT6_INIT) || \
    defined (ADC_A_ADHLMT7_INIT) || \
    defined (ADC_A_ADLLMT0_INIT) || \
    defined (ADC_A_ADLLMT1_INIT) || \
    defined (ADC_A_ADLLMT2_INIT) || \
    defined (ADC_A_ADLLMT3_INIT) || \
    defined (ADC_A_ADLLMT4_INIT) || \
    defined (ADC_A_ADLLMT5_INIT) || \
    defined (ADC_A_ADLLMT6_INIT) || \
    defined (ADC_A_ADLLMT7_INIT) || \
    defined (ADC_A_ADLST1_INIT) || \
    defined (ADC_A_ADLST2_INIT) || \
    defined (ADC_A_ADLST3_INIT) || \
    defined (ADC_A_ADLST4_INIT) || \
    defined (ADC_A_ADOFS0_INIT) || \
    defined (ADC_A_ADOFS1_INIT) || \
    defined (ADC_A_ADOFS2_INIT) || \
    defined (ADC_A_ADOFS3_INIT) || \
    defined (ADC_A_ADOFS4_INIT) || \
    defined (ADC_A_ADOFS5_INIT) || \
    defined (ADC_A_ADOFS6_INIT) || \
    defined (ADC_A_ADOFS7_INIT) || \
    defined (ADC_A_ADSDIS_INIT) || \
    defined (ADC_A_ADZCC_INIT)
#define ADC_A_INIT_USED 1
#endif

#if defined (ADC_B_ADCCAL_INIT) || \
    defined (ADC_B_ADCPOWER_INIT) || \
    defined (ADC_B_ADCR1_INIT) || \
    defined (ADC_B_ADCR2_INIT) || \
    defined (ADC_B_ADHLMT0_INIT) || \
    defined (ADC_B_ADHLMT1_INIT) || \
    defined (ADC_B_ADHLMT2_INIT) || \
    defined (ADC_B_ADHLMT3_INIT) || \
    defined (ADC_B_ADHLMT4_INIT) || \
    defined (ADC_B_ADHLMT5_INIT) || \
    defined (ADC_B_ADHLMT6_INIT) || \
    defined (ADC_B_ADHLMT7_INIT) || \
    defined (ADC_B_ADLLMT0_INIT) || \
    defined (ADC_B_ADLLMT1_INIT) || \
    defined (ADC_B_ADLLMT2_INIT) || \
    defined (ADC_B_ADLLMT3_INIT) || \
    defined (ADC_B_ADLLMT4_INIT) || \
    defined (ADC_B_ADLLMT5_INIT) || \
    defined (ADC_B_ADLLMT6_INIT) || \
    defined (ADC_B_ADLLMT7_INIT) || \
    defined (ADC_B_ADLST1_INIT) || \
    defined (ADC_B_ADLST2_INIT) || \
    defined (ADC_B_ADLST3_INIT) || \
    defined (ADC_B_ADLST4_INIT) || \
    defined (ADC_B_ADOFS0_INIT) || \
    defined (ADC_B_ADOFS1_INIT) || \
    defined (ADC_B_ADOFS2_INIT) || \
    defined (ADC_B_ADOFS3_INIT) || \
    defined (ADC_B_ADOFS4_INIT) || \
    defined (ADC_B_ADOFS5_INIT) || \
    defined (ADC_B_ADOFS6_INIT) || \
    defined (ADC_B_ADOFS7_INIT) || \
    defined (ADC_B_ADSDIS_INIT) || \
    defined (ADC_B_ADZCC_INIT)
#define ADC_B_INIT_USED 1
#endif

#if defined (ADC_ADCCAL_INIT) || \
    defined (ADC_ADCPOWER_INIT) || \
    defined (ADC_ADCR1_INIT) || \
    defined (ADC_ADCR2_INIT) || \
    defined (ADC_ADHLMT0_INIT) || \
    defined (ADC_ADHLMT1_INIT) || \
    defined (ADC_ADHLMT2_INIT) || \
    defined (ADC_ADHLMT3_INIT) || \
    defined (ADC_ADHLMT4_INIT) || \
    defined (ADC_ADHLMT5_INIT) || \
    defined (ADC_ADHLMT6_INIT) || \
    defined (ADC_ADHLMT7_INIT) || \
    defined (ADC_ADHLMT8_INIT) || \
    defined (ADC_ADHLMT9_INIT) || \
    defined (ADC_ADHLMT10_INIT) || \
    defined (ADC_ADHLMT11_INIT) || \
    defined (ADC_ADHLMT12_INIT) || \
    defined (ADC_ADHLMT13_INIT) || \
    defined (ADC_ADHLMT14_INIT) || \
    defined (ADC_ADHLMT15_INIT) || \
    defined (ADC_ADLLMT0_INIT) || \
    defined (ADC_ADLLMT1_INIT) || \
    defined (ADC_ADLLMT2_INIT) || \
    defined (ADC_ADLLMT3_INIT) || \
    defined (ADC_ADLLMT4_INIT) || \
    defined (ADC_ADLLMT5_INIT) || \
    defined (ADC_ADLLMT6_INIT) || \
    defined (ADC_ADLLMT7_INIT) || \
    defined (ADC_ADLLMT8_INIT) || \
    defined (ADC_ADLLMT9_INIT) || \
    defined (ADC_ADLLMT10_INIT) || \
    defined (ADC_ADLLMT11_INIT) || \
    defined (ADC_ADLLMT12_INIT) || \
    defined (ADC_ADLLMT13_INIT) || \
    defined (ADC_ADLLMT14_INIT) || \
    defined (ADC_ADLLMT15_INIT) || \
    defined (ADC_ADLST1_INIT) || \
    defined (ADC_ADLST2_INIT) || \
    defined (ADC_ADLST3_INIT) || \
    defined (ADC_ADLST4_INIT) || \
    defined (ADC_ADOFS0_INIT) || \
    defined (ADC_ADOFS1_INIT) || \
    defined (ADC_ADOFS2_INIT) || \
    defined (ADC_ADOFS3_INIT) || \
    defined (ADC_ADOFS4_INIT) || \
    defined (ADC_ADOFS5_INIT) || \
    defined (ADC_ADOFS6_INIT) || \
    defined (ADC_ADOFS7_INIT) || \
    defined (ADC_ADOFS8_INIT) || \
    defined (ADC_ADOFS9_INIT) || \
    defined (ADC_ADOFS10_INIT) || \
    defined (ADC_ADOFS11_INIT) || \
    defined (ADC_ADOFS12_INIT) || \
    defined (ADC_ADOFS13_INIT) || \
    defined (ADC_ADOFS14_INIT) || \
    defined (ADC_ADOFS15_INIT) || \
    defined (ADC_ADSDIS_INIT) || \
    defined (ADC_ADZCC_INIT) || \
    defined (ADC_ZXCTRL1_INIT) || \
    defined (ADC_ZXCTRL2_INIT) || \
    defined (ADC_ADCR3_INIT) || \
    defined (ADC_SCHLTEN_INIT)
#define ADC_INIT_USED 1
#endif

#if defined (ADC_1_ADCCAL_INIT) || \
    defined (ADC_1_ADCPOWER_INIT) || \
    defined (ADC_1_ADCR1_INIT) || \
    defined (ADC_1_ADCR2_INIT) || \
    defined (ADC_1_ADHLMT0_INIT) || \
    defined (ADC_1_ADHLMT1_INIT) || \
    defined (ADC_1_ADHLMT2_INIT) || \
    defined (ADC_1_ADHLMT3_INIT) || \
    defined (ADC_1_ADHLMT4_INIT) || \
    defined (ADC_1_ADHLMT5_INIT) || \
    defined (ADC_1_ADHLMT6_INIT) || \
    defined (ADC_1_ADHLMT7_INIT) || \
    defined (ADC_1_ADHLMT8_INIT) || \
    defined (ADC_1_ADHLMT9_INIT) || \
    defined (ADC_1_ADHLMT10_INIT) || \
    defined (ADC_1_ADHLMT11_INIT) || \
    defined (ADC_1_ADHLMT12_INIT) || \
    defined (ADC_1_ADHLMT13_INIT) || \
    defined (ADC_1_ADHLMT14_INIT) || \
    defined (ADC_1_ADHLMT15_INIT) || \
    defined (ADC_1_ADLLMT0_INIT) || \
    defined (ADC_1_ADLLMT1_INIT) || \
    defined (ADC_1_ADLLMT2_INIT) || \
    defined (ADC_1_ADLLMT3_INIT) || \
    defined (ADC_1_ADLLMT4_INIT) || \
    defined (ADC_1_ADLLMT5_INIT) || \
    defined (ADC_1_ADLLMT6_INIT) || \
    defined (ADC_1_ADLLMT7_INIT) || \
    defined (ADC_1_ADLLMT8_INIT) || \
    defined (ADC_1_ADLLMT9_INIT) || \
    defined (ADC_1_ADLLMT10_INIT) || \
    defined (ADC_1_ADLLMT11_INIT) || \
    defined (ADC_1_ADLLMT12_INIT) || \
    defined (ADC_1_ADLLMT13_INIT) || \
    defined (ADC_1_ADLLMT14_INIT) || \
    defined (ADC_1_ADLLMT15_INIT) || \
    defined (ADC_1_ADLST1_INIT) || \
    defined (ADC_1_ADLST2_INIT) || \
    defined (ADC_1_ADLST3_INIT) || \
    defined (ADC_1_ADLST4_INIT) || \
    defined (ADC_1_ADOFS0_INIT) || \
    defined (ADC_1_ADOFS1_INIT) || \
    defined (ADC_1_ADOFS2_INIT) || \
    defined (ADC_1_ADOFS3_INIT) || \
    defined (ADC_1_ADOFS4_INIT) || \
    defined (ADC_1_ADOFS5_INIT) || \
    defined (ADC_1_ADOFS6_INIT) || \
    defined (ADC_1_ADOFS7_INIT) || \
    defined (ADC_1_ADOFS8_INIT) || \
    defined (ADC_1_ADOFS9_INIT) || \
    defined (ADC_1_ADOFS10_INIT) || \
    defined (ADC_1_ADOFS11_INIT) || \
    defined (ADC_1_ADOFS12_INIT) || \
    defined (ADC_1_ADOFS13_INIT) || \
    defined (ADC_1_ADOFS14_INIT) || \
    defined (ADC_1_ADOFS15_INIT) || \
    defined (ADC_1_ADSDIS_INIT) || \
    defined (ADC_1_ADZCC_INIT) || \
    defined (ADC_1_ZXCTRL1_INIT) || \
    defined (ADC_1_ZXCTRL2_INIT) || \
    defined (ADC_1_ADCR3_INIT) || \
    defined (ADC_1_SCHLTEN_INIT)
#define ADC_1_INIT_USED 1
#endif

#if defined (ADC_0_ADCS2_INIT) || \
    defined (ADC_0_ADCCFG_INIT) || \
    defined (ADC_0_ADCSC1A_INIT) || \
    defined (ADC_0_ADCSC1B_INIT)
#define ADC_0_INIT_USED 1
#endif

#if defined (ADC_1_ADCS2_INIT) || \
    defined (ADC_1_ADCCFG_INIT) || \
    defined (ADC_1_ADCSC1A_INIT) || \
    defined (ADC_1_ADCSC1B_INIT)
#define ADC_1_INIT_USED 1
#endif


#if defined (DEC_0_DECCR_INIT) || \
    defined (DEC_0_FIR_INIT) || \
    defined (DEC_0_LIR_INIT) || \
    defined (DEC_0_UIR_INIT) || \
    defined (DEC_0_WTR_INIT)
#define DEC_0_INIT_USED 1
#endif

#if defined (DEC_1_DECCR_INIT) || \
    defined (DEC_1_FIR_INIT) || \
    defined (DEC_1_LIR_INIT) || \
    defined (DEC_1_UIR_INIT) || \
    defined (DEC_1_WTR_INIT)
#define DEC_1_INIT_USED 1
#endif

#if defined (DEC_DECCR_INIT) || \
    defined (DEC_FIR_INIT) || \
    defined (DEC_LIR_INIT) || \
    defined (DEC_UIR_INIT) || \
    defined (DEC_WTR_INIT)
#define DEC_INIT_USED 1
#endif

#if defined (FCAN_CTL0_INIT) || \
    defined (FCAN_CTL1_INIT) || \
    defined (FCAN_IMASK1_INIT) || \
    defined (FCAN_MCR_INIT) || \
    defined (FCAN_RX14MASKH_INIT) || \
    defined (FCAN_RX14MASKL_INIT) || \
    defined (FCAN_RX15MASKH_INIT) || \
    defined (FCAN_RX15MASKL_INIT) || \
    defined (FCAN_RXGMASKH_INIT) || \
    defined (FCAN_RXGMASKL_INIT) || \
    defined (FCAN_CTRL1_INIT) || \
    defined (FCAN_CTRL2_INIT) || \
    defined (FCAN_IMASK1_INIT) || \
    defined (FCAN_RXMGMASK_INIT) || \
    defined (FCAN_RXFGMASK_INIT) || \
    defined (FCAN_RX14MASK_INIT) || \
    defined (FCAN_RX15MASK_INIT) || \
    defined (FCAN_RXIMR0_INIT) || \
    defined (FCAN_RXIMR1_INIT) || \
    defined (FCAN_RXIMR2_INIT) || \
    defined (FCAN_RXIMR3_INIT) || \
    defined (FCAN_RXIMR4_INIT) || \
    defined (FCAN_RXIMR5_INIT) || \
    defined (FCAN_RXIMR6_INIT) || \
    defined (FCAN_RXIMR7_INIT) || \
    defined (FCAN_RXIMR8_INIT) || \
    defined (FCAN_RXIMR9_INIT) || \
    defined (FCAN_RXIMR10_INIT) || \
    defined (FCAN_RXIMR11_INIT) || \
    defined (FCAN_RXIMR12_INIT) || \
    defined (FCAN_RXIMR13_INIT) || \
    defined (FCAN_RXIMR14_INIT) || \
    defined (FCAN_RXIMR15_INIT) || \
    defined (FCAN_RXIMR16_INIT) || \
    defined (FCAN_RXIMR17_INIT) || \
    defined (FCAN_RXIMR18_INIT) || \
    defined (FCAN_RXIMR19_INIT) || \
    defined (FCAN_RXIMR20_INIT) || \
    defined (FCAN_RXIMR21_INIT) || \
    defined (FCAN_RXIMR22_INIT) || \
    defined (FCAN_RXIMR23_INIT) || \
    defined (FCAN_RXIMR24_INIT) || \
    defined (FCAN_RXIMR25_INIT) || \
    defined (FCAN_RXIMR26_INIT) || \
    defined (FCAN_RXIMR27_INIT) || \
    defined (FCAN_RXIMR28_INIT) || \
    defined (FCAN_RXIMR29_INIT) || \
    defined (FCAN_RXIMR30_INIT) || \
    defined (FCAN_RXIMR31_INIT)
#define FCAN_INIT_USED 1
#endif

#if defined (FCAN2_CTL0_INIT) || \
    defined (FCAN2_CTL1_INIT) || \
    defined (FCAN2_IMASK1_INIT) || \
    defined (FCAN2_MCR_INIT) || \
    defined (FCAN2_RX14MASKH_INIT) || \
    defined (FCAN2_RX14MASKL_INIT) || \
    defined (FCAN2_RX15MASKH_INIT) || \
    defined (FCAN2_RX15MASKL_INIT) || \
    defined (FCAN2_RXGMASKH_INIT) || \
    defined (FCAN2_RXGMASKL_INIT)
#define FCAN2_INIT_USED 1
#endif

#if defined (GPIO_A_DDR_INIT) || \
    defined (GPIO_A_DRIVE_INIT) || \
    defined (GPIO_A_DR_INIT) || \
    defined (GPIO_A_IENR_INIT) || \
    defined (GPIO_A_IPOLR_INIT) || \
    defined (GPIO_A_PER_INIT) || \
    defined (GPIO_A_PPMODE_INIT) || \
    defined (GPIO_A_PUR_INIT) || \
    defined (GPIO_A_PUS_INIT) || \
    defined (GPIO_A_SRE_INIT)
#define GPIO_A_INIT_USED 1
#endif

#if defined (GPIO_B_DDR_INIT) || \
    defined (GPIO_B_DRIVE_INIT) || \
    defined (GPIO_B_DR_INIT) || \
    defined (GPIO_B_IENR_INIT) || \
    defined (GPIO_B_IPOLR_INIT) || \
    defined (GPIO_B_PER_INIT) || \
    defined (GPIO_B_PPMODE_INIT) || \
    defined (GPIO_B_PUR_INIT) || \
    defined (GPIO_B_PUS_INIT) || \
    defined (GPIO_B_SRE_INIT)
#define GPIO_B_INIT_USED 1
#endif

#if defined (GPIO_C_DDR_INIT) || \
    defined (GPIO_C_DRIVE_INIT) || \
    defined (GPIO_C_DR_INIT) || \
    defined (GPIO_C_IENR_INIT) || \
    defined (GPIO_C_IPOLR_INIT) || \
    defined (GPIO_C_PER_INIT) || \
    defined (GPIO_C_PPMODE_INIT) || \
    defined (GPIO_C_PUR_INIT) || \
    defined (GPIO_C_PUS_INIT) || \
    defined (GPIO_C_SRE_INIT)
#define GPIO_C_INIT_USED 1
#endif

#if defined (GPIO_D_DDR_INIT) || \
    defined (GPIO_D_DRIVE_INIT) || \
    defined (GPIO_D_DR_INIT) || \
    defined (GPIO_D_IENR_INIT) || \
    defined (GPIO_D_IPOLR_INIT) || \
    defined (GPIO_D_PER_INIT) || \
    defined (GPIO_D_PPMODE_INIT) || \
    defined (GPIO_D_PUR_INIT) || \
    defined (GPIO_D_PUS_INIT) || \
    defined (GPIO_D_SRE_INIT)
#define GPIO_D_INIT_USED 1
#endif

#if defined (GPIO_E_DDR_INIT) || \
    defined (GPIO_E_DRIVE_INIT) || \
    defined (GPIO_E_DR_INIT) || \
    defined (GPIO_E_IENR_INIT) || \
    defined (GPIO_E_IPOLR_INIT) || \
    defined (GPIO_E_PER_INIT) || \
    defined (GPIO_E_PPMODE_INIT) || \
    defined (GPIO_E_PUR_INIT) || \
    defined (GPIO_E_PUS_INIT) || \
    defined (GPIO_E_SRE_INIT)
#define GPIO_E_INIT_USED 1
#endif

#if defined (GPIO_F_DDR_INIT) || \
    defined (GPIO_F_DRIVE_INIT) || \
    defined (GPIO_F_DR_INIT) || \
    defined (GPIO_F_IENR_INIT) || \
    defined (GPIO_F_IPOLR_INIT) || \
    defined (GPIO_F_PER_INIT) || \
    defined (GPIO_F_PPMODE_INIT) || \
    defined (GPIO_F_PUR_INIT) || \
    defined (GPIO_F_PUR_INIT) || \
    defined (GPIO_F_PUS_INIT) || \
    defined (GPIO_F_SRE_INIT)
#define GPIO_F_INIT_USED 1
#endif

#if defined (GPIO_G_DDR_INIT) || \
    defined (GPIO_G_DRIVE_INIT) || \
    defined (GPIO_G_DR_INIT) || \
    defined (GPIO_G_IENR_INIT) || \
    defined (GPIO_G_IPOLR_INIT) || \
    defined (GPIO_G_PER_INIT) || \
    defined (GPIO_G_PPMODE_INIT) || \
    defined (GPIO_G_PUR_INIT) || \
    defined (GPIO_G_PUR_INIT) || \
    defined (GPIO_G_PUS_INIT) || \
    defined (GPIO_G_SRE_INIT)
#define GPIO_G_INIT_USED 1
#endif

#if defined (PWM_A_PMCCR_INIT) || \
    defined (PWM_A_PMCFG_INIT) || \
    defined (PWM_A_PMCTL_INIT) || \
    defined (PWM_A_PMDEADTM0_INIT) || \
    defined (PWM_A_PMDEADTM1_INIT) || \
    defined (PWM_A_PMDEADTM_INIT) || \
    defined (PWM_A_PMDISMAP1_INIT) || \
    defined (PWM_A_PMDISMAP2_INIT) || \
    defined (PWM_A_PMFCTL_INIT) || \
    defined (PWM_A_PMICCR_INIT) || \
    defined (PWM_A_PMOUT_INIT) || \
    defined (PWM_A_PMSRC_INIT) || \
    defined (PWM_A_SYNC_INIT) || \
    defined (PWM_A_FFILT0_INIT) || \
    defined (PWM_A_FFILT1_INIT) || \
    defined (PWM_A_FFILT2_INIT) || \
    defined (PWM_A_FFILT3_INIT) || \
    defined (PWM_A_PWMCM_INIT) || \
    defined (PWM_A_PWMVAL0_INIT) || \
    defined (PWM_A_PWMVAL1_INIT) || \
    defined (PWM_A_PWMVAL2_INIT) || \
    defined (PWM_A_PWMVAL3_INIT) || \
    defined (PWM_A_PWMVAL4_INIT) || \
    defined (PWM_A_PWMVAL5_INIT)
#define PWM_A_INIT_USED 1
#endif

#if defined (PWM_B_PMCCR_INIT) || \
    defined (PWM_B_PMCFG_INIT) || \
    defined (PWM_B_PMCTL_INIT) || \
    defined (PWM_B_PMDEADTM0_INIT) || \
    defined (PWM_B_PMDEADTM1_INIT) || \
    defined (PWM_B_PMDEADTM_INIT) || \
    defined (PWM_B_PMDISMAP1_INIT) || \
    defined (PWM_B_PMDISMAP2_INIT) || \
    defined (PWM_B_PMFCTL_INIT) || \
    defined (PWM_B_PMICCR_INIT) || \
    defined (PWM_B_PMOUT_INIT) || \
    defined (PWM_B_PMSRC_INIT) || \
    defined (PWM_B_SYNC_INIT) || \
    defined (PWM_B_FFILT0_INIT) || \
    defined (PWM_B_FFILT1_INIT) || \
    defined (PWM_B_FFILT2_INIT) || \
    defined (PWM_B_FFILT3_INIT) || \
    defined (PWM_B_PWMCM_INIT) || \
    defined (PWM_B_PWMVAL0_INIT) || \
    defined (PWM_B_PWMVAL1_INIT) || \
    defined (PWM_B_PWMVAL2_INIT) || \
    defined (PWM_B_PWMVAL3_INIT) || \
    defined (PWM_B_PWMVAL4_INIT) || \
    defined (PWM_B_PWMVAL5_INIT)
#define PWM_B_INIT_USED 1
#endif

#if defined (PWM_PMCCR_INIT) || \
    defined (PWM_PMCFG_INIT) || \
    defined (PWM_PMCTL_INIT) || \
    defined (PWM_PMDEADTM0_INIT) || \
    defined (PWM_PMDEADTM1_INIT) || \
    defined (PWM_PMDEADTM_INIT) || \
    defined (PWM_PMDISMAP1_INIT) || \
    defined (PWM_PMDISMAP2_INIT) || \
    defined (PWM_PMFCTL_INIT) || \
    defined (PWM_PMICCR_INIT) || \
    defined (PWM_PMOUT_INIT) || \
    defined (PWM_PMSRC_INIT) || \
    defined (PWM_SYNC_INIT) || \
    defined (PWM_FFILT0_INIT) || \
    defined (PWM_FFILT1_INIT) || \
    defined (PWM_FFILT2_INIT) || \
    defined (PWM_FFILT3_INIT) || \
    defined (PWM_PWMCM_INIT) || \
    defined (PWM_PWMVAL0_INIT) || \
    defined (PWM_PWMVAL1_INIT) || \
    defined (PWM_PWMVAL2_INIT) || \
    defined (PWM_PWMVAL3_INIT) || \
    defined (PWM_PWMVAL4_INIT) || \
    defined (PWM_PWMVAL5_INIT)
#define PWM_INIT_USED 1
#endif

#if defined (PWM_MCTRL_INIT) || \
    defined (PWM_MCTRL2_INIT) || \
    defined (PWM_MASK_INIT) || \
    defined (PWM_OUTEN_INIT)  || \
    defined (PWM_SWCOUT_INIT) || \
    defined (PWM_DTSRCSEL_INIT) || \
    defined (PWM_FCTRL_INIT) || \
    defined (PWM_FCTRL0_INIT) || \
    defined (PWM_FCTRL1_INIT) || \
    defined (PWM_FFILT_INIT) || \
    defined (PWM_FFILT0_INIT) || \
    defined (PWM_FFILT1_INIT) || \
    defined (PWM_FSTS_INIT) || \
    defined (PWM_FSTS0_INIT) || \
    defined (PWM_FSTS1_INIT) || \
    defined (PWM_A_FTST0_INIT) || \
    defined (PWM_A_FTST1_INIT)
#define EFPWM_COMMON_INIT_USED 1
#endif

#if defined (PWM_0_CTRL_INIT) || \
    defined (PWM_0_CTRL2_INIT) || \
    defined (PWM_0_INIT_INIT) || \
    defined (PWM_0_VAL1_INIT) || \
    defined (PWM_0_FRACVAL1_INIT) || \
    defined (PWM_0_FRCTRL_INIT) || \
    defined (PWM_0_OCTRL_INIT) || \
    defined (PWM_0_VAL0_INIT) || \
    defined (PWM_0_VAL2_INIT) || \
    defined (PWM_0_VAL3_INIT) || \
    defined (PWM_0_VAL4_INIT) || \
    defined (PWM_0_VAL5_INIT) || \
    defined (PWM_0_FRACVAL2_INIT) || \
    defined (PWM_0_FRACVAL3_INIT) || \
    defined (PWM_0_FRACVAL4_INIT) || \
    defined (PWM_0_FRACVAL5_INIT) || \
    defined (PWM_0_TCTRL_INIT) || \
    defined (PWM_0_DTCNT0_INIT) || \
    defined (PWM_0_DTCNT1_INIT) || \
    defined (PWM_0_INTEN_INIT) || \
    defined (PWM_0_DISMAP_INIT) || \
    defined (PWM_0_DISMAP0_INIT) || \
    defined (PWM_0_DISMAP1_INIT)
#define EFPWM_SUB0_INIT_USED 1
#endif

#if defined (PWM_1_CTRL_INIT) || \
    defined (PWM_1_CTRL2_INIT) || \
    defined (PWM_1_INIT_INIT) || \
    defined (PWM_1_VAL1_INIT) || \
    defined (PWM_1_FRACVAL1_INIT) || \
    defined (PWM_1_FRCTRL_INIT) || \
    defined (PWM_1_OCTRL_INIT) || \
    defined (PWM_1_VAL0_INIT) || \
    defined (PWM_1_VAL2_INIT) || \
    defined (PWM_1_VAL3_INIT) || \
    defined (PWM_1_VAL4_INIT) || \
    defined (PWM_1_VAL5_INIT) || \
    defined (PWM_1_FRACVAL2_INIT) || \
    defined (PWM_1_FRACVAL3_INIT) || \
    defined (PWM_1_FRACVAL4_INIT) || \
    defined (PWM_1_FRACVAL5_INIT) || \
    defined (PWM_1_TCTRL_INIT) || \
    defined (PWM_1_DTCNT0_INIT) || \
    defined (PWM_1_DTCNT1_INIT) || \
    defined (PWM_1_INTEN_INIT) || \
    defined (PWM_1_DISMAP_INIT) || \
    defined (PWM_1_DISMAP0_INIT) || \
    defined (PWM_1_DISMAP1_INIT)
#define EFPWM_SUB1_INIT_USED 1
#endif

#if defined (PWM_2_CTRL_INIT) || \
    defined (PWM_2_CTRL2_INIT) || \
    defined (PWM_2_INIT_INIT) || \
    defined (PWM_2_VAL1_INIT) || \
    defined (PWM_2_FRACVAL1_INIT) || \
    defined (PWM_2_FRCTRL_INIT) || \
    defined (PWM_2_OCTRL_INIT) || \
    defined (PWM_2_VAL0_INIT) || \
    defined (PWM_2_VAL2_INIT) || \
    defined (PWM_2_VAL3_INIT) || \
    defined (PWM_2_VAL4_INIT) || \
    defined (PWM_2_VAL5_INIT) || \
    defined (PWM_2_FRACVAL2_INIT) || \
    defined (PWM_2_FRACVAL3_INIT) || \
    defined (PWM_2_FRACVAL4_INIT) || \
    defined (PWM_2_FRACVAL5_INIT) || \
    defined (PWM_2_TCTRL_INIT) || \
    defined (PWM_2_DTCNT0_INIT) || \
    defined (PWM_2_DTCNT1_INIT) || \
    defined (PWM_2_INTEN_INIT) || \
    defined (PWM_2_DISMAP_INIT) || \
    defined (PWM_2_DISMAP0_INIT) || \
    defined (PWM_2_DISMAP1_INIT)
#define EFPWM_SUB2_INIT_USED 1
#endif

#if defined (PWM_3_CTRL_INIT) || \
    defined (PWM_3_CTRL2_INIT) || \
    defined (PWM_3_INIT_INIT) || \
    defined (PWM_3_VAL1_INIT) || \
    defined (PWM_3_FRACVAL1_INIT) || \
    defined (PWM_3_FRCTRL_INIT) || \
    defined (PWM_3_OCTRL_INIT) || \
    defined (PWM_3_VAL0_INIT) || \
    defined (PWM_3_VAL2_INIT) || \
    defined (PWM_3_VAL3_INIT) || \
    defined (PWM_3_VAL4_INIT) || \
    defined (PWM_3_VAL5_INIT) || \
    defined (PWM_3_FRACVAL2_INIT) || \
    defined (PWM_3_FRACVAL3_INIT) || \
    defined (PWM_3_FRACVAL4_INIT) || \
    defined (PWM_3_FRACVAL5_INIT) || \
    defined (PWM_3_TCTRL_INIT) || \
    defined (PWM_3_DTCNT0_INIT) || \
    defined (PWM_3_DTCNT1_INIT) || \
    defined (PWM_3_INTEN_INIT) || \
    defined (PWM_3_DISMAP_INIT) || \
    defined (PWM_3_DISMAP0_INIT) || \
    defined (PWM_3_DISMAP1_INIT)
#define EFPWM_SUB3_INIT_USED 1
#endif

#if defined (PWM_A_MCTRL_INIT) || \
    defined (PWM_A_MCTRL2_INIT) || \
    defined (PWM_A_MASK_INIT) || \
    defined (PWM_A_OUTEN_INIT)  || \
    defined (PWM_A_SWCOUT_INIT) || \
    defined (PWM_A_DTSRCSEL_INIT) || \
    defined (PWM_A_FCTRL_INIT) || \
    defined (PWM_A_FCTRL0_INIT) || \
    defined (PWM_A_FCTRL1_INIT) || \
    defined (PWM_A_FFILT_INIT) || \
    defined (PWM_A_FFILT0_INIT) || \
    defined (PWM_A_FFILT1_INIT) || \
    defined (PWM_A_FSTS_INIT) || \
    defined (PWM_A_FSTS0_INIT) || \
    defined (PWM_A_FSTS1_INIT) || \
    defined (PWM_A_FTST0_INIT) || \
    defined (PWM_A_FTST1_INIT)
#define EFPWM_A_COMMON_INIT_USED 1
#endif

#if defined (PWM_A_0_CTRL_INIT) || \
    defined (PWM_A_0_CTRL2_INIT) || \
    defined (PWM_A_0_INIT_INIT) || \
    defined (PWM_A_0_VAL1_INIT) || \
    defined (PWM_A_0_FRACVAL1_INIT) || \
    defined (PWM_A_0_FRCTRL_INIT) || \
    defined (PWM_A_0_OCTRL_INIT) || \
    defined (PWM_A_0_VAL0_INIT) || \
    defined (PWM_A_0_VAL2_INIT) || \
    defined (PWM_A_0_VAL3_INIT) || \
    defined (PWM_A_0_VAL4_INIT) || \
    defined (PWM_A_0_VAL5_INIT) || \
    defined (PWM_A_0_FRACVAL2_INIT) || \
    defined (PWM_A_0_FRACVAL3_INIT) || \
    defined (PWM_A_0_FRACVAL4_INIT) || \
    defined (PWM_A_0_FRACVAL5_INIT) || \
    defined (PWM_A_0_TCTRL_INIT) || \
    defined (PWM_A_0_DTCNT0_INIT) || \
    defined (PWM_A_0_DTCNT1_INIT) || \
    defined (PWM_A_0_INTEN_INIT) || \
    defined (PWM_A_0_DISMAP_INIT) || \
    defined (PWM_A_0_DISMAP0_INIT) || \
    defined (PWM_A_0_DISMAP1_INIT)
#define EFPWM_A_SUB0_INIT_USED 1
#endif

#if defined (PWM_A_1_CTRL_INIT) || \
    defined (PWM_A_1_CTRL2_INIT) || \
    defined (PWM_A_1_INIT_INIT) || \
    defined (PWM_A_1_VAL1_INIT) || \
    defined (PWM_A_1_FRACVAL1_INIT) || \
    defined (PWM_A_1_FRCTRL_INIT) || \
    defined (PWM_A_1_OCTRL_INIT) || \
    defined (PWM_A_1_VAL0_INIT) || \
    defined (PWM_A_1_VAL2_INIT) || \
    defined (PWM_A_1_VAL3_INIT) || \
    defined (PWM_A_1_VAL4_INIT) || \
    defined (PWM_A_1_VAL5_INIT) || \
    defined (PWM_A_1_FRACVAL2_INIT) || \
    defined (PWM_A_1_FRACVAL3_INIT) || \
    defined (PWM_A_1_FRACVAL4_INIT) || \
    defined (PWM_A_1_FRACVAL5_INIT) || \
    defined (PWM_A_1_TCTRL_INIT) || \
    defined (PWM_A_1_DTCNT0_INIT) || \
    defined (PWM_A_1_DTCNT1_INIT) || \
    defined (PWM_A_1_INTEN_INIT) || \
    defined (PWM_A_1_DISMAP_INIT) || \
    defined (PWM_A_1_DISMAP0_INIT) || \
    defined (PWM_A_1_DISMAP1_INIT)
#define EFPWM_A_SUB1_INIT_USED 1
#endif

#if defined (PWM_A_2_CTRL_INIT) || \
    defined (PWM_A_2_CTRL2_INIT) || \
    defined (PWM_A_2_INIT_INIT) || \
    defined (PWM_A_2_VAL1_INIT) || \
    defined (PWM_A_2_FRACVAL1_INIT) || \
    defined (PWM_A_2_FRCTRL_INIT) || \
    defined (PWM_A_2_OCTRL_INIT) || \
    defined (PWM_A_2_VAL0_INIT) || \
    defined (PWM_A_2_VAL2_INIT) || \
    defined (PWM_A_2_VAL3_INIT) || \
    defined (PWM_A_2_VAL4_INIT) || \
    defined (PWM_A_2_VAL5_INIT) || \
    defined (PWM_A_2_FRACVAL2_INIT) || \
    defined (PWM_A_2_FRACVAL3_INIT) || \
    defined (PWM_A_2_FRACVAL4_INIT) || \
    defined (PWM_A_2_FRACVAL5_INIT) || \
    defined (PWM_A_2_TCTRL_INIT) || \
    defined (PWM_A_2_DTCNT0_INIT) || \
    defined (PWM_A_2_DTCNT1_INIT) || \
    defined (PWM_A_2_INTEN_INIT) || \
    defined (PWM_A_2_DISMAP_INIT) || \
    defined (PWM_A_2_DISMAP0_INIT) || \
    defined (PWM_A_2_DISMAP1_INIT)
#define EFPWM_A_SUB2_INIT_USED 1
#endif

#if defined (PWM_A_3_CTRL_INIT) || \
    defined (PWM_A_3_CTRL2_INIT) || \
    defined (PWM_A_3_INIT_INIT) || \
    defined (PWM_A_3_VAL1_INIT) || \
    defined (PWM_A_3_FRACVAL1_INIT) || \
    defined (PWM_A_3_FRCTRL_INIT) || \
    defined (PWM_A_3_OCTRL_INIT) || \
    defined (PWM_A_3_VAL0_INIT) || \
    defined (PWM_A_3_VAL2_INIT) || \
    defined (PWM_A_3_VAL3_INIT) || \
    defined (PWM_A_3_VAL4_INIT) || \
    defined (PWM_A_3_VAL5_INIT) || \
    defined (PWM_A_3_FRACVAL2_INIT) || \
    defined (PWM_A_3_FRACVAL3_INIT) || \
    defined (PWM_A_3_FRACVAL4_INIT) || \
    defined (PWM_A_3_FRACVAL5_INIT) || \
    defined (PWM_A_3_TCTRL_INIT) || \
    defined (PWM_A_3_DTCNT0_INIT) || \
    defined (PWM_A_3_DTCNT1_INIT) || \
    defined (PWM_A_3_INTEN_INIT) || \
    defined (PWM_A_3_DISMAP_INIT) || \
    defined (PWM_A_3_DISMAP0_INIT) || \
    defined (PWM_A_3_DISMAP1_INIT)
#define EFPWM_A_SUB3_INIT_USED 1
#endif

#if defined (PWM_B_MCTRL_INIT) || \
    defined (PWM_B_MCTRL2_INIT) || \
    defined (PWM_B_MASK_INIT) || \
    defined (PWM_B_OUTEN_INIT)  || \
    defined (PWM_B_SWCOUT_INIT) || \
    defined (PWM_B_DTSRCSEL_INIT) || \
    defined (PWM_B_FCTRL_INIT) || \
    defined (PWM_B_FCTRL0_INIT) || \
    defined (PWM_B_FCTRL1_INIT) || \
    defined (PWM_B_FFILT_INIT) || \
    defined (PWM_B_FFILT0_INIT) || \
    defined (PWM_B_FFILT1_INIT) || \
    defined (PWM_B_FSTS_INIT) || \
    defined (PWM_B_FSTS0_INIT) || \
    defined (PWM_B_FSTS1_INIT) || \
    defined (PWM_B_FTST0_INIT) || \
    defined (PWM_B_FTST1_INIT)
#define EFPWM_B_COMMON_INIT_USED 1
#endif

#if defined (PWM_B_0_CTRL_INIT) || \
    defined (PWM_B_0_CTRL2_INIT) || \
    defined (PWM_B_0_INIT_INIT) || \
    defined (PWM_B_0_VAL1_INIT) || \
    defined (PWM_B_0_OCTRL_INIT) || \
    defined (PWM_B_0_VAL0_INIT) || \
    defined (PWM_B_0_VAL2_INIT) || \
    defined (PWM_B_0_VAL3_INIT) || \
    defined (PWM_B_0_VAL4_INIT) || \
    defined (PWM_B_0_VAL5_INIT) || \
    defined (PWM_B_0_TCTRL_INIT) || \
    defined (PWM_B_0_DTCNT0_INIT) || \
    defined (PWM_B_0_DTCNT1_INIT) || \
    defined (PWM_B_0_INTEN_INIT) || \
    defined (PWM_B_0_DISMAP_INIT) || \
    defined (PWM_B_0_DISMAP0_INIT) || \
    defined (PWM_B_0_DISMAP1_INIT)
#define EFPWM_B_SUB0_INIT_USED 1
#endif

#if defined (PWM_B_1_CTRL_INIT) || \
    defined (PWM_B_1_CTRL2_INIT) || \
    defined (PWM_B_1_INIT_INIT) || \
    defined (PWM_B_1_VAL1_INIT) || \
    defined (PWM_B_1_OCTRL_INIT) || \
    defined (PWM_B_1_VAL0_INIT) || \
    defined (PWM_B_1_VAL2_INIT) || \
    defined (PWM_B_1_VAL3_INIT) || \
    defined (PWM_B_1_VAL4_INIT) || \
    defined (PWM_B_1_VAL5_INIT) || \
    defined (PWM_B_1_TCTRL_INIT) || \
    defined (PWM_B_1_DTCNT0_INIT) || \
    defined (PWM_B_1_DTCNT1_INIT) || \
    defined (PWM_B_1_INTEN_INIT) || \
    defined (PWM_B_1_DISMAP_INIT) || \
    defined (PWM_B_1_DISMAP0_INIT) || \
    defined (PWM_B_1_DISMAP1_INIT)
#define EFPWM_B_SUB1_INIT_USED 1
#endif

#if defined (PWM_B_2_CTRL_INIT) || \
    defined (PWM_B_2_CTRL2_INIT) || \
    defined (PWM_B_2_INIT_INIT) || \
    defined (PWM_B_2_VAL1_INIT) || \
    defined (PWM_B_2_OCTRL_INIT) || \
    defined (PWM_B_2_VAL0_INIT) || \
    defined (PWM_B_2_VAL2_INIT) || \
    defined (PWM_B_2_VAL3_INIT) || \
    defined (PWM_B_2_VAL4_INIT) || \
    defined (PWM_B_2_VAL5_INIT) || \
    defined (PWM_B_2_TCTRL_INIT) || \
    defined (PWM_B_2_DTCNT0_INIT) || \
    defined (PWM_B_2_DTCNT1_INIT) || \
    defined (PWM_B_2_INTEN_INIT) || \
    defined (PWM_B_2_DISMAP_INIT) || \
    defined (PWM_B_2_DISMAP0_INIT) || \
    defined (PWM_B_2_DISMAP1_INIT)
#define EFPWM_B_SUB2_INIT_USED 1
#endif

#if defined (PWM_B_3_CTRL_INIT) || \
    defined (PWM_B_3_CTRL2_INIT) || \
    defined (PWM_B_3_INIT_INIT) || \
    defined (PWM_B_3_VAL1_INIT) || \
    defined (PWM_B_3_OCTRL_INIT) || \
    defined (PWM_B_3_VAL0_INIT) || \
    defined (PWM_B_3_VAL2_INIT) || \
    defined (PWM_B_3_VAL3_INIT) || \
    defined (PWM_B_3_VAL4_INIT) || \
    defined (PWM_B_3_VAL5_INIT) || \
    defined (PWM_B_3_TCTRL_INIT) || \
    defined (PWM_B_3_DTCNT0_INIT) || \
    defined (PWM_B_3_DTCNT1_INIT) || \
    defined (PWM_B_3_INTEN_INIT) || \
    defined (PWM_B_3_DISMAP_INIT) || \
    defined (PWM_B_3_DISMAP0_INIT) || \
    defined (PWM_B_3_DISMAP1_INIT)
#define EFPWM_B_SUB3_INIT_USED 1
#endif
    
#if defined (QT_A0_CMP1_INIT) || \
    defined (QT_A0_CMP2_INIT) || \
    defined (QT_A0_CMPLD1_INIT) || \
    defined (QT_A0_CMPLD2_INIT) || \
    defined (QT_A0_CNTR_INIT) || \
    defined (QT_A0_COMSCR_INIT) || \
    defined (QT_A0_CTRL_INIT) || \
    defined (QT_A0_LOAD_INIT) || \
    defined (QT_A0_FILT_INIT) || \
    defined (QT_A0_ENBL_INIT) || \
    defined (QT_A0_DMA_INIT) || \
    defined (QT_A0_SCR_INIT)
#define QT_A0_INIT_USED 1
#endif

#if defined (QT_A1_CMP1_INIT) || \
    defined (QT_A1_CMP2_INIT) || \
    defined (QT_A1_CMPLD1_INIT) || \
    defined (QT_A1_CMPLD2_INIT) || \
    defined (QT_A1_CNTR_INIT) || \
    defined (QT_A1_COMSCR_INIT) || \
    defined (QT_A1_CTRL_INIT) || \
    defined (QT_A1_LOAD_INIT) || \
    defined (QT_A1_FILT_INIT) || \
    defined (QT_A1_DMA_INIT) || \
    defined (QT_A1_SCR_INIT)
#define QT_A1_INIT_USED 1
#endif

#if defined (QT_A2_CMP1_INIT) || \
    defined (QT_A2_CMP2_INIT) || \
    defined (QT_A2_CMPLD1_INIT) || \
    defined (QT_A2_CMPLD2_INIT) || \
    defined (QT_A2_CNTR_INIT) || \
    defined (QT_A2_COMSCR_INIT) || \
    defined (QT_A2_CTRL_INIT) || \
    defined (QT_A2_LOAD_INIT) || \
    defined (QT_A2_FILT_INIT) || \
    defined (QT_A2_DMA_INIT) || \
    defined (QT_A2_SCR_INIT)
#define QT_A2_INIT_USED 1
#endif

#if defined (QT_A3_CMP1_INIT) || \
    defined (QT_A3_CMP2_INIT) || \
    defined (QT_A3_CMPLD1_INIT) || \
    defined (QT_A3_CMPLD2_INIT) || \
    defined (QT_A3_CNTR_INIT) || \
    defined (QT_A3_COMSCR_INIT) || \
    defined (QT_A3_CTRL_INIT) || \
    defined (QT_A3_LOAD_INIT) || \
    defined (QT_A3_FILT_INIT) || \
    defined (QT_A3_DMA_INIT) || \
    defined (QT_A3_SCR_INIT)
#define QT_A3_INIT_USED 1
#endif

#if defined (QT_B0_CMP1_INIT) || \
    defined (QT_B0_CMP2_INIT) || \
    defined (QT_B0_CMPLD1_INIT) || \
    defined (QT_B0_CMPLD2_INIT) || \
    defined (QT_B0_CNTR_INIT) || \
    defined (QT_B0_COMSCR_INIT) || \
    defined (QT_B0_CTRL_INIT) || \
    defined (QT_B0_LOAD_INIT) || \
    defined (QT_B0_FILT_INIT) || \
    defined (QT_B0_ENBL_INIT) || \
    defined (QT_B0_DMA_INIT) || \
    defined (QT_B0_SCR_INIT)
#define QT_B0_INIT_USED 1
#endif

#if defined (QT_B1_CMP1_INIT) || \
    defined (QT_B1_CMP2_INIT) || \
    defined (QT_B1_CMPLD1_INIT) || \
    defined (QT_B1_CMPLD2_INIT) || \
    defined (QT_B1_CNTR_INIT) || \
    defined (QT_B1_COMSCR_INIT) || \
    defined (QT_B1_CTRL_INIT) || \
    defined (QT_B1_LOAD_INIT) || \
    defined (QT_B1_FILT_INIT) || \
    defined (QT_B1_DMA_INIT) || \
    defined (QT_B1_SCR_INIT)
#define QT_B1_INIT_USED 1
#endif

#if defined (QT_B2_CMP1_INIT) || \
    defined (QT_B2_CMP2_INIT) || \
    defined (QT_B2_CMPLD1_INIT) || \
    defined (QT_B2_CMPLD2_INIT) || \
    defined (QT_B2_CNTR_INIT) || \
    defined (QT_B2_COMSCR_INIT) || \
    defined (QT_B2_CTRL_INIT) || \
    defined (QT_B2_LOAD_INIT) || \
    defined (QT_B2_FILT_INIT) || \
    defined (QT_B2_DMA_INIT) || \
    defined (QT_B2_SCR_INIT)
#define QT_B2_INIT_USED 1
#endif

#if defined (QT_B3_CMP1_INIT) || \
    defined (QT_B3_CMP2_INIT) || \
    defined (QT_B3_CMPLD1_INIT) || \
    defined (QT_B3_CMPLD2_INIT) || \
    defined (QT_B3_CNTR_INIT) || \
    defined (QT_B3_COMSCR_INIT) || \
    defined (QT_B3_CTRL_INIT) || \
    defined (QT_B3_LOAD_INIT) || \
    defined (QT_B3_FILT_INIT) || \
    defined (QT_B3_DMA_INIT) || \
    defined (QT_B3_SCR_INIT)
#define QT_B3_INIT_USED 1
#endif

#if defined (QT_C0_CMP1_INIT) || \
    defined (QT_C0_CMP2_INIT) || \
    defined (QT_C0_CMPLD1_INIT) || \
    defined (QT_C0_CMPLD2_INIT) || \
    defined (QT_C0_CNTR_INIT) || \
    defined (QT_C0_COMSCR_INIT) || \
    defined (QT_C0_CTRL_INIT) || \
    defined (QT_C0_LOAD_INIT) || \
    defined (QT_C0_FILT_INIT) || \
    defined (QT_C0_ENBL_INIT) || \
    defined (QT_C0_DMA_INIT) || \
    defined (QT_C0_SCR_INIT)
#define QT_C0_INIT_USED 1
#endif

#if defined (QT_C1_CMP1_INIT) || \
    defined (QT_C1_CMP2_INIT) || \
    defined (QT_C1_CMPLD1_INIT) || \
    defined (QT_C1_CMPLD2_INIT) || \
    defined (QT_C1_CNTR_INIT) || \
    defined (QT_C1_COMSCR_INIT) || \
    defined (QT_C1_CTRL_INIT) || \
    defined (QT_C1_LOAD_INIT) || \
    defined (QT_C1_FILT_INIT) || \
    defined (QT_C1_DMA_INIT) || \
    defined (QT_C1_SCR_INIT)
#define QT_C1_INIT_USED 1
#endif

#if defined (QT_C2_CMP1_INIT) || \
    defined (QT_C2_CMP2_INIT) || \
    defined (QT_C2_CMPLD1_INIT) || \
    defined (QT_C2_CMPLD2_INIT) || \
    defined (QT_C2_CNTR_INIT) || \
    defined (QT_C2_COMSCR_INIT) || \
    defined (QT_C2_CTRL_INIT) || \
    defined (QT_C2_LOAD_INIT) || \
    defined (QT_C2_FILT_INIT) || \
    defined (QT_C2_DMA_INIT) || \
    defined (QT_C2_SCR_INIT)
#define QT_C2_INIT_USED 1
#endif

#if defined (QT_C3_CMP1_INIT) || \
    defined (QT_C3_CMP2_INIT) || \
    defined (QT_C3_CMPLD1_INIT) || \
    defined (QT_C3_CMPLD2_INIT) || \
    defined (QT_C3_CNTR_INIT) || \
    defined (QT_C3_COMSCR_INIT) || \
    defined (QT_C3_CTRL_INIT) || \
    defined (QT_C3_LOAD_INIT) || \
    defined (QT_C3_FILT_INIT) || \
    defined (QT_C3_DMA_INIT) || \
    defined (QT_C3_SCR_INIT)
#define QT_C3_INIT_USED 1
#endif

#if defined (QT_D0_CMP1_INIT) || \
    defined (QT_D0_CMP2_INIT) || \
    defined (QT_D0_CMPLD1_INIT) || \
    defined (QT_D0_CMPLD2_INIT) || \
    defined (QT_D0_CNTR_INIT) || \
    defined (QT_D0_COMSCR_INIT) || \
    defined (QT_D0_CTRL_INIT) || \
    defined (QT_D0_LOAD_INIT) || \
    defined (QT_D0_FILT_INIT) || \
    defined (QT_D0_ENBL_INIT) || \
    defined (QT_D0_DMA_INIT) || \
    defined (QT_D0_SCR_INIT)
#define QT_D0_INIT_USED 1
#endif

#if defined (QT_D1_CMP1_INIT) || \
    defined (QT_D1_CMP2_INIT) || \
    defined (QT_D1_CMPLD1_INIT) || \
    defined (QT_D1_CMPLD2_INIT) || \
    defined (QT_D1_CNTR_INIT) || \
    defined (QT_D1_COMSCR_INIT) || \
    defined (QT_D1_CTRL_INIT) || \
    defined (QT_D1_LOAD_INIT) || \
    defined (QT_D1_FILT_INIT) || \
    defined (QT_D1_DMA_INIT) || \
    defined (QT_D1_SCR_INIT)
#define QT_D1_INIT_USED 1
#endif

#if defined (QT_D2_CMP1_INIT) || \
    defined (QT_D2_CMP2_INIT) || \
    defined (QT_D2_CMPLD1_INIT) || \
    defined (QT_D2_CMPLD2_INIT) || \
    defined (QT_D2_CNTR_INIT) || \
    defined (QT_D2_COMSCR_INIT) || \
    defined (QT_D2_CTRL_INIT) || \
    defined (QT_D2_LOAD_INIT) || \
    defined (QT_D2_FILT_INIT) || \
    defined (QT_D2_DMA_INIT) || \
    defined (QT_D2_SCR_INIT)
#define QT_D2_INIT_USED 1
#endif

#if defined (QT_D3_CMP1_INIT) || \
    defined (QT_D3_CMP2_INIT) || \
    defined (QT_D3_CMPLD1_INIT) || \
    defined (QT_D3_CMPLD2_INIT) || \
    defined (QT_D3_CNTR_INIT) || \
    defined (QT_D3_COMSCR_INIT) || \
    defined (QT_D3_CTRL_INIT) || \
    defined (QT_D3_LOAD_INIT) || \
    defined (QT_D3_FILT_INIT) || \
    defined (QT_D3_DMA_INIT) || \
    defined (QT_D3_SCR_INIT)
#define QT_D3_INIT_USED 1
#endif

#if defined (QT_0_CMP1_INIT) || \
    defined (QT_0_CMP2_INIT) || \
    defined (QT_0_CMPLD1_INIT) || \
    defined (QT_0_CMPLD2_INIT) || \
    defined (QT_0_CNTR_INIT) || \
    defined (QT_0_COMSCR_INIT) || \
    defined (QT_0_CTRL_INIT) || \
    defined (QT_0_LOAD_INIT) || \
    defined (QT_0_FILT_INIT) || \
    defined (QT_0_ENBL_INIT) || \
    defined (QT_0_DMA_INIT) || \
    defined (QT_0_SCR_INIT)
#define QT_0_INIT_USED 1
#endif

#if defined (QT_1_CMP1_INIT) || \
    defined (QT_1_CMP2_INIT) || \
    defined (QT_1_CMPLD1_INIT) || \
    defined (QT_1_CMPLD2_INIT) || \
    defined (QT_1_CNTR_INIT) || \
    defined (QT_1_COMSCR_INIT) || \
    defined (QT_1_CTRL_INIT) || \
    defined (QT_1_LOAD_INIT) || \
    defined (QT_1_FILT_INIT) || \
    defined (QT_1_DMA_INIT) || \
    defined (QT_1_SCR_INIT)
#define QT_1_INIT_USED 1
#endif

#if defined (QT_2_CMP1_INIT) || \
    defined (QT_2_CMP2_INIT) || \
    defined (QT_2_CMPLD1_INIT) || \
    defined (QT_2_CMPLD2_INIT) || \
    defined (QT_2_CNTR_INIT) || \
    defined (QT_2_COMSCR_INIT) || \
    defined (QT_2_CTRL_INIT) || \
    defined (QT_2_LOAD_INIT) || \
    defined (QT_2_FILT_INIT) || \
    defined (QT_2_DMA_INIT) || \
    defined (QT_2_SCR_INIT)
#define QT_2_INIT_USED 1
#endif

#if defined (QT_3_CMP1_INIT) || \
    defined (QT_3_CMP2_INIT) || \
    defined (QT_3_CMPLD1_INIT) || \
    defined (QT_3_CMPLD2_INIT) || \
    defined (QT_3_CNTR_INIT) || \
    defined (QT_3_COMSCR_INIT) || \
    defined (QT_3_CTRL_INIT) || \
    defined (QT_3_LOAD_INIT) || \
    defined (QT_3_FILT_INIT) || \
    defined (QT_3_DMA_INIT) || \
    defined (QT_3_SCR_INIT)
#define QT_3_INIT_USED 1
#endif

#if defined (SCI_0_SCIBR_INIT) || \
    defined (SCI_0_SCICR2_INIT) || \
    defined (SCI_0_SCICR3_INIT) || \
    defined (SCI_0_SCICR_INIT)
#define SCI_0_INIT_USED 1
#endif

#if defined (SCI_1_SCIBR_INIT) || \
    defined (SCI_1_SCICR2_INIT) || \
    defined (SCI_1_SCICR3_INIT) || \
    defined (SCI_1_SCICR_INIT)
#define SCI_1_INIT_USED 1
#endif

#if defined (SCI_2_SCIBR_INIT) || \
    defined (SCI_2_SCICR2_INIT) || \
    defined (SCI_2_SCICR3_INIT) || \
    defined (SCI_2_SCICR_INIT)
#define SCI_2_INIT_USED 1
#endif

#if defined (SPI_0_SPDSCR_INIT) || \
    defined (SPI_0_SPDSR_INIT) || \
    defined (SPI_0_FIFO_INIT) || \
    defined (SPI_0_DELAY_INIT) || \
    defined (SPI_0_SPSCR_INIT)
#define SPI_0_INIT_USED 1
#endif

#if defined (SPI_1_SPDSCR_INIT) || \
    defined (SPI_1_SPDSR_INIT) || \
    defined (SPI_1_FIFO_INIT) || \
    defined (SPI_1_DELAY_INIT) || \
    defined (SPI_1_SPSCR_INIT)
#define SPI_1_INIT_USED 1
#endif

#if defined (SPI_2_SPDSCR_INIT) || \
    defined (SPI_2_SPDSR_INIT) || \
    defined (SPI_2_FIFO_INIT) || \
    defined (SPI_2_DELAY_INIT) || \
    defined (SPI_2_SPSCR_INIT)
#define SPI_2_INIT_USED 1
#endif

#if defined (SPI_SPDSCR_INIT) || \
    defined (SPI_SPDSR_INIT) || \
    defined (SPI_FIFO_INIT) || \
    defined (SPI_DELAY_INIT) || \
    defined (SPI_SPSCR_INIT)
#define SPI_INIT_USED 1
#endif

#if defined (PIT_MOD_INIT) || \
    defined (PIT_CTRL_INIT)
#define PIT_INIT_USED 1
#endif

#if defined (PIT_0_MOD_INIT) || \
    defined (PIT_0_CTRL_INIT)
#define PIT_0_INIT_USED 1
#endif

#if defined (PIT_1_MOD_INIT) || \
    defined (PIT_1_CTRL_INIT)
#define PIT_1_INIT_USED 1
#endif

#if defined (PIT_2_MOD_INIT) || \
    defined (PIT_2_CTRL_INIT)
#define PIT_2_INIT_USED 1
#endif

#if defined (DAC_0_CTRL_INIT) || \
    defined (DAC_0_DATA_INIT) || \
    defined (DAC_0_STEP_INIT) || \
    defined (DAC_0_MINVAL_INIT) || \
    defined (DAC_0_MAXVAL_INIT)
#define DAC_0_INIT_USED 1
#endif

#if defined (DAC_1_CTRL_INIT) || \
    defined (DAC_1_DATA_INIT) || \
    defined (DAC_1_STEP_INIT) || \
    defined (DAC_1_MINVAL_INIT) || \
    defined (DAC_1_MAXVAL_INIT)
#define DAC_1_INIT_USED 1
#endif

#if defined (DAC_CTRL_INIT) || \
    defined (DAC_DATA_INIT) || \
    defined (DAC_STEP_INIT) || \
    defined (DAC_MINVAL_INIT) || \
    defined (DAC_MAXVAL_INIT) || \
    defined (DAC_CTRL1_INIT)
#define DAC_INIT_USED 1
#endif

#if defined (DAC_A_CTRL_INIT) || \
    defined (DAC_A_DATA_INIT) || \
    defined (DAC_A_STEP_INIT) || \
    defined (DAC_A_MINVAL_INIT) || \
    defined (DAC_A_MAXVAL_INIT) || \
    defined (DAC_A_CTRL1_INIT)
#define DAC_A_INIT_USED 1
#endif

#if defined (DAC_B_CTRL_INIT) || \
    defined (DAC_B_DATA_INIT) || \
    defined (DAC_B_STEP_INIT) || \
    defined (DAC_B_MINVAL_INIT) || \
    defined (DAC_B_MAXVAL_INIT) || \
    defined (DAC_B_CTRL1_INIT)
#define DAC_B_INIT_USED 1
#endif

#if defined (CMP_A_CTRL_INIT) || \
    defined (CMP_A_FILT_INIT)
#define CMP_A_INIT_USED 1
#endif

#if defined (CMP_B_CTRL_INIT) || \
    defined (CMP_B_FILT_INIT)
#define CMP_B_INIT_USED 1
#endif

#if defined (HSCMP_0_CR0_INIT) || \
    defined (HSCMP_0_CR1_INIT) || \
    defined (HSCMP_0_FPR_INIT) || \
    defined (HSCMP_0_SCR_INIT)
#define HSCMP_0_INIT_USED 1
#endif

#if defined (HSCMP_1_CR0_INIT) || \
    defined (HSCMP_1_CR1_INIT) || \
    defined (HSCMP_1_FPR_INIT) || \
    defined (HSCMP_1_SCR_INIT)
#define HSCMP_1_INIT_USED 1
#endif

#if defined (HSCMP_2_CR0_INIT) || \
    defined (HSCMP_2_CR1_INIT) || \
    defined (HSCMP_2_FPR_INIT) || \
    defined (HSCMP_2_SCR_INIT)
#define HSCMP_2_INIT_USED 1
#endif

#if defined (HSCMP_A_CR0_INIT) || \
    defined (HSCMP_A_CR1_INIT) || \
    defined (HSCMP_A_FPR_INIT) || \
    defined (HSCMP_A_SCR_INIT) || \
    defined (HSCMP_A_DACCR_INIT) || \
    defined (HSCMP_A_MUXCR_INIT) || \
    defined (HSCMP_A_PCR_INIT)
#define HSCMP_A_INIT_USED 1
#endif

#if defined (HSCMP_B_CR0_INIT) || \
    defined (HSCMP_B_CR1_INIT) || \
    defined (HSCMP_B_FPR_INIT) || \
    defined (HSCMP_B_SCR_INIT) || \
    defined (HSCMP_B_DACCR_INIT) || \
    defined (HSCMP_B_MUXCR_INIT) || \
    defined (HSCMP_B_PCR_INIT)
#define HSCMP_B_INIT_USED 1
#endif

#if defined (HSCMP_C_CR0_INIT) || \
    defined (HSCMP_C_CR1_INIT) || \
    defined (HSCMP_C_FPR_INIT) || \
    defined (HSCMP_C_SCR_INIT) || \
    defined (HSCMP_C_DACCR_INIT) || \
    defined (HSCMP_C_MUXCR_INIT) || \
    defined (HSCMP_C_PCR_INIT)
#define HSCMP_C_INIT_USED 1
#endif

#if defined (HSCMP_D_CR0_INIT) || \
    defined (HSCMP_D_CR1_INIT) || \
    defined (HSCMP_D_FPR_INIT) || \
    defined (HSCMP_D_SCR_INIT) || \
    defined (HSCMP_D_DACCR_INIT) || \
    defined (HSCMP_D_MUXCR_INIT) || \
    defined (HSCMP_D_PCR_INIT)
#define HSCMP_D_INIT_USED 1
#endif

#if defined (IIC_IICF_INIT) || \
    defined (IIC_IICA1_INIT) || \
    defined (IIC_IICA2_INIT) || \
    defined (IIC_IICSLTH_INIT) || \
    defined (IIC_IICSLTL_INIT) || \
    defined (IIC_IICSMB_INIT) || \
    defined (IIC_IICC2_INIT) || \
    defined (IIC_IICC1_INIT) || \
    defined (IIC_FILT_INIT)
#define IIC_INIT_USED 1
#endif

#if defined (IIC_0_IICF_INIT) || \
    defined (IIC_0_IICA1_INIT) || \
    defined (IIC_0_IICA2_INIT) || \
    defined (IIC_0_IICSLTH_INIT) || \
    defined (IIC_0_IICSLTL_INIT) || \
    defined (IIC_0_IICSMB_INIT) || \
    defined (IIC_0_IICC2_INIT) || \
    defined (IIC_0_IICC1_INIT) || \
    defined (IIC_0_FILT_INIT)
#define IIC_0_INIT_USED 1
#endif

#if defined (IIC_1_IICF_INIT) || \
    defined (IIC_1_IICA1_INIT) || \
    defined (IIC_1_IICA2_INIT) || \
    defined (IIC_1_IICSLTH_INIT) || \
    defined (IIC_1_IICSLTL_INIT) || \
    defined (IIC_1_IICSMB_INIT) || \
    defined (IIC_1_IICC2_INIT) || \
    defined (IIC_1_IICC1_INIT) || \
    defined (IIC_1_FILT_INIT)
#define IIC_1_INIT_USED 1
#endif
    
#if defined (AOI_BFCRT010_INIT) || \
    defined (AOI_BFCRT230_INIT) || \
    defined (AOI_BFCRT011_INIT) || \
    defined (AOI_BFCRT231_INIT) || \
    defined (AOI_BFCRT012_INIT) || \
    defined (AOI_BFCRT232_INIT) || \
    defined (AOI_BFCRT013_INIT) || \
    defined (AOI_BFCRT233_INIT) 
#define AOI_INIT_USED 1
#endif


#if defined (PDB_DELAYA_INIT) || \
    defined (PDB_DELAYB_INIT) || \
    defined (PDB_MOD_INIT) || \
    defined (PDB_MCTRL_INIT) || \
    defined (PDB_DELAYC_INIT) || \
    defined (PDB_DELAYD_INIT) || \
    defined (PDB_DELAYD_INIT) || \
    defined (PDB_CTRLA_INIT) || \
    defined (PDB_CTRLC_INIT) 
#define PDB_INIT_USED 1
#endif        
        
#if  defined (PDB_1_DELAYA_INIT) || \
     defined (PDB_1_DELAYB_INIT) || \
     defined (PDB_1_MOD_INIT) || \
     defined (PDB_1_MCTRL_INIT) || \
     defined (PDB_1_DELAYC_INIT) || \
     defined (PDB_1_DELAYD_INIT) || \
     defined (PDB_1_CTRLA_INIT) || \
     defined (PDB_1_CTRLC_INIT) 
#define PDB_1_INIT_USED 1
#endif

#if defined (PDB_0_DELAYA_INIT) || \
    defined (PDB_0_DELAYB_INIT) || \
    defined (PDB_0_MOD_INIT) || \
    defined (PDB_0_MCTRL_INIT) || \
    defined (PDB_0_DELAYC_INIT) || \
    defined (PDB_0_DELAYD_INIT) || \
    defined (PDB_0_DELAYD_INIT) || \
    defined (PDB_0_CTRLA_INIT) || \
    defined (PDB_0_CTRLC_INIT) 
#define PDB_0_INIT_USED 1
#endif

#if defined (DMA_SAR0_INIT) || \
    defined (DMA_DAR0_INIT) || \
    defined (DMA_DCR0_INIT) || \
    defined (DMA_DSR_BCR0_INIT)
#define DMA_CHANNEL_0_INIT_USED 1
#endif
        
#if defined (DMA_SAR1_INIT) || \
    defined (DMA_DAR1_INIT) || \
    defined (DMA_DCR1_INIT) || \
    defined (DMA_DSR_BCR1_INIT)
#define DMA_CHANNEL_1_INIT_USED 1
#endif
        
#if defined (DMA_SAR2_INIT) || \
    defined (DMA_DAR2_INIT) || \
    defined (DMA_DCR2_INIT) || \
    defined (DMA_DSR_BCR2_INIT)
#define DMA_CHANNEL_2_INIT_USED 1
#endif
        
#if defined (DMA_SAR3_INIT) || \
    defined (DMA_DAR3_INIT) || \
    defined (DMA_DCR3_INIT) || \
    defined (DMA_DSR_BCR3_INIT)
#define DMA_CHANNEL_3_INIT_USED 1
#endif

        
#if defined (VREF_A_DACCTRL_INIT)
#define VREF_A_INIT_USED 1
#endif

#if defined (VREF_B_DACCTRL_INIT)
#define VREF_B_INIT_USED 1
#endif

#if defined (VREF_C_DACCTRL_INIT)
#define VREF_C_INIT_USED 1
#endif


#endif


