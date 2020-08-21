/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  adc.h
*
* $Date:      Dec-18-2014$
*
* $Version:   2.3.62.0$
*
* Description: Header file for the ADC low-level driver
*
* This file supports different hardware versions of the module. A version
* of module used in your project is defined in the "arch.h" processor 
* architecture definition file.
*
*  ADC_VERSION_1 .. 56F83xx devices, see MC56F8300UM.pdf
*  ADC_VERSION_2 .. 56F801x devices, see MC56F8000RM.pdf
*  ADC_VERSION_3 .. 56F802x/3x devices, see MC56F802x3xRM.pdf
*  ADC_VERSION_4 .. 56F800x devices, see MC56F8006UM.pdf
*  ADC_VERSION_5 .. 56F82xx devices, see MC56F82xxRM.pdf
*  ADC_VERSION_6 .. 56F84xxx devices, see MC56F84xxxRM.pdf
*  ADC_VERSION_7 .. 56F827xx devices, see MC56F827xxRM.pdf
*
*****************************************************************************/

#ifndef __ADC_H
#define __ADC_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before adc.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*
*                      General Interface Description
*
* The Analog-to-Digital Converter (ADC) consists of two separate and complete ADCs,
* each with their own sample and hold circuits. A common digital control module
* configures and controls the functioning of these ADCs. 
*
* The ADC device driver interface uses "ioctl" call to control specific ADC functions
* during operation. For details see "ioctl" call.
*
******************************************************************************/

/************************************************************
* ADC module identifiers
*************************************************************/

#ifdef ADCA_BASE
#define ADC_A  (&ArchIO.AdcA)
#endif

#ifdef ADCB_BASE
#define ADC_B  (&ArchIO.AdcB)
#endif

/* single ("anonymous") module on some devices */
#ifdef ADC_BASE
#define ADC    (&ArchIO.Adc)
#endif

#ifdef ADC1_BASE
#define ADC_1   (&ArchIO.Adc1)
#endif

/*************************************************************
* arch.h should define device-specific information about ADC
**************************************************************/

#if !defined(ADC_VERSION)
#error ADC not properly described in arch.h (old Quick_Start version?)
#endif

/**************************************************************
* Configuration items for appconfig.h (init values, ...),
**************************************************************/

/* Configuration items for appconfig.h  *

    ADC_A_ADCR1_INIT    // control reg 1 
    ADC_A_ADCR2_INIT    // control reg 2    
    ADC_A_ADZCC_INIT    // zero cross control reg
    ADC_A_ADLST1_INIT   // channel list reg 1
    ADC_A_ADLST2_INIT   // channel list reg 2
    ADC_A_ADSDIS_INIT   // disable reg
    ADC_A_ADCPOWER_INIT // power control reg

    ADC_A_ADLLMT0_INIT  // low limit regs
    ADC_A_ADLLMT1_INIT 
    ADC_A_ADLLMT2_INIT 
    ADC_A_ADLLMT3_INIT 
    ADC_A_ADLLMT4_INIT 
    ADC_A_ADLLMT5_INIT 
    ADC_A_ADLLMT6_INIT 
    ADC_A_ADLLMT7_INIT 
    ADC_A_ADLLMT8_INIT  // only for ADC_VERSION >= 6
    ADC_A_ADLLMT9_INIT 
    ADC_A_ADLLMT10_INIT 
    ADC_A_ADLLMT11_INIT 
    ADC_A_ADLLMT12_INIT 
    ADC_A_ADLLMT13_INIT 
    ADC_A_ADLLMT14_INIT 
    ADC_A_ADLLMT15_INIT 

    ADC_A_ADHLMT0_INIT  // high limit regs
    ADC_A_ADHLMT1_INIT  
    ADC_A_ADHLMT2_INIT  
    ADC_A_ADHLMT3_INIT  
    ADC_A_ADHLMT4_INIT  
    ADC_A_ADHLMT5_INIT  
    ADC_A_ADHLMT6_INIT  
    ADC_A_ADHLMT7_INIT  
    ADC_A_ADHLMT8_INIT // only for ADC_VERSION >= 6 
    ADC_A_ADHLMT9_INIT  
    ADC_A_ADHLMT10_INIT  
    ADC_A_ADHLMT11_INIT  
    ADC_A_ADHLMT12_INIT  
    ADC_A_ADHLMT13_INIT  
    ADC_A_ADHLMT14_INIT  
    ADC_A_ADHLMT15_INIT  

    ADC_A_ADOFS0_INIT   // offset regs
    ADC_A_ADOFS1_INIT   
    ADC_A_ADOFS2_INIT   
    ADC_A_ADOFS3_INIT   
    ADC_A_ADOFS4_INIT   
    ADC_A_ADOFS5_INIT   
    ADC_A_ADOFS6_INIT   
    ADC_A_ADOFS7_INIT   

    ADC_A_ADOFS8_INIT // only for ADC_VERSION >= 6
    ADC_A_ADOFS9_INIT   
    ADC_A_ADOFS10_INIT   
    ADC_A_ADOFS11_INIT   
    ADC_A_ADOFS12_INIT   
    ADC_A_ADOFS13_INIT   
    ADC_A_ADOFS14_INIT   
    ADC_A_ADOFS15_INIT 

// new in ADC_VERSION_5
	ADC_A_ADCGC1_INIT
	ADC_A_ADCGC2_INIT
	ADC_A_ADCSCTRL_INIT
	ADC_A_ADCPWR2_INIT

    // dtto for ADC_B


  #define INTERRUPT_VECTOR_ADDR_yy  // specify interrupt handler routine
  #define INT_PRIORITY_LEVEL_yy     // interrupt level : (INTC_DISABLED, INTC_LEVEL0, ... INTC_LEVEL2)

  where:
         yy  is interrupt vector number
            e.g. On 56F8346
                76 - ADC A Zero Crossing or Limit Error
                75 - ADC B Zero Crossing or Limit Error
                74 - ADC A Conversion Complete
                73 - ADC B Conversion Complete

                    on 56F8013 (ADC_VERSION_2)
                40 - ADC_A ADA Conversion Complete
                41 - ADC_A ADB Conversion Complete

*/

/*****************************************************************
* Single-Instruction ioctl() commands
*
*  Word16 ioctl( ADC, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
 
/* ADC control register 1 commands */  
#if ADC_VERSION >= 6
#define ADC_DMAEN                   /* ADC_CONVERTER_0/ADC_CONVERTER_1, Enable DMA. Modify the Control Register 1 or 2(ADCx_CTRL1->DMAEN0,ADCx_CTRL2->DMAEN1) */
#endif
#define ADC_START                   /* NULL/ADC_CONVERTER_0/ADC_CONVERTER_1, Start ADC1(2 conversion in software.(ADCx_CTRL1->START0,ADCx_CTRL2->START1)   */
#define ADC_STOP                    /* ADC_ON/ADC_OFF/ADC_ON_CONVERTER_0/ADC_ON_CONVERTER_1/ADC_OFF_CONVERTER_0/ADC_OFF_CONVERTER_1, Places ADC1(2) to normal operation (ADC_ON) or to stop mode (ADC_OFF).(ADCx_CTRL1->STOP0,ADCx_CTRL2->STOP1)  */
#define ADC_SYNC                    /* ADC_ON/ADC_OFF/ADC_ON_CONVERTER_0/ADC_ON_CONVERTER_1/ADC_OFF_CONVERTER_0/ADC_OFF_CONVERTER_1, Selects the ADC conversion START source - SYNC input (ADC_ON) or ADC_START command (ADC_OFF). (ADCx_CTRL1->SYNC0,ADCx_CTRL2->SYNC1)   */
#define ADC_INT_ENABLE              /* ADC_END_OF_SCAN|ADC_ZERO_CROSS|ADC_LOW_LIMIT|ADC_HIGH_LIMIT|ADC_END_OF_SCAN_CONVERTER_0|ADC_END_OF_SCAN_CONVERTER_1, Enable selected the ADC interrupts.(ADCx_CTRL1->EOSIE0,ZCIE,LLMTIE,HLMTIE) */
#define ADC_INT_DISABLE             /* ADC_END_OF_SCAN|ADC_ZERO_CROSS|ADC_LOW_LIMIT|ADC_HIGH_LIMIT|ADC_END_OF_SCAN_CONVERTER_0|ADC_END_OF_SCAN_CONVERTER_1, Disable selected the ADC interrupts.(ADCx_CTRL1->EOSIE0,ZCIE,LLMTIE,HLMTIE) */
#define ADC_TEST_INT_ENABLED        /* ADC_END_OF_SCAN/ADC_ZERO_CROSS/ADC_LOW_LIMIT/ADC_HIGH_LIMIT/ADC_END_OF_SCAN_CONVERTER_0/ADC_END_OF_SCAN_CONVERTER_1, Return non-zero if any of interrupts specified in parameter are enabled.(ADCx_CTRL1->EOSIE0,ZCIE,LLMTIE,HLMTIE) */
#define	ADC_END_OF_SCAN_INT			/* ADC_ENABLE_CONVERTER_0/ADC_DISABLE_CONVERTER_0/ADC_ENABLE_CONVERTER_1/ADC_DISABLE_CONVERTER_1,Enable/disable the ADC End of Scan interrupt this command has no effect in loop mode.(ADC_CTRL1->EOSIE0,ADC_CTRL2->EOSIE1) */
/* write the ADC zero cross register */
#define ADC_WRITE_ZERO_CROSS_CNTRL  /* ADC_Sx_ZC_DISABLE/ADC_Sx_ZC_POSITIVE_NEGATIVE/ADC_Sx_ZC_NEGATIVE_POSITIVE/ADC_Sx_ZC_ANY_CROSS, Configure zero crossing detection logic for each sample independently. Each sample can be set to 1 of 4 modes.(ADC_ZXCTRL1->_) */


/* read the ADC result register */
#define ADC_READ_SAMPLE             /* UWord16 sample number(0-15), Read one sample result at a time. The sample number is determined by param. (ADC_RSLTn->_); where n=0 to 15  */
#define ADC_READ_SAMPLE2 			/* UWord16 sample number(16-19), Read one sample result at a time. The sample number is determined by param. (ADC_RSLT2n->_); where n=0 to 3 */
#define ADC_READ_SAMPLE12 			/* UWord16 sample number(0-19), Read one sample result at a time. The sample number is determined by param. (ADC_RSLTn->_,ADC_RSLT2m->_); where n=0 to 15; m=0 to 3 */

/* read the ADC status register */
#define ADC_READ_STATUS             /* NULL, Read the ADC High Limit Register x value. The number of the sample which high limit value belongs to is determined by param. (ADC_STAT->_) */

/* write the ADC low limit registers */
#define ADC_WRITE_LOW_LIMIT0        /* UWord16, Write low limit(sample 0). It directly sets up the Low Limit Register(ADCx_LOLIM0->_) */
#define ADC_WRITE_LOW_LIMIT1        /* UWord16, Write low limit(sample 1). It directly sets up the Low Limit Register(ADCx_LOLIM1->_) */
#define ADC_WRITE_LOW_LIMIT2        /* UWord16, Write low limit(sample 2). It directly sets up the Low Limit Register(ADC_LOLIM2->_) */
#define ADC_WRITE_LOW_LIMIT3        /* UWord16, Write low limit(sample 3). It directly sets up the Low Limit Register(ADC_LOLIM3->_) */
#define ADC_WRITE_LOW_LIMIT4        /* UWord16, Write low limit(sample 4). It directly sets up the Low Limit Register(ADC_LOLIM4->_) */
#define ADC_WRITE_LOW_LIMIT5        /* UWord16, Write low limit(sample 5). It directly sets up the Low Limit Register(ADC_LOLIM5->_) */
#define ADC_WRITE_LOW_LIMIT6        /* UWord16, Write low limit(sample 6). It directly sets up the Low Limit Register(ADC_LOLIM6->_) */
#define ADC_WRITE_LOW_LIMIT7        /* UWord16, Write low limit(sample 7). It directly sets up the Low Limit Register(ADC_LOLIM7->_) */

/* read the ADC low limit register x */
#define ADC_READ_LOW_LIMIT          /* UWord16, Read the ADC Low Limit Register x value. The number of the sample which high limit value belongs to is determined by param.(ADC_LOLIMn->_) n= 0-15 */

/* write the ADC high limit registers */
#define ADC_WRITE_HIGH_LIMIT0       /* UWord16, Write high limit(sample 0). It directly sets up the High Limit Register(ADC_HILIM0->_) */
#define ADC_WRITE_HIGH_LIMIT1       /* UWord16, Write high limit(sample 1). It directly sets up the High Limit Register(ADC_HILIM1->_) */
#define ADC_WRITE_HIGH_LIMIT2       /* UWord16, Write high limit(sample 2). It directly sets up the High Limit Register(ADC_HILIM2->_) */
#define ADC_WRITE_HIGH_LIMIT3       /* UWord16, Write high limit(sample 3). It directly sets up the High Limit Register(ADC_HILIM3->_) */
#define ADC_WRITE_HIGH_LIMIT4       /* UWord16, Write high limit(sample 4). It directly sets up the High Limit Register(ADC_HILIM4->_) */
#define ADC_WRITE_HIGH_LIMIT5       /* UWord16, Write high limit(sample 5). It directly sets up the High Limit Register(ADC_HILIM5->_) */
#define ADC_WRITE_HIGH_LIMIT6       /* UWord16, Write high limit(sample 6). It directly sets up the High Limit Register(ADC_HILIM6->_) */
#define ADC_WRITE_HIGH_LIMIT7       /* UWord16, Write high limit(sample 7). It directly sets up the High Limit Register(ADC_HILIM7->_) */

/* read the ADC high limit register x */
#define ADC_READ_HIGH_LIMIT         /* UWord16, Read the ADC High Limit Register x value. The number of the sample which high limit value belongs to is determined by param.(ADC_HILIMn->_) n= 0-15 */

/* write the ADC offset registers */
  #define ADC_WRITE_OFFSET0           /* UWord16, Write offset(sample 0). It directly sets up the Offset Register(ADC_OFFST0->_) */
  #define ADC_WRITE_OFFSET1           /* UWord16, Write offset(sample 1). It directly sets up the Offset Register(ADC_OFFST1->_) */
  #define ADC_WRITE_OFFSET2           /* UWord16, Write offset(sample 2). It directly sets up the Offset Register(ADC_OFFST2->_) */
  #define ADC_WRITE_OFFSET3           /* UWord16, Write offset(sample 3). It directly sets up the Offset Register(ADC_OFFST3->_) */
  #define ADC_WRITE_OFFSET4           /* UWord16, Write offset(sample 4). It directly sets up the Offset Register(ADC_OFFST4->_) */
  #define ADC_WRITE_OFFSET5           /* UWord16, Write offset(sample 5). It directly sets up the Offset Register(ADC_OFFST5->_) */
  #define ADC_WRITE_OFFSET6           /* UWord16, Write offset(sample 6). It directly sets up the Offset Register(ADC_OFFST6->_) */
  #define ADC_WRITE_OFFSET7           /* UWord16, Write offset(sample 7). It directly sets up the Offset Register(ADC_OFFST7->_) */
                                                  
/* read the ADC offset register x */
#define ADC_READ_OFFSET             /* UWord16, Read the ADC Offset Register x value. The number of the sample which high limit value belongs to is determined by param.(ADC_OFFSTn->_) n= 0-15 */

/* read the ADC limit status register */
#if ADC_VERSION <= 5
#define ADC_READ_LIMIT_STATUS       /* NULL, Read the ADC Low Limit Status Register(ADCx_LIMSTAT->_)  */
#else /* ADC_VERSION >= 6 */                 
#define ADC_READ_LOW_LIMIT_STATUS   /* NULL, Read the ADC Low Limit Status Register(ADCx_LOLIMSTAT->_)  */
#define ADC_READ_HIGH_LIMIT_STATUS  /* NULL, Read the ADC High Limit Status Register(ADCx_HILIMSTAT->_) */
#endif /* ADC_VERSION >= 6 */

/* read the ADC zero crossing status register */
#define ADC_READ_ZERO_CROSS_STATUS  /* NULL, Read the ADC Zero Crossing Status Register(ADCx_ZXSTAT->_))  */

/* clear the ADC status registers flags */
#define ADC_CLEAR_STATUS_EOSI       /* UWord16, Clear sample number(0-15) EOSI  status. Modify the Status Register(ADCx_STAT->EOSI0)) */
#define ADC_CLEAR_STATUS_ZCI        /* UWord16, Clear sample number(0-15) ZCI   status. Modify the Status Register(ADCx_STAT->ZCI) */
#define ADC_CLEAR_STATUS_LLMTI      /* UWord16, Clear sample number(0-15) LLMTI status. Modify the Status Register(ADCx_STAT->LLMTI) */
#define ADC_CLEAR_STATUS_HLMTI      /* UWord16, Clear sample number(0-15) HLMTI status. Modify the Status Register(ADCx_STAT->HLMTI) */

/* clearing bits in Limit Status,Zero Crossing Status reg individaully */
#if ADC_VERSION <= 5
#define ADC_CLEAR_LIMIT_STATUS_BITS     /*UWord16;any combination of ADC_LLSx, Clear selected bits in the ADC limit status register(ADC_HLSx->_0)  */
#else /* ADC_VERSION >= 6 */
#define ADC_CLEAR_LOW_LIMIT_STATUS_BITS	 /* UWord16;any combination of ADC_LLSx(0x000f), Clear selected bits in the ADC Low Limit Status Register(ADC_LOLIMSTAT->LSS[0-15] ) */
#define ADC_CLEAR_HIGH_LIMIT_STATUS_BITS /* UWord16;any combination of ADC_HLSx(0x000f), Clear selected bits in the ADC High Limit Status Register(ADC_HILIMSTAT->HSS[0-15] )  */
#endif /* ADC_VERSION >= 6 */

/* Power Control Register */
#define ADC_POWER_DOWN             /* ADC_CONVERTER_0|ADC_CONVERTER_1, Force to power down individual the ADC converters and the voltage reference. Modify the Power Control Register(ADCx_PWR->_)  */
#define ADC_POWER_UP               /* ADC_CONVERTER_0|ADC_CONVERTER_1, Force to power down individual the ADC converters and the voltage reference. Modify the Power Control Register(ADCx_PWR->_) */
//#define ADC_POWER_SAVE_MODE      /* ADC_ON/ADC_OFF,Was replaced by ADC_AUTO_POWERDOWN_MODE*/
#define ADC_GET_POWER_STATUS       /* ADC_CONVERTER_0|ADC_CONVERTER_1, Get the ADC converters and the voltage reference status. It changes the Power Control Register(ADCx_PWR->PSTS1,ADCx_PWR->PSTS0) */
#define ADC_READ_POWER_CONTROL_REG /* NULL,Read the ADC Power Control Register(ADCx_PWR->_) */

/* calibration register ADC_CAL */
#if ADC_VERSION == 1
#define ADC_CALIB_ENABLE              /* ADC_CONVERTER_0|ADC_CONVERTER_1, Enable/enter the ADC calibration mode. Modify the ADC Calibration Register (ADC_CAL->_)  */
#define ADC_CALIB_DISABLE             /* ADC_CONVERTER_0|ADC_CONVERTER_1, Disable the ADC calibration mode. Modify the ADC Calibration Register (ADC_CAL->_) */
#define ADC_SET_CONVERTER0_CALIB_REF  /* ADC_VCAL_L/ADC_VCAL_H, Selects voltage reference to be used during ADC1 calibration. Modify the ADC Calibration Register (ADC_CAL->_)*/
#define ADC_SET_CONVERTER1_CALIB_REF  /* ADC_VCAL_L/ADC_VCAL_H, Selects voltage reference to be used during ADC1 calibration. Modify the ADC Calibration Register (ADC_CAL->_)*/
#endif  /* ADC_VERSION_1 */

/****************************************************************************
* ADC ADC_VERSION_2-only commands
*****************************************************************************/

#if ADC_VERSION >= 2
/* ADC control register 2 set */
#define ADC_SIMULT                      /* ADC_ON/ADC_OFF, Select simultaneous or independent parallel sca in the Control Register 2(ADCx_CTRL2->SIMULT) */
/* Power Control Register */
#define ADC_AUTO_POWERDOWN_MODE         /* ADC_ON/ADC_OFF, Switche on/off ADC Auto Power Down saving mode in the Power Control Register(ADCx_PWR->APD)*/
#define ADC_AUTO_STANDBY_MODE           /* ADC_ON/ADC_OFF, Enable/disable auto standby mode in the Power Control Register(ADCx_PWR->ASB)*/
#endif

#if ADC_VERSION == 2

/* calibration register ADC_CAL */
#define ADC_SET_VREFH_SOURCE            /* ADC_VREF_SRC_INTERNAL/ADC_VREF_SRC_EXTERNAL, Select the source of the VREFH reference inputs. Modify the ADC Calibration Register (ADC_CAL->_)*/
#define ADC_SET_VREFL_SOURCE            /* ADC_VREF_SRC_INTERNAL/ADC_VREF_SRC_EXTERNAL, Select the source of the VREFLO reference inputs. Modify the ADC Calibration Register (ADC_CAL->_) */

#elif ADC_VERSION >= 3

/* calibration register ADC_CAL */
#define ADC_SET_VREFH1_SOURCE           /* ADC_VREF_SRC_INTERNAL/ADC_VREF_SRC_EXTERNAL, Select the source of the VREFH1 reference inputs for individual sub-converters. (ADC_CAL->SEL_VREFH_B[15]) */
#define ADC_SET_VREFL1_SOURCE           /* ADC_VREF_SRC_INTERNAL/ADC_VREF_SRC_EXTERNAL, Select the source of the VREFL1 reference inputs for individual sub-converters. (ADC_CAL->SEL_VREFL_B[14]) */
#define ADC_SET_VREFH0_SOURCE           /* ADC_VREF_SRC_INTERNAL/ADC_VREF_SRC_EXTERNAL, Select the source of the VREFH0 reference inputs for individual sub-converters. (ADC_CAL->SEL_VREFH_A[13]) */
#define ADC_SET_VREFL0_SOURCE           /* ADC_VREF_SRC_INTERNAL/ADC_VREF_SRC_EXTERNAL, Select the source of the VREFL0 reference inputs for individual sub-converters. (ADC_CAL->SEL_VREFL_A[12]) */

#endif  /* ADC_VERSION >= 3 */

/****************************************************************************
* ADC ADC_VERSION_5-only commands
*****************************************************************************/

#if ADC_VERSION >= 5
#define ADC_READ_GAIN_CONTROL_1_REG     /* NULL, Read raw data of channel gain configuration from Gain Control Register 1 register. (ADC_GC1->_) */
#define ADC_WRITE_GAIN_CONTROL_1_REG    /* UWord16, Write raw data of channel gain configuration from Gain Control Register 1 register. (ADC_GC1->_) */
#define ADC_READ_GAIN_CONTROL_2_REG     /* NULL, Read raw data of channel gain configuration from Gain Control Register 2 register. (ADC_GC2->_) */
#define ADC_WRITE_GAIN_CONTROL_2_REG    /* UWord16, Write raw data of channel gain configuration from Gain Control Register 2 register. (ADC_GC2->_) */

#if ADC_VERSION >= 7
#define ADC_READ_GAIN_CONTROL_3_REG     /* NULL, Read raw data of channel gain configuration from Gain Control Register 3 register.(ADC_GC3->_) */
#define ADC_WRITE_GAIN_CONTROL_3_REG    /* UWord16, Write raw data of channel gain configuration from Gain Control Register 3 register.(ADC_GC3->_) */
#endif

/* Scan Control register SCTRL commands */
#define ADC_SET_SAMPLE_BY_SYNC          /* ADC_SAMPLEx(1|2|4|5|6|7|8|9|10|11|12|13|14|15), set to delay sample until a new sync signal occure.(SCTRL->SC) */
#define ADC_SET_SAMPLE_IMMEDIATELY      /* ADC_SAMPLEx(1|2|4|5|6|7|8|9|10|11|12|13|14|15), set to immediately sample after completion of the current sample. (SCTRL->SC) */
#define ADC_READ_SCAN_CONTROL_REG       /* NULL, Read raw data of scan configuration from Scan Control Register. (SCTRL->_) */
#define ADC_WRITE_SCAN_CONTROL_REG      /* UWord16, Write raw data of scan configuration from Scan Control Register. (SCTRL->_) */

#if ADC_VERSION >= 7
#define ADC_SET_SAMPLE_BY_SYNC2          /* ADC_SAMPLEx(1|2|4|5|6|7|8|9|10|11|12|13|14|15), set to delay sample until a new sync signal occure. (SCTRL->SC) */
#define ADC_SET_SAMPLE_IMMEDIATELY2      /* ADC_SAMPLEx(1|2|4|5|6|7|8|9|10|11|12|13|14|15), set to immediately sample until a new sync signal occure. (SCTRL->SC) */
#define ADC_READ_SCAN_CONTROL_REG2       /* NULL, Read raw data of scan configuration from Scan Control Register. (SCTRL->_) */
#define ADC_WRITE_SCAN_CONTROL_REG2      /* UWord16, Write raw data of scan configuration from Scan Control Register. (SCTRL->_) */
#define ADC_SET_SAMPLE_BY_SYNC12         /* ADC_SAMPLEx(1|2|4|5|6|7|8|9|10|11|12|13|14|15), set to delay sample until a new sync signal occure (SCTRL->SC) universal commands for old and new register */
#define ADC_SET_SAMPLE_IMMEDIATELY12     /* ADC_SAMPLEx(1|2|4|5|6|7|8|9|10|11|12|13|14|15), set to immediately sample after completion of the current sample (SCTRL->SC) universal commands for old and new register */
#endif

