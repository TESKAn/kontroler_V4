/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name: fmc.c$
*
* $Date:      Apr-12-2013$
*
* $Version:   2.5.1.0$
*
* Description: Source file for the FMC Driver
*
*****************************************************************************/

#include "qs.h"
#include "fmc.h"

#ifdef __cplusplus
extern "C" {
#endif

void fmcInit(arch_sFMC *pFmcBase)
{
#pragma unused(pFmcBase)

#ifdef FMC_PFAPR_INIT
    periphMemWrite(FMC_PFAPR_INIT, &pFmcBase->pfapr);
#endif
    
#ifdef FMC_PFB0CR_INIT
    periphMemWrite(FMC_PFB0CR_INIT, &pFmcBase->pfb0cr);
#endif
}



#ifdef __cplusplus
}
#endif
