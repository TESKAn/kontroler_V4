/*****************************************************************************
* 
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  fcan.h
*
* $Date:      Jun-25-2013$
*
* $Version:   2.6.5.0$
*
* Description: FlexCAN driver macros and definitions
*
*****************************************************************************/

#ifndef __FCAN_H
#define __FCAN_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before fcan.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************
* FlexCAN module identifier, corresponds to module base address
****************************************************************/

#ifdef CAN_BASE
#define FCAN  (&ArchIO.FCan)
#endif


/*************************************************************
* arch.h should define device-specific information about FCAN
**************************************************************/

#if !defined(FCAN_VERSION)
#error FCAN is not properly described in arch.h (old Quick_Start version?)
#endif

#if FCAN_VERSION != 2
#error This driver supports FlexCAN module version 2 only
#endif

/******************************************************************************
*
*                      General Interface Description
*
*
* The FlexCAN module is a communication controller implementing the CAN protocol.
* The CAN protocol was primarily designed to be used as a vehicle serial data bus,
* meeting the specific requirements of:
*   • Real-time processing
*   • Reliable operation in the EMI environment of a vehicle
*   • Cost-effectiveness and required bandwidth
*
* For more information, please refer to the user manual for the particular
* chip that you are using, such as the MC56F84xx Peripheral Manual,
* for a description of the FlexCAN device.
*
* The FlexCAN device driver interface uses "ioctl" call to control specific
* FlexCAN functions during operation. For details see "ioctl" call.
*
******************************************************************************/

/***************************************************************
* FlexCAN Message Buffer identifiers, corresponds to MB address
****************************************************************/
typedef arch_sFlexCAN_MB FCAN_MB;

#ifdef FCAN
#define FCAN_MB0    (&ArchIO.FCan.mb[0])
#define FCAN_MB1    (&ArchIO.FCan.mb[1])
#define FCAN_MB2    (&ArchIO.FCan.mb[2])
#define FCAN_MB3    (&ArchIO.FCan.mb[3])
#define FCAN_MB4    (&ArchIO.FCan.mb[4])
#define FCAN_MB5    (&ArchIO.FCan.mb[5])
#define FCAN_MB6    (&ArchIO.FCan.mb[6])
#define FCAN_MB7    (&ArchIO.FCan.mb[7])
#define FCAN_MB8    (&ArchIO.FCan.mb[8])
#define FCAN_MB9    (&ArchIO.FCan.mb[9])
#define FCAN_MB10   (&ArchIO.FCan.mb[10])
#define FCAN_MB11   (&ArchIO.FCan.mb[11])
#define FCAN_MB12   (&ArchIO.FCan.mb[12])
#define FCAN_MB13   (&ArchIO.FCan.mb[13])
#define FCAN_MB14   (&ArchIO.FCan.mb[14])
#define FCAN_MB15   (&ArchIO.FCan.mb[15])
#define FCAN_MB16   (&ArchIO.FCan.mb[16])
#define FCAN_MB17   (&ArchIO.FCan.mb[17])
#define FCAN_MB18   (&ArchIO.FCan.mb[18])
#define FCAN_MB19   (&ArchIO.FCan.mb[19])
#define FCAN_MB20   (&ArchIO.FCan.mb[20])
#define FCAN_MB21   (&ArchIO.FCan.mb[21])
#define FCAN_MB22   (&ArchIO.FCan.mb[22])
#define FCAN_MB23   (&ArchIO.FCan.mb[23])
#define FCAN_MB24   (&ArchIO.FCan.mb[24])
#define FCAN_MB25   (&ArchIO.FCan.mb[25])
#define FCAN_MB26   (&ArchIO.FCan.mb[26])
#define FCAN_MB27   (&ArchIO.FCan.mb[27])
#define FCAN_MB28   (&ArchIO.FCan.mb[28])
#define FCAN_MB29   (&ArchIO.FCan.mb[29])
#define FCAN_MB30   (&ArchIO.FCan.mb[30])
#define FCAN_MB31   (&ArchIO.FCan.mb[31])
#endif


/***********************************************************************
* FlexCAN static configuration items for appconfig.h
***********************************************************************/
/*
    #define FCAN_MCR_INIT                     0x00000000U
    #define FCAN_CTRL1_INIT                   0x00000000U
    #define FCAN_IMASK1_INIT                  0x00000000U
    #define FCAN_RXMGMASK_INIT                0x00000000U
    #define FCAN_RX14MASK_INIT                0x00000000U
    #define FCAN_RX15MASK_INIT                0x00000000U
    #define FCAN_CTRL2_INIT                   0x00000000U
    #define FCAN_RXFGMASK_INIT                0x00000000U
    #define FCAN_RXIMR0_INIT                  0x00000000U
    #define FCAN_RXIMR1_INIT                  0x00000000U
    #define FCAN_RXIMR2_INIT                  0x00000000U
    #define FCAN_RXIMR3_INIT                  0x00000000U
    #define FCAN_RXIMR4_INIT                  0x00000000U
    #define FCAN_RXIMR5_INIT                  0x00000000U
    #define FCAN_RXIMR6_INIT                  0x00000000U
    #define FCAN_RXIMR7_INIT                  0x00000000U
    #define FCAN_RXIMR8_INIT                  0x00000000U
    #define FCAN_RXIMR9_INIT                  0x00000000U
    #define FCAN_RXIMR10_INIT                 0x00000000U
    #define FCAN_RXIMR11_INIT                 0x00000000U
    #define FCAN_RXIMR12_INIT                 0x00000000U
    #define FCAN_RXIMR13_INIT                 0x00000000U
    #define FCAN_RXIMR14_INIT                 0x00000000U
    #define FCAN_RXIMR15_INIT                 0x00000000U

    #define INTERRUPT_VECTOR_ADDR_yy  // specify interrupt handler routine
    #define INT_PRIORITY_LEVEL_yy     // interrupt level : (INTC_DISABLED, INTC_LEVEL0,
                                      //                   INTC_LEVEL1 or INTC_LEVEL2)
    where:
         yy  is interrupt vector number
            e.g. On 56F8346
                26 - FlexCAN Bus-Off
                27 - FlexCAN Error
                28 - FlexCAN Wake-up
                29 - FlexCAN Message Buffer Interrupt
*/

/***************************************************
* FlexCAN ioctl commands
****************************************************/
/* command                    |        Param       */

#define FCAN_INIT                /* NULL, Initialize FlexCAN peripheral registers using the appconfig.h _INIT values  */
#define FCAN_MODULE              /* FCAN_ENABLE/FCAN_DISABLE, Enable or disable the FlexCAN module  */
#define FCAN_DOZE_MODE           /* FCAN_ENABLE/FCAN_DISABLE, Enable/disable Low-power Doze (Stop) Mode  */  
#define FCAN_STOP_MODE           /* FCAN_ENABLE/FCAN_DISABLE, Backward compatibility alias for FCAN_DOZE_MODE */  
#define FCAN_DEBUG_MODE          /* FCAN_ENABLE/FCAN_DISABLE, Enter/Leave Freeze (Debug/halt) mode */

#define FCAN_SOFT_RESET          /* NULL, Trigger the soft-reset of the FlexCAN module. Do not use in when FlexCAN is in low power mode. */

#define FCAN_SELF_WAKEUP_MODE    /* FCAN_ENABLE/FCAN_DISABLE, Enable or disable Self-Wakeup mode when bus activity is detected.*/