/* Power Control Registr 2 commands */
#define ADC_READ_POWER_CONTROL_2_REG    /* NULL, Read raw data of power configuration from Power Control Register 2. (PWR2->_) */
#define ADC_WRITE_POWER_CONTROL_2_REG   /* UWord16, Write raw data of power configuration from Power Control Register 2. (PWR2->_) */

#endif  /* ADC_VERSION >= 5 */

/****************************************************************************
* ADC ADC_VERSION_6-only commands
*****************************************************************************/

#if ADC_VERSION >= 6
/* write the ADC zero cross register x <= 7 */
#define ADC_WRITE_ZERO_CROSS_CNTRL1 /* ADC_Sx_ZC1_DISABLE/ADC_Sx_ZC1_POSITIVE_NEGATIVE/ADC_Sx_ZC1_NEGATIVE_POSITIVE/ADC_Sx_ZC1_ANY_CROSS, Configures zero crossing detection logic for each sample independently. Each sample can be set to 1 of 4 modes. Modify the Status Register 1(ADC_ZXCTRL1->_) */
/* write the ADC zero cross register x >= 8 */
#define ADC_WRITE_ZERO_CROSS_CNTRL2 /* ADC_Sx_ZC2_DISABLE/ADC_Sx_ZC2_POSITIVE_NEGATIVE/ADC_Sx_ZC2_NEGATIVE_POSITIVE/ADC_Sx_ZC2_ANY_CROSS, Configures zero crossing detection logic for each sample independently. Each sample can be set to 1 of 4 modes. Modify the Status Register 2(ADC_ZXCTRL1->_) */ 
/* set DMA trigger in the ADC Control Register 3 ADC_CTRL3 */
#define ADC_SET_DMA_TRIGGER        /* ADC_DMA_TRIGGER_END_SCAN/ADC_DMA_TRIGGER_RDY, select between EOSI0 and RDY bits as the DMA source in the Control Register 3(ADCx_CTRL3->DMASRC) */
#if ADC_VERSION == 6
/* Set Sample Window Count 1 in ADC Control Register 3 ADC_CTRL3  */
#define ADC_SET_SAMPLE_WINDOW_COUNT1  /* ADC_CLOCK_x(2/3/4/5/6/7/8/9), Set Sample Window Count 0 (ADCx_CTRL3->SCNT0[2-0]) */
/* Set Sample Window Count 2 in ADC Control Register 3 ADC_CTRL3    */
#define ADC_SET_SAMPLE_WINDOW_COUNT2  /* ADC_CLOCK_x(2/3/4/5/6/7/8/9), Set Sample Window Count 1 (ADCx_CTRL3->SCNT1[5-3]) */
#endif


#if ADC_VERSION >= 7
/* Set Unipolar Differential Enable High bits in the ADC Control Register 3 ADC_CTRL3 	*/
#define ADC_SET_UNIPOLAR_CHANNEL 	/* ADC_ANA0_ANA1_UNIPOLAR_DIFF|ADC_ANA0_ANA1_FULLY_DIFF| ADC_ANA2_ANA3_UNIPOLAR_DIFF|ADC_ANA0_ANA1_FULLY_DIFF|ADC_ANA4_ANA5_UNIPOLAR_DIFF|ADC_ANA4_ANA5_FULLY_DIFF|ADC_ANA6_ANA7_UNIPOLAR_DIFF|ADC_ANB6_ANB7_FULLY_DIFF, Enable the Unipolar differential or Fully differential mode according to parameter. Modify the Control Register 3(ADC_CTRL3->UPDEN_L,ADC_CTRL3->UPDEN_H) */ 
/* Disable Sample Bits */
#define ADC_WRITE_SAMPLE_DISABLE2   /* UWord16 or any combination of ADC_SAMPLEx(x:15-19) or ADC_ENABLE_ALL, Set the number(x) of samples in scan sequence. Modify the Sample Disable Register 2(ADC_SDIS2->_) */
#define ADC_GET_STATUS_RDY2         /* UWord16, Read the Status Register 2 RDYx bit (Ready Sample 16-19 flag).(ADC_RDY2->_) */
#define ADC_READ_LOW_LIMIT_STATUS2  /* NULL, read whole ADC low limit status register 2(ADC_LOLIMSTAT2->_)) - contains all sample limit flag bits */
#define ADC_READ_HIGH_LIMIT_STATUS2 /* NULL, read whole ADC high limit status register 2(ADC_HILIMSTAT2->_)) - contains all sample limit flag bits */
#define ADC_READ_ZERO_CROSS_STATUS2 /* NULL, read whole ADC zero cross status register 2(ADC_ZXSTAT2->_)) - contains all sample limit flag bits */
#define ADC_GET_LIMIT_STATUS2_LLS   /* UWord16, sample number(16-19), Test bit of the ADC limit status register 2(ADC_LOLIMSTAT2->LSS[0-3] )  */
#define ADC_GET_LIMIT_STATUS2_HLS   /* UWord16, sample number(16-19), Test bit of the ADC limit status register 2(ADC_HILIMSTAT2->HSS[0-3] )  */
#define ADC_GET_ZERO_CROSS_STATUS2_ZCS  /* UWord16, sample number(16-19),test zero crossing status register 2(ADC_ZXSTAT2->ZCS[0-3])  */
#define ADC_CLEAR_STATUS2_LLMTI     /* UWord16, sample number(16-19),clear bit of the ADC limit status register 2(ADC_LOLIMSTAT2->LSS[0-3] )   */
#define ADC_CLEAR_STATUS2_HLMTI     /* UWord16, sample number(16-19),clear bit of the ADC limit status register 2(ADC_HILIMSTAT2->HSS[0-3] )   */
#define ADC_CLEAR_STATUS2_ZCI       /* UWord16, sample number(16-19),clear bit of Zero Crossing Status Register 2(ADC_ZXSTAT2->ZCS[0-3] )  */
#define ADC_CLEAR_LIMIT_STATUS2_LLS /* UWord16, clear all bits of the ADC low limit status register 2(ADC_LOLIMSTAT2->LSS[0-3] ) */
#define ADC_CLEAR_LIMIT_STATUS2_HLS /* UWord16, clear all bits of the ADC high limit status register 2(ADC_HILIMSTAT2->HSS[0-3] ) */
#define ADC_CLEAR_ZERO_CROSS_STATUS2_ZCS  /* UWord16, clear all bits of the ADC zero crossing status register 2(ADC_ZXSTAT2->ZCS[0-3] ) */
#define ADC_CLEAR_LOW_LIMIT_STATUS2_BITS  /* UWord16, any combination of ADC_LLSx(0x000f) clear bit of the ADC limit status register 2(ADC_LOLIMSTAT2->LSS[0-3] ) */
#define ADC_CLEAR_HIGH_LIMIT_STATUS2_BITS /* UWord16, any combination of ADC_HLSx(0x000f) clear bit of the ADC limit status register 2(ADC_HILIMSTAT2->HSS[0-3] )  */
/* universal commands for old and new register */
#define ADC_WRITE_SAMPLE_DISABLE12	/* UWord16 or any combination of ADC_SAMPLEx(x:0-19) or ADC_ENABLE_ALL, Set the number(x) of samples in scan sequence. Modify the Sample Disable Register 1 and 2(ADC_SDIS->_,ADC_SDIS2->_)*/
#define ADC_GET_STATUS_RDY12        /* UWord16, Read the Status Register 1 and 2 RDYx bit (Ready Sample 0-19 flag).(ADC_RDY->_,ADC_RDY2->_) */
#define ADC_READ_LOW_LIMIT_STATUS12   /* NULL, read whole the ADC low limit status register 1,2(ADC_LOLIMSTAT,ADC_LOLIMSTAT2);return UWord32 - universal command for read the ADC low limit status register 1,2(ADC_SDIS->_,ADC_SDIS2->_)*/
#define ADC_READ_HIGH_LIMIT_STATUS12  /* NULL, read whole the ADC high limit status register 1,2(ADC_HILIMSTAT,ADC_HILIMSTAT2);return UWord32 - universal command for read the ADC high limit status register 1,2(ADC_SDIS->_,ADC_SDIS2->_)*/
#define ADC_READ_ZERO_CROSS_STATUS12  /* NULL, read whole the ADC zero crossing status register 1,2(ADC_ZXSTAT,ADC_ZXSTAT2);return UWord32 - universal command for read the ADC zero crossing status register 1,2(ADC_SDIS->_,ADC_SDIS2->_)*/
#define ADC_GET_LIMIT_STATUS12_LLS    /* UWord16, sample number(0-19),test bit of the ADC limit status register 1,2(ADC_LOLIMSTAT->LSS[0-15],ADC_LOLIMSTAT2->LSS[0-3] )   */
#define ADC_GET_LIMIT_STATUS12_HLS    /* UWord16, sample number(0-19),test bit of the ADC limit status register 1,2(ADC_LOLIMSTAT->HSS[0-15],ADC_HILIMSTAT2->HSS[0-3] )   */
#define ADC_GET_ZERO_CROSS_STATUS12_ZCS /* UWord16, sample number(0-19),test zero crossing status register 1,2(ADC_ZXSTAT->ZCS[[0-15],ADC_ZXSTAT2->ZCS[[0-3] )   */
#define ADC_CLEAR_STATUS12_LLMTI      /* UWord16, sample number(0-19),clear bit of the ADC limit status register 1,2(ADC_LOLIMSTAT->LSS[0-15],ADC_LOLIMSTAT2->LSS[0-3] )   */
#define ADC_CLEAR_STATUS12_HLMTI      /* UWord16, sample number(0-19),clear bit of the ADC limit status register 1,2(ADC_LOLIMSTAT->HSS[0-15],ADC_HILIMSTAT2->HSS[0-3] )   */
#define ADC_CLEAR_STATUS12_ZCI        /* UWord16, sample number(0-19),clear bit of Zero Crossing Status Register 1,2((ADC_ZXSTAT->ZCS[[0-15],ADC_ZXSTAT2->ZCS[0-3] ) */
#define ADC_CLEAR_LIMIT_STATUS12_LLS  /* UWord16, clear all bits of the ADC low limit status register 1 and 2(ADC_LOLIMSTAT->LSS[0-15],ADC_LOLIMSTAT2->LSS[0-3] ) */
#define ADC_CLEAR_LIMIT_STATUS12_HLS  /* UWord16, clear all bits of the ADC high limit status register 1 and 2(ADC_LOLIMSTAT->HSS[0-15],ADC_HILIMSTAT2->HSS[0-3] ) */
#define ADC_CLEAR_ZERO_CROSS_STATUS12_ZCS   /* UWord16, clear all bits of the ADC zero crossing status register 2(ADC_ZXSTAT->ZCS[[0-15],ADC_ZXSTAT2->ZCS[0-3] ) */
#define ADC_CLEAR_LOW_LIMIT_STATUS12_BITS   /* UWord32, any combination of ADC_LLSx(0xffffffff),clear bit of the ADC limit status register 1,2(ADC_LOLIMSTAT->LSS[0-15],ADC_LOLIMSTAT2->LSS[0-3] )  */
#define ADC_CLEAR_HIGH_LIMIT_STATUS12_BITS  /* UWord32, any combination of ADC_HLSx(0xffffffff),clear bit of the ADC limit status register 1,2(ADC_LOLIMSTAT->HSS[0-15],ADC_HILIMSTAT2->HSS[0-3] )  */   	
#endif

/* ADC_SCHLTEN */
#define ADC_SET_SCAN_HALTED_INTERRUPT_DISABLE /* UWord16, clear bits in Scan Halted Interrupt Enable Register(ADC_SCHLTEN->SCHLTEN[0-15]). Modify one of ADC_ANAx/ADC_ANBx(0-15) */
#define ADC_SET_SCAN_HALTED_INTERRUPT_ENABLE   /* UWord16, set bits in Scan Halted Interrupt Enable Register(ADC_SCHLTEN->SCHLTEN[0-15]);one of ADC_ANAx/ADC_ANBx(0-15) */
#define ADC_READ_SCAN_HALTED_INTERRUPT_REG     /* UWord16, read whole Scan Halted Interrupt Enable Register(ADC_SCHLTEN->SCHLTEN[0-15]) */
#define ADC_WRITE_SCAN_HALTED_INTERRUPT_REG    /* UWord16, write whole Scan Halted Interrupt Enable Register(ADC_SCHLTEN->SCHLTEN[0-15]) */

/* write the ADC low limit registers */
#define ADC_WRITE_LOW_LIMIT8        /* UWord16, write low limit(sample 8 ) Low Limit Register(ADC_LOLIM8->_) */
#define ADC_WRITE_LOW_LIMIT9        /* UWord16, write low limit(sample 9 ) Low Limit Register(ADC_LOLIM9->_) */
#define ADC_WRITE_LOW_LIMIT10       /* UWord16, write low limit(sample 10) Low Limit Register(ADC_LOLIM10->_) */
#define ADC_WRITE_LOW_LIMIT11       /* UWord16, write low limit(sample 11) Low Limit Register(ADC_LOLIM11->_) */
#define ADC_WRITE_LOW_LIMIT12       /* UWord16, write low limit(sample 12) Low Limit Register(ADC_LOLIM12->_) */
#define ADC_WRITE_LOW_LIMIT13       /* UWord16, write low limit(sample 13) Low Limit Register(ADC_LOLIM13->_) */
#define ADC_WRITE_LOW_LIMIT14       /* UWord16, write low limit(sample 14) Low Limit Register(ADC_LOLIM14->_) */
#define ADC_WRITE_LOW_LIMIT15       /* UWord16, write low limit(sample 15) Low Limit Register(ADC_LOLIM15->_) */
#if ADC_VERSION >= 7                            
#define ADC_WRITE_LOW_LIMIT16       /* UWord16, write low limit(sample 16) Low Limit Register(ADC_LOLIM16->_) */
#define ADC_WRITE_LOW_LIMIT17       /* UWord16, write low limit(sample 17) Low Limit Register(ADC_LOLIM17->_) */
#define ADC_WRITE_LOW_LIMIT18       /* UWord16, write low limit(sample 18) Low Limit Register(ADC_LOLIM18->_) */
#define ADC_WRITE_LOW_LIMIT19       /* UWord16, write low limit(sample 19) Low Limit Register(ADC_LOLIM19->_) */
#define ADC_READ_LOW_LIMIT2		 	/* UWord16, read low Limit Registers(ADC_LOLIMn->_) n= 16-19 */
#define ADC_READ_LOW_LIMIT12		/* UWord16, read low Limit Registers(ADC_LOLIMn->_) n= 0-19 */
#endif /* ADC_VERSION >= 6 */
/* read the ADC low limit register x */

/* write the ADC high limit registers */
#define ADC_WRITE_HIGH_LIMIT8       /* UWord16, write high limit(sample 8 ) High Limit Register(ADC_HILIM8->_) */
#define ADC_WRITE_HIGH_LIMIT9       /* UWord16, write high limit(sample 9 ) High Limit Register(ADC_HILIM9->_) */
#define ADC_WRITE_HIGH_LIMIT10      /* UWord16, write high limit(sample 10) High Limit Register(ADC_HILIM10->_) */
#define ADC_WRITE_HIGH_LIMIT11      /* UWord16, write high limit(sample 11) High Limit Register(ADC_HILIM11->_) */
#define ADC_WRITE_HIGH_LIMIT12      /* UWord16, write high limit(sample 12) High Limit Register(ADC_HILIM12->_) */
#define ADC_WRITE_HIGH_LIMIT13      /* UWord16, write high limit(sample 13) High Limit Register(ADC_HILIM13->_) */
#define ADC_WRITE_HIGH_LIMIT14      /* UWord16, write high limit(sample 14) High Limit Register(ADC_HILIM14->_) */
#define ADC_WRITE_HIGH_LIMIT15      /* UWord16, write high limit(sample 15) High Limit Register(ADC_HILIM15->_) */
#if ADC_VERSION >= 7
#define ADC_WRITE_HIGH_LIMIT16       /* UWord16, write high limit(sample 16) High Limit Register(ADC_HILIM16->_) */
#define ADC_WRITE_HIGH_LIMIT17       /* UWord16, write high limit(sample 17) High Limit Register(ADC_HILIM17->_) */
#define ADC_WRITE_HIGH_LIMIT18       /* UWord16, write high limit(sample 18) High Limit Register(ADC_HILIM18->_) */
#define ADC_WRITE_HIGH_LIMIT19       /* UWord16, write high limit(sample 19) High Limit Register(ADC_HILIM19->_) */
#define ADC_READ_HIGH_LIMIT2		 /* UWord16, read Low Limit Registers(ADC_HILIMn->_) n= 16-19 */
#define ADC_READ_HIGH_LIMIT12		 /* UWord16, read Low Limit Registers(ADC_HILIMn->_) n= 0-19 */
#endif
/* read the ADC high limit register x */

/* write the ADC offset registers */
#define ADC_WRITE_OFFSET8           /* UWord16, write offset(sample 8 ) Offset Register(ADC_OFFST8->_) */
#define ADC_WRITE_OFFSET9           /* UWord16, write offset(sample 9 ) Offset Register(ADC_OFFST9->_) */
#define ADC_WRITE_OFFSET10          /* UWord16, write offset(sample 10) Offset Register(ADC_OFFST10->_) */
#define ADC_WRITE_OFFSET11          /* UWord16, write offset(sample 11) Offset Register(ADC_OFFST11->_) */
#define ADC_WRITE_OFFSET12          /* UWord16, write offset(sample 12) Offset Register(ADC_OFFST12->_) */
#define ADC_WRITE_OFFSET13          /* UWord16, write offset(sample 13) Offset Register(ADC_OFFST13->_) */
#define ADC_WRITE_OFFSET14          /* UWord16, write offset(sample 14) Offset Register(ADC_OFFST14->_) */
#define ADC_WRITE_OFFSET15          /* UWord16, write offset(sample 15) Offset Register(ADC_OFFST15->_) */
#if ADC_VERSION >= 7
#define ADC_WRITE_OFFSET16       /* UWord16, write offset(sample 16) Offset Register(ADC_OFFST16->_) */
#define ADC_WRITE_OFFSET17       /* UWord16, write offset(sample 17) Offset Register(ADC_OFFST17->_) */
#define ADC_WRITE_OFFSET18       /* UWord16, write offset(sample 18) Offset Register(ADC_OFFST18->_) */
#define ADC_WRITE_OFFSET19       /* UWord16, write offset(sample 19) Offset Register(ADC_OFFST19->_) */
#define ADC_READ_OFFSET2		 /* UWord16, read Offset Registers(ADC_OFFSTn->_) n= 16-19 */
#define ADC_READ_OFFSET12		 /* UWord16, read Offset Registers(ADC_OFFSTn->_) n= 0-19 */
#endif
#endif  /* ADC_VERSION >= 6 */


/****************************************************************************
* ADC ADC_VERSION_7-only commands
*****************************************************************************/

#if ADC_VERSION >= 7
/* ADC_SCHLTEN2 */
#define ADC_SET_SCAN_HALTED_INTERRUPT_DISABLE2 /* UWord16, clear bits in Scan Halted Interrupt Enable Register(ADC_SCHLTEN2->SCHLTEN[0-3]). Modify one of ADC_ANAx/ADC_ANBx(16-19) */
#define ADC_SET_SCAN_HALTED_INTERRUPT_ENABLE2   /* UWord16, set bits in Scan Halted Interrupt Enable Register(ADC_SCHLTEN2->SCHLTEN[0-3]). Modify one of ADC_ANAx/ADC_ANBx(16-19) */
#define ADC_READ_SCAN_HALTED_INTERRUPT_REG2     /* UWord16, read whole Scan Halted Interrupt Enable Register(ADC_SCHLTEN->SCHLTEN[0-3]) */
#define ADC_WRITE_SCAN_HALTED_INTERRUPT_REG2    /* UWord16, write bits in Scan Halted Interrupt Enable Register(ADC_SCHLTEN2->SCHLTEN[0-3]). Modify one of ADC_ANAx/ADC_ANBx(16-19) */
#define ADC_SET_SCAN_HALTED_INTERRUPT_DISABLE12/* UWord16, clear bits in Scan Halted Interrupt Enable Register 1,2(ADC_SCHLTEN->SCHLTEN[0-15],ADC_SCHLTEN2->SCHLTEN[0-3]). Modify one of ADC_ANAx/ADC_ANBx(0-19) */
#define ADC_SET_SCAN_HALTED_INTERRUPT_ENABLE12  /* UWord16, set bits in Scan Halted Interrupt Enable Register 1,2(ADC_SCHLTEN->SCHLTEN[0-15],ADC_SCHLTEN2->SCHLTEN[0-3]). Modify one of ADC_ANAx/ADC_ANBx(0-19) */
#endif

/*****************************************************************
* Multi-Instruction ioctl() commands
*
*  Word16 ioctl( ADC,Command_name,Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS,COMMENTS
----------------------------------------------------------------*/

/* ADC control register 1 commands */
#define ADC_SET_CHANNEL_CONFIG      /* ADC_ANA0_ANA1_DIFF|ADC_ANA0_ANA1_SE|ADC_ANA2_ANA3_DIFF|ADC_ANA2_ANA3_SE| ADC_ANA4_ANA5_DIFF|ADC_ANA4_ANA5_SE|ADC_ANA6_ANA7_DIFF|ADC_ANA6_ANA7_SE, configure the analog inputs for either single ended or differential conversions. Modify the  Control Register 1(ADC_CTRL1->CHNCFG_L,ADC_CTRL2->CHNCFG_H) */
#define ADC_SET_SCAN_MODE           /* ADC_SCAN_ONCE_SEQUENTIAL|ADC_SCAN_ONCE_SIMULTANEOUS|ADC_SCAN_LOOP_SEQUENTIAL|ADC_SCAN_LOOP_SIMULTANEOUS|ADC_SCAN_TRIG_SEQUENTIAL|ADC_SCAN_TRIG_SIMULTANEOUS, set  Scan Mode Control. Modify the  Control Register 1(ADC_CTRL1->SMODE) */

/* ADC control register 2 set */
#define ADC_SET_DIVISOR             /* UWord16 one of ADC_DIVxx or 5-bit UWord16 value,Clock Divisor Select. Modify the  Control Register 2(ADC_CTRL2->DIV0) */

/* write the ADC sample disable register */
#define ADC_WRITE_SAMPLE_DISABLE    /* UWord16 or any combination of ADC_SAMPLEx(x:0-15) or ADC_ENABLE_ALL, Set the number(s) of samples in scan sequence. Modify the Sample Disable Register(ADC_SDIS->_) */

/* write the ADC zero cross register */
#define ADC_ZERO_CROSS_CH0          /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 1 Register(ADC_ZXCTRL1->ZCE0)*/
#define ADC_ZERO_CROSS_CH1          /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 1 Register(ADC_ZXCTRL1->ZCE1)*/
#define ADC_ZERO_CROSS_CH2          /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 1 Register(ADC_ZXCTRL1->ZCE2)*/
#define ADC_ZERO_CROSS_CH3          /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 1 Register(ADC_ZXCTRL1->ZCE3)*/
#define ADC_ZERO_CROSS_CH4          /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 1 Register(ADC_ZXCTRL1->ZCE4)*/
#define ADC_ZERO_CROSS_CH5          /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 1 Register(ADC_ZXCTRL1->ZCE5)*/
#define ADC_ZERO_CROSS_CH6          /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 1 Register(ADC_ZXCTRL1->ZCE6)*/
#define ADC_ZERO_CROSS_CH7          /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 1 Register(ADC_ZXCTRL1->ZCE7)*/

#if ADC_VERSION >= 6
#define ADC_ZERO_CROSS_CH8          /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 2 Register(ADC_ZXCTRL2->ZCE8)*/
#define ADC_ZERO_CROSS_CH9          /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 2 Register(ADC_ZXCTRL2->ZCE9)*/
#define ADC_ZERO_CROSS_CH10         /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 2 Register(ADC_ZXCTRL2->ZCE10)*/
#define ADC_ZERO_CROSS_CH11         /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 2 Register(ADC_ZXCTRL2->ZCE11)*/
#define ADC_ZERO_CROSS_CH12         /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 2 Register(ADC_ZXCTRL2->ZCE12)*/
#define ADC_ZERO_CROSS_CH13         /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 2 Register(ADC_ZXCTRL2->ZCE13)*/
#define ADC_ZERO_CROSS_CH14         /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 2 Register(ADC_ZXCTRL2->ZCE14)*/
#define ADC_ZERO_CROSS_CH15         /* ADC_ZC_DISABLE/ADC_ZC_POS2NEG/ADC_ZC_NEG2POS/ADC_ZC_BOTH, Configure zero crossing detection logic for sample 0-15 in the Zero Crossing Control 2 Register(ADC_ZXCTRL2->ZCE15)*/
#endif  /* ADC_VERSION >= 6 */

