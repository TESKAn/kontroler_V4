/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  xbar.h
*
* $Date:      May-30-2013$
*
* $Version:   2.5.12.0$
*
* Description: Header file for the XBAR driver
*
* This file supports different hardware versions of the module. A version
* of module used in your project is defined in the "arch.h" processor 
* architecture definition file.
*
*  XBAR_VERSION_1 .. 56F82xx devices, see MC56F82xxRM.pdf
*  XBAR_VERSION_2 .. 56F84xxx devices, see MC56F845xxRM.pdf
*  XBAR_VERSION_3 .. 56F827xx devices, see MC56F827xxRM.pdf
*
*******************************************************************************/

#ifndef __XBAR_H
#define __XBAR_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before xbar.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*
*                      General Interface Description
*
* The CrossBar Switch module (XBAR) implements an array of 30 outputs and 22 
* inputs of combination digital multiplexes. All 30 multiplexes share the same 
* 22 inputs in same order. All XBAR registers can by write prodected by SYS module.
*
******************************************************************************/

/************************************************************
* XBAR module identifiers, correspond to module base address
*************************************************************/
#if XBAR_VERSION == 1
#ifdef XBAR_BASE
#define XBAR    (&ArchIO.Xbar)
#endif
#else
#ifdef XBARA_BASE
#define XBAR_A    (&ArchIO.XbarA)
#endif

#ifdef XBARB_BASE
#define XBAR_B    (&ArchIO.XbarB)
#endif
#endif 
/*************************************************************
* arch.h should define device-specific information about XBAR
**************************************************************/

#if !defined(XBAR_VERSION)
#error XBAR not properly described in arch.h (old Quick_Start version?)
#endif

/****************************************************
* Configurable items, i.e. defines, for appconfig.h
*****************************************************

  #define  XBAR_XBC0_INIT     0x0000 
  #define  XBAR_XBC1_INIT     0x0000
  #define  XBAR_XBC2_INIT     0x0000
  #define  XBAR_XBC3_INIT     0x0000
  #define  XBAR_XBC4_INIT     0x0000
  #define  XBAR_XBC5_INIT     0x0000
  #define  XBAR_XBC6_INIT     0x0000
  #define  XBAR_XBC7_INIT     0x0000
  #define  XBAR_XBC8_INIT     0x0000
  #define  XBAR_XBC9_INIT     0x0000
  #define  XBAR_XBC10_INIT    0x0000
  #define  XBAR_XBC11_INIT    0x0000
  #define  XBAR_XBC12_INIT    0x0000
  #define  XBAR_XBC13_INIT    0x0000
  #define  XBAR_XBC14_INIT    0x0000

*/

/*****************************************************************
* Single-Instruction  ioctl() commands
*
*  Word16 ioctl( XBAR_module_identifier, Command_name, Parameter );
*
******************************************************************

        COMMAND NAME                      PARAMETERS, COMMENTS
------------------------------------------------------------------ */
#if XBAR_VERSION == 1
#define XBAR_WRITE_CROSSBAR_REG_0  /* UWord16, Write the Crossbar Control Register 0  (XB_XBC0->_) */
#define XBAR_WRITE_CROSSBAR_REG_1  /* UWord16, Write the Crossbar Control Register 1  (XB_XBC1->_) */
#define XBAR_WRITE_CROSSBAR_REG_2  /* UWord16, Write the Crossbar Control Register 2  (XB_XBC2->_) */
#define XBAR_WRITE_CROSSBAR_REG_3  /* UWord16, Write the Crossbar Control Register 3  (XB_XBC3->_) */
#define XBAR_WRITE_CROSSBAR_REG_4  /* UWord16, Write the Crossbar Control Register 4  (XB_XBC4->_) */
#define XBAR_WRITE_CROSSBAR_REG_5  /* UWord16, Write the Crossbar Control Register 5  (XB_XBC5->_) */
#define XBAR_WRITE_CROSSBAR_REG_6  /* UWord16, Write the Crossbar Control Register 6  (XB_XBC6->_) */
#define XBAR_WRITE_CROSSBAR_REG_7  /* UWord16, Write the Crossbar Control Register 7  (XB_XBC7->_) */
#define XBAR_WRITE_CROSSBAR_REG_8  /* UWord16, Write the Crossbar Control Register 8  (XB_XBC8->_) */
#define XBAR_WRITE_CROSSBAR_REG_9  /* UWord16, Write the Crossbar Control Register 9  (XB_XBC9->_) */
#define XBAR_WRITE_CROSSBAR_REG_10 /* UWord16, Write the Crossbar Control Register 10 (XB_XBC10->_) */
#define XBAR_WRITE_CROSSBAR_REG_11 /* UWord16, Write the Crossbar Control Register 11 (XB_XBC11->_) */
#define XBAR_WRITE_CROSSBAR_REG_12 /* UWord16, Write the Crossbar Control Register 12 (XB_XBC12->_) */
#define XBAR_WRITE_CROSSBAR_REG_13 /* UWord16, Write the Crossbar Control Register 13 (XB_XBC13->_) */
#define XBAR_WRITE_CROSSBAR_REG_14 /* UWord16, Write the Crossbar Control Register 14 (XB_XBC14->_) */

#define XBAR_READ_CROSSBAR_REG_0  /* NULL, Read and return the value of the Crossbar Control Register 0  (XB_XBC0->_) */
#define XBAR_READ_CROSSBAR_REG_1  /* NULL, Read and return the value of the Crossbar Control Register 1  (XB_XBC1->_) */
#define XBAR_READ_CROSSBAR_REG_2  /* NULL, Read and return the value of the Crossbar Control Register 2  (XB_XBC2->_) */
#define XBAR_READ_CROSSBAR_REG_3  /* NULL, Read and return the value of the Crossbar Control Register 3  (XB_XBC3->_) */
#define XBAR_READ_CROSSBAR_REG_4  /* NULL, Read and return the value of the Crossbar Control Register 4  (XB_XBC4->_) */
#define XBAR_READ_CROSSBAR_REG_5  /* NULL, Read and return the value of the Crossbar Control Register 5  (XB_XBC5->_) */
#define XBAR_READ_CROSSBAR_REG_6  /* NULL, Read and return the value of the Crossbar Control Register 6  (XB_XBC6->_) */
#define XBAR_READ_CROSSBAR_REG_7  /* NULL, Read and return the value of the Crossbar Control Register 7  (XB_XBC7->_) */
#define XBAR_READ_CROSSBAR_REG_8  /* NULL, Read and return the value of the Crossbar Control Register 8  (XB_XBC8->_) */
#define XBAR_READ_CROSSBAR_REG_9  /* NULL, Read and return the value of the Crossbar Control Register 9  (XB_XBC9->_) */
#define XBAR_READ_CROSSBAR_REG_10 /* NULL, Read and return the value of the Crossbar Control Register 10 (XB_XBC10->_) */
#define XBAR_READ_CROSSBAR_REG_11 /* NULL, Read and return the value of the Crossbar Control Register 11 (XB_XBC11->_) */
#define XBAR_READ_CROSSBAR_REG_12 /* NULL, Read and return the value of the Crossbar Control Register 12 (XB_XBC12->_) */
#define XBAR_READ_CROSSBAR_REG_13 /* NULL, Read and return the value of the Crossbar Control Register 13 (XB_XBC13->_) */
#define XBAR_READ_CROSSBAR_REG_14 /* NULL, Read and return the value of the Crossbar Control Register 14 (XB_XBC14->_) */
#endif  

#if XBAR_VERSION == 2 || XBAR_VERSION == 3

