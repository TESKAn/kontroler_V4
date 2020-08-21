/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  pmc.h
*
* $Date:      Dec-17-2014$
*
* $Version:   1.0.40.0$
*
* Description: PMC, low voltage detector (LVD) and 1KHz low power oscillator
* 
* This file only supports two hardware versions of the module (PMC_VERSION_1 and PMC_VERSION_2). 
* A version  of module used in your project is defined in the "arch.h" 
* processor architecture definition file. 
*
* PMC_VERSION_1 .. 56F800x devices,  see MC56F80006RM.pdf
* PMC_VERSION_2 .. 56F84xxx devices, see MC56F844XXRM.pdf
*                  56F827xx devices, see MC56F827XXRM.pdf
*****************************************************************************/

#ifndef __PMC_H
#define __PMC_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before sys.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************
* system module identifiers, correspond to module base address
*************************************************************/

#define PMC (&ArchIO.Pmc)

/*************************************************************
* arch.h should define device-specific information about PMC
**************************************************************/

#if !defined(PMC_VERSION)
#error PMC is not properly described in arch.h (old Quick_Start version?)
#endif

#if !(defined(PMC_VERSION_1) || defined(PMC_VERSION_2))
#error This file implements PMC version 1 and 2 only (56F800x, 56F84xxx and 56F82xxx devices)
#endif

/****************************************************
* Configurable items, i.e. defines for appconfig.h
*****************************************************

/*
    initial register values:
        PMC_VERSION_1 .. MC56F800x devices
        #ifdef PMC_SCR_INIT
        #ifdef PMC_CR2_INIT
        
        
        PMC_VERSION_2 .. MC56F84xxx & MC56F827xx devices
        #ifdef PMC_CONTROL_INIT        0x7000
        
        void LowVoltageISR( void );    prototype for user ISR 
        #define INT_VECTOR_ADDR_19     interrupt vector (e.g. LowVoltageISR)

*/
/***************************************************
* 
* PMC ioctl commands
*
****************************************************/
/* command                         Param, description       */

#define PMC_INIT                                /* NULL, initialize the PMC periheral registers using the appconfig.h _INIT values */

/****************************************************************************
* PMC Version 1 commands (MC56F800x)
*****************************************************************************/
#if PMC_VERSION ==1
#define PMC_CLEAR_FLAG                          /* one of PMC_FLAG_xxx (xxx=OUT_REG/LOW_VOLT/PART_POWER_DOWN/RESET/ALL), clear the selected flag (PMSC->OORF/LVDF/PPDF/PORF) */
#define PMC_TEST_FLAG                           /* one of PMC_FLAG_xxx (xxx=OUT_REG/LOW_VOLT/PART_POWER_DOWN/RESET) test the selected flag. Return non-zero if any of the specified flags is set (PMSC->OORF/LVDF/PPDF/PORF) */
#define PMC_SET_INT_ENABLE                      /* one of PMC_INT_xxx (xxx=OUT_REG/LOW_VOLT), enable the selected interrupts (PMSC->OORIE/LVDIE) */              		
#define PMC_SET_INT_DISABLE                     /* one of PMC_INT_xxx (xxx=OUT_REG/LOW_VOLT), disable the selected interrupts (PMSC->OORIE/LVDIE) */
#define PMC_SET_LOW_VOLTAGE_RESET               /* PMC_ENABLE/PMC_DISABLE, enable/disable the hardware reset when LVDF is set (PMSC->LVDRE->PMCSC) */
#define PMC_SET_PARTIAL_POWER_DOWN              /* PMC_ENABLE/PMC_DISABLE, enable/disable the partial power down mode (PMSC->PPDE->PMCSC) */
#define PMC_SET_LOW_POWER_REGULATOR_WAIT_MODES  /* PMC_DISABLE/PMC_ENTER, set up power wait modes (PMSC->LPR) */
#define PMC_TEST_LOW_POWER_REGULATOR_STATUS     /* NULL, return the low power regulator status (PMSC->LPRS) */
#define PMC_SET_LOW_POWER_WAKEUP_INTERRUPT      /* PMC_ENABLE/PMC_DISABLE, enable/disable the low power wakeup on the interrupt (PMSC->PLWUI) */
#define PMC_SET_BANDGAP_BUFFER                  /* PMC_ENABLE/PMC_DISABLE, enable/disable the internal buffer for the bandgap voltage reference (PMSC->BGBE) */
#define PMC_SET_LOW_VOLTAGE_DETECTOR_ENABLE     /* NULL, enable the low voltage detector (PMSC->LVDE) */
#define PMC_SET_LOW_VOLTAGE_DETECTOR_DISABLE    /* NULL, disable the low voltage detector (PMSC->LVDE) */
#define PMC_SET_LOW_VOLTAGE_DETECTOR_LEVEL      /* one of PMC_LOW_VOLT_SEL_xxx (xxx=VLDL/VLDH), set the low voltage detect level (PMSC->LVLS) */
#define PMC_SET_WPROTECTION                     /* one of PMC_xxx (xxx=ENABLE/ENABLE_PERMANENT/DISABLE/DISABLE_PERMANENT), set the write-protection of the SCR and CR2 registers in the PMC module until the next reset (PMSC->PROT)*/

