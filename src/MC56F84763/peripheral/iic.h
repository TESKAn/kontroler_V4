/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  iic.h
*
* $Date:      Dec-17-2014$
*
* $Version:   2.5.10.0$
*
* Description: Header file for the I2C driver
*
* This file only supports two hardware versions of the module (IIC_VERSION_3 and IIC_VERSION_4). 
* A version  of module used in your project is defined in the "arch.h" 
* processor architecture definition file.
*
*  IIC_VERSION_1 .. 56F801x devices, see MC56F8000RM.pdf
*  IIC_VERSION_2 .. 56F802x/3x devices, see MC56F802x3xRM.pdf
*  IIC_VERSION_3 .. 56F800x devices, see MC56F8006RM.pdf
*  IIC_VERSION_4 .. 56F824x/5x devices, see MC56F82xxRM.pdf
*  IIC_VERSION_5 .. 56F844x/5x/7x devices, see MC56F844XXRM.pdf
*  IIC_VERSION_6 .. 56F827XX devices, see MC56F827XXRM.pdf
*
*******************************************************************************/

#ifndef __IIC_H
#define __IIC_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before iic.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*
*                      General Interface Description
*
*
* The Inter-IC Bus (IIC or I2C) is a two-wire, bidirectional serial bus that provides 
* a simple, efficient method of data exchange between devices. Being a two-wire device, 
* the IIC Bus minimizes the need for large numbers of connections between devices, 
* and eliminates the need for an address decoder.
* 
* This bus is suitable for applications requiring occasional communications over a 
* short distance between a number of devices. It also provides flexibility, allowing 
* additional devices to be connected to the bus for further expansion and system 
* development.
*
* For more information, please refer to the user manual for the particular chip that you
* are using, such as the MC56F80xx Peripheral Manual, for a description
* of the I2C device.
*
* The I2C device driver interface uses "ioctl" call to control specific I2C functions
* during operation. For details see "ioctl" call.
*
******************************************************************************/

/************************************************************
* I2C module identifier
*************************************************************/

#ifdef IIC_BASE
#define IIC (&ArchIO.Iic)
#define I2C IIC
#endif

#ifdef IIC0_BASE
#define IIC_0   (&ArchIO.Iic0)
#endif

#ifdef IIC1_BASE
#define IIC_1   (&ArchIO.Iic1)
#endif

/*************************************************************
* arch.h should define device-specific information about IIC
**************************************************************/

#if !defined(IIC_VERSION)
#error IIC not properly described in arch.h (old Quick_Start version?)
#endif

#if !(defined(IIC_VERSION_3) || defined(IIC_VERSION_4)  || defined(IIC_VERSION_5) || defined(IIC_VERSION_6))
#error This file implements IIC version 3 and 4 only (56F800x, 56F82xx, 56F84xxx and 56F82xxx devices or later)
#endif


/****************************************************
* Configurable items, i.e. defines for appconfig.h
*****************************************************

  void i2cISR( void );           prototype for user ISR 
  #define INT_VECTOR_ADDR_23     interrupt vector (e.g. i2cISR)

  #define IIC_IICF_INIT 0x0000
  #define IIC_IICA1_INIT 0x0000
  #define IIC_IICA2_INIT 0x0000
  #define IIC_IICC1_INIT 0x0000
  #define IIC_IICC2_INIT 0x0000
  #define IIC_IICSMB_INIT 0x0000
  #define IIC_IICSLTH_INIT 0x0000
  #define IIC_IICSLTL_INIT 0x0000

NEW IN VERSION 4
  #define IIC_FILT_INIT 0x0000

NEW IN VERSION 5
  #define IIC_RA_INIT 	0x0000
*/

/*****************************************************************
* Single-Instruction ioctl() commands
*
*  Word16 ioctl( IIC_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define IIC_SET_ADDRESS                 /* UWord16 value 0-127, set the IIC node (slave) address. The IIC address is used in the slave mode only to detect it is being addressed in an IIC transaction. Typically, it is not necessary to change the slave address once it is set e.g. by the IIC_INIT call (A1->AD[7:1]) */
#define IIC_SET_PRESCALER               /* UWord16, write directly into the IIC Bus Frequency Divider Register register, which controls several prescalers and delays applied to the IIC bit-sampling and bit-transmission process (F->MULT[7:6], ICR[5:0]) */
#define IIC_I_BUS                       /* IIC_ENABLE/IIC_DISABLE, Enable/Disable the IIC module as a whole (C1->IICEN) */
#define IIC_I_BUS_INT                   /* IIC_ENABLE/IIC_DISABLE, Enable/Disable the IIC Interrupt. The core receives the interrupt provided if it is enabled in the INTC Interrupt Controller module and also when interrupts are enabled globally in the core Status Register (SR) (C1->ICCIE) */
#define IIC_MASTER_SLAVE_MODE           /* IIC_MASTER/IIC_SLAVE, select the mode the IIC module operates in. When used as a master mode in a single-master application, this command may be used once after the IIC initialization to set the Master mode. In a multi-master application, the IIC is typically set to Slave (listen) mode by default and is momentarily switched to the Master mode when needed (C1->MST) */
#define IIC_TX_RX_MODE                  /* IIC_TRANSMIT/IIC_RECEIVE, Select the direction of data transfers. The Receive/Transmit mode  selection should not be confused with the Master/Slave selection (C1->TX) */
#define IIC_TX_ACK                      /* IIC_NO_ACK/IIC_ACK, Enable/Disable transmiting of the acknowledge signal after a data byte is received (matching address byte is always acknowledged). By disabling an acknowledge signal a receiver informs the transmitting node that it wants to finish the transaction (C1->TXAK) */
#define IIC_REPEAT_START                /* NULL, generate a repeated START condition on the bus, provided the node is active bus Master (otherwise the Arbitration Lost status flag is set) (C1->RSTA) */
#define IIC_WRITE_CONTROL_REG           /* UWord16, write the value to IIC-Bus Control Register 1 (C1->_) */
#define IIC_READ_CONTROL_REG            /* NULL, read and return the IIC-Bus Control Register as UWord16 (C1->_) */
#define IIC_READ_DATA                   /* NULL, read and return the fetched byte received from the IIC bus by directly reading the IIC Data I/O Register. Typically, reading of the byte is done in the IIC interrupt service routine (D->_) */
#define IIC_WRITE_DATA                  /* UWord16 value 0-255, write the value to the IIC Bus Data I/O Register. Typically, writing the data register is done in the IIC interrupt service routine (D->_) */

