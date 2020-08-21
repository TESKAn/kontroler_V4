/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  crc_8xxx.h
*
* $Date:      Dec-17-2014$
*
* $Version:   2.5.10.0$
*
* Description: Header file for the CRC low-level driver
*
* This file supports different hardware versions of the module. A version
* of module used in your project is defined in the "arch.h" processor 
* architecture definition file.
*
*  CRC_VERSION_1 .. 56F82xx devices, see MC56F82xxRM.pdf
*                .. 56F823xx devices, see MC56F823xxRM.pdf, 56F827xx devices, see MC56F827xxRM.pdf
*  CRC_VERSION_2 .. 56F844xx devices, see MC56F844xxRM.pdf, 56F847xx devices, see MC56F847XXRM.pdf
*
*****************************************************************************/

#ifndef __CRC_H
#define __CRC_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before crc.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*
*                      General Interface Description
*
* The CRC device driver interface uses "ioctl" call to control specific CRC functions
* during operation. For details see "ioctl" call.
*
******************************************************************************/

/************************************************************
* CRC module identifiers
*************************************************************/

/* single ("anonymous") module on some devices */
#ifdef CRC_BASE
#define CRC     (&ArchIO.Crc)
#endif

/*************************************************************
* arch.h should define device-specific information about CRC
**************************************************************/

#if !defined(CRC_VERSION)
#error CRC not properly described in arch.h (old Quick_Start version?)
#endif


/*****************************************************************
* Single-Instruction  ioctl() commands
*
*  Word16 ioctl( CRC_module_identifier, Command_name, Parameter );
*
******************************************************************

        COMMAND NAME                      PARAMETERS, COMMENTS
------------------------------------------------------------------ */
#if CRC_VERSION == 1
    #define CRC_WRITE_CRC_LOW_REG          /* UWord16 value 0-255, write the parameter value into the CRC Low byte register. This register is using for the CRC generator initialization and for writing the data to generate CRC error check code (CRCL->_) */
    #define CRC_WRITE_CRC_HIGH_REG         /* UWord16 value 0-255, write the parameter value into the CRC High byte register. To complete the CRC generator initialization the  module expects writing the low part of the initialization byte to the CRC Low byte register (CRCH->_) */
    #define CRC_WRITE_CRC_DATA             /* UWord16 value 0-255, write the parameter value into the CRC Low byte register. This register is using for finish the CRC generator initialization and for writing the data to generate CRC error check code (CRCL->_) */
    
    #define CRC_READ_CRC_LOW_REG           /* NULL, read and return the value of CRC Low byte register. This register represents low byte of the CRC Generator result (CRCL->_) */
    #define CRC_READ_CRC_HIGH_REG          /* NULL, read and return the value of CRC High Byte register. This register represents high byte of the CRC Generator result (CRCH->_) */
    
    #define CRC_WRITE_CRC_TRANSPOSE        /* UWord16, write the CRC Transpose register. This register is used to convert data from MSb to LSb (TRANSPOSE->_) */
    #define CRC_READ_CRC_TRANSPOSE         /* NULL, read and return value of the CRC Transpose register. This register is using to convert data from MSb to LSb (TRANSPOSE->_) */

#endif /* CRC_VERSION == 1 */

#if CRC_VERSION == 2
    #define CRC_WRITE_CRC_REG                      /* UWord32, write the CRC Data register (CRC->_) */
    #define CRC_READ_CRC_REG                       /* NULL, read and return value of CRC Data register (CRC->_) */
    #define CRC_WRITE_GPOLY_REG                    /* UWord32, write the CRC Polynomial register (GPOLY->_) */
    #define CRC_READ_GPOLY_REG                     /* NULL, read and return value of CRC Polynomial register (GPOLY->_) */
    #define CRC_WRITE_CTRL_REG                     /* UWord32, write the CRC Control register (CTRL->_) */
    #define CRC_READ_CTRL_REG                      /* NULL, read and return value of CRC Control register (CTRL->_) */
    #define CRC_SET_COMPLEMENT_READ_OF_DATA_REG    /* CRC_ENABLE/CRC_DISABLE, enable/disable on-the-fly complementing the read data. Some CRC protocols require the final checksum to be XORed with 0xFFFFFFFF or 0xFFFF */
    #define CRC_SET_WRITE_AS_SEED                  /* CRC_ENABLE/CRC_DISABLE, when enabled, any value written to the CRC data register is considered to be a seed value. When deasserted, a value written is taken as data for CRC computation */
    #define CRC_SET_PROTOCOL_WIDTH                 /* CRC_16_BIT/CRC_32_BIT, set the width of CRC protocol */
