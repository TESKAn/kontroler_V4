/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) yright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name: dma.h
*
* $Date:      May-15-2013$
*
* $Version:   2.5.10.0$
*
* Description: Header file for DMA low-level driver 
*
* This file supports different hardware versions of the module. A version
* of module used in your project is defined in the "arch.h" processor 
* architecture definition file.
*
*  DMA_VERSION_1 .. 56F84xxx and 56F827xx devices, see MC56F84xxxRM.pdf and MC56F827xxRM.pdf
*
*****************************************************************************/

#ifndef __DMA_H
#define __DMA_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before dma.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************
* DMA module identifier, corresponds to module base address
*************************************************************/

#ifdef DMA_BASE
#define DMA (&ArchIO.Dma)
#define DMA_0 (&ArchIO.Dma.channel_0)
#define DMA_1 (&ArchIO.Dma.channel_1)
#define DMA_2 (&ArchIO.Dma.channel_2)
#define DMA_3 (&ArchIO.Dma.channel_3)
#endif

/*************************************************************
* arch.h should define device-specific information about DMA
**************************************************************/

#if !defined(DMA_VERSION)
#error DMA not properly described in arch.h (old Quick_Start version?)
#endif

/******************************************************************************
*
*                      General Interface Description
*
*
* The DMA controller module enables fast transfers of data, providing an efficient way to
* move blocks of data with minimal processor interaction. The DMA module has four channels 
* that allow byte, word, or longword data transfers.
* Each channel has a dedicated source address register (SARn), destination address register
* (DARn), status register (DSRn), byte count register (BCRn), and control register
* (DCRn). Collectively, the combined program-visible registers associated with each
* channel define a transfer control descriptor (TCD). All transfers are dual address, moving
* data from a source memory location to a destination memory location with the module
* operating as a 32-bit bus master connected to the system bus. The programming model is
* accessed through a 32-bit connection with the slave peripheral bus. DMA data transfers
* may be explicitly initiated by software or by peripheral hardware requests.
*
* For more information, please refer to the user manual for the particular
* chip that you are using.
*
* The DMA device driver interface uses "ioctl" call to control specific
* DMA functions during operation. For details see "ioctl" call.
*
******************************************************************************/

/***********************************************************************
* DMA static configuration items for appconfig.h
***********************************************************************/
/*
    #define DMA_REQC_INIT
    #define DMA_SAR0_INIT
    #define DMA_DAR0_INIT
    #define DMA_DCR0_INIT
    #define DMA_DSR_BCR0_INIT
    #define DMA_SAR1_INIT
    #define DMA_DAR1_INIT
    #define DMA_DCR1_INIT
    #define DMA_DSR_BCR1_INIT
    #define DMA_SAR2_INIT
    #define DMA_DAR2_INIT
    #define DMA_DCR2_INIT
    #define DMA_DSR_BCR2_INIT
    #define DMA_SAR3_INIT
    #define DMA_DAR3_INIT
    #define DMA_DCR3_INIT
    #define DMA_DSR_BCR3_INIT

*/
/*****************************************************************
* Single-Instruction ioctl() commands
*
*  Word16 ioctl( _module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/

/*   DMA channel commands used to access a channel registers use Base address " DMA_n "  n-number of channel*/

