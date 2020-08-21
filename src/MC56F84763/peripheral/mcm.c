/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name: mcm_84xxx_82xxx.c$
*
* $Date:      May-29-2013$
*
* $Version:   2.5.3.0$
*
* Description: Source file for the MCM Driver
*
*****************************************************************************/

#include "qs.h"
#include "mcm.h"

#ifdef __cplusplus
extern "C" {
#endif

void mcmInit(arch_sMCM *pMcmBase)
{
#pragma unused(pMcmBase)

    #ifdef MCM_CPCR_INIT   
	periphMemWrite(MCM_CPCR_INIT, &pMcmBase->cpcr);
    #endif

    #ifdef MCM_CFIER_INIT
	periphMemWrite(MCM_CFIER_INIT, &pMcmBase->cfier);
    #endif

    #ifdef MCM_CFISR_INIT
	periphMemWrite(MCM_CFISR_INIT, &pMcmBase->cfisr);
    #endif

    #ifdef MCM_UFLASHBAR_INIT
	periphMemWrite(MCM_UFLASHBAR_INIT, &pMcmBase->uflashbar);
    #endif

    #ifdef MCM_UPRAMBAR_INIT
	periphMemWrite(MCM_UPRAMBAR_INIT, &pMcmBase->uprambar);
    #endif

    #ifdef MCM_SRPOSP_INIT
	periphMemWrite(MCM_SRPOSP_INIT, &pMcmBase->srposp);
    #endif

    #ifdef MCM_SRPIPC_INIT
	periphMemWrite(MCM_SRPIPC_INIT, &pMcmBase->srpipc);
    #endif

    #ifdef MCM_SRPMPC_INIT
	periphMemWrite(MCM_SRPMPC_INIT, &pMcmBase->srpmpc);
    #endif

	#ifdef MCM_RPCR_INIT
	periphMemWrite(MCM_RPCR_INIT, &pMcmBase->rpcr);
	#endif
}

#ifdef __cplusplus
}
#endif
