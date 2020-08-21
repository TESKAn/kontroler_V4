/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  sys.h
*
* $Date:      May-30-2013$
*
* $Version:   2.5.3.0$
*
* Description: SIM, low voltage interrupt (LVI) and various system 
*              support macros and definitions for MC56F824x/5x
*
*****************************************************************************/

#ifndef __SYS_H
#define __SYS_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before sys.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************
* system module identifiers, correspond to module base address
*************************************************************/

#define SYS (&ArchIO.Sim)
#define SIM (&ArchIO.Sim)

/***********************************************************************
* SYS static configuration items for appconfig.h
***********************************************************************/

/*
    initial register values:

        #ifdef SIM_CONROL_INIT
        #ifdef SIM_CLKOSR_INIT
        #ifdef SIM_GPS0_INIT
        #ifdef SIM_GPS1_INIT
        #ifdef SIM_GPS2_INIT
        #ifdef SIM_GPS3_INIT
        #ifdef SIM_PCR_INIT
        #ifdef SIM_SD0_INIT
        #ifdef SIM_SD1_INIT
        #ifdef SIM_SD2_INIT
        #ifdef SIM_PCE0_INIT
        #ifdef SIM_PCE1_INIT
        #ifdef SIM_PCE2_INIT
        #ifdef SIM_PROT_INIT

    #define INTERRUPT_VECTOR_ADDR_yy  userISR //specify interrupt handler routine : e.g. lviISR
    #define INT_PRIORITY_LEVEL_yy     INTC_xxx // interrupt level : (INTC_DISABLED, INTC_LEVEL0,
                                               //                    INTC_LEVEL1 or INTC_LEVEL2)
  where:
         yy  is interrupt vector number
            e.g. On 56F8257
                14 - Low Voltage Detector (Power sense)

*/

/*****************************************************************
* ioctl() commands
*
*  Word16 ioctl( SYS_module_identifier, Command_name, Parameter );
*
******************************************************************

        COMMAND NAME                      PARAMETERS, COMMENTS
------------------------------------------------------------------ */
 #define SYS_SOFTWARE_RESET         /* NULL, issue software reset (SIM_CTRL->SWRST)*/
 #define SYS_ONCE                   /* SYS_ENABLE/SYS_DISABLE, OnCE module enable (SIM_CTRL->ONCEEBL) */

#define SYS_PERIPH_CLK_ENABLE      	/* combination of SYS_xxx_MOD, enable peripheral clock  (SIM_PCE0->_, SIM_PCE1) */
#define SYS_PERIPH_CLK_DISABLE     	/* combination of SYS_xxx_MOD, disable peripheral clock (SIM_PCE0->_, SIM_PCE1) */

#define SYS_ENABLE_IN_STOP_REG2    	/* combination of SYS_xxx_MOD2, enable  modules in STOP mode (SIM_SD2->_) */
#define SYS_DISABLE_IN_STOP_REG2   	/* combination of SYS_xxx_MOD2, disable modules in STOP mode (SIM_SD2->_) */

#define SYS_PERIPH_CLK_REG2_ENABLE  /* combination of SYS_xxx_MOD2, enable peripheral clock  (SIM_PCE2->_) */
#define SYS_PERIPH_CLK_REG2_DISABLE /* combination of SYS_xxx_MOD2, disable peripheral clock (SIM_PCE2->_) */

#define SYS_SELECT_MASTER_PIT   	/* SYS_PIT1/SYS_PIT0,  Select Master Programmable Interval Timer (SIM_MISC0->PIT_MSTR) */
#define SYS_SELECT_CLKIN        	/* SYS_CLKIN0/SYS_CLKIN1, Determine the GPIO port for the CLKIN input to the OCCS, CLKIN0 -(GPIOC0 alt1) , CLKIN1 -(GPIOC3 alt3) (SIM_MISC0->CLKINSEL) */

#define SYS_DMA_ENABLE  			/* DMAEBL_RUN_MODE/DMAEBL_RUN_WAIT_MODES/DMAEBL_ALL_MODES/DMAEBL_DISABLE_AND_WP/DMAEBL_RUN_MODE_AND_WP/DMAEBL_RUN_WAIT_MODES_AND_WP/DMAEBL_ALL_MODES_AND_WP, Select if DMA is enabled in RUN, WAIT, RUN and WAIT, or all modes. If the WP (Write protected) command is used, seting canot be changed until the next reset. (SIM_CTRL->DMAEbl) */
#define SYS_RST_FLT                	/* SYS_ENABLE/SYS_DISABLE, External Reset Padcell Input Filter Enable (SIM_CTRL->RST_FILT) */

#define SYS_READ_LSH_JTAG_ID       /* NULL, return JTAG ID as UWord16 (SIM_MSHID->LSHID) */
#define SYS_READ_MSH_JTAG_ID       /* NULL, return JTAG ID as UWord16 (SIM_MSHID->LSHID) */
#define SYS_CLKOUT                 /* SYS_ENABLE/SYS_DISABLE, Enable/disable CLKOUT pin (SIM_CLKOUT->CLKDIS1) */
#define SYS_CLKOUT_1               /* SYS_ENABLE/SYS_DISABLE, Enable/disable CLKOUT1 pin (SIM_CLKOUT->CLKDIS0) */
#define SYS_STOP                   /* SYS_ENABLE(_PERMANENT)/SYS_DISABLE(_PERMANENT), Enable/disable the STOP instruction. (SIM_CTRL->STOPDIS) */
#define SYS_WAIT                   /* SYS_ENABLE(_PERMANENT)/SYS_DISABLE(_PERMANENT), Enable/disable the WAIT instruction. (SIM_CTRL->WAITDIS) */



#define SYS_SET_LOW_POWER_MODE       /* SYS_ENABLE/SYS_DISABLE, cause the device to enter LPMODE (SIM_PWRMODE->LPMODE) */
#define SYS_GET_LOW_POWER_MODE       /* NULL, return UWord16 (SIM_PWRMODE->LPMODE) */
#define SYS_SET_VERY_LOW_POWER_MODE  /* SYS_ENABLE/SYS_DISABLE, Causes the device to enter/exit VLPMODE. (SIM_PWRMODE->VLPMODE)   */
#define SYS_GET_LOW_POWER_MODE       /* NULL, Return non-zero if device is in VLPMODE mode. (SIM_PWRMODE->VLPMODE)  */

#define SYS_SET_POWER_MODE           /* SYS_NORMAL_POWER/SYS_REDUCED_POWER | SYS_POWER_MODE_PERMANENT, Control the operation mode of the device. (SIM_PWRMODE->[0-1])    */
#define SYS_GET_POWER_MODE           /* NULL, Get current power mode. Return UWord16 value can be tested for presence of the SYS_REDUCED_POWER and SYS_POWER_MODE_PERMANENT flags. (SIM_PWRMODE->LPMODE,VLPMODE) */

#define SYS_TEST_RESET_SOURCE        /* any of SYS_xxx_RESET (SW/COP/COP_TOR/COP_LOR/EXTERN/POWER_ON/ANY/EZPORT/COP_WINDOW), get and test type of the previous RESET  (SIM_RSTAT->_) */
#define SYS_CLEAR_RESET_SOURCE       /* any of SYS_xxx_RESET (SW/COP/COP_TOR/COP_LOR/EXTERN/POWER_ON/ANY/EZPORT/COP_WINDOW), Acknowledge reset sources and clear selected bits in the Reset Staus Register. (SIM_RSTAT->_) */

#define SYS_CLKOUT_SELECT          /* one of SYS_CLKOUT_xxx (SYSCLK/IPBCLK/HSCLK/MSTRCLK), select CLSKOUT source (SIM_CLKOUT->CLKOSEL0) */

#define SYS_CLKODIV_SELECT         /*one of SYS_xxx (DIV1/DIV2//DIV4//DIV8/DIV16/DIV32/DIV128), select CLKOUT divide factor (SIM_CLKOUT->CLKODIV) */

#define SYS_WRITE_IO_SHORT_ADDR_LOCATION_REG  /* UWord32, set I/O short address mode base address (SIM_IOSAHI->_,SIM_IOSALO->_)*/
#define SYS_READ_IO_SHORT_ADDR_LOCATION_REG   /* NULL, Get I/O short address mode base address as UWord32. (SIM_IOSAHI->_,SIM_IOSALO->_) */

#define SYS_WPROTECT_CLOCK_SETTINGS  /* SYS_ENABLE(_PERMANENT)/SYS_DISABLE(_PERMANENT), write protect PCE, SD and PCR (SIM_PROT->PCEP) */
#define SYS_WPROTECT_SIGNALS_ROUTING /* SYS_ENABLE(_PERMANENT)/SYS_DISABLE(_PERMANENT), write protect GPSx, XBAR, GPIO_X_PER, GPIO_X_PPMODE, GPIO_X_DRIVE and GIO_X_IFE registers}  (SIM_PROT->GIPSP) */
#define SYS_WPROTECT_GPIOD           /* SYS_ENABLE(_PERMANENT)/SYS_DISABLE(_PERMANENT), write protect GPIO_D_PER, GPIO_D_PPMODE, and GPIO_D_DRIVE  (SIM_PROT->GDP) */
#define SYS_WPROTECT_POWER_MODE      /* SYS_ENABLE(_PERMANENT)/SYS_DISABLE(_PERMANENT), Write protect Power Mode Control.  (SIM_PROT->PMODE) */

#define SYS_SET_27_POWER_MODE         /* SYS_NORMAL_POWER/SYS_REDUCED_POWER | SYS_POWER_MODE_PERMANENT, Set Small Regulator 2.7 V Supply Standby Control (SIM_PWR->SR27STDBY) */
#define SYS_GET_27_POWER_MODE         /* NULL, Return Regulator Control as UWord16 value. (SIM_PWR->SR27STDBY) */
#define SYS_SET_12_POWER_MODE         /* SYS_NORMAL_POWER/SYS_REDUCED_POWER | SYS_POWER_MODE_PERMANENT, Set Small Regulator 1.2 V Supply Powerdown Control(SIM_PWR->SR12STDBY) */
#define SYS_GET_12_POWER_MODE         /* NULL, Return Regulator Control as UWord16 value. (SIM_PWR->SR27PDN) */
#define SYS_SET_27_POWERDOWN          /* SYS_NORMAL_POWER/SYS_POWERDOWN_MODE | SYS_POWER_MODE_PERMANENT, Set Small Regulator 2.7 V Supply Standby Control (SIM_PWR->SR27PDN) */
#define SYS_GET_27_POWERDOWN          /* NULL, Return Regulator Control as UWord16 value. (SIM_PWR->SR12STDBY) */

#if SIM_VERSION == 7
#define SYS_PERIPH_SW_RESET         /* combination of SYS_xxx_PSWR (GPIO;TB;TA;FLEXCAN;IIC1;IIC0;QSPI1;QSPI0;SCI1;SCI0;DAC;PDB1;PDB0;PIT1;PIT0;QDC;CRC;CYCADC;SARADC;CMP;EWM;PWMA), issue software reset of peripheral (SIM_PSWR0->_,SIM_PSWR1->_,SIM_PSWR2->_,SIM_PSWR3->_) */
#define SYS_HS_CLOCK_ENABLE         /* combination of SYS_HS_xxx (SCI0/SCI1), enable high-speed clock (SIM_PCR->_) */
#define SYS_HS_CLOCK_DISABLE        /* combination of SYS_HS_xxx (SCI0/SCI1), enable high-speed clock (SIM_PCR->_) */
#define SYS_CLKOUT_1_SELECT        /* one of SYS_CLKOUT_1_xxx (BUSCLK/2X_BUSCLK/DIV4_BUSCLK/MSTR_OSC/ROSC_8M/ROSC_32K), select CLSKOUT_1 source  (SIM_CLKOUT->CLKOSEL1) */

#define SYS_SET_A0PAD_FUNCTION     /* one of SYS_A0PAD_xxx  (ANA0_CMPA3/CMPC_O), package pin function selection (SIM_GPSAL->_) */ 
#define SYS_SET_B11PAD_FUNCTION    /* one of SYS_B11PAD_xxx (ANC15/XB_IN7 ), package pin function selection (SIM_GPSAL->_) */ 
#define SYS_SET_B10PAD_FUNCTION    /* one of SYS_B10PAD_xxx (ANC14/XB_IN8 ), package pin function selection (SIM_GPSAL->_) */ 
#define SYS_SET_B9PAD_FUNCTION     /* one of SYS_B9PAD_xxx  (ANC13/PADXB_IN9), package pin function selection (SIM_GPSAL->_) */ 	

#define SYS_SET_C15PAD_FUNCTION    /* one of SYS_C15PAD_xxx (XB_OUT5/PWM_SCL0  ), package pin function selection (SIM_GPSCH->C15) */
#define SYS_SET_C14PAD_FUNCTION    /* one of SYS_C14PAD_xxx (SDA0/XB_OUT4), package pin function selection (SIM_GPSCH->C14)*/
#define SYS_SET_C13PAD_FUNCTION    /* one of SYS_C13PAD_xxx (TA3/XB_IN6/EWM_OUTB ), package pin function selection (SIM_GPSCH->C13) */
#define SYS_SET_C12PAD_FUNCTION    /* one of SYS_C12PAD_xxx (CANRX/SDA1/RXD1), package pin function selection (SIM_GPSCH->C12) */ 
#define SYS_SET_C11PAD_FUNCTION    /* one of SYS_C11PAD_xxx (SCL1/TXD1/CANTX ), package pin function selection (SIM_GPSCH->C11) */ 
#define SYS_SET_C10PAD_FUNCTION    /* one of SYS_C10PAD_xxx (MASK/MOSI0/XB_IN5/MISO0  ), package pin function selection (SIM_GPSCH->C10) */ 
#define SYS_SET_C9PAD_FUNCTION     /* one of SYS_C9PAD_xxx  (XB_IN4/SCLK0), package pin function selection (SIM_GPSCH->C9) */ 
#define SYS_SET_C8PAD_FUNCTION     /* one of SYS_C8PAD_xxx  (MISO0/RXD0/XB_IN9 ), package pin function selection (SIM_GPSCH->C8) */ 
#define SYS_SET_C7PAD_FUNCTION     /* one of SYS_C7PAD_xxx  (SSB0_B/TXD0 ), package pin function selection (SIM_GPSCL->C7) */ 
#define SYS_SET_C6PAD_FUNCTION     /* one of SYS_C6PAD_xxx  (TA2/XB_IN3/CMPREF), package pin function selection (SIM_GPSCL->C6) */ 
#define SYS_SET_C5PAD_FUNCTION     /* one of SYS_C5PAD_xxx  (DAC0/XB_IN7  ), package pin function selection (SIM_GPSCL->C5) */ 
#define SYS_SET_C4PAD_FUNCTION     /* one of SYS_C4PAD_xxx  (TA1/CMPB_O/XB_IN8/EWM_OUT_B ), package pin function selection (SIM_GPSCL->C4) */ 
#define SYS_SET_C3PAD_FUNCTION     /* one of SYS_C3PAD_xxx  (TA0/CMPA_O/RXD0/CLKIN1  ), package pin function selection (SIM_GPSCL->C3) */ 
#define SYS_SET_C2PAD_FUNCTION     /* one of SYS_C2PAD_xxx  (TXD0/TB0/XB_IN2/CLKOUT0), package pin function selection (SIM_GPSCL->C2) */ 
#define SYS_SET_C0PAD_FUNCTION     /* one of SYS_C0PAD_xxx  (EXTAL/CLKIN  ), package pin function selection (SIM_GPSCL->C0) */ 

#define SYS_SET_D7PAD_FUNCTION     /* one of SYS_D7PAD_xxx  (XB_OUT11/XB_IN_7/XB_MISO1  ), package pin function selection (SIM_GPSDL->D7)*/ 
#define SYS_SET_D6PAD_FUNCTION     /* one of SYS_D6PAD_xxx  (TXD2/XB_IN4/XB_OUT8 ), package pin function selection (SIM_GPSDL->D6)*/ 
#define SYS_SET_D5PAD_FUNCTION     /* one of SYS_D5PAD_xxx  (MASK/XB_IN5/XB_OUT9 ), package pin function selection (SIM_GPSDL->D5)*/ 

#define SYS_SET_E9PAD_FUNCTION     /* one of SYS_E9PAD_xxx  (PWMA_FAULT1), package pin function selection (SIM_GPSEH->E9)*/
#define SYS_SET_E8PAD_FUNCTION     /* one of SYS_E8PAD_xxx  (PWMA_FAULT0), package pin function selection (SIM_GPSEH->E8)*/
#define SYS_SET_E7PAD_FUNCTION     /* one of SYS_E7PAD_xxx  (PWMA3A/XB_IN5), package pin function selection (SIM_GPSEH->E7)*/
#define SYS_SET_E6PAD_FUNCTION     /* one of SYS_E6PAD_xxx  (PWMB3B/XB_IN4), package pin function selection (SIM_GPSEH->E6)*/
#define SYS_SET_E5PAD_FUNCTION     /* one of SYS_E5PAD_xxx  (PWMA2A/XB_IN3), package pin function selection (SIM_GPSEH->E5)*/
#define SYS_SET_E4PAD_FUNCTION     /* one of SYS_E4PAD_xxx  (PWMB2B/XB_IN2), package pin function selection (SIM_GPSEH->E4)*/

#define SYS_SET_F15PAD_FUNCTION    /* one of SYS_F15PAD_xxx (RXD0/XB_IN10 ), package pin function selection (SIM_GPSFH->F15) */
#define SYS_SET_F14PAD_FUNCTION    /* one of SYS_F14PAD_xxx (SCLK1), package pin function selection (SIM_GPSFH->F14) */
#define SYS_SET_F13PAD_FUNCTION    /* one of SYS_F13PAD_xxx (MOSI1), package pin function selection (SIM_GPSFH->F13) */
#define SYS_SET_F12PAD_FUNCTION    /* one of SYS_F12PAD_xxx (MISO1), package pin function selection (SIM_GPSFH->F12) */
#define SYS_SET_F11PAD_FUNCTION    /* one of SYS_F11PAD_xxx (TXD0/XB_IN11), package pin function selection (SIM_GPSFH->F11) */
#define SYS_SET_F10PAD_FUNCTION    /* one of SYS_F10PAD_xxx (PWMA_FAULT6/XB_OUT10 ), package pin function selection (SIM_GPSFH->F10) */
#define SYS_SET_F9PAD_FUNCTION     /* one of SYS_F9PAD_xxx  (FAULT7/XB_OUT11), package pin function selection (SIM_GPSFH->F9) */
#define SYS_SET_F8PAD_FUNCTION     /* one of SYS_F8PAD_xxx  (RXD0/TB1/CMPD_O ), package pin function selection (SIM_GPSFH->F8) */
#define SYS_SET_F7PAD_FUNCTION     /* one of SYS_F7PAD_xxx  (CMPC_0/SS1_B/XB_IN3/TB3 ), package pin function selection (SIM_GPSFL->F7) */                         
#define SYS_SET_F6PAD_FUNCTION     /* one of SYS_F6PAD_xxx  (TB2/PWMA_3X/XB_IN2), package pin function selection (SIM_GPSFL->F6) */
#define SYS_SET_F5PAD_FUNCTION     /* one of SYS_F5PAD_xxx  (RXD1/XB_OUT9 ), package pin function selection (SIM_GPSFL->F5) */
#define SYS_SET_F4PAD_FUNCTION     /* one of SYS_F4PAD_xxx  (TXD1/XB_OUT8 ), package pin function selection (SIM_GPSFL->F4) */
#define SYS_SET_F3PAD_FUNCTION     /* one of SYS_F3PAD_xxx  (SDA1/XB_OUT7), package pin function selection (SIM_GPSFL->F3) */
#define SYS_SET_F2PAD_FUNCTION     /* one of SYS_F2PAD_xxx  (SCL1/XB_OUT6), package pin function selection (SIM_GPSFL->F2) */
#define SYS_SET_F1PAD_FUNCTION     /* one of SYS_F1PAD_xxx  (CLKOUT1 /XB_IN7 /CMPD_O), package pin function selection (SIM_GPSFL->F1) */
#define SYS_SET_F0PAD_FUNCTION     /* one of SYS_F0PAD_xxx  (XB_IN6/TB2/SCLK1 ), package pin function selection (SIM_GPSFL->F0) */