#define IIC_GET_MASTER_MODE             /* NULL, return non-zero if IIC Master mode is set (C1->MST) */
#define IIC_GET_TX_MODE                 /* NULL, return non-zero if transmit mode is set (C1->TX) */

#define IIC_READ_STATUS_REG             /* NULL, read and return the IIC Bus Status Register as UWord16 (S->_) */
#define IIC_TEST_STATUS_REG             /* combination of IIC_xxx (xxx=TRANSFER_COMPLETE|ADDRESSED_AS_SLAVE|BUS_BUSY|ARBITRATION_LOST|SLAVE_TRANSMIT|IBUS_INT|RX_ACK), test IIC Bus Status Register for selected bits (S->_) */

#define IIC_GET_TRANSFER_COMPLETE       /* NULL, get the data transferring status */
#define IIC_GET_ADDRESSED_AS_SLAVE      /* NULL, get the addressed as-a-slave flag */
#define IIC_GET_BUS_BUSY                /* NULL, get the bus busy status */
#define IIC_CLEAR_ARBITRATION_LOST      /* NULL, clear arbitration lost flag*/
#define IIC_GET_ARBITRATION_LOST        /* NULL, get arbitration lost status */
#define IIC_GET_SLAVE_TRANSMIT          /* NULL, get slave read/write status */
#define IIC_CLEAR_I_BUS_INT             /* NULL, clear the I-Bus interrupt flag */
#define IIC_GET_I_BUS_INT               /* NULL, get the I-Bus interrupt flag */
#define IIC_GET_RX_ACK                  /* NULL, get the received acknowledge flag */

#if IIC_VERSION >=3
/* IICC2 */
#define IIC_SET_GENERAL_CALL_ADDRESS    /* IIC_ENABLE/IIC_DISABLE, enable/disable the general call address (C2->GCAEN) */
#define IIC_SET_ADDRESS_EXTENSION_MODE  /* IIC_nBIT (n=7/10), set the number of bits used for the slave address (C2->ADEXT) */
/* IICSMB */
#define IIC_CLEAR_LOW_TIMEOUT_FLAG      /* NULL, clear low timeout flags (SMB->SLTF) */
/* IICA2 */
#define IIC_SET_SMBUS_ADDRESS           /* UWord16 value 0-127, write the value into the Secondary IIC Bus Address Register (A2->SAD[7:1]) */
#endif

#if IIC_VERSION == 3
#define IIC_TEST_TIMEOUT_FLAGS          /* IIC_LOW_TIMEOUT|IIC_HIGH_TIMEOUT, test and return the state of the selected timeout flags (SMB->SLTF,SHTF) */
#endif

#if IIC_VERSION >=4
#define IIC_SET_WAKEUP_IN_STOP          /* IIC_ENABLE/IIC_DISABLE, enable/disable the wake up function in stop mode (C1->WUEN) */
#define IIC_TEST_TIMEOUT_FLAGS          /* combination of IIC_xxx (xxx=LOW_TIMEOUT|HIGH_TIMEOUT|HIGH_TIMEOUT2 ), test and return the state of the selected timeout flags (IICSMB->SLTF,SHTF,SHTF2) */
#define IIC_CLEAR_HIGH_TIMEOUT_FLAG2    /* NULL, clear the High Timeout flag 2 by writing 1 to it (IICSMB->SHFT2) */
#define IIC_CLEAR_TIMEOUT_FLAGS         /* combination of IIC_xxx (xxx=LOW_TIMEOUT|HIGH_TIMEOUT2), clear selected timeout flags by writing 1 to them (IICSMB->SLRF,SHFT2) */
#define IIC_SET_GLITCH_FILTER           /* UWord16 value 0 (=disable) or 1-7 (=enable), enable/disable the glitch filter. The value 1-7 represents the number of filter glitches up to width of n bus clock cycles (FILT->FLT) */
#endif

/****************************************************************************
* IIC Version 5 commands (844x/5x/7x) & (827xx)
*****************************************************************************/
#if IIC_VERSION >=5
/* IICC1 */
#define IIC_SET_DMA_TRANSFER                /* IIC_ENABLE/IIC_DISABLE, enable/disable the DMA function, see documentation how FAST_ACK mode affects the DMA receive and transmit functions (C1->DMAEN) */
/* IICC2 */
#define IIC_SET_HIGH_DRIVE_PADS             /* IIC_ENABLE/IIC_DISABLE, enable/disable the high drive capability of the I2C pads (C2->HDRS) */
#define IIC_SET_SLAVE_BAUD_RATE_CTRL        /* IIC_MASTER_INDEPENDENT/IIC_MASTER_FOLLOW, enable/disable the slave baud rate (0 - slave follows master baud rate) (C2->SBRC) */
#define IIC_SET_RANGE_MODE                  /* IIC_ENABLE/IIC_DISABLE, enable/disable the slave address matching between the values of the A1 and RA registers (C2->RMEN) */

