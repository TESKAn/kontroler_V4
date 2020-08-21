/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2007 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name: periph.h$
*
* $Date:      Mar-16-2015$
*
* $Version:   2.3.47.0$
*
* Description: Definition of quick_start "ioctl" macro and other macros for 
*              peripheral memory space access
*
*****************************************************************************/

#ifndef __PERIPH_H
#define __PERIPH_H

/*
*  Beginning in Quick_Start version 2.1, the qs.h master header file can 
*  be used to include all other Quick_Start system headers (core.h, types.h, 
*  arch.h, periph.h and appconfig.h) 
*
*  core.h is included here in case the old application is being compiled
*/
#ifndef __CORE_H
#include "core.h"
#endif

#ifndef __HAWKCPU_H
#include "hawkcpu.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************
* ioctl commands macro 
*******************************************************/
#define ioctl(fd,cmd,prm) ioctl##cmd((fd),(prm))

/*******************************************************
* read / write commands macro 
*******************************************************/
#define write(fd,mode,address,size) write_##fd##_##mode(address,size)
#define read(fd,mode,address,size)  read_##fd##_##mode(address,size)

/*******************************************************
* Routines for Peripheral Memory Access
********************************************************
*  Parameter usage:
*   addr - architecture structure field
*   mask - bit to manipulate
*   Data - 16 bit word to assign or access  
********************************************************/

/* set bits using the bfset instruction */
#define periphBitSet(mask, addr)   (*(addr) |= (mask))

/* clear bits using the bfclr instruction */
#define periphBitClear(mask, addr) (*(addr) &= ~(mask))

/* bit-group manipulation macros changed in v2.3, use this macro for compatibility mode */
#if PERIPH_V22_COMPAT

/* set group of bits using an accumulator */
#define periphBitGrpSet(grpmask, mask, addr) ( *(addr) = ( (*(addr) & ~(grpmask)) | (mask)) )

/* Clear controls bit in register with flags which are cleared-by-write-one */
#define periphSafeBitClear(allFlagsBitsGrp, bitsToClear, addr) ( *(addr) = ( *(addr) & ~((bitsToClear) | (allFlagsBitsGrp)) ) )

/* Set controls bit in register with flags which are cleared-by-write-one */
#define periphSafeBitSet(allFlagsBitsGrp, bitsToSet, addr) ( *(addr) = ( (*(addr) & ~(bitsToClear)) | (allFlagsBitsGrp) )

/* set group of bits using an accumulator and clear flags which are cleared-by-write-one */
#define periphSafeBitGrpSet(allFlagsBitsGrp,grpmask, mask, addr) ( *(addr) = ( (*(addr) & ~((grpmask) | (allFlagsBitsGrp))) | (mask)) )

/* set group of bits using two non-interruptible instructions (first set ones, then reset zeroes) */
#define periphBitGrpSR(grpmask, mask, addr) \
	( (*(addr) |= ((mask) & (grpmask))) , (*(addr) &= ~((~(mask)) & (grpmask))) )

/* set group of bits using two non-interruptible instructions (first reset zeroes, then set ones) */
#define periphBitGrpRS(grpmask, mask, addr) \
	( (*(addr) &= ~((~(mask)) & (grpmask))) , (*(addr) |= ((mask) & (grpmask))) )

/* set group of bits using two non-interruptible instructions (first zero all group, then set ones) */
#define periphBitGrpZS(grpmask, mask, addr) \
	( (*(addr) &= ~(grpmask)) , ( *(addr) |= ((mask) & (grpmask))) )

/* set group of bits using an accumulator, allows variable as parameter */
#define periphBitGrpSetVar(grpmask, mask, addr) periphBitGrpSet(grpmask, mask, addr)

/* set group of bits using two non-interruptible instructions (first set ones, then reset zeroes), allows variable as parameter */
#define periphBitGrpSRVar(grpmask, mask, addr) periphBitGrpSR(grpmask, mask, addr)

/* set group of bits using two non-interruptible instructions (first reset zeroes, then set ones), allows variable as parameter */
#define periphBitGrpRSVar(grpmask, mask, addr) periphBitGrpRS(grpmask, mask, addr)

/* set group of bits using two non-interruptible instructions (first zero whole group, then set ones), allows variable as parameter */
#define periphBitGrpZSVar(grpmask, mask, addr) periphBitGrpZS(grpmask, mask, addr)

/* set group of bits using an accumulator and clear flags which are cleared-by-write-one, allows variable as parameter */
#define periphSafeBitGrpSetVar(allFlagsBitsGrp, grpmask, mask, addr) periphSafeBitGrpSet(allFlagsBitsGrp, grpmask, mask, addr)