/* write the ADC channel list registers */
#define ADC_WRITE_CHANNEL_LIST1 	/*ADC_ANAx_Sy(x:0-7;y:0-3)|ADC_ANBx_Sy(x:0-7;y:0-3), Configures mapping of the physical inputs ANA0-ANA7 or ANA0-ANA7 to first foursome samples in the ADC Channel List Register 1. (ADC_CLIST1->_) */
#define ADC_WRITE_CHANNEL_LIST2 	/*ADC_ANAx_Sy(x:0-7;y:4-7)|ADC_ANBx_Sy(x:0-7;y:4-7), Configures mapping of the physical inputs ANA0-ANA7 or ANA0-ANA7 to second foursome samples in the ADC Channel List Register 2. (ADC_CLIST2->_) */
#if ADC_VERSION >= 7
#define ADC_WRITE_CHANNEL_LIST3 	/*ADC_ANAx_Sy(x:0-7;y:8-11)|ADC_ANBx_Sy(x:0-7;y:8-11), Configures mapping of the physical inputs ANA0-ANA7 or ANA0-ANA7 to third foursome samples in the ADC Channel List Register 3. (ADC_CLIST3->_) */
#define ADC_WRITE_CHANNEL_LIST4 	/*ADC_ANAx_Sy(x:0-7;y:12-15)|ADC_ANBx_Sy(x:0-7;y:12-15), Configures mapping of the physical inputs ANA0-ANA7 or ANA0-ANA7 to last foursome samples in the ADC Channel List Register 4. (ADC_CLIST4->_) */
#endif

#define ADC_SET_LIST_SAMPLE0        /* one of ADC_ANAx/ADC_ANBx, Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 1(ADC_CLIST1->SAMPLE0) */
#define ADC_SET_LIST_SAMPLE1        /* one of ADC_ANAx/ADC_ANBx, Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 1(ADC_CLIST1->SAMPLE1) */
#define ADC_SET_LIST_SAMPLE2        /* one of ADC_ANAx/ADC_ANBx, Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 1(ADC_CLIST1->SAMPLE2) */
#define ADC_SET_LIST_SAMPLE3        /* one of ADC_ANAx/ADC_ANBx, Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 1(ADC_CLIST1->SAMPLE3) */
#define ADC_SET_LIST_SAMPLE4        /* one of ADC_ANAx/ADC_ANBx, Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 2(ADC_CLIST1->SAMPLE4) */
#define ADC_SET_LIST_SAMPLE5        /* one of ADC_ANAx/ADC_ANBx, Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 2(ADC_CLIST1->SAMPLE5) */
#define ADC_SET_LIST_SAMPLE6        /* one of ADC_ANAx/ADC_ANBx, Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 2(ADC_CLIST1->SAMPLE6) */
#define ADC_SET_LIST_SAMPLE7        /* one of ADC_ANAx/ADC_ANBx, Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 2(ADC_CLIST1->SAMPLE7) */

#if ADC_VERSION >= 3
#define ADC_SET_LIST_SAMPLE8        /* one of ADC_ANAx/ADC_ANBx,Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 3(ADC_CLIST1->SAMPLE8) */
#define ADC_SET_LIST_SAMPLE9        /* one of ADC_ANAx/ADC_ANBx,Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 3(ADC_CLIST1->SAMPLE9) */
#define ADC_SET_LIST_SAMPLE10       /* one of ADC_ANAx/ADC_ANBx,Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 3(ADC_CLIST1->SAMPLE10) */
#define ADC_SET_LIST_SAMPLE11       /* one of ADC_ANAx/ADC_ANBx,Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 3(ADC_CLIST1->SAMPLE11) */
#define ADC_SET_LIST_SAMPLE12       /* one of ADC_ANAx/ADC_ANBx,Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 4(ADC_CLIST1->SAMPLE12) */
#define ADC_SET_LIST_SAMPLE13       /* one of ADC_ANAx/ADC_ANBx,Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 4(ADC_CLIST1->SAMPLE13) */
#define ADC_SET_LIST_SAMPLE14       /* one of ADC_ANAx/ADC_ANBx,Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 4(ADC_CLIST1->SAMPLE14) */
#define ADC_SET_LIST_SAMPLE15       /* one of ADC_ANAx/ADC_ANBx,Set mapping of the physical ADC input to the sample number 0-15 in Channel List Register 4(ADC_CLIST1->SAMPLE15) */
#endif

/* read eight the ADC result registers */
#define ADC_READ_ALL_SAMPLES        /* adc_tBuff(Pointer to results buffer), Read first 16 sample results at a time. Sample results are copied to user allocated 16 word buffer.(ADC_RSLTn->_) n=0-15 */
#if ADC_VERSION >= 7
#define ADC_READ_ALL_SAMPLES2       /* adc_tBuff(Pointer to results buffer), Read samples results 16-19 at a time. Sample results are copied to user allocated 4 word buffer.(ADC_RSLTn->_) n=15-19 */
#endif

/* test the ADC status register bits - can be used directly in codition */
/* if it is used in assignment then it returns bit value in original position */
#define ADC_GET_STATUS_CIP          /* NULL, Read the Status Register CIP bit in the Status Register(ADCx_STAT->CIP) */
#define ADC_GET_STATUS_EOSI         /* NULL/ADC_CONVERTER_0ADC_CONVERTER_1, Read the Status Register EOSI bit in the Status Register(ADCx_STAT->EOSI0) */
#define ADC_GET_STATUS_ZCI          /* NULL, Read the Status Register ZCI bit in the Status Register(ADCx_STAT->ZCI) */
#define ADC_GET_STATUS_LLMTI        /* NULL, Read the Status Register LLMTI bit in the Status Register(ADCx_STAT->LLMTI) */
#define ADC_GET_STATUS_HLMTI        /* NULL, Read the Status Register HLMTI bit in the Status Register(ADCx_STAT->HLMTI) */
#define ADC_GET_STATUS_RDY          /* UWord16, Read the Status Register 1 RDYx bit (Ready Sample 0-15 flag).(ADC_RDY->_) */

/* test the ADC limit status register bits */
#define ADC_GET_LIMIT_STATUS_LLS    /* UWord16;sample number(0-15), Read the Low Limit Status Register LLSx bit (Low Limit Sample x flag). (ADC_LOLIMSTAT->_) */
#define ADC_GET_LIMIT_STATUS_HLS    /* UWord16;sample number(0-15), Read the High Limit Status Register HLSx bit (High Limit Sample x flag). (ADC_HILIMSTAT->_) */

#define ADC_GET_ZERO_CROSS_STATUS_ZCS   /* UWord16,sample number(0-15), Read the Zero Crossing Status Register ZCSx  bit (Zero Crossing x flag).( ADC_ZXSTAT->_) */

/* clearing bits in Limit Status,Zero Crossing Status reg individaully */
#define ADC_CLEAR_LIMIT_STATUS_HLS      /* UWord16;sample number(0-15), Clear the Low Limit Status Register LLSx bit (Low Limit Sample x flag). (ADC_LOLIMSTAT->_) */
#define ADC_CLEAR_LIMIT_STATUS_LLS      /* UWord16;sample number(0-15), Clear the High Limit Status Register HLSx bit (High Limit Sample x flag). (ADC_HILIMSTAT->_) */
#define ADC_CLEAR_ZERO_CROSS_STATUS_ZCS /* UWord16;sample number(0-15), Clear the High Limit Status Register ZCSx bit (Zero Crossing x flag). (ADC_ZXSTAT->_) */

/* Power Control Register */
#define ADC_SET_POWER_UP_DELAY          /* number 0-63 as UWord16, Set power up delay in Power Control Register(ADCx_PWR->_) */

#if ADC_VERSION >= 5
/* Calibration Register */
#define ADC_SET_CALIB_SOURCE            /* ADC_ANA7_xxx or ADC_ANB7_xxx (NORMAL/FROM_DAC0/FROM_DAC0_PASSTHRU), Select internal source of ANA7 and ANB7 inputs in the ADC Calibration Register(ADC_CAL->_) */
                                           
#endif
/****************************************************************************
* ADC ADC_VERSION_5-only commands
*****************************************************************************/

#if ADC_VERSION >= 5
/* Gain Control Register 1 */
#define ADC_SET_ANB7_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANB7 input (ADC_GGC2->GAIN15) */
#define ADC_SET_ANB6_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANB6 input (ADC_GGC2->GAIN14) */
#define ADC_SET_ANB5_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANB5 input (ADC_GGC2->GAIN13) */
#define ADC_SET_ANB4_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANB4 input (ADC_GGC2->GAIN12) */
#define ADC_SET_ANB3_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANB3 input (ADC_GGC2->GAIN11) */
#define ADC_SET_ANB2_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANB2 input (ADC_GGC2->GAIN10) */
#define ADC_SET_ANB1_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANB1 input (ADC_GGC2->GAIN9) */
#define ADC_SET_ANB0_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANB0 input (ADC_GGC2->GAIN8) */
#define ADC_SET_ANA7_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANA7 input (ADC_GGC1->GAIN7) */
#define ADC_SET_ANA6_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANA6 input (ADC_GGC1->GAIN6) */
#define ADC_SET_ANA5_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANA5 input (ADC_GGC1->GAIN5) */
#define ADC_SET_ANA4_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANA4 input (ADC_GGC1->GAIN4) */
#define ADC_SET_ANA3_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANA3 input (ADC_GGC1->GAIN3) */
#define ADC_SET_ANA2_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANA2 input (ADC_GGC1->GAIN2) */
#define ADC_SET_ANA1_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANA1 input (ADC_GGC1->GAIN1) */
#define ADC_SET_ANA0_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANA0 input (ADC_GGC1->GAIN0) */

#if ADC_VERSION >= 7
#define ADC_SET_ANA9_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANA9  input (ADC_GGC3->GAIN16) */
#define ADC_SET_ANA10_GAIN              /* ADC_GAIN_x(1/2/4), Selects channel gain for ANA10 input (ADC_GGC3->GAIN17) */
#define ADC_SET_ANB9_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANB9  input (ADC_GGC3->GAIN18) */
#define ADC_SET_ANB10_GAIN              /* ADC_GAIN_x(1/2/4), Selects channel gain for ANB10 input (ADC_GGC3->GAIN19) */
#endif
#endif

#if ADC_VERSION >= 7
/* Gain Control Register 3 */
#define ADC_SET_ANB19_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANB19 input (ADC_GGC3->GAIN19) */
#define ADC_SET_ANB18_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANB18 input (ADC_GGC3->GAIN18) */
#define ADC_SET_ANA17_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANA17 input (ADC_GGC3->GAIN17) */
#define ADC_SET_ANA16_GAIN               /* ADC_GAIN_x(1/2/4), Selects channel gain for ANA16 input (ADC_GGC3->GAIN16) */
#endif

#if ADC_VERSION <= 6
/* Power Control Register 2 */
#define ADC_SET_MAX_SPEED_ADCA          /* ADC_SPEED_xxx(ADC_SPEED_5MHZ/ADC_SPEED_10MHZ/ADC_SPEED_15MHZ/ADC_SPEED_20MHZ),set maximum clock speed of the part ADCA(PWR2->SPEEDA) */
#define ADC_SET_MAX_SPEED_ADCB          /* ADC_SPEED_xxx(5MHZ/12MHZ/15MHZ),set maximum clock speed of the part ADCB(PWR2->SPEEDB) */
#define ADC_SET_ADCB_DIVISOR_PARALEL_MODE /* UWord16/ADC_DIV2/ADC_DIV4/ADC_DIV6..ADC_DIV128, Set ADC module ANB clock divisor select in paralel mode which determines ADC conversion speed.(PWR2->DIV1) */
#endif
#endif

/*****************************************************************
* Software Layer ioctl() commands
*
*  Word16 ioctl( ADC,Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define ADC_INIT                    /* NULL,Initialization of the periheral registers using appconfig.h _INIT values  */

/****************************************************************************
* ADC command parameters
*****************************************************************************/

#define ADC_ENABLE  1
#define ADC_DISABLE 0

#if ADC_VERSION >= 2
#define ADC_ENABLE_CONVERTER_0          ADC_ENABLE
#define ADC_ENABLE_CONVERTER_1          (ADC_ENABLE | 0x10)
#define ADC_DISABLE_CONVERTER_0         ADC_DISABLE
#define ADC_DISABLE_CONVERTER_1         (ADC_DISABLE | 0x10)
#endif

#define ADC_ON  1
#define ADC_OFF 0

#if ADC_VERSION >= 2
#define ADC_ON_CONVERTER_0                  (ADC_ON)
#define ADC_ON_CONVERTER_1                  (ADC_ON|0x10)
#define ADC_OFF_CONVERTER_0                 ADC_OFF
#define ADC_OFF_CONVERTER_1                 (ADC_OFF|0x10)
#endif

/* divisor values */
#define ADC_DIV2   0UL
#define ADC_DIV4   1UL
#define ADC_DIV6   2UL
#define ADC_DIV8   3UL
#define ADC_DIV10  4UL
#define ADC_DIV12  5UL
#define ADC_DIV14  6UL
#define ADC_DIV16  7UL
#define ADC_DIV18  8UL
#define ADC_DIV20  9UL
#define ADC_DIV22  10UL
#define ADC_DIV24  11UL
#define ADC_DIV26  12UL
#define ADC_DIV28  13UL
#define ADC_DIV30  14UL
#define ADC_DIV32  15UL
#define ADC_DIV34  16UL
#define ADC_DIV36  17UL
#define ADC_DIV38  18UL
#define ADC_DIV40  19UL
#define ADC_DIV42  20UL
#define ADC_DIV44  21UL
#define ADC_DIV46  22UL
#define ADC_DIV48  23UL
#define ADC_DIV50  24UL
#define ADC_DIV52  25UL
#define ADC_DIV54  26UL
#define ADC_DIV56  27UL
#define ADC_DIV58  28UL
#define ADC_DIV60  29UL
#define ADC_DIV62  30UL
#define ADC_DIV64  31UL

#if ADC_VERSION >= 6
#define ADC_DIV66  32UL
#define ADC_DIV68  33UL
#define ADC_DIV70  34UL
#define ADC_DIV72  35UL
#define ADC_DIV74  36UL
#define ADC_DIV76  37UL
#define ADC_DIV78  38UL
#define ADC_DIV80  39UL
#define ADC_DIV82  40UL
#define ADC_DIV84  41UL
#define ADC_DIV86  42UL
#define ADC_DIV88  43UL
#define ADC_DIV90  44UL
#define ADC_DIV92  45UL
#define ADC_DIV94  46UL
#define ADC_DIV96  47UL
#define ADC_DIV98  48UL
#define ADC_DIV100 49UL
#define ADC_DIV102 50UL
#define ADC_DIV104 51UL
#define ADC_DIV106 52UL
#define ADC_DIV108 53UL
#define ADC_DIV110 54UL
#define ADC_DIV112 55UL
#define ADC_DIV114 56UL
#define ADC_DIV116 57UL
#define ADC_DIV118 58UL
#define ADC_DIV120 59UL
#define ADC_DIV122 60UL
#define ADC_DIV124 61UL
#define ADC_DIV126 62UL
#define ADC_DIV128 63UL
#endif	/* #if ADC_VERSION >= 6 */


/* interrupts */
#define ADC_END_OF_SCAN ADC_ADCR1_EOSIE 
#define ADC_ZERO_CROSS  ADC_ADCR1_ZCIE  
#define ADC_LOW_LIMIT   ADC_ADCR1_LLMTIE
#define ADC_HIGH_LIMIT  ADC_ADCR1_HLMTIE

#if ADC_VERSION >= 2
#define ADC_END_OF_SCAN_CONVERTER_0 ADC_ADCR1_EOSIE 
#define ADC_END_OF_SCAN_CONVERTER_1 (((UWord32)(ADC_ADCR1_EOSIE)) << 16)
#endif
                
/* zero crossing modes */
#define ADC_ZC_DISABLE 0UL    
#define ADC_ZC_POS2NEG 1UL
#define ADC_ZC_NEG2POS 2UL
#define ADC_ZC_BOTH    3UL

/* channel numbers */
#if ADC_VERSION == 1
#define ADC_CH0 0
#define ADC_CH1 1
#define ADC_CH2 2
#define ADC_CH3 3
#define ADC_CH4 4
#define ADC_CH5 5
#define ADC_CH6 6
#define ADC_CH7 7
#endif
#if ADC_VERSION >= 6
#define ADC_ANA0 0UL
#define ADC_ANA1 1UL
#define ADC_ANA2 2UL
#define ADC_ANA3 3UL
#define ADC_ANA4 4UL
#define ADC_ANA5 5UL
#define ADC_ANA6 6UL
#define ADC_ANA7 7UL
#define ADC_ANB0 8UL
#define ADC_ANB1 9UL
#define ADC_ANB2 10UL
#define ADC_ANB3 11UL
#define ADC_ANB4 12UL
#define ADC_ANB5 13UL
#define ADC_ANB6 14UL
#define ADC_ANB7 15UL
#else
#if ADC_VERSION >= 2
#define ADC_ANA0 0UL
#define ADC_ANA1 1UL
#define ADC_ANA2 2UL
#define ADC_ANA3 3UL
#define ADC_ANB0 4UL
#define ADC_ANB1 5UL
#define ADC_ANB2 6UL
#define ADC_ANB3 7UL
#endif
#if ADC_VERSION >= 3
#define ADC_ANA4 8UL
#define ADC_ANA5 9UL
#define ADC_ANA6 10UL
#define ADC_ANA7 11UL
#define ADC_ANB4 12UL
#define ADC_ANB5 13UL
#define ADC_ANB6 14UL
#define ADC_ANB7 15UL
#endif
#endif /* ADC_VERSION >= 6 */

/* CLIST 5 */
#if ADC_VERSION >= 7
#define ADCA_TEMPERATURE_SENSOR   0UL
#define ADCA_ANALOG_INPUT       1UL
#define ADCB_TEMPERATURE_SENSOR   2UL
#define ADCB_ANALOG_INPUT       3UL
#endif

/* channel configurations */
#if ADC_VERSION == 1
#define ADC_AN0_AN1_SE      0x0100
#define ADC_AN0_AN1_DIFF    0x0101
#define ADC_AN2_AN3_SE      0x0200
#define ADC_AN2_AN3_DIFF    0x0202
#define ADC_AN4_AN5_SE      0x0400
#define ADC_AN4_AN5_DIFF    0x0404
#define ADC_AN6_AN7_SE      0x0800
#define ADC_AN6_AN7_DIFF    0x0808
#endif
#if ADC_VERSION >= 2
#define ADC_ANA0_ANA1_SE    0x0100
#define ADC_ANA0_ANA1_DIFF  0x0101
#define ADC_ANA2_ANA3_SE    0x0200
#define ADC_ANA2_ANA3_DIFF  0x0202
#define ADC_ANB0_ANB1_SE    0x0400
#define ADC_ANB0_ANB1_DIFF  0x0404
#define ADC_ANB2_ANB3_SE    0x0800
#define ADC_ANB2_ANB3_DIFF  0x0808
#endif
#if ADC_VERSION >= 3
#define ADC_ANA4_ANA5_SE    0x1000
#define ADC_ANA4_ANA5_DIFF  0x1010
#define ADC_ANA6_ANA7_SE    0x2000
#define ADC_ANA6_ANA7_DIFF  0x2020
#define ADC_ANB4_ANB5_SE    0x4000
#define ADC_ANB4_ANB5_DIFF  0x4040
#define ADC_ANB6_ANB7_SE    0x8000
#define ADC_ANB6_ANB7_DIFF  0x8080
#endif

/* adc modes */
#define ADC_SCAN_ONCE_SEQUENTIAL    ADC_ADCR1_SMODE_ONCESEQ
#define ADC_SCAN_ONCE_SIMULTANEOUS  ADC_ADCR1_SMODE_ONCESIM
#define ADC_SCAN_LOOP_SEQUENTIAL    ADC_ADCR1_SMODE_LOOPSEQ
#define ADC_SCAN_LOOP_SIMULTANEOUS  ADC_ADCR1_SMODE_LOOPSIM
#define ADC_SCAN_TRIG_SEQUENTIAL    ADC_ADCR1_SMODE_TRIGSEQ
#define ADC_SCAN_TRIG_SIMULTANEOUS  ADC_ADCR1_SMODE_TRIGSIM

/* bit mask for testing of the status registers ADC_READ_STATUS (RDYx bits) */
#define ADC_S0      ADC_ADSTAT_RDY0
#define ADC_S1      ADC_ADSTAT_RDY1
#define ADC_S2      ADC_ADSTAT_RDY2
#define ADC_S3      ADC_ADSTAT_RDY3
#define ADC_S4      ADC_ADSTAT_RDY4
#define ADC_S5      ADC_ADSTAT_RDY5
#define ADC_S6      ADC_ADSTAT_RDY6
#define ADC_S7      ADC_ADSTAT_RDY7

#if ADC_VERSION <= 5
/* bit values for limit status registers ADC_READ_LIMIT_STATUS and ADC_CLEAR_LIMIT_STATUS_BITS */
#define ADC_LLS0    ADC_ADLSTAT_LLS0
#define ADC_LLS1    ADC_ADLSTAT_LLS1
#define ADC_LLS2    ADC_ADLSTAT_LLS2
#define ADC_LLS3    ADC_ADLSTAT_LLS3
#define ADC_LLS4    ADC_ADLSTAT_LLS4
#define ADC_LLS5    ADC_ADLSTAT_LLS5
#define ADC_LLS6    ADC_ADLSTAT_LLS6
#define ADC_LLS7    ADC_ADLSTAT_LLS7
#define ADC_LLS_ALL (ADC_LLS0 | ADC_LLS1 | ADC_LLS2 | ADC_LLS3 |\
                     ADC_LLS4 | ADC_LLS5 | ADC_LLS6 | ADC_LLS7)

#define ADC_HLS0    ADC_ADLSTAT_HLS0
#define ADC_HLS1    ADC_ADLSTAT_HLS1
#define ADC_HLS2    ADC_ADLSTAT_HLS2
#define ADC_HLS3    ADC_ADLSTAT_HLS3
#define ADC_HLS4    ADC_ADLSTAT_HLS4
#define ADC_HLS5    ADC_ADLSTAT_HLS5
#define ADC_HLS6    ADC_ADLSTAT_HLS6
#define ADC_HLS7    ADC_ADLSTAT_HLS7
#define ADC_HLS_ALL (ADC_HLS0 | ADC_HLS1 | ADC_HLS2 | ADC_HLS3 |\
                     ADC_HLS4 | ADC_HLS5 | ADC_HLS6 | ADC_HLS7)
#else /* ADC_VERSION >= 6 */
/* bit values for limit status registers ADC_READ_LOW_LIMIT_STATUS and ADC_CLEAR_LOW_LIMIT_STATUS_BITS */
#define ADC_LLS0    ADC_ADLSTAT_LLS0
#define ADC_LLS1    ADC_ADLSTAT_LLS1
#define ADC_LLS2    ADC_ADLSTAT_LLS2
#define ADC_LLS3    ADC_ADLSTAT_LLS3
#define ADC_LLS4    ADC_ADLSTAT_LLS4
#define ADC_LLS5    ADC_ADLSTAT_LLS5
#define ADC_LLS6    ADC_ADLSTAT_LLS6
#define ADC_LLS7    ADC_ADLSTAT_LLS7
#define ADC_LLS8    ADC_ADLSTAT_LLS8
#define ADC_LLS9    ADC_ADLSTAT_LLS9
#define ADC_LLS10   ADC_ADLSTAT_LLS10
#define ADC_LLS11   ADC_ADLSTAT_LLS11
#define ADC_LLS12   ADC_ADLSTAT_LLS12
#define ADC_LLS13   ADC_ADLSTAT_LLS13
#define ADC_LLS14   ADC_ADLSTAT_LLS14
#define ADC_LLS15   ADC_ADLSTAT_LLS15
#define ADC_LLS_ALL (ADC_LLS0 | ADC_LLS1 | ADC_LLS2 | ADC_LLS3 |\
                     ADC_LLS4 | ADC_LLS5 | ADC_LLS6 | ADC_LLS7 |\
                     ADC_LLS8 | ADC_LLS9 | ADC_LLS10 | ADC_LLS11 |\
                     ADC_LLS12 | ADC_LLS13 | ADC_LLS14 | ADC_LLS15)
#if ADC_VERSION >= 7
#define ADC_LLS16   ADC_ADLSTAT_LLS16
#define ADC_LLS17   ADC_ADLSTAT_LLS17
#define ADC_LLS18   ADC_ADLSTAT_LLS18
#define ADC_LLS19   ADC_ADLSTAT_LLS19
#endif

