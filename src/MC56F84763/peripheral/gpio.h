/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  gpio.h
*
* $Date:      May-6-2013$
*
* $Version:   2.3.32.0$
*
* Description: Header file for the GPIO low-level driver
*
* This file supports different hardware versions of the module. A version
* of module used in your project is defined in the "arch.h" processor 
* architecture definition file.
*
*  GPIO_VERSION_1 .. 56F83xx and 56F801x devices, see MC56F8300UM.pdf, MC56F8000RM.pdf
*  GPIO_VERSION_2 .. 56F802x/3x devices, see MC56F802x3xRM.pdf, 56F82xx devices, see MC56F82xxRM.pdf
*  GPIO_VERSION_3 .. 56F800x devices, see MC56F8006RM.pdf
*  GPIO_VERSION_4 .. 56F823xx devices, see MC56F823xxRM.pdf, 56F827xx devices, see MC56F827xxRM.pdf
*                 .. 56F844xx devices, see MC56F844xxRM.pdf, 56F847xx devices, see MC56F847XXRM.pdf
*
*******************************************************************************/

#ifndef __GPIO_H
#define __GPIO_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before gpio.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*
*                      General Interface Description
*
*
* The General Purpose Input/Output (GPIO) module allows direct access to read or write
* pin values, or assign a pin to be used as an external interrupt. GPIO pins may be dedicated
* for GPIO use only. They can also be multiplexed with other functions on the chip as well.
* The Pin Descriptions chapter specifies the assigned GPIO ports and its multiplexed
* package pin.
* 
* If the peripheral normally controlling a multiplexed pin is not required, the pin may be
* programmed as an input, output, or level-sensitive interrupt input. This specification
* illustrates GPIO in groups of 16, although any configuration of any of the 16 bits may be
* specified for a given chip.
* 
* Features. The GPIO module design includes these characteristics:
* • Individual control for each pin to be in either Normal or GPIO mode
* • Individual direction control for each pin in GPIO mode
* • Individual pull-up enable control for each pin in either Normal or GPIO mode
* • Optimized for use with the keypad interface when push-pull mode control is
*   included
* • Can monitor pad logic value even when GPIO is not enabled using the
*   GPIO_X_RAWDATA register
* 
* Some features of the GPIO are optional:
* • Push-Pull versus Open Drain mode control
* • Interrupt Assert Capability
* • Individual output Push-Pull mode control for each pin
* • Low pass filter for each pin
* • Slew rate control for each pin
*  
* For more information, please refer to the user manual for the particular chip that you
* are using, such as the MC56F8300 Peripheral Manual, for a description
* of the GPIO device.
*
* The GPIO device driver interface uses "ioctl" call to control specific GPIO functions
* during operation. For details see "ioctl" call.
*
******************************************************************************/


/************************************************************
* GPIO module identifiers 
*************************************************************/

#ifdef GPIO_A_BASE
#define GPIO_A  (&ArchIO.PortA)
#endif

#ifdef GPIO_B_BASE
#define GPIO_B  (&ArchIO.PortB)
#endif

#ifdef GPIO_C_BASE
#define GPIO_C  (&ArchIO.PortC)
#endif

#ifdef GPIO_D_BASE
#define GPIO_D  (&ArchIO.PortD)
#endif

#ifdef GPIO_E_BASE
#define GPIO_E  (&ArchIO.PortE)
#endif

#ifdef GPIO_F_BASE
#define GPIO_F  (&ArchIO.PortF)
#endif

#ifdef GPIO_G_BASE
#define GPIO_G  (&ArchIO.PortG)
#endif

#ifndef GPIO
#define GPIO  NULL
#endif

/*************************************************************
* arch.h should define device-specific information about GPIO
**************************************************************/

#if !defined(GPIO_VERSION)
#error GPIO not properly described in arch.h (old Quick_Start version?)
#endif

/****************************************************
* Configurable items, i.e. defines for appconfig.h
*****************************************************

  void gpioxISR( void );         prototype for user ISR 
  #define INT_VECTOR_ADDR_yy     gpioxISR
  #define INT_PRIORITY_LEVEL_yy  one of INTC_DISABLED, INTC_LEVEL0, INTC_LEVEL1 or INTC_LEVEL2

  #define  GPIO_A_PUR_INIT       0x0000
  #define  GPIO_A_DDR_INIT       0x0000
  #define  GPIO_A_DR_INIT        0x0000
  #define  GPIO_A_PER_INIT       0x0000
  #define  GPIO_A_IENR_INIT      0x0000
  #define  GPIO_A_IPOLR_INIT     0x0000
  #define  GPIO_A_PPMODE_INIT    0x0000
  #define  GPIO_A_DRIVE_INIT     0x0000
  #define  GPIO_A_IFE_INIT       0x0000
  #define  GPIO_A_SLEW_INIT      0x0000

  dtto for B, C, D, E, F
  
  where:
         yy  is interrupt vector number
         
         e.g. on 56F8346:
                35 - GPIO A
                34 - GPIO B
                33 - GPIO C
                32 - GPIO D
                31 - GPIO E
                30 - GPIO F
*/