#define PMC_SET_1KHZ_OSC                        /* PMC_ENABLE/PMC_DISABLE, enable/disable the 1kHz low power oscillator (CR2->LPO_EN) */
#define PMC_SET_1KHZ_OSC_TRIM                   /* one of PMC_1KHZ_TRIM_xxx (xxx=p24_75/p16_5/p8_25/CENTER/n8_25/n16_5/n24_75/n33), select the 1KHz trim value (CR2->LPO_TRIM) */
#define PMC_SET_1KHZ_OSC_FACTORY_TRIM           /* NULL, set the factory trim value by reading the calibration byte from flash memory and storing it to the PMC register (CR2->LPO_TRIM) */

#define PMC_SET_LVD_TRIM                        /* one of PMC_LVD_TRIM_xxx (xxx=p14/p13/p12/p11/p10/p9/p8/p7/p6/p5/p4/p3/p2/p1/CENTER/n1/n2/n3/n4/n5/n6), set the low voltage detection (LVD) trim value (CR2->PMC_TRIM) */
#define PMC_SET_LVD_FACTORY_TRIM                /* NULL, set the factory trim value by reading the calibration byte from flash memory and storing it to the PMC register (CR2->PMC_TRIM) */
#endif /* PMC_VERSION ==1 */


/****************************************************************************
* PMC Version 2 commands (MC56F84xxx) & (MC56F827xx)
*****************************************************************************/
#if PMC_VERSION ==2
/* ctrl */
#define PMC_SET_BANDGAP_TRIM                  /* UWord16 value 0-15, set the trim value of the bandgap reference in the regulator. Its reset state is the mid-range. (STS->TRIM) */
#define PMC_GET_BANDGAP_TRIM                  /* NULL, return the trim value (0-15) of the bandgap reference in the regulator as UWord16 (STS->VRBEN) */
#define PMC_SET_ADC_VOLTAGE_REF_BUFFER        /* PMC_ENABLE/PMC_DISABLE, enable/disable the voltage reference buffer that drives the 1.2V bandgap reference to the ADC (CTRL->VRBEN) */
#define PMC_INT_ENABLE                        /* combination of PMC_xxx_LEVEL (xxx=HVI_27V|HVI_22V|LVI_27V|LVI_22V), enable the low/high voltage interrupt (CTRL->HV27IE/HV22IE/LV27IE/LV22IE) */ 
                                              /* When 
                                               *            VDDIO < 2.2V (STS[LV22F] and STS[LV27F] are both high),  both LV22IE and LV27IE should be cleared,
                                               *            VDDIO > 2.7V (STS[LV27F] is low),                        both HV22IE and HV27IE should be cleared, 
                                               *     2.2V > VDDIO < 2.7V (STS[LV22F] is low and STS[LV27F] is high), both LV27IE and HV22IE should be cleared to avoid cyclic generation of the interrupts */