/* IICBFD */
#define IIC_WRITE_FREQ_DIV_REG              /* UWord16 value 0-255, write to the IIC-Bus Frequency Divider Register (F->MULT[7:6], ICR[5:0]) */
#define IIC_READ_FREQ_DIV_REG               /* NULL, read and return the IIC-Bus Frequency Divider Register as UWord16 (F->MULT[7:6], ICR[5:0]) */
/* IICC2 */
#define IIC_WRITE_CONTROL2_REG              /* UWord16 value 0-255, write to the IIC-Bus Control Register 2 (C2->_) */
#define IIC_READ_CONTROL2_REG               /* NULL, read and return the IIC-Bus Control Register 2 as UWord16 (C2->_) */
/* IICSMB */
#define IIC_WRITE_SMBUS_REG                 /* UWord16 value 0-255, write to the IIC-Bus SMBus Control and Status register. Note: an inappropriate write to register can clear Write-1-to-Clear (SLTF/SHTF2) flags (SMB->_) */
#define IIC_READ_SMBUS_REG                  /* NULL, read and return the IIC-Bus SMBus Control and Status as UWord16 (SMB->_) */
/* IICA2 */
#define IIC_WRITE_ADDRESS2_REG              /* UWord16 value 2-255, write to the IIC-Bus Address Register 2 (A2->_) */
#define IIC_READ_ADDRESS2_REG               /* NULL, read and return the IIC-Bus Address Register 2 as UWord16 (A2->_) */
/* IICSLTH */
#define IIC_WRITE_SCL_LOW_TIMEOUT_HIGH_REG  /* UWord16 value 0-255, write to the IIC-Bus SCL Low Timeout MSByte of Register (SLTH->_) */
#define IIC_READ_SCL_LOW_TIMEOUT_HIGH_REG   /* NULL, read and return the IIC-Bus SCL Low Timeout MSByte Register as UWord16 (SLTH->_) */
/* IICSLTL */
#define IIC_WRITE_SCL_LOW_TIMEOUT_LOW_REG   /* UWord16 value 0-255, write to the IIC-Bus SCL Low Timeout LSByte of Register (SLTL->_) */
#define IIC_READ_SCL_LOW_TIMEOUT_LOW_REG    /* NULL, read and return the IIC-Bus SCL Low Timeout LSByte Register as UWord16 (SLTL->_) */

#endif /* IIC_VERSION >=5 */

/*****************************************************************
* Multi-Instruction ioctl() commands
*
*  Word16 ioctl( IIC_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define IIC_GET_ADDRESS                 /* NULL, read and return the IIC Address (0-127) which is currently active for the slave operation */
#if IIC_VERSION >=3
/* IICC2 */
#define IIC_SET_ADDRESS_EXTENSION       /* UWord16 value of the 10bit address >> 8, set the upper three bits of the slave address in the 10-bit address scheme (IICC2->AD[10-8]) */
#define IIC_SET_10BIT_ADDRESS           /* UWord16 value 0-1023, write to the 10-bit slave address to the IIC Bus Address Register and the upper three bits to the Control Register 2 (0-1023) (IICC2->AD[10-8],(IICA1->AD[7-1]) */
#define IIC_GET_10BIT_ADDRESS           /* NULL, read and return the 10-bit slave address (IICC2->AD[10-8],(IICA1->AD[7-1]) */
/* IICSMB */
#define IIC_SET_FAST_ACK_NACK           /* IIC_ENABLE/IIC_DISABLE, enable/disable the fast set up ACK/NACK response (IICSMB->FACK) */
#define IIC_SET_SMBUS_RESPONSE_ADDRESS  /* IIC_ENABLE/IIC_DISABLE, enable/disable the SMBUS alert response address (IICSMB->ALERTEN) */
#define IIC_SET_SECOND_IIC_ADDRESS      /* IIC_ENABLE/IIC_DISABLE, enable/disable the SMBus device default address (IICSMB->SIICAEN) */
#define IIC_SET_TIME_OUT_CLOCK          /* IIC_DIV64/IIC_DIV1, select the clock sources of the timeout counter  (IICSMB->TCKSEL) */
/* IICA2 */
#define IIC_GET_SMBUS_ADDRESS           /* NULL, read and return the IIC SMBus slave address of the node in the range 0..127 as UWord16 */

#define IIC_WRITE_SCL_LOW_TIMEOUT       /* UWord16, set the SCL low timeout . This command writes directly into the SSLT bit-fields in the IIC_SLTH register and in the IIC_SLTL register */
#define IIC_READ_SCL_LOW_TIMEOUT        /* NULL, read and return the SCL low timeout value */
#endif

#if IIC_VERSION >=4
#define IIC_SET_HIGH_TIMEOUT2_INTERRUPT /* IIC_ENABLE/IIC_DISABLE, enable/disable the high timeout 2 interrupt (IICSMB->SHTF2IE) */
#endif

#if IIC_VERSION >=5
/* IICRA */
#define IIC_SET_RANGE_SLAVE_ADDRESS     /* UWord16 value 0-127, set the slave address range to by used by the IIC module, any nonzero write enables this register (RA->RAD) */
#define IIC_GET_RANGE_SLAVE_ADDRESS     /* NULL, get the slave address range (RA->RAD) */
#define IIC_WRITE_RANGE_ADDRESS_REG     /* UWord16, write to the IIC-Bus Range Address Register */
#define IIC_READ_RANGE_ADDRESS_REG      /* NULL, read and return the IIC-Bus Range Address Register as UWord16 */
/* IICFLT */
#define IIC_SET_HOLD_OFF_TO_STOP        /* IIC_ENABLE/IIC_DISABLE, enable/disable waiting to finish currently transfered data, then enter to the stop mode (FLT->SHEN) */
#define IIC_SET_STOP_START_INT          /* IIC_ENABLE/IIC_DISABLE, enable/disable the interrupt for the IIC bus stop or the start detection (FLT->SSIE) */
#define IIC_TEST_STOP_START_FLAGS       /* combination of IIC_xxx_FLAG (xxx=STOP|START), test the state of the start/stop detection flags (FLT->STOPF,STARTF) */
#define IIC_CLEAR_STOP_START_FLAGS      /* combination of IIC_xxx_FLAG (xxx=STOP|START), clear the start/stop detection flags (FLT->STOPF,STARTF) */
#define IIC_WRITE_GLITCH_FILTER_REG     /* UWord16, write to the IIC-bus Programmable Input Glitch Filter register */
#define IIC_READ_GLITCH_FILTER_REG      /* NULL, read and return the IIC-bus Programmable Input Glitch Filter Register as UWord16 */
#endif /* IIC_VERSION >=5 */

/*****************************************************************
* Software Layer ioctl() commands
*
*  Word16 ioctl( IIC_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define IIC_INIT                        /* NULL, initialize the IIC periheral registers using the appconfig.h _INIT values */


/***********************************************************************************************************
** IIC PARAMETERS DEFINITION                                                                        **
***********************************************************************************************************/

