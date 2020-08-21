/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  aoi.h
*
* $Date:      May-6-2013$
*
* $Version:   1.0.3.0$
*
* Description: Header file for the AOI driver
*
* AOI_VERSION_1 ..  56F844x devices, see MC56F844xxRM.pdf
*                   56F845x devices, see MC56F845xxRM.pdf
*                   56F827x devices, see MC56F827xxRM.pdf
* 
*******************************************************************************/

#ifndef __AOI_H
#define __AOI_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before aoi.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*
*                      General Interface Description
*
*
* The AND/OR/INVERT module (known simply as the AOI module) supports the
* generation of a configurable number of EVENT signals. Each output EVENTn is a
* configurable and/or/invert function of four associated AOI inputs: An, Bn, Cn, and Dn.
* This module is designed to be integrated in conjuction with one or more inter-peripheral
* crossbar switch (XBAR_DSC) modules. A crossbar switch is typically used to select the
* 4*n AOI inputs from among available peripheral outputs and GPIO signals. The n
* EVENTn outputs from the AOI module are typically used as additional inputs to a second
* crossbar switch, adding to it the ability to connect to its outputs an arbitrary 4-input
* boolean function of its other inputs.
*
******************************************************************************/

/************************************************************
* AOI module identifiers
*************************************************************/

#ifdef AOI_BASE
#define AOI (&ArchIO.Aoi)
#endif


/*************************************************************
* arch.h should define device-specific information about AOI
**************************************************************/

#if !defined(AOI_VERSION)
#error AOI not properly described in arch.h
#endif

/****************************************************
* Configurable items, i.e. defines for appconfig.h
*****************************************************

#define AOI_BFCRT010_INIT             0x0000U
#define AOI_BFCRT230_INIT             0x0000U
#define AOI_BFCRT011_INIT             0x0000U
#define AOI_BFCRT231_INIT             0x0000U
#define AOI_BFCRT012_INIT             0x0000U
#define AOI_BFCRT232_INIT             0x0000U
#define AOI_BFCRT013_INIT             0x0000U
#define AOI_BFCRT233_INIT             0x0000U

*/

/*****************************************************************
* ioctl() commands
*
*  Word16 ioctl( AOI, Command_name, Parameter );
*
******************************************************************


 COMMAND NAME                      PARAMETERS, COMMENTS
--------------------------------------------------------*/

#define AOI_INIT                   /* NULL, Initialize AOI periheral registers using the appconfig.h _INIT values */

/* Write commands for AOI registers */ 
#define AOI_WRITE_BFCRT010      /* UWord16, write in to AOI Boolean Function Term register (BFCRT010->_) */
#define AOI_WRITE_BFCRT230      /* UWord16, write in to AOI Boolean Function Term register (BFCRT230->_) */
#define AOI_WRITE_BFCRT011      /* UWord16, write in to AOI Boolean Function Term register (BFCRT011->_) */
#define AOI_WRITE_BFCRT231      /* UWord16, write in to AOI Boolean Function Term register (BFCRT231->_) */
#define AOI_WRITE_BFCRT012      /* UWord16, write in to AOI Boolean Function Term register (BFCRT012->_) */
#define AOI_WRITE_BFCRT232      /* UWord16, write in to AOI Boolean Function Term register (BFCRT232->_) */
#define AOI_WRITE_BFCRT013      /* UWord16, write in to AOI Boolean Function Term register (BFCRT013->_) */
#define AOI_WRITE_BFCRT233      /* UWord16, write in to AOI Boolean Function Term register (BFCRT233->_) */

/* Read commands for AOI registers */
#define AOI_READ_BFCRT010       /* NULL, return UWord16 value of AOI Boolean Function Term register (BFCRT010->_) */
#define AOI_READ_BFCRT230       /* NULL, return UWord16 value of AOI Boolean Function Term register (BFCRT230->_) */
#define AOI_READ_BFCRT011       /* NULL, return UWord16 value of AOI Boolean Function Term register (BFCRT011->_) */
#define AOI_READ_BFCRT231       /* NULL, return UWord16 value of AOI Boolean Function Term register (BFCRT231->_) */
#define AOI_READ_BFCRT012       /* NULL, return UWord16 value of AOI Boolean Function Term register (BFCRT012->_) */
#define AOI_READ_BFCRT232       /* NULL, return UWord16 value of AOI Boolean Function Term register (BFCRT232->_) */
#define AOI_READ_BFCRT013       /* NULL, return UWord16 value of AOI Boolean Function Term register (BFCRT013->_) */
#define AOI_READ_BFCRT233       /* NULL, return UWord16 value of AOI Boolean Function Term register (BFCRT233->_) */

