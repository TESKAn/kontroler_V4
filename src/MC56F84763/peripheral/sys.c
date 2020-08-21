/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  sys.c
*
* $Date:      Feb-22-2013$
*
* $Version:   2.5.1.0$
*
* Description: SYS (system reset and support functions) driver SIM_VERSION_7
*
*****************************************************************************/

#include "qs.h"
#include "sys.h"

#ifdef __cplusplus
extern "C" {
#endif

/* initialization of SYS (SIM) system support functions */

void sysInit(arch_sSIM *pSimBase)
{
#pragma unused(pSimBase)

#if SIM_VERSION <= 6

	#ifdef SIM_CONROL_INIT
	periphMemWrite(SIM_CONROL_INIT, &pSimBase->sim_control);
	#endif
 
	#ifdef SIM_CLKOSR_INIT
	periphMemWrite(SIM_CLKOSR_INIT, &pSimBase->sim_clkosr);
	#endif

	#ifdef SIM_GPS0_INIT
	periphMemWrite(SIM_GPS0_INIT, &pSimBase->sim_gps0);
	#endif

	#ifdef SIM_GPS1_INIT
	periphMemWrite(SIM_GPS1_INIT, &pSimBase->sim_gps1);
	#endif

	#ifdef SIM_GPS2_INIT
	periphMemWrite(SIM_GPS2_INIT, &pSimBase->sim_gps2);
	#endif

	#ifdef SIM_GPS3_INIT
	periphMemWrite(SIM_GPS3_INIT, &pSimBase->sim_gps3);
	#endif

	#ifdef SIM_PCR_INIT
	periphMemWrite(SIM_PCR_INIT, &pSimBase->sim_pcr);
	#endif

	#ifdef SIM_SD0_INIT
	periphMemWrite(SIM_SD0_INIT, &pSimBase->sim_sd0);
	#endif

	#ifdef SIM_SD1_INIT
	periphMemWrite(SIM_SD1_INIT, &pSimBase->sim_sd1);
	#endif

	#ifdef SIM_SD2_INIT
	periphMemWrite(SIM_SD2_INIT, &pSimBase->sim_sd2);
	#endif

	#ifdef SIM_PCE0_INIT
	periphMemWrite(SIM_PCE0_INIT, &pSimBase->sim_pce0);
	#endif

	#ifdef SIM_PCE1_INIT
	periphMemWrite(SIM_PCE1_INIT, &pSimBase->sim_pce1);
	#endif

	#ifdef SIM_PCE2_INIT
	periphMemWrite(SIM_PCE2_INIT, &pSimBase->sim_pce2);
	#endif

	#ifdef SIM_PROT_INIT
	periphMemWrite(SIM_PROT_INIT, &pSimBase->sim_prot);
	#endif

	/* LVI is initialized here as a part of SYS initialization */	
	#ifdef LVI_CONTROL_INIT								// todo
	periphMemWrite(LVI_CONTROL_INIT, &LVI->ps_ctlr);		
	#endif
#endif
	
	#if SIM_VERSION >= 7
	
		#ifdef SIM_CONROL_INIT
		periphMemWrite(SIM_CONROL_INIT, &pSimBase->sim_control);
		#endif
	 
		#ifdef SIM_CLKOSR_INIT
		periphMemWrite(SIM_CLKOSR_INIT, &pSimBase->sim_clkosr);
		#endif	
		
		#ifdef SIM_PCR_INIT
		periphMemWrite(SIM_PCR_INIT, &pSimBase->sim_pcr);
		#endif

		#ifdef SIM_SD0_INIT
		periphMemWrite(SIM_SD0_INIT, &pSimBase->sim_sd0);
		#endif

		#ifdef SIM_SD1_INIT
		periphMemWrite(SIM_SD1_INIT, &pSimBase->sim_sd1);
		#endif

		#ifdef SIM_SD2_INIT
		periphMemWrite(SIM_SD2_INIT, &pSimBase->sim_sd2);
		#endif
		
		#ifdef SIM_SD3_INIT
		periphMemWrite(SIM_SD3_INIT, &pSimBase->sim_sd3);
		#endif
		
		#ifdef SIM_PCE0_INIT
		periphMemWrite(SIM_PCE0_INIT, &pSimBase->sim_pce0);
		#endif

		#ifdef SIM_PCE1_INIT
		periphMemWrite(SIM_PCE1_INIT, &pSimBase->sim_pce1);
		#endif

		#ifdef SIM_PCE2_INIT
		periphMemWrite(SIM_PCE2_INIT, &pSimBase->sim_pce2);
		#endif
		
		#ifdef SIM_PCE3_INIT
		periphMemWrite(SIM_PCE3_INIT, &pSimBase->sim_pce3);
		#endif
		
		#ifdef SIM_PWR_INIT
		periphMemWrite(SIM_PWR_INIT, &pSimBase->sim_pwr);
		#endif
		
		#ifdef SIM_GPSAL_INIT
		periphMemWrite(SIM_GPSAL_INIT, &pSimBase->sim_gpsal);
		#endif	
		
		#ifdef SIM_GPSCL_INIT
		periphMemWrite(SIM_GPSCL_INIT, &pSimBase->sim_gpscl);
		#endif
		
		#ifdef SIM_GPSCH_INIT
		periphMemWrite(SIM_GPSCH_INIT, &pSimBase->sim_gpsch);
		#endif
		
		#ifdef SIM_GPSEL_INIT
		periphMemWrite(SIM_GPSEL_INIT, &pSimBase->sim_gpsel);
		#endif
		
		#ifdef SIM_GPSFL_INIT
		periphMemWrite(SIM_GPSFL_INIT, &pSimBase->sim_gpsfl);
		#endif		

		#ifdef SIM_GPSFH_INIT
		periphMemWrite(SIM_GPSFH_INIT, &pSimBase->sim_gpsfh);
		#endif	

		#ifdef SIM_IPS0_INIT
		periphMemWrite(SIM_IPS0_INIT, &pSimBase->sim_ips0);
		#endif		
		
		#ifdef SIM_MISC0_INIT
		periphMemWrite(SIM_MISC0_INIT, &pSimBase->sim_misc0);
		#endif	

		#ifdef SIM_PSWR0_INIT
		periphMemWrite(SIM_PSWR0_INIT, &pSimBase->sim_pswr0);
		#endif

		#ifdef SIM_PSWR1_INIT
		periphMemWrite(SIM_PSWR1_INIT, &pSimBase->sim_pswr1);
		#endif		

		#ifdef SIM_PSWR2_INIT
		periphMemWrite(SIM_PSWR2_INIT, &pSimBase->sim_pswr2);
		#endif	
		
		#ifdef SIM_PSWR3_INIT
		periphMemWrite(SIM_PSWR3_INIT, &pSimBase->sim_pswr3);
		#endif	
		
		#ifdef SIM_PWRMODE_INIT
		periphMemWrite(SIM_PWRMODE_INIT, &pSimBase->sim_pwrmode);
		#endif
		
		#ifdef SIM_IOSAHI_INIT
		periphMemWrite(SIM_IOSAHI_INIT, &pSimBase->sim_iosahi);
		#endif
		
		#ifdef SIM_IOSALO_INIT
		periphMemWrite(SIM_IOSALO_INIT, &pSimBase->sim_iosalo);
		#endif

		#ifdef SIM_SCR0_INIT
		periphMemWrite(SIM_SCR0_INIT, &pSimBase->sim_scr0);
		#endif
		
		#ifdef SIM_SCR1_INIT
		periphMemWrite(SIM_SCR1_INIT, &pSimBase->sim_scr1);
		#endif

		#ifdef SIM_SCR2_INIT
		periphMemWrite(SIM_SCR2_INIT, &pSimBase->sim_scr2);
		#endif

		#ifdef SIM_SCR3_INIT
		periphMemWrite(SIM_SCR3_INIT, &pSimBase->sim_scr3);
		#endif
		
	#endif
	
	#if SIM_VERSION == 7
	
		#ifdef SIM_GPSBH_INIT
		periphMemWrite(SIM_GPSBH_INIT, &pSimBase->sim_gpsbh);
		#endif	
		
		#ifdef SIM_GPSEH_INIT
		periphMemWrite(SIM_GPSEH_INIT, &pSimBase->sim_gpseh);
		#endif

		#ifdef SIM_GPSGL_INIT
		periphMemWrite(SIM_GPSGL_INIT, &pSimBase->sim_gpsgl);
		#endif
		
		#ifdef SIM_GPSGH_INIT
		periphMemWrite(SIM_GPSGH_INIT, &pSimBase->sim_gpsgh);
		#endif
		
        #ifdef SIM_GPSDL_INIT
        periphMemWrite(SIM_GPSDL_INIT, &pSimBase->sim_gpsdl);
        #endif
		
		#ifdef SIM_PROT_INIT
		periphMemWrite(SIM_PROT_INIT, &pSimBase->sim_prot);
		#endif
		
	#endif
	
	#if SIM_VERSION == 8	
		
		#ifdef SIM_SCR4_INIT
		periphMemWrite(SIM_SCR4_INIT, &pSimBase->sim_scr4);
		#endif

		#ifdef SIM_SCR5_INIT
		periphMemWrite(SIM_SCR5_INIT, &pSimBase->sim_scr5);
		#endif

		#ifdef SIM_SCR6_INIT
		periphMemWrite(SIM_SCR6_INIT, &pSimBase->sim_scr6);
		#endif

		#ifdef SIM_SCR7_INIT
		periphMemWrite(SIM_SCR7_INIT, &pSimBase->sim_scr7);
		#endif
		
		#ifdef SIM_GPSBL_INIT
		periphMemWrite(SIM_GPSBL_INIT, &pSimBase->sim_gpsbl);
		#endif
	
	
		#ifdef SIM_PROT_INIT
		periphMemWrite(SIM_PROT_INIT, &pSimBase->sim_prot);
		#endif
	
	#endif
}

#ifdef __cplusplus
}
#endif
