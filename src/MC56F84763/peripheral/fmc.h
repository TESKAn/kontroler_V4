/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* FILE NAME: fmc.h
*
* DESCRIPTION: Header file for the flash memory controller
*
* This file supports different hardware versions of the module. A version
* of module used in your project is defined in the "arch.h" processor 
* architecture definition file.
*
*  FMC_VERSION_1 .. 56F844xx devices, see MC56F844xxRM.pdf, 56F847xx devices, see MC56F847XXRM.pdf
*  FMC_VERSION_2 .. 56F823xx devices, see MC56F823xxRM.pdf, 56F827xx devices, see MC56F827xxRM.pdf
*
*******************************************************************************/

#ifndef __FMC_H
#define __FMC_H

/* qs.h is a master header file, which must be included */

#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before fmc.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************
* FMC module identifiers
*************************************************************/
#ifdef FMC_BASE
#define FMC (&ArchIO.Fmc)
#endif

/*************************************************************
* arch.h should define device-specific information about FMC
**************************************************************/

#if !defined(FMC_VERSION)
#error FMC not properly described in arch.h (old Quick_Start version?)
#endif

/* command names */

#define FMC_INIT        /* NULL, initialize the FMC periheral registers using the appconfig.h _INIT values */


void fmcInit(arch_sFMC *pFmcBase);
#define ioctlFMC_INIT(pFmcBase, param) fmcInit(pFmcBase)


#ifdef __cplusplus
}
#endif

#endif

