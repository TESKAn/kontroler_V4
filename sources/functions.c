/*
 * functions.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Jure
 */

/* required DSP56F800E_Quick_Start header */
#include "qs.h"

/* low-level driver headers for each module used */
#include "occs.h"
#include "sys.h"
#include "adc12.h"
#include "adc16.h"
#include "aoi.h"
#include "cop.h"
#include "crc.h"
#include "dac.h"
#include "dma.h"
#include "fcan.h"
#include "fmc.h"
#include "ftfl.h"
#include "gpio.h"
#include "hscmp.h"
#include "iic.h"
#include "intc.h"
#include "intctarget.h"
#include "mcm.h"
#include "pmc.h"
#include "pwm.h"
#include "pit.h"
#include "qtimer.h"
#include "sci.h"
#include "scihl.h"
#include "spi.h"
#include "xbar.h"
#include "pdb.h"
#include "freemaster.h"

#include "amclib.h"
#include "gdflib.h"
#include "gflib.h"
#include "gmclib.h"
#include "mlib.h"
#include "pclib.h"

#include "macro.h"
#include "var.h"
#include "functions.h"

Int16 InitVariables(Int8 i8Full)
{
	m2IAlphaBeta.f16Alpha = 0;
	m2IAlphaBeta.f16Beta = 0;
	
	m2IDQ.f16D = 0;
	m2IDQ.f16Q = 0;
	
	m2IDQReq.f16D = DEFAULT_MOTOR_IDLE_CURRENT;
	m2IDQReq.f16Q = 0;
	
	m2UDQ.f16D = 0;
	m2UDQ.f16Q = 0;
	
	m2UAlphaBeta.f16Alpha = 0;
	m2UAlphaBeta.f16Beta = 0;
	
	mSinCosAngle.f16Sin = GFLIB_Sin_F16(FRAC16(0.0));
	mSinCosAngle.f16Cos = GFLIB_Cos_F16(FRAC16(0.0));
	
	
	
	
	return 0;
}