#define PMC_INT_DISABLE                       /* combination of PMC_xxx_LEVEL (xxx=HVI_27V|HVI_22V|LVI_27V|LVI_22V), disable the low/high voltage interrupt (CTRL->HV27IE/HV22IE/LV27IE/LV22IE) */
#define PMC_WRITE_CTRL_REG                    /* UWord16, write to the PMC Control register (CTRL->_) */
#define PMC_READ_CTRL_REG                     /* NULL, read and return the value of PMC Control register as UWord16 (CTRL->_) */

/* sts */
#define PMC_GET_SMALL_27V_REGULATOR_STATUS    /* NULL, return the small regulator 2.7V active flag. The small regulator supplies the power to the crystal oscillator, relaxation oscillator, PLL and duty cycle corrector. It can be power down using the SIM's PWR [SR27PDN] bits (PMSC->LPRS) */
#define PMC_CLEAR_LOW_VOLTAGE_INT             /* combination of PMC_xxx (xxx=LVI|27V_LEVEL|22V_LEVEL), clear the selected low voltage interrupt flags. This command can be used for example in the LVI interrupt service routine to clear low voltage interrupt flags (STS->LVI/SLV27F/SLV22F) */
                                              /* LVI bit is set by any of by any of conditions:
                                               *      STS[LV22F]  and CTRL[LV22IE],
                                               *      STS[LV27F]  and CTRL[LV27IE],
                                               *      STS[/LV22F] and CTRL[HV22IE], or
                                               *      STS[/LV27F] and CTRL[HV27IE] */
#define PMC_CLEAR_STICKY_FLAG                 /* combination of PMC_STICKY_xxx_FLAG (xxx=LV22|LV27), clear the selected sticky low voltage flags. The flags indicate that supply voltage dropped below the 2.7V/2.2V level. Once set, those bits remain set until a 1 is written to those bit positions or until a reset occurs (STS->SLV27VF/SLV22F) */
#define PMC_TEST_FLAG                         /* combination of PMC_xxx_FLAG (xxx=STICKY_LV27|STICKY_LV22|LV_27V|LV_22V), test the selected flags (PMSC->SLV27VF/SLV22F/LV27F/LV22F) */
#define PMC_WRITE_STATUS_REG                  /* UWord16, write to the PMC Status register. Note: An inappropriate write to register might clear Write-1-to-Clear (STS->_) */
#define PMC_READ_STATUS_REG                   /* NULL, read and return the PMC Status register as UWord16 (STS->_) */

/* compatibility commands */
#define PMC_GET_LOW_VOLTAGE                   /* combination of PMC_xxx_LEVEL (xxx=22V|27V), get the low voltage sticky interrupt flags */
#define PMC_GET_NONSTICKY_INT_SOURCE          /* combination of PMC_xxx_LEVEL (xxx=22V|27V), get the low voltage nonsticky interrupts flags */
#define PMC_INT_SELECT                        /* combination of PMC_xxx_LEVEL (xxx=HVI_27V|HVI_22V|LVI_27V|LVI_22V), enable the selected low voltage interrupts */ 
#endif /* PMC_VERSION ==2 */

/****************************************************************************
* 
* PMC constants and type declarations used in the ioctl functions
*
*****************************************************************************/

#define PMC_DISABLE           0
#define PMC_ENABLE            1

/****************************************************************************
* PMC Version 1 parameters definition (MC56F800x)
*****************************************************************************/
#if PMC_VERSION ==1
#define PMC_ENTER             1

/* for permanent enable/disable */
#define PMC_DISABLE_PERMANENT 2
#define PMC_ENABLE_PERMANENT  3