#define DMA_READ_DSR_BCR                    /* NULL, read and return channel n DMA_DSR_BCR register (DSR_BCRn->_) */
#define DMA_WRITE_DSR_BCR                   /* UWord32, write the parameter value into the channel n DMA_DSR_BCR register (DSR_BCRn->_) */
#define DMA_READ_DCR                        /* NULL, read and return channel n DMA_DCR register (DCRn->_) */
#define DMA_WRITE_DCR                       /* UWord32, write the parameter value into channel n DMA_DCR register (DCRn->_) */
#define DMA_SET_SOURCE_ADDRESS              /* UWord32 source address, set the source address used by the DMA channel to read data (SARn->_) */
#define DMA_SET_DESTINATION_ADDRESS         /* UWord32 destination address, set the destination address used by the DMA channel to write data (DARn->_) */
#define DMA_GET_SOURCE_ADDRESS              /* NULL, read and return the source address used by the DMA channel (SARn->_) */
#define DMA_GET_DESTINATION_ADDRESS         /* NULL, read and return the destination address used by the DMA channel (DARn->_) */
#define DMA_CLEAR_TRANSACTION_DONE          /* NULL, clear DMA transaction status bit. Use in an interrupt service routine to clear the DMA interrupt flag and error bits (DSR_BCRn->DONE) */
#define DMA_DISABLE_REQUEST                 /* DMA_ENABLE/DMA_DISABLE, If enabled, the DMA hardware automatically clears the corresponding DCRn[ERQ] bit when the byte count register reaches zero (DCRn->D_REQ) */
#define DMA_SET_START_TRANSFER              /* DMA_ENABLE/DMA_DISABLE, DMA begins the transfer in accordance to the values in the TCDn.START is cleared automatically after one module clock and always reads as logic 0 (DCRn->START) */
#define DMA_SET_DESTINATION_INCREMENT       /* DMA_ENABLE/DMA_DISABLE, set destination address incremention after each successful transfer (DCRn->DINC) */
#define DMA_SET_SOURCE_INCREMENT            /* DMA_ENABLE/DMA_DISABLE, set source address incremention after each successful transfer (DCRn->SINC) */
#define DMA_SET_AUTO_ALIGN                  /* DMA_ENABLE/DMA_DISABLE, set optimised transfers based on the address and size (DCRn->AA) */
#define DMA_SET_TRANSFER_MODE               /* DMA_SINGLE/DMA_CONTINUOUS, select single read/write transfers per request or continuous read/write transfers until the BCR decrements to zero (DCRn->CS) */
#define DMA_SET_PERIPHERAL_REQUEST          /* DMA_ENABLE/DMA_DISABLE, enable peripheral request to initiate the DMA transfer (DCRn->ERQ) */
#define DMA_SET_INTERRUPT_COMPLETED         /* DMA_ENABLE/DMA_DISABLE, enable/disable interrupt to be generated when completing a transfer or by an error condition (DCRn->EINT) */

/*****************************************************************
* Multi-Instruction ioctl() commands
*
*  Word16 ioctl( DMA_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/

/*   DMA common commands used to access a common registers use Base address " DMA " */
#define DMA_INIT                            /* NULL, Initialization of the DMA peripheral registers using appconfig.h _INIT values */

#define DMA_CH0_SELECT_SOURCE                   /* DMA_REQUEST_xxx (xxx=0-15), select DMA request which will be routed to the DMA channel 0 (REQC->DMAC0) */
#define DMA_CH1_SELECT_SOURCE                   /* DMA_REQUEST_xxx (xxx=0-15), select DMA request which will be routed to the DMA channel 1 (REQC->DMAC1) */
#define DMA_CH2_SELECT_SOURCE                   /* DMA_REQUEST_xxx (xxx=0-15), select DMA request which will be routed to the DMA channel 2 (REQC->DMAC2) */
#define DMA_CH3_SELECT_SOURCE                   /* DMA_REQUEST_xxx (xxx=0-15), select DMA request which will be routed to the DMA channel 3 (REQC->DMAC3) */
#define DMA_CH0_CLEAR_STATE_MACHINE_CONTROL     /* NULL, clear the state machine for DMA channel 0 (REQC->CFSM0) */
#define DMA_CH1_CLEAR_STATE_MACHINE_CONTROL     /* NULL, clear the state machine for DMA channel 1 (REQC->CFSM1) */
#define DMA_CH2_CLEAR_STATE_MACHINE_CONTROL     /* NULL, clear the state machine for DMA channel 2 (REQC->CFSM2) */
#define DMA_CH3_CLEAR_STATE_MACHINE_CONTROL     /* NULL, clear the state machine for DMA channel 3 (REQC->CFSM3) */


