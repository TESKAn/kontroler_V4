/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  fcan.c
*
* $Date:      Jun-25-2013$
*
* $Version:   2.3.3.0$
*
* Description: Source file for the FlexCAN driver
*
*****************************************************************************/

#include "qs.h"
#include "fcan.h"
#include "initconfig.h"

#ifdef __cplusplus
extern "C" {
#endif

/* initialization of FlexCAN */

void FCAN_Init(arch_sFlexCAN *pFCanBase)
{
#if FCAN_INIT_USED
    UWord16 i;

    /* disable the module to be able to select its clock source */
    ioctl(pFCanBase, FCAN_MODULE, FCAN_DISABLE);
    
    #ifdef FCAN_CTRL1_INIT
    periphMemWrite(FCAN_CTRL1_INIT & FCAN_CTRL1_CLKSRC, &pFCanBase->ctrl1);
    #endif
    
    /* put the module safely into soft-reset state */
    ioctl(pFCanBase, FCAN_MODULE, FCAN_ENABLE);             
    ioctl(pFCanBase, FCAN_STOP_MODE, FCAN_DISABLE);
    ioctl(pFCanBase, FCAN_SOFT_RESET, NULL);

    /* Enable and enter HALT (Freeze) mode */
    ioctl(pFCanBase, FCAN_DEBUG_MODE, FCAN_ENABLE);
    
    /* wait for entering the debug mode (FRZACK) */
    while(!ioctl(pFCanBase, FCAN_TEST_DEBUG, NULL))
        ; /* do nothing */

    /* enable individual masking and other early-init bits, keep HALT and FRZ bits */
    #ifdef FCAN_MCR_INIT
    periphMemWrite((FCAN_MCR_INIT & FCAN_MCR_STARTUP_PHASE1) | FCAN_MCR_HALT | FCAN_MCR_FRZ, &pFCanBase->mcr);
    #endif
    
    #ifdef FCAN_CTRL1_INIT
    periphMemWrite(FCAN_CTRL1_INIT, &pFCanBase->ctrl1);
    #endif
    
    #ifdef FCAN_CTRL2_INIT
    periphMemWrite(FCAN_CTRL2_INIT, &pFCanBase->ctrl2);
    #endif
        
    /* initialize all MBs */ 
    for(i=0; i<ARCH_FCAN_MBCOUNT; i++)
    {
        periphMemWrite(0, &pFCanBase->mb[i].cs);
        periphMemWrite(0, &pFCanBase->mb[i].id);
        periphMemWrite(0, &pFCanBase->mb[i].data[0]);
        periphMemWrite(0, &pFCanBase->mb[i].data[1]);
    }
        
    #ifdef FCAN_RXMGMASK_INIT
    periphMemWrite(FCAN_RXMGMASK_INIT, &pFCanBase->rxmgmask);
    #endif
    #ifdef FCAN_RXFGMASK_INIT
    periphMemWrite(FCAN_RXFGMASK_INIT, &pFCanBase->rxfgmask);
    #endif
    #ifdef FCAN_RX14MASK_INIT
    periphMemWrite(FCAN_RX14MASK_INIT, &pFCanBase->rx14mask);
    #endif
    #ifdef FCAN_RX15MASK_INIT
    periphMemWrite(FCAN_RX15MASK_INIT, &pFCanBase->rx15mask);
    #endif
    
    #ifdef FCAN_IMASK1_INIT
    periphMemWrite(FCAN_IMASK1_INIT, &pFCanBase->imask1);
    #endif
    
    #ifdef FCAN_RXIMR0_INIT
    periphMemWrite(FCAN_RXIMR0_INIT, &pFCanBase->rximr0);
    #endif
    #ifdef FCAN_RXIMR1_INIT
    periphMemWrite(FCAN_RXIMR1_INIT, &pFCanBase->rximr1);
    #endif
    #ifdef FCAN_RXIMR2_INIT
    periphMemWrite(FCAN_RXIMR2_INIT, &pFCanBase->rximr2);
    #endif
    #ifdef FCAN_RXIMR3_INIT
    periphMemWrite(FCAN_RXIMR3_INIT, &pFCanBase->rximr3);
    #endif
    #ifdef FCAN_RXIMR4_INIT
    periphMemWrite(FCAN_RXIMR4_INIT, &pFCanBase->rximr4);
    #endif
    #ifdef FCAN_RXIMR5_INIT
    periphMemWrite(FCAN_RXIMR5_INIT, &pFCanBase->rximr5);
    #endif
    #ifdef FCAN_RXIMR6_INIT
    periphMemWrite(FCAN_RXIMR6_INIT, &pFCanBase->rximr6);
    #endif
    #ifdef FCAN_RXIMR7_INIT
    periphMemWrite(FCAN_RXIMR7_INIT, &pFCanBase->rximr7);
    #endif
    #ifdef FCAN_RXIMR8_INIT
    periphMemWrite(FCAN_RXIMR8_INIT, &pFCanBase->rximr8);
    #endif
    #ifdef FCAN_RXIMR9_INIT
    periphMemWrite(FCAN_RXIMR9_INIT, &pFCanBase->rximr9);
    #endif
    #ifdef FCAN_RXIMR10_INIT
    periphMemWrite(FCAN_RXIMR10_INIT, &pFCanBase->rximr10);
    #endif
    #ifdef FCAN_RXIMR11_INIT
    periphMemWrite(FCAN_RXIMR11_INIT, &pFCanBase->rximr11);
    #endif
    #ifdef FCAN_RXIMR12_INIT
    periphMemWrite(FCAN_RXIMR12_INIT, &pFCanBase->rximr12);
    #endif
    #ifdef FCAN_RXIMR13_INIT
    periphMemWrite(FCAN_RXIMR13_INIT, &pFCanBase->rximr13);
    #endif
    #ifdef FCAN_RXIMR14_INIT
    periphMemWrite(FCAN_RXIMR14_INIT, &pFCanBase->rximr14);
    #endif
    #ifdef FCAN_RXIMR15_INIT
    periphMemWrite(FCAN_RXIMR15_INIT, &pFCanBase->rximr15);
    #endif
        
    /* Apply the rest of user configuration to the MCR, this either disables the module, 
     * keeps the freeze mode or enables the FlexCAN operation. */
    #ifdef FCAN_MCR_INIT
    periphMemWrite(FCAN_MCR_INIT | FCAN_MCR_HALT | FCAN_MCR_FRZ, &pFCanBase->mcr);
    periphMemWrite(FCAN_MCR_INIT, &pFCanBase->mcr);
    
    /* if the user configuration defines the running state, wait until CAN gets ready */
    #if ((FCAN_MCR_INIT & (FCAN_MCR_MDIS | FCAN_MCR_HALT)) == 0)  
    while(!ioctl(pFCanBase, FCAN_TEST_READY, NULL))
       ; /* do nothing */
    #endif
    #endif
#endif    

    ; /* last else case */
}

/* ID->RAW calculation implemented as a function call */

#pragma interrupt called
UWord32 FCAN_Id2Idr_V(register UWord32 id)
{
    return FCAN_Id2Idr(id);
}

/* RAW->ID calculation implemented as a function call */

#pragma interrupt called
UWord32 FCAN_Idr2Id_V(register UWord32 idr, UWord16 bIsIDE)
{
    return FCAN_Idr2Id(idr, bIsIDE);
}

/* same as FCANMB_SET_ID but implemented as function (to be used when ID passed is a variable) */

#pragma interrupt called
void ioctlFCANMB_SET_ID_V(register arch_sFlexCAN_MB* pFCanMB, register UWord32 id)
{
    ioctl(pFCanMB, FCANMB_SET_ID, id);
}

/* Same as FCAN_SET_RXMGMASK but implemented as a function call; 32bit mask */

#pragma interrupt called
void ioctlFCAN_SET_RXMGMASK_V(register arch_sFlexCAN* pFCanBase, register UWord32 mask)
{
    ioctl(pFCanBase, FCAN_SET_RXMGMASK, mask);
}

/* Same as FCAN_SET_RX14MASK but implemented as a function call; 32bit mask */

#pragma interrupt called
void ioctlFCAN_SET_RX14MASK_V(register arch_sFlexCAN* pFCanBase, register UWord32 mask)
{
    ioctl(pFCanBase, FCAN_SET_RX14MASK, mask);
}

/* Same as FCAN_SET_RX15MASK but implemented as a function call; 32bit mask */

#pragma interrupt called
void ioctlFCAN_SET_RX15MASK_V(register arch_sFlexCAN* pFCanBase, register UWord32 mask)
{
    ioctl(pFCanBase, FCAN_SET_RX15MASK, mask);
}

/* swap data word endianness */

inline UWord16 bswap16(UWord16 n)
{
    return ((n & 0xff) << 8) | ((n >> 8) & 0xff); 
}

#pragma interrupt called
void ioctlFCANMB_REORDER_BYTES(register arch_sFlexCAN_MB* pFCanMB, void* dummy)
{
    UWord32 in, out; 
    
    in = pFCanMB->data[0];
    out = (((UWord32)bswap16((UWord16)in)) << 16) | bswap16((UWord16)(in >> 16));  
    pFCanMB->data[0] = out;

    in = pFCanMB->data[1];
    out = (((UWord32)bswap16((UWord16)in)) << 16) | bswap16((UWord16)(in >> 16));  
    pFCanMB->data[1] = out;
}

#pragma interrupt called
void ioctlFCANMB_REORDER_WORDS(register arch_sFlexCAN_MB* pFCanMB, void* dummy)
{
    UWord32 in, out; 
    
    in = pFCanMB->data[0];
    out = (in << 16) | (in >> 16);  
    pFCanMB->data[0] = out;

    in = pFCanMB->data[1];
    out = (in << 16) | (in >> 16);  
    pFCanMB->data[1] = out;
}

#ifdef __cplusplus
}
#endif