#define SYS_SET_G11PAD_FUNCTION    /* one of SYS_G11PAD_xxx (TB3/CLKOUT0/MOSI1 ), package pin function selection (SIM_GPSGH->G11) */
#define SYS_SET_G10PAD_FUNCTION    /* one of SYS_G10PAD_xxx (PWMA_2X/XB_IN8 ), package pin function selection (SIM_GPSGH->G10) */
#define SYS_SET_G9PAD_FUNCTION     /* one of SYS_G9PAD_xxx  (PWMA_1X/TA3/XB_OUT11 ), package pin function selection (SIM_GPSGH->G9) */
#define SYS_SET_G8PAD_FUNCTION     /* one of SYS_G8PAD_xxx  (PWMA_0X/TA2/XB_OUT10), package pin function selection (SIM_GPSGH->G8) */
#define SYS_SET_G7PAD_FUNCTION     /* one of SYS_G7PAD_xxx  (PWMA_FAULT5/XB_OUT9), package pin function selection (SIM_GPSGL->G7) */
#define SYS_SET_G6PAD_FUNCTION     /* one of SYS_G6PAD_xxx  (PWMA_FAULT4/TB2/XB_OUT8 ), package pin function selection (SIM_GPSGL->G6)*/
#define SYS_SET_G5PAD_FUNCTION     /* one of SYS_G5PAD_xxx  (PWMA_FAULT3), package pin function selection (SIM_GPSGL->G5)*/
#define SYS_SET_G4PAD_FUNCTION     /* one of SYS_G4PAD_xxx  (PWMA_FAULT2 ), package pin function selection (SIM_GPSGL->G4)*/
#define SYS_SET_G3PAD_FUNCTION     /* one of SYS_G3PAD_xxx  (XB_OUT5), package pin function selection (SIM_GPSGL->G3)*/
#define SYS_SET_G2PAD_FUNCTION     /* one of SYS_G2PAD_xxx  (XB_OUT4), package pin function selection (SIM_GPSGL->G2)*/
#define SYS_SET_G1PAD_FUNCTION     /* one of SYS_G1PAD_xxx  (XB_OUT7), package pin function selection (SIM_GPSGL->G1)*/
#define SYS_SET_G0PAD_FUNCTION     /* one of SYS_G0PAD_xxx  (XB_OUT6 ), package pin function selection (SIM_GPSGL->G0)*/

#define SYS_SET_TMRB3_INPUT        /* one of SYS_TMRB3_xxx  (GPIO_F7_G11/XB_OUT37), TMRB3 input selection (SIM_IPS0->TB3)*/
#define SYS_SET_TMRB2_INPUT        /* one of SYS_TMRB2_xxx  (GPIO_F6_F0_G6/XB_OUT36), TMRB2 input selection (SIM_IPS0->TB2)*/
#define SYS_SET_TMRB1_INPUT        /* one of SYS_TMRB1_xxx  (GPIO_F8/XB_OUT35 ), TMRB1 input selection (SIM_IPS0->TB1)*/
#define SYS_SET_TMRB0_INPUT        /* one of SYS_TMRB0_xxx  (GPIO_C2/XB_OUT34), TMRB0 input selection (SIM_IPS0->TB0)*/
#define SYS_SET_TMRA3_INPUT        /* one of SYS_TMRA3_xxx  (GPIO_C13_G9/XB_OUT52), TMRB3 input selection (SIM_IPS0->TA3)*/
#define SYS_SET_TMRA2_INPUT        /* one of SYS_TMRA2_xxx  (GPIO_C6_G8/TMRA2_XB_OUT51), TMRB2 input selection (SIM_IPS0->TA2)*/
#define SYS_SET_TMRA1_INPUT        /* one of SYS_TMRA1_xxx  (GPIO_C4/XB_OUT50), TMRB1 input selection (SIM_IPS0->TA1)*/
#define SYS_SET_TMRA0_INPUT        /* one of SYS_TMRA0_xxx  (GPIO_C3/XB_OUT49), TMRB0 input selection (SIM_IPS0->TA0)*/
#define SYS_SET_PWMAF3_INPUT       /* one of SYS_PWMAF3_xxx (GPIO_G5/XB_OUT32), SCI0 input selection (SIM_IPS0->PWMAF3)*/
#define SYS_SET_PWMAF2_INPUT       /* one of SYS_PWMAF2_xxx (GPIO_G4/XB_OUT31), SCI0 input selection (SIM_IPS0->PWMAF2)*/
#define SYS_SET_PWMAF1_INPUT       /* one of SYS_PWMAF1_xxx (GPIO_E9/XB_OUT30 ), SCI0 input selection (SIM_IPS0->PWMAF1)*/
#define SYS_SET_PWMAF0_INPUT       /* one of SYS_PWMAF0_xxx (GPIO_E8/XB_OUT29 ), SCI0 input selection (SIM_IPS0->PWMAF0)*/
#endif

#if SIM_VERSION == 8
#define SYS_PERIPH_SW_RESET         /* combination of SYS_xxx_PSWR (GPIO;TA;MSCAN;IIC0;QSPI1;QSPI0;SCI1;SCI0;DACA;DACB;PIT1;PIT0;CRC;CYCADC;CMP;EWM;PWMA), Issue software reset of peripheral (SIM_PSWR0->_,SIM_PSWR1->_,SIM_PSWR2->_,SIM_PSWR3->_) */
#define SYS_HS_CLOCK_ENABLE         /* combination of SYS_HS_xxx (IIC/PWM/TMR/SCI0/SCI1), enable high-speed clock (SIM_PCR->_)*/
#define SYS_HS_CLOCK_DISABLE        /* combination of SYS_HS_xxx (IIC/PWM/TMR/SCI0/SCI1), enable high-speed clock (SIM_PCR->_)*/

#define SYS_FAST_MODE           /* SYS_ENABLE/SYS_DISABLE, decide if the system will boot in fast mode(core:bus :: 2:1) or normal mode. (SIM_MISC0->FAST_MODE) */
#define SYS_ADC_REORDERING      /* SYS_ENABLE/SYS_DISABLE, enable the re-ordering of scan control bits of Cyclic ADC for test channels.(SIM_MISC0->ADC_SCTRL)*/
#define SYS_GET_FAST_MODE       /* NULL, return UWord16  TRUE-Fast mode, False-Normal mode  (SIM_MISC0->MODE_STAT) */

#define SYS_CLKOUT_1_SELECT        /* one of SYS_CLKOUT_1_xxx (BUSCLK/2X_BUSCLK/DIV4_BUSCLK/MSTR_OSC/ROSC_8M/ROSC_200K), select CLSKOUT_1 source */

#define SYS_SET_A0PAD_FUNCTION     /* one of SYS_A0PAD_xxx (ANA0_CMPA3/CMPC_O), package pin function selection  (SIM_GPSAL->A0) */ 
#define SYS_SET_B1PAD_FUNCTION     /* one of SYS__B1PAD_xxx (ANB1_CMPB_IN0/DACB ), package pin function selection (SIM_GPSBL->B1)*/ 

#define SYS_SET_C15PAD_FUNCTION    /* one of SYS_C15PAD_xxx (SCL0/XB_OUT5), package pin function selection (SIM_GPSCH->C15) */
#define SYS_SET_C14PAD_FUNCTION    /* one of SYS_C14PAD_xxx (SDA0/XB_OUT4/PWM_FAULT4), package pin function selection (SIM_GPSCH->C14) */
#define SYS_SET_C13PAD_FUNCTION    /* one of SYS_C13PAD_xxx (TA3/XB_IN6), package pin function selection (SIM_GPSCH->C13) */
#define SYS_SET_C12PAD_FUNCTION    /* one of SYS_C12PAD_xxx (SDA0/RXD1), package pin function selection (SIM_GPSCH->C12) */ 
#define SYS_SET_C11PAD_FUNCTION    /* one of SYS_C11PAD_xxx (TXD1/SCL0), package pin function selection (SIM_GPSCH->C11) */ 
#define SYS_SET_C10PAD_FUNCTION    /* one of SYS_C10PAD_xxx (XB_OUT9/MOSI0/XB_IN5/MISO0 ), package pin function selection (SIM_GPSCH->C10) */ 
#define SYS_SET_C9PAD_FUNCTION     /* one of SYS_C9PAD_xxx  (SCLK0/XB_IN4/XB_OUT8/TXD0), package pin function selection (SIM_GPSCH->C9) */
#define SYS_SET_C8PAD_FUNCTION     /* one of SYS_C8PAD_xxx  (XB_OUT6/RXD0/MISO0/XB_IN9), package pin function selection (SIM_GPSCH->C8) */
#define SYS_SET_C7PAD_FUNCTION     /* one of SYS_C7PAD_xxx  (SSB0_B/TXD0/XB_IN8), package pin function selection (SIM_GPSCL->C7) */
#define SYS_SET_C6PAD_FUNCTION     /* one of SYS_C6PAD_xxx  (TA2/XB_IN3/CMPREF/SS0_B), package pin function selection (SIM_GPSCL->C6) */ 
#define SYS_SET_C5PAD_FUNCTION     /* one of SYS_C5PAD_xxx  (DACA/XB_IN7), package pin function selection (SIM_GPSCL->C5) */
#define SYS_SET_C4PAD_FUNCTION     /* one of SYS_C4PAD_xxx  (TA1/CMPB_O/XB_IN6/EWM_OUT_B), package pin function selection (SIM_GPSCL->C4) */
#define SYS_SET_C3PAD_FUNCTION     /* one of SYS_C3PAD_xxx  (TA0/CMPA_O/RXD0/CLKIN1), package pin function selection (SIM_GPSCL->C3) */ 
#define SYS_SET_C2PAD_FUNCTION     /* one of SYS_C2PAD_xxx  (TXD0/XB_OUT11/XB_IN2/CLKOUT0), package pin function selection (SIM_GPSCL->C2) */ 
#define SYS_SET_C0PAD_FUNCTION     /* one of SYS_C0PAD_xxx  (EXTAL/CLKIN), package pin function selection (SIM_GPSCL->C1)*/

#define SYS_SET_E7PAD_FUNCTION     /* one of SYS_E7PAD_xxx  (PWMA3/XB_IN5), package pin function selection (SIM_GPSEH->E7)*/
#define SYS_SET_E6PAD_FUNCTION     /* one of SYS_E6PAD_xxx  (PWMB3/XB_IN4), package pin function selection (SIM_GPSEH->E6)*/
#define SYS_SET_E5PAD_FUNCTION     /* one of SYS_E5PAD_xxx  (PWMA2/XB_IN3), package pin function selection (SIM_GPSEH->E5)*/
#define SYS_SET_E4PAD_FUNCTION     /* one of SYS_E4PAD_xxx  (PWMB2/XB_IN2), package pin function selection (SIM_GPSEH->E4)*/

#define SYS_SET_F8PAD_FUNCTION     /* one of SYS_F8PAD_xxx  (RXD0/XB_OUT10/CMPDO/PWMA_2X), package pin function selection (SIM_GPSFH->F8) */
#define SYS_SET_F7PAD_FUNCTION     /* one of SYS_F7PAD_xxx  (XB_IN3/CMPC_O/SS1_B), package pin function selection (SIM_GPSGL->F7) */                         
#define SYS_SET_F6PAD_FUNCTION     /* one of SYS_F6PAD_xxx  (XB_IN2/PWMA_3X), package pin function selection (SIM_GPSGL->F6) */ 
#define SYS_SET_F5PAD_FUNCTION     /* one of SYS_F5PAD_xxx  (RXD1/XB_OUT9/PWMA_1X/PWMA_FAULT7), package pin function selection (SIM_GPSGL->F5) */ 
#define SYS_SET_F4PAD_FUNCTION     /* one of SYS_F4PAD_xxx  (XB_OUT8/TXD1/PWMA_0X/PWMA_FAULT6), package pin function selection (SIM_GPSGL->F4) */ 
#define SYS_SET_F3PAD_FUNCTION     /* one of SYS_F3PAD_xxx  (SDA0/XB_OUT7/MOSI1), package pin function selection (SIM_GPSGL->F3) */ 
#define SYS_SET_F2PAD_FUNCTION     /* one of SYS_F2PAD_xxx  (SCL0/XB_OUT6/MISO1), package pin function selection (SIM_GPSGL->F2) */ 
#define SYS_SET_F1PAD_FUNCTION     /* one of SYS_F1PAD_xxx  (CLKOUT1/XB_IN7/CMPD_O), package pin function selection (SIM_GPSGL->F1) */ 
#define SYS_SET_F0PAD_FUNCTION     /* one of SYS_F0PAD_xxx  (SCLK1/XB_IN6), package pin function selection (SIM_GPSGL->F0) */ 

#define SYS_SET_TMRA3_INPUT        /* one of SYS_TMRA3_xxx (GPIOC13/XB_OUT37), TMRA3 input selection (SIM_IPS0->TA3)*/
#define SYS_SET_TMRA2_INPUT        /* one of SYS_TMRA2_xxx (GPIOC6/XB_OUT36), TMRA2 input selection (SIM_IPS0->TA2)*/
#define SYS_SET_TMRA1_INPUT        /* one of SYS_TMRA1_xxx (GPIOC4/XB_OUT35), TMRA1 input selection (SIM_IPS0->TA1)*/
#define SYS_SET_TMRA0_INPUT        /* one of SYS_TMRA0_xxx (GPIOC3/XB_OUT34), TMRA0 input selection (SIM_IPS0->TA0)*/
#define SYS_SET_SCI1_INPUT         /* one of SYS_SCI1_xxx  (GPIOC12/XB_OUT39), SCI1 input selection (SIM_IPS0->SCI1)*/
#define SYS_SET_SCI0_INPUT         /* one of SYS_SCI0_xxx  (GPIOC3/XB_OUT38), SCI0 input selection (SIM_IPS0->SCI0)*/

#define SYS_WRITE_SW_CONTROL_REG4  /* UWord16, write SIM software control register 4 (SIM_SCR4->_) */
#define SYS_READ_SW_CONTROL_REG4   /* NULL, Read and return SIM software control register 4 as UWord16. (SIM_SCR4->_) */
#define SYS_WRITE_SW_CONTROL_REG5  /* UWord16, write SIM software control register 5 (SIM_SCR5->_) */
#define SYS_READ_SW_CONTROL_REG5   /* NULL, Read and return SIM software control register 4 as UWord16. (SIM_SCR5->_) */
#define SYS_WRITE_SW_CONTROL_REG6  /* UWord16, write SIM software control register 6 (SIM_SCR6->_) */
#define SYS_READ_SW_CONTROL_REG6   /* NULL, Read and return SIM software control register 4 as UWord16. (SIM_SCR6->_) */
#define SYS_WRITE_SW_CONTROL_REG7  /* UWord16, write SIM software control register 7 (SIM_SCR7->_) */
#define SYS_READ_SW_CONTROL_REG7   /* NULL, Read and return SIM software control register 4 as UWord16. (SIM_SCR7->_) */
#endif

#define SYS_WRITE_SW_CONTROL_REG0  /* UWord16, write SIM software control register 0 (SIM_SCR0->_) */
#define SYS_READ_SW_CONTROL_REG0   /* NULL, Read and return SIM software control register 4 as UWord16. (SIM_SCR0->_) */
#define SYS_WRITE_SW_CONTROL_REG1  /* UWord16, write SIM software control register 1 (SIM_SCR1->_) */
#define SYS_READ_SW_CONTROL_REG1   /* NULL, Read and return SIM software control register 4 as UWord16. (SIM_SCR1->_) */
#define SYS_WRITE_SW_CONTROL_REG2  /* UWord16, write SIM software control register 2 (SIM_SCR2->_) */
#define SYS_READ_SW_CONTROL_REG2   /* NULL, Read and return SIM software control register 4 as UWord16. (SIM_SCR2->_) */
#define SYS_WRITE_SW_CONTROL_REG3  /* UWord16, write SIM software control register 3 (SIM_SCR3->_) */
#define SYS_READ_SW_CONTROL_REG3   /* NULL, Read and return SIM software control register 4 as UWord16. (SIM_SCR3->_) */

/*****************************************************************
* Software Layer ioctl() commands
*
*  Word16 ioctl( SYS_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define SYS_INIT                   /* NULL, SIM & LVI registers initialization acc.to appconfig.h */



/****************************************************************************
* SYS constants and type declarations used in the ioctl functions
*****************************************************************************/

#define SYS_DISABLE           0
#define SYS_ENABLE            1

/* for permanent enable/disable */
#define SYS_DISABLE_PERMANENT 2
#define SYS_ENABLE_PERMANENT  3

/* High Speed clock enable in modules */

#define SYS_HS_SCI0  SIM_PCR_SCI0
#define SYS_HS_SCI1  SIM_PCR_SCI1

#define SYS_PIT1        0x01
#define SYS_PIT0        0x00
#define SYS_CLKIN0      0x00
#define SYS_CLKIN1      0x01

#define SYS_HS_TMRB  SIM_PCR_TMRB
#define SYS_HS_TMRA  SIM_PCR_TMRA

#if SIM_VERSION == 8
#define SYS_HS_TMR  SIM_PCR_TMR
#define SYS_HS_PWM  SIM_PCR_PWM
#define SYS_HS_IIC  SIM_PCR_IIC

#define SYS_COP_WINDOW_RESET  SIM_RSTSTS_COP_WINDOW
#endif 


/* reset sources */
#define SYS_SW_RESET        SIM_RSTSTS_SWR  
#define SYS_COP_RESET       (SIM_RSTSTS_COP_TOR | SIM_RSTSTS_COP_LOR)
#define SYS_COP_TOR_RESET   SIM_RSTSTS_COP_TOR
#define SYS_COP_LOR_RESET   SIM_RSTSTS_COP_LOR
#define SYS_EXTERN_RESET    SIM_RSTSTS_EXTR
#define SYS_POWER_ON_RESET  SIM_RSTSTS_POR  
#define SYS_ALL_RESETS      (SIM_RSTSTS_SWR | SIM_RSTSTS_COP_TOR | SIM_RSTSTS_COP_LOR | SIM_RSTSTS_EXTR | SIM_RSTSTS_POR)
#define SYS_ANY_RESET       SYS_ALL_RESETS

#if SIM_VERSION == 7
#define SYS_EZPORT_RESET  SIM_RSTSTS_EZPR
#endif


/* large regulator modes */
#define SYS_NORMAL_POWER            0
#define SYS_REDUCED_POWER           SIM_POWER_LRSTDBY0
#define SYS_POWER_MODE_PERMANENT    SIM_POWER_LRSTDBY1

#define SYS_POWERDOWN_MODE          SIM_POWER_LRSTDBY0

#define SYS_PCE0_REG_INDEX       0x10000000
#define SYS_PCE1_REG_INDEX       0x20000000
#define SYS_PCE2_REG_INDEX       0x40000000
#define SYS_PCE3_REG_INDEX       0x80000000