/*   DMA channel commands used to access a channel registers use Base address " DMA_x "  x-number of channel*/

#define DMA_READ_BYTES_TO_BE_TRANSFERRED    /* NULL, return number of bytes yet to be transferred for a given block (DSR_BCRn->BCR ) */
#define DMA_READ_TRANSACTION_DONE           /* NULL, get the DMA transfer completed [DONE] flag (DSR_BCRn->DONE ) */
#define DMA_READ_BUSY                       /* NULL, get the busy [BSY] bit; The bit is cleared when the DMA has finished the last transaction and set when the first time the channel is enabled after a transfer is initiated (DSR_BCRn->BSY ) */
#define DMA_READ_REQUEST                    /* NULL, get the request pending [REQ] bit; The DMA channel has a transfer remaining, Cleared when the channel is selected. (DSR_BCRn->REQ) */
#define DMA_READ_BUS_ERROR_DESTINATION      /* NULL, get the bus error on destination [BED] flag; Cleared at hardware reset or by writing a 1 to the [DONE] bit (DSR_BCRn->BED ) */
#define DMA_READ_BUS_ERROR_SOURCE           /* NULL, get the bus error on source [BES] flag; Cleared at hardware reset or by writing a 1 to the [DONE] bit (DSR_BCRn->BES) */
#define DMA_READ_CONFIG_ERROR               /* NULL, get the configuration error [CE] flag; A configuration error occurs when any of the following conditions occurs: BCR, SAR, or DAR does not match the requested transfer size; SSIZE or DSIZE is set to an unsupported value; BCR equals 0 when the DMA receives a start condition (DSR_BCRn->CE) */
#define DMA_SET_LINK_CHANNEL_MODE           /* DMA_xxx (xxx=NO_LINKING/LCH1_THEN_LCH2/LCH1_AFTER_CS/LCH1_WHEN_BCR_0), set the DMA channels to have their transfers linked. The current DMA channel triggers a DMA request to the linked channels (LCH1 or LCH2) depending on the condition described by the parameter. (DCRn->LINKCC ) */
#define DMA_GET_LINK_CHANNEL_2              /* NULL, get the DMA channel assigned as link channel 2. The link channel number cannot be the same as the currently executing channel  (DCRn->LCH1 ) */
#define DMA_GET_LINK_CHANNEL_1              /* NULL, get the DMA channel assigned as link channel 1. The link channel number cannot be the same as the currently executing channel  (DCRn->LCH1 ) */
#define DMA_SET_LINK_CHANNEL_2              /* DMA_CH_xxx (xxx=0-3), set the DMA channel assigned as link channel 2 (DCRn->LCH2) */
#define DMA_SET_LINK_CHANNEL_1              /* DMA_CH_xxx (xxx=0-3), set the DMA channel assigned as link channel 1 (DCRn->LCH1) */
#define DMA_SET_SOURCE_ADDRESS_MODULO       /* DMA_xxx (xxx=DISABLE/16B/32B/64B/128B/256B/512B/1KB/2KB/4KB/8KB/16KB/32KB/64KB/128KB/256KB), set the size of the source data circular buffer used by the DMA channel (DCRn->SMOD) */
#define DMA_SET_DESTINATION_ADDRESS_MODULO  /* DMA_xxx (xxx=DISABLE/16B/32B/64B/128B/256B/512B/1KB/2KB/4KB/8KB/16KB/32KB/64KB/128KB/256KB), set the size of the destination data circular buffer used by the DMA channel (DCRn->DMOD) */
#define DMA_SET_DESTINATION_SIZE            /* DMA_xxx (xxx=BYTE/WORD/LONGWORD), set the data size of the destination bus cycle for the DMA channel (DCRn->DSIZE) */
#define DMA_SET_SOURCE_SIZE                 /* DMA_xxx (xxx=BYTE/WORD/LONGWORD), set the data size of the source bus cycle for the DMA channel (DCRn->SSIZE) */