/* PMC_SCR */
#define PMC_FLAG_OUT_REG                PMC_SCR_OORF           
#define PMC_FLAG_LOW_VOLT               PMC_SCR_LVDF           
#define PMC_FLAG_PART_POWER_DOWN        PMC_SCR_PPDF           
#define PMC_FLAG_RESET                  PMC_SCR_PORF           
#define PMC_FLAG_ALL                    PMC_SCR_FLAGS_MASK
#define PMC_INT_OUT_REG                 PMC_SCR_OORIE          
#define PMC_INT_LOW_VOLT                PMC_SCR_LVDIE          
#define PMC_LOW_POWER_REG_CONTROL       PMC_SCR_LPR            
#define PMC_LOW_POWER_REG_STATUS        PMC_SCR_LPRS           
#define PMC_LOW_POWER_WAKEUP_INT        PMC_SCR_LPWUI          
#define PMC_BANDGAP_BUF_ENABLE          PMC_SCR_BGBE_ENABLE    
#define PMC_LOW_VOLT_DET_ENABLE         PMC_SCR_LVDE_ENABLE    
#define PMC_LOW_VOLT_DET_DISABLE        PMC_SCR_LVDE_DISABLE
#define PMC_LOW_VOLT_SEL_VLDL           PMC_SCR_LVLS_VLDL      
#define PMC_LOW_VOLT_SEL_VLDH           PMC_SCR_LVLS_VLDH      
#define PMC_PROT_MASK                   PMC_SCR_PROT_MASK      

#define PMC_PLO_ENABLE                  PMC_CR2_PLO_EN
#define PMC_PLO_TRIM_MASK               PMC_CR2_PLO_TRIM_MASK
#define PMC_TRIM_MASK                   PMC_CR2_TRIM_MASK

#define PMC_1KHZ_TRIM_p24_75            PMC_CR2_PLO_TRIM_p24_75
#define PMC_1KHZ_TRIM_p16_5             PMC_CR2_PLO_TRIM_p16_5
#define PMC_1KHZ_TRIM_p8_25             PMC_CR2_PLO_TRIM_p8_25
#define PMC_1KHZ_TRIM_CENTER            PMC_CR2_PLO_TRIM_CENTER
#define PMC_1KHZ_TRIM_n8_25             PMC_CR2_PLO_TRIM_n8_25
#define PMC_1KHZ_TRIM_n16_5             PMC_CR2_PLO_TRIM_n16_5
#define PMC_1KHZ_TRIM_n24_75            PMC_CR2_PLO_TRIM_n24_75
#define PMC_1KHZ_TRIM_n33               PMC_CR2_PLO_TRIM_n33

#define PMC_LVD_TRIM_p14                0x11
#define PMC_LVD_TRIM_p13                0x12
#define PMC_LVD_TRIM_p12                0x13
#define PMC_LVD_TRIM_p11                0x14
#define PMC_LVD_TRIM_p10                0x15
#define PMC_LVD_TRIM_p9                 0x16 
#define PMC_LVD_TRIM_p8                 0x17
#define PMC_LVD_TRIM_p7                 0x18
#define PMC_LVD_TRIM_p6                 0x19
#define PMC_LVD_TRIM_p5                 0x1A
#define PMC_LVD_TRIM_p4                 0x1B
#define PMC_LVD_TRIM_p3                 0x1C
#define PMC_LVD_TRIM_p2                 0x1D
#define PMC_LVD_TRIM_p1                 0x1E
#define PMC_LVD_TRIM_CENTER             0x1F 
#define PMC_LVD_TRIM_n1                 0x00
#define PMC_LVD_TRIM_n2                 0x01
#define PMC_LVD_TRIM_n3                 0x02
#define PMC_LVD_TRIM_n4                 0x03
#define PMC_LVD_TRIM_n5                 0x04
#define PMC_LVD_TRIM_n6                 0x05
#endif /* PMC_VERSION ==1 */


