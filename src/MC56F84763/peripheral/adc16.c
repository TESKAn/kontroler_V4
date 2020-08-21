/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name: adc16_84xxx.c$
*
* $Date:      Feb-28-2013$
*
* $Version:   2.4.2.0$
*
* Description: Source file for the ADC Driver
*
*****************************************************************************/

#include "qs.h"

#include "adc16.h"

#include "initconfig.h"

#ifdef __cplusplus
extern "C" {
#endif

/* initialization of ADC16 */
void adc16Init(arch_sADC16 *pAdcBase)
{
#pragma unused(pAdcBase)

#ifdef ADC_0_ADC16_OFS_INIT
 periphMemWrite(ADC_0_ADC16_OFS_INIT, &((pAdcBase)->adcofs));
#endif
   
#ifdef ADC_0_ADC16_PG_INIT        
 periphMemWrite(ADC_0_ADC16_PG_INIT, &((pAdcBase)->adcpg));
#endif
       
#ifdef ADC_0_ADC16_CLPD_INIT       
 periphMemWrite(ADC_0_ADC16_CLPD_INIT, &((pAdcBase)->adcclpd));
#endif
       
#ifdef ADC_0_ADC16_CLPS_INIT        
 periphMemWrite(ADC_0_ADC16_CLPS_INIT, &((pAdcBase)->adcclps));
#endif
       
#ifdef ADC_0_ADC16_CLP4_INIT        
 periphMemWrite(ADC_0_ADC16_CLP4_INIT, &((pAdcBase)->adcclp4));
#endif
       
#ifdef ADC_0_ADC16_CLP3_INIT       
 periphMemWrite(ADC_0_ADC16_CLP3_INIT, &((pAdcBase)->adcclp3));
#endif
       
#ifdef ADC_0_ADC16_CLP2_INIT       
 periphMemWrite(ADC_0_ADC16_CLP2_INIT, &((pAdcBase)->adcclp2));
#endif
       
#ifdef ADC_0_ADC16_CLP1_INIT       
 periphMemWrite(ADC_0_ADC16_CLP1_INIT, &((pAdcBase)->adcclp1));
#endif
       
#ifdef ADC_0_ADC16_CLP0_INIT
 periphMemWrite(ADC_0_ADC16_CLP0_INIT, &((pAdcBase)->adcclp0));
#endif

#ifdef ADC_0_ADC16_SC1A_INIT
 periphMemWrite(ADC_0_ADC16_SC1A_INIT, &((pAdcBase)->adcsc1a));
#endif

#ifdef ADC_0_ADC16_SC2_INIT
 periphMemWrite(ADC_0_ADC16_SC2_INIT, &((pAdcBase)->adcsc2));
#endif 

#ifdef ADC_0_ADC16_SC3_INIT
 periphMemWrite(ADC_0_ADC16_SC3_INIT, &((pAdcBase)->adcsc3));
#endif

#ifdef ADC_0_ADC16_CFG1_INIT
  periphMemWrite(ADC_0_ADC16_CFG1_INIT, &((pAdcBase)->adccfg1));
#endif

#ifdef ADC_0_ADC16_CFG2_INIT
  periphMemWrite(ADC_0_ADC16_CFG2_INIT, &((pAdcBase)->adccfg2));
#endif

#ifdef ADC_0_ADC16_CV1_INIT
   periphMemWrite(ADC_0_ADC16_CV1_INIT, &((pAdcBase)->adccv1));
#endif

#ifdef ADC_0_ADC16_CV2_INIT
  periphMemWrite(ADC_0_ADC16_CV2_INIT, &((pAdcBase)->adccv2));
#endif

}


#ifdef __cplusplus
}
#endif