#define IIC_ON                      1
#define IIC_OFF                     0
#define IIC_ENABLE                  1
#define IIC_DISABLE                 0
#define IIC_MASTER                  1
#define IIC_SLAVE                   0
#define IIC_TRANSMIT                1
#define IIC_RECEIVE                 0
#define IIC_NO_ACK                  1
#define IIC_ACK                     0
#define IIC_TRANSFER_COMPLETE       IIC_IBSR_TCF
#define IIC_ADDRESSED_AS_SLAVE      IIC_IBSR_IAAS
#define IIC_BUS_BUSY                IIC_IBSR_IBB
#define IIC_ARBITRATION_LOST        IIC_IBSR_IBAL
#define IIC_SLAVE_TRANSMIT          IIC_IBSR_SRW
#define IIC_IBUS_INT                IIC_IBSR_IBIF
#define IIC_RX_ACK                  IIC_IBSR_RXAK

#define IIC_10BIT                   1
#define IIC_7BIT                    0
#define IIC_DIV1                    1
#define IIC_DIV64                   0

/* IICSMB register */
#define IIC_LOW_TIMEOUT             IIC_IICSMB_SLTF
#define IIC_HIGH_TIMEOUT            IIC_IICSMB_SHTF

#if IIC_VERSION >=4
#define IIC_HIGH_TIMEOUT2           IIC_IICSMB_SHTF2
#endif

#if IIC_VERSION >= 5
#define IIC_MASTER_INDEPENDENT      1
#define IIC_MASTER_FOLLOW           0

/* IICFLT register */
#define IIC_STOP_FLAG               IIC_IICFILT_STOPF
#define IIC_START_FLAG              IIC_IICFILT_STARTF
#endif /* IIC_VERSION >= 5 */
/****************************************************************************
* register and bit names used in the ioctl functions below
*****************************************************************************/

/* IBAD register */
#define IIC_IBAD_MASK               0xFE 
#define IIC_IBAD_ADR6               0x0080
#define IIC_IBAD_ADR5               0x0040
#define IIC_IBAD_ADR4               0x0020
#define IIC_IBAD_ADR3               0x0010
#define IIC_IBAD_ADR2               0x0008
#define IIC_IBAD_ADR1               0x0004
#define IIC_IBAD_ADR0               0x0002
#define IIC_IBAD_ADR                0x00FE

/* IBFD register */
#define IIC_IBFD_MASK               0xFF 
#define IIC_IBFD_IBC7               0x0080
#define IIC_IBFD_IBC6               0x0040
#define IIC_IBFD_IBC5               0x0020
#define IIC_IBFD_IBC4               0x0010
#define IIC_IBFD_IBC3               0x0008
#define IIC_IBFD_IBC2               0x0004
#define IIC_IBFD_IBC1               0x0002
#define IIC_IBFD_IBC0               0x0001
#define IIC_IBFD_IBC                0x00FF

/* IBCR register */
#define IIC_IBCR_MASK               0xFC 
#define IIC_IBCR_IBEN               0x0080
#define IIC_IBCR_IBIE               0x0040
#define IIC_IBCR_MS_SL              0x0020
#define IIC_IBCR_TX_RX              0x0010
#define IIC_IBCR_TXAK               0x0008
#define IIC_IBCR_RSTA               0x0004

#if IIC_VERSION >=4
#define IIC_IBCR_WUEN               0x0002
#endif

#if IIC_VERSION >=5
#define IIC_IBCR_DMAEN              0x0001
#endif

/* IBSR register */
#define IIC_IBSR_MASK               0xF7 
#define IIC_IBSR_TCF                0x0080
#define IIC_IBSR_IAAS               0x0040
#define IIC_IBSR_IBB                0x0020
#define IIC_IBSR_IBAL               0x0010
#define IIC_IBSR_SRW                0x0004
#define IIC_IBSR_IBIF               0x0002
#define IIC_IBSR_RXAK               0x0001

/* IBDR register */
#define IIC_IBDR_MASK               0xFF 
#define IIC_IBDR_D7                 0x0080
#define IIC_IBDR_D6                 0x0040
#define IIC_IBDR_D5                 0x0020
#define IIC_IBDR_D4                 0x0010
#define IIC_IBDR_D3                 0x0008
#define IIC_IBDR_D2                 0x0004
#define IIC_IBDR_D1                 0x0002
#define IIC_IBDR_D0                 0x0001
#define IIC_IBDR_D                  0x00FF

/* IICC2 register */
#define IIC_IICC2_GCAEN             0x0080
#define IIC_IICC2_ADEXT             0x0040
#define IIC_IICC2_ADR_MASK          0x0007

#if IIC_VERSION >=5
#define IIC_IICC2_HDRS              0x0020
#define IIC_IICC2_SBRC              0x0010
#define IIC_IICC2_RMEN              0x0008
#endif

/* IICSMB register */
#define IIC_IICSMB_FACK             0x0080
#define IIC_IICSMB_ALERTEN          0x0040
#define IIC_IICSMB_SIICAEN          0x0020
#define IIC_IICSMB_TCKSEL           0x0010
#define IIC_IICSMB_SLTF             0x0008
#define IIC_IICSMB_SHTF             0x0004

#if IIC_VERSION >=4
#define IIC_IICSMB_SHTF2            0x0002
#define IIC_IICSMB_SHTF2IE          0x0001

/* FILT register */
#define IIC_FILT_FLT_MASK           0x0007
#endif

#if IIC_VERSION >=5
/* FLT register */
#define IIC_IICFILT_SHEN            0x0080
#define IIC_IICFILT_STOPF           0x0040
#define IIC_IICFILT_SSIE            0x0020
#define IIC_IICFILT_STARTF          0x0010

/* RA register */
#define IIC_IICRA_RAD               0x00FE

#endif /* IIC_VERSION >= 5 */

#if IIC_VERSION ==5
/* corrected name convention of bit field FLT_MASK */
#define IIC_IICFILT_FLT_MASK        0x0007
#endif /* IIC_VERSION ==5 */

#if IIC_VERSION >=6
/* FLT register */
#define IIC_IICFILT_FLT_MASK        0x000F
#endif /* IIC_VERSION >=6 */


/****************************************************************************
* I2C ioctl macro implementation
*****************************************************************************/

/***********************************************************************
* I2C init
***********************************************************************/