/****************************************************************************
* PMC Version 2 parameters definition (MC56F84xxx) & (MC56F827xx)
*****************************************************************************/
#if PMC_VERSION ==2
/* CTRL */
#define PMC_TRIM_MASK                     PMC_CTRL_TRIM
#define PMC_ADC_VOLTAGE_REF_BUFFER        PMC_CTRL_VRBEN
#define PMC_HVI_27V_LEVEL                 PMC_CTRL_HV27IE
#define PMC_HVI_22V_LEVEL                 PMC_CTRL_HV22IE
#define PMC_LVI_27V_LEVEL                 PMC_CTRL_LV27IE
#define PMC_LVI_22V_LEVEL                 PMC_CTRL_LV22IE
#define PMC_INT_ENABLE_MASK               (PMC_CTRL_HV27IE | PMC_CTRL_HV22IE | PMC_CTRL_LV27IE | PMC_CTRL_LV22IE) 
/* STS */
#define PMC_SMALL_REG_27V_ACTIVE_FLAG     PMC_STS_SR27
#define PMC_LOW_VOLTAGE_INT_FLAG          PMC_STS_LVI
#define PMC_LVI                           PMC_STS_LVI
#define PMC_STICKY_LV27_FLAG              PMC_STS_SLV27F
#define PMC_STICKY_LV22_FLAG              PMC_STS_SLV22F
#define PMC_LV_27V_FLAG                   PMC_STS_LV27F
#define PMC_27V_LEVEL                     PMC_STS_LV27F
#define PMC_LV_22V_FLAG                   PMC_STS_LV22F
#define PMC_22V_LEVEL                     PMC_STS_LV22F
#endif /* PMC_VERSION ==2 */


/****************************************************************************
* 
* register bit names and masks used inc ioctl functions below
*
*****************************************************************************/

/****************************************************************************
* PMC Version 1 (MC56F800x)
*****************************************************************************/
#if PMC_VERSION ==1
/* PMC_SCR */
#define PMC_SCR_OORF           0x8000
#define PMC_SCR_LVDF           0x4000
#define PMC_SCR_PPDF           0x2000
#define PMC_SCR_PORF           0x1000
#define PMC_SCR_FLAGS_MASK     0xf000
#define PMC_SCR_OORIE          0x0800
#define PMC_SCR_LVDIE          0x0400
#define PMC_SCR_LVDRE          0x0200
#define PMC_SCR_PPDE           0x0100
#define PMC_SCR_LPR            0x0080
#define PMC_SCR_LPRS           0x0040
#define PMC_SCR_LPWUI          0x0020
#define PMC_SCR_BGBE_ENABLE    0x0010
#define PMC_SCR_BGBE_DISABLE   0x0000
#define PMC_SCR_LVDE_ENABLE    0x0008
#define PMC_SCR_LVDE_DISABLE   0x0000
#define PMC_SCR_LVLS_VLDL      0x0000
#define PMC_SCR_LVLS_VLDH      0x0004
#define PMC_SCR_PROT_MASK      0x0003

/* PMC_CR2 */
#define PMC_CR2_PLO_EN          0x0100
#define PMC_CR2_PLO_TRIM_MASK   0x00E0
#define PMC_CR2_PLO_TRIM_p24_75 0x0080
#define PMC_CR2_PLO_TRIM_p16_5  0x00A0
#define PMC_CR2_PLO_TRIM_p8_25  0x00C0
#define PMC_CR2_PLO_TRIM_CENTER 0x00E0
#define PMC_CR2_PLO_TRIM_n8_25  0x0000
#define PMC_CR2_PLO_TRIM_n16_5  0x0020
#define PMC_CR2_PLO_TRIM_n24_75 0x0040
#define PMC_CR2_PLO_TRIM_n33    0x0060
#define PMC_CR2_TRIM_MASK       0x001F
#endif /* PMC_VERSION ==1 */

/****************************************************************************
* PMC Version 2 (MC56F84xxx) & (MC56F827xx)
*****************************************************************************/
#if PMC_VERSION ==2
/* PMC_CTRL */
#define PMC_CTRL_TRIM           0xF000
#define PMC_CTRL_VRBEN          0x0080
#define PMC_CTRL_HV27IE         0x0008
#define PMC_CTRL_HV22IE         0x0004
#define PMC_CTRL_LV27IE         0x0002
#define PMC_CTRL_LV22IE         0x0001

