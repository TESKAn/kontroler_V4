/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name: pwm_82xx.c$
*
* $Date:      Oct-14-2013$
*
* $Version:   2.5.24.0$
*
* Description: Source file for the  EFPWM driver
*
*****************************************************************************/

#include "qs.h"
#include "pwm.h"
#include "initconfig.h"

/********************************************************************************
 pwmInit() function performs the PEFWM module static configuration
 based on the configurable items from appconfig.h 
********************************************************************************/
void efpwmCommonInit(arch_sEFPWM *pEfpwmBase)
{
#pragma unused(pEfpwmBase)

	#if EFPWM_A_COMMON_INIT_USED && defined(EFPWM_A) 

		#ifdef PWM_A_SWCOUT_INIT
		periphMemWrite(PWM_A_SWCOUT_INIT, (UWord16*) &pEfpwmBase->swcount);
		#endif

		#ifdef PWM_A_DTSRCSEL_INIT
		periphMemWrite(PWM_A_DTSRCSEL_INIT, (UWord16*) &pEfpwmBase->dtsrcsel);
		#endif

		#ifdef PWM_A_MCTRL_INIT
		periphMemDummyRead((UWord16*) &pEfpwmBase->mctrl);
		periphMemWrite(PWM_A_MCTRL_INIT & (EFPWM_MCTRL_IPOL_MASK | EFPWM_MCTRL_LDOK_MASK), (UWord16*) &pEfpwmBase->mctrl);
		periphMemWrite(PWM_A_MCTRL_INIT, (UWord16*) &pEfpwmBase->mctrl);
		#endif

		#ifdef PWM_A_MCTRL2_INIT
		periphMemWrite(PWM_A_MCTRL2_INIT, (UWord16*) &pEfpwmBase->mctrl2);
		#endif


		#ifdef PWM_A_FCTRL_INIT
		periphMemWrite(PWM_A_FCTRL_INIT, (UWord16*) &pEfpwmBase->fctrl);
		#endif

		#ifdef PWM_A_FSTS_INIT
		periphMemWrite(PWM_A_FSTS_INIT, (UWord16*) &pEfpwmBase->fsts);
		#endif

		#ifdef PWM_A_FFILT_INIT
		periphMemWrite(PWM_A_FFILT_INIT, (UWord16*) &pEfpwmBase->ffilt);
		#endif

		#ifdef PWM_A_FTST_INIT
		periphMemWrite(PWM_A_FTST_INIT, (UWord16*) &pEfpwmBase->ftst); 
		#endif
		
		#ifdef PWM_A_FCTRL0_INIT
		periphMemWrite(PWM_A_FCTRL0_INIT, (UWord16*) &pEfpwmBase->fctrl0);
		#endif

		#ifdef PWM_A_FSTS0_INIT
		periphMemWrite(PWM_A_FSTS0_INIT, (UWord16*) &pEfpwmBase->fsts0);
		#endif
		
		#ifdef PWM_A_FFILT0_INIT
		periphMemWrite(PWM_A_FFILT0_INIT, (UWord16*) &pEfpwmBase->ffilt0);
		#endif
		
		#ifdef PWM_A_FTST0_INIT
		periphMemWrite(PWM_A_FTST0_INIT, (UWord16*) &pEfpwmBase->ftst0); 
		#endif
		
		#ifdef PWM_A_FCTRL1_INIT
		periphMemWrite(PWM_A_FCTRL1_INIT, (UWord16*) &pEfpwmBase->fctrl1); // new reg. comparing to anguilla Black
		#endif
		
		#ifdef PWM_A_FSTS1_INIT
		periphMemWrite(PWM_A_FSTS1_INIT, (UWord16*) &pEfpwmBase->fsts1); // new reg. comparing to anguilla Black
		#endif

		#ifdef PWM_A_FFILT1_INIT
		periphMemWrite(PWM_A_FFILT1_INIT, (UWord16*) &pEfpwmBase->ffilt1); // new reg. comparing to anguilla Black
		#endif
		
		#ifdef PWM_A_FTST1_INIT
		periphMemWrite(PWM_A_FTST1_INIT, (UWord16*) &pEfpwmBase->ftst1); 
		#endif
		
		#ifdef PWM_A_MASK_INIT
		periphMemWrite(PWM_A_MASK_INIT, (UWord16*) &pEfpwmBase->mask);
		#endif

		#ifdef PWM_A_OUTEN_INIT
		periphMemWrite(PWM_A_OUTEN_INIT, (UWord16*) &pEfpwmBase->outen);
		#endif

	#endif /* EFPWM_A_COMMON_INIT_USED && defined(EFPWM_A) */

	#if EFPWM_COMMON_INIT_USED && defined(EFPWM) 


		#ifdef PWM_SWCOUT_INIT
		periphMemWrite(PWM_SWCOUT_INIT, (UWord16*) &pEfpwmBase->swcount);
		#endif

		#ifdef PWM_DTSRCSEL_INIT
		periphMemWrite(PWM_DTSRCSEL_INIT, (UWord16*) &pEfpwmBase->dtsrcsel);
		#endif

		#ifdef PWM_MCTRL_INIT
		periphMemDummyRead((UWord16*) &pEfpwmBase->mctrl);
		periphMemWrite(PWM_MCTRL_INIT & (EFPWM_MCTRL_IPOL_MASK | EFPWM_MCTRL_LDOK_MASK), (UWord16*) &pEfpwmBase->mctrl);
		periphMemWrite(PWM_MCTRL_INIT, (UWord16*) &pEfpwmBase->mctrl);
		#endif

		#ifdef PWM_MCTRL2_INIT
		periphMemWrite(PWM_MCTRL2_INIT, (UWord16*) &pEfpwmBase->mctrl2);
		#endif

		/* 82xx */
		#ifdef PWM_FCTRL_INIT
		periphMemWrite(PWM_FCTRL_INIT, (UWord16*) &pEfpwmBase->fctrl);
		#endif

		#ifdef PWM_FSTS_INIT
		periphMemWrite(PWM_FSTS_INIT, (UWord16*) &pEfpwmBase->fsts);
		#endif

		#ifdef PWM_FFILT_INIT
		periphMemWrite(PWM_FFILT_INIT, (UWord16*) &pEfpwmBase->ffilt);
		#endif
		/* 84xxx */
		#ifdef PWM_FCTRL0_INIT  // PWM_FCTRL_INIT (Anguilla Black)
		periphMemWrite(PWM_FCTRL0_INIT, (UWord16*) &pEfpwmBase->fctrl0);
		#endif

		#ifdef PWM_FSTS0_INIT // PWM_FSTS_INIT (Anguilla Black)
		periphMemWrite(PWM_FSTS0_INIT, (UWord16*) &pEfpwmBase->fsts0);
		#endif

		#ifdef PWM_FFILT0_INIT  // PWM_FFILT_INIT (Anguilla Black)
		periphMemWrite(PWM_FFILT0_INIT, (UWord16*) &pEfpwmBase->ffilt0);
		#endif

		#ifdef PWM_FTST0_INIT  // PWM_FTST0_INIT (new reg. comparing to Anguilla Black)
		periphMemWrite(PWM_FTST0_INIT, (UWord16*) &pEfpwmBase->ftst0); 
		#endif
		
		#ifdef PWM_FCTRL1_INIT
		periphMemWrite(PWM_FCTRL1_INIT, (UWord16*) &pEfpwmBase->fctrl1); // new reg. comparing to anguilla Black
		#endif
		
		#ifdef PWM_FSTS1_INIT
		periphMemWrite(PWM_FSTS1_INIT, (UWord16*) &pEfpwmBase->fsts1); // new reg. comparing to anguilla Black
		#endif
		
		#ifdef PWM_FFILT1_INIT
		periphMemWrite(PWM_FFILT1_INIT, (UWord16*) &pEfpwmBase->ffilt1); // new reg. comparing to anguilla Black
		#endif
		
		#ifdef PWM_FTST1_INIT
		periphMemWrite(PWM_FFILT1_INIT, (UWord16*) &pEfpwmBase->ftst1); // new reg. comparing to anguilla Black   
		#endif
		
		#ifdef PWM_MASK_INIT
		periphMemWrite(PWM_MASK_INIT, (UWord16*) &pEfpwmBase->mask);
		#endif

		#ifdef PWM_OUTEN_INIT
		periphMemWrite(PWM_OUTEN_INIT, (UWord16*) &pEfpwmBase->outen);
		#endif

	#endif /* EFPWM_COMMON_INIT_USED && defined(EFPWM) */
}

#if defined(EFPWM_B)
void efpwmBCommonInit(arch_sEFPWMB *pEfpwmBase)
{
	#pragma unused(pEfpwmBase)

	#if EFPWM_B_COMMON_INIT_USED && defined(EFPWM_B) // || (EFPWM_B_COMMON_INIT_USED && defined(EFPWM_B))  

		#ifdef PWM_B_SWCOUT_INIT
		periphMemWrite(PWM_B_SWCOUT_INIT, (UWord16*) &pEfpwmBase->swcount);
		#endif

		#ifdef PWM_B_DTSRCSEL_INIT
		periphMemWrite(PWM_B_DTSRCSEL_INIT, (UWord16*) &pEfpwmBase->dtsrcsel);
		#endif

		#ifdef PWM_B_MCTRL_INIT
		periphMemDummyRead((UWord16*) &pEfpwmBase->mctrl);
		periphMemWrite(PWM_B_MCTRL_INIT & (EFPWM_MCTRL_IPOL_MASK | EFPWM_MCTRL_LDOK_MASK), (UWord16*) &pEfpwmBase->mctrl);
		periphMemWrite(PWM_B_MCTRL_INIT, (UWord16*) &pEfpwmBase->mctrl);
		#endif

		#ifdef PWM_B_FCTRL_INIT
		periphMemWrite(PWM_B_FCTRL_INIT, (UWord16*) &pEfpwmBase->fctrl);
		#endif

		#ifdef PWM_B_FSTS_INIT
		periphMemWrite(PWM_B_FSTS_INIT, (UWord16*) &pEfpwmBase->fsts);
		#endif

		#ifdef PWM_B_FFILT_INIT
		periphMemWrite(PWM_B_FFILT_INIT, (UWord16*) &pEfpwmBase->ffilt);
		#endif

		#ifdef PWM_B_FTST_INIT
		periphMemWrite(PWM_B_FTST_INIT, (UWord16*) &pEfpwmBase->ftst); 
		#endif
		
		#ifdef PWM_B_FCTRL0_INIT
		periphMemWrite(PWM_B_FCTRL0_INIT, (UWord16*) &pEfpwmBase->fctrl0);
		#endif

		#ifdef PWM_B_FSTS0_INIT
		periphMemWrite(PWM_B_FSTS0_INIT, (UWord16*) &pEfpwmBase->fsts0);
		#endif
		
		#ifdef PWM_B_FFILT0_INIT
		periphMemWrite(PWM_B_FFILT0_INIT, (UWord16*) &pEfpwmBase->ffilt0);
		#endif
		
		#ifdef PWM_B_FTST0_INIT
		periphMemWrite(PWM_B_FTST0_INIT, (UWord16*) &pEfpwmBase->ftst0); 
		#endif
		
		#ifdef PWM_B_FCTRL1_INIT
		periphMemWrite(PWM_B_FCTRL1_INIT, (UWord16*) &pEfpwmBase->fctrl1); // new reg. comparing to anguilla Black
		#endif
		
		#ifdef PWM_B_FSTS1_INIT
		periphMemWrite(PWM_B_FSTS1_INIT, (UWord16*) &pEfpwmBase->fsts1); // new reg. comparing to anguilla Black
		#endif

		#ifdef PWM_B_FFILT1_INIT
		periphMemWrite(PWM_B_FFILT1_INIT, (UWord16*) &pEfpwmBase->ffilt1); // new reg. comparing to anguilla Black
		#endif
		
		#ifdef PWM_B_FTST1_INIT
		periphMemWrite(PWM_B_FTST1_INIT, (UWord16*) &pEfpwmBase->ftst1); 
		#endif
		
		#ifdef PWM_B_MASK_INIT
		periphMemWrite(PWM_B_MASK_INIT, (UWord16*) &pEfpwmBase->mask);
		#endif

		#ifdef PWM_B_OUTEN_INIT
		periphMemWrite(PWM_B_OUTEN_INIT, (UWord16*) &pEfpwmBase->outen);
		#endif
	#endif /* EFPWM_B_COMMON_INIT_USED && defined(EFPWM_B) */
}
#endif /* defined(EFPWM_B) */