/* bit values for limit status registers ADC_READ_ZERO_CROSS_STATUS and ADC_CLEAR_ZERO_CROSS_STATUS_BITS */
#define ADC_HLS0    ADC_ADLSTAT_HLS0
#define ADC_HLS1    ADC_ADLSTAT_HLS1
#define ADC_HLS2    ADC_ADLSTAT_HLS2
#define ADC_HLS3    ADC_ADLSTAT_HLS3
#define ADC_HLS4    ADC_ADLSTAT_HLS4
#define ADC_HLS5    ADC_ADLSTAT_HLS5
#define ADC_HLS6    ADC_ADLSTAT_HLS6
#define ADC_HLS7    ADC_ADLSTAT_HLS7
#define ADC_HLS8    ADC_ADLSTAT_HLS8
#define ADC_HLS9    ADC_ADLSTAT_HLS9
#define ADC_HLS10   ADC_ADLSTAT_HLS10
#define ADC_HLS11   ADC_ADLSTAT_HLS11
#define ADC_HLS12   ADC_ADLSTAT_HLS12
#define ADC_HLS13   ADC_ADLSTAT_HLS13
#define ADC_HLS14   ADC_ADLSTAT_HLS14
#define ADC_HLS15   ADC_ADLSTAT_HLS15
#define ADC_HLS_ALL (ADC_HLS0 | ADC_HLS1 | ADC_HLS2 | ADC_HLS3 |\
                     ADC_HLS4 | ADC_HLS5 | ADC_HLS6 | ADC_HLS7 |\
                     ADC_HLS8 | ADC_HLS9 | ADC_HLS10 | ADC_HLS11 |\
                     ADC_HLS12 | ADC_HLS13 | ADC_HLS14 | ADC_HLS15)
#if ADC_VERSION >= 7
#define ADC_HLS16   ADC_ADLSTAT_HLS16
#define ADC_HLS17   ADC_ADLSTAT_HLS17
#define ADC_HLS18   ADC_ADLSTAT_HLS18
#define ADC_HLS19   ADC_ADLSTAT_HLS19
#endif	

/* bit values for limit status registers ADC_READ_HIGH_LIMIT_STATUS and ADC_CLEAR_HIGH_LIMIT_STATUS_BITS */
#define ADC_ZCS0    ADC_ADZCSTAT_ZCS0
#define ADC_ZCS1    ADC_ADZCSTAT_ZCS1
#define ADC_ZCS2    ADC_ADZCSTAT_ZCS2
#define ADC_ZCS3    ADC_ADZCSTAT_ZCS3
#define ADC_ZCS4    ADC_ADZCSTAT_ZCS4
#define ADC_ZCS5    ADC_ADZCSTAT_ZCS5
#define ADC_ZCS6    ADC_ADZCSTAT_ZCS6
#define ADC_ZCS7    ADC_ADZCSTAT_ZCS7
#define ADC_ZCS8    ADC_ADZCSTAT_ZCS8
#define ADC_ZCS9    ADC_ADZCSTAT_ZCS9
#define ADC_ZCS10   ADC_ADZCSTAT_ZCS10
#define ADC_ZCS11   ADC_ADZCSTAT_ZCS11
#define ADC_ZCS12   ADC_ADZCSTAT_ZCS12
#define ADC_ZCS13   ADC_ADZCSTAT_ZCS13
#define ADC_ZCS14   ADC_ADZCSTAT_ZCS14
#define ADC_ZCS15   ADC_ADZCSTAT_ZCS15
#define ADC_ZCS_ALL (ADC_ZCS0 | ADC_ZCS1 | ADC_ZCS2 |  ADC_ZCS3 |\
                     ADC_ZCS4 | ADC_ZCS5 | ADC_ZCS6 |  ADC_ZCS7 |\
                     ADC_ZCS8 | ADC_ZCS9 | ADC_ZCS10 | ADC_ZCS11 |\
                     ADC_ZCS12| ADC_ZCS13| ADC_ZCS14 | ADC_ZCS15)
#if ADC_VERSION >= 7
#define ADC_ZCS16   ADC_ADZCSTAT_ZCS16
#define ADC_ZCS17   ADC_ADZCSTAT_ZCS17
#define ADC_ZCS18   ADC_ADZCSTAT_ZCS18
#define ADC_ZCS19   ADC_ADZCSTAT_ZCS19
#endif				 				 					 
#endif /* ADC_VERSION >= 6 */

/* sample disable register */
#if ADC_VERSION == 2
#define ADC_SAMPLE0     (ADC_ADSDIS_DS0 | 0x8000UL)
#define ADC_SAMPLE1     (ADC_ADSDIS_DS1 | 0x8000UL)
#define ADC_SAMPLE2     (ADC_ADSDIS_DS2 | 0x8000UL)
#define ADC_SAMPLE3     (ADC_ADSDIS_DS3 | 0x8000UL)
#define ADC_SAMPLE4     (ADC_ADSDIS_DS4 | 0x8000UL)
#define ADC_SAMPLE5     (ADC_ADSDIS_DS5 | 0x8000UL)
#define ADC_SAMPLE6     (ADC_ADSDIS_DS6 | 0x8000UL)
#define ADC_SAMPLE7     (ADC_ADSDIS_DS7 | 0x8000UL)
#define ADC_ENABLE_ALL  0x8000UL
#elif ADC_VERSION >= 3
#define ADC_SAMPLE0     (ADC_ADSDIS_DS0  | 0x80000000UL)
#define ADC_SAMPLE1     (ADC_ADSDIS_DS1  | 0x80000000UL)
#define ADC_SAMPLE2     (ADC_ADSDIS_DS2  | 0x80000000UL)
#define ADC_SAMPLE3     (ADC_ADSDIS_DS3  | 0x80000000UL)
#define ADC_SAMPLE4     (ADC_ADSDIS_DS4  | 0x80000000UL)
#define ADC_SAMPLE5     (ADC_ADSDIS_DS5  | 0x80000000UL)
#define ADC_SAMPLE6     (ADC_ADSDIS_DS6  | 0x80000000UL)
#define ADC_SAMPLE7     (ADC_ADSDIS_DS7  | 0x80000000UL)
#define ADC_SAMPLE8     (ADC_ADSDIS_DS8  | 0x80000000UL)
#define ADC_SAMPLE9     (ADC_ADSDIS_DS9  | 0x80000000UL)
#define ADC_SAMPLE10    (ADC_ADSDIS_DS10 | 0x80000000UL)
#define ADC_SAMPLE11    (ADC_ADSDIS_DS11 | 0x80000000UL)
#define ADC_SAMPLE12    (ADC_ADSDIS_DS12 | 0x80000000UL)
#define ADC_SAMPLE13    (ADC_ADSDIS_DS13 | 0x80000000UL)
#define ADC_SAMPLE14    (ADC_ADSDIS_DS14 | 0x80000000UL)
#define ADC_SAMPLE15    (ADC_ADSDIS_DS15 | 0x80000000UL)
#define ADC_ENABLE_ALL  0x80000000UL
#endif
#if ADC_VERSION >= 7
#define ADC_SAMPLE19    (ADC_ADSDIS_DS19 | 0x80000000UL)
#define ADC_SAMPLE18    (ADC_ADSDIS_DS18 | 0x80000000UL)
#define ADC_SAMPLE17    (ADC_ADSDIS_DS17 | 0x80000000UL)
#define ADC_SAMPLE16    (ADC_ADSDIS_DS16 | 0x80000000UL)
#endif

/* zero crossing control register - masks for samples and crossing types */
/* sample 0 */
#define ADC_S0_ZC_DISABLE              0x0000
#define ADC_S0_ZC_POSITIVE_NEGATIVE    0x0001
#define ADC_S0_ZC_NEGATIVE_POSITIVE    0x0002
#define ADC_S0_ZC_ANY_CROSS            0x0003
/* sample 1 */
#define ADC_S1_ZC_DISABLE              0x0000
#define ADC_S1_ZC_POSITIVE_NEGATIVE    0x0004
#define ADC_S1_ZC_NEGATIVE_POSITIVE    0x0008
#define ADC_S1_ZC_ANY_CROSS            0x000C
/* sample 2 */
#define ADC_S2_ZC_DISABLE              0x0000
#define ADC_S2_ZC_POSITIVE_NEGATIVE    0x0010
#define ADC_S2_ZC_NEGATIVE_POSITIVE    0x0020
#define ADC_S2_ZC_ANY_CROSS            0x0030
/* sample 3 */
#define ADC_S3_ZC_DISABLE              0x0000
#define ADC_S3_ZC_POSITIVE_NEGATIVE    0x0040
#define ADC_S3_ZC_NEGATIVE_POSITIVE    0x0080
#define ADC_S3_ZC_ANY_CROSS            0x00C0
/* sample 4 */
#define ADC_S4_ZC_DISABLE              0x0000
#define ADC_S4_ZC_POSITIVE_NEGATIVE    0x0100
#define ADC_S4_ZC_NEGATIVE_POSITIVE    0x0200
#define ADC_S4_ZC_ANY_CROSS            0x0300
/* sample 5 */
#define ADC_S5_ZC_DISABLE              0x0000
#define ADC_S5_ZC_POSITIVE_NEGATIVE    0x0400
#define ADC_S5_ZC_NEGATIVE_POSITIVE    0x0800
#define ADC_S5_ZC_ANY_CROSS            0x0C00
/* sample 6 */
#define ADC_S6_ZC_DISABLE              0x0000
#define ADC_S6_ZC_POSITIVE_NEGATIVE    0x1000
#define ADC_S6_ZC_NEGATIVE_POSITIVE    0x2000
#define ADC_S6_ZC_ANY_CROSS            0x3000
/* sample 7 */
#define ADC_S7_ZC_DISABLE              0x0000
#define ADC_S7_ZC_POSITIVE_NEGATIVE    0x4000
#define ADC_S7_ZC_NEGATIVE_POSITIVE    0x8000
#define ADC_S7_ZC_ANY_CROSS            0xC000

#if ADC_VERSION >= 6
/* zero crossing control register zxctrl1 - ADC_WRITE_ZERO_CROSS_CNTRL1 masks for samples and crossing types */
/* sample 0 */
#define ADC_S0_ZC1_DISABLE              0x0000
#define ADC_S0_ZC1_POSITIVE_NEGATIVE    0x0001
#define ADC_S0_ZC1_NEGATIVE_POSITIVE    0x0002
#define ADC_S0_ZC1_ANY_CROSS            0x0003
/* sample 1 */
#define ADC_S1_ZC1_DISABLE              0x0000
#define ADC_S1_ZC1_POSITIVE_NEGATIVE    0x0004
#define ADC_S1_ZC1_NEGATIVE_POSITIVE    0x0008
#define ADC_S1_ZC1_ANY_CROSS            0x000C
/* sample 2 */
#define ADC_S2_ZC1_DISABLE              0x0000
#define ADC_S2_ZC1_POSITIVE_NEGATIVE    0x0010
#define ADC_S2_ZC1_NEGATIVE_POSITIVE    0x0020
#define ADC_S2_ZC1_ANY_CROSS            0x0030
/* sample 3 */
#define ADC_S3_ZC1_DISABLE              0x0000
#define ADC_S3_ZC1_POSITIVE_NEGATIVE    0x0040
#define ADC_S3_ZC1_NEGATIVE_POSITIVE    0x0080
#define ADC_S3_ZC1_ANY_CROSS            0x00C0
/* sample 4 */
#define ADC_S4_ZC1_DISABLE              0x0000
#define ADC_S4_ZC1_POSITIVE_NEGATIVE    0x0100
#define ADC_S4_ZC1_NEGATIVE_POSITIVE    0x0200
#define ADC_S4_ZC1_ANY_CROSS            0x0300
/* sample 5 */
#define ADC_S5_ZC1_DISABLE              0x0000
#define ADC_S5_ZC1_POSITIVE_NEGATIVE    0x0400
#define ADC_S5_ZC1_NEGATIVE_POSITIVE    0x0800
#define ADC_S5_ZC1_ANY_CROSS            0x0C00
/* sample 6 */
#define ADC_S6_ZC1_DISABLE              0x0000
#define ADC_S6_ZC1_POSITIVE_NEGATIVE    0x1000
#define ADC_S6_ZC1_NEGATIVE_POSITIVE    0x2000
#define ADC_S6_ZC1_ANY_CROSS            0x3000
/* sample 7 */
#define ADC_S7_ZC1_DISABLE              0x0000
#define ADC_S7_ZC1_POSITIVE_NEGATIVE    0x4000
#define ADC_S7_ZC1_NEGATIVE_POSITIVE    0x8000
#define ADC_S7_ZC1_ANY_CROSS            0xC000

/* zero crossing control register zxctrl2 - ADC_WRITE_ZERO_CROSS_CNTRL2 masks for samples and crossing types */
/* sample 8 */
#define ADC_S8_ZC2_DISABLE              0x0000
#define ADC_S8_ZC2_POSITIVE_NEGATIVE    0x0001
#define ADC_S8_ZC2_NEGATIVE_POSITIVE    0x0002
#define ADC_S8_ZC2_ANY_CROSS            0x0003
/* sample 9 */
#define ADC_S9_ZC2_DISABLE              0x0000
#define ADC_S9_ZC2_POSITIVE_NEGATIVE    0x0004
#define ADC_S9_ZC2_NEGATIVE_POSITIVE    0x0008
#define ADC_S9_ZC2_ANY_CROSS            0x000C
/* sample 10 */
#define ADC_S10_ZC2_DISABLE              0x0000
#define ADC_S10_ZC2_POSITIVE_NEGATIVE    0x0010
#define ADC_S10_ZC2_NEGATIVE_POSITIVE    0x0020
#define ADC_S10_ZC2_ANY_CROSS            0x0030
/* sample 11 */
#define ADC_S11_ZC2_DISABLE              0x0000
#define ADC_S11_ZC2_POSITIVE_NEGATIVE    0x0040
#define ADC_S11_ZC2_NEGATIVE_POSITIVE    0x0080
#define ADC_S11_ZC2_ANY_CROSS            0x00C0
/* sample 12 */
#define ADC_S12_ZC2_DISABLE              0x0000
#define ADC_S12_ZC2_POSITIVE_NEGATIVE    0x0100
#define ADC_S12_ZC2_NEGATIVE_POSITIVE    0x0200
#define ADC_S12_ZC2_ANY_CROSS            0x0300
/* sample 13 */
#define ADC_S13_ZC2_DISABLE              0x0000
#define ADC_S13_ZC2_POSITIVE_NEGATIVE    0x0400
#define ADC_S13_ZC2_NEGATIVE_POSITIVE    0x0800
#define ADC_S13_ZC2_ANY_CROSS            0x0C00
/* sample 14 */
#define ADC_S14_ZC2_DISABLE              0x0000
#define ADC_S14_ZC2_POSITIVE_NEGATIVE    0x1000
#define ADC_S14_ZC2_NEGATIVE_POSITIVE    0x2000
#define ADC_S14_ZC2_ANY_CROSS            0x3000
/* sample 15 */
#define ADC_S15_ZC2_DISABLE              0x0000
#define ADC_S15_ZC2_POSITIVE_NEGATIVE    0x4000
#define ADC_S15_ZC2_NEGATIVE_POSITIVE    0x8000
#define ADC_S15_ZC2_ANY_CROSS            0xC000
#endif

/* power control */
#define ADC_CONVERTER_0         ADC_ADCPOWER_PD0
#define ADC_CONVERTER_1         ADC_ADCPOWER_PD1

/* calibration */
#define ADC_VCAL_L 0
#define ADC_VCAL_H 1

#if ADC_VERSION >= 2
#define ADC_VREF_SRC_INTERNAL 0
#define ADC_VREF_SRC_EXTERNAL 1
#endif

/* calibration source */
#if ADC_VERSION >= 3
#define ADC_ANA7_NORMAL              0x0000
#define ADC_ANA7_FROM_DAC0           0x0001
#define ADC_ANA7_FROM_DAC0_PASSTHRU  0x0005
#define ADC_ANB7_NORMAL              0x0000
#define ADC_ANB7_FROM_DAC1           0x0002
#define ADC_ANB7_FROM_DAC1_PASSTHRU  0x000a
#endif
#if ADC_VERSION >= 7
#define ADC_NORMAL_OPERATION        0
#define ADC_ANALOG_INPUT            1
#define ADC_TEMPERATURE_SENSOR      1      
#endif

/* set ADC speed and */
#if ADC_VERSION >= 5
#define	ADC_GAIN_1                  0UL
#define	ADC_GAIN_2                  1UL
#define	ADC_GAIN_4                  2UL
#define	ADC_SPEED_5MHZ              0UL
#define	ADC_SPEED_10MHZ             1UL
#define	ADC_SPEED_15MHZ             2UL
#define ADC_SPEED_20MHZ             3UL
#endif

/* set DMA trigger in ADCx_CTRL3 */
#if ADC_VERSION >= 5
#define	ADC_DMA_TRIGGER_END_SCAN    0
#define	ADC_DMA_TRIGGER_RDY         1
#endif

/* set Sample Window in Count ADCx_CTRL3 */
#if ADC_VERSION >= 5
#define	ADC_CLOCK_2    				0UL
#define	ADC_CLOCK_3         		1UL
#define	ADC_CLOCK_4    				2UL
#define	ADC_CLOCK_5         		3UL
#define	ADC_CLOCK_6    				4UL
#define	ADC_CLOCK_7         		5UL
#define	ADC_CLOCK_8    				6UL
#define	ADC_CLOCK_9         		7UL
#endif

/* ADC Channel List Register 5 ADC_CLIST5 */
#define ADC_CLIST5_ALL_SAMPLE_MASK				0x00ff
#define ADC_CLIST5_SEL_TEMP_0_MASK				0x0100
#define ADC_CLIST5_SEL_INTERNAL_0_MASK			0x0200
#define ADC_CLIST5_SEL_TEMP_1_MASK				0x0400
#define ADC_CLIST5_SEL_INTERNAL_1_MASK			0x0800

/* ADC Sample Disable Register 2 ADC_SDIS2 */
#define ADC_SDIS2_MASK				0x000f

/* ADC Low Limit Status Register 2 ADC_LOLIMSTAT2 */
#define ADC_LOLIMSTAT2_MASK			0x000f
/* ADC High Limit Status Register 2 ADC_HILIMSTAT2 */
#define ADC_HILIMSTAT2_MASK			0x000f
/* ADC Zero Crossing Status Register 2 ADC_ZXSTAT2 */
#define ADC_ZXSTAT2_MASK			0x000f
/* ADC Result Registers 2 with sign extension ADC_RSLT2n */
#define ADC_RSLT2_MASK				0x000f


/****************************************************************************
* obsolete parameters (do not use in new designs)
*****************************************************************************/
#if ADC_VERSION < 6
/* channel list registers - masks for samples & inputs */
/* sample 0 */
#define ADC_AN0_S0      0x0000
#define ADC_AN1_S0      0x0001
#define ADC_AN2_S0      0x0002
#define ADC_AN3_S0      0x0003
#define ADC_AN4_S0      0x0004
#define ADC_AN5_S0      0x0005
#define ADC_AN6_S0      0x0006
#define ADC_AN7_S0      0x0007
/* sample 1 */
#define ADC_AN0_S1      0x0000
#define ADC_AN1_S1      0x0010
#define ADC_AN2_S1      0x0020
#define ADC_AN3_S1      0x0030
#define ADC_AN4_S1      0x0040
#define ADC_AN5_S1      0x0050
#define ADC_AN6_S1      0x0060
#define ADC_AN7_S1      0x0070
/* sample 2 */
#define ADC_AN0_S2      0x0000
#define ADC_AN1_S2      0x0100
#define ADC_AN2_S2      0x0200
#define ADC_AN3_S2      0x0300
#define ADC_AN4_S2      0x0400
#define ADC_AN5_S2      0x0500
#define ADC_AN6_S2      0x0600
#define ADC_AN7_S2      0x0700
/* sample 3 */
#define ADC_AN0_S3      0x0000
#define ADC_AN1_S3      0x1000
#define ADC_AN2_S3      0x2000
#define ADC_AN3_S3      0x3000
#define ADC_AN4_S3      0x4000
#define ADC_AN5_S3      0x5000
#define ADC_AN6_S3      0x6000
#define ADC_AN7_S3      0x7000
/* sample 4 */
#define ADC_AN0_S4      0x0000
#define ADC_AN1_S4      0x0001
#define ADC_AN2_S4      0x0002
#define ADC_AN3_S4      0x0003
#define ADC_AN4_S4      0x0004
#define ADC_AN5_S4      0x0005
#define ADC_AN6_S4      0x0006
#define ADC_AN7_S4      0x0007
/* sample 5 */
#define ADC_AN0_S5      0x0000
#define ADC_AN1_S5      0x0010
#define ADC_AN2_S5      0x0020
#define ADC_AN3_S5      0x0030
#define ADC_AN4_S5      0x0040
#define ADC_AN5_S5      0x0050
#define ADC_AN6_S5      0x0060
#define ADC_AN7_S5      0x0070
/* sample 6 */
#define ADC_AN0_S6      0x0000
#define ADC_AN1_S6      0x0100
#define ADC_AN2_S6      0x0200
#define ADC_AN3_S6      0x0300
#define ADC_AN4_S6      0x0400
#define ADC_AN5_S6      0x0500
#define ADC_AN6_S6      0x0600
#define ADC_AN7_S6      0x0700
/* sample 7 */
#define ADC_AN0_S7      0x0000
#define ADC_AN1_S7      0x1000
#define ADC_AN2_S7      0x2000
#define ADC_AN3_S7      0x3000
#define ADC_AN4_S7      0x4000
#define ADC_AN5_S7      0x5000
#define ADC_AN6_S7      0x6000
#define ADC_AN7_S7      0x7000