/*Write commands for crossbar switch A for version 2 and 3*/
#define XBAR_A_WRITE_CROSSBAR_REG_0  /* UWord16, Write the Crossbar A Select Register 0  (XBARA_SEL0->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_1  /* UWord16, Write the Crossbar A Select Register 1  (XBARA_SEL1->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_2  /* UWord16, Write the Crossbar A Select Register 2  (XBARA_SEL2->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_3  /* UWord16, Write the Crossbar A Select Register 3  (XBARA_SEL3->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_4  /* UWord16, Write the Crossbar A Select Register 4  (XBARA_SEL4->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_5  /* UWord16, Write the Crossbar A Select Register 5  (XBARA_SEL5->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_6  /* UWord16, Write the Crossbar A Select Register 6  (XBARA_SEL6->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_7  /* UWord16, Write the Crossbar A Select Register 7  (XBARA_SEL7->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_8  /* UWord16, Write the Crossbar A Select Register 8  (XBARA_SEL8->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_9  /* UWord16, Write the Crossbar A Select Register 9  (XBARA_SEL9->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_10 /* UWord16, Write the Crossbar A Select Register 10 (XBARA_SEL10->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_11 /* UWord16, Write the Crossbar A Select Register 11 (XBARA_SEL11->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_12 /* UWord16, Write the Crossbar A Select Register 12 (XBARA_SEL12->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_13 /* UWord16, Write the Crossbar A Select Register 13 (XBARA_SEL13->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_14 /* UWord16, Write the Crossbar A Select Register 14 (XBARA_SEL14->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_15 /* UWord16, Write the Crossbar A Select Register 15 (XBARA_SEL15->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_16 /* UWord16, Write the Crossbar A Select Register 16 (XBARA_SEL16->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_17 /* UWord16, Write the Crossbar A Select Register 17 (XBARA_SEL17->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_18 /* UWord16, Write the Crossbar A Select Register 18 (XBARA_SEL18->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_19 /* UWord16, Write the Crossbar A Select Register 19 (XBARA_SEL19->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_20 /* UWord16, Write the Crossbar A Select Register 20 (XBARA_SEL20->_) */
/*Read commands for crossbar switch A for version 2 and 3*/
#define XBAR_A_READ_CROSSBAR_REG_0  /* NULL, Read and return the value of the Crossbar A Select Register 0  (XBARA_SEL0->_) */
#define XBAR_A_READ_CROSSBAR_REG_1  /* NULL, Read and return the value of the Crossbar A Select Register 1  (XBARA_SEL1->_) */
#define XBAR_A_READ_CROSSBAR_REG_2  /* NULL, Read and return the value of the Crossbar A Select Register 2  (XBARA_SEL2->_) */
#define XBAR_A_READ_CROSSBAR_REG_3  /* NULL, Read and return the value of the Crossbar A Select Register 3  (XBARA_SEL3->_) */
#define XBAR_A_READ_CROSSBAR_REG_4  /* NULL, Read and return the value of the Crossbar A Select Register 4  (XBARA_SEL4->_) */
#define XBAR_A_READ_CROSSBAR_REG_5  /* NULL, Read and return the value of the Crossbar A Select Register 5  (XBARA_SEL5->_) */
#define XBAR_A_READ_CROSSBAR_REG_6  /* NULL, Read and return the value of the Crossbar A Select Register 6  (XBARA_SEL6->_) */
#define XBAR_A_READ_CROSSBAR_REG_7  /* NULL, Read and return the value of the Crossbar A Select Register 7  (XBARA_SEL7->_) */
#define XBAR_A_READ_CROSSBAR_REG_8  /* NULL, Read and return the value of the Crossbar A Select Register 8  (XBARA_SEL8->_) */
#define XBAR_A_READ_CROSSBAR_REG_9  /* NULL, Read and return the value of the Crossbar A Select Register 9  (XBARA_SEL9->_) */
#define XBAR_A_READ_CROSSBAR_REG_10 /* NULL, Read and return the value of the Crossbar A Select Register 10 (XBARA_SEL10->_) */
#define XBAR_A_READ_CROSSBAR_REG_11 /* NULL, Read and return the value of the Crossbar A Select Register 11 (XBARA_SEL11->_) */
#define XBAR_A_READ_CROSSBAR_REG_12 /* NULL, Read and return the value of the Crossbar A Select Register 12 (XBARA_SEL12->_) */
#define XBAR_A_READ_CROSSBAR_REG_13 /* NULL, Read and return the value of the Crossbar A Select Register 13 (XBARA_SEL13->_) */
#define XBAR_A_READ_CROSSBAR_REG_14 /* NULL, Read and return the value of the Crossbar A Select Register 14 (XBARA_SEL14->_) */
#define XBAR_A_READ_CROSSBAR_REG_15 /* NULL, Read and return the value of the Crossbar A Select Register 15 (XBARA_SEL15->_) */
#define XBAR_A_READ_CROSSBAR_REG_16 /* NULL, Read and return the value of the Crossbar A Select Register 16 (XBARA_SEL16->_) */
#define XBAR_A_READ_CROSSBAR_REG_17 /* NULL, Read and return the value of the Crossbar A Select Register 17 (XBARA_SEL17->_) */
#define XBAR_A_READ_CROSSBAR_REG_18 /* NULL, Read and return the value of the Crossbar A Select Register 18 (XBARA_SEL18->_) */
#define XBAR_A_READ_CROSSBAR_REG_19 /* NULL, Read and return the value of the Crossbar A Select Register 19 (XBARA_SEL19->_) */
#define XBAR_A_READ_CROSSBAR_REG_20 /* NULL, Read and return the value of the Crossbar A Select Register 20 (XBARA_SEL20->_) */
/*Write commands for crossbar switch B for version 2 and 3*/
#define XBAR_B_WRITE_CROSSBAR_REG_0  /* UWord16, Write the Crossbar the Crossbar B Select Register 0 (XBARB_SEL0->_) */
#define XBAR_B_WRITE_CROSSBAR_REG_1  /* UWord16, Write the Crossbar the Crossbar B Select Register 1 (XBARB_SEL1->_) */
#define XBAR_B_WRITE_CROSSBAR_REG_2  /* UWord16, Write the Crossbar the Crossbar B Select Register 2 (XBARB_SEL2->_) */
#define XBAR_B_WRITE_CROSSBAR_REG_3  /* UWord16, Write the Crossbar the Crossbar B Select Register 3 (XBARB_SEL3->_) */
#define XBAR_B_WRITE_CROSSBAR_REG_4  /* UWord16, Write the Crossbar the Crossbar B Select Register 4 (XBARB_SEL4->_) */
#define XBAR_B_WRITE_CROSSBAR_REG_5  /* UWord16, Write the Crossbar the Crossbar B Select Register 5 (XBARB_SEL5->_) */
#define XBAR_B_WRITE_CROSSBAR_REG_6  /* UWord16, Write the Crossbar the Crossbar B Select Register 6 (XBARB_SEL6->_) */
#define XBAR_B_WRITE_CROSSBAR_REG_7  /* UWord16, Write the Crossbar the Crossbar B Select Register 7 (XBARB_SEL7->_) */
/*Read commands for crossbar switch B for version 2 and 3*/
#define XBAR_B_READ_CROSSBAR_REG_0  /* NULL, Read and return the value of the Crossbar B Select Register 0 (XBARB_SEL0->_) */
#define XBAR_B_READ_CROSSBAR_REG_1  /* NULL, Read and return the value of the Crossbar B Select Register 1 (XBARB_SEL1->_) */
#define XBAR_B_READ_CROSSBAR_REG_2  /* NULL, Read and return the value of the Crossbar B Select Register 2 (XBARB_SEL2->_) */
#define XBAR_B_READ_CROSSBAR_REG_3  /* NULL, Read and return the value of the Crossbar B Select Register 3 (XBARB_SEL3->_) */
#define XBAR_B_READ_CROSSBAR_REG_4  /* NULL, Read and return the value of the Crossbar B Select Register 4 (XBARB_SEL4->_) */
#define XBAR_B_READ_CROSSBAR_REG_5  /* NULL, Read and return the value of the Crossbar B Select Register 5 (XBARB_SEL5->_) */
#define XBAR_B_READ_CROSSBAR_REG_6  /* NULL, Read and return the value of the Crossbar B Select Register 6 (XBARB_SEL6->_) */
#define XBAR_B_READ_CROSSBAR_REG_7  /* NULL, Read and return the value of the Crossbar B Select Register 7 (XBARB_SEL7->_) */
                                                              
#if XBAR_VERSION == 2
/*Write commands for crossbar switch A for version 2*/
#define XBAR_A_WRITE_CROSSBAR_REG_21 /* UWord16, Write the Crossbar A Select Register 21 (XBARA_SEL21->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_22 /* UWord16, Write the Crossbar A Select Register 22 (XBARA_SEL22->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_23 /* UWord16, Write the Crossbar A Select Register 23 (XBARA_SEL23->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_24 /* UWord16, Write the Crossbar A Select Register 24 (XBARA_SEL24->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_25 /* UWord16, Write the Crossbar A Select Register 25 (XBARA_SEL25->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_26 /* UWord16, Write the Crossbar A Select Register 26 (XBARA_SEL26->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_27 /* UWord16, Write the Crossbar A Select Register 27 (XBARA_SEL27->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_28 /* UWord16, Write the Crossbar A Select Register 28 (XBARA_SEL28->_) */
#define XBAR_A_WRITE_CROSSBAR_REG_29 /* UWord16, Write the Crossbar A Select Register 29 (XBARA_SEL29->_) */

/*Read commands for crossbar switch A for version 2*/       
#define XBAR_A_READ_CROSSBAR_REG_21 /* NULL, Read and return the value of the Crossbar A Select Register 21 (XBARA_SEL21->_) */
#define XBAR_A_READ_CROSSBAR_REG_22 /* NULL, Read and return the value of the Crossbar A Select Register 22 (XBARA_SEL22->_) */
#define XBAR_A_READ_CROSSBAR_REG_23 /* NULL, Read and return the value of the Crossbar A Select Register 23 (XBARA_SEL23->_) */
#define XBAR_A_READ_CROSSBAR_REG_24 /* NULL, Read and return the value of the Crossbar A Select Register 24 (XBARA_SEL24->_) */
#define XBAR_A_READ_CROSSBAR_REG_25 /* NULL, Read and return the value of the Crossbar A Select Register 25 (XBARA_SEL25->_) */
#define XBAR_A_READ_CROSSBAR_REG_26 /* NULL, Read and return the value of the Crossbar A Select Register 26 (XBARA_SEL26->_) */
#define XBAR_A_READ_CROSSBAR_REG_27 /* NULL, Read and return the value of the Crossbar A Select Register 27 (XBARA_SEL27->_) */
#define XBAR_A_READ_CROSSBAR_REG_28 /* NULL, Read and return the value of the Crossbar A Select Register 28 (XBARA_SEL28->_) */
#define XBAR_A_READ_CROSSBAR_REG_29 /* NULL, Read and return the value of the Crossbar A Select Register 29 (XBARA_SEL29->_) */


#endif /*  XBAR_VERSION == 2 */

#define XBAR_A_WRITE_CROSSBAR_CTRL_0 /* UWord16, Write the Crossbar A Control Register 0 (XBARA_CTRL0->_) */
#define XBAR_A_WRITE_CROSSBAR_CTRL_1 /* UWord16, Write the Crossbar A Control Register 0 (XBARA_CTRL1->_) */
#define XBAR_A_READ_CROSSBAR_CTRL_0 /* NULL, Read and return the value of the Crossbar A Control Register 0 (XBARA_CTRL0->_) */
#define XBAR_A_READ_CROSSBAR_CTRL_1 /* NULL, Read and return the value of the Crossbar A Control Register 0 (XBARA_CTRL1->_) */


#endif /* XBAR_VERSION == 2 || XBAR_VERSION == 3 */


/*****************************************************************
 * Multi-Instruction ioctl() commands
 *
 *  Word16 ioctl( XBAR_module_identifier, Command_name, Parameter );
 *
 ******************************************************************

        COMMAND NAME                      PARAMETERS, COMMENTS
------------------------------------------------------------------ */
#if XBAR_VERSION == 1