#endif /* CRC_VERSION == 2 */

/*****************************************************************
* Multi-Instruction ioctl() commands
*
*  Word16 ioctl( CRC_module_identifier, Command_name, Parameter );
*
******************************************************************

        COMMAND NAME                      PARAMETERS, COMMENTS
------------------------------------------------------------------ */
#if CRC_VERSION == 1
    #define CRC_WRITE_INIT_VALUE           /* UWord16, initialize the CRC function (CRCH->_, CRCL->_) */
    #define CRC_READ_CRC_RESULT            /* NULL, read and return the value of CRC result bytes (CRCH->_,CRCL->_) */
    #define CRC_WRITE_CRC_TRANSPOSED_DATA  /* UWord16 value 0-255, write the parameter value (data) in to transpose register, transposed data are written into CRC low byte (TRANSPOSE->_,CRCL->_) */
#endif /* CRC_VERSION == 1 */


#if CRC_VERSION == 2
    #define CRC_WRITE_8BIT_CRC_VALUE              /* UWord32 value 0-255, write seed or data value used for CRC checksum generation (CRC->LL) */
    #define CRC_WRITE_16BIT_CRC_VALUE             /* UWord32 value 0-65535, write seed or data value used for CRC checksum generation (CRC->LL, LU) */
    #define CRC_WRITE_32BIT_CRC_VALUE             /* UWord32 value 0-65535, write seed or data value used for CRC checksum generation (CRC->_) */

    #define CRC_READ_16BIT_CHECKSUM               /* NULL , read and return the value low Word of the CRC Data register(CRC->LU, LL) */
    #define CRC_READ_32BIT_CHECKSUM               /* NULL , read and return the value of the whole CRC Data register.(CRC->HU, HL, LU, LL) */

    #define CRC_WRITE_LOW_POLYNOMINAL             /* UWord16, write the parameter value into lower Word of the CRC Polynominal register (GPOLY->LOW) */
    #define CRC_WRITE_HIGH_POLYNOMINAL            /* UWord16, write the parameter value into higher Word of the CRC Polynominal register (GPOLY->HIGH) */
                                                  
    #define CRC_SET_TRANSPOSE_TYPE_FOR_WRITES     /* CRC_xxx (xxx=NO_TRANSPOSITION/BITS_TRANSPOSED/BITS_AND_BYTES_TRANSPOSED/BYTES_TRANSPOSED), set the transpose configuration of the data written into the CRC data register (GPOLY->TOT) */
    #define CRC_SET_TRANSPOSE_TYPE_FOR_READ       /* CRC_xxx (xxx=NO_TRANSPOSITION/BITS_TRANSPOSED/BITS_AND_BYTES_TRANSPOSED/BYTES_TRANSPOSED), set the transpose configuration of the value read from the CRC Data register (GPOLY->TOTR) */
#endif /* CRC_VERSION == 2 */


/****************************************************************************
* CRC command parameters and masks 
*****************************************************************************/

#if (CRC_VERSION == 1)
    #define CRC_CRCH_CRCH_MASK             0xff
    #define CRC_CRCL_CRCL_MASK             0xff
    #define CRC_TRANSPOSE_TRANSPOSE_MASK   0xff
#endif