/* Commands for setup all inputs at once of the one product term */
/* for EVENT0 */
#define AOI_SET_EVENT0_TERM_0   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 0 for EVENT0 */
#define AOI_SET_EVENT0_TERM_1   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 1 for EVENT0 */
#define AOI_SET_EVENT0_TERM_2   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 2 for EVENT0 */
#define AOI_SET_EVENT0_TERM_3   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 3 for EVENT0 */

/* Commands for setup all inputs at once of the one product term */
/* for EVENT1 */
#define AOI_SET_EVENT1_TERM_0   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 0 for EVENT1 */
#define AOI_SET_EVENT1_TERM_1   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 1 for EVENT1 */
#define AOI_SET_EVENT1_TERM_2   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 2 for EVENT1 */
#define AOI_SET_EVENT1_TERM_3   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 3 for EVENT1 */

/* Commands for setup all inputs at once of the one product term */
/* for EVENT2 */
#define AOI_SET_EVENT2_TERM_0   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 0 for EVENT2 */
#define AOI_SET_EVENT2_TERM_1   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 1 for EVENT2 */
#define AOI_SET_EVENT2_TERM_2   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 2 for EVENT2 */
#define AOI_SET_EVENT2_TERM_3   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 3 for EVENT2 */

/* Commands for setup all inputs at once of the one product term */
/* for EVENT3 */
#define AOI_SET_EVENT3_TERM_0   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 0 for EVENT3 */
#define AOI_SET_EVENT3_TERM_1   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 1 for EVENT3 */
#define AOI_SET_EVENT3_TERM_2   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 2 for EVENT3 */
#define AOI_SET_EVENT3_TERM_3   /* combination of AOI_INPUT_n_xxx  (n = A/B /C/D; xxx = LOG0/INVERT/NOTINVER/LOG1 ), set all inputs at once of the Term 3 for EVENT3 */

/* Commands for setup inputs of the each product term  separately */
/* for EVENT0 */
#define AOI_SET_EVENT0_TERM_0_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 0 for EVENT0 */
#define AOI_SET_EVENT0_TERM_0_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 0 for EVENT0 */
#define AOI_SET_EVENT0_TERM_0_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 0 for EVENT0 */
#define AOI_SET_EVENT0_TERM_0_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 0 for EVENT0 */
#define AOI_SET_EVENT0_TERM_1_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 1 for EVENT0 */
#define AOI_SET_EVENT0_TERM_1_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 1 for EVENT0 */
#define AOI_SET_EVENT0_TERM_1_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 1 for EVENT0 */
#define AOI_SET_EVENT0_TERM_1_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 1 for EVENT0 */
#define AOI_SET_EVENT0_TERM_2_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 2 for EVENT0 */
#define AOI_SET_EVENT0_TERM_2_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 2 for EVENT0 */
#define AOI_SET_EVENT0_TERM_2_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 2 for EVENT0 */
#define AOI_SET_EVENT0_TERM_2_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 2 for EVENT0 */
#define AOI_SET_EVENT0_TERM_3_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 3 for EVENT0 */
#define AOI_SET_EVENT0_TERM_3_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 3 for EVENT0 */
#define AOI_SET_EVENT0_TERM_3_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 3 for EVENT0 */
#define AOI_SET_EVENT0_TERM_3_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 3 for EVENT0 */