#define XBAR_SET_OUT_GPIO_C_14      /* XBAR_INPUT_xxx (LOGIC_0/LOGIC_1/GPIO_C_2/GPIO_E_4/GPIO_C_6/GPIO_E_5/GPIO_C_9/GPIO_E_6/GPIO_C_10/GPIO_E_7/GPIO_C_13/GPIO_F_0/GPIO_F_1/CMPA_OUT/CMPB_OUT/CMPC_OUT/QT_B0_OUT/QT_B1_OUT/QT_B2_OUT/QT_B3_OUT/PWM0_TRIG_COMB/PWM1_TRIG_COMB/PWM2_TRIG_COMB/PWM012_TRIG_COMB/PWM3_TRIG0/PWM3_TRIG1), set XBAR_OUT0 input (XBC0->CODE0) */
#define XBAR_SET_OUT_GPIO_C_15      /* XBAR_INPUT_xxx, set XBAR_OUT1 input  (XBC0->CODE1) */
#define XBAR_SET_OUT_GPIO_F_2       /* XBAR_INPUT_xxx, set XBAR_OUT2 input  (XBC1->CODE2) */
#define XBAR_SET_OUT_GPIO_F_3       /* XBAR_INPUT_xxx, set XBAR_OUT3 input  (XBC1->CODE3) */
#define XBAR_SET_OUT_GPIO_F_4       /* XBAR_INPUT_xxx, set XBAR_OUT4 input  (XBC2->CODE4) */
#define XBAR_SET_OUT_GPIO_F_5       /* XBAR_INPUT_xxx, set XBAR_OUT5 input  (XBC2->CODE5) */
#define XBAR_SET_OUT_ADCA_TRIGGER   /* XBAR_INPUT_xxx, set XBAR_OUT6 input  (XBC3->CODE6) */
#define XBAR_SET_OUT_ADCB_TRIGGER   /* XBAR_INPUT_xxx, set XBAR_OUT7 input  (XBC3->CODE7) */
#define XBAR_SET_OUT_DAC_SYNC       /* XBAR_INPUT_xxx, set XBAR_OUT8 input  (XBC4->CODE8) */
#define XBAR_SET_OUT_CMPA_SAMPLE    /* XBAR_INPUT_xxx, set XBAR_OUT9 input  (XBC4->CODE9) */
#define XBAR_SET_OUT_CMPB_SAMPLE    /* XBAR_INPUT_xxx, set XBAR_OUT10 input (XBC5->CODE10) */
#define XBAR_SET_OUT_CMPC_SAMPLE    /* XBAR_INPUT_xxx, set XBAR_OUT11 input (XBC5->CODE11) */
#define XBAR_SET_OUT_PWM0_EXTA      /* XBAR_INPUT_xxx, set XBAR_OUT12 input (XBC6->CODE12) */
#define XBAR_SET_OUT_PWM1_EXTA      /* XBAR_INPUT_xxx, set XBAR_OUT13 input (XBC6->CODE13) */
#define XBAR_SET_OUT_PWM2_EXTA      /* XBAR_INPUT_xxx, set XBAR_OUT14 input (XBC7->CODE14) */
#define XBAR_SET_OUT_PWM3_EXTA      /* XBAR_INPUT_xxx, set XBAR_OUT15 input (XBC7->CODE15) */
#define XBAR_SET_OUT_PWM0_EXT_SYNC  /* XBAR_INPUT_xxx, set XBAR_OUT16 input (XBC8->CODE16) */
#define XBAR_SET_OUT_PWM1_EXT_SYNC  /* XBAR_INPUT_xxx, set XBAR_OUT17 input (XBC8->CODE17) */
#define XBAR_SET_OUT_PWM2_EXT_SYNC  /* XBAR_INPUT_xxx, set XBAR_OUT18 input (XBC9->CODE18) */
#define XBAR_SET_OUT_PWM3_EXT_SYNC  /* XBAR_INPUT_xxx, set XBAR_OUT19 input (XBC9->CODE19) */
#define XBAR_SET_OUT_PWM_EXT_CLK    /* XBAR_INPUT_xxx, set XBAR_OUT20 input (XBC10->CODE20) */
#define XBAR_SET_OUT_PWM_FAULT0     /* XBAR_INPUT_xxx, set XBAR_OUT21 input (XBC10->CODE21) */
#define XBAR_SET_OUT_PWM_FAULT1     /* XBAR_INPUT_xxx, set XBAR_OUT22 input (XBC11->CODE22) */
#define XBAR_SET_OUT_PWM_FAULT2     /* XBAR_INPUT_xxx, set XBAR_OUT23 input (XBC11->CODE23) */
#define XBAR_SET_OUT_PWM_FAULT3     /* XBAR_INPUT_xxx, set XBAR_OUT24 input (XBC12->CODE24) */
#define XBAR_SET_OUT_PWM_FORCE      /* XBAR_INPUT_xxx, set XBAR_OUT25 input (XBC12->CODE25) */
#define XBAR_SET_OUT_QT_B0          /* XBAR_INPUT_xxx, set XBAR_OUT26 input (XBC13->CODE26) */
#define XBAR_SET_OUT_QT_B1          /* XBAR_INPUT_xxx, set XBAR_OUT27 input (XBC13->CODE27) */
#define XBAR_SET_OUT_QT_B2          /* XBAR_INPUT_xxx, set XBAR_OUT28 input (XBC14->CODE28) */
#define XBAR_SET_OUT_QT_B3          /* XBAR_INPUT_xxx, set XBAR_OUT29 input (XBC14->CODE29) */
#endif

#if XBAR_VERSION == 2

#define XBAR_A_SET_OUT_DMA_REQ0         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT0 input  (XBARA_SEL0->_) */ 
#define XBAR_A_SET_OUT_DMA_REQ1         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT1 input  (XBARA_SEL0->_) */
#define XBAR_A_SET_OUT_DMA_REQ2         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT2 input  (XBARA_SEL1->_) */
#define XBAR_A_SET_OUT_DMA_REQ3         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT3 input  (XBARA_SEL1->_) */
#define XBAR_A_SET_OUT_GPIO_C_14        /* XBAR_A_INPUT_xxx, set XBAR_A_OUT4 input  (XBARA_SEL2->_) */
#define XBAR_A_SET_OUT_GPIO_C_15        /* XBAR_A_INPUT_xxx, set XBAR_A_OUT5 input  (XBARA_SEL2->_) */
#define XBAR_A_SET_OUT_GPIO_F_2         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT6 input  (XBARA_SEL3->_) */
#define XBAR_A_SET_OUT_GPIO_F_3         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT7 input  (XBARA_SEL3->_) */
#define XBAR_A_SET_OUT_GPIO_F_4         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT8 input  (XBARA_SEL4->_) */
#define XBAR_A_SET_OUT_GPIO_F_5         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT9 input  (XBARA_SEL4->_) */
#define XBAR_A_SET_OUT_GPIO_G_8         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT10 input (XBARA_SEL5->_) */
#define XBAR_A_SET_OUT_GPIO_F_10        /* XBAR_A_INPUT_xxx, set XBAR_A_OUT10 input (XBARA_SEL5->_) */
#define XBAR_A_SET_OUT_GPIO_F10_G8      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT10 input (XBARA_SEL5->_) */
#define XBAR_A_SET_OUT_GPIO_G_9         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT11 input (XBARA_SEL5->_) */
#define XBAR_A_SET_OUT_GPIO_F_9         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT11 input (XBARA_SEL5->_) */
#define XBAR_A_SET_OUT_GPIO_F9_G9       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT11 input (XBARA_SEL5->_) */
#define XBAR_A_SET_OUT_ADCA_TRIGGER     /* XBAR_A_INPUT_xxx, set XBAR_A_OUT12 input (XBARA_SEL6->_) */
#define XBAR_A_SET_OUT_ADCB_TRIGGER     /* XBAR_A_INPUT_xxx, set XBAR_A_OUT13 input (XBARA_SEL6->_) */
#define XBAR_A_SET_OUT_ADCC_TRIGGER     /* XBAR_A_INPUT_xxx, set XBAR_A_OUT14 input (XBARA_SEL7->_) */
#define XBAR_A_SET_OUT_DAC_SYNC         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT15 input (XBARA_SEL7->_) */
#define XBAR_A_SET_OUT_CMPA_SAMPLE      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT16 input (XBARA_SEL8->_) */
#define XBAR_A_SET_OUT_CMPB_SAMPLE      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT17 input (XBARA_SEL8->_) */
#define XBAR_A_SET_OUT_CMPC_SAMPLE      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT18 input (XBARA_SEL9->_) */
#define XBAR_A_SET_OUT_CMPD_SAMPLE      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT19 input (XBARA_SEL9->_) */
#define XBAR_A_SET_OUT_PWMA0_EXTA       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT20 input (XBARA_SEL10->_) */
#define XBAR_A_SET_OUT_PWMA1_EXTA       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT21 input (XBARA_SEL10->_) */
#define XBAR_A_SET_OUT_PWMA2_EXTA       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT22 input (XBARA_SEL11->_) */
#define XBAR_A_SET_OUT_PWMA3_EXTA       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT23 input (XBARA_SEL11->_) */
#define XBAR_A_SET_OUT_PWMA0_EXT_SYNC   /* XBAR_A_INPUT_xxx, set XBAR_A_OUT24 input (XBARA_SEL12->_) */
#define XBAR_A_SET_OUT_PWMA1_EXT_SYNC   /* XBAR_A_INPUT_xxx, set XBAR_A_OUT25 input (XBARA_SEL12->_) */
#define XBAR_A_SET_OUT_PWMA2_EXT_SYNC   /* XBAR_A_INPUT_xxx, set XBAR_A_OUT26 input (XBARA_SEL13->_) */
#define XBAR_A_SET_OUT_PWMA3_EXT_SYNC   /* XBAR_A_INPUT_xxx, set XBAR_A_OUT27 input (XBARA_SEL13->_) */
#define XBAR_A_SET_OUT_PWMAB_EXT_CLK    /* XBAR_A_INPUT_xxx, set XBAR_A_OUT28 input (XBARA_SEL14->_) */
#define XBAR_A_SET_OUT_PWMAB_FAULT0     /* XBAR_A_INPUT_xxx, set XBAR_A_OUT29 input (XBARA_SEL14->_) */
#define XBAR_A_SET_OUT_PWMAB_FAULT1     /* XBAR_A_INPUT_xxx, set XBAR_A_OUT30 input (XBARA_SEL15->_) */
#define XBAR_A_SET_OUT_PWMAB_FAULT2     /* XBAR_A_INPUT_xxx, set XBAR_A_OUT31 input (XBARA_SEL15->_) */
#define XBAR_A_SET_OUT_PWMAB_FAULT3     /* XBAR_A_INPUT_xxx, set XBAR_A_OUT32 input (XBARA_SEL16->_) */
#define XBAR_A_SET_OUT_PWMA_FORCE       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT33 input (XBARA_SEL16->_) */
#define XBAR_A_SET_OUT_QT_B0_IN         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT34 input (XBARA_SEL17->_) */
#define XBAR_A_SET_OUT_QT_B1_IN         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT35 input (XBARA_SEL17->_) */
#define XBAR_A_SET_OUT_QT_B2_IN         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT36 input (XBARA_SEL18->_) */
#define XBAR_A_SET_OUT_QT_B3_IN         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT37 input (XBARA_SEL18->_) */
#define XBAR_A_SET_OUT_PDB0_TRIG0       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT38 input (XBARA_SEL19->_) */
#define XBAR_A_SET_OUT_PDB0_FAULTA      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT39 input (XBARA_SEL19->_) */
#define XBAR_A_SET_OUT_PDB0_FAULTC      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT40 input (XBARA_SEL20->_) */
#define XBAR_A_SET_PDB1_TRIG0           /* XBAR_A_INPUT_xxx, set XBAR_A_OUT41 input (XBARA_SEL20->_) */
#define XBAR_A_SET_OUT_PDB1_FAULTA      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT42 input (XBARA_SEL21->_) */
#define XBAR_A_SET_OUT_PDB1_FAULTC      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT43 input (XBARA_SEL21->_) */
#define XBAR_A_SET_OUT_QD_PHA           /* XBAR_A_INPUT_xxx, set XBAR_A_OUT44 input (XBARA_SEL22->_) */
#define XBAR_A_SET_OUT_QD_PHB           /* XBAR_A_INPUT_xxx, set XBAR_A_OUT45 input (XBARA_SEL22->_) */
#define XBAR_A_SET_OUT_QD_INDEX         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT46 input (XBARA_SEL23->_) */
#define XBAR_A_SET_OUT_QD_HOME          /* XBAR_A_INPUT_xxx, set XBAR_A_OUT47 input (XBARA_SEL23->_) */
#define XBAR_A_SET_OUT_QD_CAP           /* XBAR_A_INPUT_xxx, set XBAR_A_OUT48 input (XBARA_SEL24->_) */
#define XBAR_A_SET_OUT_QT_A0_IN         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT49 input (XBARA_SEL24->_) */
#define XBAR_A_SET_OUT_QT_A1_IN         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT50 input (XBARA_SEL25->_) */
#define XBAR_A_SET_OUT_QT_A2_IN         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT51 input (XBARA_SEL25->_) */
#define XBAR_A_SET_OUT_QT_A3_IN         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT52 input (XBARA_SEL26->_) */
#define XBAR_A_SET_OUT_PWMB0_EXT_SYNC   /* XBAR_A_INPUT_xxx, set XBAR_A_OUT53 input (XBARA_SEL26->_) */
#define XBAR_A_SET_OUT_PWMB1_EXT_SYNC   /* XBAR_A_INPUT_xxx, set XBAR_A_OUT54 input (XBARA_SEL27->_) */
#define XBAR_A_SET_OUT_PWMB2_EXT_SYNC   /* XBAR_A_INPUT_xxx, set XBAR_A_OUT55 input (XBARA_SEL27->_) */
#define XBAR_A_SET_OUT_PWMB3_EXT_SYNC   /* XBAR_A_INPUT_xxx, set XBAR_A_OUT56 input (XBARA_SEL28->_) */
#define XBAR_A_SET_OUT_PWMB_FORCE       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT57 input (XBARA_SEL28->_) */
#define XBAR_A_SET_OUT_EWM_IN           /* XBAR_A_INPUT_xxx, set XBAR_A_OUT58 input (XBARA_SEL29->_) */

