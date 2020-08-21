/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  pwm.h
*
* $Date:      Dec-19-2014$
*
* $Version:   2.5.49.0$
*
* Description: Header file for the EPWM driver
*
* This file supports different hardware versions of the module. A version
* of module used in your project is defined in the "arch.h" processor 
* architecture definition file.
*
*  EFPWM_VERSION_1 .. 56F82xx devices, see MC56F824x5xRM.pdf
*  EFPWM_VERSION_2 .. 56F84xxx devices, see MC56F84xxxRM.pdf
*  EFPWM_VERSION_3 .. 56F827xx devices, see MC56F827xxRM.pdf
*
*******************************************************************************/

#ifndef __EFPWM_H
#define __EFPWM_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before pwm.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*
*                      General Interface Description
*
*
* The Inteligent Pulse Width Modulator (EFPWM) modules incorporate four complementary, individually
* programmable PWM signal outputs.
* Complementary operation permits programmable dead-time insertion,
* distortion correction via current sensing by software, and separate top and bottom output
* polarity control. The up-counter value is programmable to support a continuously variable
* PWM frequency. Both edge- and center-aligned synchronous pulse width control (full 0%
* to 100% modulation) are supported. 
*
* The device is capable of controlling most motor types: 
*      ACIM (AC Induction Motors)
*      BDC and BLDC (Brush and Brushless DC motors)
*      SRM and VRM (Switched and Variable Reluctance Motors)
*      Stepper motors
*
* The PWMs incorporate fault protection and cycle-by-cycle current limiting with sufficient
* output drive capability to directly drive standard opto-isolators.
*
* A patented PWM
* waveform distortion correction circuit is also provided. Each PWM is double-buffered and
* includes interrupt controls to permit integral reload rates to be programmable from 1 to 16.
* The PWM modules also provide a reference output to synchronize the Analog-to-Digital
* Converters.
*
* For more information, please refer to the user manual for the particular chip that you
* are using, such as the MC56F824x5x Peripheral Manual, for a description
* of the EFPWM device.
*
* The PWM device driver interface uses "ioctl" call to control specific PWM functions
* during operation. For details see "ioctl" call.
*
******************************************************************************/

/************************************************************
* EFPWM module identifiers, correspond to module base address
*************************************************************/

#ifdef EFPWMA_BASE
#define EFPWM_A         (&ArchIO.EfpwmA)
#define EFPWM_A_SUB0    (&ArchIO.EfpwmA.Sub0)
#define EFPWM_A_SUB1    (&ArchIO.EfpwmA.Sub1)
#define EFPWM_A_SUB2    (&ArchIO.EfpwmA.Sub2)
#define EFPWM_A_SUB3    (&ArchIO.EfpwmA.Sub3)
//aletrnate name for modules
#define EFPWMA          EFPWM_A
#define EFPWMA_SUB0     EFPWM_A_SUB0
#define EFPWMA_SUB1     EFPWM_A_SUB1
#define EFPWMA_SUB2     EFPWM_A_SUB2
#define EFPWMA_SUB3     EFPWM_A_SUB3
#endif

#ifdef EFPWM_BASE
#define EFPWM           (&ArchIO.Efpwm)
#define EFPWM_SUB0      (&ArchIO.Efpwm.Sub0)
#define EFPWM_SUB1      (&ArchIO.Efpwm.Sub1)
#define EFPWM_SUB2      (&ArchIO.Efpwm.Sub2)
#define EFPWM_SUB3      (&ArchIO.Efpwm.Sub3)
#endif

#ifdef EFPWMB_BASE
#define EFPWM_B         (&ArchIO.EfpwmB)
#define EFPWM_B_SUB0    (&ArchIO.EfpwmB.Sub0)
#define EFPWM_B_SUB1    (&ArchIO.EfpwmB.Sub1)
#define EFPWM_B_SUB2    (&ArchIO.EfpwmB.Sub2)
#define EFPWM_B_SUB3    (&ArchIO.EfpwmB.Sub3)
#endif

/*************************************************************
* arch.h should define device-specific information about EFPWM
**************************************************************/

#if !defined(EFPWM_VERSION)
#error EFPWM not properly described in arch.h (old Quick_Start version?)
#endif

/****************************************************
* Configurable items, i.e. defines, for appconfig.h
*****************************************************

  #define INTERRUPT_VECTOR_ADDR_yy  // specify interrupt handler routine
  #define INT_PRIORITY_LEVEL_yy     // interrupt level : (INTC_DISABLED, INTC_LEVEL0, ... INTC_LEVEL2)

  Submodule Congiguration
  #define  PWM_x_CTRL_INIT      0x0000 
  #define  PWM_x_CTRL2_INIT     0x0000
  #define  PWM_x_INIT_INIT      0x0000
  #define  PWM_x_VAL1_INIT      0x0000
  #define  PWM_x_VAL0_INIT      0x0000
  #define  PWM_x_VAL2_INIT      0x0000
  #define  PWM_x_VAL3_INIT      0x0000
  #define  PWM_x_VAL4_INIT      0x0000
  #define  PWM_x_VAL5_INIT      0x0000
  #define  PWM_x_FRACVAL1_INIT  0x0000
  #define  PWM_x_FRACVAL2_INIT  0x0000
  #define  PWM_x_FRACVAL3_INIT  0x0000
  #define  PWM_x_FRACVAL4_INIT  0x0000
  #define  PWM_x_FRACVAL5_INIT  0x0000
  #define  PWM_x_FRCTRL_INIT    0x0000
  #define  PWM_x_OCTRL_INIT     0x0000
  #define  PWM_x_TCTRL_INIT     0x0000
  #define  PWM_x_DTCNT0_INIT    0x0000
  #define  PWM_x_DTCNT1_INIT    0x0000
  #define  PWM_x_INTEN_INIT     0x0000
  #define  PWM_x_DISMAP_INIT    0x0000

  where:
         x  is PWM Submodule ( 0, 1, 2 or 3)

  #define  PWM_3_CAPTCTRLA_INIT 0x0000
  #define  PWM_3_CAPTCOMPA_INIT 0x0000
  #define  PWM_3_CAPTCTRLB_INIT 0x0000
  #define  PWM_3_CAPTCOMPB_INIT 0x0000
  #define  PWM_3_CAPTCTRLX_INIT 0x0000
  #define  PWM_3_CAPTCOMPX_INIT 0x0000

  Module Configuration
  #define  PWM_MCTRL_INIT       0x0000
  #define  PWM_MCTRL2_INIT      0x0000
  #define  PWM_MASK_INIT        0x0000
  #define  PWM_OUTEN_INIT       0x0000
  #define  PWM_SWCOUT_INIT      0x0000
  #define  PWM_DTSRCSEL_INIT    0x0000
  
*/

/*****************************************************************
* Single-Instruction ioctl() commands
*
*  Word16 ioctl( PWM_module_identifier, Co;mmand_name, Parameter );
*
******************************************************************

 COMMAND NAME                             PARAMETERS, COMMENTS
------------------------------------------------------------------ */

/* submodule commands */

#define EFPWMS_READ_COUNTER_REG             /* NULL, Return value from the Counter Register. (SMxCNT->_) */
#define EFPWMS_WRITE_INIT_REG               /* Word16, Write value to the Init Register. (SMxINIT->_) */
#define EFPWMS_READ_INIT_REG                /* NULL, Return Word16 from the Init Register. (SMxINIT->_) */

#define EFPWMS_HALF_CYCLE_RELOAD            /* EFPWM_ENABLE/EFPWM_DISABLE, enable/disable middle cycle reload. (SMxCTRL->HALF) */
#define EFPWMS_FULL_CYCLE_RELOAD            /* EFPWM_ENABLE/EFPWM_DISABLE, enable/disable full cycle reload. (SMxCTRL->FULL) */
#define	EFPWMS_TEST_DEADTIME_SAMPLE_BITS    /* EFPWM_DEADTIME_0_BIT|EFPWM_DEADTIME_1_BIT, Return sampled PWMX inputs at dealdtime 0/1. (SMxCTRL->DT)  */
#define EFPWMS_SET_LOAD_MODE                /* EFPWM_LOAD_xx (IMMEDIATE/END_CYCLE), select load mode. (SMxCTRL->LDMOD) */
#define EFPWMS_SET_DOUBLE_SWITCHING         /* EFPWM_ENABLE/EFPWM_DISABLE, enable/disable double switching mode. (SMxCTRL->DBLEN) */
#if EFPWM_VERSION >= 3 
#define EFPWMS_SPLIT_DBLPWM					/* EFPWM_ENABLE/EFPWM_DISABLE, enable/disable splitting one pulse on PWMA and one on PWMB. (SMxCTRL->SPLIT)*/
#endif	 
#define EFPWMS_DEBUG_OPERATION              /* EFPWM_STOP/EFPWM_RUN, Set PWM operation during chip debuging. (SMxCTRL2->DBGEN) */
#define EFPWMS_WAIT_OPERATION               /* EFPWM_STOP/EFPWM_RUN, Set PWM operation during the wait mode. (SMxCTRL2->WAITEN) */
#define EFPWMS_SET_INDEPENDENT_MODE         /* NULL, set pair operation to independent. (SMxCTRL2->INDEP) */
#define EFPWMS_SET_COMPLEMENTARY_MODE       /* NULL, set pair operation to complementary. (SMxCTRL2->INDEP) */
#define EFPWMS_SET_PAIR_OPERATION           /* EFPWM_XXX (COMPLEMENTARY/INDEPENDENT), set pair operation. (SMxCTRL2->INDEP) */
#define EFPWMS_SET_FORCE_INIT_PWMOUT_TO_HIGH/* EFPWM_CHANNEL_45|EFPWM_CHANNEL_23|EFPWM_CHANNEL_X,determine the initial value and the value to which it is forced when FORCE_INIT;Control 2 Register. (SMxCTRL2->PWM23_INIT,PWM45_INIT,PWMX_INIT) */
#define EFPWMS_SET_FORCE_INIT_PWMOUT_TO_LOW /* EFPWM_CHANNEL_45|EFPWM_CHANNEL_23|EFPWM_CHANNEL_X,determine the initial value and the value to which it is forced when FORCE_INIT;Control 2 Register. (SMxCTRL2->PWM23_INIT,PWM45_INIT,PWMX_INIT) */
#define EFPWMS_SET_FORCE_INIT               /* EFPWM_ENABLE/EFPWM_DISABLE, enable/disable force initialization. (SMxCTRL2->FRCEN) */
#define EFPWMS_ACTIVE_FORCE_INIT            /* NULL, active force initialization. (SMxCTRL2->FORCE) */
#define EFPWMS_SET_RELOAD_SOURCE            /* EFPWM_RELOAD_XXX (LOCAL/MASTER), select PWM reload source. (SMxCTRL2->RELOAD_SEL) */

#define EFPWMS_WRITE_VALUE_REG_0            /* Word16, write Value to Value Register 0. (SMnVAL0->_) */
#define EFPWMS_WRITE_VALUE_REG_1            /* Word16, write Value to Value Register 1. (SMnVAL1->_) */
#define EFPWMS_WRITE_VALUE_REG_2            /* Word16, write Value to Value Register 2. (SMnVAL2->_) */
#define EFPWMS_WRITE_VALUE_REG_3            /* Word16, write Value to Value Register 3. (SMnVAL3->_) */
#define EFPWMS_WRITE_VALUE_REG_4            /* Word16, write Value to Value Register 4. (SMnVAL4->_) */
#define EFPWMS_WRITE_VALUE_REG_5            /* Word16, write Value to Value Register 5. (SMnVAL5->_) */

#define EFPWMS_READ_VALUE_REG_0             /* NULL, Return Word16 from Value Register 0. (SMnVAL0->_) */
#define EFPWMS_READ_VALUE_REG_1             /* NULL, Return Word16 from Value Register 1. (SMnVAL1->_) */
#define EFPWMS_READ_VALUE_REG_2             /* NULL, Return Word16 from Value Register 2. (SMnVAL2->_) */
#define EFPWMS_READ_VALUE_REG_3             /* NULL, Return Word16 from Value Register 3. (SMnVAL3->_) */
#define EFPWMS_READ_VALUE_REG_4             /* NULL, Return Word16 from Value Register 4. (SMnVAL4->_) */
#define EFPWMS_READ_VALUE_REG_5             /* NULL, Return Word16 from Value Register 5. (SMnVAL5->_) */


#define EFPWMS_WRITE_FRAC_VALUE_REG_1       /* Word16, write fractional Value to Fractional Value Register 1. (SMnFRACVAL1->_) */
#define EFPWMS_WRITE_FRAC_VALUE_REG_2       /* Word16, write fractional Value to Fractional Value Register 2. (SMnFRACVAL2->_) */
#define EFPWMS_WRITE_FRAC_VALUE_REG_3       /* Word16, write fractional Value to Fractional Value Register 3. (SMnFRACVAL3->_) */
#define EFPWMS_WRITE_FRAC_VALUE_REG_4       /* Word16, write fractional Value to Fractional Value Register 4. (SMnFRACVAL4->_) */
#define EFPWMS_WRITE_FRAC_VALUE_REG_5       /* Word16, write fractional Value to Fractional Value Register 5. (SMnFRACVAL5->_) */
                                            
#define EFPWMS_SET_FRACTIONAL_DELAY_ENABLE  /* EFPWM_FRAC_DELAY_X (1|23|45|POWERUP),enable selected fractional delay block. (SMxFRCTRL->FRACX_EN) */
#define EFPWMS_SET_FRACTIONAL_DELAY_DISABLE /* EFPWM_FRAC_DELAY_X (1|23|45|POWERUP),disable selected fractional delay block. (SMxFRCTRL->FRACX_EN) */

#define EFPWMS_TEST_PWM_INPUTS              /* EFPWM_INPUT_X (A|B|X),Return actual state of selected PWM pins. (SMxOCTRL->PWMA_IN,PWMB_IN,PWMX_IN) */
#define EFPWMS_SET_PWM_POLARITY_HIGH_ACTIVE /* EFPWM_OUTPUT_X (A|B|X),Set output polarity to non inverted, where high is active state. (SMxOCTRL->POLA,POLB,POLX) */
#define EFPWMS_SET_PWM_POLARITY_LOW_ACTIVE  /* EFPWM_OUTPUT_X (A|B|X),Set output polarity to inverted, where low is active state (SMxOCTRL->POLA,POLB,POLX) */
#define EFPWMS_WRITE_OUTPUT_CONTROL_REG     /* UWord16, Writes in to Output Control Register (SMxOCTRL->_) */

#define EFPWMS_TEST_SUBMODULE_FLAGS         /* EFPWM_xxx (REGISTER_UPDATE|RELOAD_ERROR|RELOAD|COMPARE_VAL0|COMPARE_VAL1|COMPARE_VAL2|COMPARE_VAL3|COMPARE_VAL4|COMPARE_VAL5|CAPTURE_A1|CAPTURE_A0|CAPTURE_B1|CAPTURE_B0|CAPTURE_X1|CAPTURE_X0), Return state of selected interrupt flags. (SMxSTS->_)  note: All parameters are not supported in all PWM submodules, see documentation */
#define EFPWMS_CLEAR_SUBMODULE_FLAGS        /* EFPWM_xxx (RELOAD_ERROR|RELOAD|COMPARE_VAL0|COMPARE_VAL1|COMPARE_VAL2|COMPARE_VAL3|COMPARE_VAL4|COMPARE_VAL5|CAPTURE_A1|CAPTURE_A0|CAPTURE_B1|CAPTURE_B0|CAPTURE_X1|CAPTURE_X0), Clear selected interrupt flags. (SMxSTS->_) note: All parameters are not supported in all PWM submodules, see documentation */
#define EFPWMS_INT_ENABLE                   /* EFPWM_xxx (RELOAD_ERROR|RELOAD|COMPARE_VAL0|COMPARE_VAL1|COMPARE_VAL2|COMPARE_VAL3|COMPARE_VAL4|COMPARE_VAL5|CAPTURE_A1|CAPTURE_A0|CAPTURE_B1|CAPTURE_B0|CAPTURE_X1|CAPTURE_X0), Enable selected interrupts. (SMxINTEN->_) note: All parameters are not supported in all PWM submodules, see documentation */
#define EFPWMS_INT_DISABLE                  /* EFPWM_xxx (RELOAD_ERROR|RELOAD|COMPARE_VAL0|COMPARE_VAL1|COMPARE_VAL2|COMPARE_VAL3|COMPARE_VAL4|COMPARE_VAL5|CAPTURE_A1|CAPTURE_A0|CAPTURE_B1|CAPTURE_B0|CAPTURE_X1|CAPTURE_X0), Enable selected interrupts. (SMxINTEN->_) note: All parameters are not supported in all PWM submodules, see documentation */

#define EFPWMS_OUTPUT_TRIGGER_ENABLE        /* EFPWM_TRIG0_VALx(0|2|4)|EFPWM_TRIG1_VALx(1|3|5), Connect selected output triggers in to OUT_TRIG0 and OUT_TRIG1 signals. (SMxTCTRL->OUT_TRIG_EN) */
#define EFPWMS_OUTPUT_TRIGGER_DISABLE       /* EFPWM_TRIG0_VALx(0|2|4)|EFPWM_TRIG1_VALx(1|3|5), Disconnect selected output triggers from OUT_TRIG0 and OUT_TRIG1 signals. (SMxTCTRL->OUT_TRIG_EN) */
#define EFPWMS_DMA_CAPTURE_ENABLE			/* EFPWM_DMA_FIFO_X0|EFPWM_DMA_FIFO_B0|EFPWM_DMA_FIFO_A0|EFPWM_DMA_FIFO_X1|EFPWM_DMA_FIFO_B1|EFPWM_DMA_FIFO_A1, enable DMA read requests for the Capture (A0/A1/B0/B1/X0/X1) FIFO data in the DMA Enable Register. (SMxDMAEN->[0-5]) */
#define EFPWMS_DMA_CAPTURE_DISABLE			/* EFPWM_DMA_FIFO_X0|EFPWM_DMA_FIFO_B0|EFPWM_DMA_FIFO_A0|EFPWM_DMA_FIFO_X1|EFPWM_DMA_FIFO_B1|EFPWM_DMA_FIFO_A1, disable DMA read requests for the Capture (A0/A1/B0/B1/X0/X1) FIFO data in the DMA Enable Register (SMxDMAEN->[0-5]) */
#define EFPWMS_DMA_SET_CLOCK_SOURCE			/* EFPWM_DMA_REQUEST_DISABLE/EFPWM_DMA_REQUEST_FIFO_WATERMARK/EFPWM_DMA_REQUEST_LOCAL_SYNC/EFPWM_DMA_REQUEST_LOCAL_RELOAD, Enable Source for Capture DMA according to command parameter. Modify the DMA Enable Register. (SMxDMAEN->CAPTDE[6-7])  */
#define EFPWMS_DMA_FIFO_WATERMARK_CONTROL 	/* EFPWM_DMA_WRITE_FIFO_WATERMARK_AND/EFPWM_DMA_WRITE_FIFO_WATERMARK_OR, Select wheather FIFO watermarks are OR'ed or AND'ed together. Modify the DMA Enable Register. (SMxDMAEN->FAND[8])  */
#define EFPWMS_DMA_VALUE_REGISTERS			/* EFPWM_DMA_WRITE_REQUEST_ENABLE/EFPWM_DMA_WRITE_REQUEST_DISSABLE, Enable/dissable DMA write requests for the VALx and FRACVALx registers. Modify the DMA Enable Register. (SMxDMAEN->VALDE[9])  */

#define EFPWMS_PWMX_FAULT_ENABLE            /* EFPWM_FAULT_X(0|1|2|3), Enable selected faults at PWM X pin. (SMxDISMAP->DISX) */
#define EFPWMS_PWMX_FAULT_DISABLE           /* EFPWM_FAULT_X(0|1|2|3), Disable selected faults at PWM X pin. (SMxDISMAP->DISX) */
#define EFPWMS_PWMB_FAULT_ENABLE            /* EFPWM_FAULT_X(0|1|2|3), Enable selected faults at PWM B pin. (SMxDISMAP->DISB) */
#define EFPWMS_PWMB_FAULT_DISABLE           /* EFPWM_FAULT_X(0|1|2|3), Disable selected faults at PWM B pin. (SMxDISMAP->DISB) */
#define EFPWMS_PWMA_FAULT_ENABLE            /* EFPWM_FAULT_X(0|1|2|3), Enable selected faults at PWM A pin. (SMxDISMAP->DISA) */
#define EFPWMS_PWMA_FAULT_DISABLE           /* EFPWM_FAULT_X(0|1|2|3), Disable selected faults at PWM A pin. (SMxDISMAP->DISA) */
#define EFPWMS_WRITE_FAULT_MAPPING_REG      /* UWord16, Write directly in to the fault Disable Mapping Register. (SMxDISMAP->_)  */

#if EFPWM_VERSION >= 2
#define EFPWMS_PWMX_FAULT0_ENABLE           /* EFPWM_FAULT_X(0|1|2|3), Enable selected faults at PWM X pin. (SMxDISMAP0->DISX) */
#define EFPWMS_PWMX_FAULT0_DISABLE          /* EFPWM_FAULT_X(0|1|2|3), Disable selected faults at PWM X pin. (SMxDISMAP0->DISX) */
#define EFPWMS_PWMB_FAULT0_ENABLE           /* EFPWM_FAULT_X(0|1|2|3), Enable selected faults at PWM B pin. (SMxDISMAP0->DISB) */
#define EFPWMS_PWMB_FAULT0_DISABLE          /* EFPWM_FAULT_X(0|1|2|3), Disable selected faults at PWM B pin. (SMxDISMAP0->DISB) */
#define EFPWMS_PWMA_FAULT0_ENABLE           /* EFPWM_FAULT_X(0|1|2|3), Enable selected faults at PWM A pin. (SMxDISMAP0->DISA) */
#define EFPWMS_PWMA_FAULT0_DISABLE          /* EFPWM_FAULT_X(0|1|2|3), Disable selected faults at PWM A pin. (SMxDISMAP0->DISA) */
#define EFPWMS_WRITE_FAULT0_MAPPING_REG     /* UWord16, Write directly in to the fault Disable Mapping Register. (SMxDISMAP0->_)  */
#define EFPWMS_PWMX_FAULT1_ENABLE           /* EFPWM_FAULT_X(0|1|2|3), Enable selected faults at PWM X pin. (SMxDISMAP1->DISX) */
#define EFPWMS_PWMX_FAULT1_DISABLE          /* EFPWM_FAULT_X(0|1|2|3), Disable selected faults at PWM X pin. (SMxDISMAP1->DISX) */
#define EFPWMS_PWMB_FAULT1_ENABLE           /* EFPWM_FAULT_X(0|1|2|3), Enable selected faults at PWM B pin. (SMxDISMAP1->DISB) */
#define EFPWMS_PWMB_FAULT1_DISABLE          /* EFPWM_FAULT_X(0|1|2|3), Disable selected faults at PWM B pin. (SMxDISMAP1->DISB) */
#define EFPWMS_PWMA_FAULT1_ENABLE           /* EFPWM_FAULT_X(0|1|2|3), Enable selected faults at PWM A pin. (SMxDISMAP1->DISA) */
#define EFPWMS_PWMA_FAULT1_DISABLE          /* EFPWM_FAULT_X(0|1|2|3), Disable selected faults at PWM A pin. (SMxDISMAP1->DISA) */
#define EFPWMS_WRITE_FAULT1_MAPPING_REG     /* UWord16, Write directly in to the fault Disable Mapping Register. (SMxDISMAP1->_)  */
#endif

