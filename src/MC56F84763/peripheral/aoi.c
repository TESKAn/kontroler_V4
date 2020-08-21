/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  aoi.c
*
* $Date:      Jan-10-2013$
*
* $Version:   2.3.1.0$
*
* Description: Source file for the AIO driver
*
*****************************************************************************/

#include "qs.h"
#include "aoi.h"
#include "initconfig.h"

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************
 aoiInit() function performs the AOI module static configuration
 based on the configurable items from appconfig.h 
********************************************************************************/

void aoiInit(arch_sAOI *pAoiBase)
{
#pragma unused (pAoiBase)

#if AOI_INIT_USED && defined(AOI)
	if (pAoiBase == AOI)
	{
		#ifdef AOI_BFCRT010_INIT
		periphMemWrite(AOI_BFCRT010_INIT, &pAoiBase->bfcrt010);
		#endif
		
        #ifdef AOI_BFCRT230_INIT
        periphMemWrite(AOI_BFCRT230_INIT, &pAoiBase->bfcrt230);
        #endif
        
        #ifdef AOI_BFCRT011_INIT
        periphMemWrite(AOI_BFCRT011_INIT, &pAoiBase->bfcrt011);
        #endif
        
        #ifdef AOI_BFCRT231_INIT
        periphMemWrite(AOI_BFCRT231_INIT, &pAoiBase->bfcrt231);
        #endif
        
        #ifdef AOI_BFCRT012_INIT
        periphMemWrite(AOI_BFCRT012_INIT, &pAoiBase->bfcrt012);
        #endif
        
        #ifdef AOI_BFCRT232_INIT
        periphMemWrite(AOI_BFCRT232_INIT, &pAoiBase->bfcrt232);
        #endif
        
        #ifdef AOI_BFCRT013_INIT
        periphMemWrite(AOI_BFCRT013_INIT, &pAoiBase->bfcrt013);
        #endif
        
        #ifdef AOI_BFCRT233_INIT
        periphMemWrite(AOI_BFCRT233_INIT, &pAoiBase->bfcrt233);
        #endif
	}
	else
#endif	

	; /* last else case */
}


#ifdef __cplusplus
}
#endif