#if (CRC_VERSION == 2)

    #define CRC_ENABLE                   (UWord32)0x000000001
    #define CRC_DISABLE                  (UWord32)0x000000000
    #define CRC_16_BIT                   (UWord32)0x000000000
    #define CRC_32_BIT                   (UWord32)0x000000001


    #define CRC_CRC_LL_MASK             (UWord32)0x0000000ff
    #define CRC_CRC_LU_MASK             (UWord32)0x00000ff00
    #define CRC_CRC_HL_MASK             (UWord32)0x000ff0000
    #define CRC_CRC_HU_MASK             (UWord32)0x0ff000000

    #define CRC_GPOLY_LOW_MASK          (UWord32)0x00000ffff
    #define CRC_GPOLY_HIGH_MASK         (UWord32)0x0ffff0000

    #define CRC_CTRL_TOT_MASK           (UWord32)0x0C0000000
    #define CRC_CTRL_TOTR_MASK          (UWord32)0x030000000
    #define CRC_CTRL_FXOR               (UWord32)0x004000000
    #define CRC_CTRL_WAS                (UWord32)0x002000000
    #define CRC_CTRL_TCRC               (UWord32)0x001000000

    #define CRC_NO_TRANSPOSITION            (UWord32)0x000000000
    #define CRC_BITS_TRANSPOSED             (UWord32)0x040000000
    #define CRC_BITS_AND_BYTES_TRANSPOSED   (UWord32)0x080000000
    #define CRC_BYTES_TRANSPOSED            (UWord32)0x0C0000000



#endif


/****************************************************************************
* CRC ioctl macro implementation
*****************************************************************************/

#if (CRC_VERSION == 1)

/* Writes to CRC Low byte */
#define ioctlCRC_WRITE_CRC_LOW_REG(pCrcBase, param)        \
    periphMemWrite((param), &((pCrcBase)->crc_crcl))

/* Writes to CRC Low byte */
#define ioctlCRC_WRITE_CRC_DATA(pCrcBase, param)        \
    periphMemWrite((param), &((pCrcBase)->crc_crcl))

/* Writes to CRC High byte */
#define ioctlCRC_WRITE_CRC_HIGH_REG(pCrcBase, param)        \
    periphMemWrite((param), &((pCrcBase)->crc_crch))

/* Writes to transpose byte of CRC module */
#define ioctlCRC_WRITE_CRC_TRANSPOSE(pCrcBase, param)        \
    periphMemWrite((param), &((pCrcBase)->crc_transponse))

/* Reads and returns CRC Low byte */
#define ioctlCRC_READ_CRC_LOW_REG(pCrcBase, param)        \
    ((periphMemRead( &((pCrcBase)->crc_crcl))))

/* Reads and returns CRC High byte */
#define ioctlCRC_READ_CRC_HIGH_REG(pCrcBase, param)        \
    ((periphMemRead( &((pCrcBase)->crc_crch))))

/* Reads and returns CRC Transpose byte */
#define ioctlCRC_READ_CRC_TRANSPOSE(pCrcBase, param)        \
    ((periphMemRead( &((pCrcBase)->crc_transponse))))

/* writes to byte of CRC */
#define ioctlCRC_WRITE_INIT_VALUE(pCrcBase, param)        \
    periphMemWrite( ((param)>>8), &((pCrcBase)->crc_crch) ); \
    periphMemWrite( (param)&CRC_CRCL_CRCL_MASK, &((pCrcBase)->crc_crcl) )

/*  Low byte of CRC */
#define ioctlCRC_READ_CRC_RESULT(pCrcBase, param)        \
    (( (periphMemRead( &((pCrcBase)->crc_crcl) ))&CRC_CRCL_CRCL_MASK ) | ( ((periphMemRead( &((pCrcBase)->crc_crch) )))<<8 ))

#define ioctlCRC_WRITE_CRC_TRANSPOSED_DATA(pCrcBase, param)        \
    periphMemWrite( (param), &((pCrcBase)->crc_transponse) ); \
    periphMemWrite( periphMemRead( &((pCrcBase)->crc_transponse) ), &((pCrcBase)->crc_crcl) )

#endif

#if (CRC_VERSION == 2)

void crcInit(arch_sCRC *pCrcBase);
#define ioctlCRC_INIT(pCrcBase, param) crcInit(pCrcBase)

/* writes to CRC register*/
#define ioctlCRC_WRITE_CRC_REG(pCrcBase, param)\
        periphMemWrite((param), &((pCrcBase)->crc))