#define FCAN_TEST_READY          /* NULL, Test if FlexCAN module is ready (MCR.NOTRDY bit cleared). */
#define FCAN_TEST_DEBUG          /* NULL, Test if FlexCAN is in the Freeze mode (MCR.FREEZ_ACK bit). */
#define FCAN_TEST_STOP           /* NULL, Test if FlexCAN module is in the Low-power mode (MCR.LPMACK bit). */

#define FCAN_INT_ENABLE          /* FCAN_xxx_INT (xxx=BUSOFF|ERROR|WAKEUP|TX_WARNING|RX_WARNING), Enable selected interrupts. Note that the RX and TX Warning interrupts first need to be enabled by the FCAN_WARNING_INTERRUPT command.*/
#define FCAN_INT_DISABLE         /* FCAN_xxx_INT (xxx=BUSOFF|ERROR|WAKEUP|TX_WARNING|RX_WARNING), Disable selected interrupts. */
#define FCAN_WARNING_INTERRUPT   /* FCAN_ENABLE/FCAN_DISABLE, Enable or disable occurrence of warning interrupts; when enabled, the RX and/or TX warning interrupts still need to be enabled by the FCAN_INT_ENABLE command. */ 

#define FCAN_LOOPBACK_MODE       /* FCAN_ENABLE/FCAN_DISABLE, Enable or disable test loopback mode. */
#define FCAN_TIMER_SYNC_MODE     /* FCAN_ENABLE/FCAN_DISABLE, Enable or disable Timer Sync mode. In this mode the free-running timer is reset each time a message is received in Message Buffer 0.  */
#define FCAN_LISTEN_ONLY_MODE    /* FCAN_ENABLE/FCAN_DISABLE, Enable or disable Listen Only mode. No acknowledge signal is generated. Only messages acknowledged by other CAN nodes are received. */
#define FCAN_SET_TX_FIRST_SCHEME /* FCAN_HIGHEST_PRIORITY/FCAN_LOWEST_MB_NUMBER, Set ordering mechanism for Message Buffer transmission. Either a buffer with highest assigned priority or a buffer with the lowest number is transmitted first. */

#define FCAN_INDIVIDUAL_RX_MASKING /* FCAN_ENABLE/FCAN_DISABLE, Enable or disable Individual RX mask registers. */

#define FCAN_SET_CLOCK_SOURCE    /* FCAN_OSCILATOR_CLOCK/FCAN_PERIPHERAL_CLOCK, Set Clock Source for CAN engine. */
#define FCAN_SUPERVISOR_MODE     /* FCAN_ENABLE/FCAN_DISABLE, Enable or disable Supervisor Mode. In Supervisor mode certain registers are only accessible when CPU operates in privileged mode. */
#define FCAN_WAKEUP_SOURCE       /* FCAN_UNFILTERED_RX / FCAN_FILTERED_RX, Select Wake Up Source. */  
#define FCAN_SELF_RECEPTION      /* FCAN_ENABLE/FCAN_DISABLE, Enable or disable reception of self-transmitted frames. */
#define FCAN_LOCAL_PRIORITY      /* FCAN_ENABLE/FCAN_DISABLE, Enable or disable TX priority to be set in individual MBs by using FCANMB_SET_TX_PRIORITY command. Note that this requires the FCAN_HIGHEST_PRIORITY mode to be set by the FCAN_SET_TX_FIRST_SCHEME command. */
#define FCAN_TX_ABORT_OPERATION  /* FCAN_ENABLE/FCAN_DISABLE, Enable or disable TX Abort operation. */ 

#define FCAN_SET_SAMPLING        /* FCAN_1SAMP_PER_BIT / FCAN_3SAMPS_PER_BIT, Set number of hardware samples per bit. */
#define FCAN_SET_PRESCALER       /* UWord (0-255), Set PRES_DIV prescaler divisor. */
#define FCAN_SET_RJW             /* FCAN_RJW_x  (x=1-4), Set RJW bit time parameter. */
#define FCAN_SET_PROP_SEG        /* FCAN_PROPSEG_n (n=1...8) or UWord16 (value 0-7), Set PROP_SEG bit time parameter.*/
#define FCAN_SET_PHASE_SEG1      /* FCAN_PSEG_n (n=1...8) or UWord16 (value 0-7), Set PHASE_SEG1 bit time parameter. */
#define FCAN_SET_PHASE_SEG2      /* FCAN_PSEG_n (n=1...8) or UWord16 (value 0-7), Set PHASE_SEG2 bit time parameter. */

#define FCAN_UNLOCK_ALL_MB       /* NULL, Unlocks all message boxes by reading the free running timer register. */

#define FCAN_GET_MAXMB           /* NULL, Get maximum number of MB used. */
#define FCAN_SET_MAXMB           /* UWord16 (number 0-15), Set maximum number of MB used. */

#define FCAN_READ_ERR_AND_STATUS /* NULL, Read value of error and status register (error bits are self-cleared by reading).  */

#define FCAN_CLEAR_INT            /* FCAN_ESR1_xxx (BOFFINT|ERRINT|WAKINT|TWRNINT|RWRNINT), Clear selected interrupt flags. */
#define FCAN_CLEAR_BOFF_INT       /* NULL, Clear BusOff interrupt flag. */
#define FCAN_CLEAR_ERR_INT        /* NULL, Clear Error interrupt flag. */
#define FCAN_CLEAR_WAKE_INT       /* NULL, Clear WakeUp interrupt flag. */
#define FCAN_CLEAR_RX_WARNING_INT /* NULL, Clear Rx Warning Interrupt flag. */
#define FCAN_CLEAR_TX_WARNING_INT /* NULL, Clear Tx Warning Interrupt flag. */

#define FCAN_MBINT_ENABLE        /* UWord16 with MB bits or combination of FCAN_MBINT_x (x=0...MAXMB), Enable selected MB interrupts.*/
#define FCAN_MBINT_DISABLE       /* UWord16 with MB bits or combination of FCAN_MBINT_x (x=0...MAXMB), Disable selected MB interrupts. */
#define FCAN_READ_MBINT_FLAGS    /* NULL, Get all MB interrupt flags. */
#define FCAN_CLEAR_MBINT_FLAGS   /* UWord16 with MB bits or combination of FCAN_MBINT_x (x=0...MAXMB), Clear selected MB interrupts. */

#define FCAN_SET_RXMGMASK        /* UWord32 mask value; optionally combined with FCAN_ID_EXT or FCAN_ID_RTR flags,	Set Global RX mask which affects the MB0-MB13. Logic ones in the mask determines bits which are compared in ID filtering process. Logic zeros identify don't care bits. */
#define FCAN_SET_RXMGMASK_V      /* UWord32 mask value; optionally combined with FCAN_ID_EXT or FCAN_ID_RTR flags,	Set Global RX mask, implemented as a function call. Use when passing a variable as a parameter. */
#define FCAN_SET_RXMGMASK_RAW    /* UWord32 mask value in raw register format,	Set Global RX mask register directly. */
#define FCAN_SET_RX14MASK        /* UWord32 mask value; optionally combined with FCAN_ID_EXT or FCAN_ID_RTR flags,	Set MB14 RX mask. Logic ones in the mask determines bits which are compared in ID filtering process. Logic zeros identify don't care bits. */
#define FCAN_SET_RX14MASK_V      /* UWord32 mask value; optionally combined with FCAN_ID_EXT or FCAN_ID_RTR flags,	Set MB14 RX mask, implemented as a function call. Use when passing a variable as a parameter. */
#define FCAN_SET_RX14MASK_RAW    /* UWord32 mask value in raw register format,	Set MB14 RX mask register directly. */
#define FCAN_SET_RX15MASK        /* UWord32 mask value; optionally combined with FCAN_ID_EXT or FCAN_ID_RTR flags,	Set MB15 RX mask. Logic ones in the mask determines bits which are compared in ID filtering process. Logic zeros identify don't care bits. */
#define FCAN_SET_RX15MASK_V      /* UWord32 mask value; optionally combined with FCAN_ID_EXT or FCAN_ID_RTR flags,	Set MB15 RX mask, implemented as a function call. Use when passing a variable as a parameter. */
#define FCAN_SET_RX15MASK_RAW    /* UWord32 mask value in raw register format,	Set MB15 RX mask register directly. */