void iicInit(arch_sIIC *pI2cBase);
#define ioctlIIC_INIT(pIicBase, bParam) iicInit(pIicBase)

/***********************************************************************
* I2C control register
***********************************************************************/

/* Enable/Disable IIC module */
#define ioctlIIC_I_BUS(pIicBase, param) \
  if (param) periphBitSet(IIC_IBCR_IBEN, &((pIicBase)->ctrl1)); \
  else periphBitClear(IIC_IBCR_IBEN, &((pIicBase)->ctrl1))

/* Enable/Disable IIC Interrupt */
#define ioctlIIC_I_BUS_INT(pIicBase, param) \
  if (param) periphBitSet(IIC_IBCR_IBIE, &((pIicBase)->ctrl1)); \
  else periphBitClear(IIC_IBCR_IBIE, &((pIicBase)->ctrl1))

/* Set IIC Master or Slave */
#define ioctlIIC_MASTER_SLAVE_MODE(pIicBase, param) \
  if (param) periphBitSet(IIC_IBCR_MS_SL, &((pIicBase)->ctrl1)); \
  else periphBitClear(IIC_IBCR_MS_SL, &((pIicBase)->ctrl1))

/* Select the direction of data transfers */
#define ioctlIIC_TX_RX_MODE(pIicBase, param) \
  if (param) periphBitSet(IIC_IBCR_TX_RX, &((pIicBase)->ctrl1)); \
  else periphBitClear(IIC_IBCR_TX_RX, &((pIicBase)->ctrl1))

/* Enable/Disable Transmiting of Acknowledge */
#define ioctlIIC_TX_ACK(pIicBase, param) \
  if (param) periphBitSet(IIC_IBCR_TXAK, &((pIicBase)->ctrl1)); \
  else periphBitClear(IIC_IBCR_TXAK, &((pIicBase)->ctrl1))

/* Generate a repeated START condition on the bus */
#define ioctlIIC_REPEAT_START(pIicBase, param) \
  periphBitSet(IIC_IBCR_RSTA, &((pIicBase)->ctrl1))

/* Write to IIC-Bus Control Register  */
#define ioctlIIC_WRITE_CONTROL_REG(pIicBase, param) \
  periphMemWrite(param, &((pIicBase)->ctrl1))

/* Read the IIC-Bus Control Register as UWord16 */
#define ioctlIIC_READ_CONTROL_REG(pIicBase, param)  \
  periphMemRead(&((pIicBase)->ctrl1))

#define ioctlIIC_GET_MASTER_MODE(pIicBase, param)  \
  periphBitTest(IIC_IBCR_MS_SL, &((pIicBase)->ctrl1))

#define ioctlIIC_GET_TX_MODE(pIicBase, param)  \
  periphBitTest(IIC_IBCR_TX_RX, &((pIicBase)->ctrl1))

/***********************************************************************
* I2C address
***********************************************************************/

/* UWord16, Write to the IIC Bus Address Register (0-127) */
#define ioctlIIC_SET_ADDRESS(pIicBase, param) \
  periphMemWrite((param) << 1, &((pIicBase)->addr1))

/* NULL, read IIC Address (0-127) */
#define ioctlIIC_GET_ADDRESS(pIicBase, param) \
  (periphMemRead(&((pIicBase)->addr1)) >> 1)

/***********************************************************************
* I2C baudrate register
***********************************************************************/

/* UWord16, Write to the IIC Bus Frequency Divider Register */
#define ioctlIIC_SET_PRESCALER(pIicBase, param) \
  periphMemWrite(param, &((pIicBase)->fdiv))

/***********************************************************************
* I2C status register
***********************************************************************/

/* Read IIC Bus Status Register as UWord16 */
#define ioctlIIC_READ_STATUS_REG(pIicBase, param)  \
  periphMemRead(&((pIicBase)->stat))

/* Test IIC Bus Status Register for selected bits */
#define ioctlIIC_TEST_STATUS_REG(pIicBase, param) \
  periphBitTest(param, &((pIicBase)->stat))

/* Get Data transferring status */
#define ioctlIIC_GET_TRANSFER_COMPLETE(pIicBase, param) \
  periphBitTest(IIC_IBSR_TCF, &((pIicBase)->stat))

/* Get the Addressed as a slave flag */
#define ioctlIIC_GET_ADDRESSED_AS_SLAVE(pIicBase, param) \
  periphBitTest(IIC_IBSR_IAAS, &((pIicBase)->stat))

/* Get the Bus busy status */
#define ioctlIIC_GET_BUS_BUSY(pIicBase, param) \
  periphBitTest(IIC_IBSR_IBB, &((pIicBase)->stat))

/* Clear Arbitration Lost */
#define ioctlIIC_CLEAR_ARBITRATION_LOST(pIicBase, param) \
    periphMemWrite(IIC_IBSR_IBAL, &((pIicBase)->stat))

/* Get Arbitration Lost status */
#define ioctlIIC_GET_ARBITRATION_LOST(pIicBase, param) \
  periphBitTest(IIC_IBSR_IBAL, &((pIicBase)->stat)) 

/* Get Slave Read/Write status */
#define ioctlIIC_GET_SLAVE_TRANSMIT(pIicBase, param) \
  periphBitTest(IIC_IBSR_SRW, &((pIicBase)->stat)) 

/* Clear I-Bus Interrupt flag */
#define ioctlIIC_CLEAR_I_BUS_INT(pIicBase, param) \
    periphMemWrite(IIC_IBSR_IBIF, &((pIicBase)->stat))

/* Get I-Bus Interrupt flag */
#define ioctlIIC_GET_I_BUS_INT(pIicBase, param) \
  periphBitTest(IIC_IBSR_IBIF, &((pIicBase)->stat))

/* Get Received Acknowledge flag */
#define ioctlIIC_GET_RX_ACK(pIicBase, param) \
  periphBitTest(IIC_IBSR_RXAK, &((pIicBase)->stat))

/***********************************************************************
* I2C data register
***********************************************************************/

/* Read IIC Bus Data I/O Register as UWord16, never optimize out */
#define ioctlIIC_READ_DATA(pIicBase, param)  \
  periphMemForcedRead(&((pIicBase)->data))

