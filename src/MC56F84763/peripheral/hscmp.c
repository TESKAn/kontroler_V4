/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  hscmp.c
*
* $Date:      Jan-31-2013$
*
* $Version:   2.5.8.0$
*
* Description: Source file for the HSCMP driver
* 
* HSCMP_VERSION_1 .. 56F800x devices, see MC56F8006RM.pdf
* HSCMP_VERSION_2 .. 56F82xx devices, see MC56F82xxRM.pdf
*
*****************************************************************************/

#include "qs.h"
#include "hscmp.h"
#include "initconfig.h"

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************
 hscmpInit() function performs the HSCMP module static configuration
 based on the configurable items from appconfig.h 
********************************************************************************/

void hscmpInit(arch_sHSCMP *pHscmpBase)
{
#pragma unused(pHscmpBase)

#if HSCMP_0_INIT_USED && defined(HSCMP_0)
	if (pHscmpBase == HSCMP_0)
	{
		#ifdef HSCMP_0_CR0_INIT
		periphMemWrite(HSCMP_0_CR0_INIT, &pHscmpBase->cr0);
		#endif

		#ifdef HSCMP_0_CR1_INIT
		periphMemWrite(HSCMP_0_CR1_INIT, &pHscmpBase->cr1);
		#endif

		#ifdef HSCMP_0_FPR_INIT
		periphMemWrite(HSCMP_0_FPR_INIT, &pHscmpBase->fpr);
		#endif

		#ifdef HSCMP_0_SCR_INIT
		periphMemWrite(HSCMP_0_SCR_INIT, &pHscmpBase->scr);
		#endif

	}
	else
#endif	

#if HSCMP_1_INIT_USED && defined(HSCMP_1)
	if (pHscmpBase == HSCMP_1)
	{
		#ifdef HSCMP_1_CR0_INIT
		periphMemWrite(HSCMP_1_CR0_INIT, &pHscmpBase->cr0);
		#endif

		#ifdef HSCMP_1_CR1_INIT
		periphMemWrite(HSCMP_1_CR1_INIT, &pHscmpBase->cr1);
		#endif

		#ifdef HSCMP_1_FPR_INIT
		periphMemWrite(HSCMP_1_FPR_INIT, &pHscmpBase->fpr);
		#endif

		#ifdef HSCMP_1_SCR_INIT
		periphMemWrite(HSCMP_1_SCR_INIT, &pHscmpBase->scr);
		#endif
	}
	else
#endif	

#if HSCMP_2_INIT_USED && defined(HSCMP_2)
	if (pHscmpBase == HSCMP_2)
	{
		#ifdef HSCMP_2_CR0_INIT
		periphMemWrite(HSCMP_2_CR0_INIT, &pHscmpBase->cr0);
		#endif

		#ifdef HSCMP_2_CR1_INIT
		periphMemWrite(HSCMP_2_CR1_INIT, &pHscmpBase->cr1);
		#endif

		#ifdef HSCMP_2_FPR_INIT
		periphMemWrite(HSCMP_2_FPR_INIT, &pHscmpBase->fpr);
		#endif

		#ifdef HSCMP_2_SCR_INIT
		periphMemWrite(HSCMP_2_SCR_INIT, &pHscmpBase->scr);
		#endif
	}
	else
#endif

#if HSCMP_A_INIT_USED && defined(HSCMP_A)
	if (pHscmpBase == HSCMP_A)
	{
		#ifdef HSCMP_A_CR0_INIT
		periphMemWrite(HSCMP_A_CR0_INIT, &pHscmpBase->cr0);
		#endif

		#ifdef HSCMP_A_CR1_INIT
		periphMemWrite(HSCMP_A_CR1_INIT, &pHscmpBase->cr1);
		#endif

		#ifdef HSCMP_A_FPR_INIT
		periphMemWrite(HSCMP_A_FPR_INIT, &pHscmpBase->fpr);
		#endif

		#ifdef HSCMP_A_SCR_INIT
		periphMemWrite(HSCMP_A_SCR_INIT, &pHscmpBase->scr);
		#endif
        
        #ifdef HSCMP_A_DACCR_INIT
        periphMemWrite(HSCMP_A_DACCR_INIT, &pHscmpBase->daccr);
        #endif
        
        #ifdef HSCMP_A_MUXCR_INIT
        periphMemWrite(HSCMP_A_MUXCR_INIT, &pHscmpBase->muxcr);
        #endif
	}
	else
#endif

#if HSCMP_B_INIT_USED && defined(HSCMP_B)
	if (pHscmpBase == HSCMP_B)
	{
		#ifdef HSCMP_B_CR0_INIT
		periphMemWrite(HSCMP_B_CR0_INIT, &pHscmpBase->cr0);
		#endif

		#ifdef HSCMP_B_CR1_INIT
		periphMemWrite(HSCMP_B_CR1_INIT, &pHscmpBase->cr1);
		#endif

		#ifdef HSCMP_B_FPR_INIT
		periphMemWrite(HSCMP_B_FPR_INIT, &pHscmpBase->fpr);
		#endif

		#ifdef HSCMP_B_SCR_INIT
		periphMemWrite(HSCMP_B_SCR_INIT, &pHscmpBase->scr);
		#endif
		       
        #ifdef HSCMP_B_DACCR_INIT
        periphMemWrite(HSCMP_B_DACCR_INIT, &pHscmpBase->daccr);
        #endif
        
        #ifdef HSCMP_B_MUXCR_INIT
        periphMemWrite(HSCMP_B_MUXCR_INIT, &pHscmpBase->muxcr);
        #endif
	}
	else
#endif

#if HSCMP_C_INIT_USED && defined(HSCMP_C)
	if (pHscmpBase == HSCMP_C)
	{
		#ifdef HSCMP_C_CR0_INIT
		periphMemWrite(HSCMP_C_CR0_INIT, &pHscmpBase->cr0);
		#endif

		#ifdef HSCMP_C_CR1_INIT
		periphMemWrite(HSCMP_C_CR1_INIT, &pHscmpBase->cr1);
		#endif

		#ifdef HSCMP_C_FPR_INIT
		periphMemWrite(HSCMP_C_FPR_INIT, &pHscmpBase->fpr);
		#endif

		#ifdef HSCMP_C_SCR_INIT
		periphMemWrite(HSCMP_C_SCR_INIT, &pHscmpBase->scr);
		#endif
        
        #ifdef HSCMP_C_DACCR_INIT
        periphMemWrite(HSCMP_C_DACCR_INIT, &pHscmpBase->daccr);
        #endif
        
        #ifdef HSCMP_C_MUXCR_INIT
        periphMemWrite(HSCMP_C_MUXCR_INIT, &pHscmpBase->muxcr);
        #endif
		
	}
	else
#endif
	    
#if HSCMP_D_INIT_USED && defined(HSCMP_D)
    if (pHscmpBase == HSCMP_D)
    {
        #ifdef HSCMP_D_CR0_INIT
        periphMemWrite(HSCMP_D_CR0_INIT, &pHscmpBase->cr0);
        #endif

        #ifdef HSCMP_D_CR1_INIT
        periphMemWrite(HSCMP_D_CR1_INIT, &pHscmpBase->cr1);
        #endif

        #ifdef HSCMP_D_FPR_INIT
        periphMemWrite(HSCMP_D_FPR_INIT, &pHscmpBase->fpr);
        #endif

        #ifdef HSCMP_D_SCR_INIT
        periphMemWrite(HSCMP_D_SCR_INIT, &pHscmpBase->scr);
        #endif
        
        #ifdef HSCMP_D_DACCR_INIT
        periphMemWrite(HSCMP_D_DACCR_INIT, &pHscmpBase->daccr);
        #endif
        
        #ifdef HSCMP_D_MUXCR_INIT
        periphMemWrite(HSCMP_D_MUXCR_INIT, &pHscmpBase->muxcr);
        #endif

    }
    else
#endif


	; /* last else case */
}

#ifdef __cplusplus
}
#endif

