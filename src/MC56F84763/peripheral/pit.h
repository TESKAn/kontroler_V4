/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  pit.h
*
* $Date:      May-9-2013$
*
* $Version:   2.3.16.0$
*
* Description: Header file for the PIT driver
*
* PIT_VERSION_1 .. 56F802x/3x devices, see MC56F802x3xRM.pdf
*                  56F800x devices, see MC56F80006RM.pdf
* PIT_VERSION_2 .. 56F823xx devices, see MC56F823xxRM.pdf, 56F827xx devices, see MC56F827xxRM.pdf
*                  56F844xx devices, see MC56F844xxRM.pdf, 56F847xx devices, see MC56F847XXRM.pdf
* 
*******************************************************************************/

#ifndef __PIT_H
#define __PIT_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before pit.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*
*                      General Interface Description
*
*
* The Programmable Interval Timer (PIT) module contains a 16-bit up counter, 
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
* PIT module identifiers
*************************************************************/

#ifdef PIT_BASE
#define PIT (&ArchIO.Pit)
#endif
#ifdef PIT0_BASE
#define PIT_0 (&ArchIO.Pit0)
#endif
#ifdef PIT1_BASE
#define PIT_1 (&ArchIO.Pit1)
#endif
#ifdef PIT2_BASE
#define PIT_2 (&ArchIO.Pit2)
#endif

/*************************************************************
* arch.h should define device-specific information about PIT
**************************************************************/

#if !defined(PIT_VERSION)
#error PIT not properly described in arch.h
#endif

/****************************************************
* Configurable items, i.e. defines for appconfig.h
*****************************************************

  #define PIT_CTRL_INIT 
  #define PIT_MOD_INIT  

  #define INTERRUPT_VECTOR_ADDR_yy  userISR  //specify interrupt handler routine : e.g. pit0ISR
  #define INT_PRIORITY_LEVEL_yy     INTC_xxx // interrupt level : (INTC_DISABLED, INTC_LEVEL0,
                                             //                    INTC_LEVEL1 or INTC_LEVEL2)
  where:
         yy  is interrupt vector number
            e.g. On 56F8037
                55 - PIT_0 rollover interrupt

*/

/*****************************************************************
* ioctl() commands
*
*  Word16 ioctl( PIT_n, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                      PARAMETERS, COMMENTS
--------------------------------------------------------*/
#define PIT_COUNTER                /* PIT_ENABLE/PIT_DISABLE, enable/disable the PIT module counter. This command has no effect on PIT_1 or PIT_2 modules if these operate in "slave mode". In the slave mode the PIT module counter is enabled or disabled simultaneously with PIT_0 counter. See the PIT_SLAVE_MODE command for more details (CTRL->CNT_EN) */
#define PIT_SLAVE_MODE             /* PIT_ENABLE/PIT_DISABLE, enable/disable the PIT "slave mode". It is applicable to PIT_1 and PIT_2 only. When slave mode is enabled on PIT, enabling or disabling PIT_0 counter also enables or disables this PIT. Slave mode can be used for simultaneous count-enabling or disabling of multiple PIT modules (CTRL->SLAVE) */
#define PIT_ROLLOVER_INT           /* PIT_ENABLE/PIT_DISABLE, enable/disable the PIT interrupt to be generated. The PIT interrupt is generated when PIT counter value wraps to zero after reaching the modulo value (CTRL->PRIE) */
#define PIT_CLEAR_ROLLOVER_INT     /* NULL, clear the PIT rollover interrupt flag. Typically, this command is used in the PIT interrupt service routine to acknowledge the interrupt event (CTRL->PRF) */
#define PIT_SET_PRESCALER          /* PIT_PRESCALER_xxx (xxx=1/2/4/8/16/32/64/128/256/512/1024/2048/4096/8192/16384/32768), set the counter prescaler. The PIT count clock is derived directly from the IP Bus clock, divided by the prescaler value */