#define EFPWMS_SET_DEADTIME_0               /* UWord16, Deadtime 0 logic; value 0 to 2048. Modify Deadtime Count Register 0. (SMnDTCNT0->_) */
#define EFPWMS_SET_DEADTIME_1               /* UWord16, Deadtime 1 logic; value 0 to 2048. Modify Deadtime Count Register 1. (SMnDTCNT1->_)  */

/* Submodule with capture logic */
/* capture A */
#define EFPWMS_SET_EDGE_COUNTER_A           /* EFPWM_ENABLE/EFPWM_DISABLE, enable/disable edge counter A. (SMxCAPTCTRLA->EDGCNTA_EN) */
#define EFPWMS_SET_CAPTURE_A_INPUT          /* EFPWM_RAW_INPUT/EFPWM_EDGE_COUNTER, Set input capture A source. (SMxCAPTCTRLA->INP_SELA) */
#define EFPWMS_SET_CAPTURE_A_MODE           /* EFPWM_FREE_RUNNING/EFPWM_ONE_SHOT, Set capture mode. (SMxCAPTCTRLA->ONESHOTA) */
#define EFPWMS_ACTIVE_CAPTURE_A             /* NULL, Actives capture A operation. (SMxCAPTCTRLA->ARMA) */
#define EFPWMS_CAPTURE_A_DISABLE            /* NULL, Disable capture A operation. (SMxCAPTCTRLA->ARMA) */

/* capture B */
#define EFPWMS_SET_EDGE_COUNTER_B           /* EFPWM_ENABLE/EFPWM_DISABLE, enable/disable edge counter B. (SMxCAPTCTRLB->EDGCNTB_EN) */
#define EFPWMS_SET_CAPTURE_B_INPUT          /* EFPWM_RAW_INPUT/EFPWM_EDGE_COUNTER, Set input capture B source. (SMxCAPTCTRLB->INP_SELB) */
#define EFPWMS_SET_CAPTURE_B_MODE           /* EFPWM_FREE_RUNNING/EFPWM_ONE_SHOT, Set capture mode. (SMxCAPTCTRLB->ONESHOTB) */
#define EFPWMS_ACTIVE_CAPTURE_B             /* NULL, Actives capture B operation. (SMxCAPTCTRLB->ARMB) */
#define EFPWMS_CAPTURE_B_DISABLE            /* NULL, Disable capture B operation. (SMxCAPTCTRLB->ARMB) */

/* capture X */
#define EFPWMS_SET_EDGE_COUNTER_X           /* EFPWM_ENABLE/EFPWM_DISABLE, enable/disable edge counter X. (SMxCAPTCTRLX->EDGCNTX_EN) */
#define EFPWMS_SET_CAPTURE_X_INPUT          /* EFPWM_RAW_INPUT/EFPWM_EDGE_COUNTER, Set input capture X source. (SMxCAPTCTRLX->INP_SELX) */
#define EFPWMS_SET_CAPTURE_X_MODE           /* EFPWM_FREE_RUNNING/EFPWM_ONE_SHOT, Set capture mode. (SMxCAPTCTRLX->ONESHOTX) */
#define EFPWMS_ACTIVE_CAPTURE_X             /* NULL, Actives capture B operation. (SMxCAPTCTRLX->ARMX) */
#define EFPWMS_CAPTURE_X_DISABLE            /* NULL, Disable capture B operation. (SMxCAPTCTRLX->ARMX) */

#define EFPWMS_READ_CAPTURE_VAL0            /* NULL, Return Capture Value 0. (SMxCAPTVAL0->_) */
#define EFPWMS_READ_CAPTURE_VAL1            /* NULL, Return Capture Value 1. (SMxCAPTVAL1->_) */
#define EFPWMS_READ_CAPTURE_VAL2            /* NULL, Return Capture Value 2. (SMxCAPTVAL2->_) */
#define EFPWMS_READ_CAPTURE_VAL3            /* NULL, Return Capture Value 3. (SMxCAPTVAL3->_) */
#define EFPWMS_READ_CAPTURE_VAL4            /* NULL, Return Capture Value 4. (SMxCAPTVAL4->_) */
#define EFPWMS_READ_CAPTURE_VAL5            /* NULL, Return Capture Value 5. (SMxCAPTVAL5->_) */

#define EFPWMS_READ_CAPTURE_CYCLE_VAL0      /* NULL, Return Capture Value 0. (SMxCAPTVAL0->_) */
#define EFPWMS_READ_CAPTURE_CYCLE_VAL1      /* NULL, Return Capture Value 1. (SMxCAPTVAL1->_) */
#define EFPWMS_READ_CAPTURE_CYCLE_VAL2      /* NULL, Return Capture Value 2. (SMxCAPTVAL2->_) */
#define EFPWMS_READ_CAPTURE_CYCLE_VAL3      /* NULL, Return Capture Value 3. (SMxCAPTVAL3->_) */
#define EFPWMS_READ_CAPTURE_CYCLE_VAL4      /* NULL, Return Capture Value 4. (SMxCAPTVAL4->_) */
#define EFPWMS_READ_CAPTURE_CYCLE_VAL5      /* NULL, Return Capture Value 5. (SMxCAPTVAL5->_) */

/* Common PWM registers */
#define EFPWM_SET_OUTPUTS_ENABLE           /* EFPWM_SUB0_PWM_X (A|B|X)|EFPWM_SUB1_PWM_X (A|B|X)|EFPWM_SUB2_PWM_X (A|B|X)|EFPWM_SUB3_PWM_X (A|B|X), Enable selected PWM outputs at selected submodules. (OUTEN->UPDATE_MASK) */
#define EFPWM_SET_OUTPUTS_DISABLE          /* EFPWM_SUB0_PWM_X (A|B|X)|EFPWM_SUB1_PWM_X (A|B|X)|EFPWM_SUB2_PWM_X (A|B|X)|EFPWM_SUB3_PWM_X (A|B|X), Disable selected PWM outputs at selected submodules. (OUTEN->PWMA_EN,PWMB_EN,PWMX_EN) */
#define EFPWM_SET_OUTPUTS                  /* EFPWM_SUB0_PWM_X_ENABLE (A|B|X)|EFPWM_SUB0_PWM_X_DISABLE (A|B|X)|EFPWM_SUB1_PWM_X_ENABLE (A|B|X)|EFPWM_SUB1_PWM_X_DISABLE (A|B|X)|EFPWM_SUB2_PWM_X_ENABLE (A|B|X)|EFPWM_SUB2_PWM_X_DISABLE (A|B|X)|EFPWM_SUB3_PWM_X_ENABLE (A|B|X)|EFPWM_SUB3_PWM_X_ENABLE (A|B|X)|, Enable/disable selected PWM outputs at selected submodules. (OUTEN->PWMA_EN,PWMB_EN,PWMX_EN) */

#define EFPWM_WRITE_OUTPUT_ENABLE_REG      /* UWord16, Writes prepared data in to the Output Enable Register. (OUTEN->_) */
#define EFPWM_READ_OUTPUT_ENABLE_REG       /* NULL, Return value of the Output Enable Register. (OUTEN->_) */

#define EFPWM_UPDATE_MASK_BITS_IMMEDIATELY /* EFPWM_MASK_UPDATE_MASK_SUB0|EFPWM_MASK_UPDATE_MASK_SUB1|EFPWM_MASK_UPDATE_MASK_SUB2|EFPWM_MASK_UPDATE_MASK_SUB3, Updates masked bits immediately. (MASK->OUTEN,MASKB,MASKX) */

#define EFPWM_SET_MASK_ENABLE              /* EFPWM_SUB0_PWM_X (A|B|X)|EFPWM_SUB1_PWM_X (A|B|X)|EFPWM_SUB2_PWM_X (A|B|X)|EFPWM_SUB3_PWM_X (A|B|X), Masks selected PWM outputs. (MASK->MASKA,MASKB,MASKX) */
#define EFPWM_SET_MASK_DISABLE             /* EFPWM_SUB0_PWM_X (A|B|X)|EFPWM_SUB1_PWM_X (A|B|X)|EFPWM_SUB2_PWM_X (A|B|X)|EFPWM_SUB3_PWM_X (A|B|X), Set normal PWM outputs. (MASK->MASKA,MASKB,MASKX) */
#define EFPWM_WRITE_MASK_REG               /* UWord16, Writes prepared data in to the Mask Register. (MASK->_) */
#define EFPWM_READ_MASK_REG                /* NULL, Return value of the Mask Register. (MASK->_) */

#define EFPWM_SET_FORCE_OUT_SW_SOURCE_TO_HIGH /* EFPWM_SUB0_PWMXX (23|45)|EFPWM_SUB1_PWMXX (23|45)| EFPWM_SUB2_PWMXX (23|45)|EFPWM_SUB3_PWMXX (23|45), Set Force Out software level to high. (SWCOUT->SWxOUTxx)  */
#define EFPWM_SET_FORCE_OUT_SW_SOURCE_TO_LOW  /* EFPWM_SUB0_PWMXX (23|45)| EFPWM_SUB1_PWMXX (23|45)|EFPWM_SUB2_PWMXX (23|45)|EFPWM_SUB3_PWMXX (23|45), Set Force Out software level to high. (SWCOUT->SWxOUTxx)  */
#define EFPWM_WRITE_SW_CONTROL_OUT_REG     /* UWord16, Writes prepared data in to the Software Controlled Output Register. (SWCOUT->_) */
#define EFPWM_READ_SW_CONTROL_OUT_REG      /* NULL, Return value of the Software Controlled Output Register. (SWCOUT->_) */

#define	EFPWM_SET_FORCE_OUT                /* EFPWM_SUB3_PWM23_SOURCE_xxx(PWM/ INV_PWM/ SWOUT/ EXT)|EFPWM_SUB3_PWM45_SOURCE_xxx(PWM/ INV_PWM/ SWOUT/ EXT)|EFPWM_SUB2_PWM23_SOURCE_xxx(PWM/ INV_PWM/ SWOUT/ EXT)|EFPWM_SUB2_PWM45_SOURCE_xxx(PWM/ INV_PWM/ SWOUT/ EXT)|EFPWM_SUB1_PWM23_SOURCE_xxx(PWM/ INV_PWM/ SWOUT/ EXT)|EFPWM_SUB1_PWM45_SOURCE_xxx(PWM/ INV_PWM/ SWOUT/ EXT)|EFPWM_SUB0_PWM23_SOURCE_xxx(PWM/ INV_PWM/ SWOUT/ EXT)|EFPWM_SUB0_PWM45_SOURCE_xxx(PWM/ INV_PWM/ SWOUT/ EXT), Set Force Out mode.(DTSRCSEL->SWxSELxx) */
#define EFPWM_WRITE_DEADTIME_SOURCE_REG    /* UWord16, Writes prepared data in to the Deadtime Source Select Register. (DTSRCSEL->_) */
#define EFPWM_READ_DEADTIME_SOURCE_REG     /* NULL, Return value of the Deadtime Source Select Register. (DTSRCSEL->_) */

#define EFPWM_SET_CURRENT_POLARITY_TO_PWM23 /* EFPWM_SUBMODULE_0|EFPWM_SUBMODULE_1|EFPWM_SUBMODULE_2|EFPWM_SUBMODULE_3, Set PWM23 output as PWM source in complemetary mode. (MCTRL->IPOL) */
#define EFPWM_SET_CURRENT_POLARITY_TO_PWM45 /* EFPWM_SUBMODULE_0|EFPWM_SUBMODULE_1|EFPWM_SUBMODULE_2|EFPWM_SUBMODULE_3, Set PWM45 output as PWM source in complemetary mode. (MCTRL->IPOL) */
#define EFPWM_SET_PWM_CLOCK_ENABLE         /* EFPWM_SUBMODULE_0|EFPWM_SUBMODULE_1|EFPWM_SUBMODULE_2|EFPWM_SUBMODULE_3, Set PWM generator clock enable. (MCTRL->RUN) */
#define EFPWM_SET_PWM_CLOCK_DISABLE        /* EFPWM_SUBMODULE_0|EFPWM_SUBMODULE_1|EFPWM_SUBMODULE_2|EFPWM_SUBMODULE_3, Set PWM generator clock disable. (MCTRL->RUN) */
#define EFPWM_CLEAR_LOAD_OK                /* EFPWM_SUBMODULE_0|EFPWM_SUBMODULE_1|EFPWM_SUBMODULE_2|EFPWM_SUBMODULE_3, Clear selected LDOK request. (MCTRL->CLDOK) */
#define EFPWM_SET_LOAD_OK                  /* EFPWM_SUBMODULE_0|EFPWM_SUBMODULE_1|EFPWM_SUBMODULE_2|EFPWM_SUBMODULE_3, Set selected LDOK request. (MCTRL->LDOK) */
#define EFPWM_WRITE_MASTER_CONTROL_REG     /* UWord16, Writes prepared data to the Master Control Register. (MCTRL->_) */
#define EFPWM_READ_MASTER_CONTROL_REG      /* NULL, Return value of the Master Control Register. (MCTRL->_) */

#define EFPWM_SET_ACTIVE_HIGH_FAULTS       /* EFPWM_FAULT_X(0|1|2|3), Set active fault level to high at selected fault inputs. (FCTRL->FLVL) */
#define EFPWM_SET_ACTIVE_LOW_FAULTS        /* EFPWM_FAULT_X(0|1|2|3), Set active fault level to low at selected fault inputs. (FCTRL->FLVL) */
#define EFPWM_SET_AUTOMATIC_FAULT_CLEAR    /* EFPWM_FAULT_X(0|1|2|3), Set automatic fault clearing. (FCTRL->FAUTO) */
#define EFPWM_SET_MANUAL_FAULT_CLEAR       /* EFPWM_FAULT_X(0|1|2|3), Set manual fault clearing. (FCTRL->FAUTO) */
#define EFPWM_SET_FAULT_SAFETY_MODE        /* EFPWM_FAULT_X(0|1|2|3), Set fault safety mode. (FCTRL->FSAFE) */
#define EFPWM_SET_FAULT_NORMAL_MODE        /* EFPWM_FAULT_X(0|1|2|3), Set fault normal mode. (FCTRL->FSAFE) */
#define EFPWM_FAULT_INT_ENABLE             /* EFPWM_FAULT_X(0|1|2|3), Enable fault interrupt. (FCTRL->FIE) */
#define EFPWM_FAULT_INT_DISABLE            /* EFPWM_FAULT_X(0|1|2|3), Disable fault interrupt. (FCTRL->FIE) */
#define EFPWM_WRITE_FAULT_CONTROL_REG      /* UWord16, Writes prepared data in to the Fault Register. (FCTRL->_) */
#define EFPWM_READ_FAULT_CONTROL_REG       /* NULL, Return value of the Fault Register. (FCTRL->_) */

#if EFPWM_VERSION >= 2
#define EFPWM_SET_ACTIVE_HIGH_FAULTS0      /* EFPWM_FAULT_X(0|1|2|3), Set active fault level to high at selected fault inputs. (FCTRL->FLVL) */
#define EFPWM_SET_ACTIVE_LOW_FAULTS0       /* EFPWM_FAULT_X(0|1|2|3), Set active fault level to low at selected fault inputs. (FCTRL->FLVL) */
#define EFPWM_SET_AUTOMATIC_FAULT0_CLEAR   /* EFPWM_FAULT_X(0|1|2|3), Set automatic fault clearing. (FCTRL->FAUTO) */
#define EFPWM_SET_MANUAL_FAULT0_CLEAR      /* EFPWM_FAULT_X(0|1|2|3), Set manual fault clearing. (FCTRL->FAUTO) */
#define EFPWM_SET_FAULT0_SAFETY_MODE       /* EFPWM_FAULT_X(0|1|2|3), Set fault safety mode. (FCTRL->FSAFE) */
#define EFPWM_SET_FAULT0_NORMAL_MODE       /* EFPWM_FAULT_X(0|1|2|3), Set fault normal mode. (FCTRL->FSAFE) */
#define EFPWM_FAULT0_INT_ENABLE            /* EFPWM_FAULT_X(0|1|2|3), Enable fault interrupt. (FCTRL->FIE) */
#define EFPWM_FAULT0_INT_DISABLE           /* EFPWM_FAULT_X(0|1|2|3), Disable fault interrupt. (FCTRL->FIE) */
#define EFPWM_WRITE_FAULT0_CONTROL_REG     /* UWord16, Writes prepared data in to the Fault Register. (FCTRL->_) */
#define EFPWM_READ_FAULT0_CONTROL_REG      /* NULL, Return value of the Fault Register. (FCTRL->_) */

#define EFPWM_SET_ACTIVE_HIGH_FAULTS1      /* EFPWM_FAULT_X(0|1|2|3), Set active fault level to high at selected fault inputs.  (FCTRL->FLVL) */
#define EFPWM_SET_ACTIVE_LOW_FAULTS1       /* EFPWM_FAULT_X(0|1|2|3), Set active fault level to low at selected fault inputs.  (FCTRL->FLVL) */
#define EFPWM_SET_AUTOMATIC_FAULT1_CLEAR   /* EFPWM_FAULT_X(0|1|2|3), Set automatic fault clearing. (FCTRL->FAUTO) */
#define EFPWM_SET_MANUAL_FAULT1_CLEAR      /* EFPWM_FAULT_X(0|1|2|3), Set manual fault clearing. (FCTRL->FAUTO) */
#define EFPWM_SET_FAULT1_SAFETY_MODE       /* EFPWM_FAULT_X(0|1|2|3), Set fault safety mode. (FCTRL->FSAFE) */
#define EFPWM_SET_FAULT1_NORMAL_MODE       /* EFPWM_FAULT_X(0|1|2|3), Set fault normal mode. (FCTRL->FSAFE) */
#define EFPWM_FAULT1_INT_ENABLE            /* EFPWM_FAULT_X(0|1|2|3), Enable fault interrupt. (FCTRL->FIE) */
#define EFPWM_FAULT1_INT_DISABLE           /* EFPWM_FAULT_X(0|1|2|3), Disable fault interrupt. (FCTRL->FIE) */
#define EFPWM_WRITE_FAULT1_CONTROL_REG     /* UWord16, Writes prepared data in to the Fault Register. (FCTRL->_) */
#define EFPWM_READ_FAULT1_CONTROL_REG      /* NULL, Return value of the Fault Register. (FCTRL->_) */
#endif

#define EFPWM_CLEAR_FAULT_TEST             /* NULL, Clear simulated fault condition. (FSTS->FTEST) */
#define EFPWM_TEST_FAULT_PINS              /* EFPWM_FAULT_X(0|1|2|3), Return state of filtered fault pins. (FSTS->FFPIN) */
#define EFPWM_TEST_FAULT_FLAGS             /* EFPWM_FAULT_X(0|1|2|3), Return state of selected fault flags. (FSTS->FFLAG) */
#define EFPWM_CLEAR_FAULT_FLAGS            /* EFPWM_FAULT_X(0|1|2|3), Clear selected fault flags. (FSTS->FFLAG) */
#define EFPWM_WRITE_FAULT_STATUS_REG       /* UWord16, Writes prepared data in to the Fault Status Register. (FSTS->_) */
#define EFPWM_READ_FAULT_STATUS_REG        /* NULL, Return value of the Fault Status Register. (FSTS->_) */

#define EFPWM_FAULT_GLITCH_STRETCH         /* EFPWM_ENABLE/EFPWM_DISABLE, enable/disable Fault glitch stretching. (FFILT->GSTR) */

#if EFPWM_VERSION >= 2
#define EFPWM_CLEAR_FAULT0_TEST            /* NULL, Clear simulated fault condition. (FSTS->FTEST) */
#define EFPWM_TEST_FAULT0_PINS             /* EFPWM_FAULT_X(0|1|2|3), Return state of filtered fault pins. (FSTS->FFPIN) */
#define EFPWM_TEST_FAULT0_FLAGS            /* EFPWM_FAULT_X(0|1|2|3), Return state of selected fault flags. (FSTS->FFLAG) */
#define EFPWM_CLEAR_FAULT0_FLAGS           /* EFPWM_FAULT_X(0|1|2|3), Clear selected fault flags. (FSTS->FFLAG) */
#define EFPWM_WRITE_FAULT0_STATUS_REG      /* UWord16, Writes prepared data in to the Fault Status Register. (FSTS->_) */
#define EFPWM_READ_FAULT0_STATUS_REG       /* NULL, Return value of the Fault Status Register. (FSTS->_) */

#define EFPWM_FAULT0_GLITCH_STRETCH        /* EFPWM_ENABLE/EFPWM_DISABLE, enable/disable Fault glitch stretching. (FFILT->GSTR) */

#define EFPWM_CLEAR_FAULT1_TEST            /* NULL, Clear simulated fault condition. (FSTS->FTEST) */
#define EFPWM_TEST_FAULT1_PINS             /* EFPWM_FAULT_X(0|1|2|3), Return state of filtered fault pins. (FSTS->FFPIN) */
#define EFPWM_TEST_FAULT1_FLAGS            /* EFPWM_FAULT_X(0|1|2|3), Return state of selected fault flags. (FSTS->FFLAG) */
#define EFPWM_CLEAR_FAULT1_FLAGS           /* EFPWM_FAULT_X(0|1|2|3), Clear selected fault flags. (FSTS->FFLAG) */
#define EFPWM_WRITE_FAULT1_STATUS_REG      /* UWord16, Writes prepared data in to the Fault Status Register. (FSTS->_) */
#define EFPWM_READ_FAULT1_STATUS_REG       /* NULL, Return value of the Fault Status Register. (FSTS->_) */

#define EFPWM_FAULT1_GLITCH_STRETCH        /* EFPWM_ENABLE/EFPWM_DISABLE, enable/disable Fault glitch stretching. (FFILT->GSTR) */
#endif


/*****************************************************************
* Multi-Instruction ioctl() commands
*
*  Word16 ioctl( PWM_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                             PARAMETERS, COMMENTS
------------------------------------------------------------------ */

/* Submodule commands */

#define EFPWMS_SET_RELOAD_FREQUENCY         /* EFPWM_RELOAD_OPPORTUNITY_X(1 to 16), set reload period. (SMxCTRL->LDFQ) */
#define EFPWMS_SET_PRESCALER                /* EFPWM_PRESCALER_DIV_X (1/2/4/8/16/32/64/128), set reload PWM submodule prescaler. (SMxCTRL->PRSC) */

#define EFPWMS_SET_SYNC_SOURCE              /* EFPWM_XXX (LOCAL_SYNC/MASTER_RELOAD/MASTER_SYNC/EXT_SYNC), set reload PWM sync source. (SMxCTRL2->INIT_SEL) */
#define EFPWMS_SET_FORCE_INIT_SOURCE        /* EFPWM_FORCE_XXX (LOCAL_FORCE/MASTER_FORCE/LOCAL_RELOAD/MASTER_RELOAD/LOCAL_SYNC/MASTER_SYNC/EXT_SYNC), select force initialization source. (SMxCTRL2->FORCE_SEL) */
#define EFPWMS_SET_CLOCK_SOURCE             /* EFPWM_XXX_CLOCK (IPBUS/EXT/SUB0), set reload PWM clock source. (SMxCTRL2->CLK_SEL) */