/* Commands for setup inputs of the each product term  */
/* for EVENT1 */
#define AOI_SET_EVENT1_TERM_0_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 0 for EVENT1 */
#define AOI_SET_EVENT1_TERM_0_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 0 for EVENT1 */
#define AOI_SET_EVENT1_TERM_0_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 0 for EVENT1 */
#define AOI_SET_EVENT1_TERM_0_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 0 for EVENT1 */
#define AOI_SET_EVENT1_TERM_1_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 1 for EVENT1 */
#define AOI_SET_EVENT1_TERM_1_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 1 for EVENT1 */
#define AOI_SET_EVENT1_TERM_1_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 1 for EVENT1 */
#define AOI_SET_EVENT1_TERM_1_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 1 for EVENT1 */
#define AOI_SET_EVENT1_TERM_2_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 2 for EVENT1 */
#define AOI_SET_EVENT1_TERM_2_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 2 for EVENT1 */
#define AOI_SET_EVENT1_TERM_2_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 2 for EVENT1 */
#define AOI_SET_EVENT1_TERM_2_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 2 for EVENT1 */
#define AOI_SET_EVENT1_TERM_3_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 3 for EVENT1 */
#define AOI_SET_EVENT1_TERM_3_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 3 for EVENT1 */
#define AOI_SET_EVENT1_TERM_3_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 3 for EVENT1 */
#define AOI_SET_EVENT1_TERM_3_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 3 for EVENT1 */

/* Commands for setup inputs of the each product term  */
/* for EVENT2 */
#define AOI_SET_EVENT2_TERM_0_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 0 for EVENT2 */
#define AOI_SET_EVENT2_TERM_0_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 0 for EVENT2 */
#define AOI_SET_EVENT2_TERM_0_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 0 for EVENT2 */
#define AOI_SET_EVENT2_TERM_0_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 0 for EVENT2 */
#define AOI_SET_EVENT2_TERM_1_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 1 for EVENT2 */
#define AOI_SET_EVENT2_TERM_1_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 1 for EVENT2 */
#define AOI_SET_EVENT2_TERM_1_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 1 for EVENT2 */
#define AOI_SET_EVENT2_TERM_1_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 1 for EVENT2 */
#define AOI_SET_EVENT2_TERM_2_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 2 for EVENT2 */
#define AOI_SET_EVENT2_TERM_2_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 2 for EVENT2 */
#define AOI_SET_EVENT2_TERM_2_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 2 for EVENT2 */
#define AOI_SET_EVENT2_TERM_2_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 2 for EVENT2 */
#define AOI_SET_EVENT2_TERM_3_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 3 for EVENT2 */
#define AOI_SET_EVENT2_TERM_3_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 3 for EVENT2 */
#define AOI_SET_EVENT2_TERM_3_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 3 for EVENT2 */
#define AOI_SET_EVENT2_TERM_3_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 3 for EVENT2 */

/* Commands for setup inputs of the each product term  */
/* for EVENT3 */
#define AOI_SET_EVENT3_TERM_0_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 0 for EVENT3 */
#define AOI_SET_EVENT3_TERM_0_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 0 for EVENT3 */
#define AOI_SET_EVENT3_TERM_0_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 0 for EVENT3 */
#define AOI_SET_EVENT3_TERM_0_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 0 for EVENT3 */
#define AOI_SET_EVENT3_TERM_1_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 1 for EVENT3 */
#define AOI_SET_EVENT3_TERM_1_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 1 for EVENT3 */
#define AOI_SET_EVENT3_TERM_1_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 1 for EVENT3 */
#define AOI_SET_EVENT3_TERM_1_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 1 for EVENT3 */
#define AOI_SET_EVENT3_TERM_2_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 2 for EVENT3 */
#define AOI_SET_EVENT3_TERM_2_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 2 for EVENT3 */
#define AOI_SET_EVENT3_TERM_2_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 2 for EVENT3 */
#define AOI_SET_EVENT3_TERM_2_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 2 for EVENT3 */
#define AOI_SET_EVENT3_TERM_3_INPUT_A       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_A of the Term 3 for EVENT3 */
#define AOI_SET_EVENT3_TERM_3_INPUT_B       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_B of the Term 3 for EVENT3 */
#define AOI_SET_EVENT3_TERM_3_INPUT_C       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_C of the Term 3 for EVENT3 */
#define AOI_SET_EVENT3_TERM_3_INPUT_D       /* AOI_LOG0/AOI_INVERT/AOI_NOTINVERT/AOI_LOG1, set INPUT_D of the Term 3 for EVENT3 */

/***********************************************************************************************************
**  PARAMETERS DEFINITION                                                                        **
***********************************************************************************************************/

#define AOI_INPUT_A_LOG0        0x0000
#define AOI_INPUT_A_INVERT      0x0080
#define AOI_INPUT_A_NOTINVERT   0x0040
#define AOI_INPUT_A_LOG1        0x00C0