/* Crossbar B outputs */

#define XBAR_B_SET_OUT_AOI_O_A          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT0 input (XBARB_SEL0->_) */ 
#define XBAR_B_SET_OUT_AOI_O_B          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT1 input (XBARB_SEL0->_) */
#define XBAR_B_SET_OUT_AOI_O_C          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT2 input (XBARB_SEL1->_) */
#define XBAR_B_SET_OUT_AOI_O_D          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT3 input (XBARB_SEL1->_) */
#define XBAR_B_SET_OUT_AOI_1_A          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT4 input (XBARB_SEL2->_) */
#define XBAR_B_SET_OUT_AOI_1_B          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT5 input (XBARB_SEL2->_) */
#define XBAR_B_SET_OUT_AOI_1_C          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT6 input (XBARB_SEL3->_) */
#define XBAR_B_SET_OUT_AOI_1_D          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT7 input (XBARB_SEL3->_) */
#define XBAR_B_SET_OUT_AOI_2_A          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT8 input (XBARB_SEL4->_) */
#define XBAR_B_SET_OUT_AOI_2_B          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT9 input (XBARB_SEL4->_) */
#define XBAR_B_SET_OUT_AOI_2_C          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT10 input (XBARB_SEL5->_) */
#define XBAR_B_SET_OUT_AOI_2_D          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT11 input (XBARB_SEL5->_) */
#define XBAR_B_SET_OUT_AOI_3_A          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT12 input (XBARB_SEL6->_) */
#define XBAR_B_SET_OUT_AOI_3_B          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT13 input (XBARB_SEL6->_) */
#define XBAR_B_SET_OUT_AOI_3_C          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT14 input (XBARB_SEL7->_) */
#define XBAR_B_SET_OUT_AOI_3_D          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT15 input (XBARB_SEL7->_) */

#endif /* XBAR_VERSION == 2 */
 
#if XBAR_VERSION == 3 

#define XBAR_A_SET_OUT_DMA_REQ0         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT0 input (XBARA_SEL0->_) */ 
#define XBAR_A_SET_OUT_DMA_REQ1         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT1 input (XBARA_SEL0->_) */
#define XBAR_A_SET_OUT_DMA_REQ2         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT2 input (XBARA_SEL1->_) */
#define XBAR_A_SET_OUT_DMA_REQ3         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT3 input (XBARA_SEL1->_) */
#define XBAR_A_SET_OUT_GPIO_C_14        /* XBAR_A_INPUT_xxx, set XBAR_A_OUT4 input (XBARA_SEL2->_) */
#define XBAR_A_SET_OUT_GPIO_C_15        /* XBAR_A_INPUT_xxx, set XBAR_A_OUT5 input (XBARA_SEL2->_) */
#define XBAR_A_SET_OUT_GPIO_C8_F2       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT6 input (XBARA_SEL3->_) */
#define XBAR_A_SET_OUT_GPIO_F_3         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT7 input (XBARA_SEL3->_) */
#define XBAR_A_SET_OUT_GPIO_C9_F4       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT8 input (XBARA_SEL4->_) */
#define XBAR_A_SET_OUT_GPIO_C10_F5      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT9 input (XBARA_SEL4->_) */
#define XBAR_A_SET_OUT_GPIO_F_8         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT10 input (XBARA_SEL5->_) */
#define XBAR_A_SET_OUT_GPIO_C_2         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT11 input (XBARA_SEL5->_) */
#define XBAR_A_SET_OUT_ADCA_TRIGGER     /* XBAR_A_INPUT_xxx, set XBAR_A_OUT12 input (XBARA_SEL6->_) */
#define XBAR_A_SET_OUT_ADCB_TRIGGER     /* XBAR_A_INPUT_xxx, set XBAR_A_OUT13 input (XBARA_SEL6->_) */
#define XBAR_A_SET_OUT_DACB_SYNC        /* XBAR_A_INPUT_xxx, set XBAR_A_OUT14 input (XBARA_SEL7->_) */
#define XBAR_A_SET_OUT_DACA_SYNC        /* XBAR_A_INPUT_xxx, set XBAR_A_OUT15 input (XBARA_SEL7->_) */
#define XBAR_A_SET_OUT_CMPA_SAMPLE      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT16 input (XBARA_SEL8->_) */
#define XBAR_A_SET_OUT_CMPB_SAMPLE      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT17 input (XBARA_SEL8->_) */
#define XBAR_A_SET_OUT_CMPC_SAMPLE      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT18 input (XBARA_SEL9->_) */
#define XBAR_A_SET_OUT_CMPD_SAMPLE      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT19 input (XBARA_SEL9->_) */
#define XBAR_A_SET_OUT_PWMA0_EXTA       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT20 input (XBARA_SEL10->_) */
#define XBAR_A_SET_OUT_PWMA1_EXTA       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT21 input (XBARA_SEL10->_) */
#define XBAR_A_SET_OUT_PWMA2_EXTA       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT22 input (XBARA_SEL11->_) */
#define XBAR_A_SET_OUT_PWMA3_EXTA       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT23 input (XBARA_SEL11->_) */
#define XBAR_A_SET_OUT_PWMA0_EXT_SYNC   /* XBAR_A_INPUT_xxx, set XBAR_A_OUT24 input (XBARA_SEL12->_) */
#define XBAR_A_SET_OUT_PWMA1_EXT_SYNC   /* XBAR_A_INPUT_xxx, set XBAR_A_OUT25 input (XBARA_SEL12->_) */
#define XBAR_A_SET_OUT_PWMA2_EXT_SYNC   /* XBAR_A_INPUT_xxx, set XBAR_A_OUT26 input (XBARA_SEL13->_) */
#define XBAR_A_SET_OUT_PWMA3_EXT_SYNC   /* XBAR_A_INPUT_xxx, set XBAR_A_OUT27 input (XBARA_SEL13->_) */
#define XBAR_A_SET_OUT_PWMA_EXT_CLK     /* XBAR_A_INPUT_xxx, set XBAR_A_OUT28 input (XBARA_SEL14->_) */
#define XBAR_A_SET_OUT_PWMA_FAULT0      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT29 input (XBARA_SEL14->_) */
#define XBAR_A_SET_OUT_PWMA_FAULT1      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT30 input (XBARA_SEL15->_) */
#define XBAR_A_SET_OUT_PWMA_FAULT2      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT31 input (XBARA_SEL15->_) */
#define XBAR_A_SET_OUT_PWMA_FAULT3      /* XBAR_A_INPUT_xxx, set XBAR_A_OUT32 input (XBARA_SEL16->_) */
#define XBAR_A_SET_OUT_PWMA_FORCE       /* XBAR_A_INPUT_xxx, set XBAR_A_OUT33 input (XBARA_SEL16->_) */
#define XBAR_A_SET_OUT_QT_A0_IN         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT34 input (XBARA_SEL17->_) */
#define XBAR_A_SET_OUT_QT_A1_IN         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT35 input (XBARA_SEL17->_) */
#define XBAR_A_SET_OUT_QT_A2_IN         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT36 input (XBARA_SEL18->_) */
#define XBAR_A_SET_OUT_QT_A3_IN         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT37 input (XBARA_SEL18->_) */
#define XBAR_A_SET_OUT_SCI0_RXD         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT38 input (XBARA_SEL19->_) */
#define XBAR_A_SET_OUT_SCI1_RXD         /* XBAR_A_INPUT_xxx, set XBAR_A_OUT39 input (XBARA_SEL19->_) */
#define XBAR_A_SET_OUT_EWM_IN           /* XBAR_A_INPUT_xxx, set XBAR_A_OUT40 input (XBARA_SEL20->_) */
                                                                    
          /* Crossbar B outputs */
                                                                    
