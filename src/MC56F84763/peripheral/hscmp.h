/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  hscmp.h
*
* $Date:      Dec-17-2014$
*
* $Version:   2.5.19.0$
*
* Description: Header file for the HSCMP driver
*
* This file supports different hardware versions of the module. A version
* of module used in your project is defined in the "arch.h" processor 
* architecture definition file.
* 
* HSCMP_VERSION_1 .. 56F800x devices, see MC56F8006RM.pdf
* HSCMP_VERSION_2 .. 56F82xx devices, see MC56F82xxRM.pdf
* HSCMP_VERSION_3 .. 56F823xx devices, see MC56F823xxRM.pdf, 56F827xx devices, see MC56F827xxRM.pdf
*                    56F844xx devices, see MC56F844xxRM.pdf, 56F847xx devices, see MC56F847XXRM.pdf
*
*******************************************************************************/

#ifndef __HSCMP_H
#define __HSCMP_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before hscmp.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*
*                      General Interface Description
*
*
* The comparator (HSCMP) includes a digital control interface and an analog 
* comparator module. The analog comparator also includes a four-input analog 
* switching matrix with the continuous-time differential-input analog
* comparator function. 
*
******************************************************************************/

/************************************************************
* HSCMP module identifiers
*************************************************************/

#ifdef HSCMP0_BASE
#define HSCMP_0 (&ArchIO.Hscmp0)
#endif
#ifdef HSCMP1_BASE
#define HSCMP_1 (&ArchIO.Hscmp1)
#endif
#ifdef HSCMP2_BASE
#define HSCMP_2 (&ArchIO.Hscmp2)
#endif

#ifdef HSCMPA_BASE
#define HSCMP_A (&ArchIO.HscmpA)
#endif

#ifdef HSCMPB_BASE
#define HSCMP_B (&ArchIO.HscmpB)
#endif

#ifdef HSCMPC_BASE
#define HSCMP_C (&ArchIO.HscmpC)
#endif

#ifdef HSCMPD_BASE
#define HSCMP_D (&ArchIO.HscmpD)
#endif

/*************************************************************
* arch.h should define device-specific information about HSCMP
**************************************************************/

#if !defined(HSCMP_VERSION)
#error HSCMP not properly described in arch.h
#endif

/****************************************************
* Configurable items, i.e. defines for appconfig.h
*****************************************************

  #define HSCMP_x_CR0_INIT
  #define HSCMP_x_CR1_INIT
  #define HSCMP_x_FPR_INIT
  #define HSCMP_x_SCR_INIT

*/

/*****************************************************************
* Single-Instruction ioctl() commands
*
*  Word16 ioctl( HSCMP_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define HSCMP_MODULE                 /* HSCMP_ENABLE/HSCMP_DISABLE, enable/disable the HSCMP module (CR1->EN) */
#define HSCMP_SET_INVERT             /* HSCMP_ENABLE/HSCMP_DISABLE, enable/disable the logic-level inverter at the high speed comparator output (CR1->INV) */
#define HSCMP_SET_SAMPLE             /* HSCMP_ENABLE/HSCMP_DISABLE, enable/disable the sample mode at the high speed comparator module (CR1->SE) */
#define HSCMP_SET_WINDOWING          /* HSCMP_ENABLE/HSCMP_DISABLE, enable/disable the windowing mode at the high speed comparator output (CR1->WE) */
#define HSCMP_SET_HIGH_SPEED         /* HSCMP_ENABLE/HSCMP_DISABLE, if enabled, the comparator is put to the high speed comparison mode. If disabled, the comparator is put to power saving mode (CR1->PMODE) */
#define HSCMP_SET_OUTPUT_PIN         /* HSCMP_COUT/HSCMP_COUTA, the parameter HSCMP_COUT sets CMPO to filtered comparator output (COUT). The HSCMP_COUTA selects unfiltered comparator output (COUTA) (CR1->COS) */
#define HSCMP_SET_OUTPUT_ACTIVE      /* HSCMP_ENABLE/HSCMP_DISABLE, enable/disable the comparator ouput pin (CR1->OPE) */
#define HSCMP_TEST_INT_FLAGS         /* HSCMP_FLAG_RISING_EDGE/HSCMP_FLAG_FALLING_EDGE, test and returns the value of the selected comparator interrupt flag (SCR->CFR,CFF) */
#define HSCMP_CLEAR_INT_FLAGS        /* HSCMP_FLAG_RISING_EDGE/HSCMP_FLAG_FALLING_EDGE, clear the selected comparator interrupt flag (SCR->CFR,CFF) */
#define HSCMP_TEST_OUTPUT            /* NULL, return zero/nonzero current comparator output state (SCR->COUNT) */
#define HSCMP_READ_FILT_REG          /* NULL, read and return the value of the Output Filter register as UWord16 (FPR->_) */
#define HSCMP_WRITE_FILT_REG         /* UWord16, write directly to the Filter Period Register. The comparator output signal can be filtered by applying a digital counting filter. The FPR register contains the filter sample period value so this command may be used to reconfigure the filter in run-time (FPR->_)*/