void efpwmInit(UWord16 *pEfpwmBase)
{
	#pragma unused(pEfpwmBase)
#if (EFPWM_SUB0_INIT_USED || EFPWM_A_SUB0_INIT_USED || EFPWM_SUB1_INIT_USED || EFPWM_A_SUB1_INIT_USED ||\
	 EFPWM_SUB2_INIT_USED || EFPWM_A_SUB2_INIT_USED || EFPWM_SUB3_INIT_USED || EFPWM_A_SUB3_INIT_USED)
#if defined(EFPWM)
	if (pEfpwmBase == (UWord16 *)EFPWM)
#elif defined(EFPWM_A)
	if (pEfpwmBase == (UWord16 *)EFPWM_A)
#else 
	if 0
#endif
	{
		#if EFPWM_SUB0_INIT_USED || EFPWM_A_SUB0_INIT_USED
		efpwmSubFracCaptInit(&((arch_sEFPWM*)pEfpwmBase)->Sub0);
		#endif
		#if EFPWM_SUB1_INIT_USED || EFPWM_A_SUB1_INIT_USED
		efpwmSubFracCaptInit(&((arch_sEFPWM*)pEfpwmBase)->Sub1);
		#endif
		#if EFPWM_SUB2_INIT_USED || EFPWM_A_SUB2_INIT_USED
		efpwmSubFracCaptInit(&((arch_sEFPWM*)pEfpwmBase)->Sub2);
		#endif
	#if EFPWM_VERSION == 1

		#if EFPWM_SUB3_INIT_USED
		efpwmSubCaptInit(&((arch_sEFPWM*)pEfpwmBase)->Sub3);
		#endif
	#else

		#if EFPWM_SUB3_INIT_USED || EFPWM_A_SUB3_INIT_USED
		efpwmSubFracCaptInit(&((arch_sEFPWM*)pEfpwmBase)->Sub3);
		#endif

	#endif /* EFPWM_VERSION == 1 */

		#if EFPWM_COMMON_INIT_USED || EFPWM_A_COMMON_INIT_USED
		efpwmCommonInit((arch_sEFPWM*)pEfpwmBase);
		#endif
	}
	else
#endif

#if (EFPWM_B_SUB0_INIT_USED || EFPWM_B_SUB1_INIT_USED || EFPWM_B_SUB2_INIT_USED || EFPWM_B_SUB3_INIT_USED) && defined(EFPWM_B)
	if (pEfpwmBase == (UWord16 *)EFPWM_B)
	{
	#if EFPWM_B_SUB0_INIT_USED
	efpwmBSubCaptInit(&((arch_sEFPWMB*)pEfpwmBase)->Sub0);
	#endif
	#if EFPWM_B_SUB1_INIT_USED
	efpwmBSubCaptInit(&((arch_sEFPWMB*)pEfpwmBase)->Sub1);
	#endif
	#if EFPWM_B_SUB2_INIT_USED
	efpwmBSubCaptInit(&((arch_sEFPWMB*)pEfpwmBase)->Sub2);
	#endif
	#if EFPWM_B_SUB3_INIT_USED
	efpwmBSubCaptInit(&((arch_sEFPWMB*)pEfpwmBase)->Sub3);
	#endif
	#if EFPWM_B_COMMON_INIT_USED
	efpwmBCommonInit((arch_sEFPWMB*)pEfpwmBase);
	#endif
	}
	else
#endif
	;
}

#if defined(EFPWM_B) 
void efpwmBInit(arch_sEFPWMB *pEfpwmbBase)
{
#pragma unused(pEfpwmbBase)
	#if EFPWM_B_SUB0_INIT_USED
	efpwmBSubCaptInit(&pEfpwmbBase->Sub0);
	#endif
	#if EFPWM_B_SUB1_INIT_USED
	efpwmBSubCaptInit(&pEfpwmbBase->Sub1);
	#endif
	#if EFPWM_B_SUB2_INIT_USED
	efpwmBSubCaptInit(&pEfpwmbBase->Sub2);
	#endif
	#if EFPWM_B_SUB3_INIT_USED
	efpwmBSubCaptInit(&pEfpwmbBase->Sub3);
	#endif
	#if EFPWM_B_COMMON_INIT_USED
	efpwmBCommonInit(pEfpwmbBase);
	#endif
}
#endif /* defined(EFPWM_B) */

