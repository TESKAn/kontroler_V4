/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name: ftfl_84xxx_82xxx.c$
*
* $Date:      May-28-2013$
*
* $Version:   2.5.3.0$
*
* Description: Source file for the FTFL Driver
*
*****************************************************************************/

#include "qs.h"
#include "ftfl.h"

#ifdef __cplusplus
extern "C" {
#endif

void ftflInit(arch_sFTFL *pFtflBase)
{
#pragma unused(pFtflBase)

    #ifdef FTFL_FSTAT_INIT
	periphMemWrite(FTFL_FSTAT_INIT, &pFtflBase->fstat);
    #endif

    #ifdef FTFL_FCNFG_INIT
	periphMemWrite(FTFL_FCNFG_INIT, &pFtflBase->fcnfg);
    #endif

    #ifdef FTFL_FSEC_INIT
	periphMemWrite(FTFL_FSEC_INIT, &pFtflBase->fsec);
    #endif

    #ifdef FTFL_FOPT_INIT
	periphMemWrite(FTFL_FOPT_INIT, &pFtflBase->fopt);
    #endif

    #ifdef FTFL_FCCOB3_INIT
	periphMemWrite(FTFL_FCCOB3_INIT, &pFtflBase->fccob3);
    #endif

    #ifdef FTFL_FCCOB2_INIT
	periphMemWrite(FTFL_FCCOB2_INIT, &pFtflBase->fccob2);
    #endif

    #ifdef FTFL_FCCOB1_INIT
	periphMemWrite(FTFL_FCCOB1_INIT, &pFtflBase->fccob1);
    #endif

    #ifdef FTFL_FCCOB0_INIT
	periphMemWrite(FTFL_FCCOB0_INIT, &pFtflBase->fccob0);
    #endif

    #ifdef FTFL_FCCOB7_INIT
	periphMemWrite(FTFL_FCCOB7_INIT, &pFtflBase->fccob7);
    #endif

    #ifdef FTFL_FCCOB6_INIT
	periphMemWrite(FTFL_FCCOB6_INIT, &pFtflBase->fccob6);
    #endif

    #ifdef FTFL_FCCOB5_INIT
	periphMemWrite(FTFL_FCCOB5_INIT, &pFtflBase->fccob5);
    #endif

	#ifdef FTFL_FCCOBB_INIT
	periphMemWrite(FTFL_FCCOBB_INIT, &pFtflBase->fccobb);
	#endif
	
    #ifdef FTFL_FCCOB4_INIT
	periphMemWrite(FTFL_FCCOB4_INIT, &pFtflBase->fccob4);
    #endif

    #ifdef FTFL_FCCOBA_INIT
	periphMemWrite(FTFL_FCCOBA_INIT, &pFtflBase->fccoba);
    #endif

    #ifdef FTFL_FCCOB9_INIT
	periphMemWrite(FTFL_FCCOB9_INIT, &pFtflBase->fccob9);
    #endif

    #ifdef FTFL_FCCOB8_INIT
	periphMemWrite(FTFL_FCCOB8_INIT, &pFtflBase->fccob8);
    #endif

    #ifdef FTFL_FPROT3_INIT
	periphMemWrite(FTFL_FPROT3_INIT, &pFtflBase->fprot3);
    #endif

    #ifdef FTFL_FPROT2_INIT
	periphMemWrite(FTFL_FPROT2_INIT, &pFtflBase->fprot2);
    #endif

    #ifdef FTFL_FPROT1_INIT
	periphMemWrite(FTFL_FPROT1_INIT, &pFtflBase->fprot1);
    #endif

    #ifdef FTFL_FPROT0_INIT
	periphMemWrite(FTFL_FPROT0_INIT, &pFtflBase->fprot0);
    #endif
    
#if FTFL_VERSION == 1  
    #ifdef FTFL_FEPROT_INIT
	periphMemWrite(FTFL_FEPROT_INIT, &pFtflBase->feprot);
    #endif
    
    #ifdef FTFL_FDPROT_INIT
	periphMemWrite(FTFL_FDPROT_INIT, &pFtflBase->fdprot);
    #endif
#endif

}



#ifdef __cplusplus
}
#endif