#define EFPWMS_SET_PWM_FAULT_STATEOUT_A     /* EFPWM_XXX (LOG_0/LOG_1/TRISTATED), Set level of output pin PWMA during fault state. (SMxOCTRL->PWMAFS) */
#define EFPWMS_SET_PWM_FAULT_STATEOUT_B     /* EFPWM_XXX (LOG_0/LOG_1/TRISTATED), Set level of output pin PWMB during fault state. (SMxOCTRL->PWMBFS) */
#define EFPWMS_SET_PWM_FAULT_STATEOUT_X     /* EFPWM_XXX (LOG_0/LOG_1/TRISTATED), Set level of output pin PWMX during fault state. (SMxOCTRL->PWMXFS) */

/* Submodule with capture logic */
/* capture A */
#define EFPWMS_READ_CAPTURE_A1_FIFO_COUNT   /* NULL, Return value of FIFO counter. (SMxCAPTCTRLA->CA1CNT) */
#define EFPWMS_READ_CAPTURE_A0_FIFO_COUNT   /* NULL, Return value of FIFO counter. (SMxCAPTCTRLA->CA0CNT) */
#define EFPWMS_SET_CAPTURE_A_FIFO_WATERMARK /* UWord16, value 0 to 3 (in 824x5x value 0 to 1 ). (SMxCAPTCTRLA->CFAWM) */
#define EFPWMS_SET_CAPTURE_A_1              /* EFPWM_CAPTURE_1_XXX (DISABLE/FALLING_EDGE/RISING_EDGE/ANY_EDGE), Set input capture  A 1 edge sensitivity. (SMxCAPTCTRLA->EDGA1) */
#define EFPWMS_SET_CAPTURE_A_0              /* EFPWM_CAPTURE_0_XXX (DISABLE/FALLING_EDGE/RISING_EDGE/ANY_EDGE), Set input capture  A 0 edge sensitivity. (SMxCAPTCTRLA->EDGA0) */

#define EFPWMS_SET_COMPARE_A                /* UWord16, Set Edge Compare A value, value 0 to 255. (SMxCAPTCOMPA->EDGCMPA) */
#define EFPWMS_READ_EDGE_COUNTER_A          /* NULL, Return Edge counter value. (SMxCAPTCOMPA->EDGCNTA) */

/* capture B */
#define EFPWMS_READ_CAPTURE_B1_FIFO_COUNT   /* NULL, Return value of FIFO counter. (SMxCAPTCTRLB->CB1CNT) */
#define EFPWMS_READ_CAPTURE_B0_FIFO_COUNT   /* NULL, Return value of FIFO counter. (SMxCAPTCTRLB->CB0CNT) */
#define EFPWMS_SET_CAPTURE_B_FIFO_WATERMARK /* UWord16, value 0 to 3 (in 824x5x value 0 to 1 ). (SMxCAPTCTRLB->CFBWM) */
#define EFPWMS_SET_CAPTURE_B_1              /* EFPWM_CAPTURE_1_XXX (DISABLE/FALLING_EDGE/RISING_EDGE/ANY_EDGE), Set input capture  B 1 edge sensitivity. (SMxCAPTCTRLB->EDGB1) */
#define EFPWMS_SET_CAPTURE_B_0              /* EFPWM_CAPTURE_0_XXX (DISABLE/FALLING_EDGE/RISING_EDGE/ANY_EDGE), Set input capture  B 0 edge sensitivity.(SMxCAPTCTRLB->EDGB0) */

#define EFPWMS_SET_COMPARE_B                /* UWord16, Edge Compare B value, value 0 to 255 (SMxCAPTCOMPB->EDGCNTB) */
#define EFPWMS_READ_EDGE_COUNTER_B          /* NULL, Return Edge counter value (SMxCAPTCOMPB->EDGCNTB) */

/* capture X */
#define EFPWMS_READ_CAPTURE_X1_FIFO_COUNT   /* NULL, Return value of FIFO counter. (SMxCAPTCTRLX->CX1CNT) */
#define EFPWMS_READ_CAPTURE_X0_FIFO_COUNT   /* NULL, Return value of FIFO counter. (SMxCAPTCTRLX->CX0CNT) */
#define EFPWMS_SET_CAPTURE_X_FIFO_WATERMARK /* UWord16, value 0 to 3 (in 824x5x value 0 to 1 ). (SMxCAPTCTRLX->CFXWM) */
#define EFPWMS_SET_CAPTURE_X_1              /* EFPWM_CAPTURE_1_XXX (DISABLE/FALLING_EDGE/RISING_EDGE/ANY_EDGE), Set input capture  X 1 edge sensitivity. (SMxCAPTCTRLX->EDGX1) */
#define EFPWMS_SET_CAPTURE_X_0              /* EFPWM_CAPTURE_0_XXX (DISABLE/FALLING_EDGE/RISING_EDGE/ANY_EDGE), Set input capture  X 0 edge sensitivity. (SMxCAPTCTRLX->EDGX0) */

#define EFPWMS_SET_COMPARE_X                /* UWord16, Edge Compare X value, value 0 to 255. (SMxCAPTCOMPX->EDGCNTX) */
#define EFPWMS_READ_EDGE_COUNTER_X          /* NULL, Return Edge counter value. (SMxCAPTCOMPX->EDGCNTX) */

/* Common PWM registers */
#define EFPWM_SET_SUB3_FORCE_OUT_PWM23     /* EFPWM_SOURCE_XXX (PWM/INV_PWM/SWOUT/EXT), Set force out source. (DTSRCSEL->SM3SEL23) */
#define EFPWM_SET_SUB3_FORCE_OUT_PWM45     /* EFPWM_SOURCE_XXX (PWM/INV_PWM/SWOUT/EXT), Set force out source. (DTSRCSEL->SM3SEL45) */
#define EFPWM_SET_SUB2_FORCE_OUT_PWM23     /* EFPWM_SOURCE_XXX (PWM/INV_PWM/SWOUT/EXT), Set force out source. (DTSRCSEL->SM2SEL23) */
#define EFPWM_SET_SUB2_FORCE_OUT_PWM45     /* EFPWM_SOURCE_XXX (PWM/INV_PWM/SWOUT/EXT), Set force out source. (DTSRCSEL->SM2SEL45) */
#define EFPWM_SET_SUB1_FORCE_OUT_PWM23     /* EFPWM_SOURCE_XXX (PWM/INV_PWM/SWOUT/EXT), Set force out source. (DTSRCSEL->SM1SEL23) */
#define EFPWM_SET_SUB1_FORCE_OUT_PWM45     /* EFPWM_SOURCE_XXX (PWM/INV_PWM/SWOUT/EXT), Set force out source. (DTSRCSEL->SM1SEL45) */
#define EFPWM_SET_SUB0_FORCE_OUT_PWM23     /* EFPWM_SOURCE_XXX (PWM/INV_PWM/SWOUT/EXT), Set force out source. (DTSRCSEL->SM0SEL23) */
#define EFPWM_SET_SUB0_FORCE_OUT_PWM45     /* EFPWM_SOURCE_XXX (PWM/INV_PWM/SWOUT/EXT), Set force out source. (DTSRCSEL->SM0SEL45) */

#define EFPWM_MONITOR_PLL                  /* EFPWM_ENABLE(_PERMANENT)/EFPWM_DISABLE(_PERMANENT), Enable/disable PLL monitor. (MCTRL2->MONPLL) */

#define EFPWM_SET_FAULT_FULL_CYCLE         /* EFPWM_FAULT_X(0|1|2|3), Set re-enabling PWM outputs at start of a full cycle. (FSTS->FFULL) */
#define EFPWM_SET_FAULT_HALF_FULL_CYCLE    /* EFPWM_FAULT_X(0|1|2|3), Set re-enabling PWM outputs at start of a half or full cycle. (FSTS->FFULL) */

#define EFPWM_FAULT_FILTER_COUNTER         /* EFPWM_SAMPLES_X (3/4/5/6/7/8/9/10), Set number of samples to the input filter accepting an input transition. (FFILT->FILT_CNT) */
#define EFPWM_FAULT_FILTER_PERIOD          /* UWord16, Value 0 to 255 (FFILT->FILT_PER) */

#if EFPWM_VERSION >= 2

#define EFPWM_SET_FAULT0_FULL_CYCLE         /* EFPWM_FAULT_X(0|1|2|3), Set re-enabling PWM outputs at start of a full cycle. (FSTS->FFULL) */
#define EFPWM_SET_FAULT0_HALF_FULL_CYCLE    /* EFPWM_FAULT_X(0|1|2|3), Set re-enabling PWM outputs at start of a half or full cycle. (FSTS->FFULL) */

#define EFPWM_FAULT0_FILTER_COUNTER         /* EFPWM_SAMPLES_X (3/4/5/6/7/8/9/10), Set number of samples to the input filter accepting an input transition. (FFILT->FILT_CNT) */
#define EFPWM_FAULT0_FILTER_PERIOD          /* UWord16, Value 0 to 255. (FFILT->FILT_PER) */

#define EFPWM_SET_FAULT1_FULL_CYCLE        /* EFPWM_FAULT_X(0|1|2|3), Set re-enabling PWM outputs at start of a full cycle. (FSTS->FFULL) */
#define EFPWM_SET_FAULT1_HALF_FULL_CYCLE    /* EFPWM_FAULT_X(0|1|2|3), Set re-enabling PWM outputs at start of a half or full cycle. (FSTS->FFULL) */

#define EFPWM_FAULT1_FILTER_COUNTER         /* EFPWM_SAMPLES_X (3/4/5/6/7/8/9/10), Set number of samples to the input filter accepting an input transition. (FFILT->FILT_CNT) */
#define EFPWM_FAULT1_FILTER_PERIOD          /* UWord16, Value 0 to 255. (FFILT->FILT_PER) */

#define EFPWM_FAULT0_TEST                  /* EFPWM_ENABLE/EFPWM_DISABLE, Activates simulated fault condition for fault 0. Simulated fault to be sent into all of the fault filters. (FTST0->FTEST[0]) */
#define EFPWM_FAULT1_TEST                  /* EFPWM_ENABLE/EFPWM_DISABLE, Activates simulated fault condition for fault 1. Simulated fault to be sent into all of the fault filters. (FTST1->FTEST[0]) */

#endif

/*****************************************************************
* Software Layer ioctl() commands
*
*  Word16 ioctl( PWM_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                             PARAMETERS, COMMENTS
------------------------------------------------------------------ */

#define EFPWM_INIT                         			/* NULL, Initialization of the periheral registers using appconfig.h _INIT values */

#define EFPWMS_SET_CENTER_ALIGN_MODULO_INIT_REG 	/* UWord16, range 0 to 2^16-2, writes modulo value in to Var1 register and Init register to prepare generating Center Align output signal. (INIT->_,SMVAL1->_) */

#define EFPWMS_CENTER_ALIGN_WRITE_CHANNEL_23   		/* UWord16, range 0 to 32767, Set Value2 and Value3 registers to generate center align output signal. (SMVAL2->_,SMVAL3->_) */
#define EFPWMS_CENTER_ALIGN_WRITE_CHANNEL_45   		/* UWord16, range 0 to 32767, Set Value4 and Value5 registers to generate center align output signal. (SMVAL4->_,SMVAL5->_) */

#define EFPWMS_CENTER_ALIGN_UPDATE_CHANNEL_23  		/* Word16 in Signed Fractional representation, range 0 to 1, Set Value2 and Value3 registers. (SMVAL2->_,SMVAL3->_) */
#define EFPWMS_CENTER_ALIGN_UPDATE_CHANNEL_45  		/* Word16 in Signed Fractional representation, range 0 to 1, Set Value4 and Value5 registers. (SMVAL4->_,SMVAL5->_) */

#define EFPWMS_CENTER_ALIGN_UPDATE_CHANNEL_23_FRAC  /* Word16 in Signed Fractional representation, range 0 to 1, Modulo register can be maximally 1024, Set Value2, Fractional2, Value3 and Fractional3 registers. (SMVAL2->_,FRACVAL2->_,SMVAL3->_,FRACVAL3->_) */
#define EFPWMS_CENTER_ALIGN_UPDATE_CHANNEL_45_FRAC  /* Word16 in Signed Fractional representation, range 0 to 1, Modulo register can be maximally 1024, Set Value2, Fractional2, Value3 and Fractional3 registers. (SMVAL4->_,FRACVAL4->_,SMVAL5->_,FRACVAL5->_) */

#define EFPWM_CENTER_ALIGN_UPDATE_VALUE_REGS_COMPL_012  /* pwm_sComplementaryValues*, Set PWM Submodule 0, 1 and 2 outputs in complementary mode and set LDOK bit afterwards. (SM0VAL1->_,SM0VAL2->_,SM0VAL3->_,SM1VAL2->_,SM1VAL3->_,SM2VAL2->_,SM2VAL3->_,MCTRL->LDOK) */
#define EFPWM_CENTER_ALIGN_UPDATE_VALUE_REGS_COMPL_013  /* pwm_sComplementaryValues*, Set PWM Submodule 0, 1 and 3 outputs in complementary mode and set LDOK bit afterwards. (SM0VAL1->_,SM0VAL2->_,SM0VAL3->_,SM1VAL2->_,SM1VAL3->_,SM2VAL2->_,SM2VAL3->_,MCTRL->LDOK) */
#define EFPWM_CENTER_ALIGN_UPDATE_VALUE_REGS_COMPL_023  /* pwm_sComplementaryValues*, Set PWM Submodule 0, 2 and 3 outputs in complementary mode and set LDOK bit afterwards. (SM0VAL1->_,SM0VAL2->_,SM0VAL3->_,SM1VAL2->_,SM1VAL3->_,SM2VAL2->_,SM2VAL3->_,MCTRL->LDOK) */

#define EFPWMS_SET_EDGE_ALIGN_MODULO_INIT_REG 		/* UWord16, range 0 to 32767, writes modulo value in to Var1 register and Init register to prepare generating Edge Align output signal. (INIT->_,SMVAL1->_) */

#define EFPWMS_EDGE_ALIGN_WRITE_CHANNEL_23   		/* UWord16, range 0 to 32767, Set Value2 and Value3 registers to generate edge align output signal. (SMVAL2->_,SMVAL3->_)  */
#define EFPWMS_EDGE_ALIGN_WRITE_CHANNEL_45   		/* UWord16, range 0 to 32767, Set Value4 and Value5 registers to generate edge align output signal. (SMVAL4->_,SMVAL5->_)  */

#define EFPWMS_EDGE_ALIGN_UPDATE_CHANNEL_23  		/* Word16 in Signed Fractional representation, range 0 to 1, Set Value2 and Value3 registers. (SMVAL2->_,SMVAL3->_) */
#define EFPWMS_EDGE_ALIGN_UPDATE_CHANNEL_45  		/* Word16 in Signed Fractional representation, range 0 to 1, Set Value2 and Value3 registers. (SMVAL4->_,SMVAL5->_) */

#define EFPWMS_EDGE_ALIGN_UPDATE_CHANNEL_23_FRAC  	/* Word16 in Signed Fractional representation, range 0 to 1, Modulo register can be maximaly 1024, Set Value2, Fractional2, Value3 and Fractional3 registers. (SMVAL2->_,FRACVAL2->_,SMVAL3->_,FRACVAL3->_) */
#define EFPWMS_EDGE_ALIGN_UPDATE_CHANNEL_45_FRAC  	/* Word16 in Signed Fractional representation, range 0 to 1, Modulo register can be maximaly 1024, Set Value4, Fractional4, Value5 and Fractional5 registers. (SMVAL4->_,FRACVAL4->_,SMVAL5->_,FRACVAL5->_) */

#define EFPWM_EDGE_ALIGN_UPDATE_VALUE_REGS_INDEP_012	/* pwm_sIndependentValues*, Set PWM Submodule 0, 1 and 2 outputs in indemendent mode and set LDOK bit afterwards. (SM0VAL1->_,SM0VAL2->_,SM0VAL3->_,SM0VAL4->_,SM0VAL5->_,SM1VAL2->_,SM1VAL3->_,SM1VAL4->_,SM1VAL5->_,SM2VAL2->_,SM2VAL3->_,SM2VAL4->_,SM2VAL5->_,MCTRL->LDOK) */
#define EFPWM_EDGE_ALIGN_UPDATE_VALUE_REGS_INDEP_013	/* pwm_sIndependentValues*, Set PWM Submodule 0, 1 and 3 outputs in indemendent mode and set LDOK bit afterwards. (SM0VAL1->_,SM0VAL2->_,SM0VAL3->_,SM0VAL4->_,SM0VAL5->_,SM1VAL2->_,SM1VAL3->_,SM1VAL4->_,SM1VAL5->_,SM2VAL2->_,SM2VAL3->_,SM2VAL4->_,SM2VAL5->_,MCTRL->LDOK) */
#define EFPWM_EDGE_ALIGN_UPDATE_VALUE_REGS_INDEP_023	/* pwm_sIndependentValues*, Set PWM Submodule 0, 1 and 3 outputs in indemendent mode and set LDOK bit afterwards. (SM0VAL1->_,SM0VAL2->_,SM0VAL3->_,SM0VAL4->_,SM0VAL5->_,SM1VAL2->_,SM1VAL3->_,SM1VAL4->_,SM1VAL5->_,SM2VAL2->_,SM2VAL3->_,SM2VAL4->_,SM2VAL5->_,MCTRL->LDOK) */


/****************************************************************************
* EFPWM constants and type declarations use in the ioctl functions
*****************************************************************************/

#define EFPWM_ENABLE                     1
#define EFPWM_DISABLE                    0

#define EFPWM_STOP                       0
#define EFPWM_RUN                        1


#define EFPWM_CHANNEL_23                 0x0004
#define EFPWM_CHANNEL_45                 0x0002
#define EFPWM_CHANNEL_X                  0x0001
#define EFPWM_ZERO_MASK                  0x0000

#define EFPWM_OUTPUT_A                   0x0004
#define EFPWM_OUTPUT_B                   0x0002
#define EFPWM_OUTPUT_X                   0x0001

#define EFPWM_INPUT_A                    0x0004
#define EFPWM_INPUT_B                    0x0002
#define EFPWM_INPUT_X                    0x0001


#define EFPWM_IPOL_SUB0                  EFPWM_MCTRL_IPOL_SUB0
#define EFPWM_IPOL_SUB1                  EFPWM_MCTRL_IPOL_SUB1
#define EFPWM_IPOL_SUB2                  EFPWM_MCTRL_IPOL_SUB2
#define EFPWM_IPOL_SUB3                  EFPWM_MCTRL_IPOL_SUB3

#define EFPWM_RELOAD_OPPORTUNITY_1       0
#define EFPWM_RELOAD_OPPORTUNITY_2       1
#define EFPWM_RELOAD_OPPORTUNITY_3       2
#define EFPWM_RELOAD_OPPORTUNITY_4       3
#define EFPWM_RELOAD_OPPORTUNITY_5       4
#define EFPWM_RELOAD_OPPORTUNITY_6       5
#define EFPWM_RELOAD_OPPORTUNITY_7       6
#define EFPWM_RELOAD_OPPORTUNITY_8       7
#define EFPWM_RELOAD_OPPORTUNITY_9       8
#define EFPWM_RELOAD_OPPORTUNITY_10      9
#define EFPWM_RELOAD_OPPORTUNITY_11      10
#define EFPWM_RELOAD_OPPORTUNITY_12      11
#define EFPWM_RELOAD_OPPORTUNITY_13      12
#define EFPWM_RELOAD_OPPORTUNITY_14      13
#define EFPWM_RELOAD_OPPORTUNITY_15      14
#define EFPWM_RELOAD_OPPORTUNITY_16      15

#define EFPWM_PRESCALER_DIV_1            0
#define EFPWM_PRESCALER_DIV_2            1
#define EFPWM_PRESCALER_DIV_4            2
#define EFPWM_PRESCALER_DIV_8            3
#define EFPWM_PRESCALER_DIV_16           4
#define EFPWM_PRESCALER_DIV_32           5
#define EFPWM_PRESCALER_DIV_64           6
#define EFPWM_PRESCALER_DIV_128          7

#define EFPWM_DEADTIME_0_BIT             EFPWM_CTRL_DT_DEADTIME0
#define EFPWM_DEADTIME_1_BIT             EFPWM_CTRL_DT_DEADTIME1

#define EFPWM_FRACTIONAL_DELAY_1         0z02
#define EFPWM_FRACTIONAL_DELAY_2         0z04
#define EFPWM_FRACTIONAL_DELAY_3         0x08
#define EFPWM_FRACTIONAL_DELAY_4         0x10
#define EFPWM_FRACTIONAL_DELAY_5         0x20

#if (EFPWM_HAS_FAULTS) & 1
#define EFPWM_FAULT_0                    0x1
#endif
#if (EFPWM_HAS_FAULTS) & 2
#define EFPWM_FAULT_1                    0x2
#endif
#if (EFPWM_HAS_FAULTS) & 4
#define EFPWM_FAULT_2                    0x4
#endif
#if (EFPWM_HAS_FAULTS) & 8
#define EFPWM_FAULT_3                    0x8
#endif

#define EFPWM_REGISTER_UPDATE            EFPWM_STS_RUF
#define EFPWM_RELOAD_ERROR               EFPWM_STS_REF
#define EFPWM_RELOAD                     EFPWM_STS_RF
#define EFPWM_CAPTURE_A1                 EFPWM_STS_CFA1
#define EFPWM_CAPTURE_A0                 EFPWM_STS_CFA0
#define EFPWM_CAPTURE_B1                 EFPWM_STS_CFB1
#define EFPWM_CAPTURE_B0                 EFPWM_STS_CFB0
#define EFPWM_CAPTURE_X1                 EFPWM_STS_CFX1
#define EFPWM_CAPTURE_X0                 EFPWM_STS_CFX0
#define EFPWM_COMPARE_VAL0               EFPWM_STS_CMPF_VAL0
#define EFPWM_COMPARE_VAL1               EFPWM_STS_CMPF_VAL1
#define EFPWM_COMPARE_VAL2               EFPWM_STS_CMPF_VAL2
#define EFPWM_COMPARE_VAL3               EFPWM_STS_CMPF_VAL3
#define EFPWM_COMPARE_VAL4               EFPWM_STS_CMPF_VAL4
#define EFPWM_COMPARE_VAL5               EFPWM_STS_CMPF_VAL5

#define EFPWM_LOAD_END_CYCLE              0
#define EFPWM_LOAD_IMMEDIATE              1

#define EFPWM_COMPLEMENTARY               0
#define EFPWM_INDEPENDENT                 1

#define EFPWM_LOCAL_SYNC                  EFPWM_CTRL2_INIT_SEL_LOCAL_SYNC
#define EFPWM_MASTER_RELOAD               EFPWM_CTRL2_INIT_SEL_MASTER_RELOAD
#define EFPWM_MASTER_SYNC                 EFPWM_CTRL2_INIT_SEL_MASTER_SYNC
#define EFPWM_EXT_SYNC                    EFPWM_CTRL2_INIT_SEL_EXT_SYNC