void efpwmSubFracCaptInit(arch_sEFPWMSubFracCaptModule *pEfpwmBase)
{
#pragma unused(pEfpwmBase)
	#if EFPWM_A_SUB0_INIT_USED && defined(EFPWM_A_SUB0) 

		if(pEfpwmBase == (arch_sEFPWMSubFracCaptModule*)EFPWM_A_SUB0)
		{  
			#if PWM_A_0_USE_PWMVAL
				#ifdef PWM_A_0_VAL2_INIT
				periphMemWrite(PWM_A_0_VAL2_INIT, (UWord16*) &pEfpwmBase->smval2);
				#endif
				#ifdef PWM_A_0_FRACVAL2_INIT
				periphMemWrite(PWM_A_0_FRACVAL2_INIT, (UWord16*) &pEfpwmBase->smfracval2);
				#endif
				#ifdef PWM_A_0_VAL3_INIT
				periphMemWrite(PWM_A_0_VAL3_INIT, (UWord16*) &pEfpwmBase->smval3);
				#endif
				#ifdef PWM_A_0_FRACVAL3_INIT
				periphMemWrite(PWM_A_0_FRACVAL3_INIT, (UWord16*) &pEfpwmBase->smfracval3);
				#endif
				#ifdef PWM_A_0_VAL4_INIT
				periphMemWrite(PWM_A_0_VAL4_INIT, (UWord16*) &pEfpwmBase->smval4);
				#endif
				#ifdef PWM_A_0_FRACVAL4_INIT
				periphMemWrite(PWM_A_0_FRACVAL4_INIT, (UWord16*) &pEfpwmBase->smfracval4);
				#endif
				#ifdef PWM_A_0_VAL5_INIT
				periphMemWrite(PWM_A_0_VAL5_INIT, (UWord16*) &pEfpwmBase->smval5);
				#endif
				#ifdef PWM_A_0_FRACVAL5_INIT
				periphMemWrite(PWM_A_0_FRACVAL5_INIT, (UWord16*) &pEfpwmBase->smfracval5);
				#endif
			#endif

			#ifdef PWM_A_0_VAL1_INIT //
			periphMemWrite(PWM_A_0_VAL1_INIT, (UWord16*) &pEfpwmBase->smval1);
			#endif

			#ifdef PWM_A_0_FRACVAL1_INIT //
			periphMemWrite(PWM_A_0_FRACVAL1_INIT, (UWord16*) &pEfpwmBase->smfracval1);
			#endif

			#ifdef PWM_A_0_INIT_INIT //
			periphMemWrite(PWM_A_0_INIT_INIT, (UWord16*) &pEfpwmBase->sminit);
			#endif

			#ifdef PWM_A_0_DTCNT0_INIT //
			periphMemWrite(PWM_A_0_DTCNT0_INIT, (UWord16*) &pEfpwmBase->smdtcnt0);
			#endif

			#ifdef PWM_A_0_DTCNT1_INIT //
			periphMemWrite(PWM_A_0_DTCNT1_INIT, (UWord16*) &pEfpwmBase->smdtcnt1);
			#endif

			#ifdef PWM_A_0_CTRL_INIT //
			periphMemWrite(PWM_A_0_CTRL_INIT, (UWord16*) &pEfpwmBase->smctrl);
			#endif

			#ifdef PWM_A_0_CTRL2_INIT //
			periphMemWrite(PWM_A_0_CTRL2_INIT, (UWord16*) &pEfpwmBase->smctrl2);
			#endif

			#ifdef PWM_A_0_INTEN_INIT  //
			periphMemWrite(PWM_A_0_INTEN_INIT, (UWord16*) &pEfpwmBase->sminten);
			#endif

			#ifdef PWM_A_0_TCTRL_INIT //
			periphMemWrite(PWM_A_0_TCTRL_INIT, (UWord16*) &pEfpwmBase->smtctrl);
			#endif

			#ifdef PWM_A_0_DISMAP_INIT /* LP */
			periphMemWrite(PWM_A_0_DISMAP_INIT, (UWord16*) &pEfpwmBase->smdismap);
			#endif
			
			#ifdef PWM_A_0_DISMAP0_INIT // new name of reg
			periphMemWrite(PWM_A_0_DISMAP0_INIT, (UWord16*) &pEfpwmBase->smdismap0);
			#endif
			
			#ifdef PWM_A_0_DISMAP1_INIT // new reg
			periphMemWrite(PWM_A_0_DISMAP1_INIT, (UWord16*) &pEfpwmBase->smdismap1);
			#endif

			#ifdef PWM_A_0_FRCTRL_INIT //
			periphMemWrite(PWM_A_0_FRCTRL_INIT, (UWord16*) &pEfpwmBase->smfrctrl);
			#endif

			#ifdef PWM_A_0_VAL0_INIT //
			periphMemWrite(PWM_A_0_VAL0_INIT, (UWord16*) &pEfpwmBase->smval0);
			#endif

			#ifdef PWM_A_0_CAPTCTRLA_INIT
			periphMemWrite(PWM_A_0_CAPTCTRLA_INIT, (UWord16*) &pEfpwmBase->smcaptctrla);
			#endif

			#ifdef PWM_A_0_CAPTCOMPA_INIT
			periphMemWrite(PWM_A_0_CAPTCOMPA_INIT, (UWord16*) &pEfpwmBase->smcaptcompa);
			#endif

			#ifdef PWM_A_0_CAPTCTRLB_INIT
			periphMemWrite(PWM_A_0_CAPTCTRLB_INIT, (UWord16*) &pEfpwmBase->smcaptctrlb);
			#endif

			#ifdef PWM_A_0_CAPTCOMPB_INIT
			periphMemWrite(PWM_A_0_CAPTCOMPB_INIT, (UWord16*) &pEfpwmBase->smcaptcompb);
			#endif

			#ifdef PWM_A_0_CAPTCTRLX_INIT
			periphMemWrite(PWM_A_0_CAPTCTRLX_INIT, (UWord16*) &pEfpwmBase->smcaptctrlx);
			#endif

			#ifdef PWM_A_0_CAPTCOMPX_INIT
			periphMemWrite(PWM_A_0_CAPTCOMPX_INIT, (UWord16*) &pEfpwmBase->smcaptcompx);
			#endif
			
			#ifdef PWM_A_0_OCTRL_INIT //
			periphMemWrite(PWM_A_0_OCTRL_INIT, (UWord16*) &pEfpwmBase->smoctrl);
			#endif

			#ifdef PWM_A_0_DMAEN_INIT
			periphMemWrite(PWM_A_0_DMAEN_INIT, (UWord16*) &pEfpwmBase->smdmaen);
			#endif
		}	/* if(pEfpwmBase == (arch_sEFPWMSubFracCaptModule*)EFPWM_A_SUB0) */
		else

	#endif /* EFPWM_A_SUB0_INIT_USED && defined(EFPWM_A_SUB0) */

	#if EFPWM_A_SUB1_INIT_USED && defined(EFPWM_A_SUB1) 

		if(pEfpwmBase == (arch_sEFPWMSubFracCaptModule*)EFPWM_A_SUB1)
		{  
			#if PWM_A_1_USE_PWMVAL
				#ifdef PWM_A_1_VAL2_INIT
				periphMemWrite(PWM_A_1_VAL2_INIT, (UWord16*) &pEfpwmBase->smval2);
				#endif
				#ifdef PWM_A_1_FRACVAL2_INIT
				periphMemWrite(PWM_A_1_FRACVAL2_INIT, (UWord16*) &pEfpwmBase->smfracval2);
				#endif
				#ifdef PWM_A_1_VAL3_INIT
				periphMemWrite(PWM_A_1_VAL3_INIT, (UWord16*) &pEfpwmBase->smval3);
				#endif
				#ifdef PWM_A_1_FRACVAL3_INIT
				periphMemWrite(PWM_A_1_FRACVAL3_INIT, (UWord16*) &pEfpwmBase->smfracval3);
				#endif
				#ifdef PWM_A_1_VAL4_INIT
				periphMemWrite(PWM_A_1_VAL4_INIT, (UWord16*) &pEfpwmBase->smval4);
				#endif
				#ifdef PWM_A_1_FRACVAL4_INIT
				periphMemWrite(PWM_A_1_FRACVAL4_INIT, (UWord16*) &pEfpwmBase->smfracval4);
				#endif
				#ifdef PWM_A_1_VAL5_INIT
				periphMemWrite(PWM_A_1_VAL5_INIT, (UWord16*) &pEfpwmBase->smval5);
				#endif
				#ifdef PWM_A_1_FRACVAL5_INIT
				periphMemWrite(PWM_A_1_FRACVAL5_INIT, (UWord16*) &pEfpwmBase->smfracval5);
				#endif
			#endif

			#ifdef PWM_A_1_VAL0_INIT
			periphMemWrite(PWM_A_1_VAL0_INIT, (UWord16*) &pEfpwmBase->smval0);
			#endif

			#ifdef PWM_A_1_VAL1_INIT
			periphMemWrite(PWM_A_1_VAL1_INIT, (UWord16*) &pEfpwmBase->smval1);
			#endif

			#ifdef PWM_A_1_FRACVAL1_INIT
			periphMemWrite(PWM_A_1_FRACVAL1_INIT, (UWord16*) &pEfpwmBase->smfracval1);
			#endif

			#ifdef PWM_A_1_INIT_INIT
			periphMemWrite(PWM_A_1_INIT_INIT, (UWord16*) &pEfpwmBase->sminit);
			#endif

			#ifdef PWM_A_1_CTRL_INIT
			periphMemWrite(PWM_A_1_CTRL_INIT, (UWord16*) &pEfpwmBase->smctrl);
			#endif

			#ifdef PWM_A_1_CTRL2_INIT
			periphMemWrite(PWM_A_1_CTRL2_INIT, (UWord16*) &pEfpwmBase->smctrl2);
			#endif

			#ifdef PWM_A_1_FRCTRL_INIT
			periphMemWrite(PWM_A_1_FRCTRL_INIT, (UWord16*) &pEfpwmBase->smfrctrl);
			#endif

			#ifdef PWM_A_1_OCTRL_INIT
			periphMemWrite(PWM_A_1_OCTRL_INIT, (UWord16*) &pEfpwmBase->smoctrl);
			#endif

			#ifdef PWM_A_1_INTEN_INIT
			periphMemWrite(PWM_A_1_INTEN_INIT, (UWord16*) &pEfpwmBase->sminten);
			#endif

			#ifdef PWM_A_1_TCTRL_INIT
			periphMemWrite(PWM_A_1_TCTRL_INIT, (UWord16*) &pEfpwmBase->smtctrl);
			#endif

			#ifdef PWM_A_1_DISMAP_INIT /* LP */
			periphMemWrite(PWM_A_1_DISMAP_INIT, (UWord16*) &pEfpwmBase->smdismap);
			#endif
			
			#ifdef PWM_A_1_DISMAP0_INIT
			periphMemWrite(PWM_A_1_DISMAP0_INIT, (UWord16*) &pEfpwmBase->smdismap0); // smdismap changed to smdismap0. Needs to review it
			#endif

			#ifdef PWM_A_1_DISMAP1_INIT
			periphMemWrite(PWM_A_1_DISMAP1_INIT, (UWord16*) &pEfpwmBase->smdismap1); // new reg. comparing to Anguilla Black
			#endif
			
			#ifdef PWM_A_1_DTCNT0_INIT
			periphMemWrite(PWM_A_1_DTCNT0_INIT, (UWord16*) &pEfpwmBase->smdtcnt0);
			#endif

			#ifdef PWM_A_1_DTCNT1_INIT
			periphMemWrite(PWM_A_1_DTCNT1_INIT, (UWord16*) &pEfpwmBase->smdtcnt1);
			#endif
			
			#ifdef PWM_A_1_CAPTCTRLA_INIT
			periphMemWrite(PWM_A_1_CAPTCTRLA_INIT, (UWord16*) &pEfpwmBase->smcaptctrla);
			#endif

			#ifdef PWM_A_1_CAPTCOMPA_INIT
			periphMemWrite(PWM_A_1_CAPTCOMPA_INIT, (UWord16*) &pEfpwmBase->smcaptcompa);
			#endif

			#ifdef PWM_A_1_CAPTCTRLB_INIT
			periphMemWrite(PWM_A_1_CAPTCTRLB_INIT, (UWord16*) &pEfpwmBase->smcaptctrlb);
			#endif

			#ifdef PWM_A_1_CAPTCOMPB_INIT
			periphMemWrite(PWM_A_1_CAPTCOMPB_INIT, (UWord16*) &pEfpwmBase->smcaptcompb);
			#endif

			#ifdef PWM_A_1_CAPTCTRLX_INIT
			periphMemWrite(PWM_A_1_CAPTCTRLX_INIT, (UWord16*) &pEfpwmBase->smcaptctrlx);
			#endif

			#ifdef PWM_A_1_CAPTCOMPX_INIT
			periphMemWrite(PWM_A_1_CAPTCOMPX_INIT, (UWord16*) &pEfpwmBase->smcaptcompx);
			#endif

			#ifdef PWM_A_1_DMAEN_INIT
			periphMemWrite(PWM_A_1_DMAEN_INIT, (UWord16*) &pEfpwmBase->smdmaen);
			#endif
		}	/* if(pEfpwmBase == (arch_sEFPWMSubFracCaptModule*)EFPWM_A_SUB1) */
		else

	#endif /* EFPWM_A_SUB1_INIT_USED && defined(EFPWM_A_SUB1) */

	#if EFPWM_A_SUB2_INIT_USED && defined(EFPWM_A_SUB2) 

		if(pEfpwmBase == (arch_sEFPWMSubFracCaptModule*)EFPWM_A_SUB2)
		{  
			#if PWM_A_2_USE_PWMVAL
				#ifdef PWM_A_2_VAL2_INIT
				periphMemWrite(PWM_A_2_VAL2_INIT, (UWord16*) &pEfpwmBase->smval2);
				#endif
				#ifdef PWM_A_2_FRACVAL2_INIT
				periphMemWrite(PWM_A_2_FRACVAL2_INIT, (UWord16*) &pEfpwmBase->smfracval2);
				#endif
				#ifdef PWM_A_2_VAL3_INIT
				periphMemWrite(PWM_A_2_VAL3_INIT, (UWord16*) &pEfpwmBase->smval3);
				#endif
				#ifdef PWM_A_2_FRACVAL3_INIT
				periphMemWrite(PWM_A_2_FRACVAL3_INIT, (UWord16*) &pEfpwmBase->smfracval3);
				#endif
				#ifdef PWM_A_2_VAL4_INIT
				periphMemWrite(PWM_A_2_VAL4_INIT, (UWord16*) &pEfpwmBase->smval4);
				#endif
				#ifdef PWM_A_2_FRACVAL4_INIT
				periphMemWrite(PWM_A_2_FRACVAL4_INIT, (UWord16*) &pEfpwmBase->smfracval4);
				#endif
				#ifdef PWM_A_2_VAL5_INIT
				periphMemWrite(PWM_A_2_VAL5_INIT, (UWord16*) &pEfpwmBase->smval5);
				#endif
				#ifdef PWM_A_2_FRACVAL5_INIT
				periphMemWrite(PWM_A_2_FRACVAL5_INIT, (UWord16*) &pEfpwmBase->smfracval5);
				#endif
			#endif

			#ifdef PWM_A_2_VAL0_INIT
			periphMemWrite(PWM_A_2_VAL0_INIT, (UWord16*) &pEfpwmBase->smval0);
			#endif

			#ifdef PWM_A_2_VAL1_INIT
			periphMemWrite(PWM_A_2_VAL1_INIT, (UWord16*) &pEfpwmBase->smval1);
			#endif

			#ifdef PWM_A_2_FRACVAL1_INIT
			periphMemWrite(PWM_A_2_FRACVAL1_INIT, (UWord16*) &pEfpwmBase->smfracval1);
			#endif

			#ifdef PWM_A_2_INIT_INIT
			periphMemWrite(PWM_A_2_INIT_INIT, (UWord16*) &pEfpwmBase->sminit);
			#endif

			#ifdef PWM_A_2_CTRL_INIT
			periphMemWrite(PWM_A_2_CTRL_INIT, (UWord16*) &pEfpwmBase->smctrl);
			#endif

			#ifdef PWM_A_2_CTRL2_INIT
			periphMemWrite(PWM_A_2_CTRL2_INIT, (UWord16*) &pEfpwmBase->smctrl2);
			#endif

			#ifdef PWM_A_2_FRCTRL_INIT
			periphMemWrite(PWM_A_2_FRCTRL_INIT, (UWord16*) &pEfpwmBase->smfrctrl);
			#endif

			#ifdef PWM_A_2_OCTRL_INIT
			periphMemWrite(PWM_A_2_OCTRL_INIT, (UWord16*) &pEfpwmBase->smoctrl);
			#endif

			#ifdef PWM_A_2_INTEN_INIT
			periphMemWrite(PWM_A_2_INTEN_INIT, (UWord16*) &pEfpwmBase->sminten);
			#endif

			#ifdef PWM_A_2_TCTRL_INIT
			periphMemWrite(PWM_A_2_TCTRL_INIT, (UWord16*) &pEfpwmBase->smtctrl);
			#endif

			#ifdef PWM_A_2_DISMAP_INIT /* LP */
			periphMemWrite(PWM_A_2_DISMAP_INIT, (UWord16*) &pEfpwmBase->smdismap);
			#endif
			
			#ifdef PWM_A_2_DISMAP0_INIT
			periphMemWrite(PWM_A_2_DISMAP0_INIT, (UWord16*) &pEfpwmBase->smdismap0);  // sdmdismap changed to sdmdismap0. Needs to review it
			#endif

			#ifdef PWM_A_2_DISMAP1_INIT
			periphMemWrite(PWM_A_2_DISMAP1_INIT, (UWord16*) &pEfpwmBase->smdismap1);  // new reg. comparing to Anguilla Black it
			#endif
			
			#ifdef PWM_A_2_DTCNT0_INIT
			periphMemWrite(PWM_A_2_DTCNT0_INIT, (UWord16*) &pEfpwmBase->smdtcnt0);
			#endif

			#ifdef PWM_A_2_DTCNT1_INIT
			periphMemWrite(PWM_A_2_DTCNT1_INIT, (UWord16*) &pEfpwmBase->smdtcnt1);
			#endif
			
			#ifdef PWM_A_2_CAPTCTRLA_INIT
			periphMemWrite(PWM_A_2_CAPTCTRLA_INIT, (UWord16*) &pEfpwmBase->smcaptctrla);
			#endif

			#ifdef PWM_A_2_CAPTCOMPA_INIT
			periphMemWrite(PWM_A_2_CAPTCOMPA_INIT, (UWord16*) &pEfpwmBase->smcaptcompa);
			#endif

			#ifdef PWM_A_2_CAPTCTRLB_INIT
			periphMemWrite(PWM_A_2_CAPTCTRLB_INIT, (UWord16*) &pEfpwmBase->smcaptctrlb);
			#endif

			#ifdef PWM_A_2_CAPTCOMPB_INIT
			periphMemWrite(PWM_A_2_CAPTCOMPB_INIT, (UWord16*) &pEfpwmBase->smcaptcompb);
			#endif

			#ifdef PWM_A_2_CAPTCTRLX_INIT
			periphMemWrite(PWM_A_2_CAPTCTRLX_INIT, (UWord16*) &pEfpwmBase->smcaptctrlx);
			#endif

			#ifdef PWM_A_2_CAPTCOMPX_INIT
			periphMemWrite(PWM_A_2_CAPTCOMPX_INIT, (UWord16*) &pEfpwmBase->smcaptcompx);
			#endif
			
			#ifdef PWM_A_2_DMAEN_INIT
			periphMemWrite(PWM_A_2_DMAEN_INIT, (UWord16*) &pEfpwmBase->smdmaen);
			#endif
		}	/* if(pEfpwmBase == (arch_sEFPWMSubFracCaptModule*)EFPWM_A_SUB2) */
		else

	#endif /* EFPWM_A_SUB2_INIT_USED && defined(EFPWM_A_SUB2) */

	#if EFPWM_A_SUB3_INIT_USED && defined(EFPWM_A_SUB3) 

		if(pEfpwmBase == (arch_sEFPWMSubFracCaptModule*)EFPWM_A_SUB3)
		{  
			#if PWM_A_3_USE_PWMVAL
				#ifdef PWM_A_3_VAL2_INIT
				periphMemWrite(PWM_A_3_VAL2_INIT, (UWord16*) &pEfpwmBase->smval2);
				#endif
				#ifdef PWM_A_3_FRACVAL2_INIT
				periphMemWrite(PWM_A_3_FRACVAL2_INIT, (UWord16*) &pEfpwmBase->smfracval2);
				#endif
				#ifdef PWM_A_3_VAL3_INIT
				periphMemWrite(PWM_A_3_VAL3_INIT, (UWord16*) &pEfpwmBase->smval3);
				#endif
				#ifdef PWM_A_3_FRACVAL3_INIT
				periphMemWrite(PWM_A_3_FRACVAL3_INIT, (UWord16*) &pEfpwmBase->smfracval3);
				#endif
				#ifdef PWM_A_3_VAL4_INIT
				periphMemWrite(PWM_A_3_VAL4_INIT, (UWord16*) &pEfpwmBase->smval4);
				#endif
				#ifdef PWM_A_3_FRACVAL4_INIT
				periphMemWrite(PWM_A_3_FRACVAL4_INIT, (UWord16*) &pEfpwmBase->smfracval4);
				#endif
				#ifdef PWM_A_3_VAL5_INIT
				periphMemWrite(PWM_A_3_VAL5_INIT, (UWord16*) &pEfpwmBase->smval5);
				#endif
				#ifdef PWM_A_3_FRACVAL5_INIT
				periphMemWrite(PWM_A_3_FRACVAL5_INIT, (UWord16*) &pEfpwmBase->smfracval5);
				#endif
			#endif

			#ifdef PWM_A_3_VAL0_INIT
			periphMemWrite(PWM_A_3_VAL0_INIT, (UWord16*) &pEfpwmBase->smval0);
			#endif

			#ifdef PWM_A_3_VAL1_INIT
			periphMemWrite(PWM_A_3_VAL1_INIT, (UWord16*) &pEfpwmBase->smval1);
			#endif

			#ifdef PWM_A_3_FRACVAL1_INIT
			periphMemWrite(PWM_A_3_FRACVAL1_INIT, (UWord16*) &pEfpwmBase->smfracval1);
			#endif

			#ifdef PWM_A_3_INIT_INIT
			periphMemWrite(PWM_A_3_INIT_INIT, (UWord16*) &pEfpwmBase->sminit);
			#endif

			#ifdef PWM_A_3_CTRL_INIT
			periphMemWrite(PWM_A_3_CTRL_INIT, (UWord16*) &pEfpwmBase->smctrl);
			#endif

			#ifdef PWM_A_3_CTRL2_INIT
			periphMemWrite(PWM_A_3_CTRL2_INIT, (UWord16*) &pEfpwmBase->smctrl2);
			#endif

			#ifdef PWM_A_3_FRCTRL_INIT
			periphMemWrite(PWM_A_3_FRCTRL_INIT, (UWord16*) &pEfpwmBase->smfrctrl);
			#endif

			#ifdef PWM_A_3_OCTRL_INIT
			periphMemWrite(PWM_A_3_OCTRL_INIT, (UWord16*) &pEfpwmBase->smoctrl);
			#endif

			#ifdef PWM_A_3_INTEN_INIT
			periphMemWrite(PWM_A_3_INTEN_INIT, (UWord16*) &pEfpwmBase->sminten);
			#endif

			#ifdef PWM_A_3_TCTRL_INIT
			periphMemWrite(PWM_A_3_TCTRL_INIT, (UWord16*) &pEfpwmBase->smtctrl);
			#endif

			#ifdef PWM_A_3_DISMAP_INIT /* LP */
			periphMemWrite(PWM_A_3_DISMAP_INIT, (UWord16*) &pEfpwmBase->smdismap);
			#endif
			
			#ifdef PWM_A_3_DISMAP0_INIT
			periphMemWrite(PWM_A_3_DISMAP0_INIT, (UWord16*) &pEfpwmBase->smdismap0); // smdismap changed to smdismap0. Needs to review it
			#endif

			#ifdef PWM_A_3_DISMAP1_INIT
			periphMemWrite(PWM_A_3_DISMAP1_INIT, (UWord16*) &pEfpwmBase->smdismap1); // new reg. comparing to Anguilla Black
			#endif
			
			#ifdef PWM_A_3_DTCNT0_INIT
			periphMemWrite(PWM_A_3_DTCNT0_INIT, (UWord16*) &pEfpwmBase->smdtcnt0);
			#endif

			#ifdef PWM_A_3_DTCNT1_INIT
			periphMemWrite(PWM_A_3_DTCNT1_INIT, (UWord16*) &pEfpwmBase->smdtcnt1);
			#endif

			#ifdef PWM_A_3_CAPTCTRLA_INIT
			periphMemWrite(PWM_A_3_CAPTCTRLA_INIT, (UWord16*) &pEfpwmBase->smcaptctrla);
			#endif

			#ifdef PWM_A_3_CAPTCOMPA_INIT
			periphMemWrite(PWM_A_3_CAPTCOMPA_INIT, (UWord16*) &pEfpwmBase->smcaptcompa);
			#endif

			#ifdef PWM_A_3_CAPTCTRLB_INIT
			periphMemWrite(PWM_A_3_CAPTCTRLB_INIT, (UWord16*) &pEfpwmBase->smcaptctrlb);
			#endif

			#ifdef PWM_A_3_CAPTCOMPB_INIT
			periphMemWrite(PWM_A_3_CAPTCOMPB_INIT, (UWord16*) &pEfpwmBase->smcaptcompb);
			#endif

			#ifdef PWM_A_3_CAPTCTRLX_INIT
			periphMemWrite(PWM_A_3_CAPTCTRLX_INIT, (UWord16*) &pEfpwmBase->smcaptctrlx);
			#endif

			#ifdef PWM_A_3_CAPTCOMPX_INIT
			periphMemWrite(PWM_A_3_CAPTCOMPX_INIT, (UWord16*) &pEfpwmBase->smcaptcompx);
			#endif
			
			#ifdef PWM_A_3_DMAEN_INIT
			periphMemWrite(PWM_A_3_DMAEN_INIT, (UWord16*) &pEfpwmBase->smdmaen);
			#endif
		}	/* if(pEfpwmBase == (arch_sEFPWMSubFracCaptModule*)EFPWM_A_SUB3) */
		else

	#endif /* EFPWM_A_SUB3_INIT_USED && defined(EFPWM_A_SUB3) */

	#if EFPWM_SUB0_INIT_USED && defined(EFPWM_SUB0) 

		if(pEfpwmBase == (arch_sEFPWMSubFracCaptModule*)EFPWM_SUB0)	
		{  
			#if PWM_0_USE_PWMVAL
				#ifdef PWM_0_VAL2_INIT
				periphMemWrite(PWM_0_VAL2_INIT, (UWord16*) &pEfpwmBase->smval2);
				#endif
				#ifdef PWM_0_FRACVAL2_INIT
				periphMemWrite(PWM_0_FRACVAL2_INIT, (UWord16*) &pEfpwmBase->smfracval2);
				#endif
				#ifdef PWM_0_VAL3_INIT
				periphMemWrite(PWM_0_VAL3_INIT, (UWord16*) &pEfpwmBase->smval3);
				#endif
				#ifdef PWM_0_FRACVAL3_INIT
				periphMemWrite(PWM_0_FRACVAL3_INIT, (UWord16*) &pEfpwmBase->smfracval3);
				#endif
				#ifdef PWM_0_VAL4_INIT
				periphMemWrite(PWM_0_VAL4_INIT, (UWord16*) &pEfpwmBase->smval4);
				#endif
				#ifdef PWM_0_FRACVAL4_INIT
				periphMemWrite(PWM_0_FRACVAL4_INIT, (UWord16*) &pEfpwmBase->smfracval4);
				#endif
				#ifdef PWM_0_VAL5_INIT
				periphMemWrite(PWM_0_VAL5_INIT, (UWord16*) &pEfpwmBase->smval5);
				#endif
				#ifdef PWM_0_FRACVAL5_INIT
				periphMemWrite(PWM_0_FRACVAL5_INIT, (UWord16*) &pEfpwmBase->smfracval5);
				#endif
			#endif

			#ifdef PWM_0_VAL1_INIT
			periphMemWrite(PWM_0_VAL1_INIT, (UWord16*) &pEfpwmBase->smval1);
			#endif

			#ifdef PWM_0_FRACVAL1_INIT
			periphMemWrite(PWM_0_FRACVAL1_INIT, (UWord16*) &pEfpwmBase->smfracval1);
			#endif

			#ifdef PWM_0_INIT_INIT
			periphMemWrite(PWM_0_INIT_INIT, (UWord16*) &pEfpwmBase->sminit);
			#endif

			#ifdef PWM_0_DTCNT0_INIT
			periphMemWrite(PWM_0_DTCNT0_INIT, (UWord16*) &pEfpwmBase->smdtcnt0);
			#endif

			#ifdef PWM_0_DTCNT1_INIT
			periphMemWrite(PWM_0_DTCNT1_INIT, (UWord16*) &pEfpwmBase->smdtcnt1);
			#endif

			#ifdef PWM_0_CTRL_INIT
			periphMemWrite(PWM_0_CTRL_INIT, (UWord16*) &pEfpwmBase->smctrl);
			#endif

			#ifdef PWM_0_CTRL2_INIT
			periphMemWrite(PWM_0_CTRL2_INIT, (UWord16*) &pEfpwmBase->smctrl2);
			#endif

			#ifdef PWM_0_INTEN_INIT
			periphMemWrite(PWM_0_INTEN_INIT, (UWord16*) &pEfpwmBase->sminten);
			#endif

			#ifdef PWM_0_TCTRL_INIT
			periphMemWrite(PWM_0_TCTRL_INIT, (UWord16*) &pEfpwmBase->smtctrl);
			#endif

			#ifdef PWM_0_DISMAP_INIT
			periphMemWrite(PWM_0_DISMAP_INIT, (UWord16*) &pEfpwmBase->smdismap);
			#endif

			#if EFPWM_VERSION >= 2
				#ifdef PWM_0_DISMAP0_INIT
				periphMemWrite(PWM_0_DISMAP0_INIT, (UWord16*) &pEfpwmBase->smdismap0);
				#endif
				
				#ifdef PWM_0_DISMAP1_INIT
				periphMemWrite(PWM_0_DISMAP1_INIT, (UWord16*) &pEfpwmBase->smdismap1);
				#endif
			#endif

			#ifdef PWM_0_FRCTRL_INIT
			periphMemWrite(PWM_0_FRCTRL_INIT, (UWord16*) &pEfpwmBase->smfrctrl);
			#endif

			#ifdef PWM_0_VAL0_INIT
			periphMemWrite(PWM_0_VAL0_INIT, (UWord16*) &pEfpwmBase->smval0);
			#endif

			#ifdef PWM_0_CAPTCTRLA_INIT
			periphMemWrite(PWM_0_CAPTCTRLA_INIT, (UWord16*) &pEfpwmBase->smcaptctrla);
			#endif

			#ifdef PWM_0_CAPTCOMPA_INIT
			periphMemWrite(PWM_0_CAPTCOMPA_INIT, (UWord16*) &pEfpwmBase->smcaptcompa);
			#endif

			#ifdef PWM_0_CAPTCTRLB_INIT
			periphMemWrite(PWM_0_CAPTCTRLB_INIT, (UWord16*) &pEfpwmBase->smcaptctrlb);
			#endif

			#ifdef PWM_0_CAPTCOMPB_INIT
			periphMemWrite(PWM_0_CAPTCOMPB_INIT, (UWord16*) &pEfpwmBase->smcaptcompb);
			#endif

			#ifdef PWM_0_CAPTCTRLX_INIT
			periphMemWrite(PWM_0_CAPTCTRLX_INIT, (UWord16*) &pEfpwmBase->smcaptctrlx);
			#endif

			#ifdef PWM_0_CAPTCOMPX_INIT
			periphMemWrite(PWM_0_CAPTCOMPX_INIT, (UWord16*) &pEfpwmBase->smcaptcompx);
			#endif
			
			#ifdef PWM_0_OCTRL_INIT
			periphMemWrite(PWM_0_OCTRL_INIT, (UWord16*) &pEfpwmBase->smoctrl);
			#endif

		}	/* if(pEfpwmBase == (arch_sEFPWMSubFracCaptModule*)EFPWM_SUB0) */
		else

	#endif

	#if EFPWM_SUB1_INIT_USED && defined(EFPWM_SUB1) 

		if(pEfpwmBase == EFPWM_SUB1)
		{  
			#if PWM_1_USE_PWMVAL
				#ifdef PWM_1_VAL2_INIT
				periphMemWrite(PWM_1_VAL2_INIT, (UWord16*) &pEfpwmBase->smval2);
				#endif
				#ifdef PWM_1_FRACVAL2_INIT
				periphMemWrite(PWM_1_FRACVAL2_INIT, (UWord16*) &pEfpwmBase->smfracval2);
				#endif
				#ifdef PWM_1_VAL3_INIT
				periphMemWrite(PWM_1_VAL3_INIT, (UWord16*) &pEfpwmBase->smval3);
				#endif
				#ifdef PWM_1_FRACVAL3_INIT
				periphMemWrite(PWM_1_FRACVAL3_INIT, (UWord16*) &pEfpwmBase->smfracval3);
				#endif
				#ifdef PWM_1_VAL4_INIT
				periphMemWrite(PWM_1_VAL4_INIT, (UWord16*) &pEfpwmBase->smval4);
				#endif
				#ifdef PWM_1_FRACVAL4_INIT
				periphMemWrite(PWM_1_FRACVAL4_INIT, (UWord16*) &pEfpwmBase->smfracval4);
				#endif
				#ifdef PWM_1_VAL5_INIT
				periphMemWrite(PWM_1_VAL5_INIT, (UWord16*) &pEfpwmBase->smval5);
				#endif
				#ifdef PWM_1_FRACVAL5_INIT
				periphMemWrite(PWM_1_FRACVAL5_INIT, (UWord16*) &pEfpwmBase->smfracval5);
				#endif
			#endif

			#ifdef PWM_1_VAL0_INIT
			periphMemWrite(PWM_1_VAL0_INIT, (UWord16*) &pEfpwmBase->smval0);
			#endif

			#ifdef PWM_1_VAL1_INIT
			periphMemWrite(PWM_1_VAL1_INIT, (UWord16*) &pEfpwmBase->smval1);
			#endif

			#ifdef PWM_1_FRACVAL1_INIT
			periphMemWrite(PWM_1_FRACVAL1_INIT, (UWord16*) &pEfpwmBase->smfracval1);
			#endif

			#ifdef PWM_1_INIT_INIT
			periphMemWrite(PWM_1_INIT_INIT, (UWord16*) &pEfpwmBase->sminit);
			#endif

			#ifdef PWM_1_CTRL_INIT
			periphMemWrite(PWM_1_CTRL_INIT, (UWord16*) &pEfpwmBase->smctrl);
			#endif

			#ifdef PWM_1_CTRL2_INIT
			periphMemWrite(PWM_1_CTRL2_INIT, (UWord16*) &pEfpwmBase->smctrl2);
			#endif

			#ifdef PWM_1_FRCTRL_INIT
			periphMemWrite(PWM_1_FRCTRL_INIT, (UWord16*) &pEfpwmBase->smfrctrl);
			#endif

			#ifdef PWM_1_OCTRL_INIT
			periphMemWrite(PWM_1_OCTRL_INIT, (UWord16*) &pEfpwmBase->smoctrl);
			#endif

			#ifdef PWM_1_INTEN_INIT
			periphMemWrite(PWM_1_INTEN_INIT, (UWord16*) &pEfpwmBase->sminten);
			#endif

			#ifdef PWM_1_TCTRL_INIT
			periphMemWrite(PWM_1_TCTRL_INIT, (UWord16*) &pEfpwmBase->smtctrl);
			#endif

			#ifdef PWM_1_DISMAP_INIT
			periphMemWrite(PWM_1_DISMAP_INIT, (UWord16*) &pEfpwmBase->smdismap);
			#endif

			#if EFPWM_VERSION >= 2
				#ifdef PWM_1_DISMAP0_INIT
				periphMemWrite(PWM_1_DISMAP0_INIT, (UWord16*) &pEfpwmBase->smdismap0); // smdismap changed to smdismap0. Needs to review it
				#endif

				#ifdef PWM_1_DISMAP1_INIT
				periphMemWrite(PWM_1_DISMAP1_INIT, (UWord16*) &pEfpwmBase->smdismap1); // new reg. comparing to Anguilla Black
				#endif
			#endif
			
			#ifdef PWM_1_DTCNT0_INIT
			periphMemWrite(PWM_1_DTCNT0_INIT, (UWord16*) &pEfpwmBase->smdtcnt0);
			#endif

			#ifdef PWM_1_DTCNT1_INIT
			periphMemWrite(PWM_1_DTCNT1_INIT, (UWord16*) &pEfpwmBase->smdtcnt1);
			#endif

			#if EFPWM_VERSION >= 2
				#ifdef PWM_1_CAPTCTRLA_INIT
				periphMemWrite(PWM_1_CAPTCTRLA_INIT, (UWord16*) &pEfpwmBase->smcaptctrla);
				#endif

				#ifdef PWM_1_CAPTCOMPA_INIT
				periphMemWrite(PWM_1_CAPTCOMPA_INIT, (UWord16*) &pEfpwmBase->smcaptcompa);
				#endif

				#ifdef PWM_1_CAPTCTRLB_INIT
				periphMemWrite(PWM_1_CAPTCTRLB_INIT, (UWord16*) &pEfpwmBase->smcaptctrlb);
				#endif

				#ifdef PWM_1_CAPTCOMPB_INIT
				periphMemWrite(PWM_1_CAPTCOMPB_INIT, (UWord16*) &pEfpwmBase->smcaptcompb);
				#endif

				#ifdef PWM_1_CAPTCTRLX_INIT
				periphMemWrite(PWM_1_CAPTCTRLX_INIT, (UWord16*) &pEfpwmBase->smcaptctrlx);
				#endif

				#ifdef PWM_1_CAPTCOMPX_INIT
				periphMemWrite(PWM_1_CAPTCOMPX_INIT, (UWord16*) &pEfpwmBase->smcaptcompx);
				#endif
			#endif /*  EFPWM_VERSION >= 2 */
		}	/* if(pEfpwmBase == (arch_sEFPWMSubFracCaptModule*)EFPWM_SUB1) */
		else

	#endif

	#if EFPWM_SUB2_INIT_USED && defined(EFPWM_SUB2) 

		if(pEfpwmBase == EFPWM_SUB2)
		{  
			#if PWM_2_USE_PWMVAL
				#ifdef PWM_2_VAL2_INIT
				periphMemWrite(PWM_2_VAL2_INIT, (UWord16*) &pEfpwmBase->smval2);
				#endif
				#ifdef PWM_2_FRACVAL2_INIT
				periphMemWrite(PWM_2_FRACVAL2_INIT, (UWord16*) &pEfpwmBase->smfracval2);
				#endif
				#ifdef PWM_2_VAL3_INIT
				periphMemWrite(PWM_2_VAL3_INIT, (UWord16*) &pEfpwmBase->smval3);
				#endif
				#ifdef PWM_2_FRACVAL3_INIT
				periphMemWrite(PWM_2_FRACVAL3_INIT, (UWord16*) &pEfpwmBase->smfracval3);
				#endif
				#ifdef PWM_2_VAL4_INIT
				periphMemWrite(PWM_2_VAL4_INIT, (UWord16*) &pEfpwmBase->smval4);
				#endif
				#ifdef PWM_2_FRACVAL4_INIT
				periphMemWrite(PWM_2_FRACVAL4_INIT, (UWord16*) &pEfpwmBase->smfracval4);
				#endif
				#ifdef PWM_2_VAL5_INIT
				periphMemWrite(PWM_2_VAL5_INIT, (UWord16*) &pEfpwmBase->smval5);
				#endif
				#ifdef PWM_2_FRACVAL5_INIT
				periphMemWrite(PWM_2_FRACVAL5_INIT, (UWord16*) &pEfpwmBase->smfracval5);
				#endif
			#endif

			#ifdef PWM_2_VAL0_INIT
			periphMemWrite(PWM_2_VAL0_INIT, (UWord16*) &pEfpwmBase->smval0);
			#endif

			#ifdef PWM_2_VAL1_INIT
			periphMemWrite(PWM_2_VAL1_INIT, (UWord16*) &pEfpwmBase->smval1);
			#endif

			#ifdef PWM_2_FRACVAL1_INIT
			periphMemWrite(PWM_2_FRACVAL1_INIT, (UWord16*) &pEfpwmBase->smfracval1);
			#endif

			#ifdef PWM_2_INIT_INIT
			periphMemWrite(PWM_2_INIT_INIT, (UWord16*) &pEfpwmBase->sminit);
			#endif

			#ifdef PWM_2_CTRL_INIT
			periphMemWrite(PWM_2_CTRL_INIT, (UWord16*) &pEfpwmBase->smctrl);
			#endif

			#ifdef PWM_2_CTRL2_INIT
			periphMemWrite(PWM_2_CTRL2_INIT, (UWord16*) &pEfpwmBase->smctrl2);
			#endif

			#ifdef PWM_2_FRCTRL_INIT
			periphMemWrite(PWM_2_FRCTRL_INIT, (UWord16*) &pEfpwmBase->smfrctrl);
			#endif

			#ifdef PWM_2_OCTRL_INIT
			periphMemWrite(PWM_2_OCTRL_INIT, (UWord16*) &pEfpwmBase->smoctrl);
			#endif

			#ifdef PWM_2_INTEN_INIT
			periphMemWrite(PWM_2_INTEN_INIT, (UWord16*) &pEfpwmBase->sminten);
			#endif

			#ifdef PWM_2_TCTRL_INIT
			periphMemWrite(PWM_2_TCTRL_INIT, (UWord16*) &pEfpwmBase->smtctrl);
			#endif

			#ifdef PWM_2_DISMAP_INIT
			periphMemWrite(PWM_2_DISMAP_INIT, (UWord16*) &pEfpwmBase->smdismap);
			#endif

			#if EFPWM_VERSION >= 2		
				#ifdef PWM_2_DISMAP0_INIT
				periphMemWrite(PWM_2_DISMAP0_INIT, (UWord16*) &pEfpwmBase->smdismap0);  // sdmdismap changed to sdmdismap0. Needs to review it
				#endif

				#ifdef PWM_2_DISMAP1_INIT
				periphMemWrite(PWM_2_DISMAP1_INIT, (UWord16*) &pEfpwmBase->smdismap1);  // new reg. comparing to Anguilla Black it
				#endif
			#endif
			
			#ifdef PWM_2_DTCNT0_INIT
			periphMemWrite(PWM_2_DTCNT0_INIT, (UWord16*) &pEfpwmBase->smdtcnt0);
			#endif

			#ifdef PWM_2_DTCNT1_INIT
			periphMemWrite(PWM_2_DTCNT1_INIT, (UWord16*) &pEfpwmBase->smdtcnt1);
			#endif
			
			#if EFPWM_VERSION >= 2
				#ifdef PWM_2_CAPTCTRLA_INIT
				periphMemWrite(PWM_2_CAPTCTRLA_INIT, (UWord16*) &pEfpwmBase->smcaptctrla);
				#endif

				#ifdef PWM_2_CAPTCOMPA_INIT
				periphMemWrite(PWM_2_CAPTCOMPA_INIT, (UWord16*) &pEfpwmBase->smcaptcompa);
				#endif

				#ifdef PWM_2_CAPTCTRLB_INIT
				periphMemWrite(PWM_2_CAPTCTRLB_INIT, (UWord16*) &pEfpwmBase->smcaptctrlb);
				#endif

				#ifdef PWM_2_CAPTCOMPB_INIT
				periphMemWrite(PWM_2_CAPTCOMPB_INIT, (UWord16*) &pEfpwmBase->smcaptcompb);
				#endif

				#ifdef PWM_2_CAPTCTRLX_INIT
				periphMemWrite(PWM_2_CAPTCTRLX_INIT, (UWord16*) &pEfpwmBase->smcaptctrlx);
				#endif

				#ifdef PWM_2_CAPTCOMPX_INIT
				periphMemWrite(PWM_2_CAPTCOMPX_INIT, (UWord16*) &pEfpwmBase->smcaptcompx);
				#endif
			#endif
		}	/* if(pEfpwmBase == (arch_sEFPWMSubFracCaptModule*)EFPWM_SUB2) */
		else

	#endif

	#if EFPWM_VERSION >= 2
		#if EFPWM_SUB3_INIT_USED && defined(EFPWM_SUB3) 

		if(pEfpwmBase == (arch_sEFPWMSubFracCaptModule*)EFPWM_SUB3)
		{
			#if PWM_3_USE_PWMVAL
				#ifdef PWM_3_VAL2_INIT
				periphMemWrite(PWM_3_VAL2_INIT, (UWord16*) &pEfpwmBase->smval2);
				#endif
				#ifdef PWM_3_FRACVAL2_INIT
				periphMemWrite(PWM_3_FRACVAL2_INIT, (UWord16*) &pEfpwmBase->smfracval2);
				#endif
				#ifdef PWM_3_VAL3_INIT
				periphMemWrite(PWM_3_VAL3_INIT, (UWord16*) &pEfpwmBase->smval3);
				#endif
				#ifdef PWM_3_FRACVAL3_INIT
				periphMemWrite(PWM_3_FRACVAL3_INIT, (UWord16*) &pEfpwmBase->smfracval3);
				#endif
				#ifdef PWM_3_VAL4_INIT
				periphMemWrite(PWM_3_VAL4_INIT, (UWord16*) &pEfpwmBase->smval4);
				#endif
				#ifdef PWM_3_FRACVAL4_INIT
				periphMemWrite(PWM_3_FRACVAL4_INIT, (UWord16*) &pEfpwmBase->smfracval4);
				#endif
				#ifdef PWM_3_VAL5_INIT
				periphMemWrite(PWM_3_VAL5_INIT, (UWord16*) &pEfpwmBase->smval5);
				#endif
				#ifdef PWM_3_FRACVAL5_INIT
				periphMemWrite(PWM_3_FRACVAL5_INIT, (UWord16*) &pEfpwmBase->smfracval5);
				#endif
			#endif

			#ifdef PWM_3_VAL0_INIT
			periphMemWrite(PWM_3_VAL0_INIT, (UWord16*) &pEfpwmBase->smval0);
			#endif

			#ifdef PWM_3_VAL1_INIT
			periphMemWrite(PWM_3_VAL1_INIT, (UWord16*) &pEfpwmBase->smval1);
			#endif

			#ifdef PWM_3_FRACVAL1_INIT
			periphMemWrite(PWM_3_FRACVAL1_INIT, (UWord16*) &pEfpwmBase->smfracval1);
			#endif

			#ifdef PWM_3_INIT_INIT
			periphMemWrite(PWM_3_INIT_INIT, (UWord16*) &pEfpwmBase->sminit);
			#endif

			#ifdef PWM_3_CTRL_INIT
			periphMemWrite(PWM_3_CTRL_INIT, (UWord16*) &pEfpwmBase->smctrl);
			#endif

			#ifdef PWM_3_CTRL2_INIT
			periphMemWrite(PWM_3_CTRL2_INIT, (UWord16*) &pEfpwmBase->smctrl2);
			#endif

			#ifdef PWM_3_FRCTRL_INIT
			periphMemWrite(PWM_3_FRCTRL_INIT, (UWord16*) &pEfpwmBase->smfrctrl);
			#endif

			#ifdef PWM_3_OCTRL_INIT
			periphMemWrite(PWM_3_OCTRL_INIT, (UWord16*) &pEfpwmBase->smoctrl);
			#endif

			#ifdef PWM_3_INTEN_INIT
			periphMemWrite(PWM_3_INTEN_INIT, (UWord16*) &pEfpwmBase->sminten);
			#endif

			#ifdef PWM_3_TCTRL_INIT
			periphMemWrite(PWM_3_TCTRL_INIT, (UWord16*) &pEfpwmBase->smtctrl);
			#endif

			#ifdef PWM_3_DISMAP_INIT /* LP */
			periphMemWrite(PWM_3_DISMAP_INIT, (UWord16*) &pEfpwmBase->smdismap);
			#endif
			
			#ifdef PWM_3_DISMAP0_INIT
			periphMemWrite(PWM_3_DISMAP0_INIT, (UWord16*) &pEfpwmBase->smdismap0); // smdismap changed to smdismap0. Needs to review it
			#endif

			#ifdef PWM_3_DISMAP1_INIT
			periphMemWrite(PWM_3_DISMAP1_INIT, (UWord16*) &pEfpwmBase->smdismap1); // new reg. comparing to Anguilla Black
			#endif
			
			#ifdef PWM_3_DTCNT0_INIT
			periphMemWrite(PWM_3_DTCNT0_INIT, (UWord16*) &pEfpwmBase->smdtcnt0);
			#endif

			#ifdef PWM_3_DTCNT1_INIT
			periphMemWrite(PWM_3_DTCNT1_INIT, (UWord16*) &pEfpwmBase->smdtcnt1);
			#endif

			#ifdef PWM_3_CAPTCTRLA_INIT
			periphMemWrite(PWM_3_CAPTCTRLA_INIT, (UWord16*) &pEfpwmBase->smcaptctrla);
			#endif

			#ifdef PWM_3_CAPTCOMPA_INIT
			periphMemWrite(PWM_3_CAPTCOMPA_INIT, (UWord16*) &pEfpwmBase->smcaptcompa);
			#endif

			#ifdef PWM_3_CAPTCTRLB_INIT
			periphMemWrite(PWM_3_CAPTCTRLB_INIT, (UWord16*) &pEfpwmBase->smcaptctrlb);
			#endif

			#ifdef PWM_3_CAPTCOMPB_INIT
			periphMemWrite(PWM_3_CAPTCOMPB_INIT, (UWord16*) &pEfpwmBase->smcaptcompb);
			#endif

			#ifdef PWM_3_CAPTCTRLX_INIT
			periphMemWrite(PWM_3_CAPTCTRLX_INIT, (UWord16*) &pEfpwmBase->smcaptctrlx);
			#endif

			#ifdef PWM_3_CAPTCOMPX_INIT
			periphMemWrite(PWM_3_CAPTCOMPX_INIT, (UWord16*) &pEfpwmBase->smcaptcompx);
			#endif
		}	/* if(pEfpwmBase == (arch_sEFPWMSubFracCaptModule*)EFPWM_SUB3) */
		else
		#endif	/* EFPWM_SUB3_INIT_USED && defined(EFPWM_SUB3) */
	#endif	/* EFPWM_VERSION >= 2 */
	; /* last else case */
}