#define FCAN_GET_RX_ERR_COUNT    /* NULL, Read RX error counter. */
#define FCAN_GET_TX_ERR_COUNT    /* NULL, Read TX error counter. */

#define FCAN_GET_MB_MODULE      /* UWord16 with MB index,	Get pointer to specified MB module. Use the return value with any FCANMB_ commands.*/

/* Note: this driver and example application does not support the FIFO-mode */
#define FCAN_RXFIFO_OPERATION    /* FCAN_ENABLE/FCAN_DISABLE, Enable or disable the Receiver FIFO. Beware, this option breaks a compatibility with older FlexCAN modules. The FIFO mode is not supported by the 56F800EX_Quick_Start. */
#define FCAN_ID_ACCEPTANCE_MODE  /* FCAN_ONE_FULL_ID/ FCAN_TWO_FULL_STD_IDS/FCAN_FOUR_PARTIAL_IDS/FCAN_ALL_FRAMES_REJECTED, Set FIFO ID filter Acceptance Mode. Note that FIFO mode is not supported by this version of the FCAN driver. */
#define FCAN_RXFIFO_INT_ENABLE   /* FCAN_RXFIFO_OVERFLOW_INT|FCAN_RXFIFO_WARNING_INT|FCAN_FRAMES_IN_RXFIFO_INT,	Enable interrupts when operating in FIFO mode. Note that FIFO mode is not supported by this version of the FCAN driver. */
#define FCAN_RXFIFO_INT_DISABLE  /* FCAN_RXFIFO_OVERFLOW_INT|FCAN_RXFIFO_WARNING_INT|FCAN_FRAMES_IN_RXFIFO_INT,	Disable interrupts when operating in FIFO mode. Note that FIFO mode is not supported by this version of the FCAN driver. */
#define FCAN_READ_RXFIFO_FLAGS   /* FCAN_RXFIFO_OVERFLOW_INT|FCAN_RXFIFO_WARNING_INT|FCAN_FRAMES_IN_RXFIFO_INT,	Read and test specified FIFO interrupts when operating in FIFO mode. Note that FIFO mode is not supported by this version of the FCAN driver */ 
#define FCAN_CLEAR_RXFIFO_FLAGS  /* FCAN_RXFIFO_OVERFLOW_INT|FCAN_RXFIFO_WARNING_INT|FCAN_FRAMES_IN_RXFIFO_INT,	Clear FIFO interrupts when operating in FIFO mode. Note that FIFO mode is not supported by this version of the FCAN driver. */ 

/****************************************************************************
 the following commands operate on the Message Buffer module identifier, 
 use with FCAN_MBx constants or with a pointer value returned by FCAN_GET_MB_MODULE 
*****************************************************************************/

#define FCANMB_GET_ID           /* NULL, Parse the ID from the appropriate bits in given MB. The returned value is numerical ID, with FCAN_ID_EXT bit set for extended frames.  */

#define FCANMB_SET_ID           /* UWord32 ID value, optionally combined with FCAN_ID_EXT or FCAN_ID_RTR flags,	Set given ID to the MB. This command takes care about converting a numerical ID into a format suitable for writing into the MB registers. */
#define FCANMB_SET_ID_V         /* UWord32 ID value, optionally combined with FCAN_ID_EXT or FCAN_ID_RTR flags,	Set given ID to the MB, implemented as a function call. Use when passing a variable as the command parameter.*/
#define FCANMB_SET_RTR          /* FCAN_ON/FCAN_OFF,	Set or clear RTR bit in given MB. Use before a frame is transmitted.*/

#define FCANMB_SET_LEN          /* UWord16 frame length (value 0-8),	Set data length field of the MB. Use before a frame is transmitted. */
#define FCANMB_SET_ID_RAW       /* UWord32 ID value in raw register format,	Set 32bit raw value into the ID register of the MB. */

#define FCANMB_GET_LEN          /* NULL, Get data length field of the MB. Use after a frame is received. */
#define FCANMB_GET_ID_RAW       /* NULL, Get raw 32bit ID register value. Use FCANMB_GET_ID command when a numerical value is required instead of a raw register value. */
#define FCANMB_GET_TIMESTAMP    /* NULL, Get MB Time Stamp value. The time stamp is a value of the Free Running Timer captured at the moment of frame reception or transmission.  */
#define FCANMB_SET_TX_PRIORITY  /* UWord16 (value 0-7),	Set MB transmission priority. Only applicable when local priority is enabled with FCAN_LOCAL_PRIORITY command. */

#define FCANMB_SET_CODE         /* FCAN_MB_CODE_xxx (xxx=RXVOID/RXEMPTY/RXFULL/TXABORT/TXVOID/TXONCE/TXRTR/TXRALWAYS),	Set code field of the MB. This command controls the reception or transmission of the MB. */
#define FCANMB_GET_CODE         /* NULL, Get code field of the MB to determine its operation status. Compare the value with one of FCAN_MB_CODE_xxx constants. */

#define FCANMB_REORDER_BYTES    /* NULL, Swap bytes in both 32bit data words of the MB. This switches data from CPU-ordered to bus-ordered format and vice versa. */
#define FCANMB_REORDER_WORDS    /* NULL, Swap 16bit words in both 32bit data words of the MB. This switches data between legacy DSC 16bit FlexCAN implementation and the new 32bit implementation. */
#define FCANMB_GET_DATAPTR      /* NULL, This command is not implemented intentionally. The behavior would not be backward compatible with the same command implemented in 16bit FlexCAN module driver. To get access to frame data, use the FCANMB_GET_DATAPTR32 command and be aware of different data byte endianness format. */
#define FCANMB_GET_DATAPTR32    /* NULL, Get a pointer to data buffer of the MB as a pointer to UWord32 word. Note that the endianness of the data register is different than the one of the CAN bus. Use the FCANMB_REORDER_BYTES command to switch between different data formats.  */

/****************************************************************************
* FlexCAN constants and type declarations used in the ioctl functions
*****************************************************************************/

#define FCAN_ENABLE     1
#define FCAN_DISABLE    0

#define FCAN_ON         1
#define FCAN_OFF        0

#define FCAN_OSCILATOR_CLOCK     0
#define FCAN_PERIPHERAL_CLOCK    1

#define FCAN_UNFILTERED_RX       0
#define FCAN_FILTERED_RX         1

#define FCAN_ON                  1
#define FCAN_OFF                 0

