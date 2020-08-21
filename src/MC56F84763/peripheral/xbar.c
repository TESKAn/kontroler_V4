/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name: xbar_8xxx.c$
*
* $Date:      Dec-4-2012$
*
* $Version:   2.5.4.0$
*
* Description: Source file for the XBAR driver
*
*****************************************************************************/

#include "qs.h"
#include "xbar.h"

/********************************************************************************
 xbarInit() function performs the XBAR module static configuration
 based on the configurable items from appconfig.h 
********************************************************************************/


#if XBAR_VERSION == 1

void xbarInit(arch_sXBAR *pXbarBase)
{
#pragma unused(pXbarBase)

	#ifdef XBAR_XBC0_INIT
	periphMemWrite(XBAR_XBC0_INIT, &pXbarBase->xbc0);
	#endif

	#ifdef XBAR_XBC1_INIT
	periphMemWrite(XBAR_XBC1_INIT, &pXbarBase->xbc1);
	#endif

	#ifdef XBAR_XBC2_INIT
	periphMemWrite(XBAR_XBC2_INIT, &pXbarBase->xbc2);
	#endif

	#ifdef XBAR_XBC3_INIT
	periphMemWrite(XBAR_XBC3_INIT, &pXbarBase->xbc3);
	#endif

	#ifdef XBAR_XBC4_INIT
	periphMemWrite(XBAR_XBC4_INIT, &pXbarBase->xbc4);
	#endif

	#ifdef XBAR_XBC5_INIT
	periphMemWrite(XBAR_XBC5_INIT, &pXbarBase->xbc5);
	#endif

	#ifdef XBAR_XBC6_INIT
	periphMemWrite(XBAR_XBC6_INIT, &pXbarBase->xbc6);
	#endif

	#ifdef XBAR_XBC7_INIT
	periphMemWrite(XBAR_XBC7_INIT, &pXbarBase->xbc7);
	#endif

	#ifdef XBAR_XBC8_INIT
	periphMemWrite(XBAR_XBC8_INIT, &pXbarBase->xbc8);
	#endif

	#ifdef XBAR_XBC9_INIT
	periphMemWrite(XBAR_XBC9_INIT, &pXbarBase->xbc9);
	#endif

	#ifdef XBAR_XBC10_INIT
	periphMemWrite(XBAR_XBC10_INIT, &pXbarBase->xbc10);
	#endif

	#ifdef XBAR_XBC11_INIT
	periphMemWrite(XBAR_XBC11_INIT, &pXbarBase->xbc11);
	#endif

	#ifdef XBAR_XBC12_INIT
	periphMemWrite(XBAR_XBC12_INIT, &pXbarBase->xbc12);
	#endif

	#ifdef XBAR_XBC13_INIT
	periphMemWrite(XBAR_XBC13_INIT, &pXbarBase->xbc13);
	#endif

	#ifdef XBAR_XBC14_INIT
	periphMemWrite(XBAR_XBC14_INIT, &pXbarBase->xbc14);
	#endif
}
#endif

#if XBAR_VERSION == 2 || XBAR_VERSION == 3	