/*****************************************************************
* Software Layer ioctl() commands
*
*  Word16 ioctl( DMA_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/

/****************************************************************************
* DMA constants and type declarations used in the ioctl functions
*****************************************************************************/

#define DMA_ENABLE    1
#define DMA_DISABLE   0

#define DMA_REQUEST_0           (UWord32)0x00
#define DMA_REQUEST_1           (UWord32)0x01
#define DMA_REQUEST_2           (UWord32)0x02
#define DMA_REQUEST_3           (UWord32)0x03
#define DMA_REQUEST_4           (UWord32)0x04
#define DMA_REQUEST_5           (UWord32)0x05
#define DMA_REQUEST_6           (UWord32)0x06
#define DMA_REQUEST_7           (UWord32)0x07
#define DMA_REQUEST_8           (UWord32)0x08
#define DMA_REQUEST_9           (UWord32)0x09
#define DMA_REQUEST_10          (UWord32)0x0A
#define DMA_REQUEST_11          (UWord32)0x0B
#define DMA_REQUEST_12          (UWord32)0x0C
#define DMA_REQUEST_13          (UWord32)0x0D
#define DMA_REQUEST_14          (UWord32)0x0E
#define DMA_REQUEST_15          (UWord32)0x0F

#define DMA_CONTINUOUS          (UWord32)0x020000000
#define DMA_SINGLE              (UWord32)0x020000000
#define DMA_LONGWORD            (UWord32)0x000000000
#define DMA_BYTE                (UWord32)0x000020000
#define DMA_WORD                (UWord32)0x000040000
#define DMA_16B                 (UWord32)0x000000100
#define DMA_32B                 (UWord32)0x000000200
#define DMA_64B                 (UWord32)0x000000300
#define DMA_128B                (UWord32)0x000000400
#define DMA_256B                (UWord32)0x000000500
#define DMA_512B                (UWord32)0x000000600
#define DMA_1KB                 (UWord32)0x000000700
#define DMA_2KB                 (UWord32)0x000000800
#define DMA_4KB                 (UWord32)0x000000900
#define DMA_8KB                 (UWord32)0x000000A00
#define DMA_16KB                (UWord32)0x000000B00
#define DMA_32KB                (UWord32)0x000000C00
#define DMA_64KB                (UWord32)0x000000D00
#define DMA_128KB               (UWord32)0x000000E00
#define DMA_256KB               (UWord32)0x000000F00
#define DMA_NO_LINKING          (UWord32)0x000000000
#define DMA_LCH1_THEN_LCH2      (UWord32)0x000000010
#define DMA_LCH1_AFTER_CS       (UWord32)0x000000020
#define DMA_LCH1_WHEN_BCR_0     (UWord32)0x000000030
#define DMA_CH_0                (UWord32)0x000000000
#define DMA_CH_1                (UWord32)0x000000001
#define DMA_CH_2                (UWord32)0x000000002
#define DMA_CH_3                (UWord32)0x000000003

#define DMA_REQC_DMAC0_MASK     (UWord32)0x00F000000
#define DMA_REQC_DMAC1_MASK     (UWord32)0x0000F0000
#define DMA_REQC_DMAC2_MASK     (UWord32)0x000000F00
#define DMA_REQC_DMAC3_MASK     (UWord32)0x00000000F
#define DMA_REQC_CFSM0          (UWord32)0x080000000
#define DMA_REQC_CFSM1          (UWord32)0x000800000
#define DMA_REQC_CFSM2          (UWord32)0x000008000
#define DMA_REQC_CFSM3          (UWord32)0x000000080

#define DMA_DSR_BCR_CE_MASK     (UWord32)0x040000000
#define DMA_DSR_BCR_BES_MASK    (UWord32)0x020000000
#define DMA_DSR_BCR_BED_MASK    (UWord32)0x010000000
#define DMA_DSR_BCR_REQ_MASK    (UWord32)0x004000000
#define DMA_DSR_BCR_BSY_MASK    (UWord32)0x002000000
#define DMA_DSR_BCR_DONE_MASK   (UWord32)0x001000000
#define DMA_DSR_BCR_BCR_MASK    (UWord32)0x000FFFFFF