/* PMC_STS */
#define PMC_STS_SR27            0x0020
#define PMC_STS_LVI             0x0010
#define PMC_STS_SLV27F          0x0008
#define PMC_STS_SLV22F          0x0004
#define PMC_STS_LV27F           0x0002
#define PMC_STS_LV22F           0x0001
#endif /* PMC_VERSION ==2 */


/***********************************************************************
* 
* PMC control command macros
*
************************************************************************/
/* PMC initialization */
void pmcInit(arch_sPMC *pPmcBase);
#define ioctlPMC_INIT(pPmcBase, param)        pmcInit(pPmcBase)

/****************************************************************************
* PMC Version 1 (MC56F800x)
*****************************************************************************/
#if PMC_VERSION ==1

/* LVD clear interrupt flag  */
#define ioctlPMC_CLEAR_FLAG(pPmcBase, param) \
  periphSafeAckByOne(PMC_FLAG_ALL, param, &((pPmcBase)->scr))

/* LVD test interrupt flag  */
#define ioctlPMC_TEST_FLAG(pPmcBase, param) \
  periphBitTest(param, &((pPmcBase)->scr))

/* Enables selected Interrupts */
#define ioctlPMC_SET_INT_ENABLE(pPmcBase, param) \
  periphSafeBitSet(PMC_FLAG_ALL, param, &((pPmcBase)->scr))

/* Disables selected Interrupt */
#define ioctlPMC_SET_INT_DISABLE(pPmcBase, param) \
  periphSafeBitClear(PMC_FLAG_ALL, param, &((pPmcBase)->scr))

/* Enables / disables LVD hardware reset */
#define ioctlPMC_SET_LOW_VOLTAGE_RESET(pPmcBase, param) \
  if (param) periphSafeBitSet(PMC_FLAG_ALL, PMC_SCR_LVDRE, &((pPmcBase)->scr)); \
  else periphSafeBitClear(PMC_FLAG_ALL, PMC_SCR_LVDRE, &((pPmcBase)->scr))

/* Enables / disables partial power down */
#define ioctlPMC_SET_PARTIAL_POWER_DOWN(pPmcBase, param) \
  if (param) periphSafeBitSet(PMC_FLAG_ALL, PMC_SCR_PPDE, &((pPmcBase)->scr)); \
  else periphSafeBitClear(PMC_FLAG_ALL, PMC_SCR_PPDE, &((pPmcBase)->scr))

/* set up power wait modes */
#define ioctlPMC_SET_LOW_POWER_REGULATOR_WAIT_MODES(pPmcBase, param) \
  if (param) periphSafeBitSet(PMC_FLAG_ALL, PMC_LOW_POWER_REG_CONTROL, &((pPmcBase)->scr)); \
  else periphSafeBitClear(PMC_FLAG_ALL, PMC_LOW_POWER_REG_CONTROL, &((pPmcBase)->scr))

/* test status bit for low power regulator */
#define ioctlPMC_TEST_LOW_POWER_REGULATOR_STATUS(pPmcBase, param) \
  periphBitTest(PMC_LOW_POWER_REG_STATUS, &((pPmcBase)->scr))

/* set up power wake up on interrupt mode */
#define ioctlPMC_SET_LOW_POWER_WAKEUP_INTERRUPT(pPmcBase, param) \
  if (param) periphSafeBitSet(PMC_FLAG_ALL, PMC_LOW_POWER_WAKEUP_INT, &((pPmcBase)->scr)); \
  else periphSafeBitClear(PMC_FLAG_ALL, PMC_LOW_POWER_WAKEUP_INT, &((pPmcBase)->scr))

/* set up internal buffer for the bandgap voltage reference for use by ADC module */
#define ioctlPMC_SET_BANDGAP_BUFFER(pPmcBase, param) \
  if (param) periphSafeBitSet(PMC_FLAG_ALL, PMC_BANDGAP_BUF_ENABLE, &((pPmcBase)->scr)); \
  else periphSafeBitClear(PMC_FLAG_ALL, PMC_BANDGAP_BUF_ENABLE, &((pPmcBase)->scr))