#define SYS_PSWR0_REG_INDEX       0x10000000
#define SYS_PSWR1_REG_INDEX       0x20000000
#define SYS_PSWR2_REG_INDEX       0x40000000
#define SYS_PSWR3_REG_INDEX       0x80000000


/* module clock-enables and modules in stop */

#if SIM_VERSION == 7
#define SYS_GPIOG_MOD   ((UWord32)(SIM_PCE0_GPIOG | SYS_PCE0_REG_INDEX))
#define SYS_GPIOF_MOD   ((UWord32)(SIM_PCE0_GPIOF | SYS_PCE0_REG_INDEX))
#define SYS_GPIOE_MOD   ((UWord32)(SIM_PCE0_GPIOE | SYS_PCE0_REG_INDEX))
#define SYS_GPIOD_MOD   ((UWord32)(SIM_PCE0_GPIOD | SYS_PCE0_REG_INDEX))
#define SYS_GPIOC_MOD   ((UWord32)(SIM_PCE0_GPIOC | SYS_PCE0_REG_INDEX))
#define SYS_GPIOB_MOD   ((UWord32)(SIM_PCE0_GPIOB | SYS_PCE0_REG_INDEX))
#define SYS_GPIOA_MOD   ((UWord32)(SIM_PCE0_GPIOA | SYS_PCE0_REG_INDEX))
#define SYS_TB3_MOD     ((UWord32)(SIM_PCE0_TB3 | SYS_PCE0_REG_INDEX))
#define SYS_TB2_MOD     ((UWord32)(SIM_PCE0_TB2 | SYS_PCE0_REG_INDEX))
#define SYS_TB1_MOD     ((UWord32)(SIM_PCE0_TB1 | SYS_PCE0_REG_INDEX))
#define SYS_TB0_MOD     ((UWord32)(SIM_PCE0_TB0 | SYS_PCE0_REG_INDEX))
#define SYS_TA3_MOD     ((UWord32)(SIM_PCE0_TA3 | SYS_PCE0_REG_INDEX))
#define SYS_TA2_MOD     ((UWord32)(SIM_PCE0_TA2 | SYS_PCE0_REG_INDEX))
#define SYS_TA1_MOD     ((UWord32)(SIM_PCE0_TA1 | SYS_PCE0_REG_INDEX))
#define SYS_TA0_MOD     ((UWord32)(SIM_PCE0_TA0 | SYS_PCE0_REG_INDEX))


#define SYS_FLEXCAN_MOD  ((UWord32)(SIM_PCE1_FLEXCAN | SYS_PCE1_REG_INDEX ))
#define SYS_IIC1_MOD     ((UWord32)(SIM_PCE1_IIC1 | SYS_PCE1_REG_INDEX))
#define SYS_IIC0_MOD     ((UWord32)(SIM_PCE1_IIC0 | SYS_PCE1_REG_INDEX))
#define SYS_QSPI1_MOD    ((UWord32)(SIM_PCE1_QSPI1  | SYS_PCE1_REG_INDEX))
#define SYS_QSPI0_MOD    ((UWord32)(SIM_PCE1_QSPI0  | SYS_PCE1_REG_INDEX))
#define SYS_SCI1_MOD     ((UWord32)(SIM_PCE1_SCI1 | SYS_PCE1_REG_INDEX))
#define SYS_SCI0_MOD     ((UWord32)(SIM_PCE1_SCI0 | SYS_PCE1_REG_INDEX))
#define SYS_DAC_MOD     ((UWord32)(SIM_PCE1_DAC | SYS_PCE1_REG_INDEX))

#define SYS_PDB1_MOD     ((UWord32)(SIM_PCE2_PDB1 | SYS_PCE2_REG_INDEX))
#define SYS_PDB0_MOD     ((UWord32)(SIM_PCE2_PDB0 | SYS_PCE2_REG_INDEX))
#define SYS_PIT1_MOD     ((UWord32)(SIM_PCE2_PIT1 | SYS_PCE2_REG_INDEX))
#define SYS_PIT0_MOD     ((UWord32)(SIM_PCE2_PIT0 | SYS_PCE2_REG_INDEX))
#define SYS_CRC_MOD      ((UWord32)(SIM_PCE2_CRC | SYS_PCE2_REG_INDEX))
#define SYS_CYCADC_MOD   ((UWord32)(SIM_PCE2_CYCADC | SYS_PCE2_REG_INDEX))
#define SYS_SARADC_MOD   ((UWord32)(SIM_PCE2_SARADC | SYS_PCE2_REG_INDEX))
#define SYS_CMPD_MOD     ((UWord32)(SIM_PCE2_CMPD | SYS_PCE2_REG_INDEX))
#define SYS_CMPC_MOD     ((UWord32)(SIM_PCE2_CMPC | SYS_PCE2_REG_INDEX))
#define SYS_CMPB_MOD     ((UWord32)(SIM_PCE2_CMPB | SYS_PCE2_REG_INDEX))
#define SYS_CMPA_MOD     ((UWord32)(SIM_PCE2_CMPA | SYS_PCE2_REG_INDEX))

#define SYS_PWMCH3_MOD   ((UWord32)(SIM_PCE2_PWMCH3 | SYS_PCE3_REG_INDEX))
#define SYS_PWMCH2_MOD   ((UWord32)(SIM_PCE2_PWMCH2 | SYS_PCE3_REG_INDEX))
#define SYS_PWMCH1_MOD   ((UWord32)(SIM_PCE2_PWMCH1 | SYS_PCE3_REG_INDEX))
#define SYS_PWMCH0_MOD   ((UWord32)(SIM_PCE2_PWMCH0 | SYS_PCE3_REG_INDEX))

#define SYS_GPIO_PSWR    ((UWord32)(SIM_PSWR_GPIO| SYS_PSWR0_REG_INDEX))
#define SYS_TB_PSWR      ((UWord32)(SIM_PSWR_TB | SYS_PSWR0_REG_INDEX))
#define SYS_TA_PSWR      ((UWord32)(SIM_PSWR_TA | SYS_PSWR0_REG_INDEX))
#define SYS_FLEXCAN_PSWR ((UWord32)(SIM_PSWR_FLEXCAN | SYS_PSWR1_REG_INDEX))
#define SYS_IIC1_PSWR    ((UWord32)(SIM_PSWR_IIC1 | SYS_PSWR1_REG_INDEX))
#define SYS_IIC0_PSWR    ((UWord32)(SIM_PSWR_IIC0 | SYS_PSWR1_REG_INDEX))
#define SYS_QSPI1_PSWR   ((UWord32)(SIM_PSWR_QSPI1 | SYS_PSWR1_REG_INDEX))
#define SYS_QSPI0_PSWR   ((UWord32)(SIM_PSWR_QSPI0 | SYS_PSWR1_REG_INDEX))
#define SYS_SCI1_PSWR    ((UWord32)(SIM_PSWR_SCI1 | SYS_PSWR1_REG_INDEX))
#define SYS_SCI0_PSWR    ((UWord32)(SIM_PSWR_SCI0 | SYS_PSWR1_REG_INDEX))
#define SYS_DAC_PSWR    ((UWord32)(SIM_PSWR_DAC | SYS_PSWR1_REG_INDEX))
#define SYS_PDB1_PSWR    ((UWord32)(SIM_PSWR_PDB1 | SYS_PSWR2_REG_INDEX))
#define SYS_PDB0_PSWR    ((UWord32)(SIM_PSWR_PDB0 | SYS_PSWR2_REG_INDEX))
#define SYS_PIT1_PSWR    ((UWord32)(SIM_PSWR_PIT1 | SYS_PSWR2_REG_INDEX))
#define SYS_PIT0_PSWR    ((UWord32)(SIM_PSWR_PIT0 | SYS_PSWR2_REG_INDEX))
#define SYS_QDC_PSWR     ((UWord32)(SIM_PSWR_QDC | SYS_PSWR2_REG_INDEX))
#define SYS_CRC_PSWR     ((UWord32)(SIM_PSWR_CRC | SYS_PSWR2_REG_INDEX))
#define SYS_CYCADC_PSWR  ((UWord32)(SIM_PSWR_CYCADC | SYS_PSWR2_REG_INDEX))
#define SYS_SARADC_PSWR  ((UWord32)(SIM_PSWR_SARADC | SYS_PSWR2_REG_INDEX))
#define SYS_CMP_PSWR     ((UWord32)(SIM_PSWR_CMP | SYS_PSWR2_REG_INDEX))
#define SYS_EWM_PSWR     ((UWord32)(SIM_PSWR_EWM | SYS_PSWR2_REG_INDEX))
#define SYS_PWMA_PSWR    ((UWord32)(SIM_PSWR_PWMA | SYS_PSWR3_REG_INDEX))

#endif


#if SIM_VERSION == 8
#define SYS_GPIOF_MOD   ((UWord32)(SIM_PCE0_GPIOF | SYS_PCE0_REG_INDEX))
#define SYS_GPIOE_MOD   ((UWord32)(SIM_PCE0_GPIOE | SYS_PCE0_REG_INDEX))
#define SYS_GPIOD_MOD   ((UWord32)(SIM_PCE0_GPIOD | SYS_PCE0_REG_INDEX))
#define SYS_GPIOC_MOD   ((UWord32)(SIM_PCE0_GPIOC | SYS_PCE0_REG_INDEX))
#define SYS_GPIOB_MOD   ((UWord32)(SIM_PCE0_GPIOB | SYS_PCE0_REG_INDEX))
#define SYS_GPIOA_MOD   ((UWord32)(SIM_PCE0_GPIOA | SYS_PCE0_REG_INDEX))
#define SYS_TA3_MOD     ((UWord32)(SIM_PCE0_TA3 | SYS_PCE0_REG_INDEX))
#define SYS_TA2_MOD     ((UWord32)(SIM_PCE0_TA2 | SYS_PCE0_REG_INDEX))
#define SYS_TA1_MOD     ((UWord32)(SIM_PCE0_TA1 | SYS_PCE0_REG_INDEX))
#define SYS_TA0_MOD     ((UWord32)(SIM_PCE0_TA0 | SYS_PCE0_REG_INDEX))

#define SYS_MSCAN_MOD    ((UWord32)(SIM_PCE1_MSCAN | SYS_PCE1_REG_INDEX ))
#define SYS_IIC0_MOD     ((UWord32)(SIM_PCE1_IIC0 | SYS_PCE1_REG_INDEX))
#define SYS_QSPI1_MOD    ((UWord32)(SIM_PCE1_QSPI1  | SYS_PCE1_REG_INDEX))
#define SYS_QSPI0_MOD    ((UWord32)(SIM_PCE1_QSPI0  | SYS_PCE1_REG_INDEX))
#define SYS_SCI1_MOD     ((UWord32)(SIM_PCE1_SCI1 | SYS_PCE1_REG_INDEX))
#define SYS_SCI0_MOD     ((UWord32)(SIM_PCE1_SCI0 | SYS_PCE1_REG_INDEX))
#define SYS_DACA_MOD     ((UWord32)(SIM_PCE1_DACA | SYS_PCE1_REG_INDEX))
#define SYS_DACB_MOD     ((UWord32)(SIM_PCE1_DACB | SYS_PCE1_REG_INDEX))

#define SYS_PIT1_MOD     ((UWord32)(SIM_PCE2_PIT1 | SYS_PCE2_REG_INDEX))
#define SYS_PIT0_MOD     ((UWord32)(SIM_PCE2_PIT0 | SYS_PCE2_REG_INDEX))
#define SYS_CRC_MOD      ((UWord32)(SIM_PCE2_CRC | SYS_PCE2_REG_INDEX))
#define SYS_CYCADC_MOD   ((UWord32)(SIM_PCE2_CYCADC | SYS_PCE2_REG_INDEX))
#define SYS_CMPD_MOD     ((UWord32)(SIM_PCE2_CMPD | SYS_PCE2_REG_INDEX))
#define SYS_CMPC_MOD     ((UWord32)(SIM_PCE2_CMPC | SYS_PCE2_REG_INDEX))
#define SYS_CMPB_MOD     ((UWord32)(SIM_PCE2_CMPB | SYS_PCE2_REG_INDEX))
#define SYS_CMPA_MOD     ((UWord32)(SIM_PCE2_CMPA | SYS_PCE2_REG_INDEX))

#define SYS_PWMCH3_MOD   ((UWord32)(SIM_PCE2_PWMCH3 | SYS_PCE3_REG_INDEX))
#define SYS_PWMCH2_MOD   ((UWord32)(SIM_PCE2_PWMCH2 | SYS_PCE3_REG_INDEX))
#define SYS_PWMCH1_MOD   ((UWord32)(SIM_PCE2_PWMCH1 | SYS_PCE3_REG_INDEX))
#define SYS_PWMCH0_MOD   ((UWord32)(SIM_PCE2_PWMCH0 | SYS_PCE3_REG_INDEX))

#define SYS_GPIO_PSWR   ((UWord32)(SIM_PSWR_GPIO | SYS_PSWR0_REG_INDEX))
#define SYS_TA_PSWR     ((UWord32)(SIM_PSWR_TA | SYS_PSWR0_REG_INDEX))
#define SYS_MSCAN_PSWR  ((UWord32)(SIM_PSWR_MSCAN | SYS_PSWR1_REG_INDEX))
#define SYS_IIC0_PSWR   ((UWord32)(SIM_PSWR_IIC0 | SYS_PSWR1_REG_INDEX))
#define SYS_QSPI1_PSWR  ((UWord32)(SIM_PSWR_QSPI1 | SYS_PSWR1_REG_INDEX))
#define SYS_QSPI0_PSWR  ((UWord32)(SIM_PSWR_QSPI0 | SYS_PSWR1_REG_INDEX))
#define SYS_SCI1_PSWR   ((UWord32)(SIM_PSWR_SCI1 | SYS_PSWR1_REG_INDEX))
#define SYS_SCI0_PSWR   ((UWord32)(SIM_PSWR_SCI0 | SYS_PSWR1_REG_INDEX))
#define SYS_DACA_PSWR   ((UWord32)(SIM_PSWR_DACA | SYS_PSWR1_REG_INDEX))
#define SYS_DACB_PSWR   ((UWord32)(SIM_PSWR_DACB | SYS_PSWR1_REG_INDEX))
#define SYS_PIT1_PSWR   ((UWord32)(SIM_PSWR_PIT1 | SYS_PSWR2_REG_INDEX))
#define SYS_PIT0_PSWR   ((UWord32)(SIM_PSWR_PIT0 | SYS_PSWR2_REG_INDEX))
#define SYS_CRC_PSWR    ((UWord32)(SIM_PSWR_CRC | SYS_PSWR2_REG_INDEX))
#define SYS_CYCADC_PSWR ((UWord32)(SIM_PSWR_CYCADC | SYS_PSWR2_REG_INDEX))
#define SYS_CMP_PSWR    ((UWord32)(SIM_PSWR_CMP | SYS_PSWR2_REG_INDEX))
#define SYS_EWM_PSWR    ((UWord32)(SIM_PSWR_EWM | SYS_PSWR2_REG_INDEX))
#define SYS_PWMA_PSWR   ((UWord32)(SIM_PSWR_PWMA | SYS_PSWR3_REG_INDEX))

#endif 


#if SIM_VERSION == 8
/* pad functions */
#define SYS_A0PAD_ANA0_CMPA3     SIM_GPSAL_A0_ANA0_CMPA3 
#define SYS_A0PAD_CMPC_O         SIM_GPSAL_A0_CMPC_O    

#define SYS_B1PAD_ANB1_CMPB_IN0  SIM_GPSBL_B1_ANB1_CMPB_IN0
#define SYS_B1PAD_DACB           SIM_GPSBL_B1_DACB    

#define SYS_C15PAD_SCL0          SIM_GPSCH_C15_SCL0       
#define SYS_C15PAD_XB_OUT5       SIM_GPSCH_C15_XB_OUT5

#define SYS_C14PAD_SDA0          SIM_GPSCH_C14_SDA0       
#define SYS_C14PAD_XB_OUT4       SIM_GPSCH_C14_XB_OUT4 
#define SYS_C14PAD_PWM_FAULT4    SIM_GPSCH_C14_PWM_FAULT4   
                                 
#define SYS_C13PAD_TA3           SIM_GPSCH_C13_TA3        
#define SYS_C13PAD_XB_IN6        SIM_GPSCH_C13_XB_IN6     
#define SYS_C13PAD_EWM_OUTB      SIM_GPSCH_C13_EWM_OUTB     
                                 
#define SYS_C12PAD_SDA0          SIM_GPSCH_C12_SDA0       
#define SYS_C12PAD_RXD1          SIM_GPSCH_C12_RXD1       
                                 
#define SYS_C11PAD_TXD1          SIM_GPSCH_C11_TXD1        
#define SYS_C11PAD_SCL0          SIM_GPSCH_C11_SCL0     
                                 
#define SYS_C10PAD_XB_OUT9       SIM_GPSCH_C10_XB_OUT9      
#define SYS_C10PAD_MOSI0         SIM_GPSCH_C10_MOSI0      
#define SYS_C10PAD_XB_IN5        SIM_GPSCH_C10_XB_IN5     
#define SYS_C10PAD_MISO0         SIM_GPSCH_C10_MISO0 
                                 
#define SYS_C9PAD_SCLK0          SIM_GPSCH_C9_SCLK0       
#define SYS_C9PAD_XB_IN4         SIM_GPSCH_C9_XB_IN4      
#define SYS_C9PAD_XB_OUT8        SIM_GPSCH_C9_XB_OUT8       
#define SYS_C9PAD_TXD0           SIM_GPSCH_C9_TXD0     

#define SYS_C8PAD_XB_OUT6        SIM_GPSCH_C8_XB_OUT6       
#define SYS_C8PAD_RXD0           SIM_GPSCH_C8_RXD0  
#define SYS_C8PAD_MISO0          SIM_GPSCH_C8_MISO0       
#define SYS_C8PAD_XB_IN9         SIM_GPSCH_C8_XB_IN9
  
#define SYS_C7PAD_SSB0_B         SIM_GPSCL_C7_SSB0_B      
#define SYS_C7PAD_TXD0           SIM_GPSCL_C7_TXD0  
#define SYS_C7PAD_XB_IN8         SIM_GPSCL_C7_XB_IN8       

#define SYS_C6PAD_TA2            SIM_GPSCL_C6_TA2         
#define SYS_C6PAD_XB_IN3         SIM_GPSCL_C6_XB_IN3      
#define SYS_C6PAD_CMPREF         SIM_GPSCL_C6_CMPREF  
#define SYS_C6PAD_SS0_B          SIM_GPSCL_C6_SS0_B 

#define SYS_C5PAD_DACA           SIM_GPSCL_C5_DACA        
#define SYS_C5PAD_XB_IN7         SIM_GPSCL_C5_XB_IN7  
                                 
#define SYS_C4PAD_TA1            SIM_GPSCL_C4_TA1         
#define SYS_C4PAD_CMPB_O         SIM_GPSCL_C4_CMPB_O    
#define SYS_C4PAD_XB_IN6         SIM_GPSCL_C4_XB_IN6         
#define SYS_C4PAD_EWM_OUT_B      SIM_GPSCL_C4_EWM_OUT_BO 
                                 
#define SYS_C3PAD_TA0            SIM_GPSCL_C3_TA0         
#define SYS_C3PAD_CMPA_O         SIM_GPSCL_C3_CMPA_O      
#define SYS_C3PAD_RXD0           SIM_GPSCL_C3_RXD0 
#define SYS_C3PAD_CLKIN1         SIM_GPSCL_C3_CLKIN1
                                        