#if EFPWM_VERSION == 1
void efpwmSubCaptInit(arch_sEFPWMSubCaptModule *pEfpwmBase)
{
	#pragma unused(pEfpwmBase)

	#if EFPWM_SUB3_INIT_USED && defined(EFPWM_SUB3) 

		if(pEfpwmBase == EFPWM_SUB3)
		{  
			#if PWM_3_USE_PWMVAL
				#ifdef PWM_3_VAL2_INIT
				periphMemWrite(PWM_3_VAL2_INIT, (UWord16*) &pEfpwmBase->smval2);
				#endif
				#ifdef PWM_3_VAL3_INIT
				periphMemWrite(PWM_3_VAL3_INIT, (UWord16*) &pEfpwmBase->smval3);
				#endif
				#ifdef PWM_3_VAL4_INIT
				periphMemWrite(PWM_3_VAL4_INIT, (UWord16*) &pEfpwmBase->smval4);
				#endif
				#ifdef PWM_3_VAL5_INIT
				periphMemWrite(PWM_3_VAL5_INIT, (UWord16*) &pEfpwmBase->smval5);
				#endif
			#endif

			#ifdef PWM_3_VAL1_INIT
			periphMemWrite(PWM_3_VAL1_INIT, (UWord16*) &pEfpwmBase->smval1);
			#endif

			#ifdef PWM_3_INIT_INIT
			periphMemWrite(PWM_3_INIT_INIT, (UWord16*) &pEfpwmBase->sminit);
			#endif

			#ifdef PWM_3_DISMAP_INIT
			periphMemWrite(PWM_3_DISMAP_INIT, (UWord16*) &pEfpwmBase->smdismap);
			#endif

			#ifdef PWM_3_DTCNT0_INIT
			periphMemWrite(PWM_3_DTCNT0_INIT, (UWord16*) &pEfpwmBase->smdtcnt0);
			#endif

			#ifdef PWM_3_DTCNT1_INIT
			periphMemWrite(PWM_3_DTCNT1_INIT, (UWord16*) &pEfpwmBase->smdtcnt1);
			#endif

			#ifdef PWM_3_CTRL_INIT
			periphMemWrite(PWM_3_CTRL_INIT, (UWord16*) &pEfpwmBase->smctrl);
			#endif

			#ifdef PWM_3_CTRL2_INIT
			periphMemWrite(PWM_3_CTRL2_INIT, (UWord16*) &pEfpwmBase->smctrl2);
			#endif

			#ifdef PWM_3_INTEN_INIT
			periphMemWrite(PWM_3_INTEN_INIT, (UWord16*) &pEfpwmBase->sminten);
			#endif

			#ifdef PWM_3_TCTRL_INIT
			periphMemWrite(PWM_3_TCTRL_INIT, (UWord16*) &pEfpwmBase->smtctrl);
			#endif


			#ifdef PWM_3_VAL0_INIT
			periphMemWrite(PWM_3_VAL0_INIT, (UWord16*) &pEfpwmBase->smval0);
			#endif

			#ifdef PWM_3_CAPTCTRLA_INIT
			periphMemWrite(PWM_3_CAPTCTRLA_INIT, (UWord16*) &pEfpwmBase->smcaptctrla);
			#endif

			#ifdef PWM_3_CAPTCOMPA_INIT
			periphMemWrite(PWM_3_CAPTCOMPA_INIT, (UWord16*) &pEfpwmBase->smcaptcompa);
			#endif

			#ifdef PWM_3_CAPTCTRLB_INIT
			periphMemWrite(PWM_3_CAPTCTRLB_INIT, (UWord16*) &pEfpwmBase->smcaptctrlb);
			#endif

			#ifdef PWM_3_CAPTCOMPB_INIT
			periphMemWrite(PWM_3_CAPTCOMPB_INIT, (UWord16*) &pEfpwmBase->smcaptcompb);
			#endif

			#ifdef PWM_3_CAPTCTRLX_INIT
			periphMemWrite(PWM_3_CAPTCTRLX_INIT, (UWord16*) &pEfpwmBase->smcaptctrlx);
			#endif

			#ifdef PWM_3_CAPTCOMPX_INIT
			periphMemWrite(PWM_3_CAPTCOMPX_INIT, (UWord16*) &pEfpwmBase->smcaptcompx);
			#endif

			#ifdef PWM_3_OCTRL_INIT
			periphMemWrite(PWM_3_OCTRL_INIT, (UWord16*) &pEfpwmBase->smoctrl);
			#endif

		}
		else
	#endif  /* EFPWM_SUB3_INIT_USED && defined(EFPWM_SUB3) */
#endif	/*  EFPWM_VERSION == 1 */  
	  
#if defined(EFPWM_B) 	  
  void efpwmBSubCaptInit(arch_sEFPWMBSubCaptModule *pEfpwmBase)
  {
  #pragma unused(pEfpwmBase)
	#if EFPWM_B_SUB0_INIT_USED && defined(EFPWM_B_SUB0) 

		if(pEfpwmBase == (arch_sEFPWMBSubCaptModule*)EFPWM_B_SUB0)
		{  
			#if PWM_B_0_USE_PWMVAL
				#ifdef PWM_B_0_VAL2_INIT
				periphMemWrite(PWM_B_0_VAL2_INIT, (UWord16*) &pEfpwmBase->smval2);
				#endif
				#ifdef PWM_B_0_VAL3_INIT
				periphMemWrite(PWM_B_0_VAL3_INIT, (UWord16*) &pEfpwmBase->smval3);
				#endif
				#ifdef PWM_B_0_VAL4_INIT
				periphMemWrite(PWM_B_0_VAL4_INIT, (UWord16*) &pEfpwmBase->smval4);
				#endif
				#ifdef PWM_B_0_VAL5_INIT
				periphMemWrite(PWM_B_0_VAL5_INIT, (UWord16*) &pEfpwmBase->smval5);
				#endif
			#endif

			#ifdef PWM_B_0_VAL1_INIT //
			periphMemWrite(PWM_B_0_VAL1_INIT, (UWord16*) &pEfpwmBase->smval1);
			#endif

			#ifdef PWM_B_0_INIT_INIT //
			periphMemWrite(PWM_B_0_INIT_INIT, (UWord16*) &pEfpwmBase->sminit);
			#endif

			#ifdef PWM_B_0_DTCNT0_INIT //
			periphMemWrite(PWM_B_0_DTCNT0_INIT, (UWord16*) &pEfpwmBase->smdtcnt0);
			#endif

			#ifdef PWM_B_0_DTCNT1_INIT //
			periphMemWrite(PWM_B_0_DTCNT1_INIT, (UWord16*) &pEfpwmBase->smdtcnt1);
			#endif

			#ifdef PWM_B_0_CTRL_INIT //
			periphMemWrite(PWM_B_0_CTRL_INIT, (UWord16*) &pEfpwmBase->smctrl);
			#endif

			#ifdef PWM_B_0_CTRL2_INIT //
			periphMemWrite(PWM_B_0_CTRL2_INIT, (UWord16*) &pEfpwmBase->smctrl2);
			#endif

			#ifdef PWM_B_0_INTEN_INIT  //
			periphMemWrite(PWM_B_0_INTEN_INIT, (UWord16*) &pEfpwmBase->sminten);
			#endif

			#ifdef PWM_B_0_TCTRL_INIT //
			periphMemWrite(PWM_B_0_TCTRL_INIT, (UWord16*) &pEfpwmBase->smtctrl);
			#endif

			#ifdef PWM_B_0_DISMAP_INIT /* LP */
			periphMemWrite(PWM_B_0_DISMAP_INIT, (UWord16*) &pEfpwmBase->smdismap);
			#endif
			
			#ifdef PWM_B_0_DISMAP0_INIT // new name of reg
			periphMemWrite(PWM_B_0_DISMAP0_INIT, (UWord16*) &pEfpwmBase->smdismap0);
			#endif
			
			#ifdef PWM_B_0_DISMAP1_INIT // new reg
			periphMemWrite(PWM_B_0_DISMAP1_INIT, (UWord16*) &pEfpwmBase->smdismap1);
			#endif

			#ifdef PWM_B_0_VAL0_INIT //
			periphMemWrite(PWM_B_0_VAL0_INIT, (UWord16*) &pEfpwmBase->smval0);
			#endif

			#ifdef PWM_B_0_CAPTCTRLA_INIT
			periphMemWrite(PWM_B_0_CAPTCTRLA_INIT, (UWord16*) &pEfpwmBase->smcaptctrla);
			#endif

			#ifdef PWM_B_0_CAPTCOMPA_INIT
			periphMemWrite(PWM_B_0_CAPTCOMPA_INIT, (UWord16*) &pEfpwmBase->smcaptcompa);
			#endif

			#ifdef PWM_B_0_CAPTCTRLB_INIT
			periphMemWrite(PWM_B_0_CAPTCTRLB_INIT, (UWord16*) &pEfpwmBase->smcaptctrlb);
			#endif

			#ifdef PWM_B_0_CAPTCOMPB_INIT
			periphMemWrite(PWM_B_0_CAPTCOMPB_INIT, (UWord16*) &pEfpwmBase->smcaptcompb);
			#endif

			#ifdef PWM_B_0_CAPTCTRLX_INIT
			periphMemWrite(PWM_B_0_CAPTCTRLX_INIT, (UWord16*) &pEfpwmBase->smcaptctrlx);
			#endif

			#ifdef PWM_B_0_CAPTCOMPX_INIT
			periphMemWrite(PWM_B_0_CAPTCOMPX_INIT, (UWord16*) &pEfpwmBase->smcaptcompx);
			#endif
			
			#ifdef PWM_B_0_OCTRL_INIT //
			periphMemWrite(PWM_B_0_OCTRL_INIT, (UWord16*) &pEfpwmBase->smoctrl);
			#endif

			#ifdef PWM_B_0_DMAEN_INIT
			periphMemWrite(PWM_B_0_DMAEN_INIT, (UWord16*) &pEfpwmBase->smdmaen);
			#endif
		}
		else

	#endif /* EFPWM_B_SUB0_INIT_USED && defined(EFPWM_B_SUB0)  */

	#if EFPWM_B_SUB1_INIT_USED && defined(EFPWM_B_SUB1) 

		if(pEfpwmBase == (arch_sEFPWMBSubCaptModule*)EFPWM_B_SUB1)
		{  
			#if PWM_B_1_USE_PWMVAL
				#ifdef PWM_B_1_VAL2_INIT
				periphMemWrite(PWM_B_1_VAL2_INIT, (UWord16*) &pEfpwmBase->smval2);
				#endif
				#ifdef PWM_B_1_VAL3_INIT
				periphMemWrite(PWM_B_1_VAL3_INIT, (UWord16*) &pEfpwmBase->smval3);
				#endif
				#ifdef PWM_B_1_VAL4_INIT
				periphMemWrite(PWM_B_1_VAL4_INIT, (UWord16*) &pEfpwmBase->smval4);
				#endif
				#ifdef PWM_B_1_VAL5_INIT
				periphMemWrite(PWM_B_1_VAL5_INIT, (UWord16*) &pEfpwmBase->smval5);
				#endif
			#endif

			#ifdef PWM_B_1_VAL0_INIT
			periphMemWrite(PWM_B_1_VAL0_INIT, (UWord16*) &pEfpwmBase->smval0);
			#endif

			#ifdef PWM_B_1_VAL1_INIT
			periphMemWrite(PWM_B_1_VAL1_INIT, (UWord16*) &pEfpwmBase->smval1);
			#endif

			#ifdef PWM_B_1_INIT_INIT
			periphMemWrite(PWM_B_1_INIT_INIT, (UWord16*) &pEfpwmBase->sminit);
			#endif

			#ifdef PWM_B_1_CTRL_INIT
			periphMemWrite(PWM_B_1_CTRL_INIT, (UWord16*) &pEfpwmBase->smctrl);
			#endif

			#ifdef PWM_B_1_CTRL2_INIT
			periphMemWrite(PWM_B_1_CTRL2_INIT, (UWord16*) &pEfpwmBase->smctrl2);
			#endif

			#ifdef PWM_B_1_OCTRL_INIT
			periphMemWrite(PWM_B_1_OCTRL_INIT, (UWord16*) &pEfpwmBase->smoctrl);
			#endif

			#ifdef PWM_B_1_INTEN_INIT
			periphMemWrite(PWM_B_1_INTEN_INIT, (UWord16*) &pEfpwmBase->sminten);
			#endif

			#ifdef PWM_B_1_TCTRL_INIT
			periphMemWrite(PWM_B_1_TCTRL_INIT, (UWord16*) &pEfpwmBase->smtctrl);
			#endif

			#ifdef PWM_B_1_DISMAP_INIT /* LP */
			periphMemWrite(PWM_B_1_DISMAP_INIT, (UWord16*) &pEfpwmBase->smdismap);
			#endif
			
			#ifdef PWM_B_1_DISMAP0_INIT
			periphMemWrite(PWM_B_1_DISMAP0_INIT, (UWord16*) &pEfpwmBase->smdismap0); // smdismap changed to smdismap0. Needs to review it
			#endif

			#ifdef PWM_B_1_DISMAP1_INIT
			periphMemWrite(PWM_B_1_DISMAP1_INIT, (UWord16*) &pEfpwmBase->smdismap1); // new reg. comparing to Anguilla Black
			#endif
			
			#ifdef PWM_B_1_DTCNT0_INIT
			periphMemWrite(PWM_B_1_DTCNT0_INIT, (UWord16*) &pEfpwmBase->smdtcnt0);
			#endif

			#ifdef PWM_B_1_DTCNT1_INIT
			periphMemWrite(PWM_B_1_DTCNT1_INIT, (UWord16*) &pEfpwmBase->smdtcnt1);
			#endif
			
			#ifdef PWM_B_1_CAPTCTRLA_INIT
			periphMemWrite(PWM_B_1_CAPTCTRLA_INIT, (UWord16*) &pEfpwmBase->smcaptctrla);
			#endif

			#ifdef PWM_B_1_CAPTCOMPA_INIT
			periphMemWrite(PWM_B_1_CAPTCOMPA_INIT, (UWord16*) &pEfpwmBase->smcaptcompa);
			#endif

			#ifdef PWM_B_1_CAPTCTRLB_INIT
			periphMemWrite(PWM_B_1_CAPTCTRLB_INIT, (UWord16*) &pEfpwmBase->smcaptctrlb);
			#endif

			#ifdef PWM_B_1_CAPTCOMPB_INIT
			periphMemWrite(PWM_B_1_CAPTCOMPB_INIT, (UWord16*) &pEfpwmBase->smcaptcompb);
			#endif

			#ifdef PWM_B_1_CAPTCTRLX_INIT
			periphMemWrite(PWM_B_1_CAPTCTRLX_INIT, (UWord16*) &pEfpwmBase->smcaptctrlx);
			#endif

			#ifdef PWM_B_1_CAPTCOMPX_INIT
			periphMemWrite(PWM_B_1_CAPTCOMPX_INIT, (UWord16*) &pEfpwmBase->smcaptcompx);
			#endif
			
			#ifdef PWM_B_1_DMAEN_INIT
			periphMemWrite(PWM_B_1_DMAEN_INIT, (UWord16*) &pEfpwmBase->smdmaen);
			#endif
		}
		else

	#endif  /* EFPWM_B_SUB1_INIT_USED && defined(EFPWM_B_SUB1)  */

	#if EFPWM_B_SUB2_INIT_USED && defined(EFPWM_B_SUB2) 

		if(pEfpwmBase == (arch_sEFPWMBSubCaptModule*)EFPWM_B_SUB2)
		{  
			#if PWM_B_2_USE_PWMVAL
				#ifdef PWM_B_2_VAL2_INIT
				periphMemWrite(PWM_B_2_VAL2_INIT, (UWord16*) &pEfpwmBase->smval2);
				#endif
				#ifdef PWM_B_2_VAL3_INIT
				periphMemWrite(PWM_B_2_VAL3_INIT, (UWord16*) &pEfpwmBase->smval3);
				#endif
				#ifdef PWM_B_2_VAL4_INIT
				periphMemWrite(PWM_B_2_VAL4_INIT, (UWord16*) &pEfpwmBase->smval4);
				#endif
				#ifdef PWM_B_2_VAL5_INIT
				periphMemWrite(PWM_B_2_VAL5_INIT, (UWord16*) &pEfpwmBase->smval5);
				#endif
			#endif

			#ifdef PWM_B_2_VAL0_INIT
			periphMemWrite(PWM_B_2_VAL0_INIT, (UWord16*) &pEfpwmBase->smval0);
			#endif

			#ifdef PWM_B_2_VAL1_INIT
			periphMemWrite(PWM_B_2_VAL1_INIT, (UWord16*) &pEfpwmBase->smval1);
			#endif

			#ifdef PWM_B_2_INIT_INIT
			periphMemWrite(PWM_B_2_INIT_INIT, (UWord16*) &pEfpwmBase->sminit);
			#endif

			#ifdef PWM_B_2_CTRL_INIT
			periphMemWrite(PWM_B_2_CTRL_INIT, (UWord16*) &pEfpwmBase->smctrl);
			#endif

			#ifdef PWM_B_2_CTRL2_INIT
			periphMemWrite(PWM_B_2_CTRL2_INIT, (UWord16*) &pEfpwmBase->smctrl2);
			#endif

			#ifdef PWM_B_2_OCTRL_INIT
			periphMemWrite(PWM_B_2_OCTRL_INIT, (UWord16*) &pEfpwmBase->smoctrl);
			#endif

			#ifdef PWM_B_2_INTEN_INIT
			periphMemWrite(PWM_B_2_INTEN_INIT, (UWord16*) &pEfpwmBase->sminten);
			#endif

			#ifdef PWM_B_2_TCTRL_INIT
			periphMemWrite(PWM_B_2_TCTRL_INIT, (UWord16*) &pEfpwmBase->smtctrl);
			#endif

			#ifdef PWM_B_2_DISMAP_INIT /* LP */
			periphMemWrite(PWM_B_2_DISMAP_INIT, (UWord16*) &pEfpwmBase->smdismap);
			#endif
			
			#ifdef PWM_B_2_DISMAP0_INIT
			periphMemWrite(PWM_B_2_DISMAP0_INIT, (UWord16*) &pEfpwmBase->smdismap0);  // sdmdismap changed to sdmdismap0. Needs to review it
			#endif

			#ifdef PWM_B_2_DISMAP1_INIT
			periphMemWrite(PWM_B_2_DISMAP1_INIT, (UWord16*) &pEfpwmBase->smdismap1);  // new reg. comparing to Anguilla Black it
			#endif
			
			#ifdef PWM_B_2_DTCNT0_INIT
			periphMemWrite(PWM_B_2_DTCNT0_INIT, (UWord16*) &pEfpwmBase->smdtcnt0);
			#endif

			#ifdef PWM_B_2_DTCNT1_INIT
			periphMemWrite(PWM_B_2_DTCNT1_INIT, (UWord16*) &pEfpwmBase->smdtcnt1);
			#endif
			
			#ifdef PWM_B_2_CAPTCTRLA_INIT
			periphMemWrite(PWM_B_2_CAPTCTRLA_INIT, (UWord16*) &pEfpwmBase->smcaptctrla);
			#endif

			#ifdef PWM_B_2_CAPTCOMPA_INIT
			periphMemWrite(PWM_B_2_CAPTCOMPA_INIT, (UWord16*) &pEfpwmBase->smcaptcompa);
			#endif

			#ifdef PWM_B_2_CAPTCTRLB_INIT
			periphMemWrite(PWM_B_2_CAPTCTRLB_INIT, (UWord16*) &pEfpwmBase->smcaptctrlb);
			#endif

			#ifdef PWM_B_2_CAPTCOMPB_INIT
			periphMemWrite(PWM_B_2_CAPTCOMPB_INIT, (UWord16*) &pEfpwmBase->smcaptcompb);
			#endif

			#ifdef PWM_B_2_CAPTCTRLX_INIT
			periphMemWrite(PWM_B_2_CAPTCTRLX_INIT, (UWord16*) &pEfpwmBase->smcaptctrlx);
			#endif

			#ifdef PWM_B_2_CAPTCOMPX_INIT
			periphMemWrite(PWM_B_2_CAPTCOMPX_INIT, (UWord16*) &pEfpwmBase->smcaptcompx);
			#endif
			
			#ifdef PWM_B_2_DMAEN_INIT
			periphMemWrite(PWM_B_2_DMAEN_INIT, (UWord16*) &pEfpwmBase->smdmaen);
			#endif
		}
		else

	#endif  /* EFPWM_B_SUB2_INIT_USED && defined(EFPWM_B_SUB2)  */
	  
	#if EFPWM_B_SUB3_INIT_USED && defined(EFPWM_B_SUB3) 

		if(pEfpwmBase == (arch_sEFPWMBSubCaptModule*)EFPWM_B_SUB3)
		{  
			#if PWM_B_3_USE_PWMVAL
				#ifdef PWM_B_3_VAL2_INIT
				periphMemWrite(PWM_B_3_VAL2_INIT, (UWord16*) &pEfpwmBase->smval2);
				#endif
				#ifdef PWM_B_3_VAL3_INIT
				periphMemWrite(PWM_B_3_VAL3_INIT, (UWord16*) &pEfpwmBase->smval3);
				#endif
				#ifdef PWM_B_3_VAL4_INIT
				periphMemWrite(PWM_B_3_VAL4_INIT, (UWord16*) &pEfpwmBase->smval4);
				#endif
				#ifdef PWM_B_3_VAL5_INIT
				periphMemWrite(PWM_B_3_VAL5_INIT, (UWord16*) &pEfpwmBase->smval5);
				#endif
			#endif

			#ifdef PWM_B_3_VAL0_INIT
			periphMemWrite(PWM_B_3_VAL0_INIT, (UWord16*) &pEfpwmBase->smval0);
			#endif

			#ifdef PWM_B_3_VAL1_INIT
			periphMemWrite(PWM_B_3_VAL1_INIT, (UWord16*) &pEfpwmBase->smval1);
			#endif

			#ifdef PWM_B_3_INIT_INIT
			periphMemWrite(PWM_B_3_INIT_INIT, (UWord16*) &pEfpwmBase->sminit);
			#endif

			#ifdef PWM_B_3_CTRL_INIT
			periphMemWrite(PWM_B_3_CTRL_INIT, (UWord16*) &pEfpwmBase->smctrl);
			#endif

			#ifdef PWM_B_3_CTRL2_INIT
			periphMemWrite(PWM_B_3_CTRL2_INIT, (UWord16*) &pEfpwmBase->smctrl2);
			#endif

			#ifdef PWM_B_3_OCTRL_INIT
			periphMemWrite(PWM_B_3_OCTRL_INIT, (UWord16*) &pEfpwmBase->smoctrl);
			#endif

			#ifdef PWM_B_3_INTEN_INIT
			periphMemWrite(PWM_B_3_INTEN_INIT, (UWord16*) &pEfpwmBase->sminten);
			#endif

			#ifdef PWM_B_3_TCTRL_INIT
			periphMemWrite(PWM_B_3_TCTRL_INIT, (UWord16*) &pEfpwmBase->smtctrl);
			#endif

			#ifdef PWM_B_3_DISMAP_INIT /* LP */
			periphMemWrite(PWM_B_3_DISMAP_INIT, (UWord16*) &pEfpwmBase->smdismap);
			#endif
			
			#ifdef PWM_B_3_DISMAP0_INIT
			periphMemWrite(PWM_B_3_DISMAP0_INIT, (UWord16*) &pEfpwmBase->smdismap0); // smdismap changed to smdismap0. Needs to review it
			#endif

			#ifdef PWM_B_3_DISMAP1_INIT
			periphMemWrite(PWM_B_3_DISMAP1_INIT, (UWord16*) &pEfpwmBase->smdismap1); // new reg. comparing to Anguilla Black
			#endif
			
			#ifdef PWM_B_3_DTCNT0_INIT
			periphMemWrite(PWM_B_3_DTCNT0_INIT, (UWord16*) &pEfpwmBase->smdtcnt0);
			#endif

			#ifdef PWM_B_3_DTCNT1_INIT
			periphMemWrite(PWM_B_3_DTCNT1_INIT, (UWord16*) &pEfpwmBase->smdtcnt1);
			#endif

			#ifdef PWM_B_3_CAPTCTRLA_INIT
			periphMemWrite(PWM_B_3_CAPTCTRLA_INIT, (UWord16*) &pEfpwmBase->smcaptctrla);
			#endif

			#ifdef PWM_B_3_CAPTCOMPA_INIT
			periphMemWrite(PWM_B_3_CAPTCOMPA_INIT, (UWord16*) &pEfpwmBase->smcaptcompa);
			#endif

			#ifdef PWM_B_3_CAPTCTRLB_INIT
			periphMemWrite(PWM_B_3_CAPTCTRLB_INIT, (UWord16*) &pEfpwmBase->smcaptctrlb);
			#endif

			#ifdef PWM_B_3_CAPTCOMPB_INIT
			periphMemWrite(PWM_B_3_CAPTCOMPB_INIT, (UWord16*) &pEfpwmBase->smcaptcompb);
			#endif

			#ifdef PWM_B_3_CAPTCTRLX_INIT
			periphMemWrite(PWM_B_3_CAPTCTRLX_INIT, (UWord16*) &pEfpwmBase->smcaptctrlx);
			#endif

			#ifdef PWM_B_3_CAPTCOMPX_INIT
			periphMemWrite(PWM_B_3_CAPTCOMPX_INIT, (UWord16*) &pEfpwmBase->smcaptcompx);
			#endif
			
			#ifdef PWM_B_3_DMAEN_INIT
			periphMemWrite(PWM_B_3_DMAEN_INIT, (UWord16*) &pEfpwmBase->smdmaen);
			#endif
		}	/* if(pEfpwmBase == (arch_sEFPWMBSubCaptModule*)EFPWM_B_SUB3) */
		else
		; /* last else case */

	#endif  /* EFPWM_B_SUB3_INIT_USED && defined(EFPWM_B_SUB3)  */
  } /* void  efpwmBSubCaptInit(arch_sEFPWMBSubCaptModule *pEfpwmBase) */
#endif /* #if defined(EFPWM_B)  */