#define EFPWM_FORCE_LOCAL_FORCE           EFPWM_CTRL2_FORCE_SEL_LOCAL_FORCE
#define EFPWM_FORCE_MASTER_FORCE          EFPWM_CTRL2_FORCE_SEL_MASTER_FORCE
#define EFPWM_FORCE_LOCAL_RELOAD          EFPWM_CTRL2_FORCE_SEL_LOCAL_RELOAD
#define EFPWM_FORCE_MASTER_RELOAD         EFPWM_CTRL2_FORCE_SEL_MASTER_RELOAD
#define EFPWM_FORCE_LOCAL_SYNC            EFPWM_CTRL2_FORCE_SEL_LOCAL_SYNC
#define EFPWM_FORCE_MASTER_SYNC           EFPWM_CTRL2_FORCE_SEL_MASTER_SYNC
#define EFPWM_FORCE_EXT_SYNC              EFPWM_CTRL2_FORCE_SEL_EXT_SYNC

#define EFPWM_RELOAD_LOCAL                0
#define EFPWM_RELOAD_MASTER               1

#define EFPWM_IPBUS_CLOCK                 EFPWM_CTRL2_CLK_SEL_IPBUSCLOCK
#define EFPWM_EXT_CLOCK                   EFPWM_CTRL2_CLK_SEL_EXT_CLK
#define EFPWM_SUB0_CLOCK                  EFPWM_CTRL2_CLK_SEL_SUBMODUL0

#define EFPWM_FRAC_DELAY_1                EFPWM_FRCTRL_FRACX_EN_FRAC1
#define EFPWM_FRAC_DELAY_23               EFPWM_FRCTRL_FRACX_EN_FRAC23
#define EFPWM_FRAC_DELAY_45               EFPWM_FRCTRL_FRACX_EN_FRAC45
#define EFPWM_FRAC_DELAY_POWERUP          EFPWM_FRCTRL_FRACX_EN_PU

#define EFPWM_LOG_0                       0
#define EFPWM_LOG_1                       1
#define EFPWM_TRISTATED                   2

#define EFPWM_TRIG0_VAL0                  EFPWM_TCTRL_OUT_TRIG_EN_VAL0
#define EFPWM_TRIG1_VAL1                  EFPWM_TCTRL_OUT_TRIG_EN_VAL1
#define EFPWM_TRIG0_VAL2                  EFPWM_TCTRL_OUT_TRIG_EN_VAL2
#define EFPWM_TRIG1_VAL3                  EFPWM_TCTRL_OUT_TRIG_EN_VAL3
#define EFPWM_TRIG0_VAL4                  EFPWM_TCTRL_OUT_TRIG_EN_VAL4
#define EFPWM_TRIG1_VAL5                  EFPWM_TCTRL_OUT_TRIG_EN_VAL5

#define EFPWM_RAW_INPUT                   0
#define EFPWM_EDGE_COUNTER                1

#define EFPWM_CAPTURE_1_DISABLE           EFPWM_CAPTCTRLx_EDGx1_DISABLE
#define EFPWM_CAPTURE_1_FALLING_EDGE      EFPWM_CAPTCTRLx_EDGx1_FALLING_EDGE
#define EFPWM_CAPTURE_1_RISING_EDGE       EFPWM_CAPTCTRLx_EDGx1_RISING_EDGE
#define EFPWM_CAPTURE_1_ANY_EDGE          EFPWM_CAPTCTRLx_EDGx1_ANY_EDGE
#define EFPWM_CAPTURE_0_DISABLE           EFPWM_CAPTCTRLx_EDGx0_DISABLE
#define EFPWM_CAPTURE_0_FALLING_EDGE      EFPWM_CAPTCTRLx_EDGx0_FALLING_EDGE
#define EFPWM_CAPTURE_0_RISING_EDGE       EFPWM_CAPTCTRLx_EDGx0_RISING_EDGE
#define EFPWM_CAPTURE_0_ANY_EDGE          EFPWM_CAPTCTRLx_EDGx0_ANY_EDGE

#define EFPWM_FREE_RUNNING                0
#define EFPWM_ONE_SHOT                    1


/* Common registers */
#define EFPWM_SUB3_PWM_A                  EFPWM_OUTEN_PWMA_EN_SUB3
#define EFPWM_SUB2_PWM_A                  EFPWM_OUTEN_PWMA_EN_SUB2
#define EFPWM_SUB1_PWM_A                  EFPWM_OUTEN_PWMA_EN_SUB1
#define EFPWM_SUB0_PWM_A                  EFPWM_OUTEN_PWMA_EN_SUB0
                                                                
#define EFPWM_SUB3_PWM_B                  EFPWM_OUTEN_PWMB_EN_SUB3
#define EFPWM_SUB2_PWM_B                  EFPWM_OUTEN_PWMB_EN_SUB2
#define EFPWM_SUB1_PWM_B                  EFPWM_OUTEN_PWMB_EN_SUB1
#define EFPWM_SUB0_PWM_B                  EFPWM_OUTEN_PWMB_EN_SUB0
                                                                
#define EFPWM_SUB3_PWM_X                  EFPWM_OUTEN_PWMX_EN_SUB3
#define EFPWM_SUB2_PWM_X                  EFPWM_OUTEN_PWMX_EN_SUB2
#define EFPWM_SUB1_PWM_X                  EFPWM_OUTEN_PWMX_EN_SUB1
#define EFPWM_SUB0_PWM_X                  EFPWM_OUTEN_PWMX_EN_SUB0

#define EFPWM_SUB3_PWM_A_ENABLE           EFPWM_OUTEN_PWMA_EN_SUB3 | EFPWM_OUTEN_PWMA_EN_SUB3_LONG
#define EFPWM_SUB2_PWM_A_ENABLE           EFPWM_OUTEN_PWMA_EN_SUB2 | EFPWM_OUTEN_PWMA_EN_SUB2_LONG
#define EFPWM_SUB1_PWM_A_ENABLE           EFPWM_OUTEN_PWMA_EN_SUB1 | EFPWM_OUTEN_PWMA_EN_SUB1_LONG
#define EFPWM_SUB0_PWM_A_ENABLE           EFPWM_OUTEN_PWMA_EN_SUB0 | EFPWM_OUTEN_PWMA_EN_SUB0_LONG

#define EFPWM_SUB3_PWM_A_DISABLE          EFPWM_OUTEN_PWMA_EN_SUB3_LONG
#define EFPWM_SUB2_PWM_A_DISABLE          EFPWM_OUTEN_PWMA_EN_SUB2_LONG
#define EFPWM_SUB1_PWM_A_DISABLE          EFPWM_OUTEN_PWMA_EN_SUB1_LONG
#define EFPWM_SUB0_PWM_A_DISABLE          EFPWM_OUTEN_PWMA_EN_SUB0_LONG

                                                                
#define EFPWM_SUB3_PWM_B_ENABLE           EFPWM_OUTEN_PWMB_EN_SUB3 | EFPWM_OUTEN_PWMB_EN_SUB3_LONG
#define EFPWM_SUB2_PWM_B_ENABLE           EFPWM_OUTEN_PWMB_EN_SUB2 | EFPWM_OUTEN_PWMB_EN_SUB2_LONG
#define EFPWM_SUB1_PWM_B_ENABLE           EFPWM_OUTEN_PWMB_EN_SUB1 | EFPWM_OUTEN_PWMB_EN_SUB1_LONG
#define EFPWM_SUB0_PWM_B_ENABLE           EFPWM_OUTEN_PWMB_EN_SUB0 | EFPWM_OUTEN_PWMB_EN_SUB0_LONG

#define EFPWM_SUB3_PWM_B_DISABLE          EFPWM_OUTEN_PWMB_EN_SUB3_LONG
#define EFPWM_SUB2_PWM_B_DISABLE          EFPWM_OUTEN_PWMB_EN_SUB2_LONG
#define EFPWM_SUB1_PWM_B_DISABLE          EFPWM_OUTEN_PWMB_EN_SUB1_LONG
#define EFPWM_SUB0_PWM_B_DISABLE          EFPWM_OUTEN_PWMB_EN_SUB0_LONG

                                                         
#define EFPWM_SUB3_PWM_X_ENABLE           EFPWM_OUTEN_PWMX_EN_SUB3 | EFPWM_OUTEN_PWMX_EN_SUB3_LONG
#define EFPWM_SUB2_PWM_X_ENABLE           EFPWM_OUTEN_PWMX_EN_SUB2 | EFPWM_OUTEN_PWMX_EN_SUB2_LONG
#define EFPWM_SUB1_PWM_X_ENABLE           EFPWM_OUTEN_PWMX_EN_SUB1 | EFPWM_OUTEN_PWMX_EN_SUB1_LONG
#define EFPWM_SUB0_PWM_X_ENABLE           EFPWM_OUTEN_PWMX_EN_SUB0 | EFPWM_OUTEN_PWMX_EN_SUB0_LONG

#define EFPWM_SUB3_PWM_X_DISABLE          EFPWM_OUTEN_PWMX_EN_SUB3_LONG
#define EFPWM_SUB2_PWM_X_DISABLE          EFPWM_OUTEN_PWMX_EN_SUB2_LONG
#define EFPWM_SUB1_PWM_X_DISABLE          EFPWM_OUTEN_PWMX_EN_SUB1_LONG
#define EFPWM_SUB0_PWM_X_DISABLE          EFPWM_OUTEN_PWMX_EN_SUB0_LONG



#define EFPWM_SUB3_PWM23                  EFPWM_SWCOUT_SM3OUT23
#define EFPWM_SUB3_PWM45                  EFPWM_SWCOUT_SM3OUT45
#define EFPWM_SUB2_PWM23                  EFPWM_SWCOUT_SM2OUT23
#define EFPWM_SUB2_PWM45                  EFPWM_SWCOUT_SM2OUT45
#define EFPWM_SUB1_PWM23                  EFPWM_SWCOUT_SM1OUT23
#define EFPWM_SUB1_PWM45                  EFPWM_SWCOUT_SM1OUT45
#define EFPWM_SUB0_PWM23                  EFPWM_SWCOUT_SM0OUT23
#define EFPWM_SUB0_PWM45                  EFPWM_SWCOUT_SM0OUT45

#define EFPWM_SOURCE_PWM                  0
#define EFPWM_SOURCE_INV_PWM              1
#define EFPWM_SOURCE_SWOUT                2
#define EFPWM_SOURCE_EXT                  3

#define EFPWM_SUB3_PWM23_SOURCE_PWM       (EFPWM_DTSRSEL_SM3SEL23_PWM23 | EFPWM_DTSRSEL_SM3SEL23_MASK_LONG)
#define EFPWM_SUB3_PWM23_SOURCE_INV_PWM   (EFPWM_DTSRSEL_SM3SEL23_INV_PWM23 | EFPWM_DTSRSEL_SM3SEL23_MASK_LONG)
#define EFPWM_SUB3_PWM23_SOURCE_SWOUT     (EFPWM_DTSRSEL_SM3SEL23_SWOUT23 | EFPWM_DTSRSEL_SM3SEL23_MASK_LONG)
#define EFPWM_SUB3_PWM23_SOURCE_EXT       (EFPWM_DTSRSEL_SM3SEL23_EXTA3 | EFPWM_DTSRSEL_SM3SEL23_MASK_LONG)
#define EFPWM_SUB3_PWM45_SOURCE_PWM       (EFPWM_DTSRSEL_SM3SEL45_PWM45 | EFPWM_DTSRSEL_SM3SEL45_MASK_LONG)
#define EFPWM_SUB3_PWM45_SOURCE_INV_PWM   (EFPWM_DTSRSEL_SM3SEL45_INV_PWM45 | EFPWM_DTSRSEL_SM3SEL45_MASK_LONG)
#define EFPWM_SUB3_PWM45_SOURCE_SWOUT     (EFPWM_DTSRSEL_SM3SEL45_SWOUT45 | EFPWM_DTSRSEL_SM3SEL45_MASK_LONG)
#define EFPWM_SUB3_PWM45_SOURCE_EXT       (EFPWM_DTSRSEL_SM3SEL45_EXTB3 | EFPWM_DTSRSEL_SM3SEL45_MASK_LONG)
#define EFPWM_SUB2_PWM23_SOURCE_PWM       (EFPWM_DTSRSEL_SM2SEL23_PWM23 | EFPWM_DTSRSEL_SM2SEL23_MASK_LONG)
#define EFPWM_SUB2_PWM23_SOURCE_INV_PWM   (EFPWM_DTSRSEL_SM2SEL23_INV_PWM23 | EFPWM_DTSRSEL_SM2SEL23_MASK_LONG)
#define EFPWM_SUB2_PWM23_SOURCE_SWOUT     (EFPWM_DTSRSEL_SM2SEL23_SWOUT23 | EFPWM_DTSRSEL_SM2SEL23_MASK_LONG)
#define EFPWM_SUB2_PWM23_SOURCE_EXT       (EFPWM_DTSRSEL_SM2SEL23_EXTA2 | EFPWM_DTSRSEL_SM2SEL23_MASK_LONG)
#define EFPWM_SUB2_PWM45_SOURCE_PWM       (EFPWM_DTSRSEL_SM2SEL45_PWM45 | EFPWM_DTSRSEL_SM2SEL45_MASK_LONG)
#define EFPWM_SUB2_PWM45_SOURCE_INV_PWM   (EFPWM_DTSRSEL_SM2SEL45_INV_PWM45 | EFPWM_DTSRSEL_SM2SEL45_MASK_LONG)
#define EFPWM_SUB2_PWM45_SOURCE_SWOUT     (EFPWM_DTSRSEL_SM2SEL45_SWOUT45 | EFPWM_DTSRSEL_SM2SEL45_MASK_LONG)
#define EFPWM_SUB2_PWM45_SOURCE_EXT       (EFPWM_DTSRSEL_SM2SEL45_EXTB2 | EFPWM_DTSRSEL_SM2SEL45_MASK_LONG)
#define EFPWM_SUB1_PWM23_SOURCE_PWM       (EFPWM_DTSRSEL_SM1SEL23_PWM23 | EFPWM_DTSRSEL_SM1SEL23_MASK_LONG)
#define EFPWM_SUB1_PWM23_SOURCE_INV_PWM   (EFPWM_DTSRSEL_SM1SEL23_INV_PWM23 | EFPWM_DTSRSEL_SM1SEL23_MASK_LONG)
#define EFPWM_SUB1_PWM23_SOURCE_SWOUT     (EFPWM_DTSRSEL_SM1SEL23_SWOUT23 | EFPWM_DTSRSEL_SM1SEL23_MASK_LONG)
#define EFPWM_SUB1_PWM23_SOURCE_EXT       (EFPWM_DTSRSEL_SM1SEL23_EXTA1 | EFPWM_DTSRSEL_SM1SEL23_MASK_LONG)
#define EFPWM_SUB1_PWM45_SOURCE_PWM       (EFPWM_DTSRSEL_SM1SEL45_PWM45 | EFPWM_DTSRSEL_SM1SEL45_MASK_LONG)
#define EFPWM_SUB1_PWM45_SOURCE_INV_PWM   (EFPWM_DTSRSEL_SM1SEL45_INV_PWM45 | EFPWM_DTSRSEL_SM1SEL45_MASK_LONG)
#define EFPWM_SUB1_PWM45_SOURCE_SWOUT     (EFPWM_DTSRSEL_SM1SEL45_SWOUT45 | EFPWM_DTSRSEL_SM1SEL45_MASK_LONG)
#define EFPWM_SUB1_PWM45_SOURCE_EXT       (EFPWM_DTSRSEL_SM1SEL45_EXTB1 | EFPWM_DTSRSEL_SM1SEL45_MASK_LONG)
#define EFPWM_SUB0_PWM23_SOURCE_PWM       (EFPWM_DTSRSEL_SM0SEL23_PWM23 | EFPWM_DTSRSEL_SM0SEL23_MASK_LONG)
#define EFPWM_SUB0_PWM23_SOURCE_INV_PWM   (EFPWM_DTSRSEL_SM0SEL23_INV_PWM23 | EFPWM_DTSRSEL_SM0SEL23_MASK_LONG)
#define EFPWM_SUB0_PWM23_SOURCE_SWOUT     (EFPWM_DTSRSEL_SM0SEL23_SWOUT23 | EFPWM_DTSRSEL_SM0SEL23_MASK_LONG)
#define EFPWM_SUB0_PWM23_SOURCE_EXT       (EFPWM_DTSRSEL_SM0SEL23_EXTA1 | EFPWM_DTSRSEL_SM0SEL23_MASK_LONG)
#define EFPWM_SUB0_PWM45_SOURCE_PWM       (EFPWM_DTSRSEL_SM0SEL45_PWM45 | EFPWM_DTSRSEL_SM0SEL45_MASK_LONG)
#define EFPWM_SUB0_PWM45_SOURCE_INV_PWM   (EFPWM_DTSRSEL_SM0SEL45_INV_PWM45 | EFPWM_DTSRSEL_SM0SEL45_MASK_LONG)
#define EFPWM_SUB0_PWM45_SOURCE_SWOUT     (EFPWM_DTSRSEL_SM0SEL45_SWOUT45 | EFPWM_DTSRSEL_SM0SEL45_MASK_LONG)
#define EFPWM_SUB0_PWM45_SOURCE_EXT       (EFPWM_DTSRSEL_SM0SEL45_EXTB0 | EFPWM_DTSRSEL_SM0SEL45_MASK_LONG)



#define EFPWM_SUBMODUL_0                  1
#define EFPWM_SUBMODUL_1                  2
#define EFPWM_SUBMODUL_2                  4
#define EFPWM_SUBMODUL_3                  8
#define EFPWM_SUBMODULE_0                 1
#define EFPWM_SUBMODULE_1                 2
#define EFPWM_SUBMODULE_2                 4
#define EFPWM_SUBMODULE_3                 8


#define EFPWM_DISABLE_PERMANENT           EFPWM_MCTRL2_MONPLL_DISABLE_PERNAMENT
#define EFPWM_ENABLE_PERMANENT            EFPWM_MCTRL2_MONPLL_ENABLE_PERNAMENT 

#define EFPWM_SAMPLES_3                   0
#define EFPWM_SAMPLES_4                   1
#define EFPWM_SAMPLES_5                   2
#define EFPWM_SAMPLES_6                   3
#define EFPWM_SAMPLES_7                   4
#define EFPWM_SAMPLES_8                   5
#define EFPWM_SAMPLES_9                   6
#define EFPWM_SAMPLES_10                  7


 
/****************************************************************************/

typedef struct
{
    Word16  pwmSub_0_Channel_23_Value;
    Word16  pwmSub_1_Channel_23_Value;
    Word16  pwmSub_2_Channel_23_Value;
} pwm_sComplementaryValues;

typedef struct
{
    Word16  pwmSub_0_Channel_23_Value;
    Word16  pwmSub_0_Channel_45_Value;
    Word16  pwmSub_1_Channel_23_Value;
    Word16  pwmSub_1_Channel_45_Value;
    Word16  pwmSub_2_Channel_23_Value;
    Word16  pwmSub_2_Channel_45_Value;
} pwm_sIndependentValues;

/*****************************************************************
* EFPWM Register Bits Defines, used in ioct command implementation
******************************************************************/

/* EFPWM Submodule Control Register 2 SMxCTRL2 */
#define EFPWM_CTRL2_DBGEN                    0x8000   /* Debug enable bit */  
#define EFPWM_CTRL2_WAITEN                   0x4000   /* Wait enable Bit */  
#define EFPWM_CTRL2_INDEP                    0x2000   /* Independendent or Complementary Pair Operation bit */
#define EFPWM_CTRL2_PWM23_INIT               0x1000   /* PWM23 Force Out Initial Value bit */
#define EFPWM_CTRL2_PWM45_INIT               0x0800   /* PWM45 Force Out Initial Value bit */
#define EFPWM_CTRL2_PWMX_INIT                0x0400   /* PWMX  Force Out Initial Value bit */
#define EFPWM_CTRL2_INIT_SEL_MASK            0x0300   /* Initialization Control Select bits */
#define EFPWM_CTRL2_INIT_SEL_LOCAL_SYNC      0x0000
#define EFPWM_CTRL2_INIT_SEL_MASTER_RELOAD   0x0100
#define EFPWM_CTRL2_INIT_SEL_MASTER_SYNC     0x0200
#define EFPWM_CTRL2_INIT_SEL_EXT_SYNC        0x0300
#define EFPWM_CTRL2_FRCEN                    0x0080   /* Force Initialization Enable bit */
#define EFPWM_CTRL2_FORCE                    0x0040   /* Force Initialization bit */
#define EFPWM_CTRL2_FORCE_SEL_MASK           0x0038   /* Source of the FORCE OUTPUT signal bits */
#define EFPWM_CTRL2_FORCE_SEL_LOCAL_FORCE    0x0000
#define EFPWM_CTRL2_FORCE_SEL_MASTER_FORCE   0x0008
#define EFPWM_CTRL2_FORCE_SEL_LOCAL_RELOAD   0x0010
#define EFPWM_CTRL2_FORCE_SEL_MASTER_RELOAD  0x0018
#define EFPWM_CTRL2_FORCE_SEL_LOCAL_SYNC     0x0020
#define EFPWM_CTRL2_FORCE_SEL_MASTER_SYNC    0x0028
#define EFPWM_CTRL2_FORCE_SEL_EXT_SYNC       0x0030
#define EFPWM_CTRL2_RELOAD_SEL               0x0004   /* Reload Source Select bit */
#define EFPWM_CTRL2_CLK_SEL_MASK             0x0003   /* Clock Source Select bits */
#define EFPWM_CTRL2_CLK_SEL_IPBUSCLOCK       0x0000
#define EFPWM_CTRL2_CLK_SEL_EXT_CLK          0x0001
#define EFPWM_CTRL2_CLK_SEL_SUBMODUL0        0x0002

/* EFPWM Submodule Control Register SMxCTRL */
#define EFPWM_CTRL_LDFQ_MASK                 0xf000   /* Load Frequency Bits */  
#define EFPWM_CTRL_LDFQ_0                    0x1000   /* Load Frequency Bit 0 */  
#define EFPWM_CTRL_LDFQ_1                    0x2000   /* Load Frequency Bit 1 */  
#define EFPWM_CTRL_LDFQ_2                    0x4000   /* Load Frequency Bit 2 */  
#define EFPWM_CTRL_LDFQ_3                    0x8000   /* Load Frequency Bit 3 */  
#define EFPWM_CTRL_HALF                      0x0800   /* Half Cycle Reload */
#define EFPWM_CTRL_FULL                      0x0400   /* Full Cycle Reload */
#define EFPWM_CTRL_DT_MASK                   0x0300   /* Deadtime outputs */
#define EFPWM_CTRL_DT_DEADTIME0              0x0100
#define EFPWM_CTRL_DT_DEADTIME1              0x0200
#define EFPWM_CTRL_PRSC_MASK                 0x0070   /* Prescaler Bits */
#define EFPWM_CTRL_PRSC_0                    0x0010   /* Prescaler Bit 0 */
#define EFPWM_CTRL_PRSC_1                    0x0020   /* Prescaler Bit 1 */
#define EFPWM_CTRL_PRSC_2                    0x0040   /* Prescaler Bit 2 */
#if EFPWM_VERSION >= 3
#define EFPWM_CTRL_SPLIT                     0x0008   /* Split Bit */
#endif
#define EFPWM_CTRL_LDMOD                     0x0004   /* Load Mode Select Bit */
#define EFPWM_CTRL_DBLEN                     0x0001   /* Double Switching Enable Bit */