/* ID acceptance modes */
#define FCAN_ONE_FULL_ID          FCAN_MCR_IDAM_A
#define FCAN_TWO_FULL_STD_IDS     FCAN_MCR_IDAM_B
#define FCAN_FOUR_PARTIAL_IDS     FCAN_MCR_IDAM_C
#define FCAN_ALL_FRAMES_REJECTED  FCAN_MCR_IDAM_D

/* bit sampling modes */
#define FCAN_1SAMP_PER_BIT       0
#define FCAN_3SAMPS_PER_BIT      1

/* transmit-first schemes */
#define FCAN_HIGHEST_PRIORITY    0
#define FCAN_LOWEST_MB_NUMBER    1

/* Message Buffer interupts */
#define FCAN_MBINT_0    0x0001UL
#define FCAN_MBINT_1    0x0002UL
#define FCAN_MBINT_2    0x0004UL
#define FCAN_MBINT_3    0x0008UL
#define FCAN_MBINT_4    0x0010UL
#define FCAN_MBINT_5    0x0020UL
#define FCAN_MBINT_6    0x0040UL
#define FCAN_MBINT_7    0x0080UL
#define FCAN_MBINT_8    0x0100UL
#define FCAN_MBINT_9    0x0200UL
#define FCAN_MBINT_10   0x0400UL
#define FCAN_MBINT_11   0x0800UL
#define FCAN_MBINT_12   0x1000UL
#define FCAN_MBINT_13   0x2000UL
#define FCAN_MBINT_14   0x4000UL
#define FCAN_MBINT_15   0x8000UL

#define FCAN_MBINT_16   0x00010000UL
#define FCAN_MBINT_17   0x00020000UL
#define FCAN_MBINT_18   0x00040000UL
#define FCAN_MBINT_19   0x00080000UL
#define FCAN_MBINT_20   0x00100000UL
#define FCAN_MBINT_21   0x00200000UL
#define FCAN_MBINT_22   0x00400000UL
#define FCAN_MBINT_23   0x00800000UL
#define FCAN_MBINT_24   0x01000000UL
#define FCAN_MBINT_25   0x02000000UL
#define FCAN_MBINT_26   0x04000000UL
#define FCAN_MBINT_27   0x08000000UL
#define FCAN_MBINT_28   0x10000000UL
#define FCAN_MBINT_29   0x20000000UL
#define FCAN_MBINT_30   0x40000000UL
#define FCAN_MBINT_31   0x80000000UL

/* enabling/disabling interrupts */
#define FCAN_BUSOFF_INT      FCAN_CTRL1_BOFFMSK
#define FCAN_ERROR_INT       FCAN_CTRL1_ERRMSK
#define FCAN_WAKEUP_INT      FCAN_MCR_WAKMSK
#define FCAN_TX_WARNING_INT  FCAN_CTRL1_TWRNMSK
#define FCAN_RX_WARNING_INT  FCAN_CTRL1_RWRNMSK

/* enabling/disabling FIFO interrupts */
#define FCAN_RXFIFO_OVERFLOW_INT           FCAN_MBINT_7
#define FCAN_RXFIFO_WARNING_INT            FCAN_MBINT_6
#define FCAN_FRAMES_IN_RXFIFO_INT          FCAN_MBINT_5

/* timing parameters: RJW */
#define FCAN_RJW_1      0
#define FCAN_RJW_2      1
#define FCAN_RJW_3      2
#define FCAN_RJW_4      3

/* PROP_SEG */
#define FCAN_PROPSEG_1  0
#define FCAN_PROPSEG_2  1
#define FCAN_PROPSEG_3  2
#define FCAN_PROPSEG_4  3
#define FCAN_PROPSEG_5  4
#define FCAN_PROPSEG_6  5
#define FCAN_PROPSEG_7  6
#define FCAN_PROPSEG_8  7

/* PHASE_SEG1 and PHASE_SEG2 */
#define FCAN_PSEG_1     0
#define FCAN_PSEG_2     1
#define FCAN_PSEG_3     2
#define FCAN_PSEG_4     3
#define FCAN_PSEG_5     4
#define FCAN_PSEG_6     5
#define FCAN_PSEG_7     6
#define FCAN_PSEG_8     7

/* bit sampling modes */
#define FCAN_1SAMP_PER_BIT  0
#define FCAN_3SAMPS_PER_BIT 1

/* transmit-first schemes */
#define FCAN_LOWEST_ID          0
#define FCAN_LOWEST_MB_NUMBER   1

/* special flags for passing the ID value */
#define FCAN_ID_EXT 0x80000000UL  /* specifies extended ID anywhere the ID is required */
#define FCAN_ID_RTR 0x40000000UL  /* turns on the RTR bit when calling FCANMB_SET_ID (only) */

/****************************************************************************
* FlexCAN register bit names
*****************************************************************************/

#define FCAN_MCR_MDIS                 0x80000000UL
#define FCAN_MCR_FRZ                  0x40000000UL
#define FCAN_MCR_RFEN                 0x20000000UL
#define FCAN_MCR_HALT                 0x10000000UL
#define FCAN_MCR_NOTRDY               0x08000000UL
#define FCAN_MCR_WAKMSK               0x04000000UL
#define FCAN_MCR_SOFTRST              0x02000000UL
#define FCAN_MCR_FRZACK               0x01000000UL
#define FCAN_MCR_SUPV                 0x00800000UL
#define FCAN_MCR_SLFWAK               0x00400000UL
#define FCAN_MCR_WRNEN                0x00200000UL
#define FCAN_MCR_LPMACK               0x00100000UL
#define FCAN_MCR_WAKSRC               0x00080000UL
#define FCAN_MCR_DOZE                 0x00040000UL
#define FCAN_MCR_SRXDIS               0x00020000UL
#define FCAN_MCR_IRMQ                 0x00010000UL
#define FCAN_MCR_LPRIOEN              0x00002000UL
#define FCAN_MCR_AEN                  0x00001000UL
#define FCAN_MCR_IDAM_MASK            0x00000300UL
#define FCAN_MCR_IDAM_A               0x00000000UL
#define FCAN_MCR_IDAM_B               0x00000100UL
#define FCAN_MCR_IDAM_C               0x00000200UL
#define FCAN_MCR_IDAM_D               0x00000300UL
#define FCAN_MCR_MAXMB_MASK           0x0000007FUL

#define FCAN_MCR_STARTUP_PHASE1 (FCAN_MCR_IRMQ | FCAN_MCR_WRNEN | FCAN_MCR_SRXDIS | FCAN_MCR_RFEN | FCAN_MCR_LPRIOEN | FCAN_MCR_AEN | FCAN_MCR_MAXMB_MASK)

#define FCAN_CTRL1_PRESDIV_MASK       0xFF000000UL
#define FCAN_CTRL1_RJW_MASK           0x00C00000UL
#define FCAN_CTRL1_PSEG1_MASK         0x00380000UL
#define FCAN_CTRL1_PSEG2_MASK         0x00070000UL
#define FCAN_CTRL1_BOFFMSK            0x00008000UL
#define FCAN_CTRL1_ERRMSK             0x00004000UL
#define FCAN_CTRL1_CLKSRC             0x00002000UL
#define FCAN_CTRL1_LPB                0x00001000UL
#define FCAN_CTRL1_TWRNMSK            0x00000800UL
#define FCAN_CTRL1_RWRNMSK            0x00000400UL
#define FCAN_CTRL1_SMP                0x00000080UL
#define FCAN_CTRL1_BOFFREC            0x00000040UL
#define FCAN_CTRL1_TSYN               0x00000020UL
#define FCAN_CTRL1_LBUF               0x00000010UL
#define FCAN_CTRL1_LOM                0x00000008UL
#define FCAN_CTRL1_PROPSEG_MASK       0x00000007UL

