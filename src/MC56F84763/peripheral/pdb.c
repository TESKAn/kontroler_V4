/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name: pdb_8xxx.c$
*
* $Date:      Feb-7-2013$
*
* $Version:   1.0.8.0$
*
* Description: Source file for the PDB Driver
*
*****************************************************************************/

#include "qs.h"
#include "pdb.h"
#include "initconfig.h"

#ifdef __cplusplus
extern "C" {
#endif


/* initialization of PDB  */

void pdbInit(arch_sPDB *pPdbBase)
{
#pragma unused(pPdbBase)
    
    
#if PDB_INIT_USED && defined(PDB)
    if (pPdbBase == PDB)
    {
        #ifdef PDB_DELAYA_INIT
        periphMemWrite(PDB_DELAYA_INIT, &pPdbBase->delaya);
        #endif
        #ifdef PDB_DELAYB_INIT
        periphMemWrite(PDB_DELAYB_INIT, &pPdbBase->delayc);
        #endif
        #ifdef PDB_MOD_INIT
        periphMemWrite(PDB_MOD_INIT, &pPdbBase->mod);
        #endif
    
    #if PDB_VERSION == 1
        #ifdef PDB_SCR_INIT
        periphMemWrite(PDB_SCR_INIT, &pPdbBase->scr);
        #endif
    #endif
        
    #if PDB_VERSION >= 2
        #ifdef PDB_MCTRL_INIT
        periphMemWrite(PDB_MCTRL_INIT, &pPdbBase->mctrl);
        #endif
        #ifdef PDB_DELAYC_INIT
        periphMemWrite(PDB_DELAYC_INIT, &pPdbBase->delayc);
        #endif
        #ifdef PDB_DELAYD_INIT
        periphMemWrite(PDB_DELAYD_INIT, &pPdbBase->delayd);
        #endif
        #ifdef PDB_CTRLA_INIT
        periphMemWrite(PDB_CTRLA_INIT, &pPdbBase->ctrla);
        #endif
        #ifdef PDB_CTRLC_INIT
        periphMemWrite(PDB_CTRLC_INIT, &pPdbBase->ctrlc);
        #endif
    #endif 
    }   
    else
#endif  
        
#ifdef PDB_0_INIT_USED
        
#endif
        
#if PDB_0_INIT_USED && defined(PDB_0)
    if (pPdbBase == PDB_0)
    {
        #ifdef PDB_0_DELAYA_INIT
        periphMemWrite(PDB_0_DELAYA_INIT, &pPdbBase->delaya);
        ioctl(PDB_0, PDB_LDOK, NULL);
        #endif
        #ifdef PDB_0_DELAYB_INIT
        periphMemWrite(PDB_0_DELAYB_INIT, &pPdbBase->delayb);
        ioctl(PDB_0, PDB_LDOK, NULL);
        #endif
        #ifdef PDB_0_DELAYC_INIT
        periphMemWrite(PDB_0_DELAYC_INIT, &pPdbBase->delayc);
        ioctl(PDB_0, PDB_LDOK, NULL);
        #endif
        #ifdef PDB_0_DELAYD_INIT
        periphMemWrite(PDB_0_DELAYD_INIT, &pPdbBase->delayd);
        ioctl(PDB_0, PDB_LDOK, NULL);
        #endif
        #ifdef PDB_0_MOD_INIT
        periphMemWrite(PDB_0_MOD_INIT, &pPdbBase->mod);
        ioctl(PDB_0, PDB_LDOK, NULL);
        #endif
    
    #if PDB_VERSION == 1
        #ifdef PDB_0_SCR_INIT
        periphMemWrite(PDB_0_SCR_INIT, &pPdbBase->scr);
        #endif
    #endif
        
    #if PDB_VERSION >= 2
        #ifdef PDB_0_MCTRL_INIT
        periphMemWrite(PDB_0_MCTRL_INIT, &pPdbBase->mctrl);
        #endif
        #ifdef PDB_0_CTRLA_INIT
        periphMemWrite(PDB_0_CTRLA_INIT, &pPdbBase->ctrla);
        #endif
        #ifdef PDB_0_CTRLC_INIT
        periphMemWrite(PDB_0_CTRLC_INIT, &pPdbBase->ctrlc);
        #endif
    #endif 
    }               
    else
#endif  
    


        
#if PDB_1_INIT_USED && defined(PDB_1)
    if (pPdbBase == PDB_1)
    {
        #ifdef PDB_1_DELAYA_INIT
        periphMemWrite(PDB_1_DELAYA_INIT, &pPdbBase->delaya);
        ioctl(PDB_1, PDB_LDOK, NULL);
        #endif
        #ifdef PDB_1_DELAYB_INIT
        periphMemWrite(PDB_1_DELAYB_INIT, &pPdbBase->delayb);
        ioctl(PDB_1, PDB_LDOK, NULL);
        #endif
        #ifdef PDB_1_DELAYC_INIT
        periphMemWrite(PDB_1_DELAYC_INIT, &pPdbBase->delayc);
        ioctl(PDB_1, PDB_LDOK, NULL);
        #endif
        #ifdef PDB_1_DELAYD_INIT
        periphMemWrite(PDB_1_DELAYD_INIT, &pPdbBase->delayd);
        ioctl(PDB_1, PDB_LDOK, NULL);
        #endif   
        #ifdef PDB_1_MOD_INIT
        periphMemWrite(PDB_1_MOD_INIT, &pPdbBase->mod);
        ioctl(PDB_1, PDB_LDOK, NULL);
        #endif
    
    #if PDB_VERSION == 1
        #ifdef PDB_1_SCR_INIT
        periphMemWrite(PDB_1_SCR_INIT, &pPdbBase->scr);
        #endif
    #endif
        
    #if PDB_VERSION >= 2
        #ifdef PDB_1_MCTRL_INIT
        periphMemWrite(PDB_1_MCTRL_INIT, &pPdbBase->mctrl);
        #endif

        #ifdef PDB_1_CTRLA_INIT
        periphMemWrite(PDB_1_CTRLA_INIT, &pPdbBase->ctrla);
        #endif
        #ifdef PDB_1_CTRLC_INIT
        periphMemWrite(PDB_1_CTRLC_INIT, &pPdbBase->ctrlc);
        #endif
    #endif 
    }    
    else
#endif  
        ; /* last else case */
}


#ifdef __cplusplus
}
#endif
