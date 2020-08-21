/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  iic.c
*
* $Date:      Jan-28-2013$
*
* $Version:   2.5.5.0$
*
* Description: Source file for the I2C driver
*
*****************************************************************************/

#include "qs.h"
#include "iic.h"
#include "initconfig.h"

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************
 iicInit() function performs the I2C module static configuration
 based on the configurable items from appconfig.h 
********************************************************************************/

void iicInit(arch_sIIC *pI2cBase)
{
#pragma unused(pI2cBase)

#if IIC_INIT_USED && defined(IIC)
	if (pI2cBase == IIC)
	{
		#ifdef IIC_IICF_INIT
		pI2cBase->iicf = IIC_IICF_INIT;
		#endif 
	
		#ifdef IIC_IICA1_INIT
		pI2cBase->iica1 = IIC_IICA1_INIT;
		#endif 

		#ifdef IIC_IICA2_INIT
		pI2cBase->iica2 = IIC_IICA2_INIT;
		#endif 

		#ifdef IIC_IICSLTH_INIT
		pI2cBase->iicslth = IIC_IICSLTH_INIT;
		#endif 

		#ifdef IIC_IICSLTL_INIT
		pI2cBase->iicsltl = IIC_IICSLTL_INIT;
		#endif 

		#ifdef IIC_IICSMB_INIT
		pI2cBase->iicsmb = IIC_IICSMB_INIT;
		#endif 

		#ifdef IIC_IICC2_INIT
		pI2cBase->iicc2 = IIC_IICC2_INIT;
		#endif 

		#ifdef IIC_IICC1_INIT
		pI2cBase->iicc1 = IIC_IICC1_INIT;
		#endif  
	#if IIC_VERSION >=4
		#ifdef IIC_IICFILT_INIT
		pI2cBase->iicfilt = IIC_IICFILT_INIT;
		#endif  
	#endif
		
	#if IIC_VERSION >=5
		#ifdef IIC_IICRA_INIT
		pI2cBase->iicra = IIC_IICRA_INIT;
		#endif  
	#endif
	}
	else
#endif

#if IIC_0_INIT_USED && defined(IIC_0)
	if (pI2cBase == IIC_0)
	{
		#ifdef IIC_0_IICF_INIT
		pI2cBase->iicf = IIC_0_IICF_INIT;
		#endif 
	
		#ifdef IIC_0_IICA1_INIT
		pI2cBase->iica1 = IIC_0_IICA1_INIT;
		#endif 

		#ifdef IIC_0_IICA2_INIT
		pI2cBase->iica2 = IIC_0_IICA2_INIT;
		#endif 

		#ifdef IIC_0_IICSLTH_INIT
		pI2cBase->iicslth = IIC_0_IICSLTH_INIT;
		#endif 

		#ifdef IIC_0_IICSLTL_INIT
		pI2cBase->iicsltl = IIC_0_IICSLTL_INIT;
		#endif 

		#ifdef IIC_0_IICSMB_INIT
		pI2cBase->iicsmb = IIC_0_IICSMB_INIT;
		#endif 

		#ifdef IIC_0_IICC2_INIT
		pI2cBase->iicc2 = IIC_0_IICC2_INIT;
		#endif 

		#ifdef IIC_0_IICC1_INIT
		pI2cBase->iicc1 = IIC_0_IICC1_INIT;
		#endif  

	#if IIC_VERSION >=4
		#ifdef IIC_0_IICFILT_INIT
		pI2cBase->iicfilt = IIC_0_IICFILT_INIT;
		#endif
	#endif
	
	#if IIC_VERSION >=5
		#ifdef IIC_0_IICRA_INIT
		pI2cBase->iicra = IIC_0_IICRA_INIT;
		#endif
	#endif
	}
	else
#endif

#if IIC_1_INIT_USED && defined(IIC_1)
	if (pI2cBase == IIC_1)
	{
		#ifdef IIC_1_IICF_INIT
		pI2cBase->iicf = IIC_1_IICF_INIT;
		#endif 
	
		#ifdef IIC_1_IICA1_INIT
		pI2cBase->iica1 = IIC_1_IICA1_INIT;
		#endif 

		#ifdef IIC_1_IICA2_INIT
		pI2cBase->iica2 = IIC_1_IICA2_INIT;
		#endif 

		#ifdef IIC_1_IICSLTH_INIT
		pI2cBase->iicslth = IIC_1_IICSLTH_INIT;
		#endif 

		#ifdef IIC_1_IICSLTL_INIT
		pI2cBase->iicsltl = IIC_1_IICSLTL_INIT;
		#endif 

		#ifdef IIC_1_IICSMB_INIT
		pI2cBase->iicsmb = IIC_1_IICSMB_INIT;
		#endif 

		#ifdef IIC_1_IICC2_INIT
		pI2cBase->iicc2 = IIC_1_IICC2_INIT;
		#endif 

		#ifdef IIC_1_IICC1_INIT
		pI2cBase->iicc1 = IIC_1_IICC1_INIT;
		#endif  

	#if IIC_VERSION >=4
		#ifdef IIC_1_IICFILT_INIT
		pI2cBase->iicfilt = IIC_1_IICFILT_INIT;
		#endif
	#endif

	#if IIC_VERSION >=5
		#ifdef IIC_1_IICRA_INIT
		pI2cBase->iicra = IIC_1_IICRA_INIT;
		#endif
	#endif
	}
	else
#endif

;
}

#ifdef __cplusplus
}
#endif