/* clear (acknowlege) bit flags which are active-high and are cleared-by-write-one, allows variable as parameter */
#define periphSafeAckByOneVar(allAckBitsGrp, bitsToAck, addr) periphSafeAckByOne(allAckBitsGrp, bitsToAck, addr)

/* Set controls bit in register with flags which are cleared-by-write-one, allows variable as parameter */
#define periphSafeBitSetVar(allFlagsBitsGrp, bitsToSet, addr) periphSafeBitSet(allFlagsBitsGrp, bitsToSet, addr)

#else /* PERIPH_V22_COMPAT */

/* bit-group manipulation macros using BFSC instruction */
#if defined (MC56F84xxx) || defined (MC56F82xxx)
#define hash #
/* set group of bits using BFSC instruction */
#define periphBitGrpSet(grpmask, mask, addr) \
  do{register volatile UWord16 *uw16BfscAddrTmp; uw16BfscAddrTmp = (UWord16 *)addr; \
   asm(bfsc hash grpmask, hash mask, X:(uw16BfscAddrTmp));}while(0)

/* set group of bits using BFSC instruction */
#define periphBitGrpSR(grpmask, mask, addr) \
  do{register volatile UWord16 *uw16BfscAddrTmp; uw16BfscAddrTmp = (UWord16 *)addr; \
   asm(bfsc hash grpmask, hash mask, X:(uw16BfscAddrTmp));}while(0)

/* set group of bits using BFSC instruction */
#define periphBitGrpRS(grpmask, mask, addr) \
  do{register volatile UWord16 *uw16BfscAddrTmp; uw16BfscAddrTmp = (UWord16 *)addr; \
   asm(bfsc hash grpmask, hash mask, X:(uw16BfscAddrTmp));}while(0)

/* set group of bits using BFSC instruction */
#define periphBitGrpZS(grpmask, mask, addr) \
  do{register volatile UWord16 *uw16BfscAddrTmp; uw16BfscAddrTmp = (UWord16 *)addr; \
   asm(bfsc hash grpmask, hash mask, X:(uw16BfscAddrTmp));}while(0)

/* clear (acknowlege) bit flags which are active-high and are cleared-by-write-one */
#define periphSafeBitGrpSet(allFlagsBitsGrp, grpmask, mask, addr) \
  do{register volatile UWord16 *uw16BfscAddrTmp; uw16BfscAddrTmp = (UWord16 *)addr; \
   asm(bfsc hash ((allFlagsBitsGrp) | (grpmask)), hash mask, X:(uw16BfscAddrTmp));}while(0)

/* clear (acknowlege) bit flags which are active-high and are cleared-by-write-one */
#define periphSafeAckByOne(allAckBitsGrp, bitsToAck, addr) \
  do{register volatile UWord16 *uw16BfscAddrTmp; uw16BfscAddrTmp = (UWord16 *)addr; \
   asm(bfsc hash allAckBitsGrp, hash bitsToAck, X:(uw16BfscAddrTmp));}while(0)

/* Set controls bit in register with flags which are cleared-by-write-one using BFSC instruction */
#define periphSafeBitSet(allFlagsBitsGrp, bitsToSet, addr) \
   do{register volatile UWord16 *uw16BfscAddrTmp; uw16BfscAddrTmp = (UWord16 *)addr; \
   asm(bfsc hash(allFlagsBitsGrp|bitsToSet), hash bitsToSet, X:(uw16BfscAddrTmp));}while(0)


/* Note: Alternative implementation of bit manipulation macros, 
         which accepts variable as parameter. This is not single 
         instruction implementation. */

/* set group of bits using an accumulator */
#define periphBitGrpSetVar(grpmask, mask, addr) do{ \
  register UWord16 __tmp = *(addr); \
  __tmp |= ((mask) & (grpmask)); \
  __tmp &= ~((~(mask)) & (grpmask)); \
  *(addr) = __tmp; \
  }while(0)

/* set group of bits using two non-interruptible instructions (first set ones, then reset zeroes) */
#define periphBitGrpSRVar(grpmask, mask, addr) \
  ( (*(UWord16*)(addr) |= ((mask) & (grpmask))) , (*(UWord16*)(addr) &= ~((~(mask)) & (grpmask))) )

/* set group of bits using two non-interruptible instructions (first reset zeroes, then set ones) */
#define periphBitGrpRSVar(grpmask, mask, addr) \
  ( (*(UWord16*)(addr) &= ~((~(mask)) & (grpmask))) , (*(UWord16*)(addr) |= ((mask) & (grpmask))) )

/* set group of bits using two non-interruptible instructions (first zero whole group, then set ones) */
#define periphBitGrpZSVar(grpmask, mask, addr) \
  ( (*(UWord16*)(addr) &= ~(grpmask)), ( *(UWord16*)(addr) |= ((mask) & (grpmask))) )

