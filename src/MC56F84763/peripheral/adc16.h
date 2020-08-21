/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  adc16_84xxx.h
*
* $Date:      Dec-19-2014$
*
* $Version:   2.4.8.0$
*
* Description: Header file for the ADC16 low-level driver
*
*  ADC_VERSION_1 .. 56F84xxx devices, see MC56F84xxxRM.pdf
*
*****************************************************************************/

#ifndef __ADC16_H
#define __ADC16_H



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
* The ADC device driver interface uses "ioctl" call to control specific ADC functions
* during operation. For details see "ioctl" call.
*
******************************************************************************/

/************************************************************
* ADC module identifiers
*************************************************************/

/* 16bit SAR ADC on some devices */
#ifdef ADC16_BASE
#define ADC16    (&ArchIO.Adc16)
#endif


/*************************************************************
* arch.h should define device-specific information about ADC
**************************************************************/

#if !defined(ADC16_VERSION)
#error ADC16 not properly described in arch.h (old Quick_Start version?)
#endif

/**************************************************************
* Configuration items for appconfig.h (init values, ...),
**************************************************************/

/* Configuration items for appconfig.h  *

    ADC_0_ADCSC1A_INIT      // Status and Control Register 1
    ADC_0_ADCSC2_INIT       // Status and Control Register 2
    ADC_0_ADCSC3_INIT       // Status and Control Register 3
    ADC_0_ADC16_CFG1_INIT   // Configuration Register 1
    ADC_0_ADC16_CFG2_INIT   // Configuration Register 2
    ADC_0_ADC16_CV1_INIT    // Compare Value Register 1
    ADC_0_ADC16_CV2_INIT    // Compare Value Register 2
    ADC_0_ADC16_OFS_INIT    // Offset Correction Register
    ADC_0_ADC16_PG_INIT     // Plus-Side Gain Register
    ADC_0_ADC16_CLPD_INIT   // Plus-Side General Calibration Value Register
    ADC_0_ADC16_CLPS_INIT   // Plus-Side General Calibration Value Register
    ADC_0_ADC16_CLP4_INIT   // Plus-Side General Calibration Value Register 4
    ADC_0_ADC16_CLP3_INIT   // Plus-Side General Calibration Value Register 3
    ADC_0_ADC16_CLP2_INIT   // Plus-Side General Calibration Value Register 2
    ADC_0_ADC16_CLP1_INIT   // Plus-Side General Calibration Value Register 1
    ADC_0_ADC16_CLP0_INIT   // Plus-Side General Calibration Value Register 0

*/

/***************************************************
* ADC Ioctl commands
****************************************************/
/* command                      |        Param     */

/* ADC control register 1 commands */
#define ADC16_SET_INT                             /* ADC16_ENABLE/ADC16_DISABLE, enable/disable the conversion complete interrupt. An interrupt is asserted when COCO becomes set while the AIEN is high (ADCSC1A->AIEN) */
#define ADC16_SET_INPUT_CHANNEL                   /* ADC16_xxx (xxx=AD0-AD23/VREFH/VREFL/DEACTIVATE/BANDGAP/TEMP_SENSOR), select one of the ADC input channels. Note: Some of the input channel options might not be available for all devices or packages (ADCSC1A->ADCH) */
#define ADC16_TEST_CONVERSION_COMPLETE            /* NULL, return a non-zero value when the conversion complete (COCO) flag is set. The COCO flag is cleared when the ADC Status and Control register 1 (SC1A) is written or when the respective ADC Result register (Rn) is read (ADCSC1A->COCO) */
#define ADC16_WRITE_SC1_REG                       /* UWord16, write the parameter value to the Status and Control register 1. This operation clears the conversion complete flag (ADCSC1A->_) */
#define ADC16_READ_SC1_REG                        /* NULL, read and return value of the Status and Control register 1 as UWord16 (ADCSC1A->_) */