#define XBAR_B_SET_OUT_AOI_O_A          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT0 input (XBARB_SEL0->_) */ 
#define XBAR_B_SET_OUT_AOI_O_B          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT1 input (XBARB_SEL0->_) */
#define XBAR_B_SET_OUT_AOI_O_C          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT2 input (XBARB_SEL1->_) */
#define XBAR_B_SET_OUT_AOI_O_D          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT3 input (XBARB_SEL1->_) */
#define XBAR_B_SET_OUT_AOI_1_A          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT4 input (XBARB_SEL2->_) */
#define XBAR_B_SET_OUT_AOI_1_B          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT5 input (XBARB_SEL2->_) */
#define XBAR_B_SET_OUT_AOI_1_C          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT6 input (XBARB_SEL3->_) */
#define XBAR_B_SET_OUT_AOI_1_D          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT7 input (XBARB_SEL3->_) */
#define XBAR_B_SET_OUT_AOI_2_A          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT8 input (XBARB_SEL4->_) */
#define XBAR_B_SET_OUT_AOI_2_B          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT9 input (XBARB_SEL4->_) */
#define XBAR_B_SET_OUT_AOI_2_C          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT10 input (XBARB_SEL5->_) */
#define XBAR_B_SET_OUT_AOI_2_D          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT11 input (XBARB_SEL5->_) */
#define XBAR_B_SET_OUT_AOI_3_A          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT12 input (XBARB_SEL6->_) */
#define XBAR_B_SET_OUT_AOI_3_B          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT13 input (XBARB_SEL6->_) */
#define XBAR_B_SET_OUT_AOI_3_C          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT14 input (XBARB_SEL7->_) */
#define XBAR_B_SET_OUT_AOI_3_D          /* XBAR_B_INPUT_xxx, set XBAR_B_OUT15 input (XBARB_SEL7->_) */

#endif

    /*****************************************************************
     * Software Layer ioctl() commands
     *
     *  Word16 ioctl( XBAR_module_identifier, Command_name, Parameter );
     *
     ******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#if XBAR_VERSION == 1
#define XBAR_INIT                          /* NULL, Initialize XBAR periheral registers using the appconfig.h _INIT values. */
#else
#define XBAR_A_INIT                        /* NULL, Initialize XBAR_A periheral registers using the appconfig.h _INIT values. */
#define XBAR_B_INIT                        /* NULL, Initialize XBAR_B periheral registers using the appconfig.h _INIT values. */
#endif

/****************************************************************************
* XBAR constants and type declarations use in the ioctl functions
*****************************************************************************/
#if XBAR_VERSION == 1

#define XBAR_INPUT_LOGIC_0          0x00
#define XBAR_INPUT_LOGIC_1          0x01
#define XBAR_INPUT_GPIO_C_2         0x02
#define XBAR_INPUT_GPIO_E_4         0x02
#define XBAR_INPUT_GPIO_C_6         0x03
#define XBAR_INPUT_GPIO_E_5         0x03
#define XBAR_INPUT_GPIO_C_9         0x04
#define XBAR_INPUT_GPIO_E_6         0x04
#define XBAR_INPUT_GPIO_C_10        0x05
#define XBAR_INPUT_GPIO_E_7         0x05
#define XBAR_INPUT_GPIO_C_13        0x06
#define XBAR_INPUT_GPIO_F_0         0x06
#define XBAR_INPUT_GPIO_C_5         0x07
#define XBAR_INPUT_GPIO_F_1         0x07
#define XBAR_INPUT_CMPA_OUT         0x09
#define XBAR_INPUT_CMPB_OUT         0x0A
#define XBAR_INPUT_CMPC_OUT         0x0B
#define XBAR_INPUT_QT_B0_OUT        0x0C
#define XBAR_INPUT_QT_B1_OUT        0x0D
#define XBAR_INPUT_QT_B2_OUT        0x0E
#define XBAR_INPUT_QT_B3_OUT        0x0F
#define XBAR_INPUT_PWM0_TRIG_COMB   0x10
#define XBAR_INPUT_PWM1_TRIG_COMB   0x11
#define XBAR_INPUT_PWM2_TRIG_COMB   0x12
#define XBAR_INPUT_PWM012_TRIG_COMB 0x13
#define XBAR_INPUT_PWM3_TRIG0       0x14
#define XBAR_INPUT_PWM3_TRIG1       0x15

#endif

#if XBAR_VERSION == 2

#define XBAR_A_INPUT_LOGIC_0            0x00
#define XBAR_A_INPUT_LOGIC_1            0x01
#define XBAR_A_INPUT_GPIO_C_2           0x02
#define XBAR_A_INPUT_GPIO_E_4           0x02
#define XBAR_A_INPUT_GPIO_F_6           0x02
#define XBAR_A_INPUT_GPIO_C2_E4_F6      0x02
#define XBAR_A_INPUT_GPIO_E_5           0x03
#define XBAR_A_INPUT_GPIO_C_6           0x03
#define XBAR_A_INPUT_GPIO_F_7           0x03
#define XBAR_A_INPUT_GPIO_E5_C6_F7      0x03
#define XBAR_A_INPUT_GPIO_C_9           0x04
#define XBAR_A_INPUT_GPIO_E_6           0x04
#define XBAR_A_INPUT_GPIO_D_6           0x04
#define XBAR_A_INPUT_GPIO_C9_E6_D6      0x04
#define XBAR_A_INPUT_GPIO_C_10          0x05
#define XBAR_A_INPUT_GPIO_E_7           0x05
#define XBAR_A_INPUT_GPIO_D_5           0x05
#define XBAR_A_INPUT_GPIO_C10_E7_D5     0x05
#define XBAR_A_INPUT_GPIO_F_0           0x06
#define XBAR_A_INPUT_GPIO_C_13          0x06
#define XBAR_A_INPUT_GPIO_F0_C13        0x06
#define XBAR_A_INPUT_GPIO_C_5           0x07
#define XBAR_A_INPUT_GPIO_D_7           0x07
#define XBAR_A_INPUT_GPIO_F_1           0x07
#define XBAR_A_INPUT_GPIO_B_11          0x07
#define XBAR_A_INPUT_GPIO_C5_D7_F1_B11  0x07
#define XBAR_A_INPUT_GPIO_C_4           0x08
#define XBAR_A_INPUT_GPIO_B_10          0x08
#define XBAR_A_INPUT_GPIO_G_10          0x08
#define XBAR_A_INPUT_GPIO_C4_B10_G10    0x08
#define XBAR_A_INPUT_GPIO_C_8           0x09
#define XBAR_A_INPUT_GPIO_B_9           0x09
#define XBAR_A_INPUT_GPIO_C8_B9         0x09
#define XBAR_A_INPUT_GPIO_F_15          0x0A
#define XBAR_A_INPUT_GPIO_F_11          0x0B
#define XBAR_A_INPUT_CMPA_OUT           0x0C
#define XBAR_A_INPUT_CMPB_OUT           0x0D
#define XBAR_A_INPUT_CMPC_OUT           0x0E
#define XBAR_A_INPUT_CMPD_OUT           0x0F
#define XBAR_A_INPUT_QT_B0_OUT          0x10
#define XBAR_A_INPUT_QT_B1_OUT          0x11
#define XBAR_A_INPUT_QT_B2_OUT          0x12
#define XBAR_A_INPUT_QT_B3_OUT          0x13
#define XBAR_A_INPUT_PWMA0_TRIG0        0x14
#define XBAR_A_INPUT_PWMA0_TRIG1        0x15
#define XBAR_A_INPUT_PWMA1_TRIG0        0x16
#define XBAR_A_INPUT_PWMA1_TRIG1        0x17
#define XBAR_A_INPUT_PWMA2_TRIG0        0x18
#define XBAR_A_INPUT_PWMA2_TRIG1        0x19
#define XBAR_A_INPUT_PWMA3_TRIG0        0x1A
#define XBAR_A_INPUT_PWMA3_TRIG1        0x1B
#define XBAR_A_INPUT_PDB0_OUTA          0x1C
#define XBAR_A_INPUT_PDB0_OUTB          0x1D
#define XBAR_A_INPUT_PDB0_OUTC          0x1E
#define XBAR_A_INPUT_PDB0_OUTD          0x1F
#define XBAR_A_INPUT_PDB1_OUTA          0x20
#define XBAR_A_INPUT_PDB1_OUTB          0x21
#define XBAR_A_INPUT_PDB1_OUTC          0x22
#define XBAR_A_INPUT_PDB1_OUTD          0x23
#define XBAR_A_INPUT_QT_A0_OUT          0x24    
#define XBAR_A_INPUT_QT_A1_OUT          0x25
#define XBAR_A_INPUT_QT_A2_OUT          0x26
#define XBAR_A_INPUT_QT_A3_OUT          0x27
#define XBAR_A_INPUT_PWMB0_TRIG0_TRIG1  0x28
#define XBAR_A_INPUT_PWMB1_TRIG0_TRIG1  0x29
#define XBAR_A_INPUT_PWMB2_TRIG0_TRIG1  0x2A
#define XBAR_A_INPUT_PWMB3_TRIG0        0x2B
#define XBAR_A_INPUT_PWMB3_TRIG1        0x2C
#define XBAR_A_INPUT_QD_CMP             0x2D
#define XBAR_A_INPUT_AND_OR_INVERT0     0x2E
#define XBAR_A_INPUT_AND_OR_INVERT1     0x2F
#define XBAR_A_INPUT_AND_OR_INVERT2     0x30
#define XBAR_A_INPUT_AND_OR_INVERT3     0x31

        /* Crossbar B inputs */