#define FCAN_CTRL2_WRMFRZ             0x10000000UL
#define FCAN_CTRL2_RFFN_MASK          0x0F000000UL
#define FCAN_CTRL2_TASD_MASK          0x00F80000UL
#define FCAN_CTRL2_MRP                0x00040000UL
#define FCAN_CTRL2_RRS                0x00020000UL
#define FCAN_CTRL2_EACEN              0x00010000UL

#define FCAN_ESR1_SYNCH               0x00040000UL
#define FCAN_ESR1_TWRNINT             0x00020000UL
#define FCAN_ESR1_RWRNINT             0x00010000UL
#define FCAN_ESR1_BIT1ERR             0x00008000UL
#define FCAN_ESR1_BIT0ERR             0x00004000UL
#define FCAN_ESR1_ACKERR              0x00002000UL
#define FCAN_ESR1_CRCERR              0x00001000UL
#define FCAN_ESR1_FRMERR              0x00000800UL
#define FCAN_ESR1_STFERR              0x00000400UL
#define FCAN_ESR1_TXWRN               0x00000200UL
#define FCAN_ESR1_RXWRN               0x00000100UL
#define FCAN_ESR1_IDLE                0x00000080UL
#define FCAN_ESR1_TX                  0x00000040UL
#define FCAN_ESR1_FLTCONF_MASK        0x00000030UL
#define FCAN_ESR1_RX                  0x00000008UL
#define FCAN_ESR1_BOFFINT             0x00000004UL
#define FCAN_ESR1_ERRINT              0x00000002UL
#define FCAN_ESR1_WAKINT              0x00000001UL

#define FCAN_MB_CS_CODE_MASK          0x0f000000UL
#define FCAN_MB_CS_SRR                0x00400000UL
#define FCAN_MB_CS_IDE                0x00200000UL
#define FCAN_MB_CS_RTR                0x00100000UL
#define FCAN_MB_CS_DLC_MASK           0x000F0000UL
#define FCAN_MB_CS_TIME_STAMP_MASK    0x0000FFFFUL
#define FCAN_MB_ID_PRIO_MASK          0xE0000000UL
#define FCAN_MB_ID_STD_MASK           0x1FFC0000UL
#define FCAN_MB_ID_STD_SHIFT          18
#define FCAN_MB_ID_EXT_MASK           0x1FFFFFFFUL

/* MB codes */
#define FCAN_MB_CODE_RXVOID        0x0   /* buffer void after received data read-out */
#define FCAN_MB_CODE_RXEMPTY       0x4   /* active and empty (then->RXFULL) */
#define FCAN_MB_CODE_RXFULL        0x2   /* filled with received data (then->RXOVERRUN) */
#define FCAN_MB_CODE_RXOVERRUN     0x6   /* receiver overrun */
#define FCAN_MB_CODE_RXBUSY        0x1   /* just receiving */
#define FCAN_MB_CODE_TXABORT       0x9   /* abort and do not participate in the arbitration process */
#define FCAN_MB_CODE_TXVOID        0x8   /* buffer void before new TX data can be copied into it */
#define FCAN_MB_CODE_TXONCE        0xc   /* queued for transmission, once (then->TXVOID)*/
#define FCAN_MB_CODE_TXRTR         0xe   /* transmit remote frame answer once and always since now (then->TXRANSWER) */
#define FCAN_MB_CODE_TXRALWAYS     0xa   /* transmit remote frame answer always on request (stays TXRALWAYS) */

/****************************************************************************
* FlexCAN inline functions
*****************************************************************************/

inline UWord32 FCAN_Idr2Id(UWord32 idr, UWord16 bIsIDE)
{
    /* Extended ID ? */
    if(bIsIDE)
        return (idr & FCAN_MB_ID_EXT_MASK) | FCAN_ID_EXT;
    /* Standard ID */
    else
        return (idr & FCAN_MB_ID_STD_MASK) >> FCAN_MB_ID_STD_SHIFT;
}

inline UWord32 FCAN_Id2Idr(UWord32 id)
{
    /* Extended ID */
    if(id & FCAN_ID_EXT)
        return (id & FCAN_MB_ID_EXT_MASK);
    /* Standard ID */
    else
        return (id << FCAN_MB_ID_STD_SHIFT) & FCAN_MB_ID_STD_MASK;
}

inline UWord32 FCAN_Id2Maskr(UWord32 id)
{
    UWord32 maskr = FCAN_Id2Idr(maskr);
    /* Extended ID is marked at bit 30 in mask registers*/
    if(id & FCAN_ID_EXT)
        return maskr |= 0x40000000UL;
    /* RTR is marked at bit 31 in mask registers*/
    if(id & FCAN_ID_RTR)
        return maskr |= 0x80000000UL;
    return maskr;
}

/* same as above but implemented as function call (use this when passing a variable as a parameter) */
UWord32 FCAN_Id2Idr_V(register UWord32 id);
UWord32 FCAN_Idr2Id_V(register UWord32 idr, UWord16 bIsIDE);

/****************************************************************************
* FlexCAN commands implementation
*****************************************************************************/

/* FlexCAN peripheral initialization, NULL */
void FCAN_Init(arch_sFlexCAN *pFCanBase);
#define ioctlFCAN_INIT(pFCanBase, param) FCAN_Init(pFCanBase)

/* Issue soft-reset, NULL */
#define ioctlFCAN_SOFT_RESET(pFCanBase, param)  do { \
  periphBitSet(FCAN_MCR_SOFTRST, &((pFCanBase)->mcr));      \
  while(periphBitTest(FCAN_MCR_SOFTRST, &((pFCanBase)->mcr))) \
		  ; \
  } while(0)

/* Enable/disable FlaxCAN module, FCAN_ENABLE/FCAN_DISABLE */                   
#define ioctlFCAN_MODULE(pFCanBase, param)   \
  if(param) periphBitClear(FCAN_MCR_MDIS, &((pFCanBase)->mcr)); \
  else  periphBitSet(FCAN_MCR_MDIS, &((pFCanBase)->mcr))

/* Enter/Leave freeze (Debug) mode; FCAN_ENABLE/FCAN_DISABLE */
#define ioctlFCAN_DEBUG_MODE(pFCanBase, param) \
  if(param) { \
    periphBitSet(FCAN_MCR_FRZ, &((pFCanBase)->mcr)); \
    periphBitSet(FCAN_MCR_HALT, &((pFCanBase)->mcr)); \
  } else \
    periphBitClear(FCAN_MCR_HALT | FCAN_MCR_FRZ, &((pFCanBase)->mcr))

  /* Enable/disable RX FIFO, FCAN_ENABLE/FCAN_DISABLE */
#define ioctlFCAN_RXFIFO_OPERATION(pFCanBase, param)   \
    if(param) periphBitSet(FCAN_MCR_RFEN, &((pFCanBase)->mcr)); \
    else  periphBitClear(FCAN_MCR_RFEN, &((pFCanBase)->mcr))