/* EFPWM Submodule Fractional Value Register SMxFRACVALy */
#define EFPWM_FRACVALX_FRACVALX_MASK         0xf800   /* Fractional Value Bits */

/* EFPWM Submodule Fractional Control Register SMxFRCTRL */
#define EFPWM_FRCTRL_FRACX_EN_MASK           0x013E   /* Fractional Delay Enable Bits */
#define EFPWM_FRCTRL_FRACX_EN_FRAC1          0x0002
#define EFPWM_FRCTRL_FRACX_EN_FRAC23         0x0004
#define EFPWM_FRCTRL_FRACX_EN_FRAC45         0x0010
#define EFPWM_FRCTRL_FRACX_EN_PU             0x0100

/* EFPWM Submodule Output Control Register SMxFRCTRL */
#define EFPWM_OCTRL_PWMA_IN                  0x8000   /* PWMA Input Bits */
#define EFPWM_OCTRL_PWMB_IN                  0x4000   /* PWMB Input Bits */
#define EFPWM_OCTRL_PWMX_IN                  0x2000   /* PWMX Input Bits */
#define EFPWM_OCTRL_POLA                     0x0400   /* PWMA Output Polarity */
#define EFPWM_OCTRL_POLB                     0x0200   /* PWMB Output Polarity */
#define EFPWM_OCTRL_POLX                     0x0100   /* PWMX Output Polarity */
#define EFPWM_OCTRL_PWMAFS_MASK              0x0030   /* PWMA Fault State Bits */
#define EFPWM_OCTRL_PWMAFS_LOG_0             0x0000
#define EFPWM_OCTRL_PWMAFS_LOG_1             0x0010
#define EFPWM_OCTRL_PWMAFS_TRISTATED         0x0020
#define EFPWM_OCTRL_PWMBFS_MASK              0x000C   /* PWMB Fault State Bits */
#define EFPWM_OCTRL_PWMBFS_LOG_0             0x0000
#define EFPWM_OCTRL_PWMBFS_LOG_1             0x0004
#define EFPWM_OCTRL_PWMBFS_TRISTATED         0x0008
#define EFPWM_OCTRL_PWMXFS_MASK              0x0003   /* PWMX Fault State Bits */
#define EFPWM_OCTRL_PWMXFS_LOG_0             0x0000
#define EFPWM_OCTRL_PWMXFS_LOG_1             0x0001
#define EFPWM_OCTRL_PWMXFS_TRISTATED         0x0002

/* EFPWM Submodule Status Register SMxSTS */
#define EFPWM_STS_RUF                        0x4000   /* Registers Updated Flag */
#define EFPWM_STS_REF                        0x2000   /* Reload Error Flag */
#define EFPWM_STS_RF                         0x1000   /* Reload Flag */
#define EFPWM_STS_CAPT_MASK                  0x0FC0
#define EFPWM_STS_CFA1                       0x0800   /* Capture Flag A1 */
#define EFPWM_STS_CFA0                       0x0400   /* Capture Flag A0 */
#define EFPWM_STS_CFB1                       0x0200   /* Capture Flag B1 */
#define EFPWM_STS_CFB0                       0x0100   /* Capture Flag B0 */
#define EFPWM_STS_CFX1                       0x0080   /* Capture Flag X1 */
#define EFPWM_STS_CFX0                       0x0040   /* Capture Flag X0 */
#define EFPWM_STS_CMPF_MASK                  0x003F   /* Registers Updated Flag */
#define EFPWM_STS_CMPF_VAL0                  0x0001
#define EFPWM_STS_CMPF_VAL1                  0x0002
#define EFPWM_STS_CMPF_VAL2                  0x0004
#define EFPWM_STS_CMPF_VAL3                  0x0008
#define EFPWM_STS_CMPF_VAL4                  0x0010
#define EFPWM_STS_CMPF_VAL5                  0x0020

/* Submodule DMA Enable Register PWMA_SMnDMAEN */
#if EFPWM_VERSION >= 2
#define EFPWM_DMA_FIFO_MASK                  0x003f
#define EFPWM_DMA_FIFO_X0                    0x0001
#define EFPWM_DMA_FIFO_X1                    0x0002
#define EFPWM_DMA_FIFO_B0                    0x0004
#define EFPWM_DMA_FIFO_B1                    0x0008
#define EFPWM_DMA_FIFO_A0                    0x0010
#define EFPWM_DMA_FIFO_A1                    0x0020
#define EFPWM_DMA_CAPTDE_MASK                0x00C0
#define EFPWM_DMA_REQUEST_DISABLE            0x0000
#define EFPWM_DMA_REQUEST_FIFO_WATERMARK     0x0040
#define EFPWM_DMA_REQUEST_LOCAL_SYNC         0x0080
#define EFPWM_DMA_REQUEST_LOCAL_RELOAD       0x00C0
#define EFPWM_DMA_VALDE_MASK		     	 0x0200
#define EFPWM_DMA_FAND_MASK				   	 0x0100
#define EFPWM_DMA_WRITE_REQUEST_ENABLE     	 0x1
#define EFPWM_DMA_WRITE_REQUEST_DISSABLE   	 0x0
#define EFPWM_DMA_WRITE_FIFO_WATERMARK_AND 	 0x1
#define EFPWM_DMA_WRITE_FIFO_WATERMARK_OR  	 0x0
#endif

/* EFPWM Submodule Status Register SMxTCTRL */
#define EFPWM_TCTRL_OUT_TRIG_EN_MASK         0x003F   /* Output Trigger Enable Bits */
#define EFPWM_TCTRL_OUT_TRIG_EN_VAL0         0x0001
#define EFPWM_TCTRL_OUT_TRIG_EN_VAL1         0x0002
#define EFPWM_TCTRL_OUT_TRIG_EN_VAL2         0x0004
#define EFPWM_TCTRL_OUT_TRIG_EN_VAL3         0x0008
#define EFPWM_TCTRL_OUT_TRIG_EN_VAL4         0x0010
#define EFPWM_TCTRL_OUT_TRIG_EN_VAL5         0x0020

/* EFPWM Submodule Fault Disable Maping Register SMxDISMAP */
#define EFPWM_DISMAP_DISX_MASK               0x0F00   /* PWMX Disable Falt Mask Bits */
#define EFPWM_DISMAP_DISX_FAULT_4            0x0800
#define EFPWM_DISMAP_DISX_FAULT_3            0x0400
#define EFPWM_DISMAP_DISX_FAULT_2            0x0200
#define EFPWM_DISMAP_DISX_FAULT_1            0x0100
#define EFPWM_DISMAP_DISB_MASK               0x00F0   /* PWMB Disable Falt Mask Bits */
#define EFPWM_DISMAP_DISB_FAULT_4            0x0080
#define EFPWM_DISMAP_DISB_FAULT_3            0x0040
#define EFPWM_DISMAP_DISB_FAULT_2            0x0020
#define EFPWM_DISMAP_DISB_FAULT_1            0x0010
#define EFPWM_DISMAP_DISA_MASK               0x000F   /* PWMA Disable Falt Mask Bits */
#define EFPWM_DISMAP_DISA_FAULT_4            0x0008
#define EFPWM_DISMAP_DISA_FAULT_3            0x0004
#define EFPWM_DISMAP_DISA_FAULT_2            0x0002
#define EFPWM_DISMAP_DISA_FAULT_1            0x0001

/* EFPWM Submodule 3 Capture Control x Register SM3CAPTCTRLx */
#define EFPWM_CAPTCTRLx_Cx1CNT               0xE000   /* Capture 1 FIFO Word count (A/B/X) */
#define EFPWM_CAPTCTRLx_Cx0CNT               0x1C00   /* Capture 0 FIFO Word count (A/B/X) */
#define EFPWM_CAPTCTRLx_CFxWM                0x0300   /* Capture FIFO Water Mark (A/B/X) */
#define EFPWM_CAPTCTRLx_EDGCNTx_EN           0x0080   /* Edge Counter x Enable Bit (A/B/X) */
#define EFPWM_CAPTCTRLx_INP_SETx             0x0040   /* Input Select x Bit (A/B/X) */
#define EFPWM_CAPTCTRLx_EDGx1_MASK           0x0030   /* Edge x 1 Control Bits (A/B/X) */
#define EFPWM_CAPTCTRLx_EDGx1_DISABLE        0x0000
#define EFPWM_CAPTCTRLx_EDGx1_FALLING_EDGE   0x0010
#define EFPWM_CAPTCTRLx_EDGx1_RISING_EDGE    0x0020
#define EFPWM_CAPTCTRLx_EDGx1_ANY_EDGE       0x0030
#define EFPWM_CAPTCTRLx_EDGx0_MASK           0x000C   /* Edge x 0 Control Bits (A/B/X) */
#define EFPWM_CAPTCTRLx_EDGx0_DISABLE        0x0000
#define EFPWM_CAPTCTRLx_EDGx0_FALLING_EDGE   0x0004
#define EFPWM_CAPTCTRLx_EDGx0_RISING_EDGE    0x0008
#define EFPWM_CAPTCTRLx_EDGx0_ANY_EDGE       0x000C
#define EFPWM_CAPTCTRLx_ONESHOTX             0x0002   /* One Shot Mode x Bit (A/B/X) */
#define EFPWM_CAPTCTRLx_ARMx                 0x0001   /* Initialization Capture x Bit (A/B/X) */

/* EFPWM Submodule 3 Capture Compare x Register SM3CAPTCOMPx */
#define EFPWM_CAPTCOMPx_EDGCNTx_MASK         0xFF00   /* Edge Counter x Bits (A/B/X) */
#define EFPWM_CAPTCOMPx_EDGCMPx_MASK         0x00FF   /* Edge Compare x Bits (A/B/X) */

/* EFPWM module Output Enable Register OUTEN */
#if EFPWM_VERSION >= 3
#define EFPWM_OUTEN_UPDATE_MASK_EN_MASK      0xF000	  /* OUTPUT ENABLE PWMA Bits */	
#define EFPWM_OUTEN_UPDATE_MASK_EN_SUB3      0x8000	  
#define EFPWM_OUTEN_UPDATE_MASK_EN_SUB2      0x4000
#define EFPWM_OUTEN_UPDATE_MASK_EN_SUB1      0x2000
#define EFPWM_OUTEN_UPDATE_MASK_EN_SUB0      0x1000
#endif
#define EFPWM_OUTEN_PWMA_EN_MASK             0x0F00   /* OUTPUT ENABLE PWMA Bits */
#define EFPWM_OUTEN_PWMA_EN_SUB3             0x0800
#define EFPWM_OUTEN_PWMA_EN_SUB2             0x0400
#define EFPWM_OUTEN_PWMA_EN_SUB1             0x0200
#define EFPWM_OUTEN_PWMA_EN_SUB0             0x0100
#define EFPWM_OUTEN_PWMB_EN_MASK             0x00F0   /* OUTPUT ENABLE PWMB Bits */
#define EFPWM_OUTEN_PWMB_EN_SUB3             0x0080
#define EFPWM_OUTEN_PWMB_EN_SUB2             0x0040
#define EFPWM_OUTEN_PWMB_EN_SUB1             0x0020
#define EFPWM_OUTEN_PWMB_EN_SUB0             0x0010
#define EFPWM_OUTEN_PWMX_EN_MASK             0x000F   /* OUTPUT ENABLE PWMX Bits */
#define EFPWM_OUTEN_PWMX_EN_SUB3             0x0008
#define EFPWM_OUTEN_PWMX_EN_SUB2             0x0004
#define EFPWM_OUTEN_PWMX_EN_SUB1             0x0002
#define EFPWM_OUTEN_PWMX_EN_SUB0             0x0001

#define EFPWM_OUTEN_PWMA_EN_SUB3_LONG        0x08000000L	/* OUTPUT ENABLE PWMA Bits */
#define EFPWM_OUTEN_PWMA_EN_SUB2_LONG        0x04000000L
#define EFPWM_OUTEN_PWMA_EN_SUB1_LONG        0x02000000L
#define EFPWM_OUTEN_PWMA_EN_SUB0_LONG        0x01000000L
#define EFPWM_OUTEN_PWMB_EN_SUB3_LONG        0x00800000L	/* OUTPUT ENABLE PWMB Bits */
#define EFPWM_OUTEN_PWMB_EN_SUB2_LONG        0x00400000L
#define EFPWM_OUTEN_PWMB_EN_SUB1_LONG        0x00200000L
#define EFPWM_OUTEN_PWMB_EN_SUB0_LONG        0x00100000L
#define EFPWM_OUTEN_PWMX_EN_SUB3_LONG        0x00080000L	/* OUTPUT ENABLE PWMX Bits */
#define EFPWM_OUTEN_PWMX_EN_SUB2_LONG        0x00040000L
#define EFPWM_OUTEN_PWMX_EN_SUB1_LONG        0x00020000L
#define EFPWM_OUTEN_PWMX_EN_SUB0_LONG        0x00010000L

/* EFPWM module Mask Register MASK */
#if EFPWM_VERSION >= 3
#define EFPWM_MASK_UPDATE_MASK_MASK      0xF000	  /* OUTPUT ENABLE PWMA Bits */	
#define EFPWM_MASK_UPDATE_MASK_SUB3      0x8000	  
#define EFPWM_MASK_UPDATE_MASK_SUB2      0x4000
#define EFPWM_MASK_UPDATE_MASK_SUB1      0x2000
#define EFPWM_MASK_UPDATE_MASK_SUB0      0x1000
#endif
#define EFPWM_MASK_MASKA_MASK                0x0F00   /* MASK PWMA Bits */
#define EFPWM_MASK_MASKA_SUB3                0x0800
#define EFPWM_MASK_MASKA_SUB2                0x0400
#define EFPWM_MASK_MASKA_SUB1                0x0200
#define EFPWM_MASK_MASKA_SUB0                0x0100
#define EFPWM_MASK_MASKB_MASK                0x00F0   /* MASK PWMB Bits */
#define EFPWM_MASK_MASKB_SUB3                0x0080
#define EFPWM_MASK_MASKB_SUB2                0x0040
#define EFPWM_MASK_MASKB_SUB1                0x0020
#define EFPWM_MASK_MASKB_SUB0                0x0010
#define EFPWM_MASK_MASKX_MASK                0x000F   /* MASK PWMX Bits */
#define EFPWM_MASK_MASKX_SUB3                0x0008
#define EFPWM_MASK_MASKX_SUB2                0x0004
#define EFPWM_MASK_MASKX_SUB1                0x0002
#define EFPWM_MASK_MASKX_SUB0                0x0001

/* EFPWM module Software Output Register SWCOUT */
#define EFPWM_SWCOUT_SM3OUT23                0x0080   /* Force Out Software Output Level of Submodule 3 */ 
#define EFPWM_SWCOUT_SM3OUT45                0x0040
#define EFPWM_SWCOUT_SM2OUT23                0x0020   /* Force Out Software Output Level of Submodule 2 */
#define EFPWM_SWCOUT_SM2OUT45                0x0010
#define EFPWM_SWCOUT_SM1OUT23                0x0008   /* Force Out Software Output Level of Submodule 1 */
#define EFPWM_SWCOUT_SM1OUT45                0x0004
#define EFPWM_SWCOUT_SM0OUT23                0x0002   /* Force Out Software Output Level of Submodule 0 */
#define EFPWM_SWCOUT_SM0OUT45                0x0001

/* EFPWM module Deadtime Source Select Register DTSRSEL */
#define EFPWM_DTSRSEL_SM3SEL23_MASK          0xC000UL /* Force Out Selection of Submodule 3 */
#define EFPWM_DTSRSEL_SM3SEL23_PWM23         0x0000UL
#define EFPWM_DTSRSEL_SM3SEL23_INV_PWM23     0x4000UL
#define EFPWM_DTSRSEL_SM3SEL23_SWOUT23       0x8000UL
#define EFPWM_DTSRSEL_SM3SEL23_EXTA3         0xC000UL
#define EFPWM_DTSRSEL_SM3SEL45_MASK          0x3000UL
#define EFPWM_DTSRSEL_SM3SEL45_PWM45         0x0000UL
#define EFPWM_DTSRSEL_SM3SEL45_INV_PWM45     0x1000UL
#define EFPWM_DTSRSEL_SM3SEL45_SWOUT45       0x2000UL
#define EFPWM_DTSRSEL_SM3SEL45_EXTB3         0x3000UL
#define EFPWM_DTSRSEL_SM2SEL23_MASK          0x0C00UL /* Force Out Selection of Submodule 2 */
#define EFPWM_DTSRSEL_SM2SEL23_PWM23         0x0000UL
#define EFPWM_DTSRSEL_SM2SEL23_INV_PWM23     0x0400UL
#define EFPWM_DTSRSEL_SM2SEL23_SWOUT23       0x0800UL
#define EFPWM_DTSRSEL_SM2SEL23_EXTA2         0x0C00UL
#define EFPWM_DTSRSEL_SM2SEL45_MASK          0x0300UL
#define EFPWM_DTSRSEL_SM2SEL45_PWM45         0x0000UL
#define EFPWM_DTSRSEL_SM2SEL45_INV_PWM45     0x0100UL
#define EFPWM_DTSRSEL_SM2SEL45_SWOUT45       0x0200UL
#define EFPWM_DTSRSEL_SM2SEL45_EXTB2         0x0300UL
#define EFPWM_DTSRSEL_SM1SEL23_MASK          0x00C0UL /* Force Out Selection of Submodule 1 */
#define EFPWM_DTSRSEL_SM1SEL23_PWM23         0x0000UL
#define EFPWM_DTSRSEL_SM1SEL23_INV_PWM23     0x0040UL
#define EFPWM_DTSRSEL_SM1SEL23_SWOUT23       0x0080UL
#define EFPWM_DTSRSEL_SM1SEL23_EXTA1         0x00C0UL
#define EFPWM_DTSRSEL_SM1SEL45_MASK          0x0030UL
#define EFPWM_DTSRSEL_SM1SEL45_PWM45         0x0000UL
#define EFPWM_DTSRSEL_SM1SEL45_INV_PWM45     0x0010UL
#define EFPWM_DTSRSEL_SM1SEL45_SWOUT45       0x0020UL
#define EFPWM_DTSRSEL_SM1SEL45_EXTB1         0x0030UL
#define EFPWM_DTSRSEL_SM0SEL23_MASK          0x000CUL /* Force Out Selection of Submodule 0 */
#define EFPWM_DTSRSEL_SM0SEL23_PWM23         0x0000UL
#define EFPWM_DTSRSEL_SM0SEL23_INV_PWM23     0x0004UL
#define EFPWM_DTSRSEL_SM0SEL23_SWOUT23       0x0008UL
#define EFPWM_DTSRSEL_SM0SEL23_EXTA0         0x000CUL
#define EFPWM_DTSRSEL_SM0SEL45_MASK          0x0003UL
#define EFPWM_DTSRSEL_SM0SEL45_PWM45         0x0000UL
#define EFPWM_DTSRSEL_SM0SEL45_INV_PWM45     0x0001UL
#define EFPWM_DTSRSEL_SM0SEL45_SWOUT45       0x0002UL
#define EFPWM_DTSRSEL_SM0SEL45_EXTB0         0x0003UL

#define EFPWM_DTSRSEL_SM3SEL23_MASK_LONG     0xC0000000UL  /* Force Out Selection of Submodule 3 */
#define EFPWM_DTSRSEL_SM3SEL45_MASK_LONG     0x30000000UL
#define EFPWM_DTSRSEL_SM2SEL23_MASK_LONG     0x0C000000UL
#define EFPWM_DTSRSEL_SM2SEL45_MASK_LONG     0x03000000UL
#define EFPWM_DTSRSEL_SM1SEL23_MASK_LONG     0x00C00000UL
#define EFPWM_DTSRSEL_SM1SEL45_MASK_LONG     0x00300000UL
#define EFPWM_DTSRSEL_SM0SEL23_MASK_LONG     0x000C0000UL
#define EFPWM_DTSRSEL_SM0SEL45_MASK_LONG     0x00030000UL


/* EFPWM module Master Control Register MCTRL */
#define EFPWM_MCTRL_IPOL_MASK                0xF000   /* Current Deadtime Logic Polarity Bits */
#define EFPWM_MCTRL_IPOL_SUB3                0x8000
#define EFPWM_MCTRL_IPOL_SUB2                0x4000
#define EFPWM_MCTRL_IPOL_SUB1                0x2000
#define EFPWM_MCTRL_IPOL_SUB0                0x1000
#define EFPWM_MCTRL_RUN_MASK                 0x0F00   /* Enable/disable Clock for PWM Counter Register Bits */
#define EFPWM_MCTRL_RUN_SUB3                 0x0800
#define EFPWM_MCTRL_RUN_SUB2                 0x0400
#define EFPWM_MCTRL_RUN_SUB1                 0x0200
#define EFPWM_MCTRL_RUN_SUB0                 0x0100
#define EFPWM_MCTRL_CLDOK_MASK               0x00F0   /* Clear LDOK Request Bits */
#define EFPWM_MCTRL_CLDOK_SUB3               0x0080
#define EFPWM_MCTRL_CLDOK_SUB2               0x0040
#define EFPWM_MCTRL_CLDOK_SUB1               0x0020
#define EFPWM_MCTRL_CLDOK_SUB0               0x0010
#define EFPWM_MCTRL_LDOK_MASK                0x000F   /* Load Okay Bits */
#define EFPWM_MCTRL_LDOK_SUB3                0x0008
#define EFPWM_MCTRL_LDOK_SUB2                0x0004
#define EFPWM_MCTRL_LDOK_SUB1                0x0002
#define EFPWM_MCTRL_LDOK_SUB0                0x0001

/* EFPWM module Master Control Register 2 MCTRL2 */
#define EFPWM_MCTRL2_MONPLL_MASK             0x0003   /* Monitor PLL State */
#define EFPWM_MCTRL2_MONPLL_DISABLE          0x0000
#define EFPWM_MCTRL2_MONPLL_ENABLE           0x0001
#define EFPWM_MCTRL2_MONPLL_DISABLE_PERNAMENT 0x0002
#define EFPWM_MCTRL2_MONPLL_ENABLE_PERNAMENT 0x0003



