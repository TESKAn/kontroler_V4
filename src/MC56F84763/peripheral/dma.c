/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  dma.c
*
* $Date:      May-10-2013$
*
* $Version:   2.3.4.0$
*
* Description: Source file for the DMA Driver
*
*****************************************************************************/

#include "qs.h"
#include "dma.h"
#include "initconfig.h"


#ifdef __cplusplus
extern "C" {
#endif

/* initialization of DMA  */

void Dma_init(void)
{
	Dma_common_init(DMA);
	#if DMA_CHANNEL_0_INIT_USED
	Dma_channel_init(DMA_0);
	#endif
	#if DMA_CHANNEL_1_INIT_USED
	Dma_channel_init(DMA_1);
	#endif
	#if DMA_CHANNEL_2_INIT_USED
	Dma_channel_init(DMA_2);
	#endif
	#if DMA_CHANNEL_3_INIT_USED
	Dma_channel_init(DMA_3);
	#endif
}


void Dma_channel_init(arch_sDMAchannel *pDmaBase)
{
#pragma unused(pDmaBase)
	
	if(pDmaBase == (arch_sDMAchannel*)DMA_0)
	{  
		#ifdef DMA_SAR0_INIT
		periphMemWrite(DMA_SAR0_INIT, &pDmaBase->sar);
		#endif
		
		#ifdef DMA_DAR0_INIT
		periphMemWrite(DMA_DAR0_INIT, &pDmaBase->dar);
		#endif
		
		#ifdef DMA_DCR0_INIT
		periphMemWrite(DMA_DCR0_INIT, &pDmaBase->dcr);
		#endif
		
		#ifdef DMA_DSR_BCR0_INIT
		periphMemWrite(DMA_DSR_BCR0_INIT, &pDmaBase->dsr_bcr);
		#endif
	}
	
	if(pDmaBase == (arch_sDMAchannel*)DMA_1)
	{  
		#ifdef DMA_SAR1_INIT
		periphMemWrite(DMA_SAR1_INIT, &pDmaBase->sar);
		#endif
		
		#ifdef DMA_DAR1_INIT
		periphMemWrite(DMA_DAR1_INIT, &pDmaBase->dar);
		#endif
		
		#ifdef DMA_DCR1_INIT
		periphMemWrite(DMA_DCR1_INIT, &pDmaBase->dcr);
		#endif
		
		#ifdef DMA_DSR_BCR1_INIT
		periphMemWrite(DMA_DSR_BCR1_INIT, &pDmaBase->dsr_bcr);
		#endif
	}
	
	if(pDmaBase == (arch_sDMAchannel*)DMA_2)
	{  
		#ifdef DMA_SAR2_INIT
		periphMemWrite(DMA_SAR2_INIT, &pDmaBase->sar);
		#endif
		
		#ifdef DMA_DAR2_INIT
		periphMemWrite(DMA_DAR2_INIT, &pDmaBase->dar);
		#endif
		
		#ifdef DMA_DCR2_INIT
		periphMemWrite(DMA_DCR2_INIT, &pDmaBase->dcr);
		#endif
		
		#ifdef DMA_DSR_BCR2_INIT
		periphMemWrite(DMA_DSR_BCR2_INIT, &pDmaBase->dsr_bcr);
		#endif
	}
	
	if(pDmaBase == (arch_sDMAchannel*)DMA_3)
	{  
		#ifdef DMA_SAR3_INIT
		periphMemWrite(DMA_SAR3_INIT, &pDmaBase->sar);
		#endif
		
		#ifdef DMA_DAR3_INIT
		periphMemWrite(DMA_DAR3_INIT, &pDmaBase->dar);
		#endif
		
		#ifdef DMA_DCR3_INIT
		periphMemWrite(DMA_DCR3_INIT, &pDmaBase->dcr);
		#endif
		
		#ifdef DMA_DSR_BCR3_INIT
		periphMemWrite(DMA_DSR_BCR3_INIT, &pDmaBase->dsr_bcr);
		#endif
	}	
	
}

void Dma_common_init(arch_sDMA *pDmaBase)
{
#pragma unused(pDmaBase)

	#ifdef DMA_REQC_INIT
	periphMemWrite(DMA_REQC_INIT, &pDmaBase->reqc);
	#endif
}

#ifdef __cplusplus
}
#endif