#define DMA_DCR_EINT_MASK       (UWord32)0x080000000
#define DMA_DCR_ERQ_MASK        (UWord32)0x040000000
#define DMA_DCR_CS_MASK         (UWord32)0x020000000
#define DMA_DCR_AA_MASK         (UWord32)0x010000000
#define DMA_DCR_SINC_MASK       (UWord32)0x000400000
#define DMA_DCR_SSIZE_MASK      (UWord32)0x000300000
#define DMA_DCR_DINC_MASK       (UWord32)0x000080000
#define DMA_DCR_DSIZE_MASK      (UWord32)0x000060000
#define DMA_DCR_START_MASK      (UWord32)0x000010000
#define DMA_DCR_SMOD_MASK       (UWord32)0x00000F000
#define DMA_DCR_DMOD_MASK       (UWord32)0x000000F00
#define DMA_DCR_D_REQ_MASK      (UWord32)0x000000080
#define DMA_DCR_LINKCC_MASK     (UWord32)0x000000030
#define DMA_DCR_LCH1_MASK       (UWord32)0x00000000C
#define DMA_DCR_LCH2_MASK       (UWord32)0x000000003

/***********************************************************************
*  control command macros
***********************************************************************/

/* DMA initialization */
void Dma_common_init(arch_sDMA *pDmaBase);

void Dma_channel_init(arch_sDMAchannel *pDmaBase);

void Dma_init(void);
#define ioctlDMA_INIT(pDmaBase, param) Dma_init()


#define ioctlDMA_CH3_SELECT_SOURCE(pDmaBase, param) \
        periphSafeBitGrpSet32((DMA_REQC_CFSM0 | DMA_REQC_CFSM1 | DMA_REQC_CFSM2 | DMA_REQC_CFSM3),DMA_REQC_DMAC3_MASK, param,  &((pDmaBase)->reqc))

#define ioctlDMA_CH3_CLEAR_STATE_MACHINE_CONTROL(pDmaBase, param) \
        periphSafeBitSet32((DMA_REQC_CFSM0 | DMA_REQC_CFSM1 | DMA_REQC_CFSM2), DMA_REQC_CFSM3,  &((pDmaBase)->reqc))

#define ioctlDMA_CH2_SELECT_SOURCE(pDmaBase, param) \
        periphSafeBitGrpSet32((DMA_REQC_CFSM0 | DMA_REQC_CFSM1 | DMA_REQC_CFSM2 | DMA_REQC_CFSM3),DMA_REQC_DMAC2_MASK, (param << 8),  &((pDmaBase)->reqc))

#define ioctlDMA_CH2_CLEAR_STATE_MACHINE_CONTROL(pDmaBase, param) \
        periphSafeBitSet32((DMA_REQC_CFSM0 | DMA_REQC_CFSM1 | DMA_REQC_CFSM3), DMA_REQC_CFSM2,  &((pDmaBase)->reqc))

#define ioctlDMA_CH1_SELECT_SOURCE(pDmaBase, param) \
        periphSafeBitGrpSet32((DMA_REQC_CFSM0 | DMA_REQC_CFSM1 | DMA_REQC_CFSM2 | DMA_REQC_CFSM3),DMA_REQC_DMAC1_MASK, (param << 16),  &((pDmaBase)->reqc))

#define ioctlDMA_CH1_CLEAR_STATE_MACHINE_CONTROL(pDmaBase, param) \
        periphSafeBitSet32((DMA_REQC_CFSM0 | DMA_REQC_CFSM2 | DMA_REQC_CFSM3), DMA_REQC_CFSM1,  &((pDmaBase)->reqc)) 

