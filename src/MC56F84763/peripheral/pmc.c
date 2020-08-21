/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  pmc.c
*
* $Date:      Feb-25-2013$
*
* $Version:   1.0.8.0$
*
* Description: PMC (Power management controller) driver
*
*****************************************************************************/

#include "qs.h"
#include "pmc.h"

#ifdef __cplusplus
extern "C" {
#endif

/* initialization of PMC Power Management Controller */
#if (PMC_VERSION ==1)
void pmcInit(arch_sPMC *pPmcBase)
{
#pragma unused(pPmcBase)

	#ifdef PMC_SCR_INIT
	periphMemWrite(PMC_SCR_INIT, &pPmcBase->scr);
	#endif
 
	#ifdef PMC_CR2_INIT
	periphMemWrite(PMC_CR2_INIT, &pPmcBase->cr2);
	#endif

	#if PMC_USE_FACTORY_1KHZ_TRIM
	ioctl(PMC, PMC_SET_1KHZ_OSC_FACTORY_TRIM, NULL);
	#endif

	#if PMC_USE_FACTORY_LVD_TRIM
	ioctl(PMC, PMC_SET_LVD_FACTORY_TRIM, NULL);
	#endif
   
}
#endif /* PMC_VERSION == 1 */

#if (PMC_VERSION ==2)
void pmcInit(arch_sPMC *pPmcBase)
{
#pragma unused(pPmcBase)

    #ifdef PMC_CONTROL_INIT
    periphMemWrite(PMC_CONTROL_INIT, &pPmcBase->ctrl);
    #endif
 }
#endif /* PMC_VERSION ==2 */

#ifdef __cplusplus
}
#endif