#define SYS_C2PAD_TXD0           SIM_GPSCL_C2_TXD0        
#define SYS_C2PAD_XB_OUT11       SIM_GPSCL_C2_XB_OUT11         
#define SYS_C2PAD_XB_IN2         SIM_GPSCL_C2_XB_IN2      
#define SYS_C2PAD_CLKOUT0        SIM_GPSCL_C2_CLKOUT0  
                                        
#define SYS_C0PAD_EXTAL          SIM_GPSCL_C0_EXTAL        
#define SYS_C0PAD_CLKIN          SIM_GPSCL_C0_CLKIN  

#define SYS_E7PAD_PWMA3A         SIM_GPSEL_E7_PWMA3A       
#define SYS_E7PAD_XB_IN5         SIM_GPSEL_E7_XB_IN5  

#define SYS_E6PAD_PWMB3B         SIM_GPSEL_E6_PWMB3B       
#define SYS_E6PAD_XB_IN4         SIM_GPSEL_E6_XB_IN4   

#define SYS_E5PAD_PWMA2A         SIM_GPSEL_E5_PWMA2A       
#define SYS_E5PAD_XB_IN3         SIM_GPSEL_E5_XB_IN3   

#define SYS_E4PAD_PWMB2B         SIM_GPSEL_E4_PWMB2B       
#define SYS_E4PAD_XB_IN2         SIM_GPSEL_E4_XB_IN2  

#define SYS_F8PAD_RXD0           SIM_GPSFH_F8_RXD0       
#define SYS_F8PAD_XB_OUT10       SIM_GPSFH_F8_OUT10 
#define SYS_F8PAD_CMPDO          SIM_GPSFH_F8_CMPDO  
#define SYS_F8PAD_PWMA_2X        SIM_GPSFH_F8_PWMA_2X
                                        
#define SYS_F7PAD_XB_IN3         SIM_GPSFL_F7_XB_IN3 
#define SYS_F7PAD_CMPC_O         SIM_GPSFL_F7_CMPC_0  
#define SYS_F7PAD_SS1_B          SIM_GPSFL_F7_SS1_B
                                        
#define SYS_F6PAD_XB_IN2         SIM_GPSFL_F6_XB_IN2         
#define SYS_F6PAD_PWMA_3X        SIM_GPSFL_F6_PWMA_3X  
                                        
#define SYS_F5PAD_RXD1           SIM_GPSFL_F5_RXD1        
#define SYS_F5PAD_XB_OUT9        SIM_GPSFL_F5_XB_OUT9  
#define SYS_F5PAD_PWMA_1X        SIM_GPSFL_F5_PWMA_1X
#define SYS_F5PAD_PWMA_FAULT7    SIM_GPSFL_F5_PWMA_FAULT7                                       

#define SYS_F4PAD_XB_OUT8        SIM_GPSFL_F4_XB_OUT8     
#define SYS_F4PAD_TXD1           SIM_GPSFL_F4_TXD1 
#define SYS_F4PAD_PWMA_0X        SIM_GPSFL_F4_PWMA_0X
#define SYS_F4PAD_PWMA_FAULT6    SIM_GPSFL_F4_PWMA_FAULT6

#define SYS_F3PAD_SDA0           SIM_GPSFL_F3_SDA0        
#define SYS_F3PAD_XB_OUT7        SIM_GPSFL_F3_XB_OUT7  
#define SYS_F3PAD_MOSI1          SIM_GPSFL_F3_MOSI1 

#define SYS_F2PAD_SCL0           SIM_GPSFL_F2_SCL0        
#define SYS_F2PAD_XB_OUT6        SIM_GPSFL_F2_XB_OUT6
#define SYS_F2PAD_MISO1          SIM_GPSFL_F2_MISO1 

#define SYS_F1PAD_CLKOUT1        SIM_GPSFL_F1_CLKOUT1      
#define SYS_F1PAD_XB_IN7         SIM_GPSFL_F1_XB_IN7  
#define SYS_F1PAD_CMPD_O         SIM_GPSFL_F1_CMPD_O  

#define SYS_F0PAD_SCLK1          SIM_GPSFL_F0_SCLK1      
#define SYS_F0PAD_XB_IN6         SIM_GPSFL_F0_XB_IN6 


#define SYS_TMRA3               SIM_IPSN_TMRA3             
#define SYS_TMRA2               SIM_IPSN_TMRA2             
#define SYS_TMRA1               SIM_IPSN_TMRA1             
#define SYS_TMRA0               SIM_IPSN_TMRA0             
#define SYS_SCI1                SIM_IPSN_SCI1              
#define SYS_SCI0                SIM_IPSN_SCI0              

#define SYS_TMRA3_GPIOC13       SIM_IPSN_TMRA3_GPIOC13     
#define SYS_TMRA3_XB_OUT37      SIM_IPSN_TMRA3_XB_OUT37    
#define SYS_TMRA2_GPIOC6        SIM_IPSN_TMRA2_GPIOC6      
#define SYS_TMRA2_XB_OUT36      SIM_IPSN_TMRA2_XB_OUT36    
#define SYS_TMRA1_GPIOC4        SIM_IPSN_TMRA1_GPIOC4      
#define SYS_TMRA1_XB_OUT35      SIM_IPSN_TMRA1_XB_OUT35    
#define SYS_TMRA0_GPIOC3        SIM_IPSN_TMRA0_GPIOC3      
#define SYS_TMRA0_XB_OUT34      SIM_IPSN_TMRA0_XB_OUT34    
#define SYS_SCI1_GPIOC12        SIM_IPSN_SCI1_GPIOC12      
#define SYS_SCI1_XB_OUT39       SIM_IPSN_SCI1_XB_OUT39     
#define SYS_SCI0_GPIOC3         SIM_IPSN_SCI0_GPIOC3       
#define SYS_SCI0_XB_OUT38       SIM_IPSN_SCI0_XB_OUT38     

#endif 

#if SIM_VERSION == 7

#define SYS_A0PAD_ANA0_CMPA3          SIM_GPSAL_A0_ANA0_CMPA3  
#define SYS_A0PAD_CMPC_O              SIM_GPSAL_A0_CMPC_O      
                                       
#define SYS_B11PAD_ANC15              SIM_GPSBH_B11_ANC15      
#define SYS_B11PAD_XB_IN7             SIM_GPSBH_B11_XB_IN7     
                                    
#define SYS_B10PAD_ANC14              SIM_GPSBH_B10_ANC14      
#define SYS_B10PAD_XB_IN8             SIM_GPSBH_B10_XB_IN8     
                                     
#define SYS_B9_PADANC13               SIM_GPSBH_B9_ANC13       
#define SYS_B9_PADXB_IN9              SIM_GPSBH_B9_XB_IN9      
                                     
#define SYS_C15PAD                    SIM_GPSCH_C15            
#define SYS_C15PAD_XB_OUT5            SIM_GPSCH_C15_XB_OUT5    
#define SYS_C15PAD_PWM_SCL0           SIM_GPSCH_C15_PWM_SCL0   
                                     
#define SYS_C14PAD                    SIM_GPSCH_C14            
#define SYS_C14PAD_SDA0               SIM_GPSCH_C14_SDA0       
#define SYS_C14PAD_XB_OUT4            SIM_GPSCH_C14_XB_OUT4    
                                       
#define SYS_C13PAD_TA3                SIM_GPSCH_C13_TA3        
#define SYS_C13PAD_XB_IN6             SIM_GPSCH_C13_XB_IN6     
#define SYS_C13PAD_EWM_OUTB           SIM_GPSCH_C13_EWM_OUTB   
                                          
#define SYS_C12PAD_CANRX              SIM_GPSCH_C12_CANRX      
#define SYS_C12PAD_SDA1               SIM_GPSCH_C12_SDA1       
#define SYS_C12PAD_RXD1               SIM_GPSCH_C12_RXD1       
                                     
#define SYS_C11PAD_SCL1               SIM_GPSCH_C11_SCL1       
#define SYS_C11PAD_TXD1               SIM_GPSCH_C11_TXD1       
#define SYS_C11PAD_CANTX              SIM_GPSCH_C11_CANTX      
                                   
#define SYS_C10PAD_MASK               SIM_GPSCH_C10_MASK       
#define SYS_C10PAD_MOSI0              SIM_GPSCH_C10_MOSI0      
#define SYS_C10PAD_XB_IN5             SIM_GPSCH_C10_XB_IN5     
#define SYS_C10PAD_MISO0              SIM_GPSCH_C10_MISO0      
                                                  
#define SYS_C9PAD_XB_IN4              SIM_GPSCH_C9_XB_IN4      
#define SYS_C9PAD_SCLK0               SIM_GPSCH_C9_SCLK0       
                                    
#define SYS_C8PAD_MISO0               SIM_GPSCH_C8_MISO0       
#define SYS_C8PAD_RXD0                SIM_GPSCH_C8_RXD0        
#define SYS_C8PAD_XB_IN9              SIM_GPSCH_C8_XB_IN9                                                    
                                    
#define SYS_C7PAD_SSB0_B              SIM_GPSCL_C7_SSB0_B      
#define SYS_C7PAD_TXD0                SIM_GPSCL_C7_TXD0        
                                                   
#define SYS_C6PAD_TA2                 SIM_GPSCL_C6_TA2         
#define SYS_C6PAD_XB_IN3              SIM_GPSCL_C6_XB_IN3      
#define SYS_C6PAD_CMPREF              SIM_GPSCL_C6_CMPREF      
                                    
#define SYS_C5PAD_DAC0                SIM_GPSCL_C5_DAC0        
#define SYS_C5PAD_XB_IN7              SIM_GPSCL_C5_XB_IN7      
                                    
#define SYS_C4PAD_TA1                 SIM_GPSCL_C4_TA1         
#define SYS_C4PAD_CMPB_O              SIM_GPSCL_C4_CMPB_O      
#define SYS_C4PAD_XB_IN8              SIM_GPSCL_C4_XB_IN8      
#define SYS_C4PAD_EWM_OUT_B           SIM_GPSCL_C4_EWM_OUT_B   
                                    
#define SYS_C3PAD_TA0                 SIM_GPSCL_C3_TA0         
#define SYS_C3PAD_CMPA_O              SIM_GPSCL_C3_CMPA_O      
#define SYS_C3PAD_RXD0                SIM_GPSCL_C3_RXD0        
#define SYS_C3PAD_CLKIN1              SIM_GPSCL_C3_CLKIN1      
                                    
#define SYS_C2PAD_TXD0                SIM_GPSCL_C2_TXD0        
#define SYS_C2PAD_TB0                 SIM_GPSCL_C2_TB0         
#define SYS_C2PAD_XB_IN2              SIM_GPSCL_C2_XB_IN2      
#define SYS_C2PAD_CLKOUT0             SIM_GPSCL_C2_CLKOUT0     
                                    
#define SYS_C0PAD_EXTAL               SIM_GPSCL_C0_EXTAL       
#define SYS_C0PAD_CLKIN               SIM_GPSCL_C0_CLKIN       
                                                                    
#define SYS_D7PAD_XB_OUT11            SIM_GPSDL_D7_XB_OUT11    
#define SYS_D7PAD_XB_IN_7             SIM_GPSDL_D7_XB_IN_7     
#define SYS_D7PAD_XB_MISO1            SIM_GPSDL_D7_XB_MISO1    
                                    
#define SYS_D6PAD_TXD2                SIM_GPSDL_D6_TXD2        
#define SYS_D6PAD_XB_IN4              SIM_GPSDL_D6_XB_IN4      
#define SYS_D6PAD_XB_OUT8             SIM_GPSDL_D6_XB_OUT8     
                                    
#define SYS_D5PAD_MASK                SIM_GPSDL_D5_MASK        
#define SYS_D5PAD_XB_IN5              SIM_GPSDL_D5_XB_IN5      
#define SYS_D5PAD_XB_OUT9             SIM_GPSDL_D5_XB_OUT9     
                                                    
#define SYS_E9PAD_PWMA_FAULT1         SIM_GPSEH_E9_PWMA_FAULT1                                       
                                    
#define SYS_E8PAD_PWMA_FAULT0         SIM_GPSEH_E8_PWMA_FAULT0 
                                    
#define SYS_E7PAD_PWMA3A              SIM_GPSEL_E7_PWMA3A      
#define SYS_E7PAD_XB_IN5              SIM_GPSEL_E7_XB_IN5      
                                           
#define SYS_E6PAD_PWMB3B              SIM_GPSEL_E6_PWMB3B      
#define SYS_E6PAD_XB_IN4              SIM_GPSEL_E6_XB_IN4      
                                    
#define SYS_E5PAD_PWMA2A              SIM_GPSEL_E5_PWMA2A      
#define SYS_E5PAD_XB_IN3              SIM_GPSEL_E5_XB_IN3      
                                                    
#define SYS_E4PAD_PWMB2B              SIM_GPSEL_E4_PWMB2B      
#define SYS_E4PAD_XB_IN2              SIM_GPSEL_E4_XB_IN2      
                                    
#define SYS_F15PAD_RXD0               SIM_GPSFH_F15_RXD0       
#define SYS_F15PAD_XB_IN10            SIM_GPSFH_F15_XB_IN10                                           
                                    
#define SYS_F14PAD_SCLK1              SIM_GPSFH_F14_SCLK1      
                                    
#define SYS_F13PAD_MOSI1              SIM_GPSFH_F13_MOSI1      
                                    
#define SYS_F12PAD_MISO1              SIM_GPSFH_F12_MISO1      
                                    
#define SYS_F11PAD_TXD0               SIM_GPSFH_F11_TXD0       
#define SYS_F11PAD_XB_IN11            SIM_GPSFH_F11_XB_IN11    
                                    
#define SYS_F10PAD_PWMA_FAULT6        SIM_GPSFH_F10_PWMA_FAULT6
#define SYS_F10PAD_XB_OUT10           SIM_GPSFH_F10_XB_OUT10   
     
#define SYS_F9PAD_FAULT7              SIM_GPSFH_F9_FAULT7      
#define SYS_F9PAD_XB_OUT11            SIM_GPSFH_F9_XB_OUT11    
             
#define SYS_F8PAD_RXD0                SIM_GPSFH_F8_RXD0        
#define SYS_F8PAD_TB1                 SIM_GPSFH_F8_TB1         
#define SYS_F8PAD_CMPD_O              SIM_GPSFH_F8_CMPD_O                                             
             
#define SYS_F7PAD_CMPC_0              SIM_GPSFL_F7_CMPC_0      
#define SYS_F7PAD_SS1_B               SIM_GPSFL_F7_SS1_B       
#define SYS_F7PAD_XB_IN3              SIM_GPSFL_F7_XB_IN3  
#define SYS_F7PAD_TB3                 SIM_GPSFL_F7_TB3
            
#define SYS_F6PAD_TB2                 SIM_GPSFL_F6_TB2         
#define SYS_F6PAD_PWMA_3X             SIM_GPSFL_F6_PWMA_3X     
#define SYS_F6PAD_XB_IN2              SIM_GPSFL_F6_XB_IN2      
            
#define SYS_F5PAD_RXD1                SIM_GPSFL_F5_RXD1        
#define SYS_F5PAD_XB_OUT9             SIM_GPSFL_F5_XB_OUT9     
            
#define SYS_F4PAD_TXD1                SIM_GPSFL_F4_TXD1        
#define SYS_F4PAD_XB_OUT8             SIM_GPSFL_F4_XB_OUT8     
             
#define SYS_F3PAD_SDA1                SIM_GPSFL_F3_SDA1        
#define SYS_F3PAD_XB_OUT7             SIM_GPSFL_F3_XB_OUT7     
             
#define SYS_F2PAD_SCL1                SIM_GPSFL_F2_SCL1        
#define SYS_F2PAD_XB_OUT6             SIM_GPSFL_F2_XB_OUT6     
            
#define SYS_F1PAD_CLKOUT1             SIM_GPSFL_F1_CLKOUT1     
#define SYS_F1PAD_XB_IN7              SIM_GPSFL_F1_XB_IN7      
#define SYS_F1PAD_CMPD_O              SIM_GPSFL_F1_CMPD_O      
            
#define SYS_F0PAD_XB_IN6              SIM_GPSFL_F0_XB_IN6      
#define SYS_F0PAD_TB2                 SIM_GPSFL_F0_TB2         
#define SYS_F0PAD_SCLK1               SIM_GPSFL_F0_SCLK1       
             
#define SYS_G7PAD_PWMA_FAULT5         SIM_GPSGL_G7_PWMA_FAULT5 
#define SYS_G7PAD_XB_OUT9             SIM_GPSGL_G7_XB_OUT9     
             
#define SYS_G6PAD_PWMA_FAULT4         SIM_GPSGL_G6_PWMA_FAULT4 
#define SYS_G6PAD_TB2                 SIM_GPSGL_G6_TB2         
#define SYS_G6PAD_XB_OUT8             SIM_GPSGL_G6_XB_OUT8     
             
#define SYS_G5PAD_PWMA_FAULT3         SIM_GPSGL_G5_PWMA_FAULT3 
             
#define SYS_G4PAD_PWMA_FAULT2         SIM_GPSGL_G4_PWMA_FAULT2 
             
#define SYS_G3PAD_XB_OUT5             SIM_GPSGL_G3_XB_OUT5     
             
#define SYS_G2PAD_XB_OUT4             SIM_GPSGL_G2_XB_OUT4     
             
#define SYS_G1PAD_XB_OUT7             SIM_GPSGL_G1_XB_OUT7     
             
#define SYS_G0PAD_XB_OUT6             SIM_GPSGL_G0_XB_OUT6     
    
#define SYS_G11PAD_TB3                SIM_GPSGH_G11_TB3        
#define SYS_G11PAD_CLKOUT0            SIM_GPSGH_G11_CLKOUT0    
#define SYS_G11PAD_MOSI1              SIM_GPSGH_G11_MOSI1      
              
#define SYS_G10PAD_PWMA_2X            SIM_GPSGH_G10_PWMA_2X    
#define SYS_G10PAD_XB_IN8             SIM_GPSGH_G10_XB_IN8     
     
#define SYS_G9PAD_PWMA_1X             SIM_GPSGH_G9_PWMA_1X     
#define SYS_G9PAD_TA3                 SIM_GPSGH_G9_TA3         
#define SYS_G9PAD_XB_OUT11            SIM_GPSGH_G9_XB_OUT11    
                                  
#define SYS_G8PAD_PWMA_0X             SIM_GPSGH_G8_PWMA_0X     
#define SYS_G8PAD_TA2                 SIM_GPSGH_G8_TA2         
#define SYS_G8PAD_XB_OUT10            SIM_GPSGH_G8_XB_OUT10    

                         
#define SYS_TMRB3_GPIO_F7_G11         SIM_IPS0_TMRB3_GPIO_F7_G11 
#define SYS_TMRB3_XB_OUT37            SIM_IPS0_TMRB3_XB_OUT37    
                                                    
#define SYS_TMRB2_GPIO_F6_F0_G6       SIM_IPS0_TMRB2_GPIO_F6_F0_G6
#define SYS_TMRB2_XB_OUT36            SIM_IPS0_TMRB2_XB_OUT36    
                                   
#define SYS_TMRB1_GPIO_F8             SIM_IPS0_TMRB1_GPIO_F8     
#define SYS_TMRB1_XB_OUT35            SIM_IPS0_TMRB1_XB_OUT35    
                                   
#define SYS_TMRB0_GPIO_C2             SIM_IPS0_TMRB0_GPIO_C2     
#define SYS_TMRB0_XB_OUT34            SIM_IPS0_TMRB0_XB_OUT34    
                                   
#define SYS_TMRA3_GPIO_C13_G9         SIM_IPS0_TMRA3_GPIO_C13_G9 
#define SYS_TMRA3_XB_OUT52            SIM_IPS0_TMRA3_XB_OUT52    
                                   