/* EFPWM module Fault Control Register FCTRL */
#define EFPWM_FCTRL_FLVL_MASK                0xF000   /* Fault Level Bits */
#define EFPWM_FCTRL_FLVL_FAULT3              0x8000
#define EFPWM_FCTRL_FLVL_FAULT2              0x4000
#define EFPWM_FCTRL_FLVL_FAULT1              0x2000
#define EFPWM_FCTRL_FLVL_FAULT0              0x1000
#define EFPWM_FCTRL_FAUTO_MASK               0x0F00   /* Automatic Fault Clearing Bits */
#define EFPWM_FCTRL_FAUTO_FAULT3             0x0800
#define EFPWM_FCTRL_FAUTO_FAULT2             0x0400
#define EFPWM_FCTRL_FAUTO_FAULT1             0x0200
#define EFPWM_FCTRL_FAUTO_FAULT0             0x0100
#define EFPWM_FCTRL_FSAFE_MASK               0x00F0   /* Fault Safety Mode Bits */
#define EFPWM_FCTRL_FSAFE_FAULT3             0x0080
#define EFPWM_FCTRL_FSAFE_FAULT2             0x0040
#define EFPWM_FCTRL_FSAFE_FAULT1             0x0020
#define EFPWM_FCTRL_FSAFE_FAULT0             0x0010
#define EFPWM_FCTRL_FIE_MASK                 0x000F   /* Fault Interrupt Enable Bits */
#define EFPWM_FCTRL_FIE_FAULT3               0x0008
#define EFPWM_FCTRL_FIE_FAULT2               0x0004
#define EFPWM_FCTRL_FIE_FAULT1               0x0002
#define EFPWM_FCTRL_FIE_FAULT0               0x0001

/* EFPWM module Fault Status Register FSTS */
#define EFPWM_FSTS_TEST                      0x1000   /* Fault Test Bit */
#define EFPWM_FSTS_FFPIN_MASK                0x0F00   /* Filtered Fault Pins Bits */
#define EFPWM_FSTS_FFPIN_FAULT3              0x0800
#define EFPWM_FSTS_FFPIN_FAULT2              0x0400
#define EFPWM_FSTS_FFPIN_FAULT1              0x0200
#define EFPWM_FSTS_FFPIN_FAULT0              0x0100
#define EFPWM_FSTS_FFULL_MASK                0x00F0   /* Full Cycle Bits */
#define EFPWM_FSTS_FFULL_FAULT3              0x0080
#define EFPWM_FSTS_FFULL_FAULT2              0x0040
#define EFPWM_FSTS_FFULL_FAULT1              0x0020
#define EFPWM_FSTS_FFULL_FAULT0              0x0010
#define EFPWM_FSTS_FFLAG_MASK                0x000F   /* Fault Flag Bits */
#define EFPWM_FSTS_FFLAG_FAULT3              0x0008
#define EFPWM_FSTS_FFLAG_FAULT2              0x0004
#define EFPWM_FSTS_FFLAG_FAULT1              0x0002
#define EFPWM_FSTS_FFLAG_FAULT0              0x0001

#if EFPWM_VERSION >= 2 
/* EFPWM module  Fault Test Register  */
#define EFPWM_FTEST_MASK              		0x0001
#define EFPWM_SIMUATED_FAULT              	0x1
#define EFPWM_NO_FAULT              		0x0

#endif
#if EFPWM_VERSION >= 2
/* EFPWM module Fault Test Register FTST */
#define EFPWM_FTST_TEST                      0x0001
#endif

/* EFPWM module Fault Status Register FSTS */
#define EFPWM_FFILT_GSTR                     0x8000   /* Fault Glitch Stretch Enable Bit */
#define EFPWM_FFILT_FILT_CNT_MASK            0x0700   /* Fault Filter Count Bits */
#define EFPWM_FFILT_FILT_PER_MASK            0x00FF   /* Fault Filter Period Bits */

/***********************************************************************
* PWM init
***********************************************************************/
/* common registers init */
void efpwmCommonInit(arch_sEFPWM *pEfpwmBase);
#if defined(EFPWM_B)
void efpwmBCommonInit(arch_sEFPWMB *pEfpwmBase);
#endif

/* EFPWM init  for all registers and modules */
void efpwmInit(UWord16 *pEfpwmBase);
#define ioctlEFPWM_INIT(pEfpwmBase, param) efpwmInit((UWord16*)pEfpwmBase)

/* submodule with fractional and capture logic registers init PWM or PWM_A */
void efpwmSubFracCaptInit(arch_sEFPWMSubFracCaptModule *pEfpwmBase);
/* submodule with Capture logic registers init */
void efpwmSubCaptInit(arch_sEFPWMSubCaptModule *pEfpwmBase);
/* submodule with Capture logic registers init PWM_B */
#if defined(EFPWM_B)
void efpwmBSubCaptInit(arch_sEFPWMBSubCaptModule *pEfpwmBaseB);
#endif


/* submodule with fractional and capture logic registers init PWM or PWM_A */
void efpwmSubFracCaptInit(arch_sEFPWMSubFracCaptModule *pEfpwmBase);
/* submodule with Capture logic registers init */
void efpwmSubCaptInit(arch_sEFPWMSubCaptModule *pEfpwmBase);
/* submodule with Capture logic registers init PWM_B */
#if defined(EFPWM_B)
void efpwmBSubCaptInit(arch_sEFPWMBSubCaptModule *pEfpwmBaseB);
#endif

/***********************************************************************
* PWM Low Level drivers
***********************************************************************/

#define ioctlEFPWMS_READ_COUNTER_REG(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->smcnt))

#define ioctlEFPWMS_WRITE_INIT_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->sminit))

#define ioctlEFPWMS_READ_INIT_REG(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->sminit))

/* PWM Control Register 1 */

#define ioctlEFPWMS_SET_RELOAD_FREQUENCY(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_CTRL_LDFQ_MASK, ((param) << 12), &((pEfpwmBase)->smctrl))

#define ioctlEFPWMS_HALF_CYCLE_RELOAD(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CTRL_HALF, &((pEfpwmBase)->smctrl)); \
  else periphBitClear(EFPWM_CTRL_HALF, &((pEfpwmBase)->smctrl))

#define ioctlEFPWMS_FULL_CYCLE_RELOAD(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CTRL_FULL, &((pEfpwmBase)->smctrl)); \
  else periphBitClear(EFPWM_CTRL_FULL, &((pEfpwmBase)->smctrl))

#define ioctlEFPWMS_SET_PRESCALER(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_CTRL_PRSC_MASK, ((param) << 4), &((pEfpwmBase)->smctrl))

#if EFPWM_VERSION >= 3
#define ioctlEFPWMS_SPLIT_DBLPWM(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CTRL_SPLIT, &((pEfpwmBase)->smctrl)); \
  else periphBitClear(EFPWM_CTRL_SPLIT, &((pEfpwmBase)->smctrl))
#endif

#define ioctlEFPWMS_TEST_DEADTIME_SAMPLE_BITS(pEfpwmBase, param) \
  periphBitTest( (param), &((pEfpwmBase)->smctrl) )
  
#define ioctlEFPWMS_SET_LOAD_MODE(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CTRL_LDMOD, &((pEfpwmBase)->smctrl)); \
  else periphBitClear(EFPWM_CTRL_LDMOD, &((pEfpwmBase)->smctrl))

#define ioctlEFPWMS_SET_DOUBLE_SWITCHING(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CTRL_DBLEN, &((pEfpwmBase)->smctrl)); \
  else periphBitClear(EFPWM_CTRL_DBLEN, &((pEfpwmBase)->smctrl))

/* PWM Control Register 2 */
#define ioctlEFPWMS_DEBUG_OPERATION(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CTRL2_DBGEN, &((pEfpwmBase)->smctrl2)); \
  else periphBitClear(EFPWM_CTRL2_DBGEN, &((pEfpwmBase)->smctrl2))

#define ioctlEFPWMS_WAIT_OPERATION(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CTRL2_WAITEN, &((pEfpwmBase)->smctrl2)); \
  else periphBitClear(EFPWM_CTRL2_WAITEN, &((pEfpwmBase)->smctrl2))

#define ioctlEFPWMS_SET_INDEPENDENT_MODE(pEfpwmBase, param) \
  periphBitSet(EFPWM_CTRL2_INDEP, &((pEfpwmBase)->smctrl2))

#define ioctlEFPWMS_SET_COMPLEMENTARY_MODE(pEfpwmBase, param) \
  periphBitClear(EFPWM_CTRL2_INDEP, &((pEfpwmBase)->smctrl2))

#define ioctlEFPWMS_SET_PAIR_OPERATION(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CTRL2_INDEP, &((pEfpwmBase)->smctrl2)); \
  else periphBitClear(EFPWM_CTRL2_INDEP, &((pEfpwmBase)->smctrl2))

#define ioctlEFPWMS_SET_FORCE_INIT_PWMOUT_TO_HIGH(pEfpwmBase, param) \
  periphBitSet( (((param) << 10)&(EFPWM_CTRL2_PWM23_INIT|EFPWM_CTRL2_PWM45_INIT|EFPWM_CTRL2_PWMX_INIT)), &((pEfpwmBase)->smctrl2) )

#define ioctlEFPWMS_SET_FORCE_INIT_PWMOUT_TO_LOW(pEfpwmBase, param) \
  periphBitClear( (((param) << 10)&(EFPWM_CTRL2_PWM23_INIT|EFPWM_CTRL2_PWM45_INIT|EFPWM_CTRL2_PWMX_INIT)), &((pEfpwmBase)->smctrl2) )

#define ioctlEFPWMS_SET_SYNC_SOURCE(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_CTRL2_INIT_SEL_MASK, param, &((pEfpwmBase)->smctrl2))

#define ioctlEFPWMS_SET_FORCE_INIT(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CTRL2_FRCEN, &((pEfpwmBase)->smctrl2)); \
  else periphBitClear(EFPWM_CTRL2_FRCEN, &((pEfpwmBase)->smctrl2))

#define ioctlEFPWMS_ACTIVE_FORCE_INIT(pEfpwmBase, param) \
  periphBitSet(EFPWM_CTRL2_FORCE, &((pEfpwmBase)->smctrl2))

#define ioctlEFPWMS_SET_FORCE_INIT_SOURCE(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_CTRL2_FORCE_SEL_MASK, param , &((pEfpwmBase)->smctrl2))

#define ioctlEFPWMS_SET_RELOAD_SOURCE(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CTRL2_RELOAD_SEL, &((pEfpwmBase)->smctrl2)); \
  else periphBitClear(EFPWM_CTRL2_RELOAD_SEL, &((pEfpwmBase)->smctrl2))

#define ioctlEFPWMS_SET_CLOCK_SOURCE(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_CTRL2_CLK_SEL_MASK, param , &((pEfpwmBase)->smctrl2))

/* PWM Value Registers */
#define ioctlEFPWMS_WRITE_VALUE_REG_0(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smval0))

#define ioctlEFPWMS_WRITE_VALUE_REG_1(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smval1))

#define ioctlEFPWMS_WRITE_VALUE_REG_2(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smval2))

#define ioctlEFPWMS_WRITE_VALUE_REG_3(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smval3))

#define ioctlEFPWMS_WRITE_VALUE_REG_4(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smval4))

#define ioctlEFPWMS_WRITE_VALUE_REG_5(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smval5))

#define ioctlEFPWMS_READ_VALUE_REG_0(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->smval0))

#define ioctlEFPWMS_READ_VALUE_REG_1(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->smval1))

#define ioctlEFPWMS_READ_VALUE_REG_2(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->smval2))

#define ioctlEFPWMS_READ_VALUE_REG_3(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->smval3))

#define ioctlEFPWMS_READ_VALUE_REG_4(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->smval4))

#define ioctlEFPWMS_READ_VALUE_REG_5(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->smval5))

/* PWM Fractional Delay Registers */
#define ioctlEFPWMS_WRITE_FRAC_VALUE_REG_1(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smfracval1))

#define ioctlEFPWMS_WRITE_FRAC_VALUE_REG_2(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smfracval2))

#define ioctlEFPWMS_WRITE_FRAC_VALUE_REG_3(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smfracval3))

#define ioctlEFPWMS_WRITE_FRAC_VALUE_REG_4(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smfracval4))

#define ioctlEFPWMS_WRITE_FRAC_VALUE_REG_5(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smfracval5))

/* Fractional Delay Control Register */
#define ioctlEFPWMS_SET_FRACTIONAL_DELAY_ENABLE(pEfpwmBase, param) \
  periphBitSet( ((param)&EFPWM_FRCTRL_FRACX_EN_MASK) , &((pEfpwmBase)->smfrctrl))

#define ioctlEFPWMS_SET_FRACTIONAL_DELAY_DISABLE(pEfpwmBase, param) \
  periphBitClear( ((param)&EFPWM_FRCTRL_FRACX_EN_MASK) , &((pEfpwmBase)->smfrctrl))

/* Output Control Register */
#define ioctlEFPWMS_TEST_PWM_INPUTS(pEfpwmBase, param) \
  periphBitTest((((param)<<13)&(EFPWM_OCTRL_PWMA_IN|EFPWM_OCTRL_PWMB_IN|EFPWM_OCTRL_PWMX_IN)), &((pEfpwmBase)->smoctrl))

#define ioctlEFPWMS_SET_PWM_POLARITY_HIGH_ACTIVE(pEfpwmBase, param) \
  periphBitClear( (((param)<<8)&(EFPWM_OCTRL_POLA|EFPWM_OCTRL_POLB|EFPWM_OCTRL_POLX)), &((pEfpwmBase)->smoctrl))

#define ioctlEFPWMS_SET_PWM_POLARITY_LOW_ACTIVE(pEfpwmBase, param) \
  periphBitSet( (((param)<<8)&(EFPWM_OCTRL_POLA|EFPWM_OCTRL_POLB|EFPWM_OCTRL_POLX)), &((pEfpwmBase)->smoctrl))

#define ioctlEFPWMS_SET_PWM_FAULT_STATEOUT_A(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_OCTRL_PWMAFS_MASK, ((param)<<4) , &((pEfpwmBase)->smoctrl))

#define ioctlEFPWMS_SET_PWM_FAULT_STATEOUT_B(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_OCTRL_PWMBFS_MASK, ((param)<<2) , &((pEfpwmBase)->smoctrl))

#define ioctlEFPWMS_SET_PWM_FAULT_STATEOUT_X(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_OCTRL_PWMXFS_MASK, (param) , &((pEfpwmBase)->smoctrl))

#define ioctlEFPWMS_WRITE_OUTPUT_CONTROL_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smoctrl))

/* Status Register */
#define ioctlEFPWMS_TEST_SUBMODULE_FLAGS(pEfpwmBase, param) \
  periphBitTest(param, &((pEfpwmBase)->smsts))

#define ioctlEFPWMS_CLEAR_SUBMODULE_FLAGS(pEfpwmBase, param) \
  periphSafeAckByOne(EFPWM_STS_REF|EFPWM_STS_RF|EFPWM_STS_CAPT_MASK|EFPWM_STS_CMPF_MASK, param, &((pEfpwmBase)->smsts))

/* PWM Interrupt Enable Register */
#define ioctlEFPWMS_INT_ENABLE(pEfpwmBase, param) \
  periphBitSet(param, &((pEfpwmBase)->sminten));

#define ioctlEFPWMS_INT_DISABLE(pEfpwmBase, param) \
  periphBitClear(param, &((pEfpwmBase)->sminten));

/* PWM DMA Enable Register */
#if EFPWM_VERSION >= 2 
#define ioctlEFPWMS_DMA_CAPTURE_ENABLE(pEfpwmBase, param) \
  periphBitSet((param & EFPWM_DMA_FIFO_MASK), &((pEfpwmBase)->smdmaen));

#define ioctlEFPWMS_DMA_CAPTURE_DISABLE(pEfpwmBase, param) \
  periphBitClear((param & EFPWM_DMA_FIFO_MASK), &((pEfpwmBase)->smdmaen));

#define ioctlEFPWMS_DMA_SET_CLOCK_SOURCE(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_DMA_CAPTDE_MASK, (param), &((pEfpwmBase)->smdmaen));

#define ioctlEFPWMS_DMA_FIFO_WATERMARK_CONTROL(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_DMA_FAND_MASK, &((pEfpwmBase)->smdmaen)); \
  else periphBitClear(EFPWM_DMA_FAND_MASK, &((pEfpwmBase)->smdmaen))

#define ioctlEFPWMS_DMA_VALUE_REGISTERS(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_DMA_VALDE_MASK, &((pEfpwmBase)->smdmaen)); \
  else periphBitClear(EFPWM_DMA_VALDE_MASK, &((pEfpwmBase)->smdmaen))
#endif

/*  Output Trigger Control Register */
#define ioctlEFPWMS_OUTPUT_TRIGGER_ENABLE(pEfpwmBase, param) \
  periphBitSet( ((param)&EFPWM_TCTRL_OUT_TRIG_EN_MASK), &((pEfpwmBase)->smtctrl) )

#define ioctlEFPWMS_OUTPUT_TRIGGER_DISABLE(pEfpwmBase, param) \
  periphBitClear( ((param)&EFPWM_TCTRL_OUT_TRIG_EN_MASK), &((pEfpwmBase)->smtctrl) )

/* Fault Disable Mapping Register */
#define ioctlEFPWMS_PWMX_FAULT_ENABLE(pEfpwmBase, param) \
  periphBitSet( (((param)<<8)&EFPWM_DISMAP_DISX_MASK), &((pEfpwmBase)->smdismap) )

#define ioctlEFPWMS_PWMX_FAULT_DISABLE(pEfpwmBase, param) \
  periphBitClear( (((param)<<8)&EFPWM_DISMAP_DISX_MASK), &((pEfpwmBase)->smdismap) )

#define ioctlEFPWMS_PWMB_FAULT_ENABLE(pEfpwmBase, param) \
  periphBitSet( (((param)<<4)&EFPWM_DISMAP_DISB_MASK), &((pEfpwmBase)->smdismap) )

#define ioctlEFPWMS_PWMB_FAULT_DISABLE(pEfpwmBase, param) \
  periphBitClear( (((param)<<4)&EFPWM_DISMAP_DISB_MASK), &((pEfpwmBase)->smdismap) )

#define ioctlEFPWMS_PWMA_FAULT_ENABLE(pEfpwmBase, param) \
  periphBitSet( ((param)&EFPWM_DISMAP_DISA_MASK), &((pEfpwmBase)->smdismap) )

#define ioctlEFPWMS_PWMA_FAULT_DISABLE(pEfpwmBase, param) \
  periphBitClear( ((param)&EFPWM_DISMAP_DISA_MASK), &((pEfpwmBase)->smdismap) )

#define ioctlEFPWMS_WRITE_FAULT_MAPPING_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smdismap))

#if EFPWM_VERSION >= 2
#define ioctlEFPWMS_PWMX_FAULT0_ENABLE(pEfpwmBase, param) \
  periphBitSet( (((param)<<8)&EFPWM_DISMAP_DISX_MASK), &((pEfpwmBase)->smdismap0) )

#define ioctlEFPWMS_PWMX_FAULT0_DISABLE(pEfpwmBase, param) \
  periphBitClear( (((param)<<8)&EFPWM_DISMAP_DISX_MASK), &((pEfpwmBase)->smdismap0) )

#define ioctlEFPWMS_PWMB_FAULT0_ENABLE(pEfpwmBase, param) \
  periphBitSet( (((param)<<4)&EFPWM_DISMAP_DISB_MASK), &((pEfpwmBase)->smdismap0) )

#define ioctlEFPWMS_PWMB_FAULT0_DISABLE(pEfpwmBase, param) \
  periphBitClear( (((param)<<4)&EFPWM_DISMAP_DISB_MASK), &((pEfpwmBase)->smdismap0) )

#define ioctlEFPWMS_PWMA_FAULT0_ENABLE(pEfpwmBase, param) \
  periphBitSet( ((param)&EFPWM_DISMAP_DISA_MASK), &((pEfpwmBase)->smdismap0) )

#define ioctlEFPWMS_PWMA_FAULT0_DISABLE(pEfpwmBase, param) \
  periphBitClear( ((param)&EFPWM_DISMAP_DISA_MASK), &((pEfpwmBase)->smdismap0) )

#define ioctlEFPWMS_WRITE_FAULT0_MAPPING_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smdismap0))

#define ioctlEFPWMS_PWMX_FAULT1_ENABLE(pEfpwmBase, param) \
  periphBitSet( (((param)<<8)&EFPWM_DISMAP_DISX_MASK), &((pEfpwmBase)->smdismap1) )

#define ioctlEFPWMS_PWMX_FAULT1_DISABLE(pEfpwmBase, param) \
  periphBitClear( (((param)<<8)&EFPWM_DISMAP_DISX_MASK), &((pEfpwmBase)->smdismap1) )

#define ioctlEFPWMS_PWMB_FAULT1_ENABLE(pEfpwmBase, param) \
  periphBitSet( (((param)<<4)&EFPWM_DISMAP_DISB_MASK), &((pEfpwmBase)->smdismap1) )

#define ioctlEFPWMS_PWMB_FAULT1_DISABLE(pEfpwmBase, param) \
  periphBitClear( (((param)<<4)&EFPWM_DISMAP_DISB_MASK), &((pEfpwmBase)->smdismap1) )

#define ioctlEFPWMS_PWMA_FAULT1_ENABLE(pEfpwmBase, param) \
  periphBitSet( ((param)&EFPWM_DISMAP_DISA_MASK), &((pEfpwmBase)->smdismap1) )

#define ioctlEFPWMS_PWMA_FAULT1_DISABLE(pEfpwmBase, param) \
  periphBitClear( ((param)&EFPWM_DISMAP_DISA_MASK), &((pEfpwmBase)->smdismap1) )

#define ioctlEFPWMS_WRITE_FAULT1_MAPPING_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smdismap1))
#endif

/* Deadtime logic registers */
#define ioctlEFPWMS_SET_DEADTIME_0(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smdtcnt0))

#define ioctlEFPWMS_SET_DEADTIME_1(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->smdtcnt1))

/* Submodule Comannds with Capture Logic*/
/* Capture Control A Register */
#define ioctlEFPWMS_READ_CAPTURE_A1_FIFO_COUNT(pEfpwmBase, param) \
  ((periphMemRead( &((pEfpwmBase)->smcaptctrla) )&EFPWM_CAPTCTRLx_Cx1CNT )>>13)

#define ioctlEFPWMS_READ_CAPTURE_A0_FIFO_COUNT(pEfpwmBase, param) \
  ((periphMemRead( &((pEfpwmBase)->smcaptctrla) )&EFPWM_CAPTCTRLx_Cx0CNT )>>10)

#define ioctlEFPWMS_SET_CAPTURE_A_FIFO_WATERMARK(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_CAPTCTRLx_CFxWM, ((param)<<8) , &((pEfpwmBase)->smcaptctrla))

#define ioctlEFPWMS_SET_EDGE_COUNTER_A(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CAPTCTRLx_EDGCNTx_EN, &((pEfpwmBase)->smcaptctrla)); \
  else periphBitClear(EFPWM_CAPTCTRLx_EDGCNTx_EN, &((pEfpwmBase)->smcaptctrla))

#define ioctlEFPWMS_SET_CAPTURE_A_INPUT(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CAPTCTRLx_INP_SETx, &((pEfpwmBase)->smcaptctrla)); \
  else periphBitClear(EFPWM_CAPTCTRLx_INP_SETx, &((pEfpwmBase)->smcaptctrla))

#define ioctlEFPWMS_SET_CAPTURE_A_1(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_CAPTCTRLx_EDGx1_MASK, (param) , &((pEfpwmBase)->smcaptctrla))