/* LVD enable */
#define ioctlPMC_SET_LOW_VOLTAGE_DETECTOR_ENABLE(pPmcBase, param) \
  periphSafeBitSet(PMC_FLAG_ALL, PMC_LOW_VOLT_DET_ENABLE, &((pPmcBase)->scr))

/* LVD disable */
#define ioctlPMC_SET_LOW_VOLTAGE_DETECTOR_DISABLE(pPmcBase, param) \
  periphSafeBitClear(PMC_FLAG_ALL, PMC_LOW_VOLT_DET_ENABLE, &((pPmcBase)->scr))

/* set low voltage detect level */
#define ioctlPMC_SET_LOW_VOLTAGE_DETECTOR_LEVEL(pPmcBase, param) \
  if (param) periphSafeBitSet(PMC_FLAG_ALL, PMC_LOW_VOLT_SEL_VLDH, &((pPmcBase)->scr)); \
  else periphSafeBitClear(PMC_FLAG_ALL, PMC_LOW_VOLT_SEL_VLDH, &((pPmcBase)->scr))

/* protect SCR and CR2 */
#define ioctlPMC_SET_WPROTECTION(pPmcBase, param)    \
  periphSafeBitGrpSet(PMC_FLAG_ALL, PMC_SCR_PROT_MASK, (param), &((pPmcBase)->scr))

/* set up power wake up on interrupt mode */
#define ioctlPMC_SET_1KHZ_OSC(pPmcBase, param) \
  if(param) periphBitSet(PMC_CR2_PLO_EN, &((pPmcBase)->cr2)); \
  else periphBitClear(PMC_CR2_PLO_EN, &((pPmcBase)->cr2))

/* set 1KHz trim value */
#define ioctlPMC_SET_1KHZ_OSC_TRIM(pPmcBase, param)    \
  periphBitGrpSet(PMC_CR2_PLO_TRIM_MASK, (param), &((pPmcBase)->cr2))

/* set 1KHz factory trim value */
#define ioctlPMC_SET_1KHZ_OSC_FACTORY_TRIM(pPmcBase, param) { \
    register UWord16 __tmp = *(&ArchIO.Hfm.fmopt0); \
    register UWord16 __tmp2 = *(&((pPmcBase)->cr2)); \
    __tmp &= (PMC_CR2_PLO_TRIM_MASK); \
    __tmp2 &= (~(PMC_CR2_PLO_TRIM_MASK)); \
    __tmp ^= __tmp2; \
    *(&((pPmcBase)->cr2)) = __tmp; \
    }    

/* set LVD trim value */
#define ioctlPMC_SET_LVD_TRIM(pPmcBase, param)    \
  periphBitGrpSet(PMC_CR2_TRIM_MASK, (param), &((pPmcBase)->cr2))

/* set LVD factory trim value */
#define ioctlPMC_SET_LVD_FACTORY_TRIM(pPmcBase, param) { \
    register UWord16 __tmp = *(&ArchIO.Hfm.fmopt0); \
    register UWord16 __tmp2 = *(&((pPmcBase)->cr2)); \
    __tmp &= (PMC_CR2_TRIM_MASK); \
    __tmp2 &= (~(PMC_CR2_TRIM_MASK)); \
    __tmp ^= __tmp2; \
    *(&((pPmcBase)->cr2)) = __tmp; \
    }    
#endif /* PMC_VERSION ==1 */

/****************************************************************************
* PMC Version 2 (MC56F84xxx) & (MC56F827xx)
*****************************************************************************/
#if PMC_VERSION ==2


/* ctrl */
/* UWord16, Write the trim value (0-15) of the bandgap reference in the regulator */
#define ioctlPMC_SET_BANDGAP_TRIM(pPmcBase, param) \
  periphBitGrpSet(PMC_TRIM_MASK, ((param) << 12), &((pPmcBase)->ctrl))

