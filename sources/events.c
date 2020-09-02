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

void ADC_1_ISR(void)
{
	// Clear EOSI flag
	ioctl(ADC_1, ADC_CLEAR_STATUS_EOSI, NULL);
	
	// Call freemaster recorder
	FMSTR_Recorder();
}