/* ADC control register 2 commands */
#define ADC16_TEST_CONVERSION_ACTIVE              /* NULL,return a non-zero value when a ADC conversion or hardware averaging is in progress and zero when a conversion is completed or aborted (ADCSC2->ADACT)  */
#define ADC16_SET_CONVERSION_TRIGGER              /* ADC16_SW_TRIGGER/ADC16_HW_TRIGGER, set the type of trigger used for initiating a conversion. Use ADC16_SW_TRIGGER when a conversion is initiated by writing to SC1A register. Use ADC16_HW_TRIGGER when a conversion is initiated by the assertion of the ADHWT input after a pulse of the ADHWTSn input (ADCSC2->ADTRG) */
#define ADC16_SET_VOLTAGE_REFERENCE               /* ADC16_SOURCE_xxx (xxx=VREF/ALT/BANDGAP), select the voltage reference source used for conversions (ADCSC2->REFSEL) */
#define ADC16_SET_DMA                             /* ADC16_ENABLE/ADC16_DISABLE, enable/disable the ADC DMA request. When DMA is enabled assert the DMA request on an ADC conversion complete event (ADCSC2->DMAEN) */
#define ADC16_SET_COMPARE_FUNCTION_MODE           /* ADC16_xxx (xxx=LESS_THAN/GREATER_THAN_OR_EQUAL/RANGE_NON_INCLUSIVE/RANGE_INCLUSIVE), set compare function mode. For the RANGE modes, the selection whether inside or outside of range is compared depends on relation of CV1 and CV2 values (ADCSC2->ACFGT, ACREN) */
#define ADC16_SET_COMPARE_FUNCTION                /* ADC16_ENABLE/ADC16_DISABLE, enable/disable the compare function of the conversion result (ADCSC2->ACFE) */
#define ADC16_WRITE_SC2_REG                       /* UWord16, write the parameter value to the Status and Control register 2 (ADCSC2->_) */
#define ADC16_READ_SC2_REG                        /* NULL, read and return value of the Status and Control register 2 as UWord16 (ADCSC2->_) */

/* ADC control register 3 commands */
#define ADC16_SET_CONVERSION_MODE                 /* ADC16_CONV_xxx (xxx=SINGLE/CONTINUOUS), select the conversion mode. When the HW average is enabled, the conversion is completed when the average is calculated and COCO is set (ADCSC3->ADCO) */
#define ADC16_SET_HARDWARE_AVERAGE                /* ADC16_ENABLE/ADC16_DISABLE, enable/disable the hardware average function of the ADC. The number of samples is set by the ADC16_SET_HARDWARE_AVERAGE_SAMPLES ioctl command (ADCSC3->AVGE) */
#define ADC16_SET_HARDWARE_AVERAGE_SAMPLES        /* ADC16_xxx (xxx=4_SAMPLES/8_SAMPLES/16_SAMPLES/32_SAMPLES), select how many ADC conversions will be averaged to create the ADC average result (ADCSC3->AVGS[1:0]) */
#define ADC16_SET_ASSIST_TRIGGER                  /* ADC16_ENABLE/ADC16_DISABLE, enable/disable writes to ADCSC1 COCO bit to be reflected on ADTRG register bit (ADCSC3->ASSITRGEN) */
#define ADC16_SET_CALIBRATION                     /* ADC16_ENABLE/ADC16_DISABLE, enable/disable the calibration sequence (ADCSC3->CAL) */
#define ADC16_TEST_CALIBRATION_START              /* NULL, return a non-zero value when the calibration sequence is in progress and zero when is completed (ADCSC3->CAL) */
#define ADC16_TEST_CALIBRATION_FAILED_FLAG        /* NULL, return a non-zero value when the calibration failed and zero when passed. The calibration sequence will fail if the HW trigger is enabled or any ADC register is written or any stop mode is entered before the calibration sequence completes (ADCSC3->CALF) */
#define ADC16_CLEAR_CALIBRATION_FAILED_FLAG       /* NULL, clear the Calibration Failed flag (ADCSC3->CALF) */
#define ADC16_WRITE_SC3_REG                       /* UWord16, write the parameter value to the Status and Control register 3. Note: an inappropriate write to the register can clear Write-1-to-Clear (CALF) flag (ADCSC3->_) */
#define ADC16_READ_SC3_REG                        /* NULL, read and return value of the Status and Control register 3 as UWord16 (ADCSC3->_) */

/* ADC configuration 1 register */
#define ADC16_SET_LOW_POWER_CFG                   /* ADC16_xxx (xxx=HIGH_SPEED/LOW_POWER), select between the high sample rate or the power consumption-optimized sample rate (ADCCFG->ADLPC) */
#define ADC16_SET_DIVIDER                         /* ADC16_CLOCK_DIVIDER_xxx (xxx=1/2/4/8), select the divide ratio used by the ADC to generate the internal clock ADCK (ADCCFG->ADIV) */
#define ADC16_SET_LONG_SAMPLE_TIME                /* ADC16_ENABLE/ADC16_DISABLE, select between long and short sample time. When long sample time is selected, the sample time might be selected by the ADC16_SELECT_LONG_SAMPLE_TIME ioctl command (ADCCFG->ADLSMP) */
#define ADC16_SET_RESOLUTION                      /* ADC16_MODE_xxx (xxx=8BIT/10BIT/12BIT/16BIT), set the converter's resolution (ADCCFG->MODE) */
#define ADC16_SET_CLOCK_INPUT                     /* ADC16_CLOCK_SEL_xxx (xxx=BUS/BUS_DIV2/ALTCLK/ADATCK), select the ADC input clock source to generate the internal  ADCK clock (ADCCFG->ADICLK) */
#define ADC16_WRITE_CFG1_REG                      /* UWord16, write the parameter value to the Configuration register 1 (ADCCFG1->_) */
#define ADC16_READ_CFG1_REG                       /* NULL, read and return value of the Configuration  register 1 as UWord16 (ADCCFG1->_) */