/*****************************************************************
* Multi-Instruction ioctl() commands
*
*  Word16 ioctl( HSCMP_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#if HSCMP_VERSION <= 2 
#define HSCMP_SELECT_POS_INPUT          /* HSCMP_PIN_x (x=1/2/3/4), select the positive HSCMP input (CR0->PMC)*/
#define HSCMP_SELECT_NEG_INPUT          /* HSCMP_PIN_x (x=1/2/3/4), select the negative HSCMP input (CR0->MMC)*/
#endif

#if HSCMP_VERSION >= 3
#define HSCMP_HARD_BLOCK_HYSTERESIS     /* HSCMP_HYST_LEVEL_x (x=0/1/2/3), set the programmable hysteresis level.  (CR0->HYSTCTR)*/
#define HSCMP_DAC                       /* HSCMP_ENABLE/HSCMP_DISABLE, enable/disable the 6-bit DAC comparator reference (DACCR->DACEN) */
#define HSCMP_REFERENCE_SELECT          /* HSCMP_VIN1IN / HSCMP_VIN2IN, select the supply voltage for the comparator reference source (DACCR->VRSEL) */
#define HSCMP_DAC_OUT_VOLTAGE_SELECT    /* UWord16 value 0-63, set the "VOSEL" DAC output voltage DACO = V_in /64 * (VOSEL + 1) (DACCR->VOSEL) */
#define HSCMP_MINUS_INPUT               /* HSCMP_INx (x=0-7), sSelect the negative input of the comparator (MUXCR->MSEL)*/
#define HSCMP_PLUS_INPUT                /* HSCMP_INx (x=0-7), select the positive input of the comparator (MUXCR->PSEL)*/
#define HSCMP_PASS_THROUGH_MODE         /* HSCMP_ENABLE/HSCMP_DISABLE, enable/disable the MUX pass through mode. (MUXCR->PSTM) */
#endif

#define HSCMP_WRITE_FILT_COUNTER     /* HSCMP_FILTER_COUNTER_x (x=0-7), set the filter counter (CR0->FILTER_CNT) */
#define HSCMP_INT_RISING_EDGE        /* HSCMP_ENABLE/HSCMP_DISABLE, enable/disable the rising edge interrupt (SCR->IER) */
#define HSCMP_INT_FALLING_EDGE       /* HSCMP_ENABLE/HSCMP_DISABLE, enable/disable the falling edge interrupt (SCR->IEF) */
#define HSCMP_READ_FILT_COUNTER      /* NULL, read and return the value of the filter counter (CR0->FILTER_CNT) */


#if HSCMP_VERSION == 2
#define HSCMP_SET_INT_MODE_IN_STOP   /* HSCMP_EDGE_SENSITIVE/HSCMP_LEVEL_SENSITIVE, set the interrupt sensitivity in the stop mode (SCR->SMELB) */
#define HSCMP_SET_HYSTERESIS         /* HSCMP_LEVEL_x (x=1/2/3/4), select the hysteresis of the analog comparator (SCR->HYST_SEL) */
#endif


/*****************************************************************
* Software Layer ioctl() commands
*
*  Word16 ioctl( HSCMP_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define HSCMP_INIT                   /* NULL, initialize the HSCMP peripheral registers using the appconfig.h _INIT values */


/*****************************************************************************
* HSCMP ioctl command parameters 
******************************************************************************/

#define HSCMP_ENABLE            1
#define HSCMP_DISABLE           0