#define PIT_WRITE_MODULO_REG       /* UWord16, set the PIT modulo register, which is the terminal value of the PIT counter. When the counter reaches the modulo value, it is wrapped to zero at the next counter clock and the PIT interrupt event is raised (if enabled). The modulo value of zero causes the PIT counter to remain zero and to generate the PIT interrupts at each counter clock (IP Bus clock divided by prescaler value) (MOD->_) */
#define PIT_READ_MODULO_REG        /* NULL, read and return the PIT modulo register value as UWord16 (MOD->_) */
#define PIT_READ_COUNTER_REG       /* NULL, read and return the PIT counter register value as UWord16 (CNTR->_) */

#if PIT_VERSION >= 2
#define PIT_SET_CLOCK              /* PIT_IPBUS_CLOCK/PIT_CLOCKxxx (xxx=1/2/3), select the source of the clocking for the PIT counter. This field should not be changed when CNT_EN is set. (CTRL->CLKSEL) */ 
#endif /* PIT_VERSION >= 2 */
/*****************************************************************
* Software Layer ioctl() commands
*
*  Word16 ioctl( COP_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define PIT_INIT                   /* NULL, initialize the PIT peripheral registers using the appconfig.h _INIT values */


/***********************************************************************************************************
** PIT PARAMETERS DEFINITION                                                                        **
***********************************************************************************************************/

#define PIT_ENABLE            1
#define PIT_DISABLE           0

/* PIT_SET_PRESCALER arguments */
#define PIT_PRESCALER_1       PIT_CTRL_PRESCALER_DIV1     
#define PIT_PRESCALER_2       PIT_CTRL_PRESCALER_DIV2     
#define PIT_PRESCALER_4       PIT_CTRL_PRESCALER_DIV4     
#define PIT_PRESCALER_8       PIT_CTRL_PRESCALER_DIV8     
#define PIT_PRESCALER_16      PIT_CTRL_PRESCALER_DIV16    
#define PIT_PRESCALER_32      PIT_CTRL_PRESCALER_DIV32    
#define PIT_PRESCALER_64      PIT_CTRL_PRESCALER_DIV64    
#define PIT_PRESCALER_128     PIT_CTRL_PRESCALER_DIV128   
#define PIT_PRESCALER_256     PIT_CTRL_PRESCALER_DIV256   
#define PIT_PRESCALER_512     PIT_CTRL_PRESCALER_DIV512   
#define PIT_PRESCALER_1024    PIT_CTRL_PRESCALER_DIV1024  
#define PIT_PRESCALER_2048    PIT_CTRL_PRESCALER_DIV2048  
#define PIT_PRESCALER_4096    PIT_CTRL_PRESCALER_DIV4096  
#define PIT_PRESCALER_8192    PIT_CTRL_PRESCALER_DIV8192  
#define PIT_PRESCALER_16384   PIT_CTRL_PRESCALER_DIV16384 
#define PIT_PRESCALER_32768   PIT_CTRL_PRESCALER_DIV32768 

#if PIT_VERSION >= 2
#define PIT_IPBUS_CLOCK       PIT_CTRL_CLKSEL_IPBUS 
#define PIT_CLOCK1            PIT_CTRL_CLKSEL_CLOCK1
#define PIT_CLOCK2            PIT_CTRL_CLKSEL_CLOCK2
#define PIT_CLOCK3            PIT_CTRL_CLKSEL_CLOCK3

#endif


/****************************************************************************
* register and bit names used in the ioctl functions below
*****************************************************************************/