/* set group of bits using an accumulator and clear flags which are cleared-by-write-one */
#define periphSafeBitGrpSetVar(allFlagsBitsGrp, grpmask, mask, addr) do{ \
    register UWord16 __tmp = *(addr); \
    __tmp |= ( (mask) & ((allFlagsBitsGrp) | (grpmask)) ); \
    __tmp &= ~( (~(mask)) & ((allFlagsBitsGrp) | (grpmask)) ); \
    *(addr) = __tmp; \
    }while(0)

/* clear (acknowlege) bit flags which are active-high and are cleared-by-write-one */
#define periphSafeAckByOneVar(allAckBitsGrp, bitsToAck, addr) \
  ( ((~(bitsToAck)) & (allAckBitsGrp)) ? \
    (periphBitClear((~(bitsToAck)) & (allAckBitsGrp), addr)) : \
    (periphMemDummyReadWrite(addr),0) )

/* Set controls bit in register with flags which are cleared-by-write-one */
#define periphSafeBitSetVar(allFlagsBitsGrp, bitsToSet, addr) do{ \
    register UWord16 __tmp = *(addr); \
    __tmp |= ( bitsToSet ); \
    __tmp &= ~(allFlagsBitsGrp); \
    *(addr) = __tmp; \
}while(0)

#else /* bit-group manipulation macros not using BFSC instruction */

/* Note: begining in version 2.3, the bit-manipulation macros re-cast
   the target location to non-volatile, so the "void" instructions may
   be optimized-out from SR, RZ and ZS macros. Example of "void" are 
   bfset #0,X:(addr) or bfclr #0,X:(addr) which may be produced when 
   clearing or setting all bits in the bit-group */
                               
/* set group of bits using an accumulator */
#define periphBitGrpSet(grpmask, mask, addr) do{ \
  register UWord16 __tmp = *(addr); \
  __tmp |= ((mask) & (grpmask)); \
  __tmp &= ~((~(mask)) & (grpmask)); \
  *(addr) = __tmp; \
  }while(0)

/* set group of bits using two non-interruptible instructions (first set ones, then reset zeroes) */
#define periphBitGrpSR(grpmask, mask, addr) \
  ( (*(UWord16*)(addr) |= ((mask) & (grpmask))) , (*(UWord16*)(addr) &= ~((~(mask)) & (grpmask))) )

/* set group of bits using two non-interruptible instructions (first reset zeroes, then set ones) */
#define periphBitGrpRS(grpmask, mask, addr) \
  ( (*(UWord16*)(addr) &= ~((~(mask)) & (grpmask))) , (*(UWord16*)(addr) |= ((mask) & (grpmask))) )

/* set group of bits using two non-interruptible instructions (first zero whole group, then set ones) */
#define periphBitGrpZS(grpmask, mask, addr) \
  ( (*(UWord16*)(addr) &= ~(grpmask)), ( *(UWord16*)(addr) |= ((mask) & (grpmask))) )

/* set group of bits using an accumulator and clear flags which are cleared-by-write-one */
#define periphSafeBitGrpSet(allFlagsBitsGrp, grpmask, mask, addr) do{ \
    register UWord16 __tmp = *(addr); \
    __tmp |= ( (mask) & ((allFlagsBitsGrp) | (grpmask)) ); \
    __tmp &= ~( (~(mask)) & ((allFlagsBitsGrp) | (grpmask)) ); \
    *(addr) = __tmp; \
    }while(0)

/* clear (acknowlege) bit flags which are active-high and are cleared-by-write-one */
#define periphSafeAckByOne(allAckBitsGrp, bitsToAck, addr) \
  ( ((~(bitsToAck)) & (allAckBitsGrp)) ? \
    (periphBitClear((~(bitsToAck)) & (allAckBitsGrp), addr)) : \
    (periphMemDummyReadWrite(addr),0) )

/* Set controls bit in register with flags which are cleared-by-write-one */
#define periphSafeBitSet(allFlagsBitsGrp, bitsToSet, addr) do{ \
    register UWord16 __tmp = *(addr); \
    __tmp |= ( bitsToSet ); \
    __tmp &= ~(allFlagsBitsGrp); \
    *(addr) = __tmp; \
}while(0)

/* set group of bits using an accumulator, allows variable as parameter */
#define periphBitGrpSetVar(grpmask, mask, addr) periphBitGrpSet(grpmask, mask, addr)

/* set group of bits using two non-interruptible instructions (first set ones, then reset zeroes), allows variable as parameter */
#define periphBitGrpSRVar(grpmask, mask, addr) periphBitGrpSR(grpmask, mask, addr)