#define ioctlFCAN_INDIVIDUAL_RX_MASKING(pFCanBase, param)   \
    if(param) periphBitSet(FCAN_MCR_IRMQ, &((pFCanBase)->mcr)); \
    else  periphBitClear(FCAN_MCR_IRMQ, &((pFCanBase)->mcr))

/* Enable/disable Supervisor Mode, FCAN_ENABLE/FCAN_DISABLE */  
#define ioctlFCAN_SUPERVISOR_MODE(pFCanBase, param)   \
    if(param) periphBitSet(FCAN_MCR_SUPV, &((pFCanBase)->mcr)); \
    else  periphBitClear(FCAN_MCR_SUPV, &((pFCanBase)->mcr))

/* Select Wake Up Source */  
#define ioctlFCAN_WAKEUP_SOURCE(pFCanBase, param)   \
    if(param) periphBitSet(FCAN_MCR_WAKSRC, &((pFCanBase)->mcr)); \
    else  periphBitClear(FCAN_MCR_WAKSRC, &((pFCanBase)->mcr))

/* Enable/disable Doze Mode, FCAN_ENABLE/FCAN_DISABLE */  
#define ioctlFCAN_DOZE_MODE(pFCanBase, param)   \
    if(param) periphBitSet(FCAN_MCR_DOZE, &((pFCanBase)->mcr)); \
    else  periphBitClear(FCAN_MCR_DOZE, &((pFCanBase)->mcr))

#define ioctlFCAN_STOP_MODE ioctlFCAN_DOZE_MODE

/* Enable/disable self reception, FCAN_ENABLE/FCAN_DISABLE */  
#define ioctlFCAN_SELF_RECEPTION(pFCanBase, param)   \
    if(param) periphBitSet(FCAN_MCR_SRXDIS, &((pFCanBase)->mcr)); \
    else  periphBitClear(FCAN_MCR_SRXDIS, &((pFCanBase)->mcr))

/* Enable/disable Local Priority, FCAN_ENABLE/FCAN_DISABLE */ 
#define ioctlFCAN_LOCAL_PRIORITY(pFCanBase, param)   \
    if(param) periphBitSet(FCAN_MCR_LPRIOEN, &((pFCanBase)->mcr)); \
    else  periphBitClear(FCAN_MCR_LPRIOEN, &((pFCanBase)->mcr))

/* Enable/disable Abort, FCAN_ENABLE/FCAN_DISABLE */ 
#define ioctlFCAN_TX_ABORT_OPERATION(pFCanBase, param)   \
    if(param) periphBitSet(FCAN_MCR_AEN, &((pFCanBase)->mcr)); \
    else  periphBitClear(FCAN_MCR_AEN, &((pFCanBase)->mcr))

/* Set ID Acceptance Mode,  FCAN_ONE_FULL_ID, FCAN_TWO_FULL_STD_ID, FCAN_FOUR_PARTIAL_ID, FCAN_ALL_FRAME_REJECTED */
#define ioctlFCAN_ID_ACCEPTANCE_MODE(pFCanBase, param)\
      periphBitGrpSet32(FCAN_MCR_IDAM_MASK, param, &((pFCanBase)->mcr))

/* Enable/disable Self-Wakeup without CPU intervention; FCAN_ENABLE/FCAN_DISABLE */
#define ioctlFCAN_SELF_WAKEUP_MODE(pFCanBase, param)\
  if(param) periphBitSet(FCAN_MCR_SLFWAK, &((pFCanBase)->mcr));\
  else  periphBitClear(FCAN_MCR_SLFWAK, &((pFCanBase)->mcr))
  
/* Test (negation of) NOTRDY bit in MCR; NULL */
#define ioctlFCAN_TEST_READY(pFCanBase, param)  \
    (! (periphBitTest(FCAN_MCR_NOTRDY, &((pFCanBase)->mcr)) ))     

/* Test FREEZ_ACK bit in MCR; NULL */
#define ioctlFCAN_TEST_DEBUG(pFCanBase, param)  \
    periphBitTest(FCAN_MCR_FRZACK, &((pFCanBase)->mcr))          
    
/* Test LPMACK bit in MCR; NULL */
#define ioctlFCAN_TEST_STOP(pFCanBase, param)   \
    periphBitTest(FCAN_MCR_LPMACK, &((pFCanBase)->mcr))              

/*****************************/
/* interrupts (MCR and CTL0) */

/* Enable/disable warning interrupt; FCAN_ENABLE/FCAN_DISABLE */
#define ioctlFCAN_WARNING_INTERRUPT(pFCanBase, param)\
    if(param) periphBitSet(FCAN_MCR_WRNEN, &((pFCanBase)->mcr));\
    else  periphBitClear(FCAN_MCR_WRNEN, &((pFCanBase)->mcr))       

/* Enable interrupts; FCAN_BUSOFF_INT | FCAN_ERROR_INT | FCAN_WAKEUP_INT | FCAN_TX_WARNING_INT | FCAN_RX_WARNING_INT */
#define ioctlFCAN_INT_ENABLE(pFCanBase, param) {    \
    periphBitSet((param) & FCAN_MCR_WAKMSK, &((pFCanBase)->mcr)); \
    periphBitSet((param) & (FCAN_CTRL1_BOFFMSK | FCAN_CTRL1_ERRMSK | FCAN_CTRL1_TWRNMSK | FCAN_CTRL1_RWRNMSK), &((pFCanBase)->ctrl1)); \
  }

/* Disable interrupts; FCAN_BUSOFF_INT | FCAN_ERROR_INT | FCAN_WAKEUP_INT | FCAN_TX_WARNING_INT | FCAN_RX_WARNING_INT */
#define ioctlFCAN_INT_DISABLE(pFCanBase, param) {   \
    periphBitClear((param) & FCAN_MCR_WAKMSK, &((pFCanBase)->mcr)); \
    periphBitClear((param) & (FCAN_CTRL1_BOFFMSK | FCAN_CTRL1_ERRMSK | FCAN_CTRL1_TWRNMSK | FCAN_CTRL1_RWRNMSK), &((pFCanBase)->ctrl1)); \
  }

/*****************/
/* CTL1 register */

/*Select clock source for FCAN module*/
#define ioctlFCAN_SET_CLOCK_SOURCE(pFCanBase, param) \
        if(param) periphBitSet(FCAN_CTRL1_CLKSRC, &((pFCanBase)->ctrl1)); \
        else  periphBitClear(FCAN_CTRL1_CLKSRC, &((pFCanBase)->ctrl1))

/* Enable/disable test loopback mode; FCAN_ENABLE/FCAN_DISABLE */
#define ioctlFCAN_LOOPBACK_MODE(pFCanBase, param) \
  if(param) {   \
    periphBitSet(FCAN_MCR_MAXMB_MASK, &((pFCanBase)->mcr)); \
    periphBitSet(FCAN_CTRL1_LPB, &((pFCanBase)->ctrl1)); \
  } else { \
    periphBitClear(FCAN_CTRL1_LPB, &((pFCanBase)->ctrl1)); \
    periphBitClear(FCAN_MCR_MAXMB_MASK, &((pFCanBase)->mcr)); \
  }

/* Enable/disable Timer Sync mode; FCAN_ENABLE/FCAN_DISABLE */
#define ioctlFCAN_TIMER_SYNC_MODE(pFCanBase, param) \
  if(param) periphBitSet(FCAN_CTRL1_TSYN, &((pFCanBase)->ctrl1)); \
  else  periphBitClear(FCAN_CTRL1_TSYN, &((pFCanBase)->ctrl1))
  