#define AOI_INPUT_B_LOG0        0x0000
#define AOI_INPUT_B_INVERT      0x0020
#define AOI_INPUT_B_NOTINVERT   0x0010
#define AOI_INPUT_B_LOG1        0x0030

#define AOI_INPUT_C_LOG0        0x0000
#define AOI_INPUT_C_INVERT      0x0008
#define AOI_INPUT_C_NOTINVERT   0x0004
#define AOI_INPUT_C_LOG1        0x000C

#define AOI_INPUT_D_LOG0        0x0000
#define AOI_INPUT_D_INVERT      0x0002
#define AOI_INPUT_D_NOTINVERT   0x0001
#define AOI_INPUT_D_LOG1        0x0003

#define AOI_LOG0                0x0000
#define AOI_INVERT              0x0002
#define AOI_NOTINVERT           0x0001
#define AOI_LOG1                0x0003

#define AOI_MSB_MASK            0xFF00
#define AOI_LSB_MASK            0x00FF

#define AOI_PT0_AC_MASK         0xC000
#define AOI_PT0_BC_MASK         0x3000            
#define AOI_PT0_CC_MASK         0x0C00 
#define AOI_PT0_DC_MASK         0x0300
#define AOI_PT1_AC_MASK         0x00C0
#define AOI_PT1_BC_MASK         0x0030
#define AOI_PT1_CC_MASK         0x000C
#define AOI_PT1_DC_MASK         0x0003

/****************************************************************************
* register and bit names used in the ioctl functions below
*****************************************************************************/

/* CTRL register */

/****************************************************************************
*  ioctl macro implementation
*****************************************************************************/

/* AOI init */

void aoiInit(arch_sAOI *pAoiBase);
#define ioctlAOI_INIT(pAoiBase, param) aoiInit(pAoiBase)


/*  control register */

#define ioctlSET_EVENT0_TERM_0(pAoiBase, param) \
        periphBitGrpSR(AOI_MSB_MASK , (param << 8), &((pAoiBase)->bfcrt010))

#define ioctlSET_EVENT0_TERM_1(pAoiBase, param) \
        periphBitGrpSR(AOI_LSB_MASK , param , &((pAoiBase)->bfcrt010))

#define ioctlSET_EVENT0_TERM_2(pAoiBase, param) \
        periphBitGrpSR(AOI_MSB_MASK , (param << 8) , &((pAoiBase)->bfcrt230))

#define ioctlSET_EVENT0_TERM_3(pAoiBase, param) \
        periphBitGrpSR(AOI_LSB_MASK , param , &((pAoiBase)->bfcrt230))

#define ioctlSET_EVENT1_TERM_0(pAoiBase, param) \
        periphBitGrpSR(AOI_MSB_MASK , (param << 8), &((pAoiBase)->bfcrt011))

#define ioctlSET_EVENT1_TERM_1(pAoiBase, param) \
        periphBitGrpSR(AOI_LSB_MASK , param , &((pAoiBase)->bfcrt011))

#define ioctlSET_EVENT1_TERM_2(pAoiBase, param) \
        periphBitGrpSR(AOI_MSB_MASK , (param << 8) , &((pAoiBase)->bfcrt231))

#define ioctlSET_EVENT1_TERM_3(pAoiBase, param) \
        periphBitGrpSR(AOI_LSB_MASK , param , &((pAoiBase)->bfcrt231))

#define ioctlSET_EVENT2_TERM_0(pAoiBase, param) \
        periphBitGrpSR(AOI_MSB_MASK , (param << 8), &((pAoiBase)->bfcrt012))

#define ioctlSET_EVENT2_TERM_1(pAoiBase, param) \
        periphBitGrpSR(AOI_LSB_MASK , param , &((pAoiBase)->bfcrt012))

#define ioctlSET_EVENT2_TERM_2(pAoiBase, param) \
        periphBitGrpSR(AOI_MSB_MASK , (param << 8) , &((pAoiBase)->bfcrt232))

#define ioctlSET_EVENT2_TERM_3(pAoiBase, param) \
        periphBitGrpSR(AOI_LSB_MASK , param , &((pAoiBase)->bfcrt232))