#define ioctlEFPWMS_SET_CAPTURE_A_0(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_CAPTCTRLx_EDGx0_MASK, (param) , &((pEfpwmBase)->smcaptctrla))

#define ioctlEFPWMS_SET_CAPTURE_A_MODE(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CAPTCTRLx_ONESHOTX, &((pEfpwmBase)->smcaptctrla)); \
  else periphBitClear(EFPWM_CAPTCTRLx_ONESHOTX, &((pEfpwmBase)->smcaptctrla))

#define ioctlEFPWMS_ACTIVE_CAPTURE_A(pEfpwmBase, param) \
  periphBitSet(EFPWM_CAPTCTRLx_ARMx, &((pEfpwmBase)->smcaptctrla))

#define ioctlEFPWMS_CAPTURE_A_DISABLE(pEfpwmBase, param) \
  periphBitClear(EFPWM_CAPTCTRLx_ARMx, &((pEfpwmBase)->smcaptctrla))

/* Capture Compare A Register */

#define ioctlEFPWMS_SET_COMPARE_A(pEfpwmBase, param) \
  periphMemWrite(((param)&EFPWM_CAPTCOMPx_EDGCMPx_MASK), &((pEfpwmBase)->smcaptcompa))

#define ioctlEFPWMS_READ_EDGE_COUNTER_A(pEfpwmBase, param) \
  ((periphMemRead( &((pEfpwmBase)->smcaptcompa) ))>>8)

/* Capture Control B Register */
#define ioctlEFPWMS_READ_CAPTURE_B1_FIFO_COUNT(pEfpwmBase, param) \
  ((periphMemRead( &((pEfpwmBase)->smcaptctrlb) )&EFPWM_CAPTCTRLx_Cx1CNT )>>13)

#define ioctlEFPWMS_READ_CAPTURE_B0_FIFO_COUNT(pEfpwmBase, param) \
  ((periphMemRead( &((pEfpwmBase)->smcaptctrlb) )&EFPWM_CAPTCTRLx_Cx0CNT )>>10)

#define ioctlEFPWMS_SET_CAPTURE_B_FIFO_WATERMARK(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_CAPTCTRLx_CFxWM, ((param)<<8) , &((pEfpwmBase)->smcaptctrlb))

#define ioctlEFPWMS_SET_EDGE_COUNTER_B(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CAPTCTRLx_EDGCNTx_EN, &((pEfpwmBase)->smcaptctrlb)); \
  else periphBitClear(EFPWM_CAPTCTRLx_EDGCNTx_EN, &((pEfpwmBase)->smcaptctrlb))

#define ioctlEFPWMS_SET_CAPTURE_B_INPUT(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CAPTCTRLx_INP_SETx, &((pEfpwmBase)->smcaptctrlb)); \
  else periphBitClear(EFPWM_CAPTCTRLx_INP_SETx, &((pEfpwmBase)->smcaptctrlb))

#define ioctlEFPWMS_SET_CAPTURE_B_1(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_CAPTCTRLx_EDGx1_MASK, (param) , &((pEfpwmBase)->smcaptctrlb))

#define ioctlEFPWMS_SET_CAPTURE_B_0(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_CAPTCTRLx_EDGx0_MASK, (param) , &((pEfpwmBase)->smcaptctrlb))

#define ioctlEFPWMS_SET_CAPTURE_B_MODE(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CAPTCTRLx_ONESHOTX, &((pEfpwmBase)->smcaptctrlb)); \
  else periphBitClear(EFPWM_CAPTCTRLx_ONESHOTX, &((pEfpwmBase)->smcaptctrlb))

#define ioctlEFPWMS_ACTIVE_CAPTURE_B(pEfpwmBase, param) \
  periphBitSet(EFPWM_CAPTCTRLx_ARMx, &((pEfpwmBase)->smcaptctrlb))

#define ioctlEFPWMS_CAPTURE_B_DISABLE(pEfpwmBase, param) \
  periphBitClear(EFPWM_CAPTCTRLx_ARMx, &((pEfpwmBase)->smcaptctrlb))

/* Capture Compare B Register */

#define ioctlEFPWMS_SET_COMPARE_B(pEfpwmBase, param) \
  periphMemWrite(((param)&EFPWM_CAPTCOMPx_EDGCMPx_MASK), &((pEfpwmBase)->smcaptcompb))

#define ioctlEFPWMS_READ_EDGE_COUNTER_B(pEfpwmBase, param) \
  ((periphMemRead( &((pEfpwmBase)->smcaptcompb) ))>>8)

/* Capture Control X Register */
#define ioctlEFPWMS_READ_CAPTURE_X1_FIFO_COUNT(pEfpwmBase, param) \
  ((periphMemRead( &((pEfpwmBase)->smcaptctrlx) )&EFPWM_CAPTCTRLx_Cx1CNT )>>13)

#define ioctlEFPWMS_READ_CAPTURE_X0_FIFO_COUNT(pEfpwmBase, param) \
  ((periphMemRead( &((pEfpwmBase)->smcaptctrlx) )&EFPWM_CAPTCTRLx_Cx0CNT )>>10)

#define ioctlEFPWMS_SET_CAPTURE_X_FIFO_WATERMARK(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_CAPTCTRLx_CFxWM, ((param)<<8) , &((pEfpwmBase)->smcaptctrlx))

#define ioctlEFPWMS_SET_EDGE_COUNTER_X(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CAPTCTRLx_EDGCNTx_EN, &((pEfpwmBase)->smcaptctrlx)); \
  else periphBitClear(EFPWM_CAPTCTRLx_EDGCNTx_EN, &((pEfpwmBase)->smcaptctrlx))

#define ioctlEFPWMS_SET_CAPTURE_X_INPUT(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CAPTCTRLx_INP_SETx, &((pEfpwmBase)->smcaptctrlx)); \
  else periphBitClear(EFPWM_CAPTCTRLx_INP_SETx, &((pEfpwmBase)->smcaptctrlx))

#define ioctlEFPWMS_SET_CAPTURE_X_1(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_CAPTCTRLx_EDGx1_MASK, (param) , &((pEfpwmBase)->smcaptctrlx))

#define ioctlEFPWMS_SET_CAPTURE_X_0(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_CAPTCTRLx_EDGx0_MASK, (param) , &((pEfpwmBase)->smcaptctrlx))

#define ioctlEFPWMS_SET_CAPTURE_X_MODE(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_CAPTCTRLx_ONESHOTX, &((pEfpwmBase)->smcaptctrlx)); \
  else periphBitClear(EFPWM_CAPTCTRLx_ONESHOTX, &((pEfpwmBase)->smcaptctrlx))

#define ioctlEFPWMS_ACTIVE_CAPTURE_X(pEfpwmBase, param) \
  periphBitSet(EFPWM_CAPTCTRLx_ARMx, &((pEfpwmBase)->smcaptctrlx))

#define ioctlEFPWMS_CAPTURE_X_DISABLE(pEfpwmBase, param) \
  periphBitClear(EFPWM_CAPTCTRLx_ARMx, &((pEfpwmBase)->smcaptctrlx))

/* Capture Compare X Register */

#define ioctlEFPWMS_SET_COMPARE_X(pEfpwmBase, param) \
  periphMemWrite(((param)&EFPWM_CAPTCOMPx_EDGCMPx_MASK), &((pEfpwmBase)->smcaptcompx))

#define ioctlEFPWMS_READ_EDGE_COUNTER_X(pEfpwmBase, param) \
  ((periphMemRead( &((pEfpwmBase)->smcaptcompx) ))>>8)

/* Capture Value Registers */
#define ioctlEFPWMS_READ_CAPTURE_VAL0(pEfpwmBase, param) \
  periphMemRead( &((pEfpwmBase)->smcval0) )

#define ioctlEFPWMS_READ_CAPTURE_VAL1(pEfpwmBase, param) \
  periphMemRead( &((pEfpwmBase)->smcval1) )

#define ioctlEFPWMS_READ_CAPTURE_VAL2(pEfpwmBase, param) \
  periphMemRead( &((pEfpwmBase)->smcval2) )

#define ioctlEFPWMS_READ_CAPTURE_VAL3(pEfpwmBase, param) \
  periphMemRead( &((pEfpwmBase)->smcval3) )

#define ioctlEFPWMS_READ_CAPTURE_VAL4(pEfpwmBase, param) \
  periphMemRead( &((pEfpwmBase)->smcval4) )

#define ioctlEFPWMS_READ_CAPTURE_VAL5(pEfpwmBase, param) \
  periphMemRead( &((pEfpwmBase)->smcval5) )

#if EFPWM_VERSION >= 2 
/*  Capture Value 1 Cycle Register  */
#define ioctlEFPWMS_READ_CAPTURE_CYCLE_VAL0(pEfpwmBase, param) \
  periphMemRead( &((pEfpwmBase)->smcval0cyc) )

#define ioctlEFPWMS_READ_CAPTURE_CYCLE_VAL1(pEfpwmBase, param) \
  periphMemRead( &((pEfpwmBase)->smcval1cyc) )

#define ioctlEFPWMS_READ_CAPTURE_CYCLE_VAL2(pEfpwmBase, param) \
  periphMemRead( &((pEfpwmBase)->smcval2cyc) )

#define ioctlEFPWMS_READ_CAPTURE_CYCLE_VAL3(pEfpwmBase, param) \
  periphMemRead( &((pEfpwmBase)->smcval3cyc) )

#define ioctlEFPWMS_READ_CAPTURE_CYCLE_VAL4(pEfpwmBase, param) \
  periphMemRead( &((pEfpwmBase)->smcval4cyc) )

#define ioctlEFPWMS_READ_CAPTURE_CYCLE_VAL5(pEfpwmBase, param) \
  periphMemRead( &((pEfpwmBase)->smcval5cyc) )
#endif

/* Common PWM Registers */
/* Output Enable Register */
#define ioctlEFPWM_SET_OUTPUTS_ENABLE(pEfpwmBase, param) \
  periphBitSet( (param)&(EFPWM_OUTEN_PWMA_EN_MASK | EFPWM_OUTEN_PWMB_EN_MASK | EFPWM_OUTEN_PWMX_EN_MASK) , &((pEfpwmBase)->outen))

#define ioctlEFPWM_SET_OUTPUTS_DISABLE(pEfpwmBase, param) \
  periphBitClear( (param)&(EFPWM_OUTEN_PWMA_EN_MASK | EFPWM_OUTEN_PWMB_EN_MASK | EFPWM_OUTEN_PWMX_EN_MASK) , &((pEfpwmBase)->outen))

#define ioctlEFPWM_WRITE_OUTPUT_ENABLE_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->outen))

#define ioctlEFPWM_READ_OUTPUT_ENABLE_REG(pEfpwmBase, param) \
  periphMemRead( &((pEfpwmBase)->outen))

#define ioctlEFPWM_SET_OUTPUTS(pEfpwmBase, param){ \
    register UWord16 __tmp = periphMemRead( &((pEfpwmBase)->outen)); \
    __tmp &= ~((~((UWord16) (param))) & ((UWord16)((UWord32)(param)>>16)) ); \
    __tmp |= ( ((UWord16) (param)) & ((UWord16)((UWord32)(param)>>16)) ); \
	periphMemWrite( __tmp, &((pEfpwmBase)->outen)); \
    }

/* Mask Register */
#if EFPWM_VERSION >= 3 
#define ioctlEFPWM_UPDATE_MASK_BITS_IMMEDIATELY(pEfpwmBase, param) \
  periphBitSet( (param)&(EFPWM_OUTEN_UPDATE_MASK_EN_MASK) , &((pEfpwmBase)->mask))

#define ioctlEFPWM_SET_MASK_ENABLE(pEfpwmBase, param) \
  periphBitSet( (param)&(EFPWM_OUTEN_PWMA_EN_MASK | EFPWM_OUTEN_PWMB_EN_MASK | EFPWM_OUTEN_PWMX_EN_MASK) , &((pEfpwmBase)->mask))

#define ioctlEFPWM_SET_MASK_DISABLE(pEfpwmBase, param) \
  periphBitClear( (param)&(EFPWM_OUTEN_PWMA_EN_MASK | EFPWM_OUTEN_PWMB_EN_MASK | EFPWM_OUTEN_PWMX_EN_MASK) , &((pEfpwmBase)->mask))

#else /* EFPWM_VERSION < 3  */  
#define ioctlEFPWM_SET_MASK_ENABLE(pEfpwmBase, param) \
  periphBitSet( (param)&( EFPWM_OUTEN_PWMA_EN_MASK | EFPWM_OUTEN_PWMB_EN_MASK | EFPWM_OUTEN_PWMX_EN_MASK) , &((pEfpwmBase)->mask))

#define ioctlEFPWM_SET_MASK_DISABLE(pEfpwmBase, param) \
  periphBitClear( (param)&( EFPWM_OUTEN_PWMA_EN_MASK | EFPWM_OUTEN_PWMB_EN_MASK | EFPWM_OUTEN_PWMX_EN_MASK) , &((pEfpwmBase)->mask))
#endif

#define ioctlEFPWM_WRITE_MASK_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->mask))

#define ioctlEFPWM_READ_MASK_REG(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->mask))

/* Software Controlled Output Register */
#define ioctlEFPWM_SET_FORCE_OUT_SW_SOURCE_TO_HIGH(pEfpwmBase, param) \
  periphBitSet( param, &((pEfpwmBase)->swcount))

#define ioctlEFPWM_SET_FORCE_OUT_SW_SOURCE_TO_LOW(pEfpwmBase, param) \
  periphBitClear( param, &((pEfpwmBase)->swcount))

#define ioctlEFPWM_SET_FORCE_OUT(pEfpwmBase, param) \
  periphBitGrpSet(((param)>>16), (param & 0xffff), &((pEfpwmBase)->dtsrcsel))

#define ioctlEFPWM_WRITE_SW_CONTROL_OUT_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->swcount))

#define ioctlEFPWM_READ_SW_CONTROL_OUT_REG(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->swcount))

/* Deadtime Source Select Register */
#define ioctlEFPWM_SET_SUB3_FORCE_OUT_PWM23(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_DTSRSEL_SM3SEL23_MASK, ((param)<<14) , &((pEfpwmBase)->dtsrcsel))

#define ioctlEFPWM_SET_SUB3_FORCE_OUT_PWM45(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_DTSRSEL_SM3SEL45_MASK, ((param)<<12) , &((pEfpwmBase)->dtsrcsel))

#define ioctlEFPWM_SET_SUB2_FORCE_OUT_PWM23(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_DTSRSEL_SM2SEL23_MASK, ((param)<<10) , &((pEfpwmBase)->dtsrcsel))

#define ioctlEFPWM_SET_SUB2_FORCE_OUT_PWM45(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_DTSRSEL_SM2SEL45_MASK, ((param)<<8) , &((pEfpwmBase)->dtsrcsel))

#define ioctlEFPWM_SET_SUB1_FORCE_OUT_PWM23(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_DTSRSEL_SM1SEL23_MASK, ((param)<<6) , &((pEfpwmBase)->dtsrcsel))

#define ioctlEFPWM_SET_SUB1_FORCE_OUT_PWM45(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_DTSRSEL_SM1SEL45_MASK, ((param)<<4) , &((pEfpwmBase)->dtsrcsel))

#define ioctlEFPWM_SET_SUB0_FORCE_OUT_PWM23(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_DTSRSEL_SM0SEL23_MASK, ((param)<<2) , &((pEfpwmBase)->dtsrcsel))

#define ioctlEFPWM_SET_SUB0_FORCE_OUT_PWM45(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_DTSRSEL_SM0SEL45_MASK, (param) , &((pEfpwmBase)->dtsrcsel))

#define ioctlEFPWM_WRITE_DEADTIME_SOURCE_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->dtsrcsel))

#define ioctlEFPWM_READ_DEADTIME_SOURCE_REG(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->dtsrcsel))

/* Master Control Register */
#define ioctlEFPWM_SET_CURRENT_POLARITY_TO_PWM23(pEfpwmBase, param) \
  periphBitClear( (((param)<<12)&EFPWM_MCTRL_IPOL_MASK), &((pEfpwmBase)->mctrl) )

#define ioctlEFPWM_SET_CURRENT_POLARITY_TO_PWM45(pEfpwmBase, param) \
  periphBitSet( (((param)<<12)&EFPWM_MCTRL_IPOL_MASK), &((pEfpwmBase)->mctrl) )

#define ioctlEFPWM_SET_PWM_CLOCK_ENABLE(pEfpwmBase, param) \
  periphBitSet( (((param)<<8)&EFPWM_MCTRL_RUN_MASK), &((pEfpwmBase)->mctrl) )

#define ioctlEFPWM_SET_PWM_CLOCK_DISABLE(pEfpwmBase, param) \
  periphBitClear( (((param)<<8)&EFPWM_MCTRL_RUN_MASK), &((pEfpwmBase)->mctrl) )

#define ioctlEFPWM_CLEAR_LOAD_OK(pEfpwmBase, param) \
  periphBitSet( (((param)<<4)&EFPWM_MCTRL_CLDOK_MASK), &((pEfpwmBase)->mctrl) )

#define ioctlEFPWM_SET_LOAD_OK(pEfpwmBase, param) \
  periphBitSet( ((param)&EFPWM_MCTRL_LDOK_MASK), &((pEfpwmBase)->mctrl) )

#define ioctlEFPWM_WRITE_MASTER_CONTROL_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->mctrl))

#define ioctlEFPWM_READ_MASTER_CONTROL_REG(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->mctrl))

/* Master Control Register 2 (only PWMB module does not have this register) */
#define ioctlEFPWM_MONITOR_PLL(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_MCTRL2_MONPLL_MASK, param , &((pEfpwmBase)->mctrl2))

/* Fault Control Register */
#define ioctlEFPWM_SET_ACTIVE_HIGH_FAULTS(pEfpwmBase, param) \
  periphBitSet( (((param)<<12)&EFPWM_FCTRL_FLVL_MASK), &((pEfpwmBase)->fctrl) )

#define ioctlEFPWM_SET_ACTIVE_LOW_FAULTS(pEfpwmBase, param) \
  periphBitClear( (((param)<<12)&EFPWM_FCTRL_FLVL_MASK), &((pEfpwmBase)->fctrl) )

#define ioctlEFPWM_SET_AUTOMATIC_FAULT_CLEAR(pEfpwmBase, param) \
  periphBitSet( (((param)<<8)&EFPWM_FCTRL_FAUTO_MASK), &((pEfpwmBase)->fctrl) )

#define ioctlEFPWM_SET_MANUAL_FAULT_CLEAR(pEfpwmBase, param) \
  periphBitClear( (((param)<<8)&EFPWM_FCTRL_FAUTO_MASK), &((pEfpwmBase)->fctrl) )

#define ioctlEFPWM_SET_FAULT_SAFETY_MODE(pEfpwmBase, param) \
  periphBitSet( (((param)<<4)&EFPWM_FCTRL_FSAFE_MASK), &((pEfpwmBase)->fctrl) )

#define ioctlEFPWM_SET_FAULT_NORMAL_MODE(pEfpwmBase, param) \
  periphBitClear( (((param)<<4)&EFPWM_FCTRL_FSAFE_MASK), &((pEfpwmBase)->fctrl) )

#define ioctlEFPWM_FAULT_INT_ENABLE(pEfpwmBase, param) \
  periphBitSet( ((param)&EFPWM_FCTRL_FIE_MASK), &((pEfpwmBase)->fctrl) )

#define ioctlEFPWM_FAULT_INT_DISABLE(pEfpwmBase, param) \
  periphBitClear( ((param)&EFPWM_FCTRL_FIE_MASK), &((pEfpwmBase)->fctrl) )

#define ioctlEFPWM_WRITE_FAULT_CONTROL_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->fctrl))

#define ioctlEFPWM_READ_FAULT_CONTROL_REG(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->fctrl))

#if EFPWM_VERSION >= 2
#define ioctlEFPWM_SET_ACTIVE_HIGH_FAULTS0(pEfpwmBase, param) \
  periphBitSet( (((param)<<12)&EFPWM_FCTRL_FLVL_MASK), &((pEfpwmBase)->fctrl0) )

#define ioctlEFPWM_SET_ACTIVE_HIGH_FAULTS1(pEfpwmBase, param) \
  periphBitSet( (((param)<<12)&EFPWM_FCTRL_FLVL_MASK), &((pEfpwmBase)->fctrl1) )

#define ioctlEFPWM_SET_ACTIVE_LOW_FAULTS0(pEfpwmBase, param) \
  periphBitClear( (((param)<<12)&EFPWM_FCTRL_FLVL_MASK), &((pEfpwmBase)->fctrl0) )

#define ioctlEFPWM_SET_ACTIVE_LOW_FAULTS1(pEfpwmBase, param) \
  periphBitClear( (((param)<<12)&EFPWM_FCTRL_FLVL_MASK), &((pEfpwmBase)->fctrl1) )

#define ioctlEFPWM_SET_AUTOMATIC_FAULT0_CLEAR(pEfpwmBase, param) \
  periphBitSet( (((param)<<8)&EFPWM_FCTRL_FAUTO_MASK), &((pEfpwmBase)->fctrl0) )

#define ioctlEFPWM_SET_AUTOMATIC_FAULT1_CLEAR(pEfpwmBase, param) \
  periphBitSet( (((param)<<8)&EFPWM_FCTRL_FAUTO_MASK), &((pEfpwmBase)->fctrl1) )

#define ioctlEFPWM_SET_MANUAL_FAULT0_CLEAR(pEfpwmBase, param) \
  periphBitClear( (((param)<<8)&EFPWM_FCTRL_FAUTO_MASK), &((pEfpwmBase)->fctrl0) )

#define ioctlEFPWM_SET_MANUAL_FAULT1_CLEAR(pEfpwmBase, param) \
  periphBitClear( (((param)<<8)&EFPWM_FCTRL_FAUTO_MASK), &((pEfpwmBase)->fctrl1) )

#define ioctlEFPWM_SET_FAULT0_SAFETY_MODE(pEfpwmBase, param) \
  periphBitSet( (((param)<<4)&EFPWM_FCTRL_FSAFE_MASK), &((pEfpwmBase)->fctrl0) )

#define ioctlEFPWM_SET_FAULT1_SAFETY_MODE(pEfpwmBase, param) \
  periphBitSet( (((param)<<4)&EFPWM_FCTRL_FSAFE_MASK), &((pEfpwmBase)->fctrl1) )

#define ioctlEFPWM_SET_FAULT0_NORMAL_MODE(pEfpwmBase, param) \
  periphBitClear( (((param)<<4)&EFPWM_FCTRL_FSAFE_MASK), &((pEfpwmBase)->fctrl0) )

#define ioctlEFPWM_SET_FAULT1_NORMAL_MODE(pEfpwmBase, param) \
  periphBitClear( (((param)<<4)&EFPWM_FCTRL_FSAFE_MASK), &((pEfpwmBase)->fctrl1) )

#define ioctlEFPWM_FAULT0_INT_ENABLE(pEfpwmBase, param) \
  periphBitSet( ((param)&EFPWM_FCTRL_FIE_MASK), &((pEfpwmBase)->fctrl0) )