#else // #if ADC_VERSION <= 6
/* channel list registers - masks for samples & inputs */
/* sample 0 */
#define ADC_ANA0_S0     0x0000
#define ADC_ANA1_S0     0x0001
#define ADC_ANA2_S0     0x0002
#define ADC_ANA3_S0     0x0003
#define ADC_ANA4_S0     0x0004
#define ADC_ANA5_S0     0x0005
#define ADC_ANA6_S0     0x0006
#define ADC_ANA7_S0     0x0007
#define ADC_ANB0_S0     0x0008
#define ADC_ANB1_S0     0x0009
#define ADC_ANB2_S0     0x000A
#define ADC_ANB3_S0     0x000B
#define ADC_ANB4_S0     0x000C
#define ADC_ANB5_S0     0x000D
#define ADC_ANB6_S0     0x000E
#define ADC_ANB7_S0     0x000F
/* sample 1 */
#define ADC_ANA0_S1     0x0000
#define ADC_ANA1_S1     0x0010
#define ADC_ANA2_S1     0x0020
#define ADC_ANA3_S1     0x0030
#define ADC_ANA4_S1     0x0040
#define ADC_ANA5_S1     0x0050
#define ADC_ANA6_S1     0x0060
#define ADC_ANA7_S1     0x0070
#define ADC_ANB0_S1     0x0080
#define ADC_ANB1_S1     0x0090
#define ADC_ANB2_S1     0x00A0
#define ADC_ANB3_S1     0x00B0
#define ADC_ANB4_S1     0x00C0
#define ADC_ANB5_S1     0x00D0
#define ADC_ANB6_S1     0x00E0
#define ADC_ANB7_S1     0x00F0
/* sample 2 */               
#define ADC_ANA0_S2     0x0000
#define ADC_ANA1_S2     0x0100
#define ADC_ANA2_S2     0x0200
#define ADC_ANA3_S2     0x0300
#define ADC_ANA4_S2     0x0400
#define ADC_ANA5_S2     0x0500
#define ADC_ANA6_S2     0x0600
#define ADC_ANA7_S2     0x0700
#define ADC_ANB0_S2     0x0800
#define ADC_ANB1_S2     0x0900
#define ADC_ANB2_S2     0x0A00
#define ADC_ANB3_S2     0x0B00
#define ADC_ANB4_S2     0x0C00
#define ADC_ANB5_S2     0x0D00
#define ADC_ANB6_S2     0x0E00
#define ADC_ANB7_S2     0x0F00
/* sample 3 */               
#define ADC_ANA0_S3     0x0000
#define ADC_ANA1_S3     0x1000
#define ADC_ANA2_S3     0x2000
#define ADC_ANA3_S3     0x3000
#define ADC_ANA4_S3     0x4000
#define ADC_ANA5_S3     0x5000
#define ADC_ANA6_S3     0x6000
#define ADC_ANA7_S3     0x7000
#define ADC_ANB0_S3     0x8000
#define ADC_ANB1_S3     0x9000
#define ADC_ANB2_S3     0xA000
#define ADC_ANB3_S3     0xB000
#define ADC_ANB4_S3     0xC000
#define ADC_ANB5_S3     0xD000
#define ADC_ANB6_S3     0xE000
#define ADC_ANB7_S3     0xF000
/* sample 4 */
#define ADC_ANA0_S4     0x0000
#define ADC_ANA1_S4     0x0001
#define ADC_ANA2_S4     0x0002
#define ADC_ANA3_S4     0x0003
#define ADC_ANA4_S4     0x0004
#define ADC_ANA5_S4     0x0005
#define ADC_ANA6_S4     0x0006
#define ADC_ANA7_S4     0x0007
#define ADC_ANB0_S4     0x0008
#define ADC_ANB1_S4     0x0009
#define ADC_ANB2_S4     0x000A
#define ADC_ANB3_S4     0x000B
#define ADC_ANB4_S4     0x000C
#define ADC_ANB5_S4     0x000D
#define ADC_ANB6_S4     0x000E
#define ADC_ANB7_S4     0x000F
/* sample 5 */
#define ADC_ANA0_S5     0x0000
#define ADC_ANA1_S5     0x0010
#define ADC_ANA2_S5     0x0020
#define ADC_ANA3_S5     0x0030
#define ADC_ANA4_S5     0x0040
#define ADC_ANA5_S5     0x0050
#define ADC_ANA6_S5     0x0060
#define ADC_ANA7_S5     0x0070
#define ADC_ANB0_S5     0x0080
#define ADC_ANB1_S5     0x0090
#define ADC_ANB2_S5     0x00A0
#define ADC_ANB3_S5     0x00B0
#define ADC_ANB4_S5     0x00C0
#define ADC_ANB5_S5     0x00D0
#define ADC_ANB6_S5     0x00E0
#define ADC_ANB7_S5     0x00F0
/* sample 6 */               
#define ADC_ANA0_S6     0x0000
#define ADC_ANA1_S6     0x0100
#define ADC_ANA2_S6     0x0200
#define ADC_ANA3_S6     0x0300
#define ADC_ANA4_S6     0x0400
#define ADC_ANA5_S6     0x0500
#define ADC_ANA6_S6     0x0600
#define ADC_ANA7_S6     0x0700
#define ADC_ANB0_S6     0x0800
#define ADC_ANB1_S6     0x0900
#define ADC_ANB2_S6     0x0A00
#define ADC_ANB3_S6     0x0B00
#define ADC_ANB4_S6     0x0C00
#define ADC_ANB5_S6     0x0D00
#define ADC_ANB6_S6     0x0E00
#define ADC_ANB7_S6     0x0F00
/* sample 7 */               
#define ADC_ANA0_S7     0x0000
#define ADC_ANA1_S7     0x1000
#define ADC_ANA2_S7     0x2000
#define ADC_ANA3_S7     0x3000
#define ADC_ANA4_S7     0x4000
#define ADC_ANA5_S7     0x5000
#define ADC_ANA6_S7     0x6000
#define ADC_ANA7_S7     0x7000
#define ADC_ANB0_S7     0x8000
#define ADC_ANB1_S7     0x9000
#define ADC_ANB2_S7     0xA000
#define ADC_ANB3_S7     0xB000
#define ADC_ANB4_S7     0xC000
#define ADC_ANB5_S7     0xD000
#define ADC_ANB6_S7     0xE000
#define ADC_ANB7_S7     0xF000
/* sample 8 */
#define ADC_ANA0_S8     0x0000
#define ADC_ANA1_S8     0x0001
#define ADC_ANA2_S8     0x0002
#define ADC_ANA3_S8     0x0003
#define ADC_ANA4_S8     0x0004
#define ADC_ANA5_S8     0x0005
#define ADC_ANA6_S8     0x0006
#define ADC_ANA7_S8     0x0007
#define ADC_ANB0_S8     0x0008
#define ADC_ANB1_S8     0x0009
#define ADC_ANB2_S8     0x000A
#define ADC_ANB3_S8     0x000B
#define ADC_ANB4_S8     0x000C
#define ADC_ANB5_S8     0x000D
#define ADC_ANB6_S8     0x000E
#define ADC_ANB7_S8     0x000F
/* sample 9 */
#define ADC_ANA0_S9     0x0000
#define ADC_ANA1_S9     0x0010
#define ADC_ANA2_S9     0x0020
#define ADC_ANA3_S9     0x0030
#define ADC_ANA4_S9     0x0040
#define ADC_ANA5_S9     0x0050
#define ADC_ANA6_S9     0x0060
#define ADC_ANA7_S9     0x0070
#define ADC_ANB0_S9     0x0080
#define ADC_ANB1_S9     0x0090
#define ADC_ANB2_S9     0x00A0
#define ADC_ANB3_S9     0x00B0
#define ADC_ANB4_S9     0x00C0
#define ADC_ANB5_S9     0x00D0
#define ADC_ANB6_S9     0x00E0
#define ADC_ANB7_S9     0x00F0
/* sample 10 */              
#define ADC_ANA0_S10    0x0000
#define ADC_ANA1_S10    0x0100
#define ADC_ANA2_S10    0x0200
#define ADC_ANA3_S10    0x0300
#define ADC_ANA4_S10    0x0400
#define ADC_ANA5_S10    0x0500
#define ADC_ANA6_S10    0x0600
#define ADC_ANA7_S10    0x0700
#define ADC_ANB0_S10    0x0800
#define ADC_ANB1_S10    0x0900
#define ADC_ANB2_S10    0x0A00
#define ADC_ANB3_S10    0x0B00
#define ADC_ANB4_S10    0x0C00
#define ADC_ANB5_S10    0x0D00
#define ADC_ANB6_S10    0x0E00
#define ADC_ANB7_S10    0x0F00
/* sample 11 */              
#define ADC_ANA0_S11    0x0000
#define ADC_ANA1_S11    0x1000
#define ADC_ANA2_S11    0x2000
#define ADC_ANA3_S11    0x3000
#define ADC_ANA4_S11    0x4000
#define ADC_ANA5_S11    0x5000
#define ADC_ANA6_S11    0x6000
#define ADC_ANA7_S11    0x7000
#define ADC_ANB0_S11    0x8000
#define ADC_ANB1_S11    0x9000
#define ADC_ANB2_S11    0xA000
#define ADC_ANB3_S11    0xB000
#define ADC_ANB4_S11    0xC000
#define ADC_ANB5_S11    0xD000
#define ADC_ANB6_S11    0xE000
#define ADC_ANB7_S11    0xF000
/* sample 12 */        
#define ADC_ANA0_S12    0x0000
#define ADC_ANA1_S12    0x0001
#define ADC_ANA2_S12    0x0002
#define ADC_ANA3_S12    0x0003
#define ADC_ANA4_S12    0x0004
#define ADC_ANA5_S12    0x0005
#define ADC_ANA6_S12    0x0006
#define ADC_ANA7_S12    0x0007
#define ADC_ANB0_S12    0x0008
#define ADC_ANB1_S12    0x0009
#define ADC_ANB2_S12    0x000A
#define ADC_ANB3_S12    0x000B
#define ADC_ANB4_S12    0x000C
#define ADC_ANB5_S12    0x000D
#define ADC_ANB6_S12    0x000E
#define ADC_ANB7_S12    0x000F
/* sample 13 */        
#define ADC_ANA0_S13    0x0000
#define ADC_ANA1_S13    0x0010
#define ADC_ANA2_S13    0x0020
#define ADC_ANA3_S13    0x0030
#define ADC_ANA4_S13    0x0040
#define ADC_ANA5_S13    0x0050
#define ADC_ANA6_S13    0x0060
#define ADC_ANA7_S13    0x0070
#define ADC_ANB0_S13    0x0080
#define ADC_ANB1_S13    0x0090
#define ADC_ANB2_S13    0x00A0
#define ADC_ANB3_S13    0x00B0
#define ADC_ANB4_S13    0x00C0
#define ADC_ANB5_S13    0x00D0
#define ADC_ANB6_S13    0x00E0
#define ADC_ANB7_S13    0x00F0
/* sample 14 */              
#define ADC_ANA0_S14    0x0000
#define ADC_ANA1_S14    0x0100
#define ADC_ANA2_S14    0x0200
#define ADC_ANA3_S14    0x0300
#define ADC_ANA4_S14    0x0400
#define ADC_ANA5_S14    0x0500
#define ADC_ANA6_S14    0x0600
#define ADC_ANA7_S14    0x0700
#define ADC_ANB0_S14    0x0800
#define ADC_ANB1_S14    0x0900
#define ADC_ANB2_S14    0x0A00
#define ADC_ANB3_S14    0x0B00
#define ADC_ANB4_S14    0x0C00
#define ADC_ANB5_S14    0x0D00
#define ADC_ANB6_S14    0x0E00
#define ADC_ANB7_S14    0x0F00
/* sample 15 */              
#define ADC_ANA0_S15    0x0000
#define ADC_ANA1_S15    0x1000
#define ADC_ANA2_S15    0x2000
#define ADC_ANA3_S15    0x3000
#define ADC_ANA4_S15    0x4000
#define ADC_ANA5_S15    0x5000
#define ADC_ANA6_S15    0x6000
#define ADC_ANA7_S15    0x7000
#define ADC_ANB0_S15    0x8000
#define ADC_ANB1_S15    0x9000
#define ADC_ANB2_S15    0xA000
#define ADC_ANB3_S15    0xB000
#define ADC_ANB4_S15    0xC000
#define ADC_ANB5_S15    0xD000
#define ADC_ANB6_S15    0xE000
#define ADC_ANB7_S15    0xF000
#endif                 

#if ADC_VERSION >= 7
/* SAMPLE16 */
#define ADCA_TEMPERATURE_SENSOR_S16     0x0000UL
#define ADCA_ANALOG_INPUT_S16           0x0001UL
#define ADCB_TEMPERATURE_SENSOR_S16     0x0002UL
#define ADCB_ANALOG_INPUT_S16           0x0003UL
/* SAMPLE17 */
#define ADCA_TEMPERATURE_SENSOR_S17     0x0000UL
#define ADCA_ANALOG_INPUT_S17           0x0004UL
#define ADCB_TEMPERATURE_SENSOR_S17     0x0008UL
#define ADCB_ANALOG_INPUT_S17           0x000CUL
/* SAMPLE18 */
#define ADCA_TEMPERATURE_SENSOR_S18     0x0000UL
#define ADCA_ANALOG_INPUT_S18           0x0010UL
#define ADCB_TEMPERATURE_SENSOR_S18     0x0020UL
#define ADCB_ANALOG_INPUT_S18           0x0030UL
/* SAMPLE19 */
#define ADCA_TEMPERATURE_SENSOR_S19     0x0000UL
#define ADCA_ANALOG_INPUT_S19           0x0040UL
#define ADCB_TEMPERATURE_SENSOR_S19     0x0080UL
#define ADCB_ANALOG_INPUT_S19           0x00C0UL
#endif

/****************************************************************************
* register and bit names used in the ioctl functions below
*****************************************************************************/

/* control register (ADCR1) */
#if ADC_VERSION >= 6
#define ADC_ADCR1_DMAEN0               0x8000
#endif
#define ADC_ADCR1_STOP                 0x4000
#define ADC_ADCR1_START                0x2000
#define ADC_ADCR1_SYNC                 0x1000
#define ADC_ADCR1_EOSIE                0x0800    
#define ADC_ADCR1_ZCIE                 0x0400    
#define ADC_ADCR1_LLMTIE               0x0200
#define ADC_ADCR1_HLMTIE               0x0100
#define ADC_ADCR1_SMODE_MASK           0x0007
#define ADC_ADCR1_SMODE_ONCESEQ        0x0000
#define ADC_ADCR1_SMODE_ONCESIM        0x0001
#define ADC_ADCR1_SMODE_LOOPSEQ        0x0002
#define ADC_ADCR1_SMODE_LOOPSIM        0x0003
#define ADC_ADCR1_SMODE_TRIGSEQ        0x0004
#define ADC_ADCR1_SMODE_TRIGSIM        0x0005
#if ADC_VERSION == 1
#define ADC_ADCR1_CHNCFG_MASK          0x00f0
#define ADC_ADCR1_CHNCFG_AN01_DIFF     0x0010
#define ADC_ADCR1_CHNCFG_AN23_DIFF     0x0020
#define ADC_ADCR1_CHNCFG_AN45_DIFF     0x0040
#define ADC_ADCR1_CHNCFG_AN67_DIFF     0x0080
#elif ADC_VERSION == 2
#define ADC_ADCR1_CHNCFG_MASK          0x00f0
#define ADC_ADCR1_CHNCFG_ANA01_DIFF    0x0010
#define ADC_ADCR1_CHNCFG_ANA23_DIFF    0x0020
#define ADC_ADCR1_CHNCFG_ANB01_DIFF    0x0040
#define ADC_ADCR1_CHNCFG_ANB23_DIFF    0x0080
#else /* ADC_VERSION >= 3 */
#define ADC_ADCR1_CHNCFG_L_MASK        0x00f0
#define ADC_ADCR1_CHNCFG_L_ANA01_DIFF  0x0010
#define ADC_ADCR1_CHNCFG_L_ANA23_DIFF  0x0020
#define ADC_ADCR1_CHNCFG_L_ANB01_DIFF  0x0040
#define ADC_ADCR1_CHNCFG_L_ANB23_DIFF  0x0080
#endif

/* control register (ADCR2) */
#if ADC_VERSION <= 5
#define ADC_ADCR2_DIV_MASK             0x001f
#if ADC_VERSION >= 2
#define ADC_ADCR2_STOP                 0x4000
#define ADC_ADCR2_START                0x2000
#define ADC_ADCR2_SYNC                 0x1000
#define ADC_ADCR2_EOSIE                0x0800    
#define ADC_ADCR2_SIMULT               0x0020
#endif
#if ADC_VERSION >= 3
#define ADC_ADCR2_CHNCFG_H_MASK        0x03c0
#define ADC_ADCR2_CHNCFG_H_ANA45_DIFF  0x0040
#define ADC_ADCR2_CHNCFG_H_ANA67_DIFF  0x0080
#define ADC_ADCR2_CHNCFG_H_ANB45_DIFF  0x0100
#define ADC_ADCR2_CHNCFG_H_ANB67_DIFF  0x0200
#endif

#else /* ADC_VERSION >= 6 */
#define ADC_ADCR2_DMAEN1               0x8000
#define ADC_ADCR2_STOP                 0x4000
#define ADC_ADCR2_START                0x2000
#define ADC_ADCR2_SYNC                 0x1000
#define ADC_ADCR2_EOSIE                0x0800    
#define ADC_ADCR2_SIMULT               0x0040
#define ADC_ADCR2_DIV_MASK             0x003f
#define ADC_ADCR2_CHNCFG_H_MASK        0x0780
#define ADC_ADCR2_CHNCFG_H_ANA45_DIFF  0x0080
#define ADC_ADCR2_CHNCFG_H_ANA67_DIFF  0x0100
#define ADC_ADCR2_CHNCFG_H_ANB45_DIFF  0x0200
#define ADC_ADCR2_CHNCFG_H_ANB67_DIFF  0x0400
#define ADC_ADCR3_DMASRC               0x0040
#define ADC_ADCR3_SCNT1                0x0038
#define ADC_ADCR3_SCNT0                0x0007
#define ADC_ADCR3_UPDEN_L_H_MASK       0xff00
#endif

/* sample disable register (ADSDIS) */
#define ADC_ADSDIS_DS0            0x0001
#define ADC_ADSDIS_DS1            0x0002
#define ADC_ADSDIS_DS2            0x0004
#define ADC_ADSDIS_DS3            0x0008
#define ADC_ADSDIS_DS4            0x0010
#define ADC_ADSDIS_DS5            0x0020
#define ADC_ADSDIS_DS6            0x0040
#define ADC_ADSDIS_DS7            0x0080
#if ADC_VERSION >= 3
#define ADC_ADSDIS_DS8            0x0100
#define ADC_ADSDIS_DS9            0x0200
#define ADC_ADSDIS_DS10           0x0400
#define ADC_ADSDIS_DS11           0x0800
#define ADC_ADSDIS_DS12           0x1000
#define ADC_ADSDIS_DS13           0x2000
#define ADC_ADSDIS_DS14           0x4000
#define ADC_ADSDIS_DS15           0x8000
#endif

#if ADC_VERSION >= 7
#define ADC_ADSDIS_DS19           0x00080000
#define ADC_ADSDIS_DS18           0x00040000
#define ADC_ADSDIS_DS17           0x00020000
#define ADC_ADSDIS_DS16    	  	  0x00010000	
#endif

/* status register ADSTAT */

#define ADC_ADSTAT_ZCI            0x0400    
#define ADC_ADSTAT_LLMTI          0x0200
#define ADC_ADSTAT_HLMTI          0x0100
#define ADC_ADSTAT_RDY7           0x0080
#define ADC_ADSTAT_RDY6           0x0040
#define ADC_ADSTAT_RDY5           0x0020
#define ADC_ADSTAT_RDY4           0x0010
#define ADC_ADSTAT_RDY3           0x0008
#define ADC_ADSTAT_RDY2           0x0004
#define ADC_ADSTAT_RDY1           0x0002
#define ADC_ADSTAT_RDY0           0x0001
#if ADC_VERSION == 1
#define ADC_ADSTAT_CIP            0x8000    
#define ADC_ADSTAT_EOSI           0x0800    
#else /* ADC_VERSION >= 2 */
#define ADC_ADSTAT_CIP0           0x8000    
#define ADC_ADSTAT_EOSI0          0x0800    
#define ADC_ADSTAT_CIP1           0x4000    
#define ADC_ADSTAT_EOSI1          0x1000    
#endif

#if ADC_VERSION <= 5
/* limit status register ADLSTAT */
#define ADC_ADLSTAT_HLS7          0x8000
#define ADC_ADLSTAT_HLS6          0x4000
#define ADC_ADLSTAT_HLS5          0x2000
#define ADC_ADLSTAT_HLS4          0x1000
#define ADC_ADLSTAT_HLS3          0x0800
#define ADC_ADLSTAT_HLS2          0x0400
#define ADC_ADLSTAT_HLS1          0x0200
#define ADC_ADLSTAT_HLS0          0x0100
#define ADC_ADLSTAT_LLS7          0x0080
#define ADC_ADLSTAT_LLS6          0x0040
#define ADC_ADLSTAT_LLS5          0x0020
#define ADC_ADLSTAT_LLS4          0x0010
#define ADC_ADLSTAT_LLS3          0x0008
#define ADC_ADLSTAT_LLS2          0x0004
#define ADC_ADLSTAT_LLS1          0x0002
#define ADC_ADLSTAT_LLS0          0x0001
#else /* ADC_VERSION >= 6 */
/* low limit status register lolimstat */
#define ADC_ADLSTAT_LLS15         0x8000
#define ADC_ADLSTAT_LLS14         0x4000
#define ADC_ADLSTAT_LLS13         0x2000
#define ADC_ADLSTAT_LLS12         0x1000
#define ADC_ADLSTAT_LLS11         0x0800
#define ADC_ADLSTAT_LLS10         0x0400
#define ADC_ADLSTAT_LLS9          0x0200
#define ADC_ADLSTAT_LLS8          0x0100
#define ADC_ADLSTAT_LLS7          0x0080
#define ADC_ADLSTAT_LLS6          0x0040
#define ADC_ADLSTAT_LLS5          0x0020
#define ADC_ADLSTAT_LLS4          0x0010
#define ADC_ADLSTAT_LLS3          0x0008
#define ADC_ADLSTAT_LLS2          0x0004
#define ADC_ADLSTAT_LLS1          0x0002
#define ADC_ADLSTAT_LLS0          0x0001
#if ADC_VERSION >= 7
#define ADC_ADLSTAT_LLS19         0x0008
#define ADC_ADLSTAT_LLS18         0x0004
#define ADC_ADLSTAT_LLS17         0x0002
#define ADC_ADLSTAT_LLS16         0x0001	
#endif

/* high limit status register hilimstat */
#define ADC_ADLSTAT_HLS15         0x8000
#define ADC_ADLSTAT_HLS14         0x4000
#define ADC_ADLSTAT_HLS13         0x2000
#define ADC_ADLSTAT_HLS12         0x1000
#define ADC_ADLSTAT_HLS11         0x0800
#define ADC_ADLSTAT_HLS10         0x0400
#define ADC_ADLSTAT_HLS9          0x0200
#define ADC_ADLSTAT_HLS8          0x0100
#define ADC_ADLSTAT_HLS7          0x0080
#define ADC_ADLSTAT_HLS6          0x0040
#define ADC_ADLSTAT_HLS5          0x0020
#define ADC_ADLSTAT_HLS4          0x0010
#define ADC_ADLSTAT_HLS3          0x0008
#define ADC_ADLSTAT_HLS2          0x0004
#define ADC_ADLSTAT_HLS1          0x0002
#define ADC_ADLSTAT_HLS0          0x0001
#endif /* ADC_VERSION >= 6 */
#if ADC_VERSION >= 7
#define ADC_ADLSTAT_HLS19         0x0008
#define ADC_ADLSTAT_HLS18         0x0004
#define ADC_ADLSTAT_HLS17         0x0002
#define ADC_ADLSTAT_HLS16         0x0001	
#endif

/* zero cross status register ZCSTAT */
#if ADC_VERSION >= 6
#define ADC_ADZCSTAT_ZCS15         0x8000
#define ADC_ADZCSTAT_ZCS14         0x4000
#define ADC_ADZCSTAT_ZCS13         0x2000
#define ADC_ADZCSTAT_ZCS12         0x1000
#define ADC_ADZCSTAT_ZCS11         0x0800
#define ADC_ADZCSTAT_ZCS10         0x0400
#define ADC_ADZCSTAT_ZCS9          0x0200
#define ADC_ADZCSTAT_ZCS8          0x0100
#endif

#define ADC_ADZCSTAT_ZCS7          0x0080
#define ADC_ADZCSTAT_ZCS6          0x0040
#define ADC_ADZCSTAT_ZCS5          0x0020
#define ADC_ADZCSTAT_ZCS4          0x0010
#define ADC_ADZCSTAT_ZCS3          0x0008
#define ADC_ADZCSTAT_ZCS2          0x0004
#define ADC_ADZCSTAT_ZCS1          0x0002
#define ADC_ADZCSTAT_ZCS0          0x0001

#if ADC_VERSION >= 7
#define ADC_ADZCSTAT_ZCS19         0x0008
#define ADC_ADZCSTAT_ZCS18         0x0004
#define ADC_ADZCSTAT_ZCS17         0x0002
#define ADC_ADZCSTAT_ZCS16         0x0001	
#endif

/* power control register ADCPOWER */
#define ADC_ADCPOWER_PSTS2        0x1000
#define ADC_ADCPOWER_PSTS1        0x0800
#define ADC_ADCPOWER_PSTS0        0x0400
#define ADC_ADCPOWER_PUDELAY_MASK 0x03f0
#define ADC_ADCPOWER_PSM          0x0008
#define ADC_ADCPOWER_PD2          0x0004
#define ADC_ADCPOWER_PD1          0x0002
#define ADC_ADCPOWER_PD0          0x0001
#if ADC_VERSION >= 2
#define ADC_ADCPOWER_ASB          0x8000
#define ADC_ADCPOWER_APD          0x0008
#endif

/* calibration register ADC_CAL */
#if ADC_VERSION == 1
#define ADC_CAL_CRS1              0x0008
#define ADC_CAL_CAL1              0x0004
#define ADC_CAL_CRS0              0x0002
#define ADC_CAL_CAL0              0x0001
#endif
#if ADC_VERSION == 2
#define ADC_CAL_SEL_VREFH         0x8000
#define ADC_CAL_SEL_VREFLO        0x4000
#endif
#if ADC_VERSION >= 3
#define ADC_CAL_SEL_VREFH1        0x8000
#define ADC_CAL_SEL_VREFLO1       0x4000
#define ADC_CAL_SEL_VREFH0        0x2000
#define ADC_CAL_SEL_VREFLO0       0x1000
#define ADC_CAL_SEL_TEST1         0x0008
#define ADC_CAL_SEL_TEST0         0x0004
#define ADC_CAL_SEL_DAC1          0x0002
#define ADC_CAL_SEL_DAC0          0x0001
#endif
#if ADC_VERSION >= 5
#define ADC_GC1_GAINA7_MASK        0xC000
#define ADC_GC1_GAINA6_MASK        0x3000
#define ADC_GC1_GAINA5_MASK        0x0C00
#define ADC_GC1_GAINA4_MASK        0x0300
#define ADC_GC1_GAINA3_MASK        0x00C0
#define ADC_GC1_GAINA2_MASK        0x0030
#define ADC_GC1_GAINA1_MASK        0x000C
#define ADC_GC1_GAINA0_MASK        0x0003
#define ADC_GC2_GAINB7_MASK       0xC000
#define ADC_GC2_GAINB6_MASK       0x3000
#define ADC_GC2_GAINB5_MASK       0x0C00
#define ADC_GC2_GAINB4_MASK       0x0300
#define ADC_GC2_GAINB3_MASK       0x00C0
#define ADC_GC2_GAINB2_MASK       0x0030
#define ADC_GC2_GAINB1_MASK        0x000C
#define ADC_GC2_GAINB0_MASK        0x0003
#define ADC_PWR2_DIV_MASK         0x1F00
#define ADC_PWR2_SPEEDB_MASK      0x000C
#define ADC_PWR2_SPEEDA_MASK      0x0003
#endif

#if ADC_VERSION >= 7
#define ADC_GC3_GAINB10_MASK      0x00C0
#define ADC_GC3_GAINB9_MASK       0x0030
#define ADC_GC3_GAINA10_MASK      0x000C
#define ADC_GC3_GAINA9_MASK       0x0003
#endif