/* CR0 */
#define HSCMP_FILTER_COUNTER_0   HSCMP_CR0_FILTER_CNT_0
#define HSCMP_FILTER_COUNTER_1   HSCMP_CR0_FILTER_CNT_1
#define HSCMP_FILTER_COUNTER_2   HSCMP_CR0_FILTER_CNT_2
#define HSCMP_FILTER_COUNTER_3   HSCMP_CR0_FILTER_CNT_3
#define HSCMP_FILTER_COUNTER_4   HSCMP_CR0_FILTER_CNT_4
#define HSCMP_FILTER_COUNTER_5   HSCMP_CR0_FILTER_CNT_5
#define HSCMP_FILTER_COUNTER_6   HSCMP_CR0_FILTER_CNT_6
#define HSCMP_FILTER_COUNTER_7   HSCMP_CR0_FILTER_CNT_7
/* due to backward compatibility */
#define HSCMP_FILTR_COUNTER_0   HSCMP_CR0_FILTER_CNT_0
#define HSCMP_FILTR_COUNTER_1   HSCMP_CR0_FILTER_CNT_1
#define HSCMP_FILTR_COUNTER_2   HSCMP_CR0_FILTER_CNT_2
#define HSCMP_FILTR_COUNTER_3   HSCMP_CR0_FILTER_CNT_3
#define HSCMP_FILTR_COUNTER_4   HSCMP_CR0_FILTER_CNT_4
#define HSCMP_FILTR_COUNTER_5   HSCMP_CR0_FILTER_CNT_5
#define HSCMP_FILTR_COUNTER_6   HSCMP_CR0_FILTER_CNT_6
#define HSCMP_FILTR_COUNTER_7   HSCMP_CR0_FILTER_CNT_7

#define HSCMP_PIN_1             0
#define HSCMP_PIN_2             1
#define HSCMP_PIN_3             2
#define HSCMP_PIN_4             3

/* CR1 */
#define HSCMP_COUT             0
#define HSCMP_COUTA            1

/* SCR */
#define HSCMP_FLAG_RISING_EDGE  HSCMP_SCR_CFR  
#define HSCMP_FLAG_FALLING_EDGE HSCMP_SCR_CFF
#define HSCMP_FLAG_ALL          (HSCMP_SCR_CFF | HSCMP_SCR_CFR)
#if HSCMP_VERSION >= 2
#define HSCMP_LEVEL_SENSITIVE   0
#define HSCMP_EDGE_SENSITIVE    1
#define HSCMP_LEVEL_1           0
#define HSCMP_LEVEL_2           1
#define HSCMP_LEVEL_3           2
#define HSCMP_LEVEL_4           3
#endif

/****************************************************************************
* register and bit names used in the ioctl functions below
*****************************************************************************/

/* HSCMP Control register */
/* CR0 */
#if HSCMP_VERSION <= 2 
#define HSCMP_CR0_FILTER_CNT_MASK    0x0070
#define HSCMP_CR0_FILTER_CNT_0       0x0000
#define HSCMP_CR0_FILTER_CNT_1       0x0010
#define HSCMP_CR0_FILTER_CNT_2       0x0020
#define HSCMP_CR0_FILTER_CNT_3       0x0030
#define HSCMP_CR0_FILTER_CNT_4       0x0040
#define HSCMP_CR0_FILTER_CNT_5       0x0050
#define HSCMP_CR0_FILTER_CNT_6       0x0060
#define HSCMP_CR0_FILTER_CNT_7       0x0070

#define HSCMP_CR0_PMC_MASK            0x000C
#define HSCMP_CR0_MMC_MASK            0x0003
#endif


/* CR1 */
#define HSCMP_CR1_SE                  0x0080
#define HSCMP_CR1_WE                  0x0040
#define HSCMP_CR1_PMODE               0x0010
#define HSCMP_CR1_INV                 0x0008
#define HSCMP_CR1_COS                 0x0004
#define HSCMP_CR1_OPE                 0x0002
#define HSCMP_CR1_EN                  0x0001
              
/* SCR */
#define HSCMP_SCR_IER                 0x0010
#define HSCMP_SCR_IEF                 0x0008
#define HSCMP_SCR_CFR                 0x0004
#define HSCMP_SCR_CFF                 0x0002
#define HSCMP_SCR_COUNT               0x0001
              
#if HSCMP_VERSION == 2
#define HSCMP_SCR_SMELB               0x0020
#define HSCMP_SCR_HYST_SEL_MASK       0x00C0
#endif

#if HSCMP_VERSION >= 3
#define HSCMP_DACCR_DACEN             0x0080
#define HSCMP_DACCR_VRSEL             0x0040
#define HSCMP_VIN1IN                  0x0000
#define HSCMP_VIN2IN                  0x0001
#define HSCMP_DACCR_VOSEL_MASK        0x003F

#define HSCMP_CR0_HYSTCTR_MASK        0x0003