/*****************************************************************
* Single-Instruction  ioctl() commands
*
*  Word16 ioctl( GPIO_module_identifier, Command_name, Parameter );
*
******************************************************************

        COMMAND NAME                      PARAMETERS, COMMENTS
------------------------------------------------------------------ */
#define GPIO_SETAS_GPIO                   /* combination of BIT_x (x=0|1|...|15), set the selected GPIO pins of the GPIO port as GPIO pins by modifying content of the Peripheral Enable Register (PER->_) */
#define GPIO_SETAS_PERIPHERAL             /* combination of BIT_x (x=0|1|...|15), assign the selected GPIO pins of the GPIO to a peripheral by modifying the content of the Peripheral Enable Register (PER->_) */
#define GPIO_SETAS_INPUT                  /* combination of BIT_x (x=0|1|...|15), set the selected GPIO pins as an input pins by modifying the content of the Data Direction Register (DDR->_) */
#define GPIO_SETAS_OUTPUT                 /* combination of BIT_x (x=0|1|...|15), set the selected GPIO pins as an output pins by modifying the content of the Data Direction Register (DDR->_) */
#define GPIO_INT_DISABLE                  /* combination of BIT_x (x=0|1|...|15), disable an interrupt request generated by a GPIO pin by modifying the content of the Interrupt Enable Register (IENR->_) */
#define GPIO_INT_ENABLE                   /* combination of BIT_x (x=0|1|...|15), enable an interrupt request generated by a GPIO pin by modifying the content of the Interrupt Enable Register (IENR->_) */
#define GPIO_PULLUP_DISABLE               /* combination of BIT_x (x=0|1|...|15), disable pull-up on the selected pins by modifying the content of the Pull-Up Enable Register (PUR->_) */
#define GPIO_PULLUP_ENABLE                /* combination of BIT_x (x=0|1|...|15), enable pull-up on the selected pins by modifying the content of the Pull-Up Enable Register (PUR->_) */
#define GPIO_INT_DETECTION_ACTIVE_HIGH    /* combination of BIT_x (x=0|1|...|15), set the selected GPIO pins to be active high by modifying the content of the Interrupt Polarity Register (IPOLR->_) */
#define GPIO_INT_DETECTION_ACTIVE_LOW     /* combination of BIT_x (x=0|1|...|15), set the selected GPIO pins to be active low by modifying the content of the Interrupt Polarity Register (IPOLR->_) */
#define GPIO_SET_PIN                      /* combination of BIT_x (x=0|1|...|15), set the selected GPIO pins by modifying the content of the Data Register (DR->_) */
#define GPIO_CLEAR_PIN                    /* combination of BIT_x (x=0|1|...|15), clear the selected GPIO pins by modifying the content of the Data Register (DR->_) */
#define GPIO_TOGGLE_PIN                   /* combination of BIT_x (x=0|1|...|15), toggle the selected GPIO pins by modifying the content of the Data Register (DR->_) */
#define GPIO_READ_DATA                    /* NULL, read and return the whole GPIO port by reading the GPIO Data Register (DR->_) */
#define GPIO_WRITE_DATA                   /* UWord16, write to the whole port by writing to the GPIO Data Register (DR->_) */
#define GPIO_READ_INT_PENDING_REG         /* NULL, read and return the whole content of the Interrupt Pending Register (IPR->_) */
#define GPIO_TEST_INT_PENDING             /* combination of BIT_x (x=0|1|...|15), test the selected interrupt pending flag(s) from the Interrupt Pending Register (IPR->_) */
#define GPIO_CLEAR_INT_PENDING            /* combination of BIT_x (x=0|1|...|15), clear the selected interrupt request flags generated by the GPIO by writing ones to the Interrupt Edge Sensitive Register (IESR->_) */
#define GPIO_READ_RAW_DATA                /* NULL, read and return the logic value of each GPIO pin from the GPIO Raw Data Register; even when pins are not in GPIO mode. This command reads the (RAW_DATA->_) */