/* ADC configuration 2 register */
#define ADC16_SELECT_LONG_SAMPLE_TIME             /* ADC16_xxx (xxx=24ADCK/16ADCK/10ADCK/6ADCK), select between the extended sample times when long sample time is enabled by using ADC16_SET_LONG_SAMPLE_TIME ioctl command (ADCCFG2->ADLSTS) */
#define ADC16_SET_HIGH_SPEED                      /* ADC16_ENABLE/ADC16_DISABLE, enable/disable the ADC for very high-speed operation. The conversion sequence is altered with 2 ADCK cycles added to the conversion time to allow higher speed conversion clocks (ADCCFG2->ADHSC) */
#define ADC16_SET_ASYNCH_CLOCK_OUT                /* ADC16_ENABLE/ADC16_DISABLE, enable/disable the  asynchronous clock source and output regardless of the conversion and status of CFG1[ADICLK]. Based on MCU configuration, the asynchronous clock may be used by other modules. See the chip configuration information (ADCCFG2->ADACKEN) */
#define ADC16_WRITE_CFG2_REG                      /* UWord16, write the parameter value to the Configuration register 2 (ADCCFG2->_) */
#define ADC16_READ_CFG2_REG                       /* NULL, read and return value of the Configuration  register 2 as UWord16 (ADCCFG2->_) */

/* ADC Compare Value 1 register */
#define ADC16_WRITE_CV1_REG                       /* UWord16, write the parameter value to the Compare Value 1 register. This register is formatted in the same way as the Result Rn register in different modes of operation for both bit position definition and value format using unsigned or sign-extended 2's complement (ADCCV1->_) */
#define ADC16_READ_CV1_REG                        /* NULL, read and return value of Compare Value 1 register as UWord16 (ADCCV1->_) */

/* ADC Compare Value 2 register */
#define ADC16_WRITE_CV2_REG                       /* UWord16, write the parameter value to the Compare Value 2 register. This register is used only when the compare function is set to one of RANGE modes. The relation of CV1 and CV2 register values determine whether inside-of-range or outside-of-range condition is evaluated (ADCCV2->_) */
#define ADC16_READ_CV2_REG                        /* NULL, read and return value of Compare Value 2 register as UWord16 (ADCCV2->_) */

/* read ADC result register */
#define ADC16_READ_RESULT                         /* NULL, read and return the ADC data result (RA register) as UWord16. The return value contains the result of an ADC conversion of the channel selected by the ADC16_SET_INPUT_CHANNEL ioctl command (ADCRA->_) */

/* ADC offset register */
#define ADC16_WRITE_OFS_REG                       /* UWord16, write the parameter value to the Offset register (ADCOFS->_) */
#define ADC16_READ_OFS_REG                        /* NULL, read and return the Offset register as UWord16  (ADCOFS->_) */

/* ADC calibration registers */
#define ADC16_WRITE_PLUS_SIDE_GAIN_REG            /* UWord16, write the parameter value to the Plus-Side Gain register (ADCPG->_) */
#define ADC16_READ_PLUS_SIDE_GAIN_REG             /* NULL, read and return the Plus-Side Gain register as UWord16  (ADCPG->_) */
#define ADC16_WRITE_CLPD_REG                      /* UWord16, write the parameter value to the Plus-Side General Calibration Value register (ADCCLPD->_) */
#define ADC16_READ_CLPD_REG                       /* NULL, read and return the Plus-Side General Calibration Value register as UWord16  (ADCCLPD->_) */
#define ADC16_WRITE_CLPS_REG                      /* UWord16, write the parameter value to the Plus-Side General Calibration Value register (ADCCLPS->_) */
#define ADC16_READ_CLPS_REG                       /* NULL, read and return the Plus-Side General Calibration Value register as UWord16  (ADCCLPS->_) */
#define ADC16_WRITE_CLP4_REG                      /* UWord16, write the parameter value to the ADC Plus-Side General Calibration Value 4 register (ADCCLP4->_) */
#define ADC16_READ_CLP4_REG                       /* NULL, read and return the Plus-Side General Calibration Value 4 register as UWord16 (ADCCLP4->_) */
#define ADC16_WRITE_CLP3_REG                      /* UWord16, write the parameter value to the ADC Plus-Side General Calibration Value 3 register (ADCCLP3->_) */
#define ADC16_READ_CLP3_REG                       /* NULL, read and return the Plus-Side General Calibration Value 3 register as UWord16 (ADCCLP3->_) */
#define ADC16_WRITE_CLP2_REG                      /* UWord16, write the parameter value to the ADC Plus-Side General Calibration Value 2 register (ADCCLP2->_) */
#define ADC16_READ_CLP2_REG                       /* NULL, read and return the Plus-Side General Calibration Value 2 register as UWord16 (ADCCLP2->_) */
#define ADC16_WRITE_CLP1_REG                      /* UWord16, write the parameter value to the ADC Plus-Side General Calibration Value 1 register (ADCCLP1->_) */
#define ADC16_READ_CLP1_REG                       /* NULL, read and return the Plus-Side General Calibration Value 1 register as UWord16 (ADCCLP1->_) */
#define ADC16_WRITE_CLP0_REG                      /* UWord16, write the parameter value to the ADC Plus-Side General Calibration Value 0 register (ADCCLP0->_) */
#define ADC16_READ_CLP0_REG                       /* NULL, read and return the Plus-Side General Calibration Value 0 register as Uword16 (ADCCLP0->_) */


