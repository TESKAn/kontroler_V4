/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  ewm.h
*
* $Date:      May-7-2013$
*
* $Version:   2.5.3.0$
*
* Description: Header file for External Watchdog Monitor (EWM)
*
* This file supports different hardware versions of the module. A version
* of module used in your project is defined in the "arch.h" processor 
* architecture definition file.
*
*  EWM_VERSION_1 .. 56F84xxx and 56F82xxx devices, see MC56F844xxRM.pdf, MC56F82xxxRM.pdf

*
*****************************************************************************/

#ifndef __EWM_H
#define __EWM_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before ewm.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************
* EWM module identifier, corresponds to module base address
*************************************************************/

#define EWM (&ArchIO.Ewm)

/*************************************************************
* arch.h should define device-specific information about EWM
**************************************************************/

#if !defined(EWM_VERSION)
#error EWM not properly described in arch.h (old Quick_Start version?)
#endif

/******************************************************************************
*
*                      General Interface Description
*
*
* The watchdog is generally used to monitor the flow and execution of embedded software
* within an MCU. The watchdog consists of a counter that if allowed to overflow, forces an
* internal reset (asynchronous) to all on-chip peripherals and optionally assert the RESET
* pin to reset external devices/circuits. The overflow of the watchdog counter must not
* occur if the software code works well and services the watchdog to re-start the actual
* counter.
* For safety, a redundant watchdog system, External Watchdog Monitor (EWM), is
* designed to monitor external circuits, as well as the MCU software flow. This provides a
* back-up mechanism to the internal watchdog that resets the MCU's CPU and peripherals.
*
* For more information, please refer to the user manual for the particular
* chip that you are using.
*
* The EWM device driver interface uses "ioctl" call to control specific
* EWM functions during operation. For details see "ioctl" call.
*
******************************************************************************/

/***********************************************************************
* EWM static configuration items for appconfig.h
***********************************************************************/
/*

#define    EWM_CLKPRESCALER_INIT     0x0000
#define    EWM_CLKCTRL_INIT          0x0000
#define    EWM_CMPL_INIT             0x0000
#define    EWM_CMPH_INIT             0x0000
#define    EWM_CTRL_INIT             0x0000

//New name for control register
#ifdef EWM_CTRL_INIT
#define EWM_CTRL_INIT EWM_CTRL_INIT
#endif


/*****************************************************************
* Single-Instruction ioctl() commands
*
*  Word16 ioctl( EWM_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/

/******************************************************    NOTE     *************************************************/
/* If the EWM was initialized before, some commands may be inactive because some register can be written only once. */ 


#define EWM_SELECT_CLK          /* EWM_xxx (xxx=ROSC_8M/XTAL_OSC/EWM_BUS_CLK/EWM_ROSC_32K), select the low power clock sources for running the EWM counter. Register can be writen only once after CPU reset. Modifying these bits more than once, generates a bus transfer error. (CLKCTRL->CLKSEL) */
#define EWM_SET_PRESCALER       /* UWORD16 value 0-255, set the EWM the prescaler value. Call this command before enabling the EWM. The register can be writen only once after CPU reset. Modifying these bits more than once, generates a bus transfer error.(CLKPRESCALER->CLK_DIV)*/
#define EWM_DEVICE_CONFIG       /* combinantion of EWM_xxx (xxx=INPUT_ENABLED|EWM_INT_ENABLED|EWM_ASERTION_ONE|EWM_DEVICE_ENABLE), configure the EWM device. The command may be used only once, for next time reset is needed, because register can be writen only once after CPU reset. Modifying these bits more than once, generates a bus transfer error. (CTRL->INTEN, INEN, ASSIN, EWMEN) */
#define EWM_WRITE_SERVICE_REG   /* UWord16 value 0-255, write the Service register. The EWM service mechanism requires the CPU to write two values to the SERV register: a first data byte of 0xB4, followed by a second data byte of 0x2C. (SERV->SERVICE) */
#define EWM_WRITE_COMPAREL_REG  /* UWord16 value 0-255, set the minimum time to service the EWM counter. This register can be written only once after a CPU reset (CMPL->COMPAREL) */
#define EWM_WRITE_COMPAREH_REG  /* UWord16 value 0-255, set the maximum time to service the EWM counter. The expiration happens only if EWM counter is greater than CMPH. This register can be written only once after a CPU reset. (CMPH->COMPAREH) */
#define EWM_READ_COMPAREL_REG   /* NULL, read and return the value of the Compare Low Register (CMPL->_)*/
#define EWM_READ_COMPAREH_REG   /* NULL, read and return the value of the Compare High Register (CMPH->_)*/