#define ioctlSET_EVENT3_TERM_0(pAoiBase, param) \
        periphBitGrpSR(AOI_MSB_MASK , (param << 8), &((pAoiBase)->bfcrt013))

#define ioctlSET_EVENT3_TERM_1(pAoiBase, param) \
        periphBitGrpSR(AOI_LSB_MASK , param , &((pAoiBase)->bfcrt013))

#define ioctlSET_EVENT3_TERM_2(pAoiBase, param) \
        periphBitGrpSR(AOI_MSB_MASK , (param << 8) , &((pAoiBase)->bfcrt233))

#define ioctlSET_EVENT3_TERM_3(pAoiBase, param) \
        periphBitGrpSR(AOI_LSB_MASK , param , &((pAoiBase)->bfcrt233))

/* write data to AOI registers */
#define ioctlAOI_WRITE_BFCRT010(pAoiBase, param) \
  periphMemWrite(param, &((pAoiBase)->bfcrt010))

#define ioctlAOI_WRITE_BFCRT230(pAoiBase, param) \
  periphMemWrite(param, &((pAoiBase)->bfcrt230))

#define ioctlAOI_WRITE_BFCRT011(pAoiBase, param) \
  periphMemWrite(param, &((pAoiBase)->bfcrt011))

#define ioctlAOI_WRITE_BFCRT231(pAoiBase, param) \
  periphMemWrite(param, &((pAoiBase)->bfcrt231))

#define ioctlAOI_WRITE_BFCRT012(pAoiBase, param) \
  periphMemWrite(param, &((pAoiBase)->bfcrt012))

#define ioctlAOI_WRITE_BFCRT232(pAoiBase, param) \
  periphMemWrite(param, &((pAoiBase)->bfcrt232))

#define ioctlAOI_WRITE_BFCRT013(pAoiBase, param) \
  periphMemWrite(param, &((pAoiBase)->bfcrt013))

#define ioctlAOI_WRITE_BFCRT233(pAoiBase, param) \
  periphMemWrite(param, &((pAoiBase)->bfcrt233))


/* return data from AOI registers */
#define ioctlAOI_READ_BFCRT010(pAoiBase, param) \
        periphMemRead(&((pAoiBase)->bfcrt010))

#define ioctlAOI_READ_BFCRT230(pAoiBase, param) \
        periphMemRead(&((pAoiBase)->bfcrt230))

#define ioctlAOI_READ_BFCRT011(pAoiBase, param) \
        periphMemRead(&((pAoiBase)->bfcrt011))

#define ioctlAOI_READ_BFCRT231(pAoiBase, param) \
        periphMemRead(&((pAoiBase)->bfcrt231))

#define ioctlAOI_READ_BFCRT012(pAoiBase, param) \
        periphMemRead(&((pAoiBase)->bfcrt012))

#define ioctlAOI_READ_BFCRT232(pAoiBase, param) \
        periphMemRead(&((pAoiBase)->bfcrt232))

#define ioctlAOI_READ_BFCRT013(pAoiBase, param) \
        periphMemRead(&((pAoiBase)->bfcrt013))

#define ioctlAOI_READ_BFCRT233(pAoiBase, param) \
        periphMemRead(&((pAoiBase)->bfcrt233))



#define ioctlAOI_SET_EVENT0_TERM_0_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_AC_MASK , (param << 14) , &((pAoiBase)->bfcrt010))

#define ioctlAOI_SET_EVENT0_TERM_0_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_BC_MASK , (param << 12) , &((pAoiBase)->bfcrt010))

#define ioctlAOI_SET_EVENT0_TERM_0_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_CC_MASK , (param << 10) , &((pAoiBase)->bfcrt010))

#define ioctlAOI_SET_EVENT0_TERM_0_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_DC_MASK , (param << 8) , &((pAoiBase)->bfcrt010))


#define ioctlAOI_SET_EVENT0_TERM_1_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_AC_MASK , (param << 6) , &((pAoiBase)->bfcrt010))

#define ioctlAOI_SET_EVENT0_TERM_1_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_BC_MASK , (param << 4) , &((pAoiBase)->bfcrt010))

#define ioctlAOI_SET_EVENT0_TERM_1_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_CC_MASK , (param << 2) , &((pAoiBase)->bfcrt010))