#define HSCMP_HYST_LEVEL_0            0x0000
#define HSCMP_HYST_LEVEL_1            0x0001
#define HSCMP_HYST_LEVEL_2            0x0002
#define HSCMP_HYST_LEVEL_3            0x0003
#define HSCMP_IN0                     0x00 
#define HSCMP_IN1                     0x01
#define HSCMP_IN2                     0x02
#define HSCMP_IN3                     0x03
#define HSCMP_IN4                     0x04
#define HSCMP_IN5                     0x05
#define HSCMP_IN6                     0x06
#define HSCMP_IN7                     0x07
#define HSCMP_MUXCR_PSTM              0x80
#define HSCMP_MUXCR_MSEL_MASK         0x07
#define HSCMP_MUXCR_PSEL_MASK         0x38

                
#endif

/****************************************************************************
* HSCMP ioctl macro implementation
*****************************************************************************/

/***********************************************************************
* HSCMP init
***********************************************************************/

void hscmpInit(arch_sHSCMP *pHscmpBase);
#define ioctlHSCMP_INIT(pHscmpBase, param) hscmpInit(pHscmpBase)

/* CR0 */
/* reads filter sample count */
#define ioctlHSCMP_READ_FILT_COUNTER(pHscmpBase, param) \
  (periphMemRead(&((pHscmpBase)->cr0)))>>4

/* writes filter sample count */
#define ioctlHSCMP_WRITE_FILT_COUNTER(pHscmpBase, param) \
  periphBitGrpSet(HSCMP_CR0_FILTER_CNT_MASK, param ,  &((pHscmpBase)->cr0))

#if HSCMP_VERSION <= 2 
/* selects positive HSCMP input pin */
#define ioctlHSCMP_SELECT_POS_INPUT(pHscmpBase, param) \
  periphBitGrpSet(HSCMP_CR0_PMC_MASK, (param) << 2,  &((pHscmpBase)->cr0))

/* selects positive HSCMP input pin */
#define ioctlHSCMP_SELECT_NEG_INPUT(pHscmpBase, param) \
  periphBitGrpSet(HSCMP_CR0_MMC_MASK, param ,  &((pHscmpBase)->cr0))
#endif

#if HSCMP_VERSION >= 3 

#define ioctlHSCMP_HARD_BLOCK_HYSTERESIS(pHscmpBase, param) \
  periphBitGrpSet(HSCMP_CR0_HYSTCTR_MASK, param ,  &((pHscmpBase)->cr0))

/* Enables/Disables DAC */
#define ioctlHSCMP_DAC(pHscmpBase, param) \
        if (param) periphBitSet(HSCMP_DACCR_VRSEL, &((pHscmpBase)->daccr)); \
        else periphBitClear(HSCMP_DACCR_DACEN, &((pHscmpBase)->daccr))

/* Select reference */
#define ioctlHSCMP_REFERENCE_SELECT(pHscmpBase, param) \
        if (param) periphBitSet(HSCMP_DACCR_VRSEL, &((pHscmpBase)->daccr)); \
        else periphBitClear(HSCMP_DACCR_VRSEL, &((pHscmpBase)->daccr))

/* Select DAC outout */
#define ioctlHSCMP_DAC_OUT_VOLTAGE_SELECT(pHscmpBase, param) \
        periphBitGrpSet(HSCMP_DACCR_VOSEL_MASK, param ,  &((pHscmpBase)->daccr))

/* enable to MUX pass through mode. */
#define ioctlHSCMP_PASS_THROUGH_MODE(pHscmpBase, param) \
        if (param) periphBitSet(HSCMP_MUXCR_PSTM, &((pHscmpBase)->muxcr)); \
        else periphBitClear(HSCMP_MUXCR_PSTM, &((pHscmpBase)->muxcr))

/*Determines which input is selected for the minus input of the comparator*/
#define ioctlHSCMP_MINUS_INPUT(pHscmpBase, param) \
  periphBitGrpSet(HSCMP_MUXCR_MSEL_MASK, param ,  &((pHscmpBase)->muxcr))

/*Determines which input is selected for the plus input of the comparator*/
#define ioctlHSCMP_PLUS_INPUT(pHscmpBase, param) \
  periphBitGrpSet(HSCMP_MUXCR_PSEL_MASK, (param << 3) ,  &((pHscmpBase)->muxcr))


#endif

/* CR1 */
/* Enables/Disables CMP module */
#define ioctlHSCMP_MODULE(pHscmpBase, param) \
  if (param) periphBitSet(HSCMP_CR1_EN, &((pHscmpBase)->cr1)); \
  else periphBitClear(HSCMP_CR1_EN, &((pHscmpBase)->cr1))