#define XBAR_B_INPUT_CMPA_OUT                   0x00    // IN0
#define XBAR_B_INPUT_CMPB_OUT                   0x01    // IN1
#define XBAR_B_INPUT_CMPC_OUT                   0x02    // IN2
#define XBAR_B_INPUT_CMPD_OUT                   0x03    // IN3
#define XBAR_B_INPUT_QT_B0_OUT                  0x04    // IN4
#define XBAR_B_INPUT_QT_B1_OUT                  0x05    // IN5
#define XBAR_B_INPUT_QT_B2_OUT                  0x06    // IN6
#define XBAR_B_INPUT_QT_B3_OUT                  0x07    // IN7
#define XBAR_B_INPUT_PWMA0_TRIG0_TRIG1          0x08    // IN8
#define XBAR_B_INPUT_PWMA1_TRIG0_TRIG1          0x09    // IN9
#define XBAR_B_INPUT_PWMA2_TRIG0_TRIG1          0x0A    // IN10
#define XBAR_B_INPUT_PWMA3_TRIG0_TRIG1          0x0B    // IN11
#define XBAR_B_INPUT_PDB0_OUT_B_OUT_D           0x0C    // IN12
#define XBAR_B_INPUT_PDB1_OUT_B_OUT_D           0x0D    // IN13
#define XBAR_B_INPUT_GPIO_C_2                   0x0E    // IN14
#define XBAR_B_INPUT_GPIO_E_4                   0x0E    // IN14
#define XBAR_B_INPUT_GPIO_C2_E4                 0x0E    // IN14
#define XBAR_B_INPUT_GPIO_C_6                   0x0F    // IN15
#define XBAR_B_INPUT_GPIO_E_5                   0x0F    // IN15
#define XBAR_B_INPUT_GPIO_C6_E5                 0x0F    // IN15
#define XBAR_B_INPUT_QT_A0_OUT                  0x10    // IN16
#define XBAR_B_INPUT_QT_A1_OUT                  0x11    // IN17
#define XBAR_B_INPUT_QT_A2_OUT                  0x12    // IN18
#define XBAR_B_INPUT_QT_A3_OUT                  0x13    // IN19
#define XBAR_B_INPUT_GPIO_C_4                   0x14    // IN20
#define XBAR_B_INPUT_GPIO_B_10                  0x14    // IN20
#define XBAR_B_INPUT_GPIO_C_8                   0x15    // IN21
#define XBAR_B_INPUT_GPIO_B_9                   0x15    // IN21
#define XBAR_B_INPUT_GPIO_C8_B9                 0x15    // IN21
#define XBAR_B_INPUT_PWMB0_TRIG0_TRIG1          0x16    // IN22
#define XBAR_B_INPUT_PWMB1_TRIG0_TRIG1          0x17    // IN23
#define XBAR_B_INPUT_PWMB2_TRIG0_TRIG1          0x18    // IN24
#define XBAR_B_INPUT_PWMB3_TRIG0_TRIG1          0x19    // IN25

#endif

#if XBAR_VERSION == 3 

#define XBAR_A_INPUT_LOGIC_0            0x00
#define XBAR_A_INPUT_LOGIC_1            0x01
#define XBAR_A_INPUT_GPIO_C_2           0x02
#define XBAR_A_INPUT_GPIO_E_4           0x02
#define XBAR_A_INPUT_GPIO_F_6           0x02
#define XBAR_A_INPUT_GPIO_C2_E4_F6      0x02
#define XBAR_A_INPUT_GPIO_C_6           0x03
#define XBAR_A_INPUT_GPIO_E_5           0x03
#define XBAR_A_INPUT_GPIO_F_7           0x03
#define XBAR_A_INPUT_GPIO_C6_E5_F7      0x03
#define XBAR_A_INPUT_GPIO_C_9           0x04
#define XBAR_A_INPUT_GPIO_E_6           0x04
#define XBAR_A_INPUT_GPIO_C9_E6         0x04
#define XBAR_A_INPUT_GPIO_C_10          0x05
#define XBAR_A_INPUT_GPIO_E_7           0x05
#define XBAR_A_INPUT_GPIO_C10_E7        0x05
#define XBAR_A_INPUT_GPIO_C_4           0x06
#define XBAR_A_INPUT_GPIO_F_0           0x06
#define XBAR_A_INPUT_GPIO_C_13          0x06
#define XBAR_A_INPUT_GPIO_C4_C13_F0     0x06
#define XBAR_A_INPUT_GPIO_C_5           0x07
#define XBAR_A_INPUT_GPIO_F_1           0x07
#define XBAR_A_INPUT_GPIO_C5_F1         0x07
#define XBAR_A_INPUT_GPIO_C_7           0x08
#define XBAR_A_INPUT_GPIO_C_8           0x09
#define XBAR_A_INPUT_CMPA_OUT           0x0A
#define XBAR_A_INPUT_CMPB_OUT           0x0B
#define XBAR_A_INPUT_CMPC_OUT           0x0C
#define XBAR_A_INPUT_CMPD_OUT           0x0D
#define XBAR_A_INPUT_QT_A0_OUT          0x0E    
#define XBAR_A_INPUT_QT_A1_OUT          0x0F
#define XBAR_A_INPUT_QT_A2_OUT          0x10
#define XBAR_A_INPUT_QT_A3_OUT          0x11
#define XBAR_A_INPUT_PWMA0_TRIG0        0x12
#define XBAR_A_INPUT_PWMA0_TRIG1        0x13
#define XBAR_A_INPUT_PWMA1_TRIG0        0x14
#define XBAR_A_INPUT_PWMA1_TRIG1        0x15
#define XBAR_A_INPUT_PWMA2_TRIG0        0x16
#define XBAR_A_INPUT_PWMA2_TRIG1        0x17
#define XBAR_A_INPUT_PWMA3_TRIG0        0x18
#define XBAR_A_INPUT_PWMA3_TRIG1        0x19
#define XBAR_A_INPUT_PIT0_SYNC_OUT      0x1A
#define XBAR_A_INPUT_PIT1_SYNC_OUT      0x1B
#define XBAR_A_INPUT_AND_OR_INVERT0     0x1C
#define XBAR_A_INPUT_AND_OR_INVERT1     0x1D
#define XBAR_A_INPUT_AND_OR_INVERT2     0x1E
#define XBAR_A_INPUT_AND_OR_INVERT3     0x1F

    /* Crosssbar switch B Inputs */

#define XBAR_B_INPUT_SCI0_TXD           0x00
#define XBAR_B_INPUT_SCI1_TXD           0x01
#define XBAR_B_INPUT_GPIO_C_2           0x02
#define XBAR_B_INPUT_GPIO_E_4           0x02
#define XBAR_B_INPUT_GPIO_F_6           0x02
#define XBAR_B_INPUT_GPIO_C2_E4_F6      0x02
#define XBAR_B_INPUT_GPIO_C_6           0x03
#define XBAR_B_INPUT_GPIO_E_5           0x03
#define XBAR_B_INPUT_GPIO_F_7           0x03
#define XBAR_B_INPUT_GPIO_C6_E5_F7      0x03
#define XBAR_B_INPUT_GPIO_C_9           0x04
#define XBAR_B_INPUT_GPIO_E_6           0x04
#define XBAR_B_INPUT_GPIO_C9_E6         0x04
#define XBAR_B_INPUT_GPIO_C_10          0x05
#define XBAR_B_INPUT_GPIO_E_7           0x05
#define XBAR_B_INPUT_GPIO_C10_E7        0x05
#define XBAR_B_INPUT_GPIO_C_4           0x06
#define XBAR_B_INPUT_GPIO_F_0           0x06
#define XBAR_B_INPUT_GPIO_C_13          0x06
#define XBAR_B_INPUT_GPIO_C4_C13_F0     0x06
#define XBAR_B_INPUT_GPIO_C_5           0x07
#define XBAR_B_INPUT_GPIO_F_1           0x07
#define XBAR_B_INPUT_GPIO_C5_F1         0x07
#define XBAR_B_INPUT_GPIO_C_7           0x08
#define XBAR_B_INPUT_GPIO_C_8           0x09
#define XBAR_B_INPUT_CMPA_OUT           0x0A
#define XBAR_B_INPUT_CMPB_OUT           0x0B
#define XBAR_B_INPUT_CMPC_OUT           0x0C
#define XBAR_B_INPUT_CMPD_OUT           0x0D
#define XBAR_B_INPUT_QT_A0_OUT          0x0E    
#define XBAR_B_INPUT_QT_A1_OUT          0x0F
#define XBAR_B_INPUT_QT_A2_OUT          0x10
#define XBAR_B_INPUT_QT_A3_OUT          0x11
#define XBAR_B_INPUT_PWMA0_TRIG0        0x12
#define XBAR_B_INPUT_PWMA0_TRIG1        0x13
#define XBAR_B_INPUT_PWMA1_TRIG0        0x14
#define XBAR_B_INPUT_PWMA1_TRIG1        0x15
#define XBAR_B_INPUT_PWMA2_TRIG0        0x16
#define XBAR_B_INPUT_PWMA2_TRIG1        0x17
#define XBAR_B_INPUT_PWMA3_TRIG0        0x18
#define XBAR_B_INPUT_PWMA3_TRIG1        0x19

#endif

    /*****************************************************************
     * XBAR Register Bits Defines, used in ioct command implementation
     ******************************************************************/

    /* XBAR Crossbar Control Register */
#define XBAR_XBCX_CODE1_MASK   0x1f00   /* Crossbar odd mask */  
#define XBAR_XBCX_CODE0_MASK   0x001f   /* Crossbar even mask */
                               
/***********************************************************************
* XBAR init                    
***********************************************************************/
#if XBAR_VERSION == 1

void xbarInit(arch_sXBAR *pXbarBase);
#define ioctlXBAR_INIT(pXbarBase, param) xbarInit(pXbarBase)

#endif

#if XBAR_VERSION == 2 || XBAR_VERSION == 3

    void xbaraInit(arch_sXBARA *pXbarBase);
#define ioctlXBAR_A_INIT(pXbaraBase, param) xbaraInit(pXbaraBase)

    void xbarbInit(arch_sXBARB *pXbarBase);
#define ioctlXBAR_B_INIT(pXbarbBase, param) xbarbInit(pXbarbBase)
    
#endif


#if XBAR_VERSION == 2 || XBAR_VERSION == 3

/* Crossbar Control Register 0 */
#define ioctlXBAR_A_SET_OUT_DMA_REQ0(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel0))

#define ioctlXBAR_A_SET_OUT_DMA_REQ1(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel0))
  
#define ioctlXBAR_A_SET_OUT_DMA_REQ2(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel1))
  
#define ioctlXBAR_A_SET_OUT_DMA_REQ3(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel1))

#define ioctlXBAR_A_SET_OUT_GPIO_C_14(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel2))

#define ioctlXBAR_A_SET_OUT_GPIO_C_15(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel2))

#define ioctlXBAR_A_SET_OUT_GPIO_F_3(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel3))

#define ioctlXBAR_A_SET_OUT_ADCA_TRIGGER(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel6))

#define ioctlXBAR_A_SET_OUT_ADCB_TRIGGER(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel6))

#define ioctlXBAR_A_SET_OUT_CMPA_SAMPLE(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel8))

#define ioctlXBAR_A_SET_OUT_CMPB_SAMPLE(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel8))

#define ioctlXBAR_A_SET_OUT_CMPC_SAMPLE(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel9))

#define ioctlXBAR_A_SET_OUT_CMPD_SAMPLE(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel9))

#define ioctlXBAR_A_SET_OUT_PWMA0_EXTA(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel10))

#define ioctlXBAR_A_SET_OUT_PWMA1_EXTA(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel10))

#define ioctlXBAR_A_SET_OUT_PWMA2_EXTA(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel11))

#define ioctlXBAR_A_SET_OUT_PWMA3_EXTA(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel11))

#define ioctlXBAR_A_SET_OUT_PWMA0_EXT_SYNC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel12))