/*****************************************************************
* Software Layer ioctl() commands
*
*  Word16 ioctl( ADC,Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define ADC16_INIT                                /* NULL, initialize the ADC16 peripheral registers using the appconfig.h _INIT values */


/****************************************************************************
* ADC command parameters
*****************************************************************************/

#define ADC16_ENABLE          1
#define ADC16_DISABLE         0

/* ADCSC1A */
#define ADC16_AD0             ADC16_ADCSC1A_ADCH_AD0
#define ADC16_AD1             ADC16_ADCSC1A_ADCH_AD1
#define ADC16_AD2             ADC16_ADCSC1A_ADCH_AD2
#define ADC16_AD3             ADC16_ADCSC1A_ADCH_AD3
#define ADC16_AD4             ADC16_ADCSC1A_ADCH_AD4
#define ADC16_AD5             ADC16_ADCSC1A_ADCH_AD5
#define ADC16_AD6             ADC16_ADCSC1A_ADCH_AD6
#define ADC16_AD7             ADC16_ADCSC1A_ADCH_AD7
#define ADC16_AD8             ADC16_ADCSC1A_ADCH_AD8
#define ADC16_AD9             ADC16_ADCSC1A_ADCH_AD9
#define ADC16_AD10            ADC16_ADCSC1A_ADCH_AD10
#define ADC16_AD11            ADC16_ADCSC1A_ADCH_AD11
#define ADC16_AD12            ADC16_ADCSC1A_ADCH_AD12
#define ADC16_AD13            ADC16_ADCSC1A_ADCH_AD13
#define ADC16_AD14            ADC16_ADCSC1A_ADCH_AD14
#define ADC16_AD15            ADC16_ADCSC1A_ADCH_AD15
#define ADC16_AD16            ADC16_ADCSC1A_ADCH_AD16
#define ADC16_AD17            ADC16_ADCSC1A_ADCH_AD17
#define ADC16_AD18            ADC16_ADCSC1A_ADCH_AD18
#define ADC16_AD19            ADC16_ADCSC1A_ADCH_AD19
#define ADC16_AD20            ADC16_ADCSC1A_ADCH_AD20
#define ADC16_AD21            ADC16_ADCSC1A_ADCH_AD21
#define ADC16_AD22            ADC16_ADCSC1A_ADCH_AD22
#define ADC16_AD23            ADC16_ADCSC1A_ADCH_AD23
#define ADC16_TEMP_SENSOR     ADC16_ADCSC1A_ADCH_TEMP_SENSOR
#define ADC16_BANDGAP         ADC16_ADCSC1A_ADCH_BANDGAP
#define ADC16_VREFH           ADC16_ADCSC1A_ADCH_VREFH
#define ADC16_VREFL           ADC16_ADCSC1A_ADCH_VREFL
#define ADC16_DEACTIVATE      ADC16_ADCSC1A_ADCH_DEACTIVATE

#define ADC16_4_SAMPLES      ADC16_ADCSC3_AVGS_4_SAMPLES 
#define ADC16_8_SAMPLES      ADC16_ADCSC3_AVGS_8_SAMPLES 
#define ADC16_16_SAMPLES     ADC16_ADCSC3_AVGS_16_SAMPLES
#define ADC16_32_SAMPLES     ADC16_ADCSC3_AVGS_32_SAMPLES

#define ADC16_CONV_SINGLE     0
#define ADC16_CONV_CONTINUOUS 1

#define ADC16_24ADCK          0x0000
#define ADC16_16ADCK          0x0001
#define ADC16_10ADCK          0x0002
#define ADC16_6ADCK           0x0003


/* ADCSC2 */
#define ADC16_SW_TRIGGER      0
#define ADC16_HW_TRIGGER      1
#define ADC16_SOURCE_VREF             ADC16_ADCSC2_REFSEL_VREF
#define ADC16_SOURCE_ALT              ADC16_ADCSC2_REFSEL_ALT
#define ADC16_SOURCE_BANDGAP          ADC16_ADCSC2_REFSEL_BANDGAP
#define ADC16_LESS_THAN               0x0000
#define ADC16_GREATER_THAN_OR_EQUAL   ADC16_ADCSC2_ACFGT
#define ADC16_RANGE_NON_INCLUSIVE     ADC16_ADCSC2_ACREN
#define ADC16_RANGE_INCLUSIVE         (ADC16_ADCSC2_ACFGT | ADC16_ADCSC2_ACREN)


