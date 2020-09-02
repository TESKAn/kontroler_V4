/*
 * events.c
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

#include "events.h"

#pragma interrupt saveall
void ADC_1_ISR(void)
{
	// Clear EOSI flag
	ioctl(ADC_1, ADC_CLEAR_STATUS_EOSI, NULL);
	
	// Readout motor currents	
	//ioctl(ADC_1, ADC_READ_SAMPLE, 8);
	
	// Transform to DQ frame
	//GMCLIB_Park_F16(&SYSTEM.MCTRL.m2IAlphaBeta, &SYSTEM.POSITION.mSinCosAngle, &SYSTEM.MCTRL.m2IDQ);
	
	// Calculate regulation	
	//GFLIB_CtrlPIDpAWInit_F16(FRAC16(0.0), &SVASANJE.sPIDReg);
	
	// Calculate new sin/cos
	//SYSTEM.POSITION.mSinCosAngle.f16Sin = GFLIB_Sin_F16(SYSTEM.POSITION.f16RotorAngle);
	//SYSTEM.POSITION.mSinCosAngle.f16Cos = GFLIB_Cos_F16(SYSTEM.POSITION.f16RotorAngle);
	
	// Transform to AB frame
	//GMCLIB_ParkInv_F16(&SYSTEM.MCTRL.m2UDQ, &SYSTEM.POSITION.mSinCosAngle, &SYSTEM.MCTRL.m2UAlphaBeta);
	
	// Set PWMs
	//ioctl(EFPWMA_SUB0, EFPWMS_WRITE_VALUE_REG_2, -1250 - SVASANJE.w16OutVal);
	
	// Call freemaster recorder
	FMSTR_Recorder();
}

#pragma interrupt saveall
void PIT0_ISR(void)
{
	ioctl(PIT_0, PIT_CLEAR_ROLLOVER_INT, NULL);
}