#define ioctlAOI_SET_EVENT0_TERM_1_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_DC_MASK , (param) , &((pAoiBase)->bfcrt010))


#define ioctlAOI_SET_EVENT0_TERM_2_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_AC_MASK , (param << 14) , &((pAoiBase)->bfcrt230))

#define ioctlAOI_SET_EVENT0_TERM_2_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_BC_MASK , (param << 12) , &((pAoiBase)->bfcrt230))

#define ioctlAOI_SET_EVENT0_TERM_2_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_CC_MASK , (param << 10) , &((pAoiBase)->bfcrt230))

#define ioctlAOI_SET_EVENT0_TERM_2_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_DC_MASK , (param << 8) , &((pAoiBase)->bfcrt230))


#define ioctlAOI_SET_EVENT0_TERM_3_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_AC_MASK , (param << 6) , &((pAoiBase)->bfcrt230))

#define ioctlAOI_SET_EVENT0_TERM_3_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_BC_MASK , (param << 4) , &((pAoiBase)->bfcrt230))

#define ioctlAOI_SET_EVENT0_TERM_3_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_CC_MASK , (param << 2) , &((pAoiBase)->bfcrt230))

#define ioctlAOI_SET_EVENT0_TERM_3_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_DC_MASK , (param) , &((pAoiBase)->bfcrt230))



#define ioctlAOI_SET_EVENT1_TERM_0_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_AC_MASK , (param << 14) , &((pAoiBase)->bfcrt011))

#define ioctlAOI_SET_EVENT1_TERM_0_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_BC_MASK , (param << 12) , &((pAoiBase)->bfcrt011))

#define ioctlAOI_SET_EVENT1_TERM_0_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_CC_MASK , (param << 10) , &((pAoiBase)->bfcrt011))

#define ioctlAOI_SET_EVENT1_TERM_0_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_DC_MASK , (param << 8) , &((pAoiBase)->bfcrt011))


#define ioctlAOI_SET_EVENT1_TERM_1_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_AC_MASK , (param << 6) , &((pAoiBase)->bfcrt011))

#define ioctlAOI_SET_EVENT1_TERM_1_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_BC_MASK , (param << 4) , &((pAoiBase)->bfcrt011))

#define ioctlAOI_SET_EVENT1_TERM_1_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_CC_MASK , (param << 2) , &((pAoiBase)->bfcrt011))

#define ioctlAOI_SET_EVENT1_TERM_1_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_DC_MASK , (param) , &((pAoiBase)->bfcrt011))


#define ioctlAOI_SET_EVENT1_TERM_2_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_AC_MASK , (param << 14) , &((pAoiBase)->bfcrt231))

#define ioctlAOI_SET_EVENT1_TERM_2_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_BC_MASK , (param << 12) , &((pAoiBase)->bfcrt231))

#define ioctlAOI_SET_EVENT1_TERM_2_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_CC_MASK , (param << 10) , &((pAoiBase)->bfcrt231))

#define ioctlAOI_SET_EVENT1_TERM_2_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_DC_MASK , (param << 8) , &((pAoiBase)->bfcrt231))


#define ioctlAOI_SET_EVENT1_TERM_3_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_AC_MASK , (param << 6) , &((pAoiBase)->bfcrt231))

#define ioctlAOI_SET_EVENT1_TERM_3_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_BC_MASK , (param << 4) , &((pAoiBase)->bfcrt231))

#define ioctlAOI_SET_EVENT1_TERM_3_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_CC_MASK , (param << 2) , &((pAoiBase)->bfcrt231))

#define ioctlAOI_SET_EVENT1_TERM_3_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_DC_MASK , (param) , &((pAoiBase)->bfcrt231))



#define ioctlAOI_SET_EVENT2_TERM_0_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_AC_MASK , (param << 14) , &((pAoiBase)->bfcrt012))

#define ioctlAOI_SET_EVENT2_TERM_0_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_BC_MASK , (param << 12) , &((pAoiBase)->bfcrt012))

#define ioctlAOI_SET_EVENT2_TERM_0_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_CC_MASK , (param << 10) , &((pAoiBase)->bfcrt012))

#define ioctlAOI_SET_EVENT2_TERM_0_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_DC_MASK , (param << 8) , &((pAoiBase)->bfcrt012))