/* ADCCFG */
#define ADC16_LOW_POWER             1
#define ADC16_HIGH_SPEED            0

#define ADC16_CLOCK_DIVIDER_1       ADC16_ADCCFG1_ADIV_DIV1
#define ADC16_CLOCK_DIVIDER_2       ADC16_ADCCFG1_ADIV_DIV2
#define ADC16_CLOCK_DIVIDER_4       ADC16_ADCCFG1_ADIV_DIV4
#define ADC16_CLOCK_DIVIDER_8       ADC16_ADCCFG1_ADIV_DIV8

#define ADC16_MODE_8BIT             ADC16_ADCCFG1_MODE_8BIT
#define ADC16_MODE_10BIT            ADC16_ADCCFG1_MODE_10BIT
#define ADC16_MODE_12BIT            ADC16_ADCCFG1_MODE_12BIT
#define ADC16_MODE_16BIT            ADC16_ADCCFG1_MODE_16BIT

#define ADC16_CLOCK_SEL_BUS         ADC16_ADCCFG1_ADICLK_BUS_CLK
#define ADC16_CLOCK_SEL_BUS_DIV2    ADC16_ADCCFG1_ADICLK_BUS_CLK_DIV2
#define ADC16_CLOCK_SEL_ALTCLK      ADC16_ADCCFG1_ADICLK_ALTCLK
#define ADC16_CLOCK_SEL_ADATCK      ADC16_ADCCFG1_ADICLK_ADATCK


/****************************************************************************
* register and bit names used in the ioctl functions below
*****************************************************************************/

/* Status and control register 1 A (ADCSC1A) */

#define ADC16_ADCSC1A_COCO                 0x0080
#define ADC16_ADCSC1A_AIEN                 0x0040
#define ADC16_ADCSC1A_ADCH_MASK            0x001F
#define ADC16_ADCSC1A_ADCH_AD0             0x0000
#define ADC16_ADCSC1A_ADCH_AD1             0x0001
#define ADC16_ADCSC1A_ADCH_AD2             0x0002
#define ADC16_ADCSC1A_ADCH_AD3             0x0003
#define ADC16_ADCSC1A_ADCH_AD4             0x0004
#define ADC16_ADCSC1A_ADCH_AD5             0x0005
#define ADC16_ADCSC1A_ADCH_AD6             0x0006
#define ADC16_ADCSC1A_ADCH_AD7             0x0007
#define ADC16_ADCSC1A_ADCH_AD8             0x0008
#define ADC16_ADCSC1A_ADCH_AD9             0x0009
#define ADC16_ADCSC1A_ADCH_AD10            0x000A
#define ADC16_ADCSC1A_ADCH_AD11            0x000B
#define ADC16_ADCSC1A_ADCH_AD12            0x000C
#define ADC16_ADCSC1A_ADCH_AD13            0x000D
#define ADC16_ADCSC1A_ADCH_AD14            0x000E
#define ADC16_ADCSC1A_ADCH_AD15            0x000F
#define ADC16_ADCSC1A_ADCH_AD16            0x0010
#define ADC16_ADCSC1A_ADCH_AD17            0x0011
#define ADC16_ADCSC1A_ADCH_AD18            0x0012
#define ADC16_ADCSC1A_ADCH_AD19            0x0013
#define ADC16_ADCSC1A_ADCH_AD20            0x0014
#define ADC16_ADCSC1A_ADCH_AD21            0x0015
#define ADC16_ADCSC1A_ADCH_AD22            0x0016
#define ADC16_ADCSC1A_ADCH_AD23            0x0017
#define ADC16_ADCSC1A_ADCH_TEMP_SENSOR     0x001A
#define ADC16_ADCSC1A_ADCH_BANDGAP         0x001B
#define ADC16_ADCSC1A_ADCH_VREFH           0x001D
#define ADC16_ADCSC1A_ADCH_VREFL           0x001E
#define ADC16_ADCSC1A_ADCH_DEACTIVATE      0x001F


/* Status and control register 2 (ADCSC2) */
#define ADC16_ADCSC2_ADACT                 0x0080
#define ADC16_ADCSC2_ADTRG                 0x0040
#define ADC16_ADCSC2_ACFE                  0x0020
#define ADC16_ADCSC2_ACFGT                 0x0010
#define ADC16_ADCSC2_ACREN                 0x0008
#define ADC16_ADCSC2_ACFGT_ACREN_MASK      (ADC16_ADCSC2_ACFGT | ADC16_ADCSC2_ACREN)
#define ADC16_ADCSC2_DMAEN                 0x0004
#define ADC16_ADCSC2_REFSEL_MASK           0x0003
#define ADC16_ADCSC2_REFSEL_VREF           0x0000
#define ADC16_ADCSC2_REFSEL_ALT            0x0001
#define ADC16_ADCSC2_REFSEL_BANDGAP        0x0002


