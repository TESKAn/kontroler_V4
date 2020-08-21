/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-20013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* FILE NAME: mcm.h
*
* DESCRIPTION: Header file for the Miscellaneous Control Module
*
* This file supports different hardware versions of the module. A version
* of module used in your project is defined in the "arch.h" processor 
* architecture definition file.
*
*  MCM_VERSION_1 .. 56F844xx devices, see MC56F844xxRM.pdf, 56F847xx devices, see MC56F847XXRM.pdf
*                .. 56F823xx devices, see MC56F823xxRM.pdf, 56F827xx devices, see MC56F827xxRM.pdf
*
*******************************************************************************/

#ifndef __MCM_H
#define __MCM_H

/* qs.h is a master header file, which must be included */

#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before mcm.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************
* MCM module identifiers
*************************************************************/
#ifdef MCM_BASE
#define MCM (&ArchIO.Mcm)
#endif

/*************************************************************
* arch.h should define device-specific information about MCM
**************************************************************/

#if !defined(MCM_VERSION)
#error MCM not properly described in arch.h (old Quick_Start version?)
#endif

/*****************************************************************
* Software Layer ioctl() commands
*
*  Word16 ioctl( COP_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define MCM_INIT        /* NULL, initialize the MCM periheral registers using the appconfig.h _INIT values */


void mcmInit(arch_sMCM *pMcmBase);
#define ioctlMCM_INIT(pMcmBase, param) mcmInit(pMcmBase)


#ifdef __cplusplus
}
#endif

#endif