#define SYS_TMRA2_GPIO_C6_G8          SIM_IPS0_TMRA2_GPIO_C6_G8  
#define SYS_TMRA2_XB_OUT51            SIM_IPS0_TMRA2_XB_OUT51    
                                   
#define SYS_TMRA1_GPIO_C4             SIM_IPS0_TMRA1_GPIO_C4     
#define SYS_TMRA1_XB_OUT50            SIM_IPS0_TMRA1_XB_OUT50    
                                   
#define SYS_TMRA0_GPIO_C3             SIM_IPS0_TMRA0_GPIO_C3     
#define SYS_TMRA0_XB_OUT49            SIM_IPS0_TMRA0_XB_OUT49    
           
#define SYS_PWMAF3_GPIO_G5            SIM_IPS0_PWMAF3_GPIO_G5  
#define SYS_PWMAF3_XB_OUT32           SIM_IPS0_PWMAF3_XB_OUT32 
           
#define SYS_PWMAF2_GPIO_G4            SIM_IPS0_PWMAF2_GPIO_G4  
#define SYS_PWMAF2_XB_OUT31           SIM_IPS0_PWMAF2_XB_OUT31 
           
#define SYS_PWMAF1_GPIO_E9            SIM_IPS0_PWMAF1_GPIO_E9  
#define SYS_PWMAF1_XB_OUT30           SIM_IPS0_PWMAF1_XB_OUT30 
           
#define SYS_PWMAF0_GPIO_E8            SIM_IPS0_PWMAF0_GPIO_E8  
#define SYS_PWMAF0_XB_OUT29           SIM_IPS0_PWMAF0_XB_OUT29 

#endif

/* clkout mux */
#define SYS_CLKOUT_SYSCLK   SIM_CLKOSR_CLKOSEL_SYSCLK    /* sys_clk */
#define SYS_CLKOUT_IPBCLK   SIM_CLKOSR_CLKOSEL_IPBCLK    /* periph_clk */
#define SYS_CLKOUT_HSCLK    SIM_CLKOSR_CLKOSEL_HSCLK     /* hs_perf clk */
#define SYS_CLKOUT_MSTRCLK  SIM_CLKOSR_CLKOSEL_MSTRCLK   /* mstr_osc */

#define SYS_CLKOUT_1_BUSCLK       SIM_CLKOSR_CLKOSEL_1_BUSCLK         
#define SYS_CLKOUT_1_2X_BUSCLK    SIM_CLKOSR_CLKOSEL_1_2X_BUSCLK      
#define SYS_CLKOUT_1_DIV4_BUSCLK  SIM_CLKOSR_CLKOSEL_1_DIV4_BUSCLK    
#define SYS_CLKOUT_1_MSTR_OSC     SIM_CLKOSR_CLKOSEL_1_MSTR_OSC       
#define SYS_CLKOUT_1_ROSC_8M      SIM_CLKOSR_CLKOSEL_1_ROSC_8M        


#if SIM_VERSION == 7
#define SYS_CLKOUT_1_ROSC_32K    SIM_CLKOSR_CLKOSEL_1_ROSC_200K 
#endif

#if SIM_VERSION == 8
#define SYS_CLKOUT_1_ROSC_200K    SIM_CLKOSR_CLKOSEL_1_ROSC_200K 
#endif


#define SYS_DIV1                  SIM_CLKOSR_CLKODIV_1                
#define SYS_DIV2                  SIM_CLKOSR_CLKODIV_2                
#define SYS_DIV4                  SIM_CLKOSR_CLKODIV_4                
#define SYS_DIV8                  SIM_CLKOSR_CLKODIV_8                
#define SYS_DIV16                 SIM_CLKOSR_CLKODIV_16               
#define SYS_DIV32                 SIM_CLKOSR_CLKODIV_32               
#define SYS_DIV64                 SIM_CLKOSR_CLKODIV_64               
#define SYS_DIV128                SIM_CLKOSR_CLKODIV_128             


/****************************************************************************
* register bit names and masks
*****************************************************************************/

/* SIM_CONTROL */
#define SIM_CONTROL_ONCEEBL             0x0020
#define SIM_CONTROL_SWRST               0x0010
#define SIM_CONTROL_STOPDIS_MASK        0x000c
#define SIM_CONTROL_STOPDIS_ENABLE      0x0000
#define SIM_CONTROL_STOPDIS_SOFT        0x0004
#define SIM_CONTROL_STOPDIS_PERMANENT   0x0008
#define SIM_CONTROL_WAITDIS_MASK        0x0003
#define SIM_CONTROL_WAITDIS_ENABLE      0x0000
#define SIM_CONTROL_WAITDIS_SOFT        0x0001
#define SIM_CONTROL_WAITDIS_PERMANENT   0x0002

#define SIM_CONTROL_DMAEBL_MASK         0x01c0

#define DMAEBL_DISABLE                  0x0000
#define DMAEBL_RUN_MODE                 0x0040
#define DMAEBL_RUN_WAIT_MODES           0x0080
#define DMAEBL_ALL_MODES                0x00C0
#define DMAEBL_DISABLE_AND_WP           0x0100
#define DMAEBL_RUN_MODE_AND_WP          0x0140
#define DMAEBL_RUN_WAIT_MODES_AND_WP    0x0180
#define DMAEBL_ALL_MODES_AND_WP         0x01C0

#define SIM_CONTROL_RST_FILT            0x0400

#define SIM_RSTSTS_COP_TOR      0x0020
#define SIM_RSTSTS_COP_LOR      0x0010
#define SIM_RSTSTS_EXTR         0x0008
#define SIM_RSTSTS_POR          0x0004

#if SIM_VERSION == 7
#define SIM_RSTSTS_EZPR         0x0080
/* SIM_RSTSTS */
#define SIM_RSTSTS_SWR          0x0040
#endif
#if SIM_VERSION == 8
/* SIM_RSTSTS */
#define SIM_RSTSTS_SWR          0x0080
#define SIM_RSTSTS_COP_WINDOW   0x0040
#endif

/* SIM_POWER */
#define SIM_POWER_LRSTDBY0       0x0001
#define SIM_POWER_LRSTDBY1       0x0002

#define SIM_POWER_LRSTDBY_MASK   0x0003
#define SIM_POWER_SR27STDBY_MASK 0x000C
#define SIM_POWER_SR27PDN_MASK   0x0030
#define SIM_POWER_SR12STDBY_MASK 0x00C0

/* SIM_CLKOSR */
#define SIM_CLKOSR_CLKDIS           0x0020
#define SIM_CLKOSR_CLKOSEL_MASK     0x001f
#define SIM_CLKOSR_CLKOSEL_SYSCLK   0x0000
#define SIM_CLKOSR_CLKOSEL_IPBCLK   0x0001
#define SIM_CLKOSR_CLKOSEL_HSCLK    0x0002
#define SIM_CLKOSR_CLKOSEL_MSTRCLK  0x0003

#define SIM_CLKOSR_CLKOSEL_1_MASK           0x0380
#define SIM_CLKOSR_CLKDIS_1                 0x1000
#define SIM_CLKOSR_CLOKDIV_MASK             0xE000
#define SIM_CLKOSR_CLKOSEL_1_BUSCLK         0x0000
#define SIM_CLKOSR_CLKOSEL_1_2X_BUSCLK      0x0001
#define SIM_CLKOSR_CLKOSEL_1_DIV4_BUSCLK    0x0002
#define SIM_CLKOSR_CLKOSEL_1_MSTR_OSC       0x0003
#define SIM_CLKOSR_CLKOSEL_1_ROSC_8M        0x0004
#define SIM_CLKOSR_CLKOSEL_1_ROSC_200K      0x0005
#define SIM_CLKOSR_CLKODIV_1                0x0000
#define SIM_CLKOSR_CLKODIV_2                0x0001
#define SIM_CLKOSR_CLKODIV_4                0x0002
#define SIM_CLKOSR_CLKODIV_8                0x0003
#define SIM_CLKOSR_CLKODIV_16               0x0004
#define SIM_CLKOSR_CLKODIV_32               0x0005
#define SIM_CLKOSR_CLKODIV_64               0x0006
#define SIM_CLKOSR_CLKODIV_128              0x0007

/* SIM_PCR */

#define SIM_PCR_SCI0            0x2000
#define SIM_PCR_SCI1            0x1000

#if SIM_VERSION == 7
#define SIM_PCR_TMRB            0x8000
#define SIM_PCR_TMRA            0x4000
#endif

#if SIM_VERSION == 8
#define SIM_PCR_TMR     0x0800
#define SIM_PCR_PWM     0x0400
#define SIM_PCR_IIC     0x0200
#endif 

/* SIM_PCE0 */
#if SIM_VERSION == 7

#define SIM_PCE0_TA0            0x8000
#define SIM_PCE0_TA1            0x4000
#define SIM_PCE0_TA2            0x2000
#define SIM_PCE0_TA3            0x1000
#define SIM_PCE0_TB0            0x0800
#define SIM_PCE0_TB1            0x0400
#define SIM_PCE0_TB2            0x0200
#define SIM_PCE0_TB3            0x0100
#define SIM_PCE0_GPIOA          0x0040
#define SIM_PCE0_GPIOB          0x0020
#define SIM_PCE0_GPIOC          0x0010
#define SIM_PCE0_GPIOD          0x0008
#define SIM_PCE0_GPIOE          0x0004
#define SIM_PCE0_GPIOF          0x0002
#define SIM_PCE0_GPIOG          0x0001

#define SIM_PCE1_FLEXCAN        0x0001 
#define SIM_PCE1_IIC1           0x0020  
#define SIM_PCE1_IIC0           0x0040 
#define SIM_PCE1_QSPI1          0x0100
#define SIM_PCE1_QSPI0          0x0200
#define SIM_PCE1_SCI1           0x0800
#define SIM_PCE1_SCI0           0x1000
#define SIM_PCE1_DAC            0x2000 
        
#define SIM_PCE2_PDB1           0x0001
#define SIM_PCE2_PDB0           0x0002
#define SIM_PCE2_PIT1           0x0004
#define SIM_PCE2_PIT0           0x0008
#define SIM_PCE2_CRC            0x0020
#define SIM_PCE2_CYCADC         0x0080
#define SIM_PCE2_SARADC         0x0100
#define SIM_PCE2_CMPD           0x0200
#define SIM_PCE2_CMPC           0x0400
#define SIM_PCE2_CMPB           0x0800
#define SIM_PCE2_CMPA           0x1000
        
#define SIM_PCE2_PWMCH3         0x0010
#define SIM_PCE2_PWMCH2         0x0020
#define SIM_PCE2_PWMCH1         0x0040
#define SIM_PCE2_PWMCH0         0x0080

#endif

#if SIM_VERSION == 8
#define SIM_PCE0_TA0            0x8000
#define SIM_PCE0_TA1            0x4000
#define SIM_PCE0_TA2            0x2000
#define SIM_PCE0_TA3            0x1000
#define SIM_PCE0_GPIOA          0x0040
#define SIM_PCE0_GPIOB          0x0020
#define SIM_PCE0_GPIOC          0x0010
#define SIM_PCE0_GPIOD          0x0008
#define SIM_PCE0_GPIOE          0x0004
#define SIM_PCE0_GPIOF          0x0002

#define SIM_PCE1_MSCAN          0x0001
#define SIM_PCE1_IIC0           0x0040
#define SIM_PCE1_QSPI1          0x0100
#define SIM_PCE1_QSPI0          0x0200
#define SIM_PCE1_SCI1           0x0800
#define SIM_PCE1_SCI0           0x1000
#define SIM_PCE1_DACA           0x2000
#define SIM_PCE1_DACB           0x4000

#define SIM_PCE2_PIT1           0x0004
#define SIM_PCE2_PIT0           0x0008
#define SIM_PCE2_CRC            0x0020
#define SIM_PCE2_CYCADC         0x0080
#define SIM_PCE2_CMPD           0x0200
#define SIM_PCE2_CMPC           0x0400  
#define SIM_PCE2_CMPB           0x0800
#define SIM_PCE2_CMPA           0x1000

#define SIM_PCE2_PWMCH3         0x0010
#define SIM_PCE2_PWMCH2         0x0020
#define SIM_PCE2_PWMCH1         0x0040
#define SIM_PCE2_PWMCH0         0x0080

#endif


/* SIM_SD0 */
#define SIM_SD0_TA0             0x8000
#define SIM_SD0_TA1             0x4000
#define SIM_SD0_TA2             0x2000
#define SIM_SD0_TA3             0x1000
#define SIM_SD0_TB0             0x0800
#define SIM_SD0_TB1             0x0400
#define SIM_SD0_TB2             0x0200
#define SIM_SD0_TB3             0x0100
#define SIM_SD0_ADC             0x0080
#define SIM_SD0_GPIOA           0x0040
#define SIM_SD0_GPIOB           0x0020
#define SIM_SD0_GPIOC           0x0010
#define SIM_SD0_GPIOD           0x0008
#define SIM_SD0_GPIOE           0x0004
#define SIM_SD0_GPIOF           0x0002

/* SIM_SD1 */
#define SIM_SD1_DAC             0x4000
#define SIM_SD1_CMPA            0x2000
#define SIM_SD1_CMPB            0x1000
#define SIM_SD1_CMPC            0x0800
#define SIM_SD1_SCI0            0x0400
#define SIM_SD1_SCI1            0x0200
#define SIM_SD1_QSPI0           0x0100
#define SIM_SD1_IIC0            0x0080
#define SIM_SD1_IIC1            0x0040
#define SIM_SD1_CRC             0x0020
#define SIM_SD1_REFA            0x0010
#define SIM_SD1_REFB            0x0008
#define SIM_SD1_REFC            0x0004
#define SIM_SD1_HFM             0x0002
#define SIM_SD1_MSCAN           0x0001

/* SIM_SD2 */
#define SIM_SD2_PWMCH0          0x0008
#define SIM_SD2_PWMCH1          0x0004
#define SIM_SD2_PWMCH2          0x0002
#define SIM_SD2_PWMCH3          0x0001

/* SIM_PROT */
#define SIM_PROT_PCEP_MASK      0x000c
#define SIM_PROT_PCEP_PROT      0x0004
#define SIM_PROT_PCEP_LOCK      0x0008
#define SIM_PROT_GIPSP_MASK     0x0003
#define SIM_PROT_GIPSP_PROT     0x0001
#define SIM_PROT_GIPSP_LOCK     0x0002

#define SIM_PROT_GDP_MASK       0x0030
#define SIM_PROT_GSP_PROT       0x0010
#define SIM_PROT_GDP_LOCK       0x0020
#define SIM_PROT_PMODE_MASK     0x00C0
#define SIM_PROT_PMODE_PROT     0x0040
#define SIM_PROT_PMODE_LOCK     0x0080


#if SIM_VERSION == 8

#define SIM_GPSAL_A0_ANA0_CMPA3     0x0000
#define SIM_GPSAL_A0_CMPC_O         0x0001
                           
#define SIM_GPSBL_B1_ANB1_CMPB_IN0  0x0000
#define SIM_GPSBL_B1_DACB           0x0004
                         
#define SIM_GPSCH_C15_SCL0          0x8000
#define SIM_GPSCH_C15_XB_OUT5       0x4000
                         
#define SIM_GPSCH_C14_SDA0          0x0000
#define SIM_GPSCH_C14_XB_OUT4       0x1000
#define SIM_GPSCH_C14_PWM_FAULT4    0x2000
                            
#define SIM_GPSCH_C13_TA3           0x0000
#define SIM_GPSCH_C13_XB_IN6        0x0400
#define SIM_GPSCH_C13_EWM_OUTB      0x0800
    
#define SIM_GPSCH_C12_SDA0          0x0100
#define SIM_GPSCH_C12_RXD1          0x0200
                          
#define SIM_GPSCH_C11_TXD1          0x0080
#define SIM_GPSCH_C11_SCL0          0x0040                         

#define SIM_GPSCH_C10_XB_OUT9       0x0030
#define SIM_GPSCH_C10_MOSI0         0x0000
#define SIM_GPSCH_C10_XB_IN5        0x0010
#define SIM_GPSCH_C10_MISO0         0x0020
                         
#define SIM_GPSCH_C9_SCLK0          0x0000
#define SIM_GPSCH_C9_XB_IN4         0x0004
#define SIM_GPSCH_C9_XB_OUT8        0x000C
#define SIM_GPSCH_C9_TXD0           0x0008
                           
#define SIM_GPSCH_C8_XB_OUT6        0x0003
#define SIM_GPSCH_C8_RXD0           0x0001
#define SIM_GPSCH_C8_MISO0          0x0000
#define SIM_GPSCH_C8_XB_IN9         0x0002
                                
#define SIM_GPSCL_C7_SSB0_B         0x0000
#define SIM_GPSCL_C7_TXD0           0x4000
#define SIM_GPSCL_C7_XB_IN8         0x8000
                      
#define SIM_GPSCL_C6_TA2            0x0000
#define SIM_GPSCL_C6_XB_IN3         0x1000
#define SIM_GPSCL_C6_CMPREF         0x2000
#define SIM_GPSCL_C6_SS0_B          0x3000
                            
#define SIM_GPSCL_C5_DACA           0x0000
#define SIM_GPSCL_C5_XB_IN7         0x0400
                            
#define SIM_GPSCL_C4_TA1            0x0000
#define SIM_GPSCL_C4_CMPB_O         0x0100
#define SIM_GPSCL_C4_XB_IN6         0x0200
#define SIM_GPSCL_C4_EWM_OUT_BO     0x0300
                            
#define SIM_GPSCL_C3_TA0            0x0000
#define SIM_GPSCL_C3_CMPA_O         0x0040
#define SIM_GPSCL_C3_RXD0           0x0080
#define SIM_GPSCL_C3_CLKIN1         0x00C0
                           
#define SIM_GPSCL_C2_TXD0           0x0000
#define SIM_GPSCL_C2_XB_OUT11       0x0010
#define SIM_GPSCL_C2_XB_IN2         0x0020
#define SIM_GPSCL_C2_CLKOUT0        0x0030
                            
#define SIM_GPSCL_C0_EXTAL          0x0000
#define SIM_GPSCL_C0_CLKIN          0x0001
                           
#define SIM_GPSEL_E7_PWMA3A         0x0000
#define SIM_GPSEL_E7_XB_IN5         0x4000
                                
#define SIM_GPSEL_E6_PWMB3B         0x0000
#define SIM_GPSEL_E6_XB_IN4         0x1000
                                
#define SIM_GPSEL_E5_PWMA2A         0x0000
#define SIM_GPSEL_E5_XB_IN3         0x0400
                                
#define SIM_GPSEL_E4_PWMB2B         0x0000
#define SIM_GPSEL_E4_XB_IN2         0x0100
                                
#define SIM_GPSFH_F8_RXD0           0x0000
#define SIM_GPSFH_F8_OUT10          0x0001
#define SIM_GPSFH_F8_CMPDO          0x0002
#define SIM_GPSFH_F8_PWMA_2X        0x0003
                                
#define SIM_GPSFL_F7_XB_IN3         0xC000
#define SIM_GPSFL_F7_CMPC_0         0x4000
#define SIM_GPSFL_F7_SS1_B          0x8000
                                
#define SIM_GPSFL_F6_XB_IN2         0x3000
#define SIM_GPSFL_F6_PWMA_3X        0x1000
                                
#define SIM_GPSFL_F5_RXD1           0x0000
#define SIM_GPSFL_F5_XB_OUT9        0x0400
#define SIM_GPSFL_F5_PWMA_1X        0x0800
#define SIM_GPSFL_F5_PWMA_FAULT7    0x0C00
                           
