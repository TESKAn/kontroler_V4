/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  cop.c
*
* $Date:      Jan-15-2013$
*
* $Version:   2.3.18.0$
*
* Description: Source file for the COP Driver
*
*****************************************************************************/

#include "qs.h"
#include "cop.h"

#ifdef __cplusplus
extern "C" {
#endif

/* initialization of COP (watchdog) */

void copInit(arch_sCOP *pCopBase)
{
#pragma unused(pCopBase)

	/* we are writing to COP Timeout reg first to allow using
	   write protect bit (CWP) in COP Control Reg */ 
	
	#ifdef COP_COPTO_INIT
	periphMemWrite(COP_COPTO_INIT, &pCopBase->copto);
	#endif
	#ifdef COP_COPCTL_INIT
	periphMemWrite(COP_COPCTL_INIT, &pCopBase->copctl);
	#endif
    
#if COP_VERSION >= 4
	#ifdef COP_INITVAL_INIT
	periphMemWrite(COP_INITVAL_INIT, &pCopBase->intval);
	#endif
#endif
		
#if COP_VERSION >= 5
	#ifdef COP_WINDOW_INIT
	periphMemWrite(COP_WINDOW_INIT, &pCopBase->window);
	#endif
	
#endif	
	
	/* COP Service Register is not initialized */
}

#ifdef __cplusplus
}
#endif