/*****************************************************************
* Multi-Instruction ioctl() commands
*
*  Word16 ioctl( EWM_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define EWM_CLEAR_COUNTER       /* NULL, clear/service the EWM counter (both steps are performed) (SERV->SERVICE) */


/*****************************************************************
* Software Layer ioctl() commands
*
*  Word16 ioctl( EWM_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define EWM_INIT                /* NULL, initialize the EWM (External watchdog monitor) periheral registers using the appconfig.h _INIT values */


/****************************************************************************
* EWM constants and type declarations used in the ioctl functions
*****************************************************************************/

#define EWM_ENABLE       1
#define EWM_DISABLE      0

#define EWM_LOGIC_ONE    1
#define EWM_LOGIC_ZERO   0

#define EWM_LPO_CLK_0    0
#define EWM_LPO_CLK_1    1
#define EWM_LPO_CLK_2    2
#define EWM_LPO_CLK_3    3

#define EWM_ROSC_8M     EWM_LPO_CLK_0
#define EWM_XTAL_OSC    EWM_LPO_CLK_1
#define EWM_BUS_CLK     EWM_LPO_CLK_2
#define EWM_ROSC_32K    EWM_LPO_CLK_3

#define EWM_INT_ENABLED         EWM_CTRL_INTEN 
#define EWM_INPUT_ENABLED       EWM_CTRL_INEN  
#define EWM_ASERTION_ONE        EWM_CTRL_ASSIN 
#define EWM_DEVICE_ENABLE       EWM_CTRL_EWMEN 


//#endif
/****************************************************************************
* EWM registers and bits
*****************************************************************************/

/* control register */
#define EWM_CTRL_INTEN          0x0008
#define EWM_CTRL_INEN           0x0004
#define EWM_CTRL_ASSIN          0x0002
#define EWM_CTRL_EWMEN          0x0001

#define EWM_CLKCTRL_CLKSEL      0x0003

/***********************************************************************
* EWM control command macros
***********************************************************************/

/* EWM initialization */
void ewmInit(arch_sEWM *pEwmBase);
#define ioctlEWM_INIT(pEwmBase, param) ewmInit(pEwmBase)

#define ioctlEWM_DEVICE_CONFIG(pEwmBase, param) \
  periphMemWrite(param, &((pEwmBase)->ctrl))

#define ioctlEWM_WRITE_SERVICE_REG(pEwmBase, param) \
  periphMemWrite(param, &((pEwmBase)->serv))

#define ioctlEWM_WRITE_COMPAREL_REG(pEwmBase, param) \
  periphMemWrite(param, &((pEwmBase)->cmpl))

#define ioctlEWM_WRITE_COMPAREH_REG(pEwmBase, param) \
  periphMemWrite(param, &((pEwmBase)->cmph))

#define ioctlEWM_SELECT_CLK(pEwmBase, param) \
  periphMemWrite(param, &((pEwmBase)->clkctrl))

#define ioctlEWM_SET_PRESCALER(pEwmBase, param) \
  periphMemWrite(param, &((pEwmBase)->clkprescaler))

#define ioctlEWM_READ_COMPAREL_REG(pEwmBase, param) \
  periphMemRead(&((pEwmBase)->cmpl))

#define ioctlEWM_READ_COMPAREH_REG(pEwmBase, param) \
  periphMemRead(&((pEwmBase)->cmph))

/* clear(service) EWM timer */
#define ioctlEWM_CLEAR_COUNTER(pEwmBase, param) \
  { periphMemWrite(0x00b4, &((pEwmBase)->serv));\
    periphMemWrite(0x002c, &((pEwmBase)->serv)); }

#ifdef __cplusplus
}
#endif

#endif