#define ioctlHSCMP_SET_INVERT(pHscmpBase, param) \
  if (param) periphBitSet(HSCMP_CR1_INV, &((pHscmpBase)->cr1)); \
  else periphBitClear(HSCMP_CR1_INV, &((pHscmpBase)->cr1))

/* Sets sample mode */
#define ioctlHSCMP_SET_SAMPLE(pHscmpBase, param) \
  if (param) periphBitSet(HSCMP_CR1_SE, &((pHscmpBase)->cr1)); \
  else periphBitClear(HSCMP_CR1_SE, &((pHscmpBase)->cr1))

/* Sets windowing mode */
#define ioctlHSCMP_SET_WINDOWING(pHscmpBase, param) \
  if (param) periphBitSet(HSCMP_CR1_WE, &((pHscmpBase)->cr1)); \
  else periphBitClear(HSCMP_CR1_WE, &((pHscmpBase)->cr1))

/* Sets power mode */
#define ioctlHSCMP_SET_HIGH_SPEED(pHscmpBase, param) \
  if (param) periphBitSet(HSCMP_CR1_PMODE, &((pHscmpBase)->cr1)); \
  else periphBitClear(HSCMP_CR1_PMODE, &((pHscmpBase)->cr1))

/* Selects comparator output  */
#define ioctlHSCMP_SET_OUTPUT_PIN(pHscmpBase, param) \
  if (param) periphBitSet(HSCMP_CR1_COS, &((pHscmpBase)->cr1)); \
  else periphBitClear(HSCMP_CR1_COS, &((pHscmpBase)->cr1))

/* Sets power mode */
#define ioctlHSCMP_SET_OUTPUT_ACTIVE(pHscmpBase, param) \
  if (param) periphBitSet(HSCMP_CR1_OPE, &((pHscmpBase)->cr1)); \
  else periphBitClear(HSCMP_CR1_OPE, &((pHscmpBase)->cr1))

/* SCR */
/* Enables/Disables rising edge interrupt */
#define ioctlHSCMP_INT_RISING_EDGE(pHscmpBase, param) \
  if (param) periphSafeBitSet(HSCMP_FLAG_ALL, HSCMP_SCR_IER, &((pHscmpBase)->scr)); \
  else periphSafeBitClear(HSCMP_FLAG_ALL, HSCMP_SCR_IER, &((pHscmpBase)->scr))

/* Enables/Disables falling edge interrupt */
#define ioctlHSCMP_INT_FALLING_EDGE(pHscmpBase, param) \
 if (param) periphSafeBitSet(HSCMP_FLAG_ALL, HSCMP_SCR_IEF, &((pHscmpBase)->scr)); \
  else periphSafeBitClear(HSCMP_FLAG_ALL, HSCMP_SCR_IEF, &((pHscmpBase)->scr))

/* HSCMP clears Interrupt flags  */
#define ioctlHSCMP_CLEAR_INT_FLAGS(pHscmpBase, param) \
  periphSafeAckByOne(HSCMP_FLAG_ALL, param, &((pHscmpBase)->scr))

/* HSCMP tests interrupt flag  */
#define ioctlHSCMP_TEST_INT_FLAGS(pHscmpBase, param) \
  periphBitTest(param & HSCMP_FLAG_ALL, &((pHscmpBase)->scr))

/* HSCMP tests interrupt flag  */
#define ioctlHSCMP_TEST_OUTPUT(pHscmpBase, param) \
  periphBitTest(HSCMP_SCR_COUNT, &((pHscmpBase)->scr))

/* FPR */
#define ioctlHSCMP_READ_FILT_REG(pHscmpBase, param) \
  periphMemRead(&((pHscmpBase)->fpr))
  
#define ioctlHSCMP_WRITE_FILT_REG(pHscmpBase, param) \
  periphMemWrite(param,  &((pHscmpBase)->fpr))

#if HSCMP_VERSION == 2
/* Sets power mode */
#define ioctlHSCMP_SET_INT_MODE_IN_STOP(pHscmpBase, param) \
  if (param) periphSafeBitSet(HSCMP_FLAG_ALL, HSCMP_SCR_SMELB, &((pHscmpBase)->scr)); \
  else periphSafeBitClear(HSCMP_FLAG_ALL, HSCMP_SCR_SMELB, &((pHscmpBase)->scr))

/* Sets analog comparator hysteresis */
#define ioctlHSCMP_SET_HYSTERESIS(pHscmpBase, param) \
  periphSafeBitGrpSet(HSCMP_FLAG_ALL, HSCMP_SCR_HYST_SEL_MASK, (param)<<6, &((pHscmpBase)->scr))

#endif

#ifdef __cplusplus
}
#endif

#endif                                      