/* Configuration Register (ADCCFG1) */
#define ADC16_ADCCFG1_ADLPC                 0x0080
#define ADC16_ADCCFG1_ADIV_MASK             0x0060
#define ADC16_ADCCFG1_ADIV_DIV1             0x0000
#define ADC16_ADCCFG1_ADIV_DIV2             0x0020
#define ADC16_ADCCFG1_ADIV_DIV4             0x0040
#define ADC16_ADCCFG1_ADIV_DIV8             0x0060
#define ADC16_ADCCFG1_ADLSMP                0x0010
#define ADC16_ADCCFG1_MODE_MASK             0x000C
#define ADC16_ADCCFG1_MODE_8BIT             0x0000
#define ADC16_ADCCFG1_MODE_10BIT            0x0008
#define ADC16_ADCCFG1_MODE_12BIT            0x0004
#define ADC16_ADCCFG1_MODE_16BIT            0x000C
#define ADC16_ADCCFG1_ADICLK_MASK           0x0003
#define ADC16_ADCCFG1_ADICLK_BUS_CLK        0x0000
#define ADC16_ADCCFG1_ADICLK_BUS_CLK_DIV2   0x0001
#define ADC16_ADCCFG1_ADICLK_ALTCLK         0x0002
#define ADC16_ADCCFG1_ADICLK_ADATCK         0x0003

/* Configuration Register (ADCCFG2) */
#define ADC16_ADCCFG2_ADLSTS_MASK           0x0003
#define ADC16_ADCCFG2_ADHSC                 0x0004
#define ADC16_ADCCFG2_ADACKEN               0x0008

/* Configuration Register ADCSC3 */

#define ADC16_ADCSC3_AVGS_4_SAMPLES         0x0000
#define ADC16_ADCSC3_AVGS_8_SAMPLES         0x0001
#define ADC16_ADCSC3_AVGS_16_SAMPLES        0x0002
#define ADC16_ADCSC3_AVGS_32_SAMPLES        0x0003
#define ADC16_ADCSC3_AVGS_MASK              0x0003
#define ADC16_ADCSC3_AVGE                   0x0004
#define ADC16_ADCSC3_ADCO                   0x0008
#define ADC16_ADCSC3_ASSITRGEN              0x0010
#define ADC16_ADCSC3_CALF                   0x0040
#define ADC16_ADCSC3_CAL                    0x0080

/****************************************************************************
* ADC ioctl macro implementation
*****************************************************************************/

/***********************************************************************
* ADC init
***********************************************************************/

void adc16Init(arch_sADC16 *pAdcBase);
#define ioctlADC16_INIT(pAdcBase, param) adc16Init(pAdcBase)

/***********************************************************************
* ADC Control Register
***********************************************************************/

/* ADCSC1 */

/* to enable/disable interrupt  */
#define ioctlADC16_SET_INT(pAdcBase, param)        \
 if (param) periphBitSet(ADC16_ADCSC1A_AIEN, &((pAdcBase)->adcsc1a)); \
 else periphBitClear(ADC16_ADCSC1A_AIEN, &((pAdcBase)->adcsc1a))

/* to select input channel */
#define ioctlADC16_SET_INPUT_CHANNEL(pAdcBase, param) \
  periphBitGrpSet(ADC16_ADCSC1A_ADCH_MASK, param, &((pAdcBase)->adcsc1a))

/* to test the ADC conversion complete flag  */
#define ioctlADC16_TEST_CONVERSION_COMPLETE(pAdcBase, param) \
 periphBitTest(ADC16_ADCSC1A_COCO, &((pAdcBase)->adcsc1a))

#define ioctlADC16_WRITE_SC1_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adcsc1a))

#define ioctlADC16_READ_SC1_REG(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adcsc1a))


/* ADCSC2 */

#define ioctlADC16_TEST_CONVERSION_ACTIVE(pAdcBase, param) \
  periphBitTest(ADC16_ADCSC2_ADACT, &((pAdcBase)->adcsc2))

/* to select SW or HW trigger */
#define ioctlADC16_SET_CONVERSION_TRIGGER(pAdcBase, param) \
 if (param) periphBitSet(ADC16_ADCSC2_ADTRG, &((pAdcBase)->adcsc2)); \
 else periphBitClear(ADC16_ADCSC2_ADTRG, &((pAdcBase)->adcsc2))