/*******************************************************************************
  commands applicable to version 2 of GPIO module (first used in 80xx)
*******************************************************************************/
#if GPIO_VERSION >= 2
#define GPIO_SET_HIGH_DRIVE_STRENGTH      /* combination of BIT_x (x=0|1|...|15), set the high strength (8mA) of the selected GPIO pin output driver by modifying the content of the Drive Strength Control Register (DRIVE->) */
#define GPIO_SET_LOW_DRIVE_STRENGTH       /* combination of BIT_x (x=0|1|...|15), set the low strength (4mA) of the selected GPIO pin output driver by modifying the content of the Drive Strength Control Register (DRIVE->) */
#endif

/*******************************************************************************
  commands are not applicable to version 3 of GPIO module (first used in 80xx)
*******************************************************************************/
#if GPIO_VERSION <= 2
#define GPIO_SW_INT_ASSERT                /* combination of BIT_x (x=0|1|...|15), enable a software generated interrupt request by modifying the content of the Interrupt Assert Register (IAR->_) */
#define GPIO_CLEAR_SW_INT_PENDING         /* combination of BIT_x (x=0|1|...|15), disable a software generated interrupt request by modifying the content of the Interrupt Assert Register (IAR->_) */
#define GPIO_SETAS_PUSHPULL               /* combination of BIT_x (x=0|1|...|15), set the output driver of the selected GPIO pins to push-pull mode by modifying the content of the Push-Pull Mode Register (PPMODE->_) */
#define GPIO_SETAS_OPENDRAIN              /* combination of BIT_x (x=0|1|...|15), set the output driver of the selected GPIO pins to open drain mode by modifying the content of the Push-Pull Mode Register (PPMODE->_) */
#endif


/*******************************************************************************
  commands applicable to version 3 of GPIO module (first used in 800x)
*******************************************************************************/
#if GPIO_VERSION == 3
#define GPIO_SET_LOW_PASS_FILTER_ENABLE   /* combination of BIT_x (x=0|1|...|15), enable the low pass input filter of the selected GPIO pin by modifying the content of the Input Filter Control Register */
#define GPIO_SET_LOW_PASS_FILTER_DISABLE  /* combination of BIT_x (x=0|1|...|15), disable the low pass input filter of the selected GPIO pin by modifying the content of the Input Filter Control Register */
#endif
#if GPIO_VERSION >= 3
#define GPIO_SET_SLEW_RATE_ENABLE         /* combination of BIT_x (x=0|1|...|15), enable the slew rate mode of the selected GPIO pin output driver by modifying the content of the Slew Rate Control Register (SRE->_) */
#define GPIO_SET_SLEW_RATE_DISABLE        /* combination of BIT_x (x=0|1|...|15), disable the slew rate mode of the selected GPIO pin output driver by modifying the content of the Slew Rate Control Register (SRE->_) */
#endif

/*********************************************************************************
  commands applicable to version 4 of GPIO module (first used in 844x, 845x, 827x)
**********************************************************************************/

#if GPIO_VERSION >= 4
#define GPIO_SET_PULL_UP                  /* combination of BIT_x (x=0|1|...|15), enable pull-up on the selected pins by modifying the content of the Pull Resistor Enable Register (PUS->_) */
#define GPIO_SET_PULL_DOWN                /* combination of BIT_x (x=0|1|...|15), enable pull-down on the selected pins by modifying the content of the Pull Resistor Enable Register (PUS->_) */

#define GPIO_SW_INT_ASSERT                /* combination of BIT_x (x=0|1|...|15), enable a software generated interrupt request by modifying the content of the Interrupt Assert Register (IAR->_) */
#define GPIO_CLEAR_SW_INT_PENDING         /* combination of BIT_x (x=0|1|...|15), disable a software generated interrupt request by modifying the content of the Interrupt Assert Register (IAR->_) */
#define GPIO_SETAS_PUSHPULL               /* combination of BIT_x (x=0|1|...|15), set the output driver of the selected GPIO pins to push-pull mode by modifying the content of the Push-Pull Mode Register (PPMODE->_) */
#define GPIO_SETAS_OPENDRAIN              /* combination of BIT_x (x=0|1|...|15), set the output driver of the selected GPIO pins to open drain mode by modifying the content of the Push-Pull Mode Register (PPMODE->_) */
#endif

/*****************************************************************
* Multi-Instruction ioctl() commands
*
*  Word16 ioctl( GPIO_module_identifier, Command_name, Parameter );
*
******************************************************************

        COMMAND NAME                      PARAMETERS, COMMENTS
------------------------------------------------------------------ */
#define GPIO_GET_INT_PENDING_FLAG         /* combination of BIT_x (x=0|1|...|15), read and return the selected interrupt pending flag(s) from the Interrupt Pending Register (IPR->_) */


