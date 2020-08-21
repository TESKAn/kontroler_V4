/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name: crc_8xxx.c$
*
* $Date:      Apr-22-2013$
*
* $Version:   2.5.5.0$
*
* Description: Source file for the CRC Driver
*
*****************************************************************************/

#include "qs.h"
#include "crc.h"

#ifdef __cplusplus
extern "C" {
#endif

#if (CRC_VERSION == 2) 

void crcInit(arch_sCRC *pCrcBase)
{
#pragma unused(pCrcBase)

#ifdef CRC_CTRL_INIT
    periphMemWrite(CRC_CTRL_INIT, &(pCrcBase)->ctrl);
#endif
    
#ifdef CRC_GPOLY_INIT
    periphMemWrite(CRC_GPOLY_INIT, &(pCrcBase)->gpoly);
#endif
     
}
#endif

#ifdef __cplusplus
}
#endif