/* Write IIC Bus Data I/O Register  */
#define ioctlIIC_WRITE_DATA(pIicBase, param) \
  periphMemWrite(param, &((pIicBase)->data))

/***********************************************************************
* I2C Control register 2
***********************************************************************/

/* IICC2 */
/* Enable/Disable general call address */
#define ioctlIIC_SET_GENERAL_CALL_ADDRESS(pIicBase, param) \
  if (param) periphBitSet(IIC_IICC2_GCAEN, &((pIicBase)->iicc2)); \
  else periphBitClear(IIC_IICC2_GCAEN, &((pIicBase)->iicc2))

/* Set the number of bits used for the slave address. */
#define ioctlIIC_SET_ADDRESS_EXTENSION_MODE(pIicBase, param) \
  if (param) periphBitSet(IIC_IICC2_ADEXT, &((pIicBase)->iicc2)); \
  else periphBitClear(IIC_IICC2_ADEXT, &((pIicBase)->iicc2))

/* Set upper 3 bits in 10bit adress mode */
#define ioctlIIC_SET_ADDRESS_EXTENSION(pIicBase, param) \
  periphBitGrpSet(IIC_IICC2_ADR_MASK, param, &((pIicBase)->iicc2))

/* Set slave address in 10bit adress mode (0-1023) */
#define ioctlIIC_SET_10BIT_ADDRESS(pIicBase, param) \
  periphBitGrpSet(IIC_IICC2_ADR_MASK, (param) >> 7, &((pIicBase)->iicc2)) \
  periphMemWrite((param) << 1, &((pIicBase)->addr1))


/* NULL, read IIC Address (0-1023) */
#define ioctlIIC_GET_10BIT_ADDRESS(pIicBase, param) \
  ( (periphMemRead(&((pIicBase)->addr1)) >> 1) | \
  ( (periphMemRead(&((pIicBase)->iicc2))&IIC_IICC2_ADR_MASK) << 7 ) )


/* IICSMB register */
#if IIC_VERSION <=3
/* Enable/Disable sending ACK/NACK automatically */
#define ioctlIIC_SET_FAST_ACK_NACK(pIicBase, param) \
  if (param) periphSafeBitSet(IIC_IICSMB_SLTF, IIC_IICSMB_FACK, &((pIicBase)->iicsmb)); \
  else periphSafeBitClear(IIC_IICSMB_SLTF, IIC_IICSMB_FACK, &((pIicBase)->iicsmb))

/* Enable/Disable SMBus alert response address */
#define ioctlIIC_SET_SMBUS_RESPONSE_ADDRESS(pIicBase, param) \
  if (param) periphSafeBitSet(IIC_IICSMB_SLTF, IIC_IICSMB_ALERTEN, &((pIicBase)->iicsmb)); \
  else periphSafeBitClear(IIC_IICSMB_SLTF, IIC_IICSMB_ALERTEN, &((pIicBase)->iicsmb))

/* Enable/Disable SMBus device default address */
#define ioctlIIC_SET_SECOND_IIC_ADDRESS(pIicBase, param) \
  if (param) periphSafeBitSet(IIC_IICSMB_SLTF, IIC_IICSMB_SIICAEN, &((pIicBase)->iicsmb)); \
  else periphSafeBitClear(IIC_IICSMB_SLTF, IIC_IICSMB_SIICAEN, &((pIicBase)->iicsmb))

/* Enable/Disable SMBus device default address */
#define ioctlIIC_SET_TIME_OUT_CLOCK(pIicBase, param) \
  if (param) periphSafeBitSet(IIC_IICSMB_SLTF, IIC_IICSMB_TCKSEL, &((pIicBase)->iicsmb)); \
  else periphSafeBitClear(IIC_IICSMB_SLTF, IIC_IICSMB_TCKSEL, &((pIicBase)->iicsmb))

/* clear low timeout flags */
#define ioctlIIC_CLEAR_LOW_TIMEOUT_FLAG(pIicBase, param) \
  periphBitSet(IIC_IICSMB_SLTF, &((pIicBase)->iicsmb)) 

#endif /* IIC_VERSION <=3 */

/* test state of timeout flags */
#define ioctlIIC_TEST_TIMEOUT_FLAGS(pIicBase, param) \
  periphBitTest(param, &((pIicBase)->iicsmb)) 

/* UWord16, Write to the SMBUS IIC Bus Address Register (0-127) */
#define ioctlIIC_SET_SMBUS_ADDRESS(pIicBase, param) \
  periphMemWrite((param) << 1, &((pIicBase)->iica2))

/* NULL, read SMBUS IIC Address (0-127) */
#define ioctlIIC_GET_SMBUS_ADDRESS(pIicBase, param) \
  (periphMemRead(&((pIicBase)->iica2)) >> 1)

/* Write to the SCL LowTime Out Register */
#define ioctlIIC_WRITE_SCL_LOW_TIMEOUT(pIicBase, param) \
  periphMemWrite( (param) >> 8, &((pIicBase)->iicslth)); \
  periphMemWrite(param, &((pIicBase)->iicsltl))

/* NULL, Read the SCL LowTime Out Register */
#define ioctlIIC_READ_SCL_LOW_TIMEOUT(pIicBase, param) \
  ( periphMemRead(&((pIicBase)->iicsltl)) | \
  (periphMemRead(&((pIicBase)->iicslth)) << 8) )


#if IIC_VERSION >=4
/* correct old commands*/
/* Enable/Disable sending ACK/NACK automatically */
#define ioctlIIC_SET_FAST_ACK_NACK(pIicBase, param) \
  if (param) periphSafeBitSet(IIC_IICSMB_SLTF | IIC_IICSMB_SHTF2, IIC_IICSMB_FACK, &((pIicBase)->iicsmb)); \
  else periphSafeBitClear(IIC_IICSMB_SLTF | IIC_IICSMB_SHTF2, IIC_IICSMB_FACK, &((pIicBase)->iicsmb))