/* to select voltage reference source */
#define ioctlADC16_SET_VOLTAGE_REFERENCE(pAdcBase, param) \
 periphBitGrpSet(ADC16_ADCSC2_REFSEL_MASK, param, &((pAdcBase)->adcsc2))

/* to enable/disable DMA */
#define ioctlADC16_SET_DMA(pAdcBase, param) \
 if (param) periphBitSet(ADC16_ADCSC2_DMAEN, &((pAdcBase)->adcsc2)); \
 else periphBitClear(ADC16_ADCSC2_DMAEN, &((pAdcBase)->adcsc2))

/* set the compare function mode */
#define ioctlADC16_SET_COMPARE_FUNCTION_MODE(pAdcBase, param) \
 periphBitGrpSet(ADC16_ADCSC2_ACFGT_ACREN_MASK, (param), &((pAdcBase)->adcsc2))

/* to enable/disable compare function */
#define ioctlADC16_SET_COMPARE_FUNCTION(pAdcBase, param) \
 if (param) periphBitSet(ADC16_ADCSC2_ACFE, &((pAdcBase)->adcsc2)); \
 else periphBitClear(ADC16_ADCSC2_ACFE, &((pAdcBase)->adcsc2))

#define ioctlADC16_WRITE_SC2_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adcsc2))

#define ioctlADC16_READ_SC2_REG(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adcsc2))


/* ADCSC3 */

/* to select operation mode single/continuous */
#define ioctlADC16_SET_CONVERSION_MODE(pAdcBase, param)\
 if (param) {periphSafeBitSet(ADC16_ADCSC3_CALF, ADC16_ADCSC3_ADCO, &((pAdcBase)->adcsc3));}\
 else periphSafeBitClear(ADC16_ADCSC3_CALF, ADC16_ADCSC3_ADCO, &((pAdcBase)->adcsc3))

#define ioctlADC16_SET_HARDWARE_AVERAGE(pAdcBase, param)\
 if (param) {periphSafeBitSet(ADC16_ADCSC3_CALF, ADC16_ADCSC3_AVGE, &((pAdcBase)->adcsc3));}\
 else periphSafeBitClear(ADC16_ADCSC3_CALF, ADC16_ADCSC3_AVGE, &((pAdcBase)->adcsc3))

#define ioctlADC16_SET_HARDWARE_AVERAGE_SAMPLES(pAdcBase, param)\
  periphSafeBitGrpSet(ADC16_ADCSC3_CALF, ADC16_ADCSC3_AVGS_MASK, param,  &((pAdcBase)->adcsc3))

#define ioctlADC16_SET_ASSIST_TRIGGER(pAdcBase, param)\
 if (param) {periphSafeBitSet(ADC16_ADCSC3_CALF, ADC16_ADCSC3_ASSITRGEN, &((pAdcBase)->adcsc3));}\
 else periphSafeBitClear(ADC16_ADCSC3_CALF, ADC16_ADCSC3_ASSITRGEN, &((pAdcBase)->adcsc3))

#define ioctlADC16_SET_CALIBRATION(pAdcBase, param)\
 if (param) {periphSafeBitSet(ADC16_ADCSC3_CALF, ADC16_ADCSC3_CAL, &((pAdcBase)->adcsc3));}\
 else periphSafeBitClear(ADC16_ADCSC3_CALF, ADC16_ADCSC3_CAL, &((pAdcBase)->adcsc3))

#define ioctlADC16_TEST_CALIBRATION_START(pAdcBase, param)\
 periphBitTest(ADC16_ADCSC3_CAL, &((pAdcBase)->adcsc3))
  
#define ioctlADC16_TEST_CALIBRATION_FAILED_FLAG(pAdcBase, param)\
 periphBitTest(ADC16_ADCSC3_CALF, &((pAdcBase)->adcsc3))
 
#define ioctlADC16_CLEAR_CALIBRATION_FAILED_FLAG(pAdcBase, param)\
 periphSafeAckByOne(ADC16_ADCSC3_CALF, ADC16_ADCSC3_CALF, &((pAdcBase)->adcsc3))

#define ioctlADC16_WRITE_SC3_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adcsc3))

#define ioctlADC16_READ_SC3_REG(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adcsc3))


/* ADCCFG */
/*  controls the speed and power configuration converter */
#define ioctlADC16_SET_LOW_POWER_CFG(pAdcBase, param) \
 if (param) periphBitSet(ADC16_ADCCFG1_ADLPC, &((pAdcBase)->adccfg1)); \
 else periphBitClear(ADC16_ADCCFG1_ADLPC, &((pAdcBase)->adccfg1))

/* to select the divide ratio used by the ADC to generate the internal clock ADCK. */
#define ioctlADC16_SET_DIVIDER(pAdcBase, param) \
  periphBitGrpSet(ADC16_ADCCFG1_ADIV_MASK, param, &((pAdcBase)->adccfg1))