#define SIM_GPSFL_F4_XB_OUT8        0x0100
#define SIM_GPSFL_F4_TXD1           0x0000
#define SIM_GPSFL_F4_PWMA_0X        0x0200
#define SIM_GPSFL_F4_PWMA_FAULT6    0x0300
                            
#define SIM_GPSFL_F3_SDA0           0x0000
#define SIM_GPSFL_F3_XB_OUT7        0x0040
#define SIM_GPSFL_F3_MOSI1          0x0080
                                
#define SIM_GPSFL_F2_SCL0           0x0000
#define SIM_GPSFL_F2_XB_OUT6        0x0010
#define SIM_GPSFL_F2_MISO1          0x0020
                            
#define SIM_GPSFL_F1_CLKOUT1        0x0000
#define SIM_GPSFL_F1_XB_IN7         0x0004
#define SIM_GPSFL_F1_CMPD_O         0x0008
    
#define SIM_GPSFL_F0_SCLK1          0x0002
#define SIM_GPSFL_F0_XB_IN6         0x0000

#define SIM_GPSAL_A0                0x0001
#define SIM_GPSBL_B1                0x0004
#define SIM_GPSCL_C0                0x0001
#define SIM_GPSCL_C2_MASK           0x0030
#define SIM_GPSCH_C8_MASK           0x0003
#define SIM_GPSCH_C9_MASK           0x000C
#define SIM_GPSCH_C10_MASK          0x0030
#define SIM_GPSCH_C11_MASK          0x00C0
#define SIM_GPSCH_C12_MASK          0x0300
#define SIM_GPSCH_C13_MASK          0x0C00
#define SIM_GPSCH_C14_MASK          0x3000
#define SIM_GPSCH_C15_MASK          0xC000
#define SIM_GPSCL_C3_MASK           0x00C0
#define SIM_GPSCL_C4_MASK           0x0300
#define SIM_GPSCL_C5                0x0400
#define SIM_GPSCL_C6_MASK           0x3000
#define SIM_GPSCL_C7_MASK           0xC000
#define SIM_GPSEL_E4                0x0100
#define SIM_GPSEL_E5                0x0400
#define SIM_GPSEL_E6                0x1000
#define SIM_GPSEL_E7                0x4000
#define SIM_GPSFL_F0_MASK           0x0003
#define SIM_GPSFL_F1_MASK           0x000C
#define SIM_GPSFL_F2_MASK           0x0030
#define SIM_GPSFL_F3_MASK           0x00C0
#define SIM_GPSFL_F4_MASK           0x0300
#define SIM_GPSFL_F5_MASK           0x0C00
#define SIM_GPSFL_F6_MASK           0x3000
#define SIM_GPSFL_F7_MASK           0xC000
#define SIM_GPSFH_F8_MASK           0x0003

#define SIM_IPSN_TMRA3              0x0800
#define SIM_IPSN_TMRA3_GPIOC13      0x0000
#define SIM_IPSN_TMRA3_XB_OUT37     0x0800
#define SIM_IPSN_TMRA2              0x0400
#define SIM_IPSN_TMRA2_GPIOC6       0x0000
#define SIM_IPSN_TMRA2_XB_OUT36     0x0400
#define SIM_IPSN_TMRA1              0x0200
#define SIM_IPSN_TMRA1_GPIOC4       0x0000
#define SIM_IPSN_TMRA1_XB_OUT35     0x0200
#define SIM_IPSN_TMRA0              0x0100
#define SIM_IPSN_TMRA0_GPIOC3       0x0000
#define SIM_IPSN_TMRA0_XB_OUT34     0x0100
#define SIM_IPSN_SCI1               0x0002
#define SIM_IPSN_SCI1_GPIOC12       0x0000
#define SIM_IPSN_SCI1_XB_OUT39      0x0002
#define SIM_IPSN_SCI0               0x0001
#define SIM_IPSN_SCI0_GPIOC3        0x0000
#define SIM_IPSN_SCI0_XB_OUT38      0x0001

#define SIM_PSWR_GPIO    0x40
#define SIM_PSWR_TA      0x8000
#define SIM_PSWR_MSCAN   0x1
#define SIM_PSWR_IIC0    0x40
#define SIM_PSWR_QSPI1   0x100
#define SIM_PSWR_QSPI0   0x200
#define SIM_PSWR_SCI1    0x800
#define SIM_PSWR_SCI0    0x1000
#define SIM_PSWR_DACA    0x2000
#define SIM_PSWR_DACB    0x4000
#define SIM_PSWR_PIT1    0x4
#define SIM_PSWR_PIT0    0x8
#define SIM_PSWR_CRC     0x20
#define SIM_PSWR_CYCADC  0x80
#define SIM_PSWR_CMP     0x1000
#define SIM_PSWR_EWM     0x8000
#define SIM_PSWR_PWMA    0x80

#endif


/**************************   MASK  **********************************/
#if SIM_VERSION == 7

#define  SIM_GPSAL_A0                 0x1
#define  SIM_GPSAL_A0_ANA0_CMPA3      0x0
#define  SIM_GPSAL_A0_CMPC_O          0x1
                                        
#define  SIM_GPSBH_B11_MASK           0xC0
#define  SIM_GPSBH_B11_ANC15          0x0
#define  SIM_GPSBH_B11_XB_IN7         0x40
                                        
#define  SIM_GPSBH_B10_MASK           0x30
#define  SIM_GPSBH_B10_ANC14          0x0
#define  SIM_GPSBH_B10_XB_IN8         0x10
                                        
#define  SIM_GPSBH_B9_MASK            0xC
#define  SIM_GPSBH_B9_ANC13           0x0
#define  SIM_GPSBH_B9_XB_IN9          0x4
                                        
#define  SIM_GPSCH_C15                0x4000
#define  SIM_GPSCH_C15_XB_OUT5        0x4000
#define  SIM_GPSCH_C15_PWM_SCL0       0x0
                                        
#define  SIM_GPSCH_C14                0x1000
#define  SIM_GPSCH_C14_SDA0           0x0
#define  SIM_GPSCH_C14_XB_OUT4        0x1000
                                        
#define  SIM_GPSCH_C13_MASK           0xC00
#define  SIM_GPSCH_C13_TA3            0x0
#define  SIM_GPSCH_C13_XB_IN6         0x400
#define  SIM_GPSCH_C13_EWM_OUTB       0x800
                                        
#define  SIM_GPSCH_C12_MASK           0x300
#define  SIM_GPSCH_C12_CANRX          0x0
#define  SIM_GPSCH_C12_SDA1           0x100
#define  SIM_GPSCH_C12_RXD1           0x200
                                        
#define  SIM_GPSCH_C11_MASK           0xC0
#define  SIM_GPSCH_C11_SCL1           0x40
#define  SIM_GPSCH_C11_TXD1           0x80
#define  SIM_GPSCH_C11_CANTX          0x0
                                        
#define  SIM_GPSCH_C10_MASK           0x30
#define  SIM_GPSCH_C10_MOSI0          0x0
#define  SIM_GPSCH_C10_XB_IN5         0x10
#define  SIM_GPSCH_C10_MISO0          0x20
                                        
#define  SIM_GPSCH_C9                 0x4
#define  SIM_GPSCH_C9_XB_IN4          0x4
#define  SIM_GPSCH_C9_SCLK0           0x0
                                        
#define  SIM_GPSCH_C8_MASK            0x3
#define  SIM_GPSCH_C8_MISO0           0x0
#define  SIM_GPSCH_C8_RXD0            0x1
#define  SIM_GPSCH_C8_XB_IN9          0x2
                                        
#define  SIM_GPSCL_C7                 0x4000
#define  SIM_GPSCL_C7_SSB0_B          0x0
#define  SIM_GPSCL_C7_TXD0            0x4000
                                        
#define  SIM_GPSCL_C6_MASK            0x3000
#define  SIM_GPSCL_C6_TA2             0x0
#define  SIM_GPSCL_C6_XB_IN3          0x1000
#define  SIM_GPSCL_C6_CMPREF          0x2000
                                        
#define  SIM_GPSCL_C5                 0x400
#define  SIM_GPSCL_C5_DAC0            0x0
#define  SIM_GPSCL_C5_XB_IN7          0x400
                                        
#define  SIM_GPSCL_C4_MASK            0x300
#define  SIM_GPSCL_C4_TA1             0x0
#define  SIM_GPSCL_C4_CMPB_O          0x100
#define  SIM_GPSCL_C4_XB_IN8          0x200
#define  SIM_GPSCL_C4_EWM_OUT_B       0x300
                                        
#define  SIM_GPSCL_C3_MASK            0xC0
#define  SIM_GPSCL_C3_TA0             0x0
#define  SIM_GPSCL_C3_CMPA_O          0x40
#define  SIM_GPSCL_C3_RXD0            0x80
#define  SIM_GPSCL_C3_CLKIN1          0xC0
                                        
#define  SIM_GPSCL_C2_MASK            0x30
#define  SIM_GPSCL_C2_TXD0            0x0
#define  SIM_GPSCL_C2_TB0             0x10
#define  SIM_GPSCL_C2_XB_IN2          0x20
#define  SIM_GPSCL_C2_CLKOUT0         0x30

#define  SIM_GPSCL_C0                 0x1                                       
#define  SIM_GPSCL_C0_EXTAL           0x0
#define  SIM_GPSCL_C0_CLKIN           0x1
                                      
#define  SIM_GPSDL_D7_MASK            0xC000
#define  SIM_GPSDL_D7_XB_OUT11        0x0
#define  SIM_GPSDL_D7_XB_IN_7         0x4000
#define  SIM_GPSDL_D7_XB_MISO1        0x8000
                                        
#define  SIM_GPSDL_D6_MASK            0x3000
#define  SIM_GPSDL_D6_TXD2            0x0
#define  SIM_GPSDL_D6_XB_IN4          0x1000
#define  SIM_GPSDL_D6_XB_OUT8         0x2000
                                        
#define  SIM_GPSDL_D5_MASK            0xC00
#define  SIM_GPSDL_D5_XB_IN5          0x400
#define  SIM_GPSDL_D5_XB_OUT9         0x800
                                        
#define  SIM_GPSEH_E9                 0x4
#define  SIM_GPSEH_E9_PWMA_FAULT1     0x4
                                        
#define  SIM_GPSEH_E8                 0x1
#define  SIM_GPSEH_E8_PWMA_FAULT0     0x1
                                        
#define  SIM_GPSEL_E7_MASK            0xC000
#define  SIM_GPSEL_E7_PWMA3A          0x0
#define  SIM_GPSEL_E7_XB_IN5          0x4000
                                        
#define  SIM_GPSEL_E6_MASK            0x3000
#define  SIM_GPSEL_E6_PWMB3B          0x0
#define  SIM_GPSEL_E6_XB_IN4          0x1000
                                        
#define  SIM_GPSEL_E5                 0x400
#define  SIM_GPSEL_E5_PWMA2A          0x0
#define  SIM_GPSEL_E5_XB_IN3          0x400
                                        
#define  SIM_GPSEL_E4                 0x100
#define  SIM_GPSEL_E4_PWMB2B          0x0
#define  SIM_GPSEL_E4_XB_IN2          0x100
                                        
#define  SIM_GPSFH_F15                0x4000
#define  SIM_GPSFH_F15_RXD0           0x0
#define  SIM_GPSFH_F15_XB_IN10        0x4000
                                        
#define  SIM_GPSFH_F14                0x1000
#define  SIM_GPSFH_F14_SCLK1          0x0
                                        
#define  SIM_GPSFH_F13                0x400
#define  SIM_GPSFH_F13_MOSI1          0x0
                                        
#define  SIM_GPSFH_F12                0x100
#define  SIM_GPSFH_F12_MISO1          0x0
                                        
#define  SIM_GPSFH_F11                0x40
#define  SIM_GPSFH_F11_TXD0           0x0
#define  SIM_GPSFH_F11_XB_IN11        0x40
                                        
#define  SIM_GPSFH_F10_MASK           0x30
#define  SIM_GPSFH_F10_PWMA_FAULT6    0x10
#define  SIM_GPSFH_F10_XB_OUT10       0x30
                                        
#define  SIM_GPSFH_F9_MASK            0xC
#define  SIM_GPSFH_F9_FAULT7          0x4
#define  SIM_GPSFH_F9_XB_OUT11        0xC
                                        
#define  SIM_GPSFH_F8_MASK            0x3
#define  SIM_GPSFH_F8_RXD0            0x0
#define  SIM_GPSFH_F8_TB1             0x1
#define  SIM_GPSFH_F8_CMPD_O          0x2
                                        
#define  SIM_GPSFL_F7_MASK            0xC000
#define  SIM_GPSFL_F7_CMPC_0          0x4000
#define  SIM_GPSFL_F7_SS1_B           0x8000
#define  SIM_GPSFL_F7_XB_IN3          0xC000
#define  SIM_GPSFL_F7_TB3             0x0
                                        
#define  SIM_GPSFL_F6_MASK            0x3000
#define  SIM_GPSFL_F6_TB2             0x0
#define  SIM_GPSFL_F6_PWMA_3X         0x1000
#define  SIM_GPSFL_F6_XB_IN2          0x3000
                                        
#define  SIM_GPSFL_F5                 0x400
#define  SIM_GPSFL_F5_RXD1            0x0
#define  SIM_GPSFL_F5_XB_OUT9         0x400
                                        
#define  SIM_GPSFL_F4                 0x100
#define  SIM_GPSFL_F4_TXD1            0x0
#define  SIM_GPSFL_F4_XB_OUT8         0x100
                                        
#define  SIM_GPSFL_F3                 0x40
#define  SIM_GPSFL_F3_SDA1            0x0
#define  SIM_GPSFL_F3_XB_OUT7         0x40
                                        
#define  SIM_GPSFL_F2                 0x10
#define  SIM_GPSFL_F2_SCL1            0x0
#define  SIM_GPSFL_F2_XB_OUT6         0x10
                                        
#define  SIM_GPSFL_F1_MASK            0xC
#define  SIM_GPSFL_F1_CLKOUT1         0x0
#define  SIM_GPSFL_F1_XB_IN7          0x4
#define  SIM_GPSFL_F1_CMPD_O          0x8
                                        
#define  SIM_GPSFL_F0_MASK            0x3
#define  SIM_GPSFL_F0_XB_IN6          0x0
#define  SIM_GPSFL_F0_TB2             0x1
#define  SIM_GPSFL_F0_SCLK1           0x2
                                        
#define  SIM_GPSGL_G7_MASK            0xC000
#define  SIM_GPSGL_G7_PWMA_FAULT5     0x0
#define  SIM_GPSGL_G7_XB_OUT9         0x8000
                                        
#define  SIM_GPSGL_G6_MASK            0x3000
#define  SIM_GPSGL_G6_PWMA_FAULT4     0x0
#define  SIM_GPSGL_G6_TB2             0x2000
#define  SIM_GPSGL_G6_XB_OUT8         0x3000
                                        
#define  SIM_GPSGL_G5                 0x400
#define  SIM_GPSGL_G5_PWMA_FAULT3     0x400
                                        
#define  SIM_GPSGL_G4                 0x100
#define  SIM_GPSGL_G4_PWMA_FAULT2     0x100
                                        
#define  SIM_GPSGL_G3                 0x40
#define  SIM_GPSGL_G3_XB_OUT5         0x40
                                        
#define  SIM_GPSGL_G2                 0x10
#define  SIM_GPSGL_G2_XB_OUT4         0x10
                                        
#define  SIM_GPSGL_G1                 0x4
#define  SIM_GPSGL_G1_XB_OUT7         0x4
                                        
#define  SIM_GPSGL_G0                 0x1
#define  SIM_GPSGL_G0_XB_OUT6         0x1
                                        
#define  SIM_GPSGH_G11_MASK           0xC0
#define  SIM_GPSGH_G11_TB3            0x0
#define  SIM_GPSGH_G11_CLKOUT0        0x40
#define  SIM_GPSGH_G11_MOSI1          0x80
                                        
#define  SIM_GPSGH_G10_MASK           0x30
#define  SIM_GPSGH_G10_PWMA_2X        0x10
#define  SIM_GPSGH_G10_XB_IN8         0x20
                                        
#define  SIM_GPSGH_G9_MASK            0xC
#define  SIM_GPSGH_G9_PWMA_1X         0x4
#define  SIM_GPSGH_G9_TA3             0x8
#define  SIM_GPSGH_G9_XB_OUT11        0xC
                                        
#define  SIM_GPSGH_G8_MASK            0x3
#define  SIM_GPSGH_G8_PWMA_0X         0x1
#define  SIM_GPSGH_G8_TA2             0x2
#define  SIM_GPSGH_G8_XB_OUT10        0x3                                                                           
                                        
#define  SIM_IPS0_TMRB3               0x8000
#define  SIM_IPS0_TMRB3_GPIO_F7_G11   0x0
#define  SIM_IPS0_TMRB3_XB_OUT37      0x8000
                                        
#define  SIM_IPS0_TMRB2               0x4000
#define  SIM_IPS0_TMRB2_GPIO_F6_F0_G6 0x0
#define  SIM_IPS0_TMRB2_XB_OUT36      0x4000
                                    
#define  SIM_IPS0_TMRB1               0x2000
#define  SIM_IPS0_TMRB1_GPIO_F8       0x00
#define  SIM_IPS0_TMRB1_XB_OUT35      0x2000
                                    
#define  SIM_IPS0_TMRB0               0x1000
#define  SIM_IPS0_TMRB0_GPIO_C2       0x0
#define  SIM_IPS0_TMRB0_XB_OUT34      0x1000
                                    
#define  SIM_IPS0_TMRA3               0x800
#define  SIM_IPS0_TMRA3_GPIO_C13_G9   0x0
#define  SIM_IPS0_TMRA3_XB_OUT52      0x800
                                        
#define  SIM_IPS0_TMRA2               0x400
#define  SIM_IPS0_TMRA2_GPIO_C6_G8    0x0
#define  SIM_IPS0_TMRA2_XB_OUT51      0x400
                                    
#define  SIM_IPS0_TMRA1               0x200
#define  SIM_IPS0_TMRA1_GPIO_C4       0x0
#define  SIM_IPS0_TMRA1_XB_OUT50      0x200
                                        
#define  SIM_IPS0_TMRA0               0x100
#define  SIM_IPS0_TMRA0_GPIO_C3       0x0
#define  SIM_IPS0_TMRA0_XB_OUT49      0x100
                                        
#define  SIM_IPS0_PWMAF3              0x8
#define  SIM_IPS0_PWMAF3_GPIO_G5      0x0
#define  SIM_IPS0_PWMAF3_XB_OUT32     0x8
                                        
#define  SIM_IPS0_PWMAF2              0x4
#define  SIM_IPS0_PWMAF2_GPIO_G4      0x0
#define  SIM_IPS0_PWMAF2_XB_OUT31     0x4
                                        
#define  SIM_IPS0_PWMAF1              0x2
#define  SIM_IPS0_PWMAF1_GPIO_E9      0x0
#define  SIM_IPS0_PWMAF1_XB_OUT30     0x2
                                        
#define  SIM_IPS0_PWMAF0              0x1
#define  SIM_IPS0_PWMAF0_GPIO_E8      0x0
#define  SIM_IPS0_PWMAF0_XB_OUT29     0x1