#if ADC_VERSION >= 6 
#undef ADC_PWR2_DIV_MASK
#define ADC_PWR2_DIV_MASK         0x3F00
#endif
#if ADC_VERSION >= 7 
#undef ADC_PWR2_SPEEDA_MASK		   
#undef ADC_PWR2_SPEEDB_MASK		   
#endif
/* ADC Control Register 3 ADCx_PRW2 */
#if ADC_VERSION >= 6 
#define ADC_PWR2_SPEEDB_MASK      0x000C
#define ADC_PWR2_SPEEDA_MASK      0x0003
#endif
#if ADC_VERSION >= 7
#define ADC_ANA0_ANA1_FULLY_DIFF    0x0100
#define ADC_ANA0_ANA1_UNIPOLAR_DIFF	  0x0101
#define ADC_ANA2_ANA3_FULLY_DIFF    0x0200
#define ADC_ANA2_ANA3_UNIPOLAR_DIFF	  0x0202
#define ADC_ANB0_ANB1_FULLY_DIFF    0x0400
#define ADC_ANB0_ANB1_UNIPOLAR_DIFF	  0x0404
#define ADC_ANB2_ANB3_FULLY_DIFF    0x0800
#define ADC_ANB2_ANB3_UNIPOLAR_DIFF	  0x0808
#define ADC_ANA4_ANA5_FULLY_DIFF    0x1000
#define ADC_ANA4_ANA5_UNIPOLAR_DIFF	  0x1010
#define ADC_ANA6_ANA7_FULLY_DIFF    0x2000
#define ADC_ANA6_ANA7_UNIPOLAR_DIFF	  0x2020
#define ADC_ANB4_ANB5_FULLY_DIFF    0x4000
#define ADC_ANB4_ANB5_UNIPOLAR_DIFF	  0x4040
#define ADC_ANB6_ANB7_FULLY_DIFF    0x8000
#define ADC_ANB6_ANB7_UNIPOLAR_DIFF	  0x8080
#endif

/* ADC Channel List Register 5 (ADC_CLIST5) */
#if ADC_VERSION >= 7
#define ADC_WRITE_CHANNEL_LIST5 	/*ADCA_TEMPERATURE_SENSOR_S16|ADCA_ANALOG_INPUT_S16|ADCB_TEMPERATURE_SENSOR_S16|ADCB_ANALOG_INPUT_S16|ADCA_TEMPERATURE_SENSOR_S17|ADCA_ANALOG_INPUT_S17|ADCB_TEMPERATURE_SENSOR_S17|ADCB_ANALOG_INPUT_S17|ADCA_TEMPERATURE_SENSOR_S18|ADCA_ANALOG_INPUT_S18|ADCB_TEMPERATURE_SENSOR_S18|ADCB_ANALOG_INPUT_S18|ADCA_TEMPERATURE_SENSOR_S19|ADCA_ANALOG_INPUT_S19|ADCB_TEMPERATURE_SENSOR_S19|ADCB_ANALOG_INPUT_S19,write ADC channel list 5 register. Modify the ADC Channel List Register 5 (ADC_CLIST5->_) */
#define ADC_SET_LIST_SAMPLE16       /*ADCA_TEMPERATURE_SENSOR/ADCA_ANALOG_INPUT/ADCB_TEMPERATURE_SENSOR/ADCB_ANALOG_INPUT,write ADC channel list 5 register Sample Field 16. Modify the ADC Channel List Register 5 (ADC_CLIST5->SAMPLE16[0-1]) */
#define ADC_SET_LIST_SAMPLE17       /*ADCA_TEMPERATURE_SENSOR/ADCA_ANALOG_INPUT/ADCB_TEMPERATURE_SENSOR/ADCB_ANALOG_INPUT,write ADC channel list 5 register Sample Field 17. Modify the ADC Channel List Register 5 (ADC_CLIST5->SAMPLE16[2-3]) */
#define ADC_SET_LIST_SAMPLE18       /*ADCA_TEMPERATURE_SENSOR/ADCA_ANALOG_INPUT/ADCB_TEMPERATURE_SENSOR/ADCB_ANALOG_INPUT,write ADC channel list 5 register Sample Field 18. Modify the ADC Channel List Register 5 (ADC_CLIST5->SAMPLE16[4-5]) */
#define ADC_SET_LIST_SAMPLE19       /*ADCA_TEMPERATURE_SENSOR/ADCA_ANALOG_INPUT/ADCB_TEMPERATURE_SENSOR/ADCB_ANALOG_INPUT,write ADC channel list 5 register Sample Field 19. Modify the ADC Channel List Register 5 (ADC_CLIST5->SAMPLE16[6-7]) */
#define ADC_SET_ADCA6_INPUT       	/*ADC_ANALOG_INPUT|ADC_NORMAL_OPERATION,set On-Chip Analog Input Alternate Source  in ADC Channel List Register 5 (ADC_CLIST5->SEL_TEMP_0[8]) */
#define ADC_SET_ADCA7_INPUT       	/*ADC_TEMPERATURE_SENSOR|ADC_NORMAL_OPERATION,set On-Chip Analog Input Alternate Source  in ADC Channel List Register 5 (ADC_CLIST5->SEL_INTERNAL_0[9]) */
#define ADC_SET_ADCB6_INPUT       	/*ADC_ANALOG_INPUT|ADC_NORMAL_OPERATION,set On-Chip Analog Input Alternate Source  in ADC Channel List Register 5 (ADC_CLIST5->SEL_TEMP_1[10]) */
#define ADC_SET_ADCB7_INPUT       	/*ADC_TEMPERATURE_SENSOR|ADC_NORMAL_OPERATION,set On-Chip Analog Input Alternate Source  in ADC Channel List Register 5 (ADC_CLIST5->SEL_INTERNAL_1[11]) */
#endif

/* results buffer */
#if ADC_VERSION <= 5
  typedef UWord16 adc_tBuff[8];
#else
  typedef UWord16 adc_tBuff[16];
#endif
/****************************************************************************
* ADC ioctl macro implementation
*****************************************************************************/

/***********************************************************************
* ADC init
***********************************************************************/

void adcInit(arch_sADC *pAdcBase);
#define ioctlADC_INIT(pAdcBase, param) adcInit(pAdcBase)

/***********************************************************************
* ADC Control Register
***********************************************************************/

/* start ADC conversion */
#ifdef ADC_VERSION_1

/* start ADC conversion */
#define ioctlADC_START(pAdcBase, param) \
  periphBitSet(ADC_ADCR1_START, &((pAdcBase)->adctl1))
                      
/* stop ADC conversion */
#define ioctlADC_STOP(pAdcBase, param) \
 if (param) periphBitSet(ADC_ADCR1_STOP, &((pAdcBase)->adctl1)); \
 else periphBitClear(ADC_ADCR1_STOP, &((pAdcBase)->adctl1))
 
/* switch on/off ADC conversion starting by SYNC (spec. timer output) */
#define ioctlADC_SYNC(pAdcBase, param) \
 if (param) periphBitSet(ADC_ADCR1_SYNC, &((pAdcBase)->adctl1)); \
 else periphBitClear(ADC_ADCR1_SYNC, &((pAdcBase)->adctl1))

/* enable/disable interrupt on the end of the ADC conversion */
#define ioctlADC_END_OF_SCAN_INT(pAdcBase, param) \
  if (param) periphBitSet(ADC_ADCR1_EOSIE, &((pAdcBase)->adctl1)); \
  else periphBitClear(ADC_ADCR1_EOSIE, &((pAdcBase)->adctl1))

/* enable interrupts */
#define ioctlADC_INT_ENABLE(pAdcBase, param)        \
  periphBitSet(param, &((pAdcBase)->adctl1))

/* enable interrupts */
#define ioctlADC_INT_DISABLE(pAdcBase, param)       \
  periphBitClear(param, &((pAdcBase)->adctl1))

/* test if given interrupts are enabled */
#define ioctlADC_TEST_INT_ENABLED(pAdcBase, param)  \
  periphBitTest(param, &((pAdcBase)->adctl1))

/* enable interrupts */
#define ioctlADC_INT_SELECT(pAdcBase, param)        \
  periphBitGrpRS (ADC_ADCR1_EOSIE | ADC_ADCR1_ZCIE | ADC_ADCR1_LLMTIE | ADC_ADCR1_HLMTIE, \
    param, &((pAdcBase)->adctl1))
  
#else /* ADC_VERSION >= 2 */
#if ADC_VERSION >= 6
#define ioctlADC_DMAEN(pAdcBase, param) \
  if((((UWord16)(param)) == ADC_CONVERTER_0) || (((UWord16)(param)) == 0)) \
    periphBitSet(ADC_ADCR1_DMAEN0, &((pAdcBase)->adctl1)); \
  else if(((UWord16)(param)) == ADC_CONVERTER_1) \
    periphBitSet(ADC_ADCR2_DMAEN1, &((pAdcBase)->adctl2))
#endif

#define ioctlADC_START(pAdcBase, param) \
  if((((UWord16)(param)) == ADC_CONVERTER_0) || (((UWord16)(param)) == 0)) \
    periphBitSet(ADC_ADCR1_START, &((pAdcBase)->adctl1)); \
  else if(((UWord16)(param)) == ADC_CONVERTER_1) \
    periphBitSet(ADC_ADCR2_START, &((pAdcBase)->adctl2))
                      
/* stop ADC conversion */
#define ioctlADC_STOP(pAdcBase, param) \
if((param) & 0x10) \
    if((param) & 0x1) periphBitSet(ADC_ADCR2_STOP, &((pAdcBase)->adctl2)); \
    else periphBitClear(ADC_ADCR2_STOP, &((pAdcBase)->adctl2)); \
else \
    if((param) & 0x1) periphBitSet(ADC_ADCR1_STOP, &((pAdcBase)->adctl1)); \
    else periphBitClear(ADC_ADCR1_STOP, &((pAdcBase)->adctl1))
 
/* switch on/off ADC conversion starting by SYNC (spec. timer output) */
#define ioctlADC_SYNC(pAdcBase, param) \
if((param) & 0x10) \
    if ((param) & 0x1) periphBitSet(ADC_ADCR2_SYNC, &((pAdcBase)->adctl2)); \
    else periphBitClear(ADC_ADCR2_SYNC, &((pAdcBase)->adctl2)); \
else \
    if((param) & 0x1) periphBitSet(ADC_ADCR1_SYNC, &((pAdcBase)->adctl1)); \
    else periphBitClear(ADC_ADCR1_SYNC, &((pAdcBase)->adctl1))

/* enable/disable interrupt on the end of the ADC conversion */
#define ioctlADC_END_OF_SCAN_INT(pAdcBase, param) \
if ((param) & 0x10) \
  if ((param) & 0x1) periphBitSet(ADC_ADCR2_EOSIE, &((pAdcBase)->adctl2)); \
  else periphBitClear(ADC_ADCR2_EOSIE, &((pAdcBase)->adctl2)); \
else \
  if ((param) & 0x1) periphBitSet(ADC_ADCR1_EOSIE, &((pAdcBase)->adctl1)); \
  else periphBitClear(ADC_ADCR1_EOSIE, &((pAdcBase)->adctl1))

/* enable interrupts */
#define ioctlADC_INT_ENABLE(pAdcBase, param) { \
  if((param) & (ADC_ADCR1_EOSIE | ADC_ADCR1_ZCIE | ADC_ADCR1_LLMTIE | ADC_ADCR1_HLMTIE)) \
    periphBitSet ((param) & (ADC_ADCR1_EOSIE | ADC_ADCR1_ZCIE | ADC_ADCR1_LLMTIE | ADC_ADCR1_HLMTIE), &((pAdcBase)->adctl1)); \
  if(((param) >> 16) & (ADC_ADCR2_EOSIE)) \
    periphBitSet (((param) >> 16) & (ADC_ADCR2_EOSIE), &((pAdcBase)->adctl2)); }

/* disable interrupts */
#define ioctlADC_INT_DISABLE(pAdcBase, param) { \
  if((param) & (ADC_ADCR1_EOSIE | ADC_ADCR1_ZCIE | ADC_ADCR1_LLMTIE | ADC_ADCR1_HLMTIE)) \
    periphBitClear ((param) & (ADC_ADCR1_EOSIE | ADC_ADCR1_ZCIE | ADC_ADCR1_LLMTIE | ADC_ADCR1_HLMTIE), &((pAdcBase)->adctl1)); \
  if(((param) >> 16) & (ADC_ADCR2_EOSIE)) \
    periphBitClear (((param) >> 16) & (ADC_ADCR2_EOSIE), &((pAdcBase)->adctl2)); }

/* test if given interrupts are enabled */
#define ioctlADC_TEST_INT_ENABLED(pAdcBase, param) ( \
  ( ((param) & (ADC_ADCR1_EOSIE | ADC_ADCR1_ZCIE | ADC_ADCR1_LLMTIE | ADC_ADCR1_HLMTIE)) ? \
    periphBitTest (((UWord16)(param)) & (ADC_ADCR1_EOSIE | ADC_ADCR1_ZCIE | ADC_ADCR1_LLMTIE | ADC_ADCR1_HLMTIE), &((pAdcBase)->adctl1)) : 0 ) | \
  ( (((param) >> 16) & (ADC_ADCR2_EOSIE)) ? \
    periphBitTest (((UWord16)((param) >> 16)) & (ADC_ADCR2_EOSIE), &((pAdcBase)->adctl2)) : 0 ) )

/* enable/disable interrupts */
#define ioctlADC_INT_SELECT(pAdcBase, param) { \
  periphBitGrpRS (ADC_ADCR1_EOSIE | ADC_ADCR1_ZCIE | ADC_ADCR1_LLMTIE | ADC_ADCR1_HLMTIE, param, &((pAdcBase)->adctl1)); \
  periphBitGrpRS (ADC_ADCR2_EOSIE, (param) >> 16, &((pAdcBase)->adctl2)); }

#endif  /* ADC_VERSION */
  
/* enable/disable interrupt on ADC zero crossing */
#define ioctlADC_ZERO_CROSS_INT(pAdcBase, param) \
  if (param) periphBitSet(ADC_ADCR1_ZCIE, &((pAdcBase)->adctl1)); \
  else periphBitClear(ADC_ADCR1_ZCIE, &((pAdcBase)->adctl1))
  
/* enable/disable interrupt on ADC low limit compare */
#define ioctlADC_LOW_LIMIT_INT(pAdcBase, param) \
 if (param) periphBitSet(ADC_ADCR1_LLMTIE, &((pAdcBase)->adctl1)); \
 else periphBitClear(ADC_ADCR1_LLMTIE, &((pAdcBase)->adctl1))
 
/* enable/disable interrupt on ADC high limit compare */
#define ioctlADC_HIGH_LIMIT_INT(pAdcBase, param) \
 if (param) periphBitSet(ADC_ADCR1_HLMTIE, &((pAdcBase)->adctl1)); \
 else periphBitClear(ADC_ADCR1_HLMTIE, &((pAdcBase)->adctl1))

/* write to CHNCFG[3:0] bits in ADCR1 */
#if ADC_VERSION <= 2

#define ioctlADC_SET_CHANNEL_CONFIG(pAdcBase, param) \
  periphBitGrpSet(ADC_ADCR1_CHNCFG_MASK & (((param)>>8)<<4), (param)<<4, &((pAdcBase)->adctl1))
  
#elif ADC_VERSION <= 5 /* 5 <= ADC_VERSION >= 3 */

#define ioctlADC_SET_CHANNEL_CONFIG(pAdcBase, param) { \
    if((param) & 0x0f00) periphBitGrpSet(ADC_ADCR1_CHNCFG_L_MASK & ((param)>>(8-4)), (param)<<4, &((pAdcBase)->adctl1)); \
    if((param) & 0xf000) periphBitGrpSet(ADC_ADCR2_CHNCFG_H_MASK & ((param)>>(12-6)), (param)<<(6-4), &((pAdcBase)->adctl2)); \
  }  
#else /* ADC_VERSION >= 6 */

#define ioctlADC_SET_CHANNEL_CONFIG(pAdcBase, param) { \
    if((param) & 0x0f00) periphBitGrpSet(ADC_ADCR1_CHNCFG_L_MASK & ((param)>>(8-4)), ((param)<<4)&0xffff, &((pAdcBase)->adctl1)); \
    if((param) & 0xf000) periphBitGrpSet(ADC_ADCR2_CHNCFG_H_MASK & ((param)>>(12-7)), ((param)<<(7-4))&0xffff, &((pAdcBase)->adctl2)); \
}
#endif /* ADC_VERSION  */

/* write to SMODE[2:0] bits in ADCR1 */
#define ioctlADC_SET_SCAN_MODE(pAdcBase, param) \
  periphBitGrpSet(ADC_ADCR1_SMODE_MASK, param, &((pAdcBase)->adctl1))

/* set ADC clock divisor select */
#define ioctlADC_SET_DIVISOR(pAdcBase, param) \
  periphBitGrpSet(ADC_ADCR2_DIV_MASK, param, &((pAdcBase)->adctl2))

/* switch on/off parallel scan mode  */ 
#if ADC_VERSION >= 2
#define ioctlADC_SIMULT(pAdcBase, param) \
  if (param) periphBitSet(ADC_ADCR2_SIMULT, &((pAdcBase)->adctl2)); \
  else periphBitClear(ADC_ADCR2_SIMULT, &((pAdcBase)->adctl2))
#endif

/***********************************************************************
* ADC zero crossing register
***********************************************************************/

/* set ADC zero crossing control register */
#define ioctlADC_WRITE_ZERO_CROSS_CNTRL(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adzcc))

/* individual zero-cross settings for each channel (added) */
#define ioctlADC_ZERO_CROSS_CH0(pAdcBase, param) \
  periphBitGrpSet(3 << 0, ((param)<<0), &((pAdcBase)->adzcc))
#define ioctlADC_ZERO_CROSS_CH1(pAdcBase, param) \
  periphBitGrpSet(3 << 2, ((param)<<2), &((pAdcBase)->adzcc))
#define ioctlADC_ZERO_CROSS_CH2(pAdcBase, param) \
  periphBitGrpSet(3 << 4, ((param)<<4), &((pAdcBase)->adzcc))
#define ioctlADC_ZERO_CROSS_CH3(pAdcBase, param) \
  periphBitGrpSet(3 << 6, ((param)<<6), &((pAdcBase)->adzcc))
#define ioctlADC_ZERO_CROSS_CH4(pAdcBase, param) \
  periphBitGrpSet(3 << 8, ((param)<<8), &((pAdcBase)->adzcc))
#define ioctlADC_ZERO_CROSS_CH5(pAdcBase, param) \
  periphBitGrpSet(3 << 10, ((param)<<10), &((pAdcBase)->adzcc))
#define ioctlADC_ZERO_CROSS_CH6(pAdcBase, param) \
  periphBitGrpSet(3 << 12, ((param)<<12), &((pAdcBase)->adzcc))
#define ioctlADC_ZERO_CROSS_CH7(pAdcBase, param) \
  periphBitGrpSet(3 << 14, ((param)<<14), &((pAdcBase)->adzcc))

#if ADC_VERSION >= 6
#define ioctlADC_WRITE_ZERO_CROSS_CNTRL1(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->zxctrl1))
#define ioctlADC_WRITE_ZERO_CROSS_CNTRL2(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->zxctrl2))

#define ioctlADC_ZERO_CROSS_CH8(pAdcBase, param) \
  periphBitGrpSet(3 << 0, ((param)<<0), &((pAdcBase)->zxctrl2))
#define ioctlADC_ZERO_CROSS_CH9(pAdcBase, param) \
  periphBitGrpSet(3 << 2, ((param)<<2), &((pAdcBase)->zxctrl2))
#define ioctlADC_ZERO_CROSS_CH10(pAdcBase, param) \
  periphBitGrpSet(3 << 4, ((param)<<4), &((pAdcBase)->zxctrl2))
#define ioctlADC_ZERO_CROSS_CH11(pAdcBase, param) \
  periphBitGrpSet(3 << 6, ((param)<<6), &((pAdcBase)->zxctrl2))
#define ioctlADC_ZERO_CROSS_CH12(pAdcBase, param) \
  periphBitGrpSet(3 << 8, ((param)<<8), &((pAdcBase)->zxctrl2))
#define ioctlADC_ZERO_CROSS_CH13(pAdcBase, param) \
  periphBitGrpSet(3 << 10, ((param)<<10), &((pAdcBase)->zxctrl2))
#define ioctlADC_ZERO_CROSS_CH14(pAdcBase, param) \
  periphBitGrpSet(3 << 12, ((param)<<12), &((pAdcBase)->zxctrl2))
#define ioctlADC_ZERO_CROSS_CH15(pAdcBase, param) \
  periphBitGrpSet(3 << 14, ((param)<<14), &((pAdcBase)->zxctrl2))
#endif /*  ADC_VERSION >= 6 */

/* set ADC channel list register (end-of-life) */
#define ioctlADC_WRITE_CHANNEL_LIST1(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adlst1))
#define ioctlADC_WRITE_CHANNEL_LIST2(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adlst2))
#if ADC_VERSION >= 6
#define ioctlADC_WRITE_CHANNEL_LIST3(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adlst3))
#define ioctlADC_WRITE_CHANNEL_LIST4(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adlst4))
#endif

/* individual channel list manipulation for each channel (added) */
#define ioctlADC_SET_LIST_SAMPLE0(pAdcBase, param) \
  periphBitGrpSet(0xf << 0, ((param)<<0), &((pAdcBase)->adlst1))
#define ioctlADC_SET_LIST_SAMPLE1(pAdcBase, param) \
  periphBitGrpSet(0xf << 4, ((param)<<4), &((pAdcBase)->adlst1))
#define ioctlADC_SET_LIST_SAMPLE2(pAdcBase, param) \
  periphBitGrpSet(0xf << 8, ((param)<<8), &((pAdcBase)->adlst1))
#define ioctlADC_SET_LIST_SAMPLE3(pAdcBase, param) \
  periphBitGrpSet(0xf << 12, ((param)<<12), &((pAdcBase)->adlst1))
  
#define ioctlADC_SET_LIST_SAMPLE4(pAdcBase, param) \
  periphBitGrpSet(0xf << 0, ((param)<<0), &((pAdcBase)->adlst2))
#define ioctlADC_SET_LIST_SAMPLE5(pAdcBase, param) \
  periphBitGrpSet(0xf << 4, ((param)<<4), &((pAdcBase)->adlst2))
#define ioctlADC_SET_LIST_SAMPLE6(pAdcBase, param) \
  periphBitGrpSet(0xf << 8, ((param)<<8), &((pAdcBase)->adlst2))
#define ioctlADC_SET_LIST_SAMPLE7(pAdcBase, param) \
  periphBitGrpSet(0xf << 12, ((param)<<12), &((pAdcBase)->adlst2))

#if ADC_VERSION >= 3
#define ioctlADC_SET_LIST_SAMPLE8(pAdcBase, param) \
  periphBitGrpSet(0xf << 0, ((param)<<0), &((pAdcBase)->adlst3))
#define ioctlADC_SET_LIST_SAMPLE9(pAdcBase, param) \
  periphBitGrpSet(0xf << 4, ((param)<<4), &((pAdcBase)->adlst3))
#define ioctlADC_SET_LIST_SAMPLE10(pAdcBase, param) \
  periphBitGrpSet(0xf << 8, ((param)<<8), &((pAdcBase)->adlst3))
#define ioctlADC_SET_LIST_SAMPLE11(pAdcBase, param) \
  periphBitGrpSet(0xf << 12, ((param)<<12), &((pAdcBase)->adlst3))

#define ioctlADC_SET_LIST_SAMPLE12(pAdcBase, param) \
  periphBitGrpSet(0xf << 0, ((param)<<0), &((pAdcBase)->adlst4))
#define ioctlADC_SET_LIST_SAMPLE13(pAdcBase, param) \
  periphBitGrpSet(0xf << 4, ((param)<<4), &((pAdcBase)->adlst4))
#define ioctlADC_SET_LIST_SAMPLE14(pAdcBase, param) \
  periphBitGrpSet(0xf << 8, ((param)<<8), &((pAdcBase)->adlst4))
#define ioctlADC_SET_LIST_SAMPLE15(pAdcBase, param) \
  periphBitGrpSet(0xf << 12, ((param)<<12), &((pAdcBase)->adlst4))
#endif
  
/* ADC sample disable register */
#if ADC_VERSION == 1

#define ioctlADC_WRITE_SAMPLE_DISABLE(pAdcBase, param) \
  periphBitGrpSR(0x00FF, (1 << (param)), &((pAdcBase)->adsdis))

#elif ADC_VERSION == 2

#define ioctlADC_WRITE_SAMPLE_DISABLE(pAdcBase, param) \
  if((param) & 0x8000)\
    periphBitGrpSR(0x00FF, (0x00FF & (param)), &((pAdcBase)->adsdis)); \
  else \
    periphBitGrpSR(0x00FF, (1 << (param)), &((pAdcBase)->adsdis))

#else /* ADC_VERSION >= 3 */

#define ioctlADC_WRITE_SAMPLE_DISABLE(pAdcBase, param) \
  if((param) & 0xFFFF0000L)\
    periphBitGrpSR(0xFFFF, (0xFFFF & (param)), &((pAdcBase)->adsdis)); \
  else \
    periphBitGrpSR(0xFFFF, (1 << (param)), &((pAdcBase)->adsdis))

