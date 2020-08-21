/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  dac.h
*
* $Date:      Dec-17-2014$
*
* $Version:   2.5.15.0$
*
* Description: Header file for the DAC driver
* 
* This file supports different hardware versions of the module. A version
* of module used in your project is defined in the "arch.h" processor 
* architecture definition file.
*
*  DAC_VERSION_1 .. 56F802x/3x devices, see MC56F802x3xRM.pdf
*                   56F82xx devices, see MC56F82xxRM.pdf 
*  DAC_VERSION_2 .. 56F823xx devices, see MC56F823xxRM.pdf, 56F827xx devices, see MC56F827xxRM.pdf, 
*                   56F844xx devices, see MC56F844xxRM.pdf, 56F847xx devices, see MC56F847XXRM.pdf
*
*******************************************************************************/

#ifndef __DAC_H
#define __DAC_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before dac.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*
*                      General Interface Description
*
*
* The Programmable Interval Timer (DAC) module contains a 16-bit up counter, 
* a modulo register and a control register. The modulo and control registers 
* are read/writable. The counter is read only.
*
* The modulo register is loaded with a value to count to and the prescaler is 
* set to determine the counting rate. When enabled, the counter counts up to 
* the modulo value and sets a flag (and an interrupt request if enabled), 
* resets to $0000, and resumes counting.
*
******************************************************************************/

/************************************************************
* DAC module identifiers
*************************************************************/

#ifdef DAC0_BASE
#define DAC_0 (&ArchIO.Dac0)
#endif
#ifdef DAC1_BASE
#define DAC_1 (&ArchIO.Dac1)
#endif

#ifdef DAC_BASE
#define DAC (&ArchIO.Dac)
#endif

#ifdef DACA_BASE
#define DAC_A (&ArchIO.DacA)
#endif

#ifdef DACB_BASE
#define DAC_B (&ArchIO.DacB)
#endif


/*************************************************************
* arch.h should define device-specific information about DAC
**************************************************************/

#if !defined(DAC_VERSION)
#error DAC not properly described in arch.h
#endif

/****************************************************
* Configurable items, i.e. defines for appconfig.h
*****************************************************

  #define DAC_x_CTRL_INIT 
  #define DAC_x_DATA_INIT 
  #define DAC_x_STEP_INIT
  #define DAC_x_MAXVAL_INIT
  #define DAC_x_MINVAL_INIT

*/

/*****************************************************************
* Single-Instruction ioctl() commands
*
*  Word16 ioctl( DAC_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define DAC_MODULE                 /* DAC_ENABLE/DAC_DISABLE, enable/disable the DAC module. Before the DAC module is used; the DAC device should be configured (in disabled state) and then enabled. (CTRL0->PDN) */
#define DAC_SET_DATA_FORMAT        /* DAC_RIGHT_ALIGNED_FMT/DAC_LEFT_ALIGNED_FMT, configure the data alignment for the DATA, STEP, MINVAL and MAXVAL Registers. The alignment defines what bits of the registers contain the 12-bit DAC value */
#define DAC_SET_SYNC_SOURCE        /* DAC_IPBUS_SOURCE/DAC_SYNCIN_SOURCE, select the DAC trigger signal to be used to trigger an update of the buffered data to the analog DAC output. Restriction: Do not set SYNC_EN low when DMA_EN is set high. */


#define DAC_WRITE_CONTROL_REG      /* UWord16, write the parameter value into the DAC Control Register (CTRL0->_) */
#define DAC_READ_CONTROL_REG       /* NULL, read and return the value of the DAC Control Register (CTRL0->_) */

#define DAC_WRITE_DATA             /* UWord16, write the parameter value into the DAC DATA Register. This causes the DAC output to be changed after the next update-trigger signal which is either SYNC_IN or IP Bus clock */
#define DAC_READ_DATA              /* NULL, read and return a value of the DAC Data Register */
#define DAC_WRITE_STEP             /* UWord16, write the parameter value into the DAC STEP Register. This value is used anytime the DAC is switched to an automatic mode */
#define DAC_READ_STEP              /* NULL,  read and return a value of the DAC Step Register */
#define DAC_WRITE_MINVAL           /* UWord16, write the parameter value into the DAC Minimum Value Register. This value is used anytime the DAC is switched to an automatic mode */
#define DAC_READ_MINVAL            /* NULL, read and return a value of the DAC Minimum Value Register */
#define DAC_WRITE_MAXVAL           /* UWord16, write the parameter value into the DAC Maximum Value Register. This value is used anytime the DAC is switched to an automatic mode */
#define DAC_READ_MAXVAL            /* NULL, read and return a value of the DAC Maximum Value Register */

#if DAC_VERSION == 1
#define DAC_DISABLE_FILTER         /* NULL, disable the glitch-suppression filter. See more details about the filter at DAC_ENABLE_FILTER */
#endif

#if DAC_VERSION == 2

