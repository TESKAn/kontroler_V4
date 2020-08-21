/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* FILE NAME: ftfl.h
*
* DESCRIPTION: Header file for the flash memory controller
*
*
* NOTES:
*
*******************************************************************************/

#ifndef __FTFL_H
#define __FTFL_H

/* qs.h is a master header file, which must be included */

#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before ftfl.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************
* FTFL module identifiers
*************************************************************/
#ifdef FTFL_BASE
#define FTFL (&ArchIO.Ftfl)
#endif

/*************************************************************
* arch.h should define device-specific information about FTFL
**************************************************************/

#if !defined(FTFL_VERSION)
#error FTFL not properly described in arch.h (old Quick_Start version?)
#endif

/* command names */

#define FTFL_INIT        /* NULL */


void ftflInit(arch_sFTFL *pFtflBase);
#define ioctlFTFL_INIT(pFtflBase, param) ftflInit(pFtflBase)



#ifdef __cplusplus
}
#endif

#endif

