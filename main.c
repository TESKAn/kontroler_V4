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

#include "sysInclude.h"

#include "functions.h"

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

	ioctl(XBAR_A, XBAR_A_INIT, null);
	ioctl(EFPWMA, EFPWM_INIT, null);
	ioctl(EFPWM_A_SUB0, EFPWM_INIT, null);
	ioctl(EFPWM_A_SUB1, EFPWM_INIT, null);
	ioctl(EFPWM_A_SUB2, EFPWM_INIT, null);
	ioctl(EFPWM_A_SUB3, EFPWM_INIT, null);

	ioctl(ADC_1, ADC_INIT, null);
	//ioctl(DAC, DAC_INIT, null);
	//ioctl(PIT_0, PIT_INIT, NULL);
	//ioctl(SPI_0, SPI_INIT, NULL);
	//ioctl(SCI_0, SCI_INIT, NULL);
	//ioctl(SCI_1, SCI_INIT, NULL);
	ioctl(QTIMER_A0, QT_INIT, NULL);
	ioctl(QTIMER_A1, QT_INIT, NULL);
	ioctl(QTIMER_A2, QT_INIT, NULL);
	ioctl(QTIMER_A3, QT_INIT, NULL);
	//ioctl(QTIMER_B0, QT_INIT, NULL);
	//ioctl(QTIMER_B1, QT_INIT, NULL);
	//ioctl(QTIMER_B2, QT_INIT, NULL);
	//ioctl(QTIMER_B3, QT_INIT, NULL);		// For input PWM
	//ioctl(HSCMP_A, HSCMP_INIT, NULL);
	//ioctl(FCAN, FCAN_INIT, NULL);
	//ioctl(CRC, CRC_INIT, NULL);

	FMSTR_Init();   

	/* 
	 * TODO: put your other module initialisation calls here
	 *   e.g. ioctl(SCI, SCI_INIT, NULL)
	 *
	 */

	/* initialise interrupt controller and enable interrupts */
	ioctl(INTC, INTC_INIT, NULL);
	archEnableInt();

	InitVariables(1);

	while(1)
	{
		// Check freemaster
		FMSTR_Poll();

		/* feed the watchdog periodically */
		ioctl(COP, COP_CLEAR_COUNTER, NULL);

	}
}