/*****************************************************************
* Software Layer ioctl() commands
*
*  Word16 ioctl( GPIO_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define GPIO_INIT                         /* NULL, initialize the selected GPIO port registers using appconfig.h _INIT values */
#define GPIO_INIT_ALL                     /* NULL, initialize all available GPIO ports registers using appconfig.h _INIT values */


/****************************************************************************
* GPIO constants used in the ioctl functions
*****************************************************************************/

#define BIT_0   0x0001
#define BIT_1   0x0002
#define BIT_2   0x0004
#define BIT_3   0x0008
#define BIT_4   0x0010
#define BIT_5   0x0020
#define BIT_6   0x0040
#define BIT_7   0x0080
#define BIT_8   0x0100
#define BIT_9   0x0200
#define BIT_10  0x0400
#define BIT_11  0x0800
#define BIT_12  0x1000
#define BIT_13  0x2000
#define BIT_14  0x4000
#define BIT_15  0x8000

/*******************************************************************************
  Implementations of GPIO ioctl() commands
*******************************************************************************/

/* GPIO Init */

void gpioInit(arch_sPort *pGpioBase);
#define ioctlGPIO_INIT(pGpioBase, param) gpioInit(pGpioBase)

/* All GPIO Init */

void gpioInitAll(void);
#define ioctlGPIO_INIT_ALL(pGpioBase, param) gpioInitAll()


/* GPIO Peripheral Enable Register */

#define ioctlGPIO_SETAS_GPIO(pGpioBase, param)      \
  periphBitClear(param, &((pGpioBase)->per))
                        
#define ioctlGPIO_SETAS_PERIPHERAL(pGpioBase, param)     \
  periphBitSet(param, &((pGpioBase)->per))

/* GPIO Data Direction Register */

#define ioctlGPIO_SETAS_INPUT(pGpioBase, param) \
  periphBitClear(param, &((pGpioBase)->ddr))

#define ioctlGPIO_SETAS_OUTPUT(pGpioBase, param)    \
  periphBitSet(param, &((pGpioBase)->ddr))

/* GPIO Data Register */

#define ioctlGPIO_SET_PIN(pGpioBase, param)             \
  periphBitSet(param, &((pGpioBase)->dr))

#define ioctlGPIO_CLEAR_PIN(pGpioBase, param)           \
  periphBitClear(param, &((pGpioBase)->dr))

#define ioctlGPIO_TOGGLE_PIN(pGpioBase, param)          \
  periphBitChange(param, &((pGpioBase)->dr))

#define ioctlGPIO_READ_DATA(pGpioBase, param)     \
  periphMemRead(&((pGpioBase)->dr))

#define ioctlGPIO_WRITE_DATA(pGpioBase, param)     \
  periphMemWrite(param, &((pGpioBase)->dr))

/* GPIO Pull-Up Enable Register */

#define ioctlGPIO_PULLUP_DISABLE(pGpioBase, param)          \
  periphBitClear(param, &((pGpioBase)->pur))

#define ioctlGPIO_PULLUP_ENABLE(pGpioBase, param)        \
  periphBitSet(param, &((pGpioBase)->pur))

/* GPIO Interrupt Enable Register */

#define ioctlGPIO_INT_DISABLE(pGpioBase, param)    \
  periphBitClear(param, &((pGpioBase)->ienr))

#define ioctlGPIO_INT_ENABLE(pGpioBase, param)     \
  periphBitSet(param, &((pGpioBase)->ienr))

/* GPIO Interrupt Polarity Register */

#define ioctlGPIO_INT_DETECTION_ACTIVE_HIGH(pGpioBase, param)    \
  periphBitClear(param, &((pGpioBase)->ipolr))

#define ioctlGPIO_INT_DETECTION_ACTIVE_LOW(pGpioBase, param)     \
  periphBitSet(param, &((pGpioBase)->ipolr))

/* GPIO Interrupt Edge Sensitive Register */

#define ioctlGPIO_CLEAR_INT_PENDING(pGpioBase, param)     \
  periphMemWrite(param, &((pGpioBase)->iesr))

#define ioctlGPIO_CLEAR_EDGE_SENSITIVE_INT_FLAG(pGpioBase, param)     \
  periphMemWrite(param, &((pGpioBase)->iesr))

/* GPIO Interrupt Pending Register */