/* set group of bits using two non-interruptible instructions (first reset zeroes, then set ones), allows variable as parameter */
#define periphBitGrpRSVar(grpmask, mask, addr) periphBitGrpRS(grpmask, mask, addr)

/* set group of bits using two non-interruptible instructions (first zero whole group, then set ones), allows variable as parameter */
#define periphBitGrpZSVar(grpmask, mask, addr) periphBitGrpZS(grpmask, mask, addr)

/* set group of bits using an accumulator and clear flags which are cleared-by-write-one, allows variable as parameter */
#define periphSafeBitGrpSetVar(allFlagsBitsGrp, grpmask, mask, addr) periphSafeBitGrpSet(allFlagsBitsGrp, grpmask, mask, addr)

/* clear (acknowlege) bit flags which are active-high and are cleared-by-write-one, allows variable as parameter */
#define periphSafeAckByOneVar(allAckBitsGrp, bitsToAck, addr) periphSafeAckByOne(allAckBitsGrp, bitsToAck, addr)

/* Set controls bit in register with flags which are cleared-by-write-one, allows variable as parameter */
#define periphSafeBitSetVar(allFlagsBitsGrp, bitsToSet, addr) periphSafeBitSet(allFlagsBitsGrp, bitsToSet, addr)

#endif /* bit-group manipulation macros using not BFSC instruction end */ 

/* special instruction for 32 bit operation */
#define periphBitGrpSet32(grpmask, mask, addr) { \
    register UWord32 __tmp = *(addr); \
    __tmp |= ((mask) & (grpmask)); \
    __tmp &= ~((~(mask)) & (grpmask)); \
    *(addr) = __tmp; \
    }

/* set group of bits using two non-interruptible instructions for 32bit (first reset zeroes, then set ones) */
#define periphBitGrpRS32(grpmask, mask, addr) \
    ( (*(UWord32*)(addr) &= ~((UWord32)(~((UWord32)mask)) & ((UWord32)grpmask))) , (*(UWord32*)(addr) |= ((UWord32)((UWord32)mask) & ((UWord32)grpmask))) )

/* Clear controls bit in register with flags which are cleared-by-write-one */
#define periphSafeBitClear(allFlagsBitsGrp, bitsToClear, addr) \
	( 	periphBitClear( (allFlagsBitsGrp) | (bitsToClear), addr)  )

/* Set controls bit in register with flags which are cleared-by-write-one  for 32 register*/
#define periphSafeBitSet32(allFlagsBitsGrp, bitsToSet, addr) { \
    register UWord32 __tmp = *(addr); \
    __tmp |= ( bitsToSet ); \
    __tmp &= ~(allFlagsBitsGrp); \
    *(addr) = __tmp; \
    }

/* special instruction for 32 bit operation */
#define periphSafeBitGrpSet32(allFlagsBitsGrp,grpmask, mask, addr) { \
    register UWord32 __tmp = *(addr); \
    __tmp |= ( (mask) & ((allFlagsBitsGrp) | (grpmask)) ); \
    __tmp &= ~( (~(mask)) & ((allFlagsBitsGrp) | (grpmask)) ); \
    *(addr) = __tmp; \
    }

#endif /* PERIPH_V22_COMPAT */

/* toggle bits using a bfchg instruction */
#define periphBitChange(mask, addr)     (*(addr) ^= (mask))

/* filter bits */
#define periphBitTest(mask, addr)       (*(addr) & (mask))

/* void periphMemInvBitSet(UWord16 mask, volatile UWord16 * addr); */
#define periphMemInvBitSet(mask, addr)   (*(addr) = (mask) | ~(*(addr)))

/* read peripheral memory space */
#define periphMemRead(addr) (*(addr))

/* write peripheral memory space */
#define periphMemWrite(data, addr) (*(addr) = (data))

/* a direct address is read and then overwritten with the value read */
inline void periphMemDummyReadWrite(register volatile UWord16* addr) 
{
	asm ( bfset #0, X:(addr) );
}

/* a direct address read, result is thrown away */
inline void periphMemDummyRead(register volatile UWord16* addr)
{
	register UWord16 reg;
	asm { move.w X:(addr),reg }
}

/* a direct address read, result is thrown away */
inline void periphMemDummyRead32(register volatile UWord32* addr)
{
	register UWord32 reg;
	asm { move.l X:(addr),reg }
}

/* a direct address read, never optimized out (even if result is not used) */
inline UWord16 periphMemForcedRead(register volatile UWord16* addr)
{
	register UWord16 reg;
	asm { move.w X:(addr),reg }
	return reg;
}

#ifdef __cplusplus
}
#endif

#endif