#endif /* ADC_VERSION */

/* write ADC low limit register x */
#define ioctlADC_WRITE_LOW_LIMIT0(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[0]))
#define ioctlADC_WRITE_LOW_LIMIT1(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[1]))
#define ioctlADC_WRITE_LOW_LIMIT2(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[2]))
#define ioctlADC_WRITE_LOW_LIMIT3(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[3]))
#define ioctlADC_WRITE_LOW_LIMIT4(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[4]))
#define ioctlADC_WRITE_LOW_LIMIT5(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[5]))
#define ioctlADC_WRITE_LOW_LIMIT6(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[6]))
#define ioctlADC_WRITE_LOW_LIMIT7(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[7]))

#if ADC_VERSION >= 6
#define ioctlADC_WRITE_LOW_LIMIT8(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[8]))
#define ioctlADC_WRITE_LOW_LIMIT9(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[9]))
#define ioctlADC_WRITE_LOW_LIMIT10(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[10]))
#define ioctlADC_WRITE_LOW_LIMIT11(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[11]))
#define ioctlADC_WRITE_LOW_LIMIT12(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[12]))
#define ioctlADC_WRITE_LOW_LIMIT13(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[13]))
#define ioctlADC_WRITE_LOW_LIMIT14(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[14]))
#define ioctlADC_WRITE_LOW_LIMIT15(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt[15]))
#endif /* ADC_VERSION >= 6 */

#if ADC_VERSION >= 7
#define ioctlADC_WRITE_LOW_LIMIT16(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt2[0]))
#define ioctlADC_WRITE_LOW_LIMIT17(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt2[1]))
#define ioctlADC_WRITE_LOW_LIMIT18(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt2[2]))
#define ioctlADC_WRITE_LOW_LIMIT19(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adllmt2[3]))
#endif /* ADC_VERSION >= 7 */

/* read ADC low limit register x */
#if ADC_VERSION >= 6
#define ioctlADC_READ_LOW_LIMIT(pAdcBase, param)  \
  periphMemRead(&((pAdcBase)->adllmt[param]))
#endif	
#if ADC_VERSION >= 7
#define ioctlADC_READ_LOW_LIMIT2(pAdcBase, param)\
  periphMemRead(&((pAdcBase)->adllmt2[param-16]))	
/* universal commands for old and new register */
#define ioctlADC_READ_LOW_LIMIT12(pAdcBase, param)  \
  (param <= 15) ? periphMemRead(&((pAdcBase)->adllmt[param])) : periphMemRead(&((pAdcBase)->adllmt2[param-16])); 
#endif		

/* set ADC high limit register x */
#define ioctlADC_WRITE_HIGH_LIMIT0(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[0]))
#define ioctlADC_WRITE_HIGH_LIMIT1(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[1]))
#define ioctlADC_WRITE_HIGH_LIMIT2(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[2]))
#define ioctlADC_WRITE_HIGH_LIMIT3(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[3]))
#define ioctlADC_WRITE_HIGH_LIMIT4(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[4]))
#define ioctlADC_WRITE_HIGH_LIMIT5(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[5]))
#define ioctlADC_WRITE_HIGH_LIMIT6(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[6]))
#define ioctlADC_WRITE_HIGH_LIMIT7(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[7]))

#if ADC_VERSION >= 6
#define ioctlADC_WRITE_HIGH_LIMIT8(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[8]))
#define ioctlADC_WRITE_HIGH_LIMIT9(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[9]))
#define ioctlADC_WRITE_HIGH_LIMIT10(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[10]))
#define ioctlADC_WRITE_HIGH_LIMIT11(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[11]))
#define ioctlADC_WRITE_HIGH_LIMIT12(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[12]))
#define ioctlADC_WRITE_HIGH_LIMIT13(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[13]))
#define ioctlADC_WRITE_HIGH_LIMIT14(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[14]))
#define ioctlADC_WRITE_HIGH_LIMIT15(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt[15]))
#endif /* ADC_VERSION >= 6 */

#if ADC_VERSION >= 7	
#define ioctlADC_WRITE_HIGH_LIMIT16(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt2[0]))
#define ioctlADC_WRITE_HIGH_LIMIT17(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt2[1]))
#define ioctlADC_WRITE_HIGH_LIMIT18(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt2[2]))
#define ioctlADC_WRITE_HIGH_LIMIT19(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adhlmt2[3]))	
#endif /* ADC_VERSION >= 7 */
	
/* read ADC high limit register x */
#if ADC_VERSION >= 6
#define ioctlADC_READ_HIGH_LIMIT(pAdcBase, param)  	\
  periphMemRead(&((pAdcBase)->adhlmt[param]))
#endif	
#if ADC_VERSION >= 7
#define ioctlADC_READ_HIGH_LIMIT2(pAdcBase, param)\
  periphMemRead(&((pAdcBase)->adhlmt2[param-16]))	
/* universal commands for old and new register */
#define ioctlADC_READ_HIGH_LIMIT12(pAdcBase, param)  \
  (param <= 15) ? periphMemRead(&((pAdcBase)->adhlmt[param])) : periphMemRead(&((pAdcBase)->adhlmt2[param-16])); 
#endif	
	
/* write ADC offset register x */
#define ioctlADC_WRITE_OFFSET0(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[0]))
#define ioctlADC_WRITE_OFFSET1(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[1]))
#define ioctlADC_WRITE_OFFSET2(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[2]))
#define ioctlADC_WRITE_OFFSET3(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[3]))
#define ioctlADC_WRITE_OFFSET4(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[4]))
#define ioctlADC_WRITE_OFFSET5(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[5]))
#define ioctlADC_WRITE_OFFSET6(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[6]))
#define ioctlADC_WRITE_OFFSET7(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[7]))

#if ADC_VERSION >= 6
#define ioctlADC_WRITE_OFFSET8(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[8]))
#define ioctlADC_WRITE_OFFSET9(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[9]))
#define ioctlADC_WRITE_OFFSET10(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[10]))
#define ioctlADC_WRITE_OFFSET11(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[11]))
#define ioctlADC_WRITE_OFFSET12(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[12]))
#define ioctlADC_WRITE_OFFSET13(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[13]))
#define ioctlADC_WRITE_OFFSET14(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[14]))
#define ioctlADC_WRITE_OFFSET15(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs[15]))
#endif /* ADC_VERSION >= 6 */

#if ADC_VERSION >= 7			
#define ioctlADC_WRITE_OFFSET16(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs2[0]))
#define ioctlADC_WRITE_OFFSET17(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs2[1]))
#define ioctlADC_WRITE_OFFSET18(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs2[2]))
#define ioctlADC_WRITE_OFFSET19(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adofs2[3]))			
#endif /* ADC_VERSION >= 7 */			
			
/* read ADC offset register x */
#if ADC_VERSION >= 6
#define ioctlADC_READ_OFFSET(pAdcBase, param)  \
  periphMemRead(&((pAdcBase)->adofs[param]))
#endif	
#if ADC_VERSION >= 7
#define ioctlADC_READ_OFFSET2(pAdcBase, param)\
  periphMemRead(&((pAdcBase)->adofs2[param-16]))
/* universal commands for old and new register */
#define ioctlADC_READ_OFFSET12(pAdcBase, param)  \
  (param <= 15) ? periphMemRead(&((pAdcBase)->adofs[param])) : periphMemRead(&((pAdcBase)->adofs2[param-16])); 
#endif				
						
/* read samples from result registers */
/* one at a time, param is the number of the Result reg (0-7) */
#if ADC_VERSION >= 6
#define ioctlADC_READ_SAMPLE(pAdcBase, param) 	\
  periphMemRead(&((pAdcBase)->adrslt[param]))
#endif
#if ADC_VERSION >= 7
#define ioctlADC_READ_SAMPLE2(pAdcBase, param)  \
  periphMemRead(&((pAdcBase)->adrslt2[param-16]))
/* universal commands for old and new register */
#define ioctlADC_READ_SAMPLE12(pAdcBase, param)  \
  (param <= 15) ? periphMemRead(&((pAdcBase)->adrslt[param])) : periphMemRead(&((pAdcBase)->adrslt2[param-16])); 
#endif		

	
/* reads samples from result registers - all 8(or 16) to the buffer pointed by pParam */
#if ADC_VERSION <= 5
	inline void AdcRdResults(adc_tBuff buff,volatile UWord16 *reg) {
	    int i; for(i=0; i<8; i++) *buff++ = periphMemRead(reg++); 
	}
#else 
	inline void AdcRdResults(adc_tBuff buff,volatile UWord16 *reg) {
	    int i; for(i=0; i<16; i++) *buff++ = periphMemRead(reg++); 
	}
#endif	
#if ADC_VERSION >= 7	
	inline void AdcRdResults2(adc_tBuff buff,volatile UWord16 *reg) {
	    int i; for(i=0; i<4; i++) *buff++ = periphMemRead(reg++); 
	}
#endif	
	
#define ioctlADC_READ_ALL_SAMPLES(pAdcBase, param) \
  AdcRdResults(param,((UWord16*)&((pAdcBase)->adrslt[0])))
#if ADC_VERSION >= 7	
#define ioctlADC_READ_ALL_SAMPLES2(pAdcBase, param) \
  AdcRdResults2(param,((UWord16*)&((pAdcBase)->adrslt2[0])))
#endif

/* read ADC status register */
#define ioctlADC_READ_STATUS(pAdcBase, param) 	\
  periphMemRead(&((pAdcBase)->adstat))

#if ADC_VERSION == 1

/* test some ADC status bits */
#define ioctlADC_GET_STATUS_CIP(pAdcBase, param) \
  periphBitTest(ADC_ADSTAT_CIP, &((pAdcBase)->adstat))

#define ioctlADC_GET_STATUS_EOSI(pAdcBase, param) \
  periphBitTest(ADC_ADSTAT_EOSI, &((pAdcBase)->adstat))

/* clear ADC status bit - end of scan interrupt flag (EOSI) */
#define ioctlADC_CLEAR_STATUS_EOSI(pAdcBase, param) \
  periphMemWrite(ADC_ADSTAT_EOSI, &((pAdcBase)->adstat))

#else /* ADC_VERSION >= 2 */

/* test some ADC status bits */
#define ioctlADC_GET_STATUS_CIP(pAdcBase, param) \
  periphBitTest(((((UWord16)(param) & ADC_CONVERTER_0) | ((UWord16)(param) == 0)) ? ADC_ADSTAT_CIP0 : 0 )| \
    ((((UWord16)(param)) & ADC_CONVERTER_1) ? ADC_ADSTAT_CIP1 : 0), &((pAdcBase)->adstat))
  
#define ioctlADC_GET_STATUS_EOSI(pAdcBase, param) \
  periphBitTest(((((UWord16)(param) & ADC_CONVERTER_0) | ((UWord16)(param) == 0)) ? ADC_ADSTAT_EOSI0 : 0 )| \
    ((((UWord16)(param)) & ADC_CONVERTER_1) ? ADC_ADSTAT_EOSI1 : 0), &((pAdcBase)->adstat))

/* clear ADC status bit - end of scan interrupt flag (EOSI) */
#define ioctlADC_CLEAR_STATUS_EOSI(pAdcBase, param) \
  periphMemWrite(((((UWord16)(param) & ADC_CONVERTER_0) | ((UWord16)(param) == 0)) ? ADC_ADSTAT_EOSI0 : 0 )| \
    ((((UWord16)(param)) & ADC_CONVERTER_1) ? ADC_ADSTAT_EOSI1 : 0), &((pAdcBase)->adstat))

#endif  /* ADC_VERSION */
#define ioctlADC_GET_STATUS_ZCI(pAdcBase, param) \
  periphBitTest(ADC_ADSTAT_ZCI, &((pAdcBase)->adstat))
	
#define ioctlADC_GET_STATUS_LLMTI(pAdcBase, param) \
  periphBitTest(ADC_ADSTAT_LLMTI, &((pAdcBase)->adstat))
	
#define ioctlADC_GET_STATUS_HLMTI(pAdcBase, param) \
  periphBitTest(ADC_ADSTAT_HLMTI, &((pAdcBase)->adstat))


/* test ADC status - ready channel x flag (RDYx), x should be immediate */
#if ADC_VERSION <= 2
#define ioctlADC_GET_STATUS_RDY(pAdcBase, param) \
  periphBitTest(1 << ((UWord16)(param)), &((pAdcBase)->adstat))
#else /* ADC_VERSION >= 3 */
#define ioctlADC_GET_STATUS_RDY(pAdcBase, param) \
  periphBitTest(1 << ((UWord16)(param)), &((pAdcBase)->cnrdy))
#endif

/* write ADC status register */
#define ioctlADC_WRITE_STATUS(pAdcBase, param) \
  periphMemWrite((UWord16) (param), &((pAdcBase)->adstat))

/***********************************************************************
* ADC Limits and Zero Crossing Status Registers ADC_LOLIMSTAT2, ADC_HILIMSTAT2, ADC_ZXSTAT2 
***********************************************************************/

#if ADC_VERSION <= 5

/* reads ADC limit status register - contains all sample limit flag bits */
#define ioctlADC_READ_LIMIT_STATUS(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adlstat))

/* test ADC limit status - low limit sample flag x (LLSx) - each sample has distinctive flag bit */
#define ioctlADC_GET_LIMIT_STATUS_LLS(pAdcBase, param) \
  periphBitTest(1 << ((UWord16)(param)), &((pAdcBase)->adlstat))

/* test ADC limit status - high limit sample flag x (HLSx) - each sample has distinctive flag bit */
#define ioctlADC_GET_LIMIT_STATUS_HLS(pAdcBase, param) \
  periphBitTest(1 << ((UWord16)(param)+8), &((pAdcBase)->adlstat))

/* reads ADC zero cross status register */
#define ioctlADC_READ_ZERO_CROSS_STATUS(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adzcstat))

/* test ADC zero cross status - zero cross sample flag x (ZCSx) */
#define ioctlADC_GET_ZERO_CROSS_STATUS_ZCS(pAdcBase, param) \
  periphBitTest(1 << ((UWord16)(param)), &((pAdcBase)->adzcstat))

/* clear ADC status bit - low limit interrupt flag (LLMTI) */
/* cleared indirectly by clearing all LLSx flags in limit status registers */
#define ioctlADC_CLEAR_STATUS_LLMTI(pAdcBase, param) \
  periphMemWrite(0x00FF, &((pAdcBase)->adlstat))

/* clear ADC status bit - high limit interrupt flag (HLMTI) */
/* cleared indirectly by clearing all HLSx flags in limit status registers */
#define ioctlADC_CLEAR_STATUS_HLMTI(pAdcBase, param) \
  periphMemWrite(0xFF00, &((pAdcBase)->adlstat))

/* clear ADC status bit - zero cross interrupt flag (ZCI) */
#define ioctlADC_CLEAR_STATUS_ZCI(pAdcBase, param) \
  periphMemWrite(0x00FF, &((pAdcBase)->adzcstat))

/* clear bits in ADC limit status - low limit sample flag x (LLSx) */
#define ioctlADC_CLEAR_LIMIT_STATUS_LLS(pAdcBase, param) \
  periphMemWrite(1 << ((UWord16)(param)), &((pAdcBase)->adlstat))

/* clear bits in ADC limit status - high limit sample flag x (HLSx) */
#define ioctlADC_CLEAR_LIMIT_STATUS_HLS(pAdcBase, param) \
  periphMemWrite(1 << ((UWord16)(param)+8), &((pAdcBase)->adlstat))

/* clear bits in ADC zero cross status - zero cross sample flag x (ZCSx) */
#define ioctlADC_CLEAR_ZERO_CROSS_STATUS_ZCS(pAdcBase, param) \
  periphMemWrite(1 << ((UWord16)(param)), &((pAdcBase)->adzcstat))

/* clear ADC any combination of limiting status bits */
#define ioctlADC_CLEAR_LIMIT_STATUS_BITS(pAdcBase, param) \
  periphMemWrite(param, &((pAdcBase)->adlstat))

#else /* ADC_VERSION >= 6 */

/* reads ADC low limit status register - contains all sample limit flag bits */
#define ioctlADC_READ_LOW_LIMIT_STATUS(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->lolimstat))

/* reads ADC high limit status register - contains all sample limit flag bits */
#define ioctlADC_READ_HIGH_LIMIT_STATUS(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->hilimstat))

/* test ADC limit status - low limit sample flag x (LLSx) - each sample has distinctive flag bit */
#define ioctlADC_GET_LIMIT_STATUS_LLS(pAdcBase, param) \
  periphBitTest(1 << ((UWord16)(param)), &((pAdcBase)->lolimstat))

/* test ADC limit status - high limit sample flag x (HLSx) - each sample has distinctive flag bit */
#define ioctlADC_GET_LIMIT_STATUS_HLS(pAdcBase, param) \
  periphBitTest(1 << ((UWord16)(param)), &((pAdcBase)->hilimstat))

/* reads ADC zero cross status register */
#define ioctlADC_READ_ZERO_CROSS_STATUS(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->zxstat))

/* test ADC zero cross status - zero cross sample flag x (ZCSx) */
#define ioctlADC_GET_ZERO_CROSS_STATUS_ZCS(pAdcBase, param) \
  periphBitTest(1 << ((UWord16)(param)), &((pAdcBase)->zxstat))

/* clear ADC status bit - low limit interrupt flag (LLMTI) */
/* cleared indirectly by clearing all LLSx flags in limit status registers */
#define ioctlADC_CLEAR_STATUS_LLMTI(pAdcBase, param) \
  periphMemWrite(0xFFFF, &((pAdcBase)->lolimstat))

/* clear ADC status bit - high limit interrupt flag (HLMTI) */
/* cleared indirectly by clearing all HLSx flags in limit status registers */
#define ioctlADC_CLEAR_STATUS_HLMTI(pAdcBase, param) \
  periphMemWrite(0xFFFF, &((pAdcBase)->hilimstat))

/* clear ADC status bit - zero cross interrupt flag (ZCI) */
#define ioctlADC_CLEAR_STATUS_ZCI(pAdcBase, param) \
  periphMemWrite(0xFFFF, &((pAdcBase)->zxstat))
  
/* clear bits in ADC limit status - low limit sample flag x (LLSx) */
#define ioctlADC_CLEAR_LIMIT_STATUS_LLS(pAdcBase, param) \
  periphMemWrite(1 << ((UWord16)(param)), &((pAdcBase)->lolimstat))

/* clear bits in ADC limit status - high limit sample flag x (HLSx) */
#define ioctlADC_CLEAR_LIMIT_STATUS_HLS(pAdcBase, param) \
  periphMemWrite(1 << ((UWord16)(param)), &((pAdcBase)->hilimstat))

#define ioctlADC_CLEAR_ZERO_CROSS_STATUS_ZCS(pAdcBase, param) \
  periphMemWrite(1 << ((UWord16)(param)), &((pAdcBase)->zxstat))

/* clear ADC combination of low limiting status bits */
#define ioctlADC_CLEAR_LOW_LIMIT_STATUS_BITS(pAdcBase, param) \
  periphMemWrite(param, &((pAdcBase)->lolimstat))

/* clear ADC any combination of high limiting status bits */
#define ioctlADC_CLEAR_HIGH_LIMIT_STATUS_BITS(pAdcBase, param) \
  periphMemWrite(param, &((pAdcBase)->hilimstat))

#endif /* ADC_VERSION >= 6 */

#if ADC_VERSION >= 7 /* ADC_VERSION >= 7 */

/* reads ADC low limit status register - contains all sample limit flag bits */
#define ioctlADC_READ_LOW_LIMIT_STATUS2(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->lolimstat2))

/* reads ADC high limit status register - contains all sample limit flag bits */
#define ioctlADC_READ_HIGH_LIMIT_STATUS2(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->hilimstat2))

/* test ADC limit status - low limit sample flag x (LLSx) - each sample has distinctive flag bit */
#define ioctlADC_GET_LIMIT_STATUS2_LLS(pAdcBase, param) \
  periphBitTest(1 << ((UWord16)((param - 16) & 0x0003)), &((pAdcBase)->lolimstat2))
	
/* test ADC limit status - high limit sample flag x (HLSx) - each sample has distinctive flag bit */
#define ioctlADC_GET_LIMIT_STATUS2_HLS(pAdcBase, param) \
  periphBitTest(1 << ((UWord16)((param - 16) & 0x0003)), &((pAdcBase)->hilimstat2))

/* reads ADC zero cross status register */
#define ioctlADC_READ_ZERO_CROSS_STATUS2(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->zxstat2))

/* test ADC zero cross status - zero cross sample flag x (ZCSx) */
#define ioctlADC_GET_ZERO_CROSS_STATUS2_ZCS(pAdcBase, param) \
  periphBitTest(1 << ((UWord16)((param-16) & 0x0003)), &((pAdcBase)->zxstat2))

/* clear ADC status bit - low limit interrupt flag (LLMTI) */
/* cleared indirectly by clearing all LLSx flags in limit status registers */
#define ioctlADC_CLEAR_STATUS2_LLMTI(pAdcBase, param) \
  periphMemWrite(ADC_LOLIMSTAT2_MASK, &((pAdcBase)->lolimstat2))

/* clear ADC status bit - high limit interrupt flag (HLMTI) */
/* cleared indirectly by clearing all HLSx flags in limit status registers */
#define ioctlADC_CLEAR_STATUS2_HLMTI(pAdcBase, param) \
  periphMemWrite(ADC_HILIMSTAT2_MASK, &((pAdcBase)->hilimstat2))

/* clear ADC status bit - zero cross interrupt flag (ZCI) */
#define ioctlADC_CLEAR_STATUS2_ZCI(pAdcBase, param) \
  periphMemWrite(ADC_ZXSTAT2_MASK, &((pAdcBase)->zxstat2))
  
/* clear bits in ADC limit status - low limit sample flag x (LLSx) */
#define ioctlADC_CLEAR_LIMIT_STATUS2_LLS(pAdcBase, param) \
  periphMemWrite(1 << ((UWord16)((param - 16) & 0x0003)), &((pAdcBase)->lolimstat2))

	/* clear bits in ADC limit status - high limit sample flag x (HLSx) */
#define ioctlADC_CLEAR_LIMIT_STATUS2_HLS(pAdcBase, param) \
  periphMemWrite(1 << ((UWord16)((param - 16) & 0x0003)), &((pAdcBase)->hilimstat2))

#define ioctlADC_CLEAR_ZERO_CROSS_STATUS2_ZCS(pAdcBase, param) \
  periphMemWrite(1 << ((UWord16)((param - 16) & 0x0003)), &((pAdcBase)->zxstat2))

/* clear ADC combination of low limiting status bits */
#define ioctlADC_CLEAR_LOW_LIMIT_STATUS2_BITS(pAdcBase, param) \
  periphMemWrite((param & ADC_LOLIMSTAT2_MASK), &((pAdcBase)->lolimstat2))

/* clear ADC any combination of high limiting status bits */
#define ioctlADC_CLEAR_HIGH_LIMIT_STATUS2_BITS(pAdcBase, param) \
  periphMemWrite((param & ADC_HILIMSTAT2_MASK), &((pAdcBase)->hilimstat2))
	
/* reads ADC low limit status register 1(param =1) or 2 (param =1)   - contains all sample limit flag bits */
#define ioctlADC_READ_LOW_LIMIT_STATUS12(pAdcBase, param) \
  (((UWord32)periphMemRead(&((pAdcBase)->lolimstat2))<<16 | (UWord32)periphMemRead(&((pAdcBase)->lolimstat)))); 
	
	/* reads ADC high limit status register - contains all sample limit flag bits */
#define ioctlADC_READ_HIGH_LIMIT_STATUS12(pAdcBase, param) \
  (((UWord32)periphMemRead(&((pAdcBase)->hilimstat2))<<16 | (UWord32)periphMemRead(&((pAdcBase)->hilimstat)))); 
	
/* test ADC limit status - low limit sample flag x (LLSx) - each sample has distinctive flag bit */
#define ioctlADC_GET_LIMIT_STATUS12_LLS(pAdcBase, param) \
  (param <= 15) ? periphBitTest(1 << ((UWord16)(param & 0x000f)), &((pAdcBase)->lolimstat)) : \
				periphBitTest(1 << ((UWord16)((param - 16) & 0x0003)), &((pAdcBase)->lolimstat2))

/* test ADC limit status - high limit sample flag x (HLSx) - each sample has distinctive flag bit */
#define ioctlADC_GET_LIMIT_STATUS12_HLS(pAdcBase, param) \
  (param <= 15) ? periphBitTest(1 << ((UWord16)(param & 0x000f)), &((pAdcBase)->hilimstat)) : \
				periphBitTest(1 << ((UWord16)((param - 16) & 0x0003)), &((pAdcBase)->hilimstat2))

/* reads ADC zero cross status register */
#define ioctlADC_READ_ZERO_CROSS_STATUS12(pAdcBase, param) \
  (((UWord32)periphMemRead(&((pAdcBase)->zxstat2))<<16 | (UWord32)periphMemRead(&((pAdcBase)->zxstat)))); 
	