#define ioctlDMA_CH0_SELECT_SOURCE(pDmaBase, param) \
        periphSafeBitGrpSet32((DMA_REQC_CFSM0 | DMA_REQC_CFSM1 | DMA_REQC_CFSM2 | DMA_REQC_CFSM3),DMA_REQC_DMAC0_MASK, (param << 24),  &((pDmaBase)->reqc)) 

#define ioctlDMA_CH0_CLEAR_STATE_MACHINE_CONTROL(pDmaBase, param) \
        periphSafeBitSet32((DMA_REQC_CFSM1 | DMA_REQC_CFSM2 | DMA_REQC_CFSM3), DMA_REQC_CFSM0,  &((pDmaBase)->reqc))



#define ioctlDMA_SET_SOURCE_ADDRESS(pDmaBase, param) \
        periphMemWrite( param, &((pDmaBase)->sar))

#define ioctlDMA_GET_SOURCE_ADDRESS(pDmaBase, param) \
        periphMemRead( &((pDmaBase)->sar))

#define ioctlDMA_SET_DESTINATION_ADDRESS(pDmaBase, param) \
        periphMemWrite( param, &((pDmaBase)->dar))

#define ioctlDMA_GET_DESTINATION_ADDRESS(pDmaBase, param) \
        periphMemRead( &((pDmaBase)->dar))

#define ioctlDMA_READ_DSR_BCR(pDmaBase, param) \
        periphMemRead(&((pDmaBase)->dsr_bcr))
        
#define ioctlDMA_WRITE_DSR_BCR(pDmaBase, param) \
        periphMemWrite(param, &((pDmaBase)->dsr_bcr))

#define ioctlDMA_READ_DCR(pDmaBase, param) \
        periphMemRead(&((pDmaBase)->dcr))

#define ioctlDMA_WRITE_DCR(pDmaBase, param) \
        periphMemWrite(param, &((pDmaBase)->dcr))  
        
#define ioctlDMA_READ_BYTES_TO_BE_TRANSFERRED(pDmaBase, param) \
        periphBitTest(DMA_DSR_BCR_BCR_MASK, &((pDmaBase)->dsr_bcr))         
        
#define ioctlDMA_READ_TRANSACTION_DONE(pDmaBase, param) \
        periphBitTest(DMA_DSR_BCR_DONE_MASK, &((pDmaBase)->dsr_bcr))
              
#define ioctlDMA_CLEAR_TRANSACTION_DONE(pDmaBase, param) \
        periphBitSet(DMA_DSR_BCR_DONE_MASK, &((pDmaBase)->dsr_bcr))
              
#define ioctlDMA_READ_BUSY(pDmaBase, param) \
        periphBitTest(DMA_DSR_BCR_BSY_MASK, &((pDmaBase)->dsr_bcr))
              
#define ioctlDMA_READ_REQUEST(pDmaBase, param) \
        periphBitTest(DMA_DSR_BCR_REQ_MASK, &((pDmaBase)->dsr_bcr))
        
#define ioctlDMA_READ_BUS_ERROR_DESTINATION(pDmaBase, param) \
        periphBitTest(DMA_DSR_BCR_BED_MASK, &((pDmaBase)->dsr_bcr))
        
#define ioctlDMA_READ_BUS_ERROR_SOURCE(pDmaBase, param) \
        periphBitTest(DMA_DSR_BCR_BES_MASK, &((pDmaBase)->dsr_bcr))  
        
#define ioctlDMA_READ_CONFIG_ERROR(pDmaBase, param) \
        periphBitTest(DMA_DSR_BCR_CE_MASK, &((pDmaBase)->dsr_bcr)) 
        
#define ioctlDMA_SET_LINK_CHANNEL_MODE(pDmaBase, param) \
        periphBitGrpSet32(DMA_DCR_LINKCC_MASK, param, &((pDmaBase)->dcr)) 

#define ioctlDMA_GET_LINK_CHANNEL_2(pDmaBase, param) \
        periphBitTest(DMA_DCR_LCH2_MASK, &((pDmaBase)->dcr))              
        