#define ioctlEFPWM_FAULT1_INT_ENABLE(pEfpwmBase, param) \
  periphBitSet( ((param)&EFPWM_FCTRL_FIE_MASK), &((pEfpwmBase)->fctrl1) )

#define ioctlEFPWM_FAULT0_INT_DISABLE(pEfpwmBase, param) \
  periphBitClear( ((param)&EFPWM_FCTRL_FIE_MASK), &((pEfpwmBase)->fctrl0) )

#define ioctlEFPWM_FAULT1_INT_DISABLE(pEfpwmBase, param) \
  periphBitClear( ((param)&EFPWM_FCTRL_FIE_MASK), &((pEfpwmBase)->fctrl1) )

#define ioctlEFPWM_WRITE_FAULT0_CONTROL_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->fctrl0))

#define ioctlEFPWM_WRITE_FAULT1_CONTROL_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->fctrl1))

#define ioctlEFPWM_READ_FAULT0_CONTROL_REG(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->fctrl0))

#define ioctlEFPWM_READ_FAULT1_CONTROL_REG(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->fctrl1))

#endif

/* Fault Status Register */

#if EFPWM_VERSION == 1
#define ioctlEFPWM_CLEAR_FAULT_TEST(pEfpwmBase, param) \
  periphSafeBitClear( EFPWM_FSTS_FFLAG_MASK, EFPWM_FSTS_TEST, &((pEfpwmBase)->fsts) )
#else EFPWM_VERSION >= 2
#define ioctlEFPWM_CLEAR_FAULT_TEST(pEfpwmBase, param) \
  periphBitClear( EFPWM_FTST_TEST, &((pEfpwmBase)->ftst0) )
#endif

#define ioctlEFPWM_TEST_FAULT_PINS(pEfpwmBase, param) \
  periphBitTest( (((param)<<8)&EFPWM_FSTS_FFPIN_MASK), &((pEfpwmBase)->fsts) )

#define ioctlEFPWM_SET_FAULT_FULL_CYCLE(pEfpwmBase, param) \
  periphSafeBitSet(EFPWM_FSTS_FFLAG_MASK, ( ((param)<<4)&EFPWM_FSTS_FFULL_MASK), &((pEfpwmBase)->fsts) )

#define ioctlEFPWM_SET_FAULT_HALF_FULL_CYCLE(pEfpwmBase, param) \
  periphSafeBitClear(EFPWM_FSTS_FFLAG_MASK, ( ((param)<<4)&EFPWM_FSTS_FFULL_MASK), &((pEfpwmBase)->fsts) )

        #define ioctlEFPWM_TEST_FAULT_FLAGS(pEfpwmBase, param) \
          periphBitTest( ((param)&EFPWM_FSTS_FFLAG_MASK), &((pEfpwmBase)->fsts) )

#define ioctlEFPWM_CLEAR_FAULT_FLAGS(pEfpwmBase, param) \
  periphSafeAckByOne( EFPWM_FSTS_FFLAG_MASK, ((param)&EFPWM_FSTS_FFLAG_MASK), &((pEfpwmBase)->fsts) )

#define ioctlEFPWM_WRITE_FAULT_STATUS_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->fsts))

#define ioctlEFPWM_READ_FAULT_STATUS_REG(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->fsts))


/* Fault Filter Register */
#define ioctlEFPWM_FAULT_GLITCH_STRETCH(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_FFILT_GSTR, &((pEfpwmBase)->ffilt)); \
  else periphBitClear(EFPWM_FFILT_GSTR, &((pEfpwmBase)->ffilt))

#define ioctlEFPWM_FAULT_FILTER_COUNTER(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_FFILT_FILT_CNT_MASK, ((param)<<8) , &((pEfpwmBase)->ffilt))

#define ioctlEFPWM_FAULT_FILTER_PERIOD(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_FFILT_FILT_PER_MASK, param , &((pEfpwmBase)->ffilt))

#if EFPWM_VERSION >= 2
#define ioctlEFPWM_ACTIVE_FAULT0_TEST(pEfpwmBase, param) \
  periphSafeBitSet( EFPWM_FSTS_FFLAG_MASK, EFPWM_FSTS_TEST, &((pEfpwmBase)->fsts0) )

#define ioctlEFPWM_CLEAR_FAULT0_TEST(pEfpwmBase, param) \
  periphSafeBitClear( EFPWM_FSTS_FFLAG_MASK, EFPWM_FSTS_TEST, &((pEfpwmBase)->fsts0) )

#define ioctlEFPWM_TEST_FAULT0_PINS(pEfpwmBase, param) \
  periphBitTest( (((param)<<8)&EFPWM_FSTS_FFPIN_MASK), &((pEfpwmBase)->fsts0) )

#define ioctlEFPWM_SET_FAULT0_FULL_CYCLE(pEfpwmBase, param) \
  periphSafeBitSet(EFPWM_FSTS_FFLAG_MASK, ( ((param)<<4)&EFPWM_FSTS_FFULL_MASK), &((pEfpwmBase)->fsts0) )

#define ioctlEFPWM_SET_FAULT0_HALF_FULL_CYCLE(pEfpwmBase, param) \
  periphSafeBitClear(EFPWM_FSTS_FFLAG_MASK, ( ((param)<<4)&EFPWM_FSTS_FFULL_MASK), &((pEfpwmBase)->fsts0) )

#define ioctlEFPWM_TEST_FAULT0_FLAGS(pEfpwmBase, param) \
  periphBitTest( ((param)&EFPWM_FSTS_FFLAG_MASK), &((pEfpwmBase)->fsts0) )

#define ioctlEFPWM_CLEAR_FAULT0_FLAGS(pEfpwmBase, param) \
  periphSafeAckByOne( EFPWM_FSTS_FFLAG_MASK, ((param)&EFPWM_FSTS_FFLAG_MASK), &((pEfpwmBase)->fsts0) )

#define ioctlEFPWM_WRITE_FAULT0_STATUS_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->fsts0))

#define ioctlEFPWM_READ_FAULT0_STATUS_REG(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->fsts0))

#define ioctlEFPWM_ACTIVE_FAULT1_TEST(pEfpwmBase, param) \
  periphSafeBitSet( EFPWM_FSTS_FFLAG_MASK, EFPWM_FSTS_TEST, &((pEfpwmBase)->fsts1) )

#define ioctlEFPWM_CLEAR_FAULT1_TEST(pEfpwmBase, param) \
  periphSafeBitClear( EFPWM_FSTS_FFLAG_MASK, EFPWM_FSTS_TEST, &((pEfpwmBase)->fsts1) )

#define ioctlEFPWM_TEST_FAULT1_PINS(pEfpwmBase, param) \
  periphBitTest( (((param)<<8)&EFPWM_FSTS_FFPIN_MASK), &((pEfpwmBase)->fsts1) )

#define ioctlEFPWM_SET_FAULT1_FULL_CYCLE(pEfpwmBase, param) \
  periphSafeBitSet(EFPWM_FSTS_FFLAG_MASK, ( ((param)<<4)&EFPWM_FSTS_FFULL_MASK), &((pEfpwmBase)->fsts1) )

#define ioctlEFPWM_SET_FAULT1_HALF_FULL_CYCLE(pEfpwmBase, param) \
  periphSafeBitClear(EFPWM_FSTS_FFLAG_MASK, ( ((param)<<4)&EFPWM_FSTS_FFULL_MASK), &((pEfpwmBase)->fsts1) )

#define ioctlEFPWM_TEST_FAULT1_FLAGS(pEfpwmBase, param) \
  periphBitTest( ((param)&EFPWM_FSTS_FFLAG_MASK), &((pEfpwmBase)->fsts1) )

#define ioctlEFPWM_CLEAR_FAULT1_FLAGS(pEfpwmBase, param) \
  periphSafeAckByOne( EFPWM_FSTS_FFLAG_MASK, ((param)&EFPWM_FSTS_FFLAG_MASK), &((pEfpwmBase)->fsts1) )

#define ioctlEFPWM_WRITE_FAULT1_STATUS_REG(pEfpwmBase, param) \
  periphMemWrite(param, &((pEfpwmBase)->fsts1))

#define ioctlEFPWM_READ_FAULT1_STATUS_REG(pEfpwmBase, param) \
  periphMemRead(&((pEfpwmBase)->fsts1))

/* Fault Filter Register */
#define ioctlEFPWM_FAULT0_GLITCH_STRETCH(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_FFILT_GSTR, &((pEfpwmBase)->ffilt0)); \
  else periphBitClear(EFPWM_FFILT_GSTR, &((pEfpwmBase)->ffilt0))

#define ioctlEFPWM_FAULT0_FILTER_COUNTER(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_FFILT_FILT_CNT_MASK, ((param)<<8) , &((pEfpwmBase)->ffilt0))

#define ioctlEFPWM_FAULT0_FILTER_PERIOD(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_FFILT_FILT_PER_MASK, param , &((pEfpwmBase)->ffilt0))

#define ioctlEFPWM_FAULT1_GLITCH_STRETCH(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_FFILT_GSTR, &((pEfpwmBase)->ffilt1)); \
  else periphBitClear(EFPWM_FFILT_GSTR, &((pEfpwmBase)->ffilt1))

#define ioctlEFPWM_FAULT1_FILTER_COUNTER(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_FFILT_FILT_CNT_MASK, ((param)<<8) , &((pEfpwmBase)->ffilt1))

#define ioctlEFPWM_FAULT1_FILTER_PERIOD(pEfpwmBase, param) \
  periphBitGrpSet(EFPWM_FFILT_FILT_PER_MASK, param , &((pEfpwmBase)->ffilt1))

#endif
#if EFPWM_VERSION >= 2 
/* Fault0 Test Register (PWMA_FTSTn) */
#define ioctlEFPWM_FAULT0_TEST(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_FTEST_MASK, &((pEfpwmBase)->ftst0)); \
  else periphBitClear(EFPWM_FTEST_MASK, &((pEfpwmBase)->ftst0))

/* Fault1 Test Register (PWMA_FTSTn) */
#define ioctlEFPWM_FAULT1_TEST(pEfpwmBase, param) \
  if (param) periphBitSet(EFPWM_FTEST_MASK, &((pEfpwmBase)->ftst1)); \
  else periphBitClear(EFPWM_FTEST_MASK, &((pEfpwmBase)->ftst1))
#endif

/*  */
#define ioctlEFPWMS_SET_CENTER_ALIGN_MODULO_INIT_REG(pEfpwmBase, param) \
  { register Word16 sTempModulus = (((UWord16)param)>>1); \
  	periphMemWrite( (sTempModulus)-1, &((pEfpwmBase)->smval1)); \
    periphMemWrite( -(sTempModulus), &((pEfpwmBase)->sminit));}
 

#define ioctlEFPWMS_CENTER_ALIGN_WRITE_CHANNEL_23(pEfpwmBase, param) \
  { periphMemWrite( param, &((pEfpwmBase)->smval3)); \
    periphMemWrite( -(param), &((pEfpwmBase)->smval2));}

#define ioctlEFPWMS_CENTER_ALIGN_WRITE_CHANNEL_45(pEfpwmBase, param) \
  { periphMemWrite( param, &((pEfpwmBase)->smval5)); \
    periphMemWrite( -(param), &((pEfpwmBase)->smval4));}


#define ioctlEFPWMS_CENTER_ALIGN_UPDATE_CHANNEL_23(pEfpwmBase, param) \
  { Word16 sTempModulus; \
	sTempModulus = mult_r( (Word16) periphMemRead(&((pEfpwmBase)->smval1))+1, param);\
	periphMemWrite( sTempModulus, &((pEfpwmBase)->smval3)); \
    periphMemWrite( -(sTempModulus), &((pEfpwmBase)->smval2));}


#define ioctlEFPWMS_CENTER_ALIGN_UPDATE_CHANNEL_45(pEfpwmBase, param) \
  { Word16 sTempModulus; \
	sTempModulus = mult_r( (Word16) periphMemRead(&((pEfpwmBase)->smval1))+1, param);\
	periphMemWrite( sTempModulus, &((pEfpwmBase)->smval5)); \
    periphMemWrite( -(sTempModulus), &((pEfpwmBase)->smval4));}


#define ioctlEFPWMS_CENTER_ALIGN_UPDATE_CHANNEL_23_FRAC(pEfpwmBase, param) \
  { Word32 sTempVar; \
	sTempVar =__L_shrtNs(__L_mult( (periphMemRead((Word16*)&((pEfpwmBase)->smval1))+1)<<5, param),5);\
   	periphMemWrite(  sTempVar, (Word32*) &((pEfpwmBase)->smfracval3)); \
   	periphMemWrite(  -sTempVar, (Word32*) &((pEfpwmBase)->smfracval2));}

#define ioctlEFPWMS_CENTER_ALIGN_UPDATE_CHANNEL_45_FRAC(pEfpwmBase, param) \
  { Word32 sTempVar; \
	sTempVar =__L_shrtNs(__L_mult( (periphMemRead((Word16*)&((pEfpwmBase)->smval1))+1)<<5, param),5);\
   	periphMemWrite(  sTempVar, (Word32*) &((pEfpwmBase)->smfracval5)); \
   	periphMemWrite(  -sTempVar, (Word32*) &((pEfpwmBase)->smfracval4));}


#define ioctlEFPWM_CENTER_ALIGN_UPDATE_VALUE_REGS_COMPL_012(pEfpwmBase, param) \
  { Word16 TempModulus,TempVar;  \
    TempModulus = (Word16) periphMemRead(&((pEfpwmBase)->Sub0.smval1))+1; \
    TempVar=mult_r( TempModulus, ((pwm_sComplementaryValues*)(param))->pwmSub_0_Channel_23_Value);\
	periphMemWrite( TempVar, &((pEfpwmBase)->Sub0.smval3)); \
    periphMemWrite( -TempVar, &((pEfpwmBase)->Sub0.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sComplementaryValues*)(param))->pwmSub_1_Channel_23_Value);\
	periphMemWrite( TempVar, &((pEfpwmBase)->Sub1.smval3)); \
    periphMemWrite( -TempVar, &((pEfpwmBase)->Sub1.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sComplementaryValues*)(param))->pwmSub_2_Channel_23_Value);\
	periphMemWrite( TempVar, &((pEfpwmBase)->Sub2.smval3)); \
    periphMemWrite( -TempVar, &((pEfpwmBase)->Sub2.smval2)); \
    periphBitSet(EFPWM_SUBMODULE_0|EFPWM_SUBMODULE_1|EFPWM_SUBMODULE_2, &((pEfpwmBase)->mctrl)); }

#define ioctlEFPWM_CENTER_ALIGN_UPDATE_VALUE_REGS_COMPL_013(pEfpwmBase, param) \
  { Word16 TempModulus,TempVar;  \
    TempModulus = (Word16) periphMemRead(&((pEfpwmBase)->Sub0.smval1))+1; \
    TempVar=mult_r( TempModulus, ((pwm_sComplementaryValues*)(param))->pwmSub_0_Channel_23_Value);\
	periphMemWrite( TempVar, &((pEfpwmBase)->Sub0.smval3)); \
    periphMemWrite( -TempVar, &((pEfpwmBase)->Sub0.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sComplementaryValues*)(param))->pwmSub_1_Channel_23_Value);\
	periphMemWrite( TempVar, &((pEfpwmBase)->Sub1.smval3)); \
    periphMemWrite( -TempVar, &((pEfpwmBase)->Sub1.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sComplementaryValues*)(param))->pwmSub_2_Channel_23_Value);\
	periphMemWrite( TempVar, &((pEfpwmBase)->Sub3.smval3)); \
    periphMemWrite( -TempVar, &((pEfpwmBase)->Sub3.smval2)); \
    periphBitSet(EFPWM_SUBMODULE_0|EFPWM_SUBMODULE_1|EFPWM_SUBMODULE_3, &((pEfpwmBase)->mctrl)); }

#define ioctlEFPWM_CENTER_ALIGN_UPDATE_VALUE_REGS_COMPL_023(pEfpwmBase, param) \
  { Word16 TempModulus,TempVar;  \
    TempModulus = (Word16) periphMemRead(&((pEfpwmBase)->Sub0.smval1))+1; \
    TempVar=mult_r( TempModulus, ((pwm_sComplementaryValues*)(param))->pwmSub_0_Channel_23_Value);\
	periphMemWrite( TempVar, &((pEfpwmBase)->Sub0.smval3)); \
    periphMemWrite( -TempVar, &((pEfpwmBase)->Sub0.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sComplementaryValues*)(param))->pwmSub_1_Channel_23_Value);\
	periphMemWrite( TempVar, &((pEfpwmBase)->Sub2.smval3)); \
    periphMemWrite( -TempVar, &((pEfpwmBase)->Sub2.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sComplementaryValues*)(param))->pwmSub_2_Channel_23_Value);\
	periphMemWrite( TempVar, &((pEfpwmBase)->Sub3.smval3)); \
    periphMemWrite( -TempVar, &((pEfpwmBase)->Sub3.smval2)); \
    periphBitSet(EFPWM_SUBMODULE_0|EFPWM_SUBMODULE_2|EFPWM_SUBMODULE_3, &((pEfpwmBase)->mctrl)); }


#define ioctlEFPWMS_SET_EDGE_ALIGN_MODULO_INIT_REG(pEfpwmBase, param) \
  { periphMemWrite( (param)-1, &((pEfpwmBase)->smval1)); \
    periphMemWrite( 0, &((pEfpwmBase)->sminit));}

#define ioctlEFPWMS_EDGE_ALIGN_WRITE_CHANNEL_23(pEfpwmBase, param) \
  {	periphMemWrite( 0, &((pEfpwmBase)->smval2)); \
    periphMemWrite( param, &((pEfpwmBase)->smval3));}

#define ioctlEFPWMS_EDGE_ALIGN_WRITE_CHANNEL_45(pEfpwmBase, param) \
  {	periphMemWrite( 0, &((pEfpwmBase)->smval4)); \
    periphMemWrite( param, &((pEfpwmBase)->smval5));}

#define ioctlEFPWMS_EDGE_ALIGN_UPDATE_CHANNEL_23(pEfpwmBase, param) \
  {	periphMemWrite( 0, &((pEfpwmBase)->smval2)); \
    periphMemWrite( mult_r( (Word16) (periphMemRead(&((pEfpwmBase)->smval1))+1), param), &((pEfpwmBase)->smval3));}

#define ioctlEFPWMS_EDGE_ALIGN_UPDATE_CHANNEL_45(pEfpwmBase, param) \
  {	periphMemWrite( 0, &((pEfpwmBase)->smval4)); \
    periphMemWrite( mult_r( (Word16) (periphMemRead(&((pEfpwmBase)->smval1))+1), param), &((pEfpwmBase)->smval5));}

#define ioctlEFPWMS_EDGE_ALIGN_UPDATE_CHANNEL_23_FRAC(pEfpwmBase, param) \
  {	periphMemWrite( 0, (Word32*) &((pEfpwmBase)->smfracval2)); \
   	periphMemWrite( (Word32) __L_shrtNs(__L_mult( ((periphMemRead((Word16*)&((pEfpwmBase)->smval1)))+1)<<5, param),5), (Word32*) &((pEfpwmBase)->smfracval3));}

#define ioctlEFPWMS_EDGE_ALIGN_UPDATE_CHANNEL_45_FRAC(pEfpwmBase, param) \
  {	periphMemWrite( 0, (Word32*) &((pEfpwmBase)->smfracval4)); \
   	periphMemWrite( (Word32) __L_shrtNs(__L_mult( ((periphMemRead((Word16*)&((pEfpwmBase)->smval1)))+1)<<5, param),5), (Word32*) &((pEfpwmBase)->smfracval5));}

#define ioctlEFPWM_EDGE_ALIGN_UPDATE_VALUE_REGS_INDEP_012(pEfpwmBase, param) \
  { Word16 TempModulus,TempVar;  \
    TempModulus = (Word16) periphMemRead(&((pEfpwmBase)->Sub0.smval1))+1; \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_0_Channel_23_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub0.smval3)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub0.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_0_Channel_45_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub0.smval5)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub0.smval4)); \
	TempModulus = (Word16) periphMemRead(&((pEfpwmBase)->Sub1.smval1))+1; \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_1_Channel_23_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub1.smval3)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub1.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_1_Channel_45_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub1.smval5)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub1.smval4)); \
	TempModulus = (Word16) periphMemRead(&((pEfpwmBase)->Sub2.smval1))+1; \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_2_Channel_23_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub2.smval3)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub2.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_2_Channel_45_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub2.smval5)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub2.smval4)); \
    periphBitSet(EFPWM_SUBMODULE_0|EFPWM_SUBMODULE_1|EFPWM_SUBMODULE_2, &((pEfpwmBase)->mctrl)); }

#define ioctlEFPWM_EDGE_ALIGN_UPDATE_VALUE_REGS_INDEP_013(pEfpwmBase, param) \
  { Word16 TempModulus,TempVar;  \
    TempModulus = (Word16) periphMemRead(&((pEfpwmBase)->Sub0.smval1))+1; \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_0_Channel_23_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub0.smval3)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub0.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_0_Channel_45_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub0.smval5)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub0.smval4)); \
	TempModulus = (Word16) periphMemRead(&((pEfpwmBase)->Sub1.smval1))+1; \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_1_Channel_23_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub1.smval3)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub1.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_1_Channel_45_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub1.smval5)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub1.smval4)); \
	TempModulus = (Word16) periphMemRead(&((pEfpwmBase)->Sub3.smval1))+1; \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_2_Channel_23_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub3.smval3)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub3.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_2_Channel_45_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub3.smval5)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub3.smval4)); \
    periphBitSet(EFPWM_SUBMODULE_0|EFPWM_SUBMODULE_1|EFPWM_SUBMODULE_3, &((pEfpwmBase)->mctrl)); }

#define ioctlEFPWM_EDGE_ALIGN_UPDATE_VALUE_REGS_INDEP_023(pEfpwmBase, param) \
  { Word16 TempModulus,TempVar;  \
    TempModulus = (Word16) periphMemRead(&((pEfpwmBase)->Sub0.smval1))+1; \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_0_Channel_23_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub0.smval3)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub0.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_0_Channel_45_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub0.smval5)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub0.smval4)); \
	TempModulus = (Word16) periphMemRead(&((pEfpwmBase)->Sub2.smval1))+1; \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_1_Channel_23_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub2.smval3)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub2.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_1_Channel_45_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub2.smval5)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub2.smval4)); \
	TempModulus = (Word16) periphMemRead(&((pEfpwmBase)->Sub3.smval1))+1; \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_2_Channel_23_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub3.smval3)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub3.smval2)); \
    TempVar=mult_r( TempModulus, ((pwm_sIndependentValues*)(param))->pwmSub_2_Channel_45_Value);\
    periphMemWrite( TempVar, &((pEfpwmBase)->Sub3.smval5)); \
    periphMemWrite( 0, &((pEfpwmBase)->Sub3.smval4)); \
    periphBitSet(EFPWM_SUBMODULE_0|EFPWM_SUBMODULE_2|EFPWM_SUBMODULE_3, &((pEfpwmBase)->mctrl)); }

  
#ifdef __cplusplus
}
#endif

#endif