/* test ADC zero cross status - zero cross sample flag x (ZCSx) */
#define ioctlADC_GET_ZERO_CROSS_STATUS12_ZCS(pAdcBase, param) \
  (param <= 15) ? periphBitTest(1 << ((UWord16)(param & 0x000f)), &((pAdcBase)->zxstat)) : \
				periphBitTest(1 << ((UWord16)((param - 16) & 0x0003)), &((pAdcBase)->zxstat2))

/* clear ADC status bit - low limit interrupt flag (LLMTI) */
/* cleared indirectly by clearing all LLSx flags in limit status registers */
#define ioctlADC_CLEAR_STATUS12_LLMTI(pAdcBase, param) { \
  periphMemWrite(0xFFFF, &((pAdcBase)->lolimstat)); \
  periphMemWrite(ADC_LOLIMSTAT2_MASK, &((pAdcBase)->lolimstat2)); \
}
/* clear ADC status bit - high limit interrupt flag (HLMTI) */
/* cleared indirectly by clearing all HLSx flags in limit status registers */
#define ioctlADC_CLEAR_STATUS12_HLMTI(pAdcBase, param) { \
  periphMemWrite(0xFFFF, &((pAdcBase)->hilimstat)); \
  periphMemWrite(ADC_HILIMSTAT2_MASK, &((pAdcBase)->hilimstat2)); \
}	  
/* clear ADC status bit - zero cross interrupt flag (ZCI) */
#define ioctlADC_CLEAR_STATUS12_ZCI(pAdcBase, param) { \
  periphMemWrite(0xFFFF, &((pAdcBase)->zxstat)); \
  periphMemWrite(ADC_ZXSTAT2_MASK, &((pAdcBase)->zxstat2)); \
}  
/* clear bits in ADC limit status - low limit sample flag x (LLSx) */
#define ioctlADC_CLEAR_LIMIT_STATUS12_LLS(pAdcBase, param) \
if (param <= 15) periphMemWrite(1 << ((UWord16)(param & 0x000f)), &((pAdcBase)->lolimstat)); \
else  periphMemWrite(1 << ((UWord16)((param - 16) & 0x0003)), &((pAdcBase)->lolimstat2)) 
  
/* clear bits in ADC limit status - high limit sample flag x (HLSx) */
#define ioctlADC_CLEAR_LIMIT_STATUS12_HLS(pAdcBase, param) \
if (param <= 15) periphMemWrite(1 << ((UWord16)(param & 0x000f)), &((pAdcBase)->hilimstat)); \
else  periphMemWrite(1 << ((UWord16)((param - 16) & 0x0003)), &((pAdcBase)->hilimstat2)) 

#define ioctlADC_CLEAR_ZERO_CROSS_STATUS12_ZCS(pAdcBase, param) \
if (param <= 15) periphMemWrite(1 << ((UWord16)(param & 0x000f)), &((pAdcBase)->zxstat)); \
else  periphMemWrite(1 << ((UWord16)((param - 16) & 0x0003)), &((pAdcBase)->zxstat2)) 

/* clear ADC combination of low limiting status bits */
#define ioctlADC_CLEAR_LOW_LIMIT_STATUS12_BITS(pAdcBase, param) { \
  if ((param & 0x000ffff)) periphMemWrite((param & 0xFFFF), &((pAdcBase)->lolimstat));	\
  if ((param & 0x00f0000)) periphMemWrite((param & ADC_LOLIMSTAT2_MASK), &((pAdcBase)->lolimstat2)); \
}
/* clear ADC any combination of high limiting status bits */
#define ioctlADC_CLEAR_HIGH_LIMIT_STATUS12_BITS(pAdcBase, param) { \
  if ((param & 0x000ffff)) periphMemWrite((param & 0xFFFF), &((pAdcBase)->hilimstat));	\
  if ((param & 0x00f0000)) periphMemWrite((param & ADC_HILIMSTAT2_MASK), &((pAdcBase)->hilimstat2)); \
}	
	
#endif /* ADC_VERSION >= 7 */

/***********************************************************************
* ADC power control register (ADCPOWER)
***********************************************************************/

#define ioctlADC_POWER_DOWN(pAdcBase, param) \
  periphBitSet((UWord16)(param), &((pAdcBase)->adcpower))

#define ioctlADC_POWER_UP(pAdcBase, param) \
  periphBitClear((UWord16)(param), &((pAdcBase)->adcpower))

#define ioctlADC_POWER_SAVE_MODE(pAdcBase, param) \
  if(param) periphBitSet(ADC_ADCPOWER_PSM, &((pAdcBase)->adcpower)); \
  else periphBitClear(ADC_ADCPOWER_PSM, &((pAdcBase)->adcpower))

#define ioctlADC_SET_POWER_UP_DELAY(pAdcBase, param) \
  periphBitGrpSet(ADC_ADCPOWER_PUDELAY_MASK, ((param) << 4), &((pAdcBase)->adcpower))

#define ioctlADC_GET_POWER_STATUS(pAdcBase, param) \
  periphBitTest(((UWord16)(param) << 10), &((pAdcBase)->adcpower))

#define ioctlADC_READ_POWER_CONTROL_REG(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adcpower))

#if ADC_VERSION >= 2
#define ioctlADC_AUTO_POWERDOWN_MODE(pAdcBase, param) \
  if(param) periphBitSet(ADC_ADCPOWER_APD, &((pAdcBase)->adcpower)); \
  else periphBitClear(ADC_ADCPOWER_APD, &((pAdcBase)->adcpower))

#define ioctlADC_AUTO_STANDBY_MODE(pAdcBase, param) \
  if(param) periphBitSet(ADC_ADCPOWER_ASB, &((pAdcBase)->adcpower)); \
  else periphBitClear(ADC_ADCPOWER_ASB, &((pAdcBase)->adcpower))
#endif

/***********************************************************************
* ADC calibration register ADC_CAL
***********************************************************************/

#if ADC_VERSION == 1

#define ioctlADC_CALIB_ENABLE(pAdcBase, param) \
  periphBitSet((((param) & ADC_CONVERTER_0) ? ADC_CAL_CAL0 : 0) | \
               (((param) & ADC_CONVERTER_1) ? ADC_CAL_CAL1 : 0), &((pAdcBase)->adc_cal))
  
#define ioctlADC_CALIB_DISABLE(pAdcBase, param) \
  periphBitClear((((param) & ADC_CONVERTER_0) ? ADC_CAL_CAL0 : 0) | \
                 (((param) & ADC_CONVERTER_1) ? ADC_CAL_CAL1 : 0), &((pAdcBase)->adc_cal))

#define ioctlADC_SET_CONVERTER0_CALIB_REF(pAdcBase, param) \
  if (param) periphBitSet(ADC_CAL_CRS0, &((pAdcBase)->adc_cal)); \
  else periphBitClear(ADC_CAL_CRS0, &((pAdcBase)->adc_cal))

#define ioctlADC_SET_CONVERTER1_CALIB_REF(pAdcBase, param) \
  if (param) periphBitSet(ADC_CAL_CRS1, &((pAdcBase)->adc_cal)); \
  else periphBitClear(ADC_CAL_CRS1, &((pAdcBase)->adc_cal))

#elif ADC_VERSION == 2

#define ioctlADC_SET_VREFH_SOURCE(pAdcBase, param) \
  if (param) periphBitSet(ADC_CAL_SEL_VREFH, &((pAdcBase)->adc_cal)); \
  else periphBitClear(ADC_CAL_SEL_VREFH, &((pAdcBase)->adc_cal))

#define ioctlADC_SET_VREFL_SOURCE(pAdcBase, param) \
  if (param) periphBitSet(ADC_CAL_SEL_VREFLO, &((pAdcBase)->adc_cal)); \
  else periphBitClear(ADC_CAL_SEL_VREFLO, &((pAdcBase)->adc_cal))

#elif ADC_VERSION >= 3

#define ioctlADC_SET_VREFH0_SOURCE(pAdcBase, param) \
  if (param) periphBitSet(ADC_CAL_SEL_VREFH0, &((pAdcBase)->adc_cal)); \
  else periphBitClear(ADC_CAL_SEL_VREFH0, &((pAdcBase)->adc_cal))

#define ioctlADC_SET_VREFH1_SOURCE(pAdcBase, param) \
  if (param) periphBitSet(ADC_CAL_SEL_VREFH1, &((pAdcBase)->adc_cal)); \
  else periphBitClear(ADC_CAL_SEL_VREFH1, &((pAdcBase)->adc_cal))

#define ioctlADC_SET_VREFL0_SOURCE(pAdcBase, param) \
  if (param) periphBitSet(ADC_CAL_SEL_VREFLO0, &((pAdcBase)->adc_cal)); \
  else periphBitClear(ADC_CAL_SEL_VREFLO0, &((pAdcBase)->adc_cal))

#define ioctlADC_SET_VREFL1_SOURCE(pAdcBase, param) \
  if (param) periphBitSet(ADC_CAL_SEL_VREFLO1, &((pAdcBase)->adc_cal)); \
  else periphBitClear(ADC_CAL_SEL_VREFLO1, &((pAdcBase)->adc_cal))

#define ioctlADC_SET_CALIB_SOURCE(pAdcBase, param) \
  periphBitGrpSet((ADC_CAL_SEL_TEST0 | ADC_CAL_SEL_DAC0 | ADC_CAL_SEL_TEST1 | ADC_CAL_SEL_DAC1), (param), &((pAdcBase)->adc_cal))

#endif /* ADC_VERSION >= 3 */


#if ADC_VERSION >= 5
/* Gain Settings ADC_GC1, ADC_GC2 */
#define ioctlADC_SET_ANA0_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC1_GAINA0_MASK, (param), &((pAdcBase)->adc_gc1))

#define ioctlADC_SET_ANA1_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC1_GAINA1_MASK, ((param)<<2), &((pAdcBase)->adc_gc1))

#define ioctlADC_SET_ANA2_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC1_GAINA2_MASK, ((param)<<4), &((pAdcBase)->adc_gc1))

#define ioctlADC_SET_ANA3_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC1_GAINA3_MASK, ((param)<<6), &((pAdcBase)->adc_gc1))

#define ioctlADC_SET_ANA4_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC1_GAINA4_MASK, ((param)<<8), &((pAdcBase)->adc_gc1))

#define ioctlADC_SET_ANA5_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC1_GAINA5_MASK, ((param)<<10), &((pAdcBase)->adc_gc1))

#define ioctlADC_SET_ANA6_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC1_GAINA6_MASK, ((param)<<12), &((pAdcBase)->adc_gc1))
  
#define ioctlADC_SET_ANA7_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC1_GAINA7_MASK, ((param)<<14), &((pAdcBase)->adc_gc1))

#define ioctlADC_SET_ANB0_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC2_GAINB0_MASK, ((param)), &((pAdcBase)->adc_gc2))

#define ioctlADC_SET_ANB1_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC2_GAINB1_MASK, ((param)<<2), &((pAdcBase)->adc_gc2))

#define ioctlADC_SET_ANB2_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC2_GAINB2_MASK, ((param)<<4), &((pAdcBase)->adc_gc2))

#define ioctlADC_SET_ANB3_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC2_GAINB3_MASK, ((param)<<6), &((pAdcBase)->adc_gc2))

#define ioctlADC_SET_ANB4_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC2_GAINB4_MASK, ((param)<<8), &((pAdcBase)->adc_gc2))

#define ioctlADC_SET_ANB5_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC2_GAINB5_MASK, ((param)<<10), &((pAdcBase)->adc_gc2))

#define ioctlADC_SET_ANB6_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC2_GAINB6_MASK, ((param)<<12), &((pAdcBase)->adc_gc2))

#define ioctlADC_SET_ANB7_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC2_GAINB7_MASK, ((param)<<14), &((pAdcBase)->adc_gc2))

#define ioctlADC_READ_GAIN_CONTROL_1_REG(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adc_gc1))

#define ioctlADC_WRITE_GAIN_CONTROL_1_REG(pAdcBase, param) \
  periphMemWrite( param, &((pAdcBase)->adc_gc1))

#define ioctlADC_READ_GAIN_CONTROL_2_REG(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adc_gc2))

#define ioctlADC_WRITE_GAIN_CONTROL_2_REG(pAdcBase, param) \
  periphMemWrite( param, &((pAdcBase)->adc_gc2))
#endif

#if ADC_VERSION >= 7
/* Gain Settings ADC_GC3 */
#define ioctlADC_SET_ANA9_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC3_GAINA9_MASK, (param), &((pAdcBase)->adc_gc3))

#define ioctlADC_SET_ANA10_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC3_GAINA10_MASK, ((param)<<2), &((pAdcBase)->adc_gc3))

#define ioctlADC_SET_ANB9_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC3_GAINB9_MASK, ((param)<<4), &((pAdcBase)->adc_gc3))

#define ioctlADC_SET_ANB10_GAIN(pAdcBase, param) \
  periphBitGrpSet(ADC_GC3_GAINB10_MASK, ((param)<<6), &((pAdcBase)->adc_gc3))

#define ioctlADC_READ_GAIN_CONTROL_3_REG(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adc_gc3))

#define ioctlADC_WRITE_GAIN_CONTROL_3_REG(pAdcBase, param) \
  periphMemWrite( (param & 0x00ff), &((pAdcBase)->adc_gc3))
#endif
/* Scan control */
#if ADC_VERSION >= 5	
#define ioctlADC_SET_SAMPLE_BY_SYNC(pAdcBase, param) \
  periphBitSet(param, &((pAdcBase)->adc_sctrl))

#define ioctlADC_SET_SAMPLE_IMMEDIATELY(pAdcBase, param) \
  periphBitClear(param, &((pAdcBase)->adc_sctrl))

#define ioctlADC_READ_SCAN_CONTROL_REG(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adc_sctrl))

#define ioctlADC_WRITE_SCAN_CONTROL_REG(pAdcBase, param) \
  periphMemWrite( param, &((pAdcBase)->adc_sctrl))
#endif
#if ADC_VERSION >= 7	
#define ioctlADC_SET_SAMPLE_BY_SYNC2(pAdcBase, param) \
  periphBitSet((param>>16 & 0x000f), &((pAdcBase)->adc_sctrl2))

#define ioctlADC_SET_SAMPLE_IMMEDIATELY2(pAdcBase, param) \
  periphBitClear((param>>16 & 0x000f), &((pAdcBase)->adc_sctrl2))

#define ioctlADC_READ_SCAN_CONTROL_REG2(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adc_sctrl2))

#define ioctlADC_WRITE_SCAN_CONTROL_REG2(pAdcBase, param) \
  periphMemWrite((param & 0x000f), &((pAdcBase)->adc_sctrl2))

#define ioctlADC_SET_SAMPLE_BY_SYNC12(pAdcBase, param) { \
  if ((param & 0x000ffff)) periphBitSet(param, &((pAdcBase)->adc_sctrl));	\
  if ((param & 0x00f0000)) periphBitSet((param & 0x000f0000)>>16, &((pAdcBase)->adc_sctrl2)); \
}
#define ioctlADC_SET_SAMPLE_IMMEDIATELY12(pAdcBase, param) { \
  if ((param & 0x000ffff)) periphBitClear(param, &((pAdcBase)->adc_sctrl));	\
  if ((param & 0x00f0000)) periphBitClear((param & 0x000f0000)>>16, &((pAdcBase)->adc_sctrl2)); \
}	
#endif	
	
#if ADC_VERSION >= 5
/* Power Control */

#define ioctlADC_SET_ADCB_DIVISOR_PARALEL_MODE(pAdcBase, param) \
  periphBitGrpSet(ADC_PWR2_DIV_MASK, ((param)<<8), &((pAdcBase)->adc_pwr2))

#if ADC_VERSION <= 6
#define ioctlADC_SET_MAX_SPEED_ADCA(pAdcBase, param) \
  periphBitGrpSet(ADC_PWR2_SPEEDA_MASK,(param), &((pAdcBase)->adc_pwr2))

#define ioctlADC_SET_MAX_SPEED_ADCB(pAdcBase, param) \
  periphBitGrpSet(ADC_PWR2_SPEEDB_MASK, ((param)<<2), &((pAdcBase)->adc_pwr2))
#endif /* ADC_VERSION <= 6 */ 

#define ioctlADC_READ_POWER_CONTROL_2_REG(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adc_pwr2))

#define ioctlADC_WRITE_POWER_CONTROL_2_REG(pAdcBase, param) \
  periphMemWrite( param, &((pAdcBase)->adc_pwr2))

#endif /* ADC_VERSION >= 5 */

/***********************************************************************
* ADC Control Register 3 ADC_CTRL3
***********************************************************************/
#define ioctlADC_SET_DMA_TRIGGER(pAdcBase, param) \
  if (param) periphBitSet(ADC_ADCR3_DMASRC, &((pAdcBase)->ctrl3)); \
  else periphBitClear(ADC_ADCR3_DMASRC, &((pAdcBase)->ctrl3))

#define ioctlADC_SET_UNIPOLAR_CHANNEL(pAdcBase, param)  \
    periphBitGrpSet(ADC_ADCR3_UPDEN_L_H_MASK & (param), ((param)<<8), &((pAdcBase)->ctrl3)) 

#if ADC_VERSION == 6	
#define ioctlADC_SET_SAMPLE_WINDOW_COUNT1(pAdcBase, param) \
  periphBitGrpSet(ADC_ADCR3_SCNT0, ((param) << 0), &((pAdcBase)->ctrl3))

#define ioctlADC_SET_SAMPLE_WINDOW_COUNT2(pAdcBase, param) \
  periphBitGrpSet(ADC_ADCR3_SCNT1, ((param) << 3), &((pAdcBase)->ctrl3))
#endif	
	
/***********************************************************************
* ADC Channel List Register 5 ADC_CLIST5
***********************************************************************/
#define ioctlADC_WRITE_CHANNEL_LIST5(pAdcBase, param) \
  periphBitGrpSet(ADC_CLIST5_ALL_SAMPLE_MASK, ((param)), &((pAdcBase)->adlst5))

#define ioctlADC_SET_LIST_SAMPLE16(pAdcBase, param) \
  periphBitGrpSet(0x3 << 0, ((param)<<0), &((pAdcBase)->adlst5))
#define ioctlADC_SET_LIST_SAMPLE17(pAdcBase, param) \
  periphBitGrpSet(0x3 << 2, ((param)<<2), &((pAdcBase)->adlst5))
#define ioctlADC_SET_LIST_SAMPLE18(pAdcBase, param) \
  periphBitGrpSet(0x3 << 4, ((param)<<4), &((pAdcBase)->adlst5))
#define ioctlADC_SET_LIST_SAMPLE19(pAdcBase, param) \
  periphBitGrpSet(0x3 << 6, ((param)<<6), &((pAdcBase)->adlst5))

#define ioctlADC_SET_ADCA6_INPUT(pAdcBase, param) \
  if (param) periphBitSet(ADC_CLIST5_SEL_TEMP_0_MASK, &((pAdcBase)->adlst5)); \
  else periphBitClear(ADC_CLIST5_SEL_TEMP_0_MASK, &((pAdcBase)->adlst5))
#define ioctlADC_SET_ADCA7_INPUT(pAdcBase, param) \
  if (param) periphBitSet(ADC_CLIST5_SEL_INTERNAL_0_MASK, &((pAdcBase)->adlst5)); \
  else periphBitClear(ADC_CLIST5_SEL_INTERNAL_0_MASK, &((pAdcBase)->adlst5))
#define ioctlADC_SET_ADCB6_INPUT(pAdcBase, param) \
  if (param) periphBitSet(ADC_CLIST5_SEL_TEMP_1_MASK, &((pAdcBase)->adlst5)); \
  else periphBitClear(ADC_CLIST5_SEL_TEMP_1_MASK, &((pAdcBase)->adlst5))
#define ioctlADC_SET_ADCB7_INPUT(pAdcBase, param) \
  if (param) periphBitSet(ADC_CLIST5_SEL_INTERNAL_1_MASK, &((pAdcBase)->adlst5)); \
  else periphBitClear(ADC_CLIST5_SEL_INTERNAL_1_MASK, &((pAdcBase)->adlst5))
	
/***********************************************************************
* ADC Sample Disable Register 2 ADC_SDIS2
***********************************************************************/
#if ADC_VERSION >= 7
  #define ioctlADC_WRITE_SAMPLE_DISABLE2(pAdcBase, param) \
  if((param) & 0xFFFF0000L)\
  	periphBitGrpSR(ADC_SDIS2_MASK, ((param >> 16)), &((pAdcBase)->adsdis2)); \
  else \
    periphBitGrpSR(ADC_SDIS2_MASK, (1 << ((param-16))), &((pAdcBase)->adsdis2))
/*	universal command for old and new register */
  #define ioctlADC_WRITE_SAMPLE_DISABLE12(pAdcBase, param) \
  if((param) & 0xFFFF0000L) \
  {	if (param & 0x8000FFFF) periphBitGrpSR(0xFFFF, (0xFFFF & (param)), &((pAdcBase)->adsdis)); \
	if (param & 0x800F0000) periphBitGrpSR(ADC_SDIS2_MASK, (ADC_SDIS2_MASK & (param>>16)), &((pAdcBase)->adsdis2)); \
  } \
  else  \
  { if (param < 16) periphBitGrpSR(0x000F, (1 << (param)), &((pAdcBase)->adsdis)); \
	else periphBitGrpSR(ADC_SDIS2_MASK, (1 << ((param-16))), &((pAdcBase)->adsdis2));\
  }
	
#endif
	
/***********************************************************************
* ADC Ready Register 2 ADC_RDY2
***********************************************************************/
#if ADC_VERSION >= 7
  #define ioctlADC_GET_STATUS_RDY2(pAdcBase, param) \
  periphBitTest(1 << ((UWord16)((param-16) & 0x000f)), &((pAdcBase)->cnrdy2))
/* universal commands for old and new register */
#define ioctlADC_GET_STATUS_RDY12(pAdcBase, param)  \
  ((param <= 15)) ?  periphBitTest(1 << ((UWord16)(param)), &((pAdcBase)->cnrdy)) : periphBitTest(1 << ((UWord16)((param-16) & 0x000f)), &((pAdcBase)->cnrdy2));
#endif

/***********************************************************************
* ADC Scan Halted Interrupt Enable Register 1 and 2  ADC_SCHLTEN 1 and 2 
***********************************************************************/
	#if ADC_VERSION >= 6	/* ADC_SET_SCAN_HALTED_INTERRUPT_DISABLE/ENABLE 
	                            Conditions are reversed with respect to the documentation, 
	                            because of bug in documentation. For proper setting proper settings:
	                            Interrupt disable - 0 
	                            Interrupt enable - 1         */
        #define ioctlADC_SET_SCAN_HALTED_INTERRUPT_DISABLE(pAdcBase, param) \
          periphBitClear(param, &((pAdcBase)->schlten))
        #define ioctlADC_SET_SCAN_HALTED_INTERRUPT_ENABLE(pAdcBase, param) \
          periphBitSet(param, &((pAdcBase)->schlten))

        #define ioctlADC_READ_SCAN_HALTED_INTERRUPT_REG(pAdcBase, param) \
            periphMemRead(&((pAdcBase)->schlten))
        #define ioctlADC_WRITE_SCAN_HALTED_INTERRUPT_REG(pAdcBase, param) \
             periphMemWrite(param, &((pAdcBase)->schlten))
    #endif
	
	#if ADC_VERSION >= 7	/* ADC_SET_SCAN_HALTED_INTERRUPT_DISABLE/ENABLE 
                                Conditions are reversed with respect to the documentation, 
                                because of bug in documentation. For proper setting proper settings:
                                Interrupt disable - 0 
                                Interrupt enable - 1         */
	#define ioctlADC_SET_SCAN_HALTED_INTERRUPT_DISABLE2(pAdcBase, param) \
      periphBitClear((param>>16 & 0x000f), &((pAdcBase)->schlten2))
    #define ioctlADC_SET_SCAN_HALTED_INTERRUPT_ENABLE2(pAdcBase, param) \
      periphBitSet((param & 0x000f), &((pAdcBase)->schlten2))

	#define ioctlADC_READ_SCAN_HALTED_INTERRUPT_REG2(pAdcBase, param) \
	  periphMemRead(&((pAdcBase)->schlten2))
	#define ioctlADC_WRITE_SCAN_HALTED_INTERRUPT_REG2(pAdcBase, param) \
	  periphMemWrite((param & 0x000f), &((pAdcBase)->schlten2))
	/* universal commands for old and new register */
	#define ioctlADC_SET_SCAN_HALTED_INTERRUPT_DISABLE12(pAdcBase, param) { \
	  if ((param & 0x000ffff)) periphBitClear(param, &((pAdcBase)->schlten));	\
	  if ((param & 0x00f0000)) periphBitClear((param & 0x000f0000)>>16, &((pAdcBase)->schlten2)); \
	}	
	#define ioctlADC_SET_SCAN_HALTED_INTERRUPT_ENABLE12(pAdcBase, param) { \
	  if ((param & 0x000ffff)) periphBitSet(param, &((pAdcBase)->schlten));	\
	  if ((param & 0x00f0000)) periphBitSet((param & 0x000f0000)>>16, &((pAdcBase)->schlten2)); \
	}		
	#endif
	


#ifdef __cplusplus
}
#endif