#define ioctlXBAR_A_SET_OUT_PWMA1_EXT_SYNC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel12))

#define ioctlXBAR_A_SET_OUT_PWMA2_EXT_SYNC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel13))

#define ioctlXBAR_A_SET_OUT_PWMA3_EXT_SYNC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel13))

#define ioctlXBAR_A_SET_OUT_PWMA_FORCE(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel16))

#if XBAR_VERSION == 2

#define ioctlXBAR_A_SET_OUT_GPIO_F_2(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel3))

#define ioctlXBAR_A_SET_OUT_GPIO_F_4(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel4))

#define ioctlXBAR_A_SET_OUT_GPIO_F_5(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel4))
    
#define ioctlXBAR_A_SET_OUT_GPIO_G_8(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel5))

#define ioctlXBAR_A_SET_OUT_GPIO_F_10(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel5))

#define ioctlXBAR_A_SET_OUT_GPIO_F10_G8(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel5))

#define ioctlXBAR_A_SET_OUT_GPIO_G_9(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel5))

#define ioctlXBAR_A_SET_OUT_GPIO_F_9(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel5))

#define ioctlXBAR_A_SET_OUT_GPIO_F9_G9(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel5))
    
#define ioctlXBAR_A_SET_OUT_ADCC_TRIGGER(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel7))

#define ioctlXBAR_A_SET_OUT_DAC_SYNC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel7)) 
    
#define ioctlXBAR_A_SET_OUT_PWMAB_EXT_CLK(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel14))

#define ioctlXBAR_A_SET_OUT_PWMAB_FAULT0(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel14))

#define ioctlXBAR_A_SET_OUT_PWMAB_FAULT1(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel15))

#define ioctlXBAR_A_SET_OUT_PWMAB_FAULT2(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel15))

#define ioctlXBAR_A_SET_OUT_PWMAB_FAULT3(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel16))
    

#define ioctlXBAR_A_SET_OUT_QT_B0_IN(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel17))

#define ioctlXBAR_A_SET_OUT_QT_B1_IN(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel17))

#define ioctlXBAR_A_SET_OUT_QT_B2_IN(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel18))

#define ioctlXBAR_A_SET_OUT_QT_B3_IN(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel18))

#define ioctlXBAR_A_SET_OUT_PDB0_TRIG0(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel19))

#define ioctlXBAR_A_SET_OUT_PDB0_FAULTA(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel19))

#define ioctlXBAR_A_SET_OUT_PDB0_FAULTC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel20))

#define ioctlXBAR_A_SET_PDB1_TRIG0(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel20))
    

#define ioctlXBAR_A_SET_OUT_PDB1_FAULTA(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel21))

#define ioctlXBAR_A_SET_OUT_PDB1_FAULTC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel21))

#define ioctlXBAR_A_SET_OUT_QD_PHA(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel22))

#define ioctlXBAR_A_SET_OUT_QD_PHB(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel22))

#define ioctlXBAR_A_SET_OUT_QD_INDEX(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel23))

#define ioctlXBAR_A_SET_OUT_QD_HOME(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel23))

#define ioctlXBAR_A_SET_OUT_QD_CAP(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel24))

#define ioctlXBAR_A_SET_OUT_QT_A0_IN(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel24))

#define ioctlXBAR_A_SET_OUT_QT_A1_IN(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel25))

#define ioctlXBAR_A_SET_OUT_QT_A2_IN(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel25))

#define ioctlXBAR_A_SET_OUT_QT_A3_IN(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel26))

#define ioctlXBAR_A_SET_OUT_PWMB0_EXT_SYNC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel26))

#define ioctlXBAR_A_SET_OUT_PWMB1_EXT_SYNC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel27))

#define ioctlXBAR_A_SET_OUT_PWMB2_EXT_SYNC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel27))

#define ioctlXBAR_A_SET_OUT_PWMB3_EXT_SYNC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel28))

#define ioctlXBAR_A_SET_OUT_PWMB_FORCE(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel28))

#define ioctlXBAR_A_SET_OUT_EWM_IN(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel29))

#endif

#if XBAR_VERSION == 3
    
#define ioctlXBAR_A_SET_OUT_GPIO_C8_F2(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel3))
    
#define ioctlXBAR_A_SET_OUT_GPIO_C9_F4(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel4))
    
#define ioctlXBAR_A_SET_OUT_GPIO_C10_F5(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel4))
    
#define ioctlXBAR_A_SET_OUT_GPIO_F_8(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel5))
    
#define ioctlXBAR_A_SET_OUT_GPIO_C_2(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel5))

#define ioctlXBAR_A_SET_OUT_DACB_SYNC(pXbarBase, param) \
   periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel7)) 
     
#define ioctlXBAR_A_SET_OUT_DACA_SYNC(pXbarBase, param) \
   periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel7))
    
#define ioctlXBAR_A_SET_OUT_PWMA_EXT_CLK(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel14))

#define ioctlXBAR_A_SET_OUT_PWMA_FAULT0(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel14))

#define ioctlXBAR_A_SET_OUT_PWMA_FAULT1(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel15))

#define ioctlXBAR_A_SET_OUT_PWMA_FAULT2(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel15))

#define ioctlXBAR_A_SET_OUT_PWMA_FAULT3(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel16))
    
#define ioctlXBAR_A_SET_OUT_QT_A0_IN(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel17))

#define ioctlXBAR_A_SET_OUT_QT_A1_IN(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel17))

#define ioctlXBAR_A_SET_OUT_QT_A2_IN(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel18))

#define ioctlXBAR_A_SET_OUT_QT_A3_IN(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel18))

#define ioctlXBAR_A_SET_OUT_SCI0_RXD(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel19))

#define ioctlXBAR_A_SET_OUT_SCI1_RXD(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbara_sel19))

#define ioctlXBAR_A_SET_OUT_EWM_IN(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbara_sel20))
    
#endif 
    
/* Crossbar switch B ioctl commands */

#define ioctlXBAR_B_SET_OUT_AOI_O_A(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbarb_sel0))

#define ioctlXBAR_B_SET_OUT_AOI_O_B(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbarb_sel0))

#define ioctlXBAR_B_SET_OUT_AOI_O_C(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbarb_sel1))

#define ioctlXBAR_B_SET_OUT_AOI_O_D(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbarb_sel1))

#define ioctlXBAR_B_SET_OUT_AOI_1_A(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbarb_sel2))

#define ioctlXBAR_B_SET_OUT_AOI_1_B(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbarb_sel2))

#define ioctlXBAR_B_SET_OUT_AOI_1_C(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbarb_sel3))

#define ioctlXBAR_B_SET_OUT_AOI_1_D(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbarb_sel3))

#define ioctlXBAR_B_SET_OUT_AOI_2_A(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbarb_sel4))

#define ioctlXBAR_B_SET_OUT_AOI_2_B(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbarb_sel4))

#define ioctlXBAR_B_SET_OUT_AOI_2_C(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbarb_sel5))

#define ioctlXBAR_B_SET_OUT_AOI_2_D(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbarb_sel5))

#define ioctlXBAR_B_SET_OUT_AOI_3_A(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbarb_sel6))

#define ioctlXBAR_B_SET_OUT_AOI_3_B(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbarb_sel6))

#define ioctlXBAR_B_SET_OUT_AOI_3_C(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbarb_sel7))

#define ioctlXBAR_B_SET_OUT_AOI_3_D(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbarb_sel7))

#endif

#if XBAR_VERSION == 2 || XBAR_VERSION == 3

/* reads data from Xbar A control registers */
#define ioctlXBAR_A_READ_CROSSBAR_REG_0(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel0))

#define ioctlXBAR_A_READ_CROSSBAR_REG_1(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel1))

#define ioctlXBAR_A_READ_CROSSBAR_REG_2(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel2))

#define ioctlXBAR_A_READ_CROSSBAR_REG_3(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel3))

#define ioctlXBAR_A_READ_CROSSBAR_REG_4(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel4))

#define ioctlXBAR_A_READ_CROSSBAR_REG_5(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel5))

#define ioctlXBAR_A_READ_CROSSBAR_REG_6(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel6))

#define ioctlXBAR_A_READ_CROSSBAR_REG_7(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel7))

#define ioctlXBAR_A_READ_CROSSBAR_REG_8(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel8))

#define ioctlXBAR_A_READ_CROSSBAR_REG_9(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel9))

#define ioctlXBAR_A_READ_CROSSBAR_REG_10(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel10))

#define ioctlXBAR_A_READ_CROSSBAR_REG_11(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel11))

#define ioctlXBAR_A_READ_CROSSBAR_REG_12(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel12))

#define ioctlXBAR_A_READ_CROSSBAR_REG_13(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel13))

#define ioctlXBAR_A_READ_CROSSBAR_REG_14(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel14))
  
#define ioctlXBAR_A_READ_CROSSBAR_REG_15(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel15))

#define ioctlXBAR_A_READ_CROSSBAR_REG_16(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel16))

#define ioctlXBAR_A_READ_CROSSBAR_REG_17(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel17))

#define ioctlXBAR_A_READ_CROSSBAR_REG_18(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel18))

#define ioctlXBAR_A_READ_CROSSBAR_REG_19(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel19))
  
#define ioctlXBAR_A_READ_CROSSBAR_REG_20(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel20))

#if XBAR_VERSION == 2
  
#define ioctlXBAR_A_READ_CROSSBAR_REG_21(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel21))

#define ioctlXBAR_A_READ_CROSSBAR_REG_22(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel12))

#define ioctlXBAR_A_READ_CROSSBAR_REG_23(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel23))

#define ioctlXBAR_A_READ_CROSSBAR_REG_24(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel24))
  
#define ioctlXBAR_A_READ_CROSSBAR_REG_25(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel25))

#define ioctlXBAR_A_READ_CROSSBAR_REG_26(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel26))

#define ioctlXBAR_A_READ_CROSSBAR_REG_27(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel27))

#define ioctlXBAR_A_READ_CROSSBAR_REG_28(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel28))

#define ioctlXBAR_A_READ_CROSSBAR_REG_29(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_sel29))

#endif /* XBAR_VERSION == 2 */

#define ioctlXBAR_A_READ_CROSSBAR_CTRL_0(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_ctrl0))
    
#define ioctlXBAR_A_READ_CROSSBAR_CTRL_1(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbara_ctrl1))

/* reads data from Xbar B control registers */
#define ioctlXBAR_B_READ_CROSSBAR_REG_0(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbarb_sel0))

#define ioctlXBAR_B_READ_CROSSBAR_REG_1(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbarb_sel1))

#define ioctlXBAR_B_READ_CROSSBAR_REG_2(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbarb_sel2))