#define ioctlDMA_GET_LINK_CHANNEL_1(pDmaBase, param) \
        periphBitTest(DMA_DCR_LCH1_MASK, &((pDmaBase)->dcr))  
        
#define ioctlDMA_SET_LINK_CHANNEL_2(pDmaBase, param) \
        periphBitGrpSet32(DMA_DCR_LCH2_MASK, param, &((pDmaBase)->dcr)) 
        
#define ioctlDMA_SET_LINK_CHANNEL_1(pDmaBase, param) \
        periphBitGrpSet32(DMA_DCR_LCH1_MASK, (param << 2), &((pDmaBase)->dcr)) 
        
#define ioctlDMA_DISABLE_REQUEST(pDmaBase, param) \
        if (param)periphBitSet(DMA_DCR_D_REQ_MASK, &((pDmaBase)->dcr)); \
        else periphBitClear(DMA_DCR_D_REQ_MASK, &((pDmaBase)->dcr))
        
#define ioctlDMA_SET_SOURCE_ADDRESS_MODULO(pDmaBase, param) \
        periphBitGrpSet32(DMA_DCR_DMOD_MASK, param, &((pDmaBase)->dcr))
       
#define ioctlDMA_SET_DESTINATION_ADDRESS_MODULO(pDmaBase, param) \
        periphBitGrpSet32(DMA_DCR_SMOD_MASK, (param << 4), &((pDmaBase)->dcr))
        
#define ioctlDMA_SET_START_TRANSFER(pDmaBase, param) \
        periphBitSet(DMA_DCR_START_MASK, &((pDmaBase)->dcr));  

#define ioctlDMA_SET_DESTINATION_SIZE(pDmaBase, param) \
        periphBitGrpSet32(DMA_DCR_DSIZE_MASK, param, &((pDmaBase)->dcr))  
        
#define ioctlDMA_SET_DESTINATION_INCREMENT(pDmaBase, param) \
        if (param)periphBitSet(DMA_DCR_DINC_MASK, &((pDmaBase)->dcr)); \
        else periphBitClear(DMA_DCR_DINC_MASK, &((pDmaBase)->dcr))
        
#define ioctlDMA_SET_SOURCE_SIZE(pDmaBase, param) \
        periphBitGrpSet32(DMA_DCR_SSIZE_MASK, (param << 3), &((pDmaBase)->dcr))  
        
#define ioctlDMA_SET_SOURCE_INCREMENT(pDmaBase, param) \
        if (param)periphBitSet(DMA_DCR_SINC_MASK, &((pDmaBase)->dcr)); \
        else periphBitClear(DMA_DCR_SINC_MASK, &((pDmaBase)->dcr))
        
#define ioctlDMA_SET_AUTO_ALIGN(pDmaBase, param) \
        if (param)periphBitSet(DMA_DCR_AA_MASK, &((pDmaBase)->dcr)); \
        else periphBitClear(DMA_DCR_AA_MASK, &((pDmaBase)->dcr))
        
#define ioctlDMA_SET_TRANSFER_MODE(pDmaBase, param) \
        if (param)periphBitSet(DMA_DCR_CS_MASK, &((pDmaBase)->dcr)); \
        else periphBitClear(DMA_DCR_CS_MASK, &((pDmaBase)->dcr))        
        
#define ioctlDMA_SET_PERIPHERAL_REQUEST(pDmaBase, param) \
        if (param)periphBitSet(DMA_DCR_ERQ_MASK, &((pDmaBase)->dcr)); \
        else periphBitClear(DMA_DCR_ERQ_MASK, &((pDmaBase)->dcr))
        
#define ioctlDMA_SET_INTERRUPT_COMPLETED(pDmaBase, param) \
        if (param)periphBitSet(DMA_DCR_EINT_MASK, &((pDmaBase)->dcr)); \
        else periphBitClear(DMA_DCR_EINT_MASK, &((pDmaBase)->dcr))   


#ifdef __cplusplus
}
#endif

#endif
