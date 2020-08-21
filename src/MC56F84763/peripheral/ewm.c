/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  ewm.c
*
* $Date:      Apr-3-2013$
*
* $Version:   2.3.1.0$
*
* Description: Source file for the EWM Driver
*
*****************************************************************************/

#include "qs.h"
#include "ewm.h"

#ifdef __cplusplus
extern "C" {
#endif

/* initialization of EWM (external watchdog monitor) */

void ewmInit(arch_sEWM *pEwmBase)
{
#pragma unused(pEwmBase)

	#ifdef EWM_CLKPRESCALER_INIT
	periphMemWrite(EWM_CLKPRESCALER_INIT, &pEwmBase->clkprescaler);
	#endif
	
    #ifdef EWM_CLKCTRL_INIT
    periphMemWrite(EWM_CLKCTRL_INIT, &pEwmBase->clkctrl);
    #endif
	
    #ifdef EWM_CMPL_INIT
    periphMemWrite(EWM_CMPL_INIT, &pEwmBase->cmpl);
    #endif
    
    #ifdef EWM_CMPH_INIT
    periphMemWrite(EWM_CMPH_INIT, &pEwmBase->cmph);
    #endif
    
    #ifdef EWM_CTRL_INIT
    periphMemWrite(EWM_CTRL_INIT, &pEwmBase->ctrl);
    #endif

}

#ifdef __cplusplus
}
#endif