#define ioctlGPIO_READ_INT_PENDING_REG(pGpioBase, param)     \
  periphMemRead(&((pGpioBase)->ipr))
  
#define ioctlGPIO_GET_INT_PENDING_FLAG(pGpioBase, param)     \
   ((param) & periphMemRead(&((pGpioBase)->ipr)))

#define ioctlGPIO_TEST_INT_PENDING(pGpioBase, param)     \
  periphBitTest(param, &((pGpioBase)->ipr))

/* GPIO raw data registers */

#define ioctlGPIO_READ_RAW_DATA(pGpioBase, param)     \
  periphMemRead(&((pGpioBase)->rawdata))


/* GPIO drive strength register */

#ifdef GPIO_SET_HIGH_DRIVE_STRENGTH
#define ioctlGPIO_SET_HIGH_DRIVE_STRENGTH(pGpioBase, param) \
  periphBitSet(param, &((pGpioBase)->drive))
#endif

#ifdef GPIO_SET_LOW_DRIVE_STRENGTH
#define ioctlGPIO_SET_LOW_DRIVE_STRENGTH(pGpioBase, param)  \
  periphBitClear(param, &((pGpioBase)->drive))
#endif


#if GPIO_VERSION <= 2
/* GPIO Interrupt Assert Register */

#define ioctlGPIO_CLEAR_SW_INT_PENDING(pGpioBase, param)     \
  periphBitClear(param, &((pGpioBase)->iar))

#define ioctlGPIO_SW_INT_ASSERT(pGpioBase, param)     \
  periphBitSet(param, &((pGpioBase)->iar))

#define ioctlGPIO_INT_ASSERT_DISABLE(pGpioBase, param)     \
  periphBitClear(param, &((pGpioBase)->iar))

#define ioctlGPIO_INT_ASSERT_ENABLE(pGpioBase, param)     \
  periphBitSet(param, &((pGpioBase)->iar))

/* GPIO ppmode registers */

#define ioctlGPIO_SETAS_OPENDRAIN(pGpioBase, param)     \
  periphBitClear(param, &((pGpioBase)->ppmode))
                        
#define ioctlGPIO_SETAS_PUSHPULL(pGpioBase, param)     \
  periphBitSet(param, &((pGpioBase)->ppmode))
#endif


#if GPIO_VERSION == 3

/* Input Filter Control Register */
#define ioctlGPIO_SET_LOW_PASS_FILTER_ENABLE(pGpioBase, param)  \
  periphBitSet(param, &((pGpioBase)->ifcr))

#define ioctlGPIO_SET_LOW_PASS_FILTER_DISABLE(pGpioBase, param)  \
  periphBitClear(param, &((pGpioBase)->ifcr))

#endif

#if GPIO_VERSION >= 3

/* Slew Rate Control Register */
#define ioctlGPIO_SET_SLEW_RATE_ENABLE(pGpioBase, param)  \
  periphBitClear(param, &((pGpioBase)->slew))

#define ioctlGPIO_SET_SLEW_RATE_DISABLE(pGpioBase, param)  \
  periphBitSet(param, &((pGpioBase)->slew))

#endif


#if GPIO_VERSION >= 4

#define ioctlGPIO_SET_PULL_UP(pGpioBase, param)  \
  periphBitSet(param, &((pGpioBase)->pus))

#define ioctlGPIO_SET_PULL_DOWN(pGpioBase, param)  \
  periphBitClear(param, &((pGpioBase)->pus))

/* GPIO Interrupt Assert Register */
#define ioctlGPIO_CLEAR_SW_INT_PENDING(pGpioBase, param)     \
  periphBitClear(param, &((pGpioBase)->iar))

#define ioctlGPIO_SW_INT_ASSERT(pGpioBase, param)     \
  periphBitSet(param, &((pGpioBase)->iar))

#define ioctlGPIO_INT_ASSERT_DISABLE(pGpioBase, param)     \
  periphBitClear(param, &((pGpioBase)->iar))

#define ioctlGPIO_INT_ASSERT_ENABLE(pGpioBase, param)     \
  periphBitSet(param, &((pGpioBase)->iar))

/* GPIO ppmode registers */

#define ioctlGPIO_SETAS_OPENDRAIN(pGpioBase, param)     \
  periphBitClear(param, &((pGpioBase)->ppmode))
                        
#define ioctlGPIO_SETAS_PUSHPULL(pGpioBase, param)     \
  periphBitSet(param, &((pGpioBase)->ppmode))

#endif /* GPIO_VERSION >= 4 */


#ifdef __cplusplus
}
#endif

#endif                                      