#define DAC_DMA_ENABLE              /* DAC_ENABLE/DAC_DISABLE, enable/disable the DMA to feed the DAC output */
#define DAC_SET_SPEED               /* DAC_LOW_SPEED/DAC_HIGH_SPEED, select  between speed and power while operating in normal mode. Setting this input low selects high speed mode, in which the settling time of the DAC is 1 µs (faster response) but at the expense of higher power consumption (CTRL0-> HSLS) */
#define DAC_SET_WATER_MARK_LEVEL    /* DAC_LEVEL_x (x=0/2/4/6), select DAC water mark level. When the level of FIFO is less than or equal to this field, a DMA request should be sent. The FIFO used for DMA support generates a watermark signal depending on the value of WTMK_LVL, which is used for asserting a DMA request (CTRL0->WTMK_LVL) */
#define DAC_READ_FIFO_EMPTY         /* NULL, read and return the empty status of FIFO (STATUS->EMPTY) */
#define DAC_READ_FIFO_FULL          /* NULL, read and return the full status of FIFO (STATUS->FULL) */

#define DAC_ENABLE_FILTER           /* NULL, enable the glitch-suppression filter on the DAC output. The glitch suppression filter introduces a latency between the DATA Register update (both manual or automatic) and the actual DAC output update */
#define DAC_DISABLE_FILTER          /* NULL, disable the glitch-suppression filter. See more details about the filter at DAC_ENABLE_FILTER */
#define DAC_SET_FILTER              /* UWord16 value 0-31, set the number of IP Bus clock cycles for which the DAC output is held unchanged after new data is presented to the analog DAC's inputs. The number of clock cycles for which DAC output is held unchanged is equal to the value of FILT_CNT (CTRL1->FLT_CNT) */


#endif
/*****************************************************************
* Multi-Instruction ioctl() commands
*
*  Word16 ioctl( DAC_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/

#define DAC_SET_AUTO_MODE           /* DAC_AUTO_xxx (xxx=OFF/SAWTOOTH1/SAWTOOTH2/TRIANGLE), set generation of a shaped analog signal on the DAC output */

#if DAC_VERSION == 1
#define DAC_ENABLE_FILTER           /* UWord16 value 0 (=disable) or 1-7 (=enable), enable/disable the glitch-suppression filter on the DAC output. The glitch suppression filter introduces a latency between the DATA Register update (both manual or automatic) and the actual DAC output update. The parameter value (1-7) represents a number of  IPBus clock cycles the DAC output is held unchanged after new data is presented */
#endif


/*****************************************************************
* Software Layer ioctl() commands
*
*  Word16 ioctl( DAC_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define DAC_INIT                    /* NULL, Initialize DAC periheral registers using the appconfig.h _INIT values */


/***********************************************************************************************************
** DAC PARAMETERS DEFINITION                                                                        **
***********************************************************************************************************/

#define DAC_ENABLE               1
#define DAC_DISABLE              0

#define DAC_RIGHT_ALIGNED_FMT    0
#define DAC_LEFT_ALIGNED_FMT     1   

#define DAC_IPBUS_SOURCE         0
#define DAC_SYNCIN_SOURCE        1

#define DAC_AUTO_OFF             0
#define DAC_AUTO_SAWTOOTH1       (DAC_CTRL_AUTO | DAC_CTRL_UP)
#define DAC_AUTO_SAWTOOTH2       (DAC_CTRL_AUTO | DAC_CTRL_DOWN)
#define DAC_AUTO_TRIANGLE        (DAC_CTRL_AUTO | DAC_CTRL_UP | DAC_CTRL_DOWN)

#if DAC_VERSION == 2

#define DAC_LOW_SPEED            1
#define DAC_HIGH_SPEED           0

#define DAC_LEVEL_0             0x0000
#define DAC_LEVEL_2             0x0100
#define DAC_LEVEL_4             0x0200
#define DAC_LEVEL_6             0x0300


#endif


/****************************************************************************
* register and bit names used in the ioctl functions below
*****************************************************************************/

/* CTRL register */

#define DAC_CTRL_FILT_EN         0x1000
#define DAC_CTRL_UP              0x0020
#define DAC_CTRL_DOWN            0x0010
#define DAC_CTRL_FORMAT          0x0002
#define DAC_CTRL_PDN             0x0001

#if DAC_VERSION == 1
#define DAC_CTRL_FILT_CNT_MASK   0xe000
#define DAC_CTRL_AUTO            0x0008
#define DAC_CTRL_SYNC_EN         0x0004
#endif

#if DAC_VERSION == 2
#define DAC_CTRL_AUTO            0x0008
#define DAC_CTRL_SYNC_EN         0x0004
#define DAC_CTRL_WTMK_LVL        0x0300
#define DAC_CTRL_HSLS            0x0040
#define DAC_CTRL_DMA_EN          0x0080

#define DAC_STATUS_EMPTY         0x0001
#define DAC_STATUS_FULL          0x0002
#define DAC_CTRL1_FILT_CNT       0x003F

#endif



/****************************************************************************
* DAC ioctl macro implementation
*****************************************************************************/

/* DAC init */

void dacInit(arch_sDAC *pDacBase);
#define ioctlDAC_INIT(pDacBase, param) dacInit(pDacBase)