#define ioctlAOI_SET_EVENT2_TERM_1_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_AC_MASK , (param << 6) , &((pAoiBase)->bfcrt012))

#define ioctlAOI_SET_EVENT2_TERM_1_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_BC_MASK , (param << 4) , &((pAoiBase)->bfcrt012))

#define ioctlAOI_SET_EVENT2_TERM_1_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_CC_MASK , (param << 2) , &((pAoiBase)->bfcrt012))

#define ioctlAOI_SET_EVENT2_TERM_1_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_DC_MASK , (param) , &((pAoiBase)->bfcrt012))


#define ioctlAOI_SET_EVENT2_TERM_2_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_AC_MASK , (param << 14) , &((pAoiBase)->bfcrt232))

#define ioctlAOI_SET_EVENT2_TERM_2_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_BC_MASK , (param << 12) , &((pAoiBase)->bfcrt232))

#define ioctlAOI_SET_EVENT2_TERM_2_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_CC_MASK , (param << 10) , &((pAoiBase)->bfcrt232))

#define ioctlAOI_SET_EVENT2_TERM_2_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_DC_MASK , (param << 8) , &((pAoiBase)->bfcrt232))


#define ioctlAOI_SET_EVENT2_TERM_3_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_AC_MASK , (param << 6) , &((pAoiBase)->bfcrt232))

#define ioctlAOI_SET_EVENT2_TERM_3_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_BC_MASK , (param << 4) , &((pAoiBase)->bfcrt232))

#define ioctlAOI_SET_EVENT2_TERM_3_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_CC_MASK , (param << 2) , &((pAoiBase)->bfcrt232))

#define ioctlAOI_SET_EVENT2_TERM_3_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_DC_MASK , (param) , &((pAoiBase)->bfcrt232))


#define ioctlAOI_SET_EVENT3_TERM_0_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_AC_MASK , (param << 14) , &((pAoiBase)->bfcrt013))

#define ioctlAOI_SET_EVENT3_TERM_0_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_BC_MASK , (param << 12) , &((pAoiBase)->bfcrt013))

#define ioctlAOI_SET_EVENT3_TERM_0_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_CC_MASK , (param << 10) , &((pAoiBase)->bfcrt013))

#define ioctlAOI_SET_EVENT3_TERM_0_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_DC_MASK , (param << 8) , &((pAoiBase)->bfcrt013))



#define ioctlAOI_SET_EVENT3_TERM_1_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_AC_MASK , (param << 6) , &((pAoiBase)->bfcrt013))

#define ioctlAOI_SET_EVENT3_TERM_1_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_BC_MASK , (param << 4) , &((pAoiBase)->bfcrt013))

#define ioctlAOI_SET_EVENT3_TERM_1_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_CC_MASK , (param << 2) , &((pAoiBase)->bfcrt013))

#define ioctlAOI_SET_EVENT3_TERM_1_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_DC_MASK , (param) , &((pAoiBase)->bfcrt013))



#define ioctlAOI_SET_EVENT3_TERM_2_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_AC_MASK , (param << 14) , &((pAoiBase)->bfcrt233))

#define ioctlAOI_SET_EVENT3_TERM_2_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_BC_MASK , (param << 12) , &((pAoiBase)->bfcrt233))

#define ioctlAOI_SET_EVENT3_TERM_2_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_CC_MASK , (param << 10) , &((pAoiBase)->bfcrt233))

#define ioctlAOI_SET_EVENT3_TERM_2_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT0_DC_MASK , (param << 8) , &((pAoiBase)->bfcrt233))


#define ioctlAOI_SET_EVENT3_TERM_3_INPUT_A(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_AC_MASK , (param << 6) , &((pAoiBase)->bfcrt233))

#define ioctlAOI_SET_EVENT3_TERM_3_INPUT_B(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_BC_MASK , (param << 4) , &((pAoiBase)->bfcrt233))

#define ioctlAOI_SET_EVENT3_TERM_3_INPUT_C(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_CC_MASK , (param << 2) , &((pAoiBase)->bfcrt233))

#define ioctlAOI_SET_EVENT3_TERM_3_INPUT_D(pAoiBase, param) \
        periphBitGrpSR(AOI_PT1_DC_MASK , (param) , &((pAoiBase)->bfcrt233))



#ifdef __cplusplus
}
#endif

#endif                                      
