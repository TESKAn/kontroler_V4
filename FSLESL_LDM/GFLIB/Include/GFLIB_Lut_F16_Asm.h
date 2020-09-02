/*******************************************************************************
*
* Copyright 2007-2015 Freescale Semiconductor, Inc.
*
* This software is owned or controlled by Freescale Semiconductor.
* Use of this software is governed by the Freescale License
* distributed with this Material.
* See the LICENSE file distributed for more details.
* 
*
****************************************************************************//*!
*
* @brief  Look-up table algorithm implemented in assembler 
* 
*******************************************************************************/
#ifndef _GFLIB_LUT_F16_ASM_H_
#define _GFLIB_LUT_F16_ASM_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib.h"

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/
#define GFLIB_Lut1D_F16_Asm(f16X, pf16Table, u16TableSize) GFLIB_Lut1D_F16_FAsm(f16X, pf16Table, u16TableSize)
#define GFLIB_Lut2D_F16_Asm(f16X, f16Y, psParam) GFLIB_Lut2D_F16_FAsm(f16X, f16Y, psParam)

/******************************************************************************
* Types
******************************************************************************/
typedef struct
{
	uint16_t  u16ShamOffset1;
	uint16_t  u16ShamOffset2;
	frac16_t *pf16Table;
} GFLIB_LUT2D_T_F16;

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/

extern asm frac16_t GFLIB_Lut1D_F16_FAsm(frac16_t f16X, const frac16_t *pf16Table, uint16_t u16TableSize);

extern asm frac16_t GFLIB_Lut2D_F16_FAsm(frac16_t f16X, frac16_t f16Y, const GFLIB_LUT2D_T_F16 *psParam);

/******************************************************************************
* Inline functions
******************************************************************************/
#if defined(__cplusplus) 
} 
#endif 

#endif /* _GFLIB_LUT_F16_ASM_H_ */