/* DAC control register */

#define ioctlDAC_MODULE(pDacBase, param) \
  if (param) periphBitClear(DAC_CTRL_PDN, &((pDacBase)->ctrl)); \
  else periphBitSet(DAC_CTRL_PDN, &((pDacBase)->ctrl))

#define ioctlDAC_SET_DATA_FORMAT(pDacBase, param) \
  if (param) periphBitSet(DAC_CTRL_FORMAT, &((pDacBase)->ctrl)); \
  else periphBitClear(DAC_CTRL_FORMAT, &((pDacBase)->ctrl))
  
#define ioctlDAC_SET_SYNC_SOURCE(pDacBase, param) \
  if (param) periphBitSet(DAC_CTRL_SYNC_EN, &((pDacBase)->ctrl)); \
  else periphBitClear(DAC_CTRL_SYNC_EN, &((pDacBase)->ctrl))
  
#define ioctlDAC_SET_AUTO_MODE(pDacBase, param) \
  periphBitGrpSet(DAC_CTRL_AUTO | DAC_CTRL_UP | DAC_CTRL_DOWN, \
    param, &((pDacBase)->ctrl))

#define ioctlDAC_WRITE_CONTROL_REG(pDacBase, param) \
  periphMemWrite(param, &((pDacBase)->ctrl))

#define ioctlDAC_READ_CONTROL_REG(pDacBase, param) \
  periphMemRead(&((pDacBase)->ctrl))

/* DAC data register */

#define ioctlDAC_WRITE_DATA(pDacBase, param) \
  periphMemWrite(param, &((pDacBase)->data))

#define ioctlDAC_READ_DATA(pDacBase, param) \
  periphMemRead(&((pDacBase)->data))

/* DAC auto-mode registers */

#define ioctlDAC_WRITE_STEP(pDacBase, param) \
  periphMemWrite(param, &((pDacBase)->step))

#define ioctlDAC_READ_STEP(pDacBase, param) \
  periphMemRead(&((pDacBase)->step))

#define ioctlDAC_WRITE_MINVAL(pDacBase, param) \
  periphMemWrite(param, &((pDacBase)->minval))

#define ioctlDAC_READ_MINVAL(pDacBase, param) \
  periphMemRead(&((pDacBase)->minval))

#define ioctlDAC_WRITE_MAXVAL(pDacBase, param) \
  periphMemWrite(param, &((pDacBase)->maxval))

#define ioctlDAC_READ_MAXVAL(pDacBase, param) \
  periphMemRead(&((pDacBase)->maxval))

#if DAC_VERSION == 1

#define ioctlDAC_ENABLE_FILTER(pDacBase, param) \
  if(param) periphBitGrpRS(DAC_CTRL_FILT_CNT_MASK | DAC_CTRL_FILT_EN, \
    DAC_CTRL_FILT_EN | ((param)) << 13, &((pDacBase)->ctrl)); \
  else periphBitSet(DAC_CTRL_FILT_CNT_MASK | DAC_CTRL_FILT_EN, &((pDacBase)->ctrl))

#define ioctlDAC_DISABLE_FILTER(pDacBase, param) \
  periphBitClear(DAC_CTRL_FILT_CNT_MASK | DAC_CTRL_FILT_EN, &((pDacBase)->ctrl))

#endif

#if DAC_VERSION == 2

#define ioctlDAC_SET_WATER_MARK_LEVEL(pDacBase, param) \
  periphBitGrpSet(DAC_CTRL_WTMK_LVL, param, &((pDacBase)->ctrl))

#define ioctlDAC_SET_SPEED(pDacBase, param) \
  if (param) periphBitSet(DAC_CTRL_HSLS , &((pDacBase)->ctrl)); \
  else periphBitClear(DAC_CTRL_HSLS , &((pDacBase)->ctrl))

#define ioctlDAC_DMA_ENABLE(pDacBase, param) \
  if (param) periphBitSet(DAC_CTRL_DMA_EN , &((pDacBase)->ctrl)); \
  else periphBitClear(DAC_CTRL_DMA_EN , &((pDacBase)->ctrl))

#define ioctlDAC_READ_FIFO_EMPTY(pDacBase, param) \
  periphBitTest(DAC_STATUS_EMPTY, &((pDacBase)->status))

#define ioctlDAC_READ_FIFO_FULL(pDacBase, param) \
  periphBitTest(DAC_STATUS_FULL, &((pDacBase)->status))

#define ioctlDAC_ENABLE_FILTER(pDacBase, param) \
  periphBitSet(DAC_CTRL_FILT_EN , &((pDacBase)->ctrl))

#define ioctlDAC_DISABLE_FILTER(pDacBase, param) \
  periphBitClear(DAC_CTRL_FILT_EN , &((pDacBase)->ctrl))

#define ioctlDAC_SET_FILTER(pDacBase, param) \
  periphBitGrpSet(DAC_CTRL1_FILT_CNT, param, &((pDacBase)->ctrl1))

#endif


#ifdef __cplusplus
}
#endif

#endif                                      
