/*
 * events.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Jure
 */

#include "sysInclude.h"

#include "amclib.h"
#include "gdflib.h"
#include "gflib.h"
#include "gmclib.h"
#include "mlib.h"
#include "pclib.h"

#include "macro.h"
#include "events.h"
#include "var.h"

#pragma interrupt saveall
void ADC_1_ISR(void)
{
	Word16 w16Temp = 0;
	// Clear EOSI flag
	ioctl(ADC_1, ADC_CLEAR_STATUS_EOSI, NULL);
	
	// Readout motor currents	
	m2IAlphaBeta.f16Alpha = ioctl(ADC_1, ADC_READ_SAMPLE, 0);
	m2IAlphaBeta.f16Beta = ioctl(ADC_1, ADC_READ_SAMPLE, 8);
	
	// Transform to DQ frame
	GMCLIB_Park_F16(&m2IAlphaBeta, &mSinCosAngle, &m2IDQ);
	
	// Calculate regulation	
	m2IDQError.f16D = m2IDQReq.f16D - m2IDQ.f16D;
	m2UDQ.f16D = GFLIB_CtrlPIDpAW_F16(m2IDQError.f16D, m2IDQError.f16D, &bStopDIntegFlag, &mudtControllerParamId);
	
	m2IDQError.f16Q = m2IDQReq.f16Q - m2IDQ.f16Q;
	m2UDQ.f16Q = GFLIB_CtrlPIDpAW_F16(m2IDQError.f16Q, m2IDQError.f16Q, &bStopQIntegFlag, &mudtControllerParamIq);
	
	// Calculate new sin/cos
	mSinCosAngle.f16Sin = GFLIB_Sin_F16(f16CurrentMotorAngle);
	mSinCosAngle.f16Cos = GFLIB_Cos_F16(f16CurrentMotorAngle);
	
	// Transform to AB frame
	GMCLIB_ParkInv_F16(&m2UDQ, &mSinCosAngle, &m2UAlphaBeta);
	
	w16Temp = mult(PWM_MODULO, m2UAlphaBeta.f16Alpha);
	w16APWMValue = w16Temp >> 1;
	w16APWMNegValue = w16APWMValue - w16Temp;
	
	w16Temp = mult(PWM_MODULO, m2UAlphaBeta.f16Beta);
	w16BPWMValue = w16Temp >> 1;
	w16BPWMNegValue = w16BPWMValue - w16Temp;
	
	// Set PWMs
	ioctl(EFPWMA_SUB0, EFPWMS_WRITE_VALUE_REG_2, w16APWMValue);
	ioctl(EFPWMA_SUB0, EFPWMS_WRITE_VALUE_REG_3, -w16APWMValue);
	
	ioctl(EFPWMA_SUB1, EFPWMS_WRITE_VALUE_REG_2, w16APWMNegValue);
	ioctl(EFPWMA_SUB1, EFPWMS_WRITE_VALUE_REG_3, -w16APWMNegValue);

	ioctl(EFPWMA_SUB2, EFPWMS_WRITE_VALUE_REG_2, w16BPWMValue);
	ioctl(EFPWMA_SUB2, EFPWMS_WRITE_VALUE_REG_3, -w16BPWMValue);
	
	ioctl(EFPWMA_SUB3, EFPWMS_WRITE_VALUE_REG_2, w16BPWMNegValue);
	ioctl(EFPWMA_SUB3, EFPWMS_WRITE_VALUE_REG_3, -w16BPWMNegValue);
	// Call freemaster recorder
	FMSTR_Recorder();
}

#pragma interrupt saveall
void PIT0_ISR(void)
{
	ioctl(PIT_0, PIT_CLEAR_ROLLOVER_INT, NULL);
}
