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
* @brief  Multiply functions with 32-bit accumulator input in assembler
* 
*******************************************************************************/
#ifndef _MLIB_MUL_A32_ASM_H_
#define _MLIB_MUL_A32_ASM_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib_types.h"
#include "MLIB_Mul_A32_Asmi.h"

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/
#define MLIB_Mul_F16as_Asmi(a32Accum, f16Mult) MLIB_Mul_F16as_FAsmi(a32Accum, f16Mult)
#define MLIB_MulSat_F16as_Asmi(a32Accum, f16Mult) MLIB_MulSat_F16as_FAsmi(a32Accum, f16Mult)
#define MLIB_MulNeg_F16as_Asmi(a32Accum, f16Mult) MLIB_MulNeg_F16as_FAsmi(a32Accum, f16Mult)
#define MLIB_MulNegSat_F16as_Asmi(a32Accum, f16Mult) MLIB_MulNegSat_F16as_FAsmi(a32Accum, f16Mult)

#define MLIB_Mul_A32_Asmi(a32Mult1, a32Mult2) MLIB_Mul_A32_FAsmi(a32Mult1, a32Mult2)
#define MLIB_MulSat_A32_Asmi(a32Mult1, a32Mult2) MLIB_MulSat_A32_FAsmi(a32Mult1, a32Mult2)
#define MLIB_MulNeg_A32_Asmi(a32Mult1, a32Mult2) MLIB_MulNeg_A32_FAsmi(a32Mult1, a32Mult2)
#define MLIB_MulNegSat_A32_Asmi(a32Mult1, a32Mult2) MLIB_MulNegSat_A32_FAsmi(a32Mult1, a32Mult2)



/******************************************************************************
* Types
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/

/******************************************************************************
* Inline functions
******************************************************************************/
#if defined(__cplusplus) 
} 
#endif 

#endif /* _MLIB_MUL_A32_ASM_H_ */