/* NULL, Reads the trim value (0-15) of the bandgap reference */
#define ioctlPMC_GET_BANDGAP_TRIM(pPmcBase, param) \
(periphMemRead(&((pPmcBase)->ctrl)) >> 12)

 /* Enable/Disable a buffer that drives the 1.2V bangap reference to the ADC */
#define ioctlPMC_SET_ADC_VOLTAGE_REF_BUFFER(pPmcBase, param) \
  if (param) periphBitSet(PMC_ADC_VOLTAGE_REF_BUFFER, &((pPmcBase)->ctrl)); \
  else periphBitClear(PMC_ADC_VOLTAGE_REF_BUFFER, &((pPmcBase)->ctrl))

/* Enable low/high voltage interrupt */
#define ioctlPMC_INT_ENABLE(pPmcBase, param) \
  periphBitSet ((param), &((pPmcBase)->ctrl))

/* Disable low/high voltage interrupt */
#define ioctlPMC_INT_DISABLE(pPmcBase, param) \
  periphBitClear ((param), &((pPmcBase)->ctrl))

/* UWord16, Write to PMC Control Register */
#define ioctlPMC_WRITE_CTRL_REG(pPmcBase, param) \
  periphMemWrite((param), &((pPmcBase)->ctrl))

/* Read the PMC Control Register as UWord16 */
#define ioctlPMC_READ_CTRL_REG(pPmcBase, param)  \
  periphMemRead(&((pPmcBase)->ctrl))

/* Select which low/high voltage interrupts will be enabled */
#define ioctlPMC_INT_SELECT(pPmcBase, param) \
  periphBitGrpSR(PMC_CTRL_HV27IE | PMC_CTRL_HV22IE | PMC_CTRL_LV27IE | PMC_CTRL_LV22IE, (param), &((pPmcBase)->ctrl))


/* sts - contains w1c flags */
/* NULL, get small regulator 2.7 active flag */
#define ioctlPMC_GET_SMALL_27V_REGULATOR_STATUS(pPmcBase, param) \
  periphBitTest(PMC_SMALL_REG_27V_ACTIVE_FLAG, &((pPmcBase)->sts))

/* Clear selected low voltage interrupt flags */
#define ioctlPMC_CLEAR_LOW_VOLTAGE_INT(pPmcBase, param) \
  periphSafeAckByOne(PMC_LOW_VOLTAGE_INT_FLAG | PMC_STICKY_LV27_FLAG | PMC_STICKY_LV22_FLAG, (param), &((pPmcBase)->sts)) 

/* Clear sticky low voltage flags */
#define ioctlPMC_CLEAR_STICKY_FLAG(pPmcBase, param) \
  periphSafeAckByOne(PMC_LOW_VOLTAGE_INT_FLAG | PMC_STICKY_LV27_FLAG | PMC_STICKY_LV22_FLAG, ((param) << 2), &((pPmcBase)->sts)) 

/* Test state of non/sticky and low voltage interrupt flags */
#define ioctlPMC_TEST_FLAG(pPmcBase, param) \
  periphBitTest((param), &((pPmcBase)->sts)) 

/* UWord16, Write to the PMC Status Register */
#define ioctlPMC_WRITE_STATUS_REG(pPmcBase, param) \
  periphMemWrite((param), &((pPmcBase)->sts))

/* NULL, Read the PMC Status Register as UWord16 */
#define ioctlREAD_STATUS_REG(pPmcBase, param)  \
  periphMemRead(&((pPmcBase)->sts))

/* return low voltage sticky interrupt flags */
#define ioctlPMC_GET_LOW_VOLTAGE(pPmcBase, param) \
  periphBitTest(((param) << 2), &((pPmcBase)->sts))

/* return low voltage nonsticky flags */
#define ioctlPMC_GET_NONSTICKY_INT_SOURCE(pPmcBase, param) \
  periphBitTest((param), &((pPmcBase)->sts))
#endif /* PMC_VERSION ==2 */


#ifdef __cplusplus
}
#endif

#endif

