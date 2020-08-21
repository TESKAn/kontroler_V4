/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name: adc_8xxx.c$
*
* $Date:      Dec-4-2012$
*
* $Version:   2.5.26.0$
*
* Description: Source file for the ADC Driver
*
*****************************************************************************/

#include "qs.h"
#ifdef MC56F84xxx
#include "adc12.h"
#else
#include "adc.h"
#endif
#include "initconfig.h"

#ifdef __cplusplus
extern "C" {
#endif

/* initialization of ADC A or B module */

void adcInit(arch_sADC *pAdcBase)
{
#pragma unused(pAdcBase)

#if ADC_A_INIT_USED && defined(ADC_A)
	if (pAdcBase==ADC_A)
	{
		/* init of ADC A module */
		#ifdef ADC_A_ADLST1_INIT
		periphMemWrite(ADC_A_ADLST1_INIT, &pAdcBase->adlst1);
		#endif
		#ifdef ADC_A_ADLST2_INIT
		periphMemWrite(ADC_A_ADLST2_INIT, &pAdcBase->adlst2);
		#endif
		#ifdef ADC_A_ADLST3_INIT
		periphMemWrite(ADC_A_ADLST3_INIT, &pAdcBase->adlst3);
		#endif
		#ifdef ADC_A_ADLST4_INIT
		periphMemWrite(ADC_A_ADLST4_INIT, &pAdcBase->adlst4);
		#endif
		#ifdef ADC_A_ADSDIS_INIT
		periphMemWrite(ADC_A_ADSDIS_INIT, &pAdcBase->adsdis);
		#endif

		/* low limit registers */
		#ifdef ADC_A_ADLLMT0_INIT
		periphMemWrite(ADC_A_ADLLMT0_INIT, &pAdcBase->adllmt[0]);
		#endif
		#ifdef ADC_A_ADLLMT1_INIT
		periphMemWrite(ADC_A_ADLLMT1_INIT, &pAdcBase->adllmt[1]);
		#endif
		#ifdef ADC_A_ADLLMT2_INIT
		periphMemWrite(ADC_A_ADLLMT2_INIT, &pAdcBase->adllmt[2]);
		#endif
		#ifdef ADC_A_ADLLMT3_INIT
		periphMemWrite(ADC_A_ADLLMT3_INIT, &pAdcBase->adllmt[3]);
		#endif
		#ifdef ADC_A_ADLLMT4_INIT
		periphMemWrite(ADC_A_ADLLMT4_INIT, &pAdcBase->adllmt[4]);
		#endif
		#ifdef ADC_A_ADLLMT5_INIT
		periphMemWrite(ADC_A_ADLLMT5_INIT, &pAdcBase->adllmt[5]);
		#endif
		#ifdef ADC_A_ADLLMT6_INIT
		periphMemWrite(ADC_A_ADLLMT6_INIT, &pAdcBase->adllmt[6]);
		#endif
		#ifdef ADC_A_ADLLMT7_INIT
		periphMemWrite(ADC_A_ADLLMT7_INIT, &pAdcBase->adllmt[7]);
		#endif
		
		/* high limit registers */
		#ifdef ADC_A_ADHLMT0_INIT
		periphMemWrite(ADC_A_ADHLMT0_INIT, &pAdcBase->adhlmt[0]);
		#endif
		#ifdef ADC_A_ADHLMT1_INIT
		periphMemWrite(ADC_A_ADHLMT1_INIT, &pAdcBase->adhlmt[1]);
		#endif
		#ifdef ADC_A_ADHLMT2_INIT
		periphMemWrite(ADC_A_ADHLMT2_INIT, &pAdcBase->adhlmt[2]);
		#endif
		#ifdef ADC_A_ADHLMT3_INIT
		periphMemWrite(ADC_A_ADHLMT3_INIT, &pAdcBase->adhlmt[3]);
		#endif
		#ifdef ADC_A_ADHLMT4_INIT
		periphMemWrite(ADC_A_ADHLMT4_INIT, &pAdcBase->adhlmt[4]);
		#endif
		#ifdef ADC_A_ADHLMT5_INIT
		periphMemWrite(ADC_A_ADHLMT5_INIT, &pAdcBase->adhlmt[5]);
		#endif
		#ifdef ADC_A_ADHLMT6_INIT
		periphMemWrite(ADC_A_ADHLMT6_INIT, &pAdcBase->adhlmt[6]);
		#endif
		#ifdef ADC_A_ADHLMT7_INIT
		periphMemWrite(ADC_A_ADHLMT7_INIT, &pAdcBase->adhlmt[7]);
		#endif
		
		/* offset registers */
		#ifdef ADC_A_ADOFS0_INIT
		periphMemWrite(ADC_A_ADOFS0_INIT, &pAdcBase->adofs[0]);
		#endif
		#ifdef ADC_A_ADOFS1_INIT
		periphMemWrite(ADC_A_ADOFS1_INIT, &pAdcBase->adofs[1]);
		#endif
		#ifdef ADC_A_ADOFS2_INIT
		periphMemWrite(ADC_A_ADOFS2_INIT, &pAdcBase->adofs[2]);
		#endif
		#ifdef ADC_A_ADOFS3_INIT
		periphMemWrite(ADC_A_ADOFS3_INIT, &pAdcBase->adofs[3]);
		#endif 
		#ifdef ADC_A_ADOFS4_INIT
		periphMemWrite(ADC_A_ADOFS4_INIT, &pAdcBase->adofs[4]);
		#endif	
		#ifdef ADC_A_ADOFS5_INIT
		periphMemWrite(ADC_A_ADOFS5_INIT, &pAdcBase->adofs[5]);
		#endif
		#ifdef ADC_A_ADOFS6_INIT
		periphMemWrite(ADC_A_ADOFS6_INIT, &pAdcBase->adofs[6]);
		#endif
		#ifdef ADC_A_ADOFS7_INIT
		periphMemWrite(ADC_A_ADOFS7_INIT, &pAdcBase->adofs[7]);
		#endif

		/* control registers, initialized last */
		#ifdef ADC_A_ADCCAL_INIT
		periphMemWrite(ADC_A_ADCCAL_INIT, &pAdcBase->adc_cal);
		#endif		
		#ifdef ADC_A_ADZCC_INIT
		periphMemWrite(ADC_A_ADZCC_INIT, &pAdcBase->adzcc);
		#endif
		#ifdef ADC_A_ADCR2_INIT
		periphMemWrite(ADC_A_ADCR2_INIT, &pAdcBase->adctl2);
		#endif
		#ifdef ADC_A_ADCR1_INIT
		periphMemWrite(ADC_A_ADCR1_INIT, &pAdcBase->adctl1);
		#endif
		#ifdef ADC_A_ADCPOWER_INIT
		periphMemWrite(ADC_A_ADCPOWER_INIT, &pAdcBase->adcpower);
		#endif
	}
	else
#endif

#if ADC_B_INIT_USED && defined(ADC_B)
	if (pAdcBase==ADC_B)
	{
		/* init of ADC A module */
		#ifdef ADC_B_ADLST1_INIT
		periphMemWrite(ADC_B_ADLST1_INIT, &pAdcBase->adlst1);
		#endif
		#ifdef ADC_B_ADLST2_INIT
		periphMemWrite(ADC_B_ADLST2_INIT, &pAdcBase->adlst2);
		#endif
		#ifdef ADC_B_ADLST3_INIT
		periphMemWrite(ADC_B_ADLST3_INIT, &pAdcBase->adlst3);
		#endif
		#ifdef ADC_B_ADLST4_INIT
		periphMemWrite(ADC_B_ADLST4_INIT, &pAdcBase->adlst4);
		#endif
		#ifdef ADC_B_ADSDIS_INIT
		periphMemWrite(ADC_B_ADSDIS_INIT, &pAdcBase->adsdis);
		#endif

		/* low limit registers */
		#ifdef ADC_B_ADLLMT0_INIT
		periphMemWrite(ADC_B_ADLLMT0_INIT, &pAdcBase->adllmt[0]);
		#endif
		#ifdef ADC_B_ADLLMT1_INIT
		periphMemWrite(ADC_B_ADLLMT1_INIT, &pAdcBase->adllmt[1]);
		#endif
		#ifdef ADC_B_ADLLMT2_INIT
		periphMemWrite(ADC_B_ADLLMT2_INIT, &pAdcBase->adllmt[2]);
		#endif
		#ifdef ADC_B_ADLLMT3_INIT
		periphMemWrite(ADC_B_ADLLMT3_INIT, &pAdcBase->adllmt[3]);
		#endif
		#ifdef ADC_B_ADLLMT4_INIT
		periphMemWrite(ADC_B_ADLLMT4_INIT, &pAdcBase->adllmt[4]);
		#endif
		#ifdef ADC_B_ADLLMT5_INIT
		periphMemWrite(ADC_B_ADLLMT5_INIT, &pAdcBase->adllmt[5]);
		#endif
		#ifdef ADC_B_ADLLMT6_INIT
		periphMemWrite(ADC_B_ADLLMT6_INIT, &pAdcBase->adllmt[6]);
		#endif
		#ifdef ADC_B_ADLLMT7_INIT
		periphMemWrite(ADC_B_ADLLMT7_INIT, &pAdcBase->adllmt[7]);
		#endif
		
		/* high limit registers */
		#ifdef ADC_B_ADHLMT0_INIT
		periphMemWrite(ADC_B_ADHLMT0_INIT, &pAdcBase->adhlmt[0]);
		#endif
		#ifdef ADC_B_ADHLMT1_INIT
		periphMemWrite(ADC_B_ADHLMT1_INIT, &pAdcBase->adhlmt[1]);
		#endif
		#ifdef ADC_B_ADHLMT2_INIT
		periphMemWrite(ADC_B_ADHLMT2_INIT, &pAdcBase->adhlmt[2]);
		#endif
		#ifdef ADC_B_ADHLMT3_INIT
		periphMemWrite(ADC_B_ADHLMT3_INIT, &pAdcBase->adhlmt[3]);
		#endif
		#ifdef ADC_B_ADHLMT4_INIT
		periphMemWrite(ADC_B_ADHLMT4_INIT, &pAdcBase->adhlmt[4]);
		#endif
		#ifdef ADC_B_ADHLMT5_INIT
		periphMemWrite(ADC_B_ADHLMT5_INIT, &pAdcBase->adhlmt[5]);
		#endif
		#ifdef ADC_B_ADHLMT6_INIT
		periphMemWrite(ADC_B_ADHLMT6_INIT, &pAdcBase->adhlmt[6]);
		#endif
		#ifdef ADC_B_ADHLMT7_INIT
		periphMemWrite(ADC_B_ADHLMT7_INIT, &pAdcBase->adhlmt[7]);
		#endif
		
		/* offset registers */
		#ifdef ADC_B_ADOFS0_INIT
		periphMemWrite(ADC_B_ADOFS0_INIT, &pAdcBase->adofs[0]);
		#endif
		#ifdef ADC_B_ADOFS1_INIT
		periphMemWrite(ADC_B_ADOFS1_INIT, &pAdcBase->adofs[1]);
		#endif
		#ifdef ADC_B_ADOFS2_INIT
		periphMemWrite(ADC_B_ADOFS2_INIT, &pAdcBase->adofs[2]);
		#endif
		#ifdef ADC_B_ADOFS3_INIT
		periphMemWrite(ADC_B_ADOFS3_INIT, &pAdcBase->adofs[3]);
		#endif 
		#ifdef ADC_B_ADOFS4_INIT
		periphMemWrite(ADC_B_ADOFS4_INIT, &pAdcBase->adofs[4]);
		#endif	
		#ifdef ADC_B_ADOFS5_INIT
		periphMemWrite(ADC_B_ADOFS5_INIT, &pAdcBase->adofs[5]);
		#endif
		#ifdef ADC_B_ADOFS6_INIT
		periphMemWrite(ADC_B_ADOFS6_INIT, &pAdcBase->adofs[6]);
		#endif
		#ifdef ADC_B_ADOFS7_INIT
		periphMemWrite(ADC_B_ADOFS7_INIT, &pAdcBase->adofs[7]);
		#endif

		/* control registers, initialized last */
		#ifdef ADC_B_ADCCAL_INIT
		periphMemWrite(ADC_B_ADCCAL_INIT, &pAdcBase->adc_cal);
		#endif		
		#ifdef ADC_B_ADZCC_INIT
		periphMemWrite(ADC_B_ADZCC_INIT, &pAdcBase->adzcc);
		#endif
		#ifdef ADC_B_ADCR2_INIT
		periphMemWrite(ADC_B_ADCR2_INIT, &pAdcBase->adctl2);
		#endif
		#ifdef ADC_B_ADCR1_INIT
		periphMemWrite(ADC_B_ADCR1_INIT, &pAdcBase->adctl1);
		#endif
		#ifdef ADC_B_ADCPOWER_INIT
		periphMemWrite(ADC_B_ADCPOWER_INIT, &pAdcBase->adcpower);
		#endif
	}
	else
#endif

#if ADC_INIT_USED && defined(ADC)
	if (pAdcBase==ADC)
	{
		/* init of ADC A module */
		#ifdef ADC_ADLST1_INIT
		periphMemWrite(ADC_ADLST1_INIT, &pAdcBase->adlst1);
		#endif
		#ifdef ADC_ADLST2_INIT
		periphMemWrite(ADC_ADLST2_INIT, &pAdcBase->adlst2);
		#endif
		#ifdef ADC_ADLST3_INIT
		periphMemWrite(ADC_ADLST3_INIT, &pAdcBase->adlst3);
		#endif
		#ifdef ADC_ADLST4_INIT
		periphMemWrite(ADC_ADLST4_INIT, &pAdcBase->adlst4);
		#endif
		#ifdef ADC_ADSDIS_INIT
		periphMemWrite(ADC_ADSDIS_INIT, &pAdcBase->adsdis);
		#endif

		/* gain and power settings */
	#if ADC_VERSION >= 5
		#ifdef ADC_ADCGC1_INIT
		periphMemWrite(ADC_ADCGC1_INIT, &pAdcBase->adc_gc1);
		#endif

		#ifdef ADC_ADCGC2_INIT
		periphMemWrite(ADC_ADCGC2_INIT, &pAdcBase->adc_gc2);
		#endif

		#ifdef ADC_ADCSCTRL_INIT
		periphMemWrite(ADC_ADCSCTRL_INIT, &pAdcBase->adc_sctrl);
		#endif

		#ifdef ADC_ADCPWR2_INIT
		periphMemWrite(ADC_ADCPWR2_INIT, &pAdcBase->adc_pwr2);
		#endif
	#endif
	#if ADC_VERSION >= 6
		#ifdef ADC_SCHLTEN_INIT
		periphMemWrite(ADC_SCHLTEN_INIT, &pAdcBase->adc_schlten);
		#endif
	#endif

		/* low limit registers */
		#ifdef ADC_ADLLMT0_INIT
		periphMemWrite(ADC_ADLLMT0_INIT, &pAdcBase->adllmt[0]);
		#endif
		#ifdef ADC_ADLLMT1_INIT
		periphMemWrite(ADC_ADLLMT1_INIT, &pAdcBase->adllmt[1]);
		#endif
		#ifdef ADC_ADLLMT2_INIT
		periphMemWrite(ADC_ADLLMT2_INIT, &pAdcBase->adllmt[2]);
		#endif
		#ifdef ADC_ADLLMT3_INIT
		periphMemWrite(ADC_ADLLMT3_INIT, &pAdcBase->adllmt[3]);
		#endif
		#ifdef ADC_ADLLMT4_INIT
		periphMemWrite(ADC_ADLLMT4_INIT, &pAdcBase->adllmt[4]);
		#endif
		#ifdef ADC_ADLLMT5_INIT
		periphMemWrite(ADC_ADLLMT5_INIT, &pAdcBase->adllmt[5]);
		#endif
		#ifdef ADC_ADLLMT6_INIT
		periphMemWrite(ADC_ADLLMT6_INIT, &pAdcBase->adllmt[6]);
		#endif
		#ifdef ADC_ADLLMT7_INIT
		periphMemWrite(ADC_ADLLMT7_INIT, &pAdcBase->adllmt[7]);
		#endif
	#if ADC_VERSION >= 6
		#ifdef ADC_ADLLMT8_INIT
		periphMemWrite(ADC_ADLLMT8_INIT, &pAdcBase->adllmt[8]);
		#endif
		#ifdef ADC_ADLLMT9_INIT
		periphMemWrite(ADC_ADLLMT9_INIT, &pAdcBase->adllmt[9]);
		#endif
		#ifdef ADC_ADLLMT10_INIT
		periphMemWrite(ADC_ADLLMT10_INIT, &pAdcBase->adllmt[10]);
		#endif
		#ifdef ADC_ADLLMT11_INIT
		periphMemWrite(ADC_ADLLMT11_INIT, &pAdcBase->adllmt[11]);
		#endif
		#ifdef ADC_ADLLMT12_INIT
		periphMemWrite(ADC_ADLLMT12_INIT, &pAdcBase->adllmt[12]);
		#endif
		#ifdef ADC_ADLLMT13_INIT
		periphMemWrite(ADC_ADLLMT13_INIT, &pAdcBase->adllmt[13]);
		#endif
		#ifdef ADC_ADLLMT14_INIT
		periphMemWrite(ADC_ADLLMT14_INIT, &pAdcBase->adllmt[14]);
		#endif
		#ifdef ADC_ADLLMT15_INIT
		periphMemWrite(ADC_ADLLMT15_INIT, &pAdcBase->adllmt[15]);
		#endif
	#endif
		
		/* high limit registers */
		#ifdef ADC_ADHLMT0_INIT
		periphMemWrite(ADC_ADHLMT0_INIT, &pAdcBase->adhlmt[0]);
		#endif
		#ifdef ADC_ADHLMT1_INIT
		periphMemWrite(ADC_ADHLMT1_INIT, &pAdcBase->adhlmt[1]);
		#endif
		#ifdef ADC_ADHLMT2_INIT
		periphMemWrite(ADC_ADHLMT2_INIT, &pAdcBase->adhlmt[2]);
		#endif
		#ifdef ADC_ADHLMT3_INIT
		periphMemWrite(ADC_ADHLMT3_INIT, &pAdcBase->adhlmt[3]);
		#endif
		#ifdef ADC_ADHLMT4_INIT
		periphMemWrite(ADC_ADHLMT4_INIT, &pAdcBase->adhlmt[4]);
		#endif
		#ifdef ADC_ADHLMT5_INIT
		periphMemWrite(ADC_ADHLMT5_INIT, &pAdcBase->adhlmt[5]);
		#endif
		#ifdef ADC_ADHLMT6_INIT
		periphMemWrite(ADC_ADHLMT6_INIT, &pAdcBase->adhlmt[6]);
		#endif
		#ifdef ADC_ADHLMT7_INIT
		periphMemWrite(ADC_ADHLMT7_INIT, &pAdcBase->adhlmt[7]);
		#endif
	#if ADC_VERSION >= 6
		#ifdef ADC_ADHLMT8_INIT
		periphMemWrite(ADC_ADHLMT8_INIT, &pAdcBase->adllmt[8]);
		#endif
		#ifdef ADC_ADHLMT9_INIT
		periphMemWrite(ADC_ADHLMT9_INIT, &pAdcBase->adllmt[9]);
		#endif
		#ifdef ADC_ADHLMT10_INIT
		periphMemWrite(ADC_ADHLMT10_INIT, &pAdcBase->adllmt[10]);
		#endif
		#ifdef ADC_ADHLMT11_INIT
		periphMemWrite(ADC_ADHLMT11_INIT, &pAdcBase->adllmt[11]);
		#endif
		#ifdef ADC_ADHLMT12_INIT
		periphMemWrite(ADC_ADHLMT12_INIT, &pAdcBase->adllmt[12]);
		#endif
		#ifdef ADC_ADHLMT13_INIT
		periphMemWrite(ADC_ADHLMT13_INIT, &pAdcBase->adllmt[13]);
		#endif
		#ifdef ADC_ADHLMT14_INIT
		periphMemWrite(ADC_ADHLMT14_INIT, &pAdcBase->adllmt[14]);
		#endif
		#ifdef ADC_ADHLMT15_INIT
		periphMemWrite(ADC_ADHLMT15_INIT, &pAdcBase->adllmt[15]);
		#endif
	#endif
		
		/* offset registers */
		#ifdef ADC_ADOFS0_INIT
		periphMemWrite(ADC_ADOFS0_INIT, &pAdcBase->adofs[0]);
		#endif
		#ifdef ADC_ADOFS1_INIT
		periphMemWrite(ADC_ADOFS1_INIT, &pAdcBase->adofs[1]);
		#endif
		#ifdef ADC_ADOFS2_INIT
		periphMemWrite(ADC_ADOFS2_INIT, &pAdcBase->adofs[2]);
		#endif
		#ifdef ADC_ADOFS3_INIT
		periphMemWrite(ADC_ADOFS3_INIT, &pAdcBase->adofs[3]);
		#endif 
		#ifdef ADC_ADOFS4_INIT
		periphMemWrite(ADC_ADOFS4_INIT, &pAdcBase->adofs[4]);
		#endif	
		#ifdef ADC_ADOFS5_INIT
		periphMemWrite(ADC_ADOFS5_INIT, &pAdcBase->adofs[5]);
		#endif
		#ifdef ADC_ADOFS6_INIT
		periphMemWrite(ADC_ADOFS6_INIT, &pAdcBase->adofs[6]);
		#endif
		#ifdef ADC_ADOFS7_INIT
		periphMemWrite(ADC_ADOFS7_INIT, &pAdcBase->adofs[7]);
		#endif
	#if ADC_VERSION >= 6
		#ifdef ADC_ADOFS8_INIT
		periphMemWrite(ADC_ADOFS8_INIT, &pAdcBase->adofs[8]);
		#endif
		#ifdef ADC_ADOFS9_INIT
		periphMemWrite(ADC_ADOFS9_INIT, &pAdcBase->adofs[9]);
		#endif
		#ifdef ADC_ADOFS10_INIT
		periphMemWrite(ADC_ADOFS10_INIT, &pAdcBase->adofs[10]);
		#endif
		#ifdef ADC_ADOFS11_INIT
		periphMemWrite(ADC_ADOFS11_INIT, &pAdcBase->adofs[11]);
		#endif 
		#ifdef ADC_ADOFS12_INIT
		periphMemWrite(ADC_ADOFS12_INIT, &pAdcBase->adofs[12]);
		#endif	
		#ifdef ADC_ADOFS13_INIT
		periphMemWrite(ADC_ADOFS13_INIT, &pAdcBase->adofs[13]);
		#endif
		#ifdef ADC_ADOFS14_INIT
		periphMemWrite(ADC_ADOFS14_INIT, &pAdcBase->adofs[14]);
		#endif
		#ifdef ADC_ADOFS15_INIT
		periphMemWrite(ADC_ADOFS15_INIT, &pAdcBase->adofs[15]);
		#endif
	#endif
		
		/* control registers, initialized last */
		#ifdef ADC_ADCCAL_INIT
		periphMemWrite(ADC_ADCCAL_INIT, &pAdcBase->adc_cal);
		#endif
	#if ADC_VERSION <= 5
		#ifdef ADC_ADZCC_INIT
		periphMemWrite(ADC_ADZCC_INIT, &pAdcBase->adzcc);
		#endif
	#else
		#ifdef ADC_ZXCTRL1_INIT
		periphMemWrite(ADC_ZXCTRL1_INIT, &pAdcBase->zxctrl1);
		#endif
		#ifdef ADC_ZXCTRL2_INIT
		periphMemWrite(ADC_ZXCTRL2_INIT, &pAdcBase->zxctrl2);
		#endif
	#endif
		#ifdef ADC_ADCR3_INIT
		periphMemWrite(ADC_ADCR3_INIT, &pAdcBase->adctl3);	//LP Position?
		#endif
		#ifdef ADC_ADCR2_INIT
		periphMemWrite(ADC_ADCR2_INIT, &pAdcBase->adctl2);
		#endif
		#ifdef ADC_ADCR1_INIT
		periphMemWrite(ADC_ADCR1_INIT, &pAdcBase->adctl1);
		#endif
		#ifdef ADC_ADCPOWER_INIT
		periphMemWrite(ADC_ADCPOWER_INIT, &pAdcBase->adcpower);
		#endif
	}
	else
#endif

#if ADC_1_INIT_USED && defined(ADC_1)
	if (pAdcBase==ADC_1)
	{
		/* init of ADC A module */
		#ifdef ADC_1_ADLST1_INIT
		periphMemWrite(ADC_1_ADLST1_INIT, &pAdcBase->adlst1);
		#endif
		#ifdef ADC_1_ADLST2_INIT
		periphMemWrite(ADC_1_ADLST2_INIT, &pAdcBase->adlst2);
		#endif
		#ifdef ADC_1_ADLST3_INIT
		periphMemWrite(ADC_1_ADLST3_INIT, &pAdcBase->adlst3);
		#endif
		#ifdef ADC_1_ADLST4_INIT
		periphMemWrite(ADC_1_ADLST4_INIT, &pAdcBase->adlst4);
		#endif
		#ifdef ADC_1_ADSDIS_INIT
		periphMemWrite(ADC_1_ADSDIS_INIT, &pAdcBase->adsdis);
		#endif

		/* gain and power settings */
	#if ADC_VERSION >= 5
		#ifdef ADC_1_ADCGC1_INIT
		periphMemWrite(ADC_1_ADCGC1_INIT, &pAdcBase->adc_gc1);
		#endif

		#ifdef ADC_1_ADCGC2_INIT
		periphMemWrite(ADC_1_ADCGC2_INIT, &pAdcBase->adc_gc2);
		#endif

		#ifdef ADC_1_ADCSCTRL_INIT
		periphMemWrite(ADC_1_ADCSCTRL_INIT, &pAdcBase->adc_sctrl);
		#endif

		#ifdef ADC_1_ADCPWR2_INIT
		periphMemWrite(ADC_1_ADCPWR2_INIT, &pAdcBase->adc_pwr2);
		#endif
	#endif
	#if ADC_VERSION >= 6
		#ifdef ADC_1_SCHLTEN_INIT
		periphMemWrite(ADC_1_SCHLTEN_INIT, &pAdcBase->adc_schlten);	//LP Position?
		#endif
	#endif	

		/* low limit registers */
		#ifdef ADC_1_ADLLMT0_INIT
		periphMemWrite(ADC_1_ADLLMT0_INIT, &pAdcBase->adllmt[0]);
		#endif
		#ifdef ADC_1_ADLLMT1_INIT
		periphMemWrite(ADC_1_ADLLMT1_INIT, &pAdcBase->adllmt[1]);
		#endif
		#ifdef ADC_1_ADLLMT2_INIT
		periphMemWrite(ADC_1_ADLLMT2_INIT, &pAdcBase->adllmt[2]);
		#endif
		#ifdef ADC_1_ADLLMT3_INIT
		periphMemWrite(ADC_1_ADLLMT3_INIT, &pAdcBase->adllmt[3]);
		#endif
		#ifdef ADC_1_ADLLMT4_INIT
		periphMemWrite(ADC_1_ADLLMT4_INIT, &pAdcBase->adllmt[4]);
		#endif
		#ifdef ADC_1_ADLLMT5_INIT
		periphMemWrite(ADC_1_ADLLMT5_INIT, &pAdcBase->adllmt[5]);
		#endif
		#ifdef ADC_1_ADLLMT6_INIT
		periphMemWrite(ADC_1_ADLLMT6_INIT, &pAdcBase->adllmt[6]);
		#endif
		#ifdef ADC_1_ADLLMT7_INIT
		periphMemWrite(ADC_1_ADLLMT7_INIT, &pAdcBase->adllmt[7]);
		#endif
	#if ADC_VERSION >= 6
		#ifdef ADC_1_ADLLMT8_INIT
		periphMemWrite(ADC_1_ADLLMT8_INIT, &pAdcBase->adllmt[8]);
		#endif
		#ifdef ADC_1_ADLLMT9_INIT
		periphMemWrite(ADC_1_ADLLMT9_INIT, &pAdcBase->adllmt[9]);
		#endif
		#ifdef ADC_1_ADLLMT10_INIT
		periphMemWrite(ADC_1_ADLLMT10_INIT, &pAdcBase->adllmt[10]);
		#endif
		#ifdef ADC_1_ADLLMT11_INIT
		periphMemWrite(ADC_1_ADLLMT11_INIT, &pAdcBase->adllmt[11]);
		#endif
		#ifdef ADC_1_ADLLMT12_INIT
		periphMemWrite(ADC_1_ADLLMT12_INIT, &pAdcBase->adllmt[12]);
		#endif
		#ifdef ADC_1_ADLLMT13_INIT
		periphMemWrite(ADC_1_ADLLMT13_INIT, &pAdcBase->adllmt[13]);
		#endif
		#ifdef ADC_1_ADLLMT14_INIT
		periphMemWrite(ADC_1_ADLLMT14_INIT, &pAdcBase->adllmt[14]);
		#endif
		#ifdef ADC_1_ADLLMT15_INIT
		periphMemWrite(ADC_1_ADLLMT15_INIT, &pAdcBase->adllmt[15]);
		#endif
	#endif
		
		/* high limit registers */
		#ifdef ADC_1_ADHLMT0_INIT
		periphMemWrite(ADC_1_ADHLMT0_INIT, &pAdcBase->adhlmt[0]);
		#endif
		#ifdef ADC_1_ADHLMT1_INIT
		periphMemWrite(ADC_1_ADHLMT1_INIT, &pAdcBase->adhlmt[1]);
		#endif
		#ifdef ADC_1_ADHLMT2_INIT
		periphMemWrite(ADC_1_ADHLMT2_INIT, &pAdcBase->adhlmt[2]);
		#endif
		#ifdef ADC_1_ADHLMT3_INIT
		periphMemWrite(ADC_1_ADHLMT3_INIT, &pAdcBase->adhlmt[3]);
		#endif
		#ifdef ADC_1_ADHLMT4_INIT
		periphMemWrite(ADC_1_ADHLMT4_INIT, &pAdcBase->adhlmt[4]);
		#endif
		#ifdef ADC_1_ADHLMT5_INIT
		periphMemWrite(ADC_1_ADHLMT5_INIT, &pAdcBase->adhlmt[5]);
		#endif
		#ifdef ADC_1_ADHLMT6_INIT
		periphMemWrite(ADC_1_ADHLMT6_INIT, &pAdcBase->adhlmt[6]);
		#endif
		#ifdef ADC_1_ADHLMT7_INIT
		periphMemWrite(ADC_1_ADHLMT7_INIT, &pAdcBase->adhlmt[7]);
		#endif
	#if ADC_VERSION >= 6
		#ifdef ADC_1_ADHLMT8_INIT
		periphMemWrite(ADC_1_ADHLMT8_INIT, &pAdcBase->adllmt[8]);
		#endif
		#ifdef ADC_1_ADHLMT9_INIT
		periphMemWrite(ADC_1_ADHLMT9_INIT, &pAdcBase->adllmt[9]);
		#endif
		#ifdef ADC_1_ADHLMT10_INIT
		periphMemWrite(ADC_1_ADHLMT10_INIT, &pAdcBase->adllmt[10]);
		#endif
		#ifdef ADC_1_ADHLMT11_INIT
		periphMemWrite(ADC_1_ADHLMT11_INIT, &pAdcBase->adllmt[11]);
		#endif
		#ifdef ADC_1_ADHLMT12_INIT
		periphMemWrite(ADC_1_ADHLMT12_INIT, &pAdcBase->adllmt[12]);
		#endif
		#ifdef ADC_1_ADHLMT13_INIT
		periphMemWrite(ADC_1_ADHLMT13_INIT, &pAdcBase->adllmt[13]);
		#endif
		#ifdef ADC_1_ADHLMT14_INIT
		periphMemWrite(ADC_1_ADHLMT14_INIT, &pAdcBase->adllmt[14]);
		#endif
		#ifdef ADC_1_ADHLMT15_INIT
		periphMemWrite(ADC_1_ADHLMT15_INIT, &pAdcBase->adllmt[15]);
		#endif
	#endif
		
		/* offset registers */
		#ifdef ADC_1_ADOFS0_INIT
		periphMemWrite(ADC_1_ADOFS0_INIT, &pAdcBase->adofs[0]);
		#endif
		#ifdef ADC_1_ADOFS1_INIT
		periphMemWrite(ADC_1_ADOFS1_INIT, &pAdcBase->adofs[1]);
		#endif
		#ifdef ADC_1_ADOFS2_INIT
		periphMemWrite(ADC_1_ADOFS2_INIT, &pAdcBase->adofs[2]);
		#endif
		#ifdef ADC_1_ADOFS3_INIT
		periphMemWrite(ADC_1_ADOFS3_INIT, &pAdcBase->adofs[3]);
		#endif 
		#ifdef ADC_1_ADOFS4_INIT
		periphMemWrite(ADC_1_ADOFS4_INIT, &pAdcBase->adofs[4]);
		#endif	
		#ifdef ADC_1_ADOFS5_INIT
		periphMemWrite(ADC_1_ADOFS5_INIT, &pAdcBase->adofs[5]);
		#endif
		#ifdef ADC_1_ADOFS6_INIT
		periphMemWrite(ADC_1_ADOFS6_INIT, &pAdcBase->adofs[6]);
		#endif
		#ifdef ADC_1_ADOFS7_INIT
		periphMemWrite(ADC_1_ADOFS7_INIT, &pAdcBase->adofs[7]);
		#endif
	#if ADC_VERSION >= 6
		#ifdef ADC_1_ADOFS8_INIT
		periphMemWrite(ADC_1_ADOFS8_INIT, &pAdcBase->adofs[8]);
		#endif
		#ifdef ADC_1_ADOFS9_INIT
		periphMemWrite(ADC_1_ADOFS9_INIT, &pAdcBase->adofs[9]);
		#endif
		#ifdef ADC_1_ADOFS10_INIT
		periphMemWrite(ADC_1_ADOFS10_INIT, &pAdcBase->adofs[10]);
		#endif
		#ifdef ADC_1_ADOFS11_INIT
		periphMemWrite(ADC_1_ADOFS11_INIT, &pAdcBase->adofs[11]);
		#endif 
		#ifdef ADC_1_ADOFS12_INIT
		periphMemWrite(ADC_1_ADOFS12_INIT, &pAdcBase->adofs[12]);
		#endif	
		#ifdef ADC_1_ADOFS13_INIT
		periphMemWrite(ADC_1_ADOFS13_INIT, &pAdcBase->adofs[13]);
		#endif
		#ifdef ADC_1_ADOFS14_INIT
		periphMemWrite(ADC_1_ADOFS14_INIT, &pAdcBase->adofs[14]);
		#endif
		#ifdef ADC_1_ADOFS15_INIT
		periphMemWrite(ADC_1_ADOFS15_INIT, &pAdcBase->adofs[15]);
		#endif
	#endif
		
		/* control registers, initialized last */
		#ifdef ADC_1_ADCCAL_INIT
		periphMemWrite(ADC_1_ADCCAL_INIT, &pAdcBase->adc_cal);
		#endif
	#if ADC_VERSION <= 5
		#ifdef ADC_1_ADZCC_INIT
		periphMemWrite(ADC_1_ADZCC_INIT, &pAdcBase->adzcc);
		#endif
	#else
		#ifdef ADC_1_ZXCTRL1_INIT
		periphMemWrite(ADC_1_ZXCTRL1_INIT, &pAdcBase->zxctrl1);
		#endif
		#ifdef ADC_1_ZXCTRL2_INIT
		periphMemWrite(ADC_1_ZXCTRL2_INIT, &pAdcBase->zxctrl2);
		#endif
	#endif
		#ifdef ADC_1_ADCR3_INIT
		periphMemWrite(ADC_1_ADCR3_INIT, &pAdcBase->adctl3);	//LP Position?
		#endif
		#ifdef ADC_1_ADCR2_INIT
		periphMemWrite(ADC_1_ADCR2_INIT, &pAdcBase->adctl2);
		#endif
		#ifdef ADC_1_ADCR1_INIT
		periphMemWrite(ADC_1_ADCR1_INIT, &pAdcBase->adctl1);
		#endif
		#ifdef ADC_1_ADCPOWER_INIT
		periphMemWrite(ADC_1_ADCPOWER_INIT, &pAdcBase->adcpower);
		#endif
	}
	else
#endif

	; /* last else case */
}

#ifdef __cplusplus
}
#endif