/* Enable/disable Listen Only mode; FCAN_ENABLE/FCAN_DISABLE */
#define ioctlFCAN_LISTEN_ONLY_MODE(pFCanBase, param) \
  if(param) periphBitSet(FCAN_CTRL1_LOM, &((pFCanBase)->ctrl1)); \
  else  periphBitClear(FCAN_CTRL1_LOM, &((pFCanBase)->ctrl1))

/* set transmit-first mode  */
#define ioctlFCAN_SET_TX_FIRST_SCHEME(pFCanBase, param) \
  if(param) periphBitSet(FCAN_CTRL1_LBUF, &((pFCanBase)->ctrl1)); \
  else  periphBitClear(FCAN_CTRL1_LBUF, &((pFCanBase)->ctrl1))

/*********************************************************/
/* Setting bitrates and timings in CTL0 & CTL1 registers */

/* set samples per bit; FCAN_1SAMP_PER_BIT / FCAN_3SAMPS_PER_BIT  */
#define ioctlFCAN_SET_SAMPLING(pFCanBase, param) \
  if(param) periphBitSet(FCAN_CTRL1_SMP, &((pFCanBase)->ctrl1)); \
  else  periphBitClear(FCAN_CTRL1_SMP, &((pFCanBase)->ctrl1))

/* set Propagation Segment (PROP_SEG); number 0, .. 7 */
#define ioctlFCAN_SET_PROP_SEG(pFCanBase, param) \
        periphBitGrpRS32(FCAN_CTRL1_PROPSEG_MASK, param, &((pFCanBase)->ctrl1))

/* set PRES_DIV; number 0, .. 255 */
#define ioctlFCAN_SET_PRESCALER(pFCanBase, param) \
   periphBitGrpRS32(FCAN_CTRL1_PRESDIV_MASK, (UWord32)(param)<<24 , &((pFCanBase)->ctrl1)) 

/* set RJW (known also as SJW); number 0, .. 3 */
#define ioctlFCAN_SET_RJW(pFCanBase, param) \
   periphBitGrpRS32(FCAN_CTRL1_RJW_MASK, (UWord32)(param)<<22, &((pFCanBase)->ctrl1))

/* set PHASE_SEG1; number 0, .. 7 */
#define ioctlFCAN_SET_PHASE_SEG1(pFCanBase, param) \
   periphBitGrpRS32(FCAN_CTRL1_PSEG1_MASK, (UWord32)(param)<<19, &((pFCanBase)->ctrl1))
  
/* set PHASE_SEG2; number 0, .. 7 */
#define ioctlFCAN_SET_PHASE_SEG2(pFCanBase, param) \
   periphBitGrpRS32(FCAN_CTRL1_PSEG2_MASK, (UWord32)(param)<<16, &((pFCanBase)->ctrl1))


/*******************/
/* STATUS register */

/* Read error and status bits; NULL */
#define ioctlFCAN_READ_ERR_AND_STATUS(pFCanBase, param) \
    periphMemRead(&((pFCanBase)->esr1))

/* Clear BusOff interrupt status; NULL */
#define ioctlFCAN_CLEAR_BOFF_INT(pFCanBase, param)  \
        periphBitSet(FCAN_ESR1_BOFFINT, &((pFCanBase)->esr1))
  
/* Clear Error interrupt status; NULL */
#define ioctlFCAN_CLEAR_ERR_INT(pFCanBase, param)   \
     periphBitSet(FCAN_ESR1_ERRINT, &((pFCanBase)->esr1))

/* Clear WakeUp interrupt status; NULL */
#define ioctlFCAN_CLEAR_WAKE_INT(pFCanBase, param)  \
     periphBitSet(FCAN_ESR1_WAKINT, &((pFCanBase)->esr1))

  /* Clear Tx Warning Interrupt Flag; NULL */
  #define ioctlFCAN_CLEAR_TX_WARNING_INT(pFCanBase, param)  \
     periphBitSet(FCAN_ESR1_TWRNINT, &((pFCanBase)->esr1))

  /* Clear Rx Warning Interrupt Flag; NULL */
  #define ioctlFCAN_CLEAR_RX_WARNING_INT(pFCanBase, param)  \
     periphBitSet(FCAN_ESR1_RWRNINT, &((pFCanBase)->esr1))

/* Clear selected interrupt status; param */
#define ioctlFCAN_CLEAR_INT(pFCanBase, param)   \
    periphMemWrite((param) & (FCAN_ESR1_BOFFINT | FCAN_ESR1_ERRINT | FCAN_ESR1_WAKINT | FCAN_ESR1_TWRNINT | FCAN_ESR1_RWRNINT), &((pFCanBase)->esr1))


/*******************/
/* Mask registers  */

/* Set Global RX mask, the passed mask is rebuilt to suit the IDR bit-scheme, mask */
#define ioctlFCAN_SET_RXMGMASK(pFCanBase, param)     \
  { register UWord32 maskRaw = FCAN_Id2Maskr(param);  \
    periphMemWrite((UWord32)(maskRaw), &((pFCanBase)->rxmgmask)); }
    
/* Set MB14 RX mask, the passed mask is rebuilt to suit the IDR bit-scheme, mask */
#define ioctlFCAN_SET_RX14MASK(pFCanBase, param)     \
  { register UWord32 maskRaw = FCAN_Id2Maskr(param);  \
    periphMemWrite((UWord32)(maskRaw), &((pFCanBase)->rx14mask)); }
    
/* Set MB15 RX mask, the passed mask is rebuilt to suit the IDR bit-scheme, mask */
#define ioctlFCAN_SET_RX15MASK(pFCanBase, param)     \
  { register UWord32 maskRaw = FCAN_Id2Maskr(param);  \
    periphMemWrite((UWord32)(maskRaw), &((pFCanBase)->rx15mask)); }

/* Same as FCAN_SET_RXxMASK but implemented as a function call; 32bit mask */
void ioctlFCAN_SET_RXMGMASK_V(register arch_sFlexCAN* pFCanMB, register UWord32 mask); 
void ioctlFCAN_SET_RX14MASK_V(register arch_sFlexCAN* pFCanMB, register UWord32 mask);
void ioctlFCAN_SET_RX15MASK_V(register arch_sFlexCAN* pFCanMB, register UWord32 mask);
    
/* Set Global RX mask, the passed mask must already be in raw (IDR) format, mask_idr */
#define ioctlFCAN_SET_RXMGMASK_RAW(pFCanBase, param)     \
    periphMemWrite((UWord32)(param), &((pFCanBase)->rxmgmask));

/* Set MB14 RX mask, the passed mask must already be in raw (IDR) format, mask_idr */
#define ioctlFCAN_SET_RX14MASK_RAW(pFCanBase, param)    \
    periphMemWrite((UWord32)(param), &((pFCanBase)->rx14mask));
    
/* Set MB15 RX mask, the passed mask must already be in raw (IDR) format, mask_idr */
#define ioctlFCAN_SET_RX15MASK_RAW(pFCanBase, param)    \
    periphMemWrite((UWord32)(param), &((pFCanBase)->rx15mask)); 


/******************/
/* Error Counters */

/* read RX error counter; NULL */
#define ioctlFCAN_GET_RX_ERR_COUNT(pFCanBase, param)    \
  (( periphMemRead(&((pFCanBase)->ecr)) >> 8) & 0xff)
  