/* Reads and returns CRC register */
#define ioctlCRC_READ_CRC_REG(pCrcBase, param)\
        ((periphMemRead( &((pCrcBase)->crc))))

/* writes to GPOLY register*/
#define ioctlCRC_WRITE_GPOLY_REG(pCrcBase, param)\
        periphMemWrite((param), &((pCrcBase)->gpoly))

/* Reads and returns GPOLY register */
#define ioctlCRC_READ_GPOLY_REG(pCrcBase, param)\
        ((periphMemRead( &((pCrcBase)->gpoly))))

/* writes to CTRL register*/
#define ioctlCRC_WRITE_CTRL_REG(pCrcBase, param)\
        periphMemWrite((param), &((pCrcBase)->ctrl))

/* Reads and returns CTRL register */
#define ioctlCRC_READ_CTRL_REG(pCrcBase, param)\
        ((periphMemRead( &((pCrcBase)->ctrl))))

#define ioctlCRC_SET_COMPLEMENT_READ_OF_DATA_REG(pCrcBase, param)\
        if (param)periphBitSet(CRC_CTRL_FXOR ,&((pCrcBase)->ctrl)); \
        else periphBitClear(CRC_CTRL_FXOR ,&((pCrcBase)->ctrl))

#define ioctlCRC_SET_WRITE_AS_SEED(pCrcBase, param)\
        if (param)periphBitSet(CRC_CTRL_WAS ,&((pCrcBase)->ctrl)); \
        else periphBitClear(CRC_CTRL_WAS ,&((pCrcBase)->ctrl))

#define ioctlCRC_SET_PROTOCOL_WIDTH(pCrcBase, param)\
        if (param)periphBitSet(CRC_CTRL_TCRC ,&((pCrcBase)->ctrl)); \
        else periphBitClear(CRC_CTRL_TCRC ,&((pCrcBase)->ctrl))


#define ioctlCRC_WRITE_8BIT_CRC_VALUE(pCrcBase, param)\
        periphBitGrpSet32(CRC_CRC_LL_MASK, param, &((pCrcBase)->crc))
       
#define ioctlCRC_WRITE_16BIT_CRC_VALUE(pCrcBase, param)\
        periphBitGrpSet32(CRC_CRC_LU_MASK | CRC_CRC_LL_MASK, param, &((pCrcBase)->crc))
                 
#define ioctlCRC_WRITE_32BIT_CRC_VALUE(pCrcBase, param)\
        periphBitGrpSet32(CRC_CRC_LU_MASK | CRC_CRC_LL_MASK | CRC_CRC_HL_MASK | CRC_CRC_HU_MASK, param, &((pCrcBase)->crc))

#define ioctlCRC_READ_32BIT_CHECKSUM(pCrcBase, param)\
        periphBitTest(CRC_CRC_LU_MASK | CRC_CRC_LL_MASK | CRC_CRC_HL_MASK | CRC_CRC_HU_MASK, &((pCrcBase)->crc))

#define ioctlCRC_READ_16BIT_CHECKSUM(pCrcBase, param)\
        periphBitTest(CRC_CRC_LU_MASK | CRC_CRC_LL_MASK , &((pCrcBase)->crc))


#define ioctlCRC_WRITE_LOW_POLYNOMINAL(pCrcBase, param)\
        periphBitGrpSet32(CRC_GPOLY_LOW_MASK, param, &((pCrcBase)->gpoly))
               
#define ioctlCRC_WRITE_HIGH_POLYNOMINAL(pCrcBase, param)\
        periphBitGrpSet32(CRC_GPOLY_HIGH_MASK, (param)<<16, &((pCrcBase)->gpoly)) 

                 
#define ioctlCRC_SET_TRANSPOSE_TYPE_FOR_WRITES(pCrcBase, param)\
        periphBitGrpSet32(CRC_CTRL_TOT_MASK, param, &((pCrcBase)->ctrl))

#define ioctlCRC_SET_TRANSPOSE_TYPE_FOR_READ(pCrcBase, param)\
        periphBitGrpSet32(CRC_CTRL_TOTR_MASK, (param >> 2), &((pCrcBase)->ctrl))



#endif



#ifdef __cplusplus
}
#endif

#endif