/* Enable/Disable SMBus alert response address */
#define ioctlIIC_SET_SMBUS_RESPONSE_ADDRESS(pIicBase, param) \
  if (param) periphSafeBitSet(IIC_IICSMB_SLTF | IIC_IICSMB_SHTF2, IIC_IICSMB_ALERTEN, &((pIicBase)->iicsmb)); \
  else periphSafeBitClear(IIC_IICSMB_SLTF | IIC_IICSMB_SHTF2, IIC_IICSMB_ALERTEN, &((pIicBase)->iicsmb))

/* Enable/Disable SMBus device default address */
#define ioctlIIC_SET_SECOND_IIC_ADDRESS(pIicBase, param) \
  if (param) periphSafeBitSet(IIC_IICSMB_SLTF | IIC_IICSMB_SHTF2, IIC_IICSMB_SIICAEN, &((pIicBase)->iicsmb)); \
  else periphSafeBitClear(IIC_IICSMB_SLTF | IIC_IICSMB_SHTF2, IIC_IICSMB_SIICAEN, &((pIicBase)->iicsmb))

/* Enable/Disable SMBus device default address */
#define ioctlIIC_SET_TIME_OUT_CLOCK(pIicBase, param) \
  if (param) periphSafeBitSet(IIC_IICSMB_SLTF | IIC_IICSMB_SHTF2, IIC_IICSMB_TCKSEL, &((pIicBase)->iicsmb)); \
  else periphSafeBitClear(IIC_IICSMB_SLTF | IIC_IICSMB_SHTF2, IIC_IICSMB_TCKSEL, &((pIicBase)->iicsmb))

/* clear low timeout flags */
#define ioctlIIC_CLEAR_LOW_TIMEOUT_FLAG(pIicBase, param) \
  periphBitClear(IIC_IICSMB_SHTF2, &((pIicBase)->iicsmb)) 
  /*instruction bfclear reads, masks and returns data, if IIC_IICSMB_SLTF flag is set, returns back 1 and clears the flag, 
  flag IIC_IICSMB_SHTF2 is not cleared, because instruction sets this bit to 0 and returns 0.*/   


/* new commands in version 4*/
/* Enables/Disables wakeup function in stop mode */
#define ioctlIIC_SET_WAKEUP_IN_STOP(pIicBase, param) \
  if (param) periphBitSet(IIC_IBCR_WUEN, &((pIicBase)->ctrl1)); \
  else periphBitClear(IIC_IBCR_WUEN, &((pIicBase)->ctrl1))

/* clears high timeout flag 2 */
#define ioctlIIC_CLEAR_HIGH_TIMEOUT_FLAG2(pIicBase, param) \
  periphBitClear(IIC_IICSMB_SLTF, &((pIicBase)->iicsmb)) 
  /*instruction bfclear reads, masks and returns data, if IIC_IICSMB_SHTF2 flag is set, returns back 1 and clears the flag, 
  flag IIC_IICSMB_SLTF is not cleared, because instruction sets this bit to 0 and returns 0.*/   

/* clears selected timeout flags  */
#define ioctlIIC_CLEAR_TIMEOUT_FLAGS(pIicBase, param) \
  periphSafeAckByOne(IIC_IICSMB_SLTF|IIC_IICSMB_SHTF2, (param), &((pIicBase)->iicsmb)) 

/* Enable/Disable High Timeout 2 Interrupt */
#define ioctlIIC_SET_HIGH_TIMEOUT2_INTERRUPT(pIicBase, param) \
  if (param) periphSafeBitSet(IIC_IICSMB_SLTF | IIC_IICSMB_SHTF2, IIC_IICSMB_SHTF2IE, &((pIicBase)->iicsmb)); \
  else periphSafeBitClear(IIC_IICSMB_SLTF | IIC_IICSMB_SHTF2, IIC_IICSMB_SHTF2IE, &((pIicBase)->iicsmb))

#endif /* IIC_VERSION >=4 */

#if IIC_VERSION ==4
/* UWord16, Writes to the glitch filter register  (0-7) */
#define ioctlIIC_SET_GLITCH_FILTER(pIicBase, param) \
  periphMemWrite( (param), &((pIicBase)->iicfilt))
#endif /* IIC_VERSION >=4 */


#if IIC_VERSION >= 5
/* fdiv */
/* UWord16, Write to IIC-Bus Frequency Divider Register */
#define ioctlIIC_WRITE_FREQ_DIV_REG(pIicBase, param) \
  periphMemWrite(param, &((pIicBase)->iicf))

/* NULL, Read the IIC-Bus Frequency Divider Register as UWord16 */
#define ioctlIIC_READ_FREQ_DIV_REG(pIicBase, param)  \
  periphMemRead(&((pIicBase)->iicf))


/* iicsmb */
/* UWord16, Write to IIC-Bus SMBus Control and Status register, 
note: inappropriate write to register can clear Write-1-to-Clear (SLTF/SHTF2) flags */
#define ioctlIIC_WRITE_SMBUS_REG(pIicBase, param) \
  periphMemWrite(param, &((pIicBase)->iicsmb))

/* NULL, Read the IIC-Bus SMBus Control and Status as UWord16 */
#define ioctlIIC_READ_SMBUS_REG(pIicBase, param)  \
  periphMemRead(&((pIicBase)->iicsmb))


/* addr2 */
/* UWord16, Write to IIC-Bus Address Register 2 */
#define ioctlIIC_WRITE_ADDRESS2_REG(pIicBase, param) \
  periphMemWrite(param, &((pIicBase)->iica2))

/* NULL, Read the IIC-Bus Address Register 2 as UWord16 */
#define ioctlIIC_READ_ADDRESS2_REG(pIicBase, param)  \
  periphMemRead(&((pIicBase)->iica2))


/* ra */
/* UWord16, Write to the Range slave address Register (0-127) */
#define ioctlIIC_SET_RANGE_SLAVE_ADDRESS(pIicBase, param) \
  periphMemWrite(((param) << 1) & IIC_IICRA_RAD, &((pIicBase)->iicra))

/* NULL, get the slave address range (0-127) */
#define ioctlIIC_GET_RANGE_SLAVE_ADDRESS(pIicBase, param) \
  (periphMemRead(&((pIicBase)->iicra)) >> 1)

/* Write to IIC-Bus Range Address Register  */
#define ioctlIIC_WRITE_RANGE_ADDRESS_REG(pIicBase, param) \
  periphMemWrite(param, &((pIicBase)->iicra))