/* read TX error counter; NULL */
#define ioctlFCAN_GET_TX_ERR_COUNT(pFCanBase, param)    \
  ( periphMemRead(&((pFCanBase)->ecr)) & 0xff )


/*********/
/* Timer */

/* Read FRT to unlock any MB locked; NULL */
#define ioctlFCAN_UNLOCK_ALL_MB(pFCanBase, param)   \
  periphMemDummyRead32(&((pFCanBase)->timer))

/*********/
/* MAXMB */

/* Set maximum number of MB used; number 0-15 */
#define ioctlFCAN_SET_MAXMB(pFCanBase, param)\
  periphBitGrpRS32(FCAN_MCR_MAXMB_MASK, param, &((pFCanBase)->mcr))

/* Get maximum number of MB used */
#define ioctlFCAN_GET_MAXMB(pFCanBase, param)   \
  ( periphMemRead(&((pFCanBase)->mcr)) & FCAN_MCR_MAXMB_MASK )


/*****************/
/* MB interrupts */
    
/* Enable MB interrupts; MB bits */
#define ioctlFCAN_MBINT_ENABLE(pFCanBase, param)    \
  periphBitSet(param, &((pFCanBase)->imask1))

/* Disable MB interrupts; MB bits */
#define ioctlFCAN_MBINT_DISABLE(pFCanBase, param)   \
  periphBitClear(param, &((pFCanBase)->imask1))

/* get MB interrupt source; NULL */
#define ioctlFCAN_READ_MBINT_FLAGS(pFCanBase, param)    \
  periphMemRead(&((pFCanBase)->iflag1))

/* ack MB interrupts; MB bits */
#define ioctlFCAN_CLEAR_MBINT_FLAGS(pFCanBase, param)   \
  periphMemWrite(param, &((pFCanBase)->iflag1))

/*****************/
/* FIFO interrupts (=MB interrupts for special MB numbers) */
    
/* Enable MB interrupts; MB bits */
#define ioctlFCAN_FIFO_INT_ENABLE(pFCanBase, param)    \
  periphBitSet(param, &((pFCanBase)->imask1))

/* Disable MB interrupts; MB bits */
#define ioctlFCAN_FIFO_INT_DISABLE(pFCanBase, param)   \
  periphBitClear(param, &((pFCanBase)->imask1))

/* get FIFO interrupt sources; NULL */
#define ioctlFCAN_READ_FIFO_FLAGS(pFCanBase, param)    \
  periphMemRead(&((pFCanBase)->iflag1))

/* ack FIFO interrupts; MB bits */
#define ioctlFCAN_CLEAR_FIFO_FLAGS(pFCanBase, param)   \
  periphMemWrite(param, &((pFCanBase)->iflag1))

/*******************/
/* Message Buffers */

/* Get pointer to MB structure; MB index */
#define ioctlFCAN_GET_MB_MODULE(pFCanBase, param)\
    (&((pFCanBase)->mb[param]))

/* Retrieve 32bit ID from the appropriate bits in given MB;  */
#define ioctlFCANMB_GET_ID(pFCanMB, param) \
    FCAN_Idr2Id((pFCanMB)->id, periphBitTest(FCAN_MB_CS_IDE, (pFCanMB)->cs))

/* Write given ID to the appropriate bits in given MB; FCAN_ON/FCAN_OFF */
#define ioctlFCANMB_SET_RTR(pFCanMB, param)     \
  if(param) periphBitSet(FCAN_MB_CS_RTR, &((pFCanMB)->cs)); \
  else periphBitClear(FCAN_MB_CS_RTR, &((pFCanMB)->cs))

/* Write given ID to the appropriate bits in given MB; FCAN_ON/FCAN_OFF */
#define ioctlFCANMB_SET_IDE(pFCanMB, param)     \
  if(param) periphBitSet(FCAN_MB_CS_IDE | FCAN_MB_CS_SRR, &((pFCanMB)->cs)); \
  else periphBitClear(FCAN_MB_CS_IDE | FCAN_MB_CS_SRR, &((pFCanMB)->cs))

/* same as above but done as function (to be used when ID passed is a variable) */
void ioctlFCANMB_SET_ID_V(register arch_sFlexCAN_MB* pFCanMB, register UWord32 id);

/* swap data word endianness */
void ioctlFCANMB_REORDER_BYTES(register arch_sFlexCAN_MB* pFCanMB, void* dummy);
void ioctlFCANMB_REORDER_WORDS(register arch_sFlexCAN_MB* pFCanMB, void* dummy);

/* Set 32bit ID to the appropriate bits in given MB (also set/clear RTR);  */
#define ioctlFCANMB_SET_ID(pFCanMB, i) \
  { UWord32 idr = FCAN_Id2Idr(i);  \
    periphMemWrite(idr, &((pFCanMB)->id)); \
    ioctlFCANMB_SET_IDE(pFCanMB, ((i) & FCAN_ID_EXT)); \
    ioctlFCANMB_SET_RTR(pFCanMB, ((i) & FCAN_ID_RTR)); \
  } 

/* Get 32bit ID as it was received (IDR) in given MB; NULL */
#define ioctlFCANMB_GET_ID_RAW(pFCanMB, param)  \
  ((UWord32) periphMemRead(&((pFCanMB)->id)))

/* Set 32bit ID as it is to be transmitted (IDR) in given MB;  */
#define ioctlFCANMB_SET_ID_RAW(pFCanMB, param) \
   periphMemWrite((UWord32)(param), &((pFCanMB)->id)) 

/* Get length field of the MB; NULL */
#define ioctlFCANMB_GET_LEN(pFCanMB, param) \
  ( periphBitTest(FCAN_MB_CS_DLC_MASK, &((pFCanMB)->cs))>>16 )

/* Set length field of the MB; length */
#define ioctlFCANMB_SET_LEN(pFCanMB, param) \
  periphBitGrpRS32(FCAN_MB_CS_DLC_MASK, ((UWord32)(param))<<16 , &((pFCanMB)->cs))
    
/* Get code field of the MB; NULL */
#define ioctlFCANMB_GET_CODE(pFCanMB, param) \
  ( periphBitTest(FCAN_MB_CS_CODE_MASK, &((pFCanMB)->cs))>>24 )

/* Set code field of the MB; code */ 
#define ioctlFCANMB_SET_CODE(pFCanMB, param) \
  periphBitGrpRS32(FCAN_MB_CS_CODE_MASK, ((UWord32)(param))<<24 , &((pFCanMB)->cs))

/* Set transmission priority of MB; priority 0-7*/ 
#define ioctlFCANMB_SET_TX_PRIORITY(pFCanMB, param) \
  periphBitGrpRS32(FCAN_MB_ID_PRIO_MASK, ((UWord32)(param))<<29 , &((pFCanMB)->id))

/* Get pointer to data buffer of the MB (as ptr to UWord16); NULL */
#define ioctlFCANMB_GET_DATAPTR32(pFCanMB, param) \
  ( (UWord32*)((pFCanMB)->data) )

/* Get MB TimeStamp, both bytes if available, NULL  */      
#define ioctlFCANMB_GET_TIMESTAMP(pFCanMB, param) \
  ( periphMemRead(&((pFCanMB)->cs)) & FCAN_MB_CS_TIME_STAMP_MASK )

#ifdef __cplusplus
}
#endif

#endif