/*  controls the speed and power configuration converter */
#define ioctlADC16_SET_LONG_SAMPLE_TIME(pAdcBase, param) \
 if (param) periphBitSet(ADC16_ADCCFG1_ADLSMP, &((pAdcBase)->adccfg1)); \
 else periphBitClear(ADC16_ADCCFG1_ADLSMP, &((pAdcBase)->adccfg1))

/* to select the divide ratio used by the ADC to generate the internal clock ADCK. */
#define ioctlADC16_SET_RESOLUTION(pAdcBase, param) \
  periphBitGrpSet(ADC16_ADCCFG1_MODE_MASK, param, &((pAdcBase)->adccfg1))

/* to select the divide ratio used by the ADC to generate the internal clock ADCK. */
#define ioctlADC16_SET_CLOCK_INPUT(pAdcBase, param) \
  periphBitGrpSet(ADC16_ADCCFG1_ADICLK_MASK, param, &((pAdcBase)->adccfg1))

#define ioctlADC16_WRITE_CFG1_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adccfg1))

#define ioctlADC16_READ_CFG1_REG(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adccfg1))

/* ADC configuration 2 (ADCCFG2) */

#define ioctlADC16_SELECT_LONG_SAMPLE_TIME(pAdcBase, param) \
  periphBitGrpSet(ADC16_ADCCFG2_ADLSTS_MASK, param, &((pAdcBase)->adccfg2))

#define ioctlADC16_SET_HIGH_SPEED(pAdcBase, param) \
 if (param) periphBitSet(ADC16_ADCCFG2_ADHSC, &((pAdcBase)->adccfg2)); \
 else periphBitClear(ADC16_ADCCFG2_ADHSC, &((pAdcBase)->adccfg2))

#define ioctlADC16_SET_ASYNCH_CLOCK_OUT(pAdcBase, param) \
 if (param) periphBitSet(ADC16_ADCCFG2_ADACKEN, &((pAdcBase)->adccfg2)); \
 else periphBitClear(ADC16_ADCCFG2_ADACKEN, &((pAdcBase)->adccfg2))

#define ioctlADC16_WRITE_CFG2_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adccfg2))

#define ioctlADC16_READ_CFG2_REG(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adccfg2))


/* ADCCV1 */
#define ioctlADC16_WRITE_CV1_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adccv1))

#define ioctlADC16_READ_CV1_REG(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adccv1))


/* ADCCV2 */
#define ioctlADC16_WRITE_CV2_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adccv2))

#define ioctlADC16_READ_CV2_REG(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adccv2))


/* ADCRA */
/* read converted data */
#define ioctlADC16_READ_RESULT(pAdcBase, param) \
  periphMemRead(&((pAdcBase)->adcra))


/* ADC offset register OFS */
#define ioctlADC16_WRITE_OFS_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adcofs))

#define ioctlADC16_READ_OFS_REG(pAdcBase, param)\
 periphMemRead( &((pAdcBase)->adcofs))


/* ADC calibration registers */
#define ioctlADC16_WRITE_PLUS_SIDE_GAIN_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adcpg))

#define ioctlADC16_READ_PLUS_SIDE_GAIN_REG(pAdcBase, param)\
 periphMemRead( &((pAdcBase)->adcpg))

#define ioctlADC16_WRITE_CLPD_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adcclpd))

#define ioctlADC16_READ_CLPD_REG(pAdcBase, param)\
 periphMemRead( &((pAdcBase)->adcclpd))

#define ioctlADC16_WRITE_CLPS_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adcclps))

#define ioctlADC16_READ_CLPS_REG(pAdcBase, param)\
 periphMemRead( &((pAdcBase)->adcclps))

#define ioctlADC16_WRITE_CLP4_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adcclp4))

#define ioctlADC16_READ_CLP4_REG(pAdcBase, param)\
 periphMemRead( &((pAdcBase)->adcclp4))

#define ioctlADC16_WRITE_CLP3_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adcclp3))

#define ioctlADC16_READ_CLP3_REG(pAdcBase, param)\
 periphMemRead( &((pAdcBase)->adcclp3))

#define ioctlADC16_WRITE_CLP2_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adcclp2))

#define ioctlADC16_READ_CLP2_REG(pAdcBase, param)\
 periphMemRead( &((pAdcBase)->adcclp2))

#define ioctlADC16_WRITE_CLP1_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adcclp1))

#define ioctlADC16_READ_CLP1_REG(pAdcBase, param)\
 periphMemRead( &((pAdcBase)->adcclp1))

#define ioctlADC16_WRITE_CLP0_REG(pAdcBase, param)\
 periphMemWrite(param, &((pAdcBase)->adcclp0))

#define ioctlADC16_READ_CLP0_REG(pAdcBase, param)\
 periphMemRead( &((pAdcBase)->adcclp0))

#ifdef __cplusplus
}
#endif

#endif