#define ioctlXBAR_B_READ_CROSSBAR_REG_3(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbarb_sel3))

#define ioctlXBAR_B_READ_CROSSBAR_REG_4(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbarb_sel4))

#define ioctlXBAR_B_READ_CROSSBAR_REG_5(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbarb_sel5))

#define ioctlXBAR_B_READ_CROSSBAR_REG_6(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbarb_sel6))

#define ioctlXBAR_B_READ_CROSSBAR_REG_7(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbarb_sel7))


/* writes data to Xbar A control registers */
#define ioctlXBAR_A_WRITE_CROSSBAR_REG_0(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel0))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_1(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel1))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_2(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel2))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_3(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel3))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_4(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel4))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_5(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel5))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_6(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel6))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_7(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel7))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_8(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel8))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_9(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel9))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_10(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel10))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_11(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel11))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_12(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel12))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_13(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel13))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_14(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel14))
  
#define ioctlXBAR_A_WRITE_CROSSBAR_REG_15(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel15))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_16(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel16))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_17(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel17))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_18(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel18))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_19(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel19))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_20(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel20))

#if XBAR_VERSION == 2

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_21(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel21))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_22(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel22))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_23(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel23))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_24(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel24))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_25(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel25))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_26(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel26))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_27(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel27))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_28(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel28))

#define ioctlXBAR_A_WRITE_CROSSBAR_REG_29(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_sel29))    

#endif /* XBAR_VERSION == 2 */

#define ioctlXBAR_A_WRITE_CROSSBAR_CTRL_0(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_ctrl0))

#define ioctlXBAR_A_WRITE_CROSSBAR_CTRL_1(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbara_ctrl1))

/* writes data to Xbar control registers */

#define ioctlXBAR_B_WRITE_CROSSBAR_REG_0(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbarb_sel0))

#define ioctlXBAR_B_WRITE_CROSSBAR_REG_1(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbarb_sel1))

#define ioctlXBAR_B_WRITE_CROSSBAR_REG_2(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbarb_sel2))

#define ioctlXBAR_B_WRITE_CROSSBAR_REG_3(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbarb_sel3))

#define ioctlXBAR_B_WRITE_CROSSBAR_REG_4(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbarb_sel4))

#define ioctlXBAR_B_WRITE_CROSSBAR_REG_5(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbarb_sel5))

#define ioctlXBAR_B_WRITE_CROSSBAR_REG_6(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbarb_sel6))

#define ioctlXBAR_B_WRITE_CROSSBAR_REG_7(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbarb_sel7))

#endif

#if XBAR_VERSION == 1
    /* Crossbar Control Register 0 */
#define ioctlXBAR_SET_OUT_GPIO_C_14(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc0))

#define ioctlXBAR_SET_OUT_GPIO_C_15(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc0))

/* Crossbar Control Register 1 */
#define ioctlXBAR_SET_OUT_GPIO_F_2(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc1))

#define ioctlXBAR_SET_OUT_GPIO_F_3(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc1))

/* Crossbar Control Register 2 */
#define ioctlXBAR_SET_OUT_GPIO_F_4(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc2))

#define ioctlXBAR_SET_OUT_GPIO_F_5(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc2))

/* Crossbar Control Register 3 */
#define ioctlXBAR_SET_OUT_ADCA_TRIGGER(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc3))

#define ioctlXBAR_SET_OUT_ADCB_TRIGGER(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc3))

/* Crossbar Control Register 4 */
#define ioctlXBAR_SET_OUT_DAC_SYNC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc4))

#define ioctlXBAR_SET_OUT_CMPA_SAMPLE(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc4))

/* Crossbar Control Register 5 */
#define ioctlXBAR_SET_OUT_CMPB_SAMPLE(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc5))

#define ioctlXBAR_SET_OUT_CMPC_SAMPLE(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc5))

/* Crossbar Control Register 6 */
#define ioctlXBAR_SET_OUT_PWM0_EXTA(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc6))

#define ioctlXBAR_SET_OUT_PWM1_EXTA(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc6))

/* Crossbar Control Register 7 */
#define ioctlXBAR_SET_OUT_PWM2_EXTA(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc7))

#define ioctlXBAR_SET_OUT_PWM3_EXTA(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc7))

/* Crossbar Control Register 8 */
#define ioctlXBAR_SET_OUT_PWM0_EXT_SYNC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc8))

#define ioctlXBAR_SET_OUT_PWM1_EXT_SYNC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc8))

/* Crossbar Control Register 9 */
#define ioctlXBAR_SET_OUT_PWM2_EXT_SYNC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc9))

#define ioctlXBAR_SET_OUT_PWM3_EXT_SYNC(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc9))

/* Crossbar Control Register 10 */
#define ioctlXBAR_SET_OUT_PWM_EXT_CLK(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc10))

#define ioctlXBAR_SET_OUT_PWM_FAULT0(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc10))

/* Crossbar Control Register 11 */
#define ioctlXBAR_SET_OUT_PWM_FAULT1(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc11))

#define ioctlXBAR_SET_OUT_PWM_FAULT2(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc11))

/* Crossbar Control Register 12 */
#define ioctlXBAR_SET_OUT_PWM_FAULT3(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc12))

#define ioctlXBAR_SET_OUT_PWM_FORCE(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc12))

/* Crossbar Control Register 13 */
#define ioctlXBAR_SET_OUT_QT_B0(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc13))

#define ioctlXBAR_SET_OUT_QT_B1(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc13))

/* Crossbar Control Register 14 */
#define ioctlXBAR_SET_OUT_QT_B2(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE0_MASK, param, &((pXbarBase)->xbc14))

#define ioctlXBAR_SET_OUT_QT_B3(pXbarBase, param) \
  periphBitGrpSet(XBAR_XBCX_CODE1_MASK, ((param) << 8), &((pXbarBase)->xbc14))

/* writes data in to Xbar control registers */
#define ioctlXBAR_WRITE_CROSSBARR_REG_0(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_0(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_0(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc0))

#define ioctlXBAR_WRITE_CROSSBARR_REG_1(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_1(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_1(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc1))

#define ioctlXBAR_WRITE_CROSSBARR_REG_2(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_2(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_2(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc2))

#define ioctlXBAR_WRITE_CROSSBARR_REG_3(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_3(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_3(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc3))

#define ioctlXBAR_WRITE_CROSSBARR_REG_4(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_4(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_4(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc4))

#define ioctlXBAR_WRITE_CROSSBARR_REG_5(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_5(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_5(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc5))

#define ioctlXBAR_WRITE_CROSSBARR_REG_6(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_6(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_6(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc6))

#define ioctlXBAR_WRITE_CROSSBARR_REG_7(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_7(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_7(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc7))

#define ioctlXBAR_WRITE_CROSSBARR_REG_8(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_8(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_8(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc8))

#define ioctlXBAR_WRITE_CROSSBARR_REG_9(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_9(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_9(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc9))

#define ioctlXBAR_WRITE_CROSSBARR_REG_10(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_10(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_10(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc10))

#define ioctlXBAR_WRITE_CROSSBARR_REG_11(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_11(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_11(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc11))

#define ioctlXBAR_WRITE_CROSSBARR_REG_12(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_12(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_12(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc12))

#define ioctlXBAR_WRITE_CROSSBARR_REG_13(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_13(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_13(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc13))

#define ioctlXBAR_WRITE_CROSSBARR_REG_14(pXbarBase, param) ioctlXBAR_WRITE_CROSSBAR_REG_14(pXbarBase, param)
#define ioctlXBAR_WRITE_CROSSBAR_REG_14(pXbarBase, param) \
  periphMemWrite(param, &((pXbarBase)->xbc14))

/* reads data from Xbar control registers */
#define ioctlXBAR_READ_CROSSBARR_REG_0(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_0(pXbarBase, param)
#define ioctlXBAR_READ_CROSSBAR_REG_0(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc0))

#define ioctlXBAR_READ_CROSSBARR_REG_1(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_1(pXbarBase, param)
#define ioctlXBAR_READ_CROSSBAR_REG_1(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc1))

#define ioctlXBAR_READ_CROSSBARR_REG_2(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_2(pXbarBase, param)
#define ioctlXBAR_READ_CROSSBAR_REG_2(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc2))

#define ioctlXBAR_READ_CROSSBARR_REG_3(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_3(pXbarBase, param)
#define ioctlXBAR_READ_CROSSBAR_REG_3(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc3))

#define ioctlXBAR_READ_CROSSBARR_REG_4(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_4(pXbarBase, param)
#define ioctlXBAR_READ_CROSSBAR_REG_4(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc4))

#define ioctlXBAR_READ_CROSSBARR_REG_5(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_5(pXbarBase, param)
#define ioctlXBAR_READ_CROSSBAR_REG_5(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc5))

#define ioctlXBAR_READ_CROSSBARR_REG_6(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_6(pXbarBase, param)
#define ioctlXBAR_READ_CROSSBAR_REG_6(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc6))

#define ioctlXBAR_READ_CROSSBARR_REG_7(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_7(pXbarBase, param)
#define ioctlXBAR_READ_CROSSBAR_REG_7(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc7))

#define ioctlXBAR_READ_CROSSBARR_REG_8(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_8(pXbarBase, param)
#define ioctlXBAR_READ_CROSSBAR_REG_8(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc8))

#define ioctlXBAR_READ_CROSSBARR_REG_9(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_9(pXbarBase, param)
#define ioctlXBAR_READ_CROSSBAR_REG_9(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc9))

#define ioctlXBAR_READ_CROSSBARR_REG_10(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_10(pXbarBase, param)
#define ioctlXBAR_READ_CROSSBAR_REG_10(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc10))
#define ioctlXBAR_READ_CROSSBARR_REG_11(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_11(pXbarBase, param)

#define ioctlXBAR_READ_CROSSBAR_REG_11(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc11))

#define ioctlXBAR_READ_CROSSBARR_REG_12(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_12(pXbarBase, param)
#define ioctlXBAR_READ_CROSSBAR_REG_12(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc12))

#define ioctlXBAR_READ_CROSSBARR_REG_13(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_13(pXbarBase, param)
#define ioctlXBAR_READ_CROSSBAR_REG_13(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc13))

#define ioctlXBAR_READ_CROSSBARR_REG_14(pXbarBase, param) ioctlXBAR_READ_CROSSBAR_REG_14(pXbarBase, param)
#define ioctlXBAR_READ_CROSSBAR_REG_14(pXbarBase, param) \
  periphMemRead(&((pXbarBase)->xbc14))

#ifdef __cplusplus
}
#endif
#endif

#endif