/* CTRL register */
#define PIT_CTRL_SLAVE                0x8000
#define PIT_CTRL_PRESCALER_MASK       0x0078
#define PIT_CTRL_PRESCALER_DIV1       0x0000
#define PIT_CTRL_PRESCALER_DIV2       0x0008
#define PIT_CTRL_PRESCALER_DIV4       0x0010
#define PIT_CTRL_PRESCALER_DIV8       0x0018
#define PIT_CTRL_PRESCALER_DIV16      0x0020
#define PIT_CTRL_PRESCALER_DIV32      0x0028
#define PIT_CTRL_PRESCALER_DIV64      0x0030
#define PIT_CTRL_PRESCALER_DIV128     0x0038
#define PIT_CTRL_PRESCALER_DIV256     0x0040
#define PIT_CTRL_PRESCALER_DIV512     0x0048
#define PIT_CTRL_PRESCALER_DIV1024    0x0050
#define PIT_CTRL_PRESCALER_DIV2048    0x0058
#define PIT_CTRL_PRESCALER_DIV4096    0x0060
#define PIT_CTRL_PRESCALER_DIV8192    0x0068
#define PIT_CTRL_PRESCALER_DIV16384   0x0070
#define PIT_CTRL_PRESCALER_DIV32768   0x0078
#define PIT_CTRL_PRF                  0x0004
#define PIT_CTRL_PRIE                 0x0002
#define PIT_CTRL_CNT_EN               0x0001

#if PIT_VERSION >= 2

#define PIT_CTRL_CLKSEL_MASK          0x0300
#define PIT_CTRL_CLKSEL_IPBUS         0x0000
#define PIT_CTRL_CLKSEL_CLOCK1        0x0100
#define PIT_CTRL_CLKSEL_CLOCK2        0x0200
#define PIT_CTRL_CLKSEL_CLOCK3        0x0300

#endif
/****************************************************************************
* PIT ioctl macro implementation
*****************************************************************************/

/* PIT init */

void pitInit(arch_sPIT *pPitBase);
#define ioctlPIT_INIT(pPitBase, param) pitInit(pPitBase)

/* PIT control register */

/* Enable/Disable PIT counter */
#define ioctlPIT_COUNTER(pPitBase, param) \
  if (param) periphBitSet(PIT_CTRL_CNT_EN, &((pPitBase)->ctrl)); \
  else periphBitClear(PIT_CTRL_CNT_EN, &((pPitBase)->ctrl))

/* Enable/Disable PIT slave mode */
#define ioctlPIT_SLAVE_MODE(pPitBase, param) \
  if (param) periphBitSet(PIT_CTRL_SLAVE, &((pPitBase)->ctrl)); \
  else periphBitClear(PIT_CTRL_SLAVE, &((pPitBase)->ctrl))

/* Enable/disable PIT interrupt */
#define ioctlPIT_ROLLOVER_INT(pPitBase, param) \
  if(param) periphBitSet(PIT_CTRL_PRIE, &((pPitBase)->ctrl)); \
  else periphBitClear(PIT_CTRL_PRIE, &((pPitBase)->ctrl))

/* Clear PIT interrupt */
#define ioctlPIT_CLEAR_ROLLOVER_INT(pPitBase, param) \
  periphBitClear(PIT_CTRL_PRF, &((pPitBase)->ctrl))

/* Set PIT prescaler */
#define ioctlPIT_SET_PRESCALER(pPitBase, param) \
  periphBitGrpSR(PIT_CTRL_PRESCALER_MASK, param, &((pPitBase)->ctrl))

/* PIT counter/modulo registers */

#define ioctlPIT_WRITE_MODULO_REG(pPitBase, param) \
  periphMemWrite(param, &((pPitBase)->mod))

#define ioctlPIT_READ_MODULO_REG(pPitBase, param) \
  periphMemRead(&((pPitBase)->mod))

#define ioctlPIT_READ_COUNTER_REG(pPitBase, param) \
  periphMemRead(&((pPitBase)->cntr))

#if PIT_VERSION >= 2
/* Select the clock source for PIT */
#define ioctlPIT_SET_CLOCK(pPitBase, param) \
  periphBitGrpSR(PIT_CTRL_CLKSEL_MASK, param, &((pPitBase)->ctrl))
#endif


#ifdef __cplusplus
}
#endif

#endif                                      