void xbaraInit(arch_sXBARA *pXbarBase)
{
#pragma unused(pXbarBase)

	#ifdef XBAR_A_SEL0_INIT
	periphMemWrite(XBAR_A_SEL0_INIT, &pXbarBase->xbara_sel0);
	#endif

	#ifdef XBAR_A_SEL1_INIT
	periphMemWrite(XBAR_A_SEL1_INIT, &pXbarBase->xbara_sel1);
	#endif

	#ifdef XBAR_A_SEL2_INIT
	periphMemWrite(XBAR_A_SEL2_INIT, &pXbarBase->xbara_sel2);
	#endif

	#ifdef XBAR_A_SEL3_INIT
	periphMemWrite(XBAR_A_SEL3_INIT, &pXbarBase->xbara_sel3);
	#endif		

	#ifdef XBAR_A_SEL4_INIT
	periphMemWrite(XBAR_A_SEL4_INIT, &pXbarBase->xbara_sel4);
	#endif

	#ifdef XBAR_A_SEL5_INIT
	periphMemWrite(XBAR_A_SEL5_INIT, &pXbarBase->xbara_sel5);
	#endif

	#ifdef XBAR_A_SEL6_INIT
	periphMemWrite(XBAR_A_SEL6_INIT, &pXbarBase->xbara_sel6);
	#endif

	#ifdef XBAR_A_SEL7_INIT
	periphMemWrite(XBAR_A_SEL7_INIT, &pXbarBase->xbara_sel7);
	#endif

	#ifdef XBAR_A_SEL8_INIT
	periphMemWrite(XBAR_A_SEL8_INIT, &pXbarBase->xbara_sel8);
	#endif

	#ifdef XBAR_A_SEL9_INIT
	periphMemWrite(XBAR_A_SEL9_INIT, &pXbarBase->xbara_sel9);
	#endif

	#ifdef XBAR_A_SEL10_INIT
	periphMemWrite(XBAR_A_SEL10_INIT, &pXbarBase->xbara_sel10);
	#endif

	#ifdef XBAR_A_SEL11_INIT
	periphMemWrite(XBAR_A_SEL11_INIT, &pXbarBase->xbara_sel11);
	#endif

	#ifdef XBAR_A_SEL12_INIT
	periphMemWrite(XBAR_A_SEL12_INIT, &pXbarBase->xbara_sel12);
	#endif

	#ifdef XBAR_A_SEL13_INIT
	periphMemWrite(XBAR_A_SEL13_INIT, &pXbarBase->xbara_sel13);
	#endif

	#ifdef XBAR_A_SEL14_INIT
	periphMemWrite(XBAR_A_SEL14_INIT, &pXbarBase->xbara_sel14);
	#endif

	#ifdef XBAR_A_SEL15_INIT
	periphMemWrite(XBAR_A_SEL15_INIT, &pXbarBase->xbara_sel15);
	#endif

	#ifdef XBAR_A_SEL16_INIT
	periphMemWrite(XBAR_A_SEL16_INIT, &pXbarBase->xbara_sel16);
	#endif

	#ifdef XBAR_A_SEL17_INIT
	periphMemWrite(XBAR_A_SEL17_INIT, &pXbarBase->xbara_sel17);
	#endif

	#ifdef XBAR_A_SEL18_INIT
	periphMemWrite(XBAR_A_SEL18_INIT, &pXbarBase->xbara_sel18);
	#endif

	#ifdef XBAR_A_SEL19_INIT
	periphMemWrite(XBAR_A_SEL19_INIT, &pXbarBase->xbara_sel19);
	#endif

	#ifdef XBAR_A_SEL20_INIT
	periphMemWrite(XBAR_A_SEL20_INIT, &pXbarBase->xbara_sel20);
	#endif

#if XBAR_VERSION == 2

	#ifdef XBAR_A_SEL21_INIT
	periphMemWrite(XBAR_A_SEL21_INIT, &pXbarBase->xbara_sel21);
	#endif

	#ifdef XBAR_A_SEL22_INIT
	periphMemWrite(XBAR_A_SEL22_INIT, &pXbarBase->xbara_sel22);
	#endif

	#ifdef XBAR_A_SEL23_INIT
	periphMemWrite(XBAR_A_SEL23_INIT, &pXbarBase->xbara_sel23);
	#endif

	#ifdef XBAR_A_SEL24_INIT
	periphMemWrite(XBAR_A_SEL24_INIT, &pXbarBase->xbara_sel24);
	#endif

	#ifdef XBAR_A_SEL25_INIT
	periphMemWrite(XBAR_A_SEL25_INIT, &pXbarBase->xbara_sel25);
	#endif

	#ifdef XBAR_A_SEL26_INIT
	periphMemWrite(XBAR_A_SEL26_INIT, &pXbarBase->xbara_sel26);
	#endif

	#ifdef XBAR_A_SEL27_INIT
	periphMemWrite(XBAR_A_SEL27_INIT, &pXbarBase->xbara_sel27);
	#endif

	#ifdef XBAR_A_SEL28_INIT
	periphMemWrite(XBAR_A_SEL28_INIT, &pXbarBase->xbara_sel28);
	#endif

	#ifdef XBAR_A_SEL29_INIT
	periphMemWrite(XBAR_A_SEL29_INIT, &pXbarBase->xbara_sel29);
	#endif
	
#endif

	#ifdef XBAR_A_CTRL0_INIT
	periphMemWrite(XBAR_A_CTRL0_INIT, &pXbarBase->xbara_ctrl0);
	#endif

	#ifdef XBAR_A_CTRL1_INIT
	periphMemWrite(XBAR_A_CTRL1_INIT, &pXbarBase->xbara_ctrl1);
	#endif
}

void xbarbInit(arch_sXBARB *pXbarBase)
{
#pragma unused(pXbarBase)

	#ifdef XBAR_B_SEL0_INIT
	periphMemWrite(XBAR_B_SEL0_INIT, &pXbarBase->xbarb_sel0);
	#endif

	#ifdef XBAR_B_SEL1_INIT
	periphMemWrite(XBAR_B_SEL1_INIT, &pXbarBase->xbarb_sel1);
	#endif

	#ifdef XBAR_B_SEL2_INIT
	periphMemWrite(XBAR_B_SEL2_INIT, &pXbarBase->xbarb_sel2);
	#endif

	#ifdef XBAR_B_SEL3_INIT
	periphMemWrite(XBAR_B_SEL3_INIT, &pXbarBase->xbarb_sel3);
	#endif		

	#ifdef XBAR_B_SEL4_INIT
	periphMemWrite(XBAR_B_SEL4_INIT, &pXbarBase->xbarb_sel4);
	#endif

	#ifdef XBAR_B_SEL5_INIT
	periphMemWrite(XBAR_B_SEL5_INIT, &pXbarBase->xbarb_sel5);
	#endif

	#ifdef XBAR_B_SEL6_INIT
	periphMemWrite(XBAR_B_SEL6_INIT, &pXbarBase->xbarb_sel6);
	#endif

	#ifdef XBAR_B_SEL7_INIT
	periphMemWrite(XBAR_B_SEL7_INIT, &pXbarBase->xbarb_sel7);
	#endif

}
#endif

