/*******************************************************************************
*
* File Name: main.c
*
* Description: Main application file generated automatically from the 
*              DSP56800E_Quick_Start stationery
*
* Target: MC56F84789 device
*
*******************************************************************************/

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


/* local prototypes */


/*
 * The main function is invoked from the startup code after 
 * key device resources (PLL, memory) are initialised.
 *
 */

void main (void) 
{
	/* initialise SYS module */
    ioctl(SYS, SYS_INIT, NULL);

    /* configure COP module */
    ioctl(COP, COP_INIT, NULL);
    
    /* configure all GPIO modules */
    ioctl(GPIO, GPIO_INIT_ALL, NULL);

    /* 
     * TODO: put your other module initialisation calls here
     *   e.g. ioctl(SCI, SCI_INIT, NULL)
     *
     */

    /* initialise interrupt controller and enable interrupts */
    ioctl(INTC, INTC_INIT, NULL);
    archEnableInt();

    /*
     * TODO: perform additional initialisations here 
     *
     */

    while(1)
    {
        /*
         * TODO: put your main-loop code here 
         *
         */

         /* feed the watchdog periodically */
         ioctl(COP, COP_CLEAR_COUNTER, NULL);

    }
}