#define SIM_PSWR_GPIO       0x40
#define SIM_PSWR_TB         0x800
#define SIM_PSWR_TA         0x8000
#define SIM_PSWR_FLEXCAN    0x1
#define SIM_PSWR_IIC1       0x20
#define SIM_PSWR_IIC0       0x40
#define SIM_PSWR_QSPI1      0x100
#define SIM_PSWR_QSPI0      0x200
#define SIM_PSWR_SCI1       0x800
#define SIM_PSWR_SCI0       0x1000
#define SIM_PSWR_DAC        0x2000
#define SIM_PSWR_PDB1       0x1
#define SIM_PSWR_PDB0       0x2
#define SIM_PSWR_PIT1       0x4
#define SIM_PSWR_PIT0       0x8
#define SIM_PSWR_QDC        0x10
#define SIM_PSWR_CRC        0x20
#define SIM_PSWR_CYCADC     0x80
#define SIM_PSWR_SARADC     0x100
#define SIM_PSWR_CMP        0x1000
#define SIM_PSWR_EWM        0x8000
#define SIM_PSWR_PWMA       0x80

#endif


#define SIM_MISC0_PIT_MSTR        0x01
#define SIM_MISC0_CLKINSEL        0x02

#define SIM_PWRMODE_LPMODE_MASK   0x2
#define SIM_PWRMODE_LPMS_MASK     0x200
#define SIM_PWRMODE_VLPMODE_MASK  0x1
#define SIM_PWRMODE_VLPMS_MASK    0x100


#if SIM_VERSION == 8
#define SIM_MISC0_FAST_MODE     0x04
#define SIM_MISC0_ADC_SCTRL     0x08
#define SIM_MISC0_MODE_STAT     0x100
#endif

/***********************************************************************
* SYS control command macros
***********************************************************************/

/* SYS initialization */
void sysInit(arch_sSIM *pSimBase);
#define ioctlSYS_INIT(pSimBase, param) sysInit(pSimBase)

/* reprogramable "stop" instruction disable */ 
#define ioctlSYS_STOP(pSimBase, param) \
  periphBitGrpSet(SIM_CONTROL_STOPDIS_MASK, (param)<<2, &((pSimBase)->sim_control))

/* reprogramable "wait" instruction disable */ 
#define ioctlSYS_WAIT(pSimBase, param) \
  periphBitGrpSet(SIM_CONTROL_WAITDIS_MASK, param, &((pSimBase)->sim_control))

/* subset of teh ones above, maintained for backward compatibility */
#define ioctlSYS_STOP_PERMANENT_DISABLE(pSimBase, param) \
  periphBitGrpSet(SIM_CONTROL_STOPDIS_MASK, (SYS_DISABLE_PERMANENT)<<2, &((pSimBase)->sim_control))
#define ioctlSYS_WAIT_PERMANENT_DISABLE(pSimBase, param) \
  periphBitGrpSet(SIM_CONTROL_WAITDIS_MASK, SYS_DISABLE_PERMANENT, &((pSimBase)->sim_control))

/* issue software reset */
#define ioctlSYS_SOFTWARE_RESET(pSimBase, param) \
  periphBitSet(SIM_CONTROL_SWRST, &((pSimBase)->sim_control))

/* OnCE enable/disable */
#define ioctlSYS_ONCE(pSimBase, param) \
  if(param) periphBitSet(SIM_CONTROL_ONCEEBL, &((pSimBase)->sim_control));\
  else periphBitClear(SIM_CONTROL_ONCEEBL, &((pSimBase)->sim_control))

/* backward compatibility macros */
#define ioctlSYS_ONCE_ENABLE(pSimBase, param) \
  periphBitSet(SIM_CONTROL_ONCEEBL, &((pSimBase)->sim_control))
#define ioctlSYS_ONCE_DISABLE(pSimBase, param) \
  periphBitClear(SIM_CONTROL_ONCEEBL, &((pSimBase)->sim_control))


/* enable modules in STOP mode */
#define ioctlSYS_ENABLE_IN_STOP(pSimBase, param) { \
  if((param) & SYS_PCE3_REG_INDEX) periphBitSet((UWord16)((param)&0xffff), &((pSimBase)->sim_sd3));    \
  if((param) & SYS_PCE2_REG_INDEX) periphBitSet((UWord16)((param)&0xffff), &((pSimBase)->sim_sd2));    \
  if((param) & SYS_PCE1_REG_INDEX) periphBitSet((UWord16)((param)&0xffff), &((pSimBase)->sim_sd1));    \
  if((param) & SYS_PCE0_REG_INDEX) periphBitSet((UWord16)((param)&0xffff), &((pSimBase)->sim_sd0)); }
  
/* disable modules in STOP mode */
#define ioctlSYS_DISABLE_IN_STOP(pSimBase, param) { \
  if((param) & SYS_PCE3_REG_INDEX) periphBitClear((UWord16)((param)&0xffff), &((pSimBase)->sim_sd3));     \
  if((param) & SYS_PCE2_REG_INDEX) periphBitClear((UWord16)((param)&0xffff), &((pSimBase)->sim_sd2));    \
  if((param) & SYS_PCE1_REG_INDEX) periphBitClear((UWord16)((param)&0xffff), &((pSimBase)->sim_sd1));    \
  if((param) & SYS_PCE0_REG_INDEX) periphBitClear((UWord16)((param)&0xffff), &((pSimBase)->sim_sd0)); }


/* enable peripheral clock */
#define ioctlSYS_PERIPH_CLK_ENABLE(pSimBase, param) { \
  if((param) & SYS_PCE3_REG_INDEX) periphBitSet((UWord16)((param)&0xffff), &((pSimBase)->sim_pce3));    \
  if((param) & SYS_PCE2_REG_INDEX) periphBitSet((UWord16)((param)&0xffff), &((pSimBase)->sim_pce2));    \
  if((param) & SYS_PCE1_REG_INDEX) periphBitSet((UWord16)((param)&0xffff), &((pSimBase)->sim_pce1));    \
  if((param) & SYS_PCE0_REG_INDEX) periphBitSet((UWord16)((param)&0xffff), &((pSimBase)->sim_pce0)); }

/* disable peripheral clock */
#define ioctlSYS_PERIPH_CLK_DISABLE(pSimBase, param) { \
  if((param) & SYS_PCE3_REG_INDEX) periphBitClear((UWord16)((param)&0xffff), &((pSimBase)->sim_pce3));    \
  if((param) & SYS_PCE2_REG_INDEX) periphBitClear((UWord16)((param)&0xffff), &((pSimBase)->sim_pce2));    \
  if((param) & SYS_PCE1_REG_INDEX) periphBitClear((UWord16)((param)&0xffff), &((pSimBase)->sim_pce1));    \
  if((param) & SYS_PCE0_REG_INDEX) periphBitClear((UWord16)((param)&0xffff), &((pSimBase)->sim_pce0)); }


/* enable modules in STOP mode, second register  */
#define ioctlSYS_ENABLE_IN_STOP_REG2(pSimBase, param) \
  periphBitSet((param), &((pSimBase)->sim_sd2)); 
  
/* disable modules in STOP mode, second register  */
#define ioctlSYS_DISABLE_IN_STOP_REG2(pSimBase, param) \
  periphBitClear((param), &((pSimBase)->sim_sd2)); 

/* enable peripheral clock, second register */
#define ioctlSYS_PERIPH_CLK_REG2_ENABLE(pSimBase, param) \
  periphBitSet((param), &((pSimBase)->sim_pce2));

/* disable peripheral clock, second register  */
#define ioctlSYS_PERIPH_CLK_REG2_DISABLE(pSimBase,  param) \
  periphBitClear((param), &((pSimBase)->sim_pce2));


/* enable High_Speed clock for peripheral modules */
#define ioctlSYS_HS_CLOCK_ENABLE(pSimBase, param) \
  periphBitSet(param, &((pSimBase)->sim_pcr))

/* disable High_Speed clock for peripheral modules */
#define ioctlSYS_HS_CLOCK_DISABLE(pSimBase, param) \
  periphBitClear(param, &((pSimBase)->sim_pcr))


#if SIM_VERSION == 8
/* pins configuration usign GPS registers */

#define ioctlSYS_SET_A0PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSAL_A0, &((pSimBase)->sim_gpsal)); \
  else periphBitClear(SIM_GPSAL_A0, &((pSimBase)->sim_gpsal))
  
#define ioctlSYS_SET_B1PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSBL_B1, &((pSimBase)->sim_gpsbl)); \
  else periphBitClear(SIM_GPSBL_B1, &((pSimBase)->sim_gpsbl))
  
#define ioctlSYS_SET_C0PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSCL_C0, &((pSimBase)->sim_gpscl)); \
  else periphBitClear(SIM_GPSCL_C0, &((pSimBase)->sim_gpscl))

#define ioctlSYS_SET_C5PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSCL_C5, &((pSimBase)->sim_gpscl)); \
  else periphBitClear(SIM_GPSCL_C5, &((pSimBase)->sim_gpscl))
  
#define ioctlSYS_SET_C2PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCL_C2_MASK, param, &((pSimBase)->sim_gpscl))
  
#define ioctlSYS_SET_C3PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCL_C3_MASK, param, &((pSimBase)->sim_gpscl))
  
#define ioctlSYS_SET_C4PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCL_C4_MASK, param, &((pSimBase)->sim_gpscl))
  
#define ioctlSYS_SET_C6PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCL_C6_MASK, param, &((pSimBase)->sim_gpscl))
  
#define ioctlSYS_SET_C7PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCL_C7_MASK, param, &((pSimBase)->sim_gpscl))
  

#define ioctlSYS_SET_C8PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCH_C8_MASK, param, &((pSimBase)->sim_gpsch))
 
#define ioctlSYS_SET_C9PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCH_C9_MASK, param, &((pSimBase)->sim_gpsch))

#define ioctlSYS_SET_C10PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCH_C10_MASK, param, &((pSimBase)->sim_gpsch))

#define ioctlSYS_SET_C11PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCH_C11_MASK, param, &((pSimBase)->sim_gpsch))

#define ioctlSYS_SET_C12PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCH_C12_MASK, param, &((pSimBase)->sim_gpsch))

#define ioctlSYS_SET_C13PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCH_C13_MASK, param, &((pSimBase)->sim_gpsch))

#define ioctlSYS_SET_C14PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCH_C14_MASK, param, &((pSimBase)->sim_gpsch))

#define ioctlSYS_SET_C15PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCH_C15_MASK, param, &((pSimBase)->sim_gpsch))  
  
 
#define ioctlSYS_SET_E4PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSEL_E4, &((pSimBase)->sim_gpsel)); \
  else periphBitClear(SIM_GPSEL_E4, &((pSimBase)->sim_gpsel))

#define ioctlSYS_SET_E5PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSEL_E5, &((pSimBase)->sim_gpsel)); \
  else periphBitClear(SIM_GPSEL_E5, &((pSimBase)->sim_gpsel))

#define ioctlSYS_SET_E6PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSEL_E6, &((pSimBase)->sim_gpsel)); \
  else periphBitClear(SIM_GPSEL_E6, &((pSimBase)->sim_gpsel))
  
#define ioctlSYS_SET_E7PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSEL_E7, &((pSimBase)->sim_gpsel)); \
  else periphBitClear(SIM_GPSEL_E7, &((pSimBase)->sim_gpsel))


#define ioctlSYS_SET_F0PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFL_F0_MASK, param, &((pSimBase)->sim_gpsfl))  
  
#define ioctlSYS_SET_F1PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFL_F1_MASK, param, &((pSimBase)->sim_gpsfl))  

#define ioctlSYS_SET_F2PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFL_F2_MASK, param, &((pSimBase)->sim_gpsfl))    
  
#define ioctlSYS_SET_F3PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFL_F3_MASK, param, &((pSimBase)->sim_gpsfl))    
  
#define ioctlSYS_SET_F4PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFL_F4_MASK, param, &((pSimBase)->sim_gpsfl))    
  
#define ioctlSYS_SET_F5PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFL_F5_MASK, param, &((pSimBase)->sim_gpsfl))    
  
#define ioctlSYS_SET_F6PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFL_F6_MASK, param, &((pSimBase)->sim_gpsfl))   
  
#define ioctlSYS_SET_F7PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFL_F7_MASK, param, &((pSimBase)->sim_gpsfl))    
  
#define ioctlSYS_SET_F8PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFH_F8_MASK, param, &((pSimBase)->sim_gpsfh))  



#define ioctlSYS_SET_TMRA3_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPSN_TMRA3, &((pSimBase)->sim_ipsn)); \
  else periphBitClear(SIM_IPSN_TMRA3, &((pSimBase)->sim_ipsn))

#define ioctlSYS_SET_TMRA2_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPSN_TMRA2, &((pSimBase)->sim_ipsn)); \
  else periphBitClear(SIM_IPSN_TMRA2, &((pSimBase)->sim_ipsn))

#define ioctlSYS_SET_TMRA1_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPSN_TMRA1, &((pSimBase)->sim_ipsn)); \
  else periphBitClear(SIM_IPSN_TMRA1, &((pSimBase)->sim_ipsn))

#define ioctlSYS_SET_TMRA0_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPSN_TMRA0, &((pSimBase)->sim_ipsn)); \
  else periphBitClear(SIM_IPSN_TMRA0, &((pSimBase)->sim_ipsn))

#define ioctlSYS_SET_SCI1_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPSN_SCI1, &((pSimBase)->sim_ipsn)); \
  else periphBitClear(SIM_IPSN_SCI1, &((pSimBase)->sim_ipsn))

#define ioctlSYS_SET_SCI0_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPSN_SCI0, &((pSimBase)->sim_ipsn)); \
  else periphBitClear(SIM_IPSN_SCI0, &((pSimBase)->sim_ipsn))
#endif

#if SIM_VERSION == 7

/* pins configuration usign GPS registers */
#define ioctlSYS_SET_A0PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSAL_A0, &((pSimBase)->sim_gpsal)); \
  else periphBitClear(SIM_GPSAL_A0, &((pSimBase)->sim_gpsal))
  
#define ioctlSYS_SET_B11PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSBH_B11_MASK , param, &((pSimBase)->sim_gpsbh))
  
#define ioctlSYS_SET_B10PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSBH_B10_MASK , param, &((pSimBase)->sim_gpsbh))
  
#define ioctlSYS_SET_B9PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSBH_B9_MASK , param, &((pSimBase)->sim_gpsbh))
  
#define ioctlSYS_SET_C15PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSCH_C15, &((pSimBase)->sim_gpsch)); \
  else periphBitClear(SIM_GPSCH_C15, &((pSimBase)->sim_gpsch))
  
#define ioctlSYS_SET_C14PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSCH_C14, &((pSimBase)->sim_gpsch)); \
  else periphBitClear(SIM_GPSCH_C14, &((pSimBase)->sim_gpsch))
  
#define ioctlSYS_SET_C13PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCH_C13_MASK , param, &((pSimBase)->sim_gpsch))
  
#define ioctlSYS_SET_C12PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCH_C12_MASK , param, &((pSimBase)->sim_gpsch))
  
#define ioctlSYS_SET_C11PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCH_C11_MASK , param, &((pSimBase)->sim_gpsch))
  
#define ioctlSYS_SET_C10PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCH_C10_MASK , param, &((pSimBase)->sim_gpsch))

#define ioctlSYS_SET_C9PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSCH_C9, &((pSimBase)->sim_gpsch)); \
  else periphBitClear(SIM_GPSCH_C9, &((pSimBase)->sim_gpsch))
  
#define ioctlSYS_SET_C8PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCH_C8_MASK , param, &((pSimBase)->sim_gpsch))
  
#define ioctlSYS_SET_C7PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSCL_C7, &((pSimBase)->sim_gpscl)); \
  else periphBitClear(SIM_GPSCL_C7, &((pSimBase)->sim_gpscl))
  
#define ioctlSYS_SET_C6PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCL_C6_MASK , param, &((pSimBase)->sim_gpscl))

#define ioctlSYS_SET_C5PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSCL_C5, &((pSimBase)->sim_gpscl)); \
  else periphBitClear(SIM_GPSCL_C5, &((pSimBase)->sim_gpscl))
  
#define ioctlSYS_SET_C4PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCL_C4_MASK , param, &((pSimBase)->sim_gpscl))
  
#define ioctlSYS_SET_C3PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCL_C3_MASK , param, &((pSimBase)->sim_gpscl))
  
#define ioctlSYS_SET_C2PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSCL_C2_MASK , param, &((pSimBase)->sim_gpscl))

#define ioctlSYS_SET_C0PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSCL_C0, &((pSimBase)->sim_gpscl)); \
  else periphBitClear(SIM_GPSCL_C0, &((pSimBase)->sim_gpscl))
  
                            
#define ioctlSYS_SET_D7PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSDL_D7_MASK , param, &((pSimBase)->sim_gpsdl))
  
#define ioctlSYS_SET_D6PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSDL_D6_MASK , param, &((pSimBase)->sim_gpsdl))
  
#define ioctlSYS_SET_D5PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSDL_D5_MASK , param, &((pSimBase)->sim_gpsdl))
            
#define ioctlSYS_SET_E9PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSEH_E9, &((pSimBase)->sim_gpseh)); \
  else periphBitClear(SIM_GPSEH_E9, &((pSimBase)->sim_gpseh))
  
#define ioctlSYS_SET_E8PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSEH_E8, &((pSimBase)->sim_gpseh)); \
  else periphBitClear(SIM_GPSEH_E8, &((pSimBase)->sim_gpseh))
  
#define ioctlSYS_SET_E7PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSEL_E7_MASK , param, &((pSimBase)->sim_gpsel))
  
#define ioctlSYS_SET_E6PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSEL_E6_MASK , param, &((pSimBase)->sim_gpsel))
  
#define ioctlSYS_SET_E5PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSEL_E5, &((pSimBase)->sim_gpsel)); \
  else periphBitClear(SIM_GPSEL_E5, &((pSimBase)->sim_gpsel))
  
#define ioctlSYS_SET_E4PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSEL_E4 , &((pSimBase)->sim_gpsel)); \
  else periphBitClear(SIM_GPSEL_E4 , &((pSimBase)->sim_gpsel))
            
#define ioctlSYS_SET_F15PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSFH_F15, &((pSimBase)->sim_gpsfh)); \
  else periphBitClear(SIM_GPSFH_F15, &((pSimBase)->sim_gpsfh))
  
#define ioctlSYS_SET_F14PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSFH_F14, &((pSimBase)->sim_gpsfh)); \
  else periphBitClear(SIM_GPSFH_F14, &((pSimBase)->sim_gpsfh))
  
#define ioctlSYS_SET_F13PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSFH_F13, &((pSimBase)->sim_gpsfh)); \
  else periphBitClear(SIM_GPSFH_F13, &((pSimBase)->sim_gpsfh))
  
#define ioctlSYS_SET_F12PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSFH_F12, &((pSimBase)->sim_gpsfh)); \
  else periphBitClear(SIM_GPSFH_F12, &((pSimBase)->sim_gpsfh))
  
#define ioctlSYS_SET_F11PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSFH_F11, &((pSimBase)->sim_gpsfh)); \
  else periphBitClear(SIM_GPSFH_F11, &((pSimBase)->sim_gpsfh))
  
#define ioctlSYS_SET_F10PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFH_F10_MASK , param, &((pSimBase)->sim_gpsfh))
  
#define ioctlSYS_SET_F9PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFH_F9_MASK , param, &((pSimBase)->sim_gpsfh))
  
#define ioctlSYS_SET_F8PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFH_F8_MASK , param, &((pSimBase)->sim_gpsfh))
  
#define ioctlSYS_SET_F7PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFL_F7_MASK , param, &((pSimBase)->sim_gpsfl))
  
#define ioctlSYS_SET_F6PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFL_F6_MASK , param, &((pSimBase)->sim_gpsfl))

#define ioctlSYS_SET_F5PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSFL_F5, &((pSimBase)->sim_gpsfl)); \
  else periphBitClear(SIM_GPSFL_F5, &((pSimBase)->sim_gpsfl))
  