/* Read the IIC-Bus Range Address Register as UWord16 */
#define ioctlIIC_READ_RANGE_ADDRESS_REG(pIicBase, param)  \
  periphMemRead(&((pIicBase)->iicra))


/* ctrl1 */
/* Enable/Disable DMA function, while/when FACK=0/1 byte is received/transmitted */
#define ioctlIIC_SET_DMA_TRANSFER(pIicBase, param) \
  if (param) periphBitSet(IIC_IBCR_DMAEN, &((pIicBase)->iicc1)); \
  else periphBitClear(IIC_IBCR_DMAEN, &((pIicBase)->iicc1))


/* ctrl2 */
/* Enable/Disable high drive capability of the I2C pads */
#define ioctlIIC_SET_HIGH_DRIVE_PADS(pIicBase, param) \
  if (param) periphBitSet(IIC_IICC2_HDRS, &((pIicBase)->iicc2)); \
  else periphBitClear(IIC_IICC2_HDRS, &((pIicBase)->iicc2))

/* Enable/Disable independent slave mode baud rate at max frequency, forces clock stretching on SCL */
#define ioctlIIC_SET_SLAVE_BAUD_RATE_CTRL(pIicBase, param) \
  if (param) periphBitSet(IIC_IICC2_SBRC, &((pIicBase)->iicc2)); \
  else periphBitClear(IIC_IICC2_SBRC, &((pIicBase)->iicc2))

/* Enable/Disable independent slave mode baud rate at max frequency, forces clock stretching on SCL */
#define ioctlIIC_SET_RANGE_MODE(pIicBase, param) \
  if (param) periphBitSet(IIC_IICC2_RMEN, &((pIicBase)->iicc2)); \
  else periphBitClear(IIC_IICC2_RMEN, &((pIicBase)->iicc2))

/* UWord16, Write to IIC-Bus Control Register 2 */
#define ioctlIIC_WRITE_CONTROL2_REG(pIicBase, param) \
  periphMemWrite(param, &((pIicBase)->iicc2))

/* NULL, Read the IIC-Bus Control Register 2 as UWord16 */
#define ioctlIIC_READ_CONTROL2_REG(pIicBase, param)  \
  periphMemRead(&((pIicBase)->iicc2))


/* filt - contains w1c flags */
/* Enable/Disable waiting to finish currently transfered data, then enter stop mode */
#define ioctlIIC_SET_HOLD_OFF_TO_STOP(pIicBase, param) \
  if (param) periphSafeBitSet(IIC_IICFILT_STOPF | IIC_IICFILT_STARTF, IIC_IICFILT_SHEN, &((pIicBase)->iicfilt)); \
  else periphSafeBitClear(IIC_IICFILT_STOPF | IIC_IICFILT_STARTF, IIC_IICFILT_SHEN, &((pIicBase)->iicfilt))

/* Enable/Disable the interrupt for I2C bus stop or start detection */
#define ioctlIIC_SET_STOP_START_INT(pIicBase, param) \
  if (param) periphSafeBitSet(IIC_IICFILT_STOPF | IIC_IICFILT_STARTF, IIC_IICFILT_SSIE, &((pIicBase)->iicfilt)); \
  else periphSafeBitClear(IIC_IICFILT_STOPF | IIC_IICFILT_STARTF, IIC_IICFILT_SSIE, &((pIicBase)->iicfilt))

/* UWord16, Writes to the glitch filter register  (0-7), 827xx (0-15) */
#define ioctlIIC_SET_GLITCH_FILTER(pIicBase, param) \
  if (param) periphSafeBitGrpSet(IIC_IICFILT_STOPF | IIC_IICFILT_STARTF, IIC_IICFILT_FLT_MASK, (param), &((pIicBase)->iicfilt)); \
  else periphSafeBitClear(IIC_IICFILT_STOPF | IIC_IICFILT_STARTF, IIC_IICFILT_FLT_MASK, &((pIicBase)->iicfilt))

/* test state of start/stop detect flags */
#define ioctlIIC_TEST_STOP_START_FLAGS(pIicBase, param) \
  periphBitTest((param), &((pIicBase)->iicfilt)) 

/* clear  selected start/stop detect flags  */
#define ioctlIIC_CLEAR_STOP_START_FLAGS(pIicBase, param) \
  periphSafeAckByOne(IIC_STOP_FLAG | IIC_START_FLAG, (param), &((pIicBase)->iicfilt)) 

/* Write to IIC-Bus Programmable Input Glitch Filter Register  */
#define ioctlIIC_WRITE_GLITCH_FILTER_REG(pIicBase, param) \
  periphMemWrite(param, &((pIicBase)->iicfilt))

/* Read the IIC-Bus Programmable Input Glitch Filter Register as UWord16 */
#define ioctlIIC_READ_GLITCH_FILTER_REG(pIicBase, param)  \
  periphMemRead(&((pIicBase)->iicfilt))
  
  
/* iicslth */
/* UWord16, Write to IIC-Bus SCL Low Timeout MSByte of Register */
#define ioctlIIC_WRITE_SCL_LOW_TIMEOUT_HIGH_REG(pIicBase, param) \
  periphMemWrite(param, &((pIicBase)->iicslth))

/* NULL, Read the IIC-Bus SCL Low Timeout MSByte Register as UWord16 */
#define ioctlIIC_READ_SCL_LOW_TIMEOUT_HIGH_REG(pIicBase, param)  \
  periphMemRead(&((pIicBase)->iicslth))


/* iicsltl */
/* UWord16, Write to IIC-Bus SCL Low Timeout LSByte of Register */
#define ioctlIIC_WRITE_SCL_LOW_TIMEOUT_LOW_REG(pIicBase, param) \
  periphMemWrite(param, &((pIicBase)->iicsltl))

/* NULL, Read the IIC-Bus SCL Low Timeout LSByte Register as UWord16 */
#define ioctlIIC_READ_SCL_LOW_TIMEOUT_LOW_REG(pIicBase, param)  \
  periphMemRead(&((pIicBase)->iicsltl))

#endif /* IIC_VERSION >=5 */


#ifdef __cplusplus
}
#endif

#endif