#define ioctlSYS_SET_F4PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSFL_F4, &((pSimBase)->sim_gpsfl)); \
  else periphBitClear(SIM_GPSFL_F4, &((pSimBase)->sim_gpsfl))
  
#define ioctlSYS_SET_F3PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSFL_F3, &((pSimBase)->sim_gpsfl)); \
  else periphBitClear(SIM_GPSFL_F3, &((pSimBase)->sim_gpsfl))
  
#define ioctlSYS_SET_F2PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSFL_F2, &((pSimBase)->sim_gpsfl)); \
  else periphBitClear(SIM_GPSFL_F2, &((pSimBase)->sim_gpsfl))
  
#define ioctlSYS_SET_F1PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFL_F1_MASK , param, &((pSimBase)->sim_gpsfl))
  
#define ioctlSYS_SET_F0PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSFL_F0_MASK , param, &((pSimBase)->sim_gpsfl))
            
            
#define ioctlSYS_SET_G11PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSGH_G11_MASK , param, &((pSimBase)->sim_gpsgh))
  
#define ioctlSYS_SET_G10PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSGH_G10_MASK , param, &((pSimBase)->sim_gpsgh))
  
#define ioctlSYS_SET_G9PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSGH_G9_MASK , param, &((pSimBase)->sim_gpsgh))
  
#define ioctlSYS_SET_G8PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSGH_G8_MASK , param, &((pSimBase)->sim_gpsgh))
  
#define ioctlSYS_SET_G7PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSGL_G7_MASK , param, &((pSimBase)->sim_gpsgl))
  
#define ioctlSYS_SET_G6PAD_FUNCTION(pSimBase, param) \
  periphBitGrpSet(SIM_GPSGL_G6_MASK , param, &((pSimBase)->sim_gpsgl))
  
#define ioctlSYS_SET_G5PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSGL_G5, &((pSimBase)->sim_gpsgl)); \
  else periphBitClear(SIM_GPSGL_G5, &((pSimBase)->sim_gpsgl))
  
#define ioctlSYS_SET_G4PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSGL_G4, &((pSimBase)->sim_gpsgl)); \
  else periphBitClear(SIM_GPSGL_G4, &((pSimBase)->sim_gpsgl))
  
#define ioctlSYS_SET_G3PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSGL_G3, &((pSimBase)->sim_gpsgl)); \
  else periphBitClear(SIM_GPSGL_G3, &((pSimBase)->sim_gpsgl))
  
#define ioctlSYS_SET_G2PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSGL_G2, &((pSimBase)->sim_gpsgl)); \
  else periphBitClear(SIM_GPSGL_G2, &((pSimBase)->sim_gpsgl))
  
#define ioctlSYS_SET_G1PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSGL_G1, &((pSimBase)->sim_gpsgl)); \
  else periphBitClear(SIM_GPSGL_G1, &((pSimBase)->sim_gpsgl))
  
#define ioctlSYS_SET_G0PAD_FUNCTION(pSimBase, param) \
  if(param) periphBitSet(SIM_GPSGL_G0, &((pSimBase)->sim_gpsgl)); \
  else periphBitClear(SIM_GPSGL_G0, &((pSimBase)->sim_gpsgl))
            
    
#define ioctlSYS_SET_TMRB3_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPS0_TMRB3, &((pSimBase)->sim_ips0)); \
  else periphBitClear(SIM_IPS0_TMRB3, &((pSimBase)->sim_ips0))

#define ioctlSYS_SET_TMRB2_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPS0_TMRB2, &((pSimBase)->sim_ips0)); \
  else periphBitClear(SIM_IPS0_TMRB2, &((pSimBase)->sim_ips0))
  
#define ioctlSYS_SET_TMRB1_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPS0_TMRB1, &((pSimBase)->sim_ips0)); \
  else periphBitClear(SIM_IPS0_TMRB1, &((pSimBase)->sim_ips0))
  
#define ioctlSYS_SET_TMRB0_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPS0_TMRB0, &((pSimBase)->sim_ips0)); \
  else periphBitClear(SIM_IPS0_TMRB0, &((pSimBase)->sim_ips0))
  
#define ioctlSYS_SET_TMRA3_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPS0_TMRA3, &((pSimBase)->sim_ips0)); \
  else periphBitClear(SIM_IPS0_TMRA3, &((pSimBase)->sim_ips0))
  
#define ioctlSYS_SET_TMRA2_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPS0_TMRA2, &((pSimBase)->sim_ips0)); \
  else periphBitClear(SIM_IPS0_TMRA2, &((pSimBase)->sim_ips0))
  
#define ioctlSYS_SET_TMRA1_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPS0_TMRA1, &((pSimBase)->sim_ips0)); \
  else periphBitClear(SIM_IPS0_TMRA1, &((pSimBase)->sim_ips0))
  
#define ioctlSYS_SET_TMRA0_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPS0_TMRA0, &((pSimBase)->sim_ips0)); \
  else periphBitClear(SIM_IPS0_TMRA0, &((pSimBase)->sim_ips0))
  
#define ioctlSYS_SET_PWMAF3_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPS0_PWMAF3, &((pSimBase)->sim_ips0)); \
  else periphBitClear(SIM_IPS0_PWMAF3, &((pSimBase)->sim_ips0))
  
#define ioctlSYS_SET_PWMAF2_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPS0_PWMAF2, &((pSimBase)->sim_ips0)); \
  else periphBitClear(SIM_IPS0_PWMAF2, &((pSimBase)->sim_ips0))
  
#define ioctlSYS_SET_PWMAF1_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPS0_PWMAF1, &((pSimBase)->sim_ips0)); \
  else periphBitClear(SIM_IPS0_PWMAF1, &((pSimBase)->sim_ips0))
  
#define ioctlSYS_SET_PWMAF0_INPUT(pSimBase, param) \
  if(param) periphBitSet(SIM_IPS0_PWMAF0, &((pSimBase)->sim_ips0)); \
  else periphBitClear(SIM_IPS0_PWMAF0, &((pSimBase)->sim_ips0))

#endif


#if SIM_VERSION >= 7
#define ioctlSYS_SELECT_MASTER_PIT(pSimBase, param) \
  if(param) periphBitSet(SIM_MISC0_PIT_MSTR, &((pSimBase)->sim_misc0)); \
  else periphBitClear(SIM_MISC0_PIT_MSTR, &((pSimBase)->sim_misc0))

#define ioctlSYS_SELECT_CLKIN(pSimBase, param) \
  if(param) periphBitSet(SIM_MISC0_CLKINSEL, &((pSimBase)->sim_misc0)); \
  else periphBitClear(SIM_MISC0_CLKINSEL, &((pSimBase)->sim_misc0))
#endif

#if SIM_VERSION == 8
#define ioctlSYS_FAST_MODE(pSimBase, param) \
  if(param) periphBitSet(SIM_MISC0_FAST_MODE, &((pSimBase)->sim_misc0)); \
  else periphBitClear(SIM_MISC0_FAST_MODE, &((pSimBase)->sim_misc0))

#define ioctlSYS_ADC_REORDERING(pSimBase, param) \
  if(param) periphBitSet(SIM_MISC0_ADC_SCTRL, &((pSimBase)->sim_misc0)); \
  else periphBitClear(SIM_MISC0_ADC_SCTRL, &((pSimBase)->sim_misc0))

#define ioctlSYS_GET_FAST_MODE(pSimBase, param) \
  periphBitTest(SIM_MISC0_MODE_STAT, &((pSimBase)->sim_misc0))

#endif


/* set large-regulator mode */
#define ioctlSYS_SET_POWER_MODE(pSimBase, param) \
  periphBitGrpZS(SIM_POWER_LRSTDBY_MASK, param, &((pSimBase)->sim_power))

/* get large-regulator mode */
#define ioctlSYS_GET_POWER_MODE(pSimBase, param) \
  periphBitTest(SIM_POWER_LRSTDBY_MASK, &((pSimBase)->sim_power))


/* set low power mode */
#define ioctlSYS_SET_LOW_POWER_MODE(pSimBase, param) \
  periphBitGrpZS(SIM_PWRMODE_LPMODE_MASK, param, &((pSimBase)->sim_pwrmode))

/* get low power mode status */
#define ioctlSYS_GET_LOW_POWER_MODE(pSimBase, param) \
  periphBitTest(SIM_PWRMODE_LPMS_MASK, &((pSimBase)->sim_pwrmode))

/* set very low power mode  */
#define ioctlSYS_SET_VERY_LOW_POWER_MODE(pSimBase, param) \
  periphBitGrpZS(SIM_PWRMODE_VLPMODE_MASK, param, &((pSimBase)->sim_pwrmode))

/* get very low power mode status */
#define ioctlSYS_GET_VERY_LOW_POWER_MODE(pSimBase, param) \
  periphBitTest(SIM_PWRMODE_VLPMS_MASK, &((pSimBase)->sim_pwrmode))

  
/* test reset status SWR, COPR, EXTR, POR bits */
#define ioctlSYS_TEST_RESET_SOURCE(pSimBase, param) \
  periphBitTest(param, &((pSimBase)->sim_rststs))

/* clear reset status SWR, COPR, EXTR, POR bits */
#define ioctlSYS_CLEAR_RESET_SOURCE(pSimBase, param) \
  periphMemInvBitSet(param, &((pSimBase)->sim_rststs))

/* SIM software control registers */ 
#define ioctlSYS_WRITE_SW_CONTROL_REG0(pSimBase, param) \
  periphMemWrite(param, &((pSimBase)->sim_scr0))

#define ioctlSYS_WRITE_SW_CONTROL_REG1(pSimBase, param) \
  periphMemWrite(param, &((pSimBase)->sim_scr1))

#define ioctlSYS_WRITE_SW_CONTROL_REG2(pSimBase, param) \
  periphMemWrite(param, &((pSimBase)->sim_scr2))

#define ioctlSYS_WRITE_SW_CONTROL_REG3(pSimBase, param) \
  periphMemWrite(param, &((pSimBase)->sim_scr3))


#if SIM_VERSION == 8

#define ioctlSYS_WRITE_SW_CONTROL_REG4(pSimBase, param) \
  periphMemWrite(param, &((pSimBase)->sim_scr4))

#define ioctlSYS_WRITE_SW_CONTROL_REG5(pSimBase, param) \
  periphMemWrite(param, &((pSimBase)->sim_scr5))

#define ioctlSYS_WRITE_SW_CONTROL_REG6(pSimBase, param) \
  periphMemWrite(param, &((pSimBase)->sim_scr6))

#define ioctlSYS_WRITE_SW_CONTROL_REG7(pSimBase, param) \
  periphMemWrite(param, &((pSimBase)->sim_scr7))

#define ioctlSYS_READ_SW_CONTROL_REG4(pSimBase, param) \
  periphMemRead(&((pSimBase)->sim_scr4))

#define ioctlSYS_READ_SW_CONTROL_REG5(pSimBase, param) \
  periphMemRead(&((pSimBase)->sim_scr5))

#define ioctlSYS_READ_SW_CONTROL_REG6(pSimBase, param) \
  periphMemRead(&((pSimBase)->sim_scr6))

#define ioctlSYS_READ_SW_CONTROL_REG7(pSimBase, param) \
  periphMemRead(&((pSimBase)->sim_scr7))

#endif


#define ioctlSYS_READ_SW_CONTROL_REG0(pSimBase, param) \
  periphMemRead(&((pSimBase)->sim_scr0))

#define ioctlSYS_READ_SW_CONTROL_REG1(pSimBase, param) \
  periphMemRead(&((pSimBase)->sim_scr1))

#define ioctlSYS_READ_SW_CONTROL_REG2(pSimBase, param) \
  periphMemRead(&((pSimBase)->sim_scr2))

#define ioctlSYS_READ_SW_CONTROL_REG3(pSimBase, param) \
  periphMemRead(&((pSimBase)->sim_scr3))

/* enable/disable CLKOUT pin */
#define ioctlSYS_CLKOUT(pSimBase, param) \
  if(param) periphBitClear(SIM_CLKOSR_CLKDIS, &((pSimBase)->sim_clkosr));\
  else periphBitSet(SIM_CLKOSR_CLKDIS, &((pSimBase)->sim_clkosr))
  
/* enable/disable CLKOUT pin, backward comaptibility only */
#define ioctlSYS_CLKOUT_ENABLE(pSimBase, param)  \
  periphBitClear(SIM_CLKOSR_CLKDIS, &((pSimBase)->sim_clkosr))
#define ioctlSYS_CLKOUT_DISABLE(pSimBase, param) \
  periphBitSet(SIM_CLKOSR_CLKDIS, &((pSimBase)->sim_clkosr))

/* select CLSKOUT source */
#define ioctlSYS_CLKOUT_SELECT(pSimBase, param)  \
  periphBitGrpSet(SIM_CLKOSR_CLKOSEL_MASK, param, &((pSimBase)->sim_clkosr))
  
#if SIM_VERSION >= 7 
      /* enable/disable CLKOUT_1 pin */
    #define ioctlSYS_CLKOUT_1(pSimBase, param) \
      if(param) periphBitClear(SIM_CLKOSR_CLKDIS_1, &((pSimBase)->sim_clkosr));\
      else periphBitSet(SIM_CLKOSR_CLKDIS_1, &((pSimBase)->sim_clkosr))

    /* select CLSKOUT_1 source */
    #define ioctlSYS_CLKOUT_1_SELECT(pSimBase, param)  \
      periphBitGrpSet(SIM_CLKOSR_CLKOSEL_1_MASK, (param << 7), &((pSimBase)->sim_clkosr))
      
          /* select CLSKOUT_1 source */
    #define ioctlSYS_CLKODIV_SELECT(pSimBase, param)  \
      periphBitGrpSet(SIM_CLKOSR_CLOKDIV_MASK, param << 13, &((pSimBase)->sim_clkosr))
      
#endif 
  

/* JTAG ID */
#define ioctlSYS_READ_LSH_JTAG_ID(pSimBase, param) \
  periphMemRead(&((pSimBase)->sim_lsh_id))

#define ioctlSYS_READ_MSH_JTAG_ID(pSimBase, param) \
  periphMemRead(&((pSimBase)->sim_msh_id))

/* memory reference via the I/O short address mode */
#define ioctlSYS_WRITE_IO_SHORT_ADDR_LOCATION_REG(pSimBase, param) \
  { periphMemWrite((UWord16)(((UWord32)(param)) & 0xFFFF), &((pSimBase)->sim_isall));   \
    periphMemWrite((UWord16)(((UWord32)(param)) >> 16), &((pSimBase)->sim_isalh));  }

#define ioctlSYS_READ_IO_SHORT_ADDR_LOCATION_REG(pSimBase, param) \
  (  (UWord32) periphMemRead(&((pSimBase)->sim_isall)) | \
    ((UWord32)(periphMemRead(&((pSimBase)->sim_isalh)) & 3) << 16) )

/* write protect PCE, SD and PCR */
#define ioctlSYS_WPROTECT_CLOCK_SETTINGS(pSimBase, param)    \
  periphBitGrpSet(SIM_PROT_PCEP_MASK, ((param)<<2), &((pSimBase)->sim_prot))

/* write protect IPS and GPSxx */
#define ioctlSYS_WPROTECT_SIGNALS_ROUTING(pSimBase, param)    \
  periphBitGrpSet(SIM_PROT_GIPSP_MASK, (param), &((pSimBase)->sim_prot))

/* write protect GPIO_D_PER, GPIO_D_PPMODE, and GPIO_D_DRIVE */
#define ioctlSYS_WPROTECT_GPIOD(pSimBase, param)    \
  periphBitGrpSet(SIM_PROT_GDP_MASK, ((param)<<4), &((pSimBase)->sim_prot))

/* Power Mode Control Write Protection */
#define ioctlSYS_WPROTECT_POWER_MODE(pSimBase, param)    \
  periphBitGrpSet(SIM_PROT_PMODE_MASK, ((param)<<6), &((pSimBase)->sim_prot))


#if SIM_VERSION >= 7

#define ioctlSYS_DMA_ENABLE(pSimBase, param) \
  periphBitGrpZS(SIM_CONTROL_DMAEBL_MASK, (param), &((pSimBase)->sim_control))

  /* enable/disable reset filter */
#define ioctlSYS_RST_FLT(pSimBase, param) \
  if(param) periphBitSet(SIM_CONTROL_RST_FILT, &((pSimBase)->sim_control));\
  else periphBitClear(SIM_CONTROL_RST_FILT, &((pSimBase)->sim_control))

     /* set Small Regulator 2.7 V mode */
 #define ioctlSYS_SET_27_POWER_MODE(pSimBase, param) \
   periphBitGrpZS(SIM_POWER_SR27STDBY_MASK, ( param << 2 ), &((pSimBase)->sim_power))
 
    /* get Small Regulator 2.7 V mode */
 #define ioctlSYS_GET_27_POWER_MODE(pSimBase, param) \
   periphBitTest(SIM_POWER_SR27STDBY_MASK, &((pSimBase)->sim_power))
   
   /* set Small Regulator 2.7 V powerdown mode */
 #define ioctlSYS_SET_27_POWERDOWN(pSimBase, param) \
   periphBitGrpZS(SIM_POWER_SR27PDN_MASK, (param << 4), &((pSimBase)->sim_power))
 
    /* get Small Regulator 2.7 V powerdown mode */
 #define ioctlSYS_GET_27_POWERDOWN(pSimBase, param) \
   periphBitTest(SIM_POWER_SR27PDN_MASK, &((pSimBase)->sim_power))
   
    /* set Small Regulator 1.2 V mode */
 #define ioctlSYS_SET_12_POWER_MODE(pSimBase, param) \
   periphBitGrpZS(SIM_POWER_SR12STDBY_MASK, (param << 6), &((pSimBase)->sim_power))
 
   /* get Small Regulator 1.2 V mode */
 #define ioctlSYS_GET_12_POWER_MODE(pSimBase, param) \
   periphBitTest(SIM_POWER_SR12STDBY_MASK, &((pSimBase)->sim_power))
  
#endif

/*  reset individual peripherals without resetting the entire chip */
#define ioctlSYS_PERIPH_SW_RESET(pSimBase, param) { \
  if((param) & SYS_PSWR3_REG_INDEX) periphBitSet((UWord16)((param)&0xffff), &((pSimBase)->sim_pswr3));    \
  if((param) & SYS_PSWR2_REG_INDEX) periphBitSet((UWord16)((param)&0xffff), &((pSimBase)->sim_pswr2));    \
  if((param) & SYS_PSWR1_REG_INDEX) periphBitSet((UWord16)((param)&0xffff), &((pSimBase)->sim_pswr1));    \
  if((param) & SYS_PSWR0_REG_INDEX) periphBitSet((UWord16)((param)&0xffff), &((pSimBase)->sim_pswr0)); }

#if 0  
#define ioctlLVI_CLEAR_LOW_VOLTAGE_INT(pLviBase, param) \
  periphMemWrite(((param) << 2), &((pLviBase)->lvisr))
#else
/* a workaround is to clear the LVI INT flag during LVIExx temporarily zeroed */
#define ioctlLVI_CLEAR_LOW_VOLTAGE_INT(pLviBase, param) \
  if((param) & LVI_INT) \
  { UWord16 tmp = periphMemRead(&((pLviBase)->lvictlr)); \
    periphMemWrite(0, &((pLviBase)->lvictlr)); \
    periphMemWrite(((param) << 2), &((pLviBase)->lvisr)); \
    periphMemWrite(tmp, &((pLviBase)->lvictlr)); } \
  else periphMemWrite(((param) << 2), &((pLviBase)->lvisr));
#endif

#ifdef __cplusplus
}
#endif

#endif

