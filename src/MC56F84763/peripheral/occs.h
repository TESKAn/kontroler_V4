/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name: occs.h
*
* $Date:      May-13-2013$
*
* $Version:   2.5.59.0$
*
* Description: Header file for the On-chip Clock Synthesis (OCCS) driver.
*
* This file supports different hardware versions of the module. A version
* of module used in your project is defined in the "arch.h" processor 
* architecture definition file.
*
*  OCCS_VERSION_1 .. 56F83xx devices, see MC56F8300UM.pdf
*  OCCS_VERSION_2 .. 56F801x devices, see MC56F8000RM.pdf
*  OCCS_VERSION_3 .. 56F802x/3x devices, see MC56F802x3xRM.pdf
*  OCCS_VERSION_4 .. 56F800x devices, see MC56F8006RM.pdf
*  OCCS_VERSION_5 .. 56F824x/5x devices, see MC56F825xRM.pdf
*  OCCS_VERSION_6 .. 56F84xxx devices, see MC56F84xxxRM.pdf
*  OCCS_VERSION_7 .. 56F827xx devices, see MC56F827xRM.pdf
*
*******************************************************************************/

#ifndef __OCCS_H
#define __OCCS_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before occs.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
    OCCS base address used as device handle in ioctl()
*******************************************************************************/

#define OCCS (&ArchIO.Pll)

/*************************************************************
* arch.h should define device-specific information about OCCS
**************************************************************/

#if !defined(OCCS_VERSION) || !defined(OCCS_HAS_RXOSC)
#error OCCS not properly described in arch.h (old Quick_Start version?)
#endif

/******************************************************************************
*
*                      General Interface Description
*
*
* The On-Chip Clock Synthesis (OCCS) module allows product design using inexpensive
* 8MHz crystals to run the MC56F8300 at frequencies up to 60Mhz. This module provides
* the 2X system clock frequency to the System Integration Module (SIM), using it to
* generate the various chip clocks. This module also produces the OSC_CLK signals.
* 
* The OCCS module interfaces with the Oscillator and PLL, as well as having an On-Chip
* prescaler. The OCCS module characteristics include:
* • Oscillator can be crystal controlled or driven from an external clock generator
* • Two-bit prescaler can divide oscillator output by 1, 2, 4 or 8 prior to its
*   use as the PLL source clock
* • Two-bit postscaler provides similar control for the PLL output
* • Ability to power down the internal PLL
* • Provides 2X master clock frequency and OSC_CLK signals.
* • Safety shutdown feature available in the event the PLL reference clock disappears
* 
* The clock generation module provides the programming interface for both the PLL
* and on and off-chip oscillators.
*
* For more information, please refer to the user manual for the particular chip that you
* are using, such as the MC56F8300 Peripheral Manual, for a description
* of the OCCS device.
*
* The OCCS device driver interface uses "ioctl" call to control specific OCCS functions
* during operation. For details see "ioctl" call.
*
* Note: A simplified OCCS module is implemented on MF56F80xx devices (no prescaler, 
*       fixed PLL multiplier). Consult MC56F8000 Peripheral Manual for more details.
*
******************************************************************************/

/*******************************************************************************
    Defines for appconfig.h
********************************************************************************/

/*
    #define EXTCLK                  8000000UL   // board oscillator frequency
    #define INT_VECTOR_ADDR_yy      occsISR
    #define INT_PRIORITY_LEVEL_yy   // one of INTC_DISABLED, INTC_LEVEL0, INTC_LEVEL1 or INTC_LEVEL2

    #define OCCS_PLLCR_INIT         0x82        // lock detector on, postscaler (PLL) used
    #define OCCS_PLLDB_INIT         0x2019      // 52 MHz MC core, 208 MHz VCO
    #define OCCS_OSCTL_INIT         0x0000
    #define OCCS_REQUIRED_LOCK_MODE 0x20        // 0x20 (LCK0-fine) or 0x40 (LCK1-coarse)

    where:  
         yy is PLL (OCCS) interrupt vector number (e.g. 21 on MC56F8346)

New on MC56f8006 
	#define EXTAL 					9000000L	//Crystal oscillator frequency
*/


/*****************************************************************
* Single-Instruction  ioctl() commands
*
*  Word16 ioctl( OCCS_module_identifier, Command_name, Parameter );
*
******************************************************************

        COMMAND NAME                      PARAMETERS, COMMENTS
------------------------------------------------------------------ */
#define OCCS_INT_ENABLE             /* combination of (OCCS_LOL0_INT_xxx  (xxx=ANY_EDGE/FALLING_EDGE/RISING_EDGE ) | OCCS_LOL1_INT_xxx (xxx=ANY_EDGE/FALLING_EDGE/RISING_EDGE ) | OCCS_LOSS_OF_CLOCK_INT ), enable the selected OCCS interrupts. Note: PLL Interrupt 1 and PLL Interrupt 0 can be enabled only if they were disabled before the usage of this command. It is not possible to change the mode of enabled PLL Interrupt 1 or 0 (for example from any edge to falling edge) */
#define OCCS_INT_DISABLE            /* combination of (OCCS_LOL1_INT|OCCS_LOL0_INT|OCCS_LOSS_OF_CLOCK_INT), disable the selected OCCS interrupts */

#define OCCS_LOCK_DETECTOR          /* OCCS_ENABLE/OCCS_DISABLE, enable/disable the lock detector */

#define OCCS_CLEAR_FLAG             /* combination of OCCS_STATUS_xxx (xxx=LOCK_LOST_INT1|LOCK_LOST_INT0|CLOCK_LOST ), clear the selected flags (bits) from the PLL Status register */

#define OCCS_WRITE_CONTROL_REG      /* UWord16, write the parameter value to the PLL Control register */
#define OCCS_WRITE_DIVIDE_BY_REG    /* UWord16, write the parameter value to the PLL Divide-by register */
#define OCCS_WRITE_OSC_CONTROL_REG  /* UWord16, write the parameter value to the Oscillator Control register */

#define OCCS_READ_CONTROL_REG       /* NULL, read and return the content of the PLL Control register as UWord16 */
#define OCCS_READ_DIVIDE_BY_REG     /* NULL, read and return the content of the PLL Divide-by register as UWord16 */
#define OCCS_READ_STATUS_REG        /* NULL, read and return the content of the PLL Status register as UWord16 */
#define OCCS_READ_OSC_CONTROL_REG   /* NULL, read and return the content of the Oscillator Control register as UWord16 */

#if OCCS_VERSION >= 6
#define OCCS_READ_OSC_CONTROL2_REG   /* NULL, read and return the content of the Oscillator Control 2 register as UWord16 */
#define OCCS_WRITE_OSC_CONTROL2_REG  /* UWord16, write the parameter value to the Oscillator Control 2 register */
#endif
/*******************************************************************************
    Full OCCS (8xxx family) clock configuration commands
*******************************************************************************/

#if OCCS_VERSION == 1
#define OCCS_POWER_MODE             /* OCCS_HIGH_POWER/OCCS_LOW_POWER, set the resonator/crystal power mode */
#define OCCS_DIRECT_CLOCK_MODE      /* OCCS_ENABLE/OCCS_DISABLE, set the clkin mode on XTAL (turn off osc) */

#endif

#if OCCS_VERSION <= 2
#define OCCS_TURN_OFF_CHARGE_PUMP   /* NULL, use this command only in the event of loss of clock */
#define OCCS_SHUTDOWN               /* NULL, shutdown chip on loss-of-clock (charge pump must be off) */
#endif


/*******************************************************************************
    Internal Relaxation Oscillator commands
*******************************************************************************/

#if OCCS_HAS_RXOSC
#define OCCS_SET_PRESCALER_CLOCK            /* OCCS_INTERNAL_RELAX_OSC/OCCS_CRYSTAL_OSC, set the prescaler clock source. OCCS_CRYSTAL_OSC should only be set if XTAL and EXTAL pin functions are enabled in the appropriate GPIO control register */
#define OCCS_INTERNAL_RELAX_OSC_OPERATION   /* OCCS_ENABLE/OCCS_DISABLE/OCCS_STANDBY(80xx only), enable/disable the Relaxation Oscillator. Power-down the relaxation oscillator if the crystal oscillator is being used. To prevent loss of clock to the core or the PLL, set this bit only if the prescaler clock source has been changed to the crystal oscillator by setting the [OCCS_CTRL_PRECS] bit in PLLCR */ 
#endif /* OCCS_HAS_RXOSC */

/*******************************************************************************
    New Features of OCCS_VERSION_3
*******************************************************************************/
#if OCCS_VERSION >= 3
#define OCCS_POWER_MODE              /* OCCS_HIGH_POWER/OCCS_LOW_POWER, set the resonator/crystal power mode */
#define OCCS_DIRECT_CLOCK_MODE       /* OCCS_ENABLE/OCCS_DISABLE, enable/disable the direct clock input on the XTAL pin. - OCCS_ENABLE = use when the clock source is connected on the XTAL pin. - OCCS_DISABLE = use when the crystal or the resonator is connected on the EXTAL and XTAL pins. Note that the OCCS_SELECT_EXT_CLOCK_SOURCE ioctl command needs to be used first to switch clock input to OCCS_CLKIN_OSC. Then the OCCS_DIRECT_CLOCK_MODE command may be used to enable or disable direct clock input on XTAL */

#define OCCS_SET_CLOCK_CHECK         /* OCCS_ENABLE/OCCS_DISABLE, enable/disable the clock checking function. This command enables clock checking function and resets counters REF_COUNT and TARGET_CNT, when parameter is OCCS_ENABLE. When clock checking function finished, bit CHK_ENA is cleared and in counters REF_COUNT and TARGET_CNT are valid values. The parameter OCCS_DISABLE stops the clock checking function */
#endif

/*******************************************************************************
    New Features of OCCS_VERSION_4
*******************************************************************************/
#if OCCS_VERSION == 4
#define OCCS_SELECT_FREQ_RANGE       /* OCCS_32KHZ_CRYSTAL/OCCS_1MHZ_TO_16MHZ_CRYSTAL, select the frequency range */
#endif

/*******************************************************************************
    New Features of OCCS_VERSION_6
*******************************************************************************/
#if OCCS_VERSION >= 6
#define OCCS_READ_OSC_OK_FLAG               /* NULL, return a non-zero value as UWord16; after the crystal oscillator startup (the XOSC OK indicator). This command returns zero when the oscillator clock is still not stable or XOSC is disabled */

//#define OCCS_ADJUST_RELAX_OSC_FREQ        /* UWord16 value in range of 0 to 1023 (0x000 - 0x3FF) */
#define OCCS_CRYSTAL_OSCILLATOR_POWER_DOWN  /* OCCS_ENABLE/OCCS_DISABLE, enable/disable the power down of the external crystal oscillator. Note: To prevent a loss of clock to the core or the PLL, this bit should never be asserted while this clock source is selected by the [OCCS_CTRL_PRECS] bitfield in the control register */
#define OCCS_TEMP_TRIM_OSC_8MHZ             /* UWord16 value 0-15, set the temperature trim value */ 
#define OCCS_CLOCK_MONITOR_ENABLE           /* OCCS_ENABLE/OCCS_DISABLE, enable/disable the clock monitor functionality of the XOSC */
#endif

#if OCCS_VERSION >= 5
#if OCCS_VERSION < 7
#define OCCS_CRYSTAL_CLOCK_DIV2             /* OCCS_ENABLE/OCCS_DISABLE, enable/disable the external oscillator output divider by 2 before use as MSTR_OSC. Note: The [OCCS_CTRL_PRECS] bitfield should not be selecting the external clock source while changing the value of OSC_DIV2 to avoid glitches on the system clock */
#endif
#endif /* OCCS_VERSION >= 5 */

#if OCCS_VERSION == 6
#define OCCS_TRIM_OSC_32K                   /* NULL, set the factory frequency trim value of the 32 kHz Internal RC Oscillator */
#define OCCS_RETRIM_OSC_32K                 /* UWord16 value 0-511, adjust the 32 kHz Internal RC Oscillator frequency by the parameter value*/
#define OCCS_32KHZ_RC_OSCILATOR_OPERATION   /* OCCS_ENABLE/OCCS_DISABLE, enable/disable the power down of the 32 kHz internal RC oscillator. Note: To prevent a loss of clock to the core or the PLL, this bit should never be asserted while this clock source is selected by the PRECS field in the control register */ 
#endif

#if OCCS_VERSION == 7
#define OCCS_CLOCK_SOURCE_TOPWM_NANO_EDGE   /* OCCS_RAW_PLL/OCCS_PLL_DIV2, set the 200MHz clock source to PWM nano edge. The recommended setting is (OCCS_PLL_DIV2), when the PLL output frequency is 400 MHz, then the PLL DIV2 Clock is selected as PWM 2X clock */
#define OCCS_TRIM_OSC_200K                  /* NULL, set the factory frequency trim value of the 200 kHz Internal RC Oscillator */
#define OCCS_RETRIM_OSC_200K                /* UWord16 value 0-511, adjust the 200 kHz Internal RC Oscillator frequency by the parameter value */
#define OCCS_200KHZ_RC_OSCILATOR_OPERATION  /* OCCS_ENABLE/OCCS_DISABLE, enable/disable the power down of the 200 kHz internal RC oscillator. Note: To prevent a loss of clock to the core or the PLL, this bit should never be asserted while this clock source is selected by the PRECS field in the control register */ 
#endif

/*******************************************************************************
    New Features of OCCS_VERSION_6
*******************************************************************************/


/*****************************************************************
* Multi-Instruction ioctl() commands
*
*  Word16 ioctl( OCCS_module_identifier, Command_name, Parameter );
*
******************************************************************

        COMMAND NAME                      PARAMETERS, COMMENTS
------------------------------------------------------------------ */
#define OCCS_SET_LORTP              /* UWord16 value 1-15, set the loss-of-reference clock trip point. The parameter controls the amount of time required for the loss of reference clock interrupt to be generated. It's recommended to keep the value of LORTP >= 2 */

#define OCCS_SET_ZCLOCK_SOURCE      /* OCCS_POSTSCALER_OUTPUT/OCCS_PRESCALER_OUTPUT(83xx only) /OCCS_MSTR_OSC_OUTPUT(80xx only) /OCCS_xxx_OSC_OUTPUT (xxx=PLL/MSTR) (800x & 84xxx & 827xxx), set the sys_clk_x2 source to the SIM, which generates divided-down versions of this signal for use by memories and the IP Bus. If PLLPD is set, ZSRC is automatically set to 0 to prevent a loss of the reference clock to the core. NOTE: Before switching to a new clock source, you must enable the new source. The PLL should be on, configured, and locked before switching to it. For extra assurance in cases where the PLL may be stressed, confirm that the PLL remains locked for a period of time before switching to it */
#define OCCS_GET_ZCLOCK_SOURCE      /* NULL, return the same values as OCCS_SET_ZCLOCK_SOURCE parameters, any other value means synchronizing is in progress */

#define OCCS_READ_FLAG              /* combination of OCCS_STATUS_xxx (xxx=LOCK_LOST_INT1|LOCK_LOST_INT0|CLOCK_LOST|LOCK_1|LOCK_0|POWER_DOWN|ZCLOCK|CRYSTAL_READY(800x only) ), return zero if flag is cleared, non-zero if flag is set */

/*******************************************************************************
    Full OCCS (8xxx family) clock configuration commands
*******************************************************************************/

#if OCCS_VERSION == 1
#define OCCS_SET_CORE_CLOCK         /* OCCS_CLOCK_IN_DIVIDE_BY_x | OCCS_CLOCK_OUT_DIVIDE_BY_y | DivBy,
                                        where x and y are 1,2,4 or 8. Range of DivBy is 1 to 128
                                        After command is executed the VCO frequency and MC core frequency is
                                        Fvco = Fosc*(DivBy+1)/x  (recommended Fvco range is 80MHz to 240MHz)
                                        Fzclk = Fvco/(4*y) */

#define OCCS_SET_POSTSCALER         /* OCCS_CLOCK_OUT_DIVIDE_BY_x, where x is 1,2,4 or 8 */
#define OCCS_SET_DIVIDE_BY          /* value  1 to 128, use this command only when ZCLOCK Source is set to prescaler */
#define OCCS_SET_PRESCALER          /* OCCS_CLOCK_IN_DIVIDE_BY_x, where x is 1,2,4 or 8 
                                       use this command only when ZCLOCK Source is set to prescaler */
#endif

/*******************************************************************************
    Fixed-PLL OCCS (80xx family) clock configuration commands
*******************************************************************************/
#if OCCS_VERSION >= 2 && OCCS_VERSION <= 4

#define OCCS_SET_CORE_CLOCK         /* OCCS_CLOCK_OUT_DIVIDE_BY_x, where x are 1,2,4,8,16 or 32 (64,128,256 only 800x)
                                        After command is executed the VCO frequency and MC core frequency is
                                        Fvco = Fosc*24/3  (recommended Fvco range is 80MHz to 240MHz) 
                                        Fzclk = Fvco/(2*x)
                                        Note: as there is no prescaler nor PLL div-by, this command is 
                                              same as the OCCS_SET_POSTSCALER */
                                    
#define OCCS_SET_POSTSCALER         /* OCCS_CLOCK_OUT_DIVIDE_BY_x, where x is 1,2,4,8,16 or 32 (64,128,256 only 800x)*/
#endif

/*******************************************************************************
    variable-PLL OCCS (82xx family) clock configuration commands
*******************************************************************************/
#if OCCS_VERSION == 5
#define OCCS_SET_CORE_CLOCK         /* OCCS_CLOCK_IN_DIVIDE_BY_x | DivBy,
                                        where x is 1,2,4,8,16,32,64,128 or 256. Range of DivBy is 1 to 128
                                        After command is executed the VCO frequency and MC core frequency is
                                        Fvco = Fosc*(DivBy+1)  (recommended Fvco range is 120MHz to 240MHz)
                                        Fzclk = Fvco/(2*x) */
#endif

#if OCCS_VERSION >= 5
#define OCCS_SET_CORE_CLOCK         /* combination of (OCCS_CLOCK_IN_DIVIDE_BY_xxx (xxx= 1/2/4/8/16/32/64/128/256) | DivBy - range is 0 to 127) (for MC56F82xxx and MC56F84xxx value 1 to 64 only ), configure the OCCS module to the most frequently used mode, when the PLL block provides clock to the DSC core (ZCLOCK Source is set to Postscaler output). First the command sets the ZCLOCK Source to Prescaler output and turns the lock detector on. Then it writes the "param" value to the PLL Divide by Register (PLLDB on MC56F83xx, DIVBY on MC56F80xx/MC56F824x5x/MC56F82xxx/MC56F84xxx) and it waits until the PLL is locked. Finally it switches the ZCLOCK Source to the Postscaler output */
#define OCCS_SET_DIVIDE_BY          /* UWord16 value  0-127 (for MC56F827xx and MC56F84xxx value 0-63 only ), set the PLL Divide-by value. This command writes passed parameter to the PLL Divide-by register. Use this command only when ZCLOCK Source is set to MSTR clock */
#endif

#define OCCS_SET_POSTSCALER         /* OCCS_CLOCK_OUT_DIVIDE_BY_xxx (xxx=1/2/4/8/16/32/64/128/256), set the postscaler */


/*******************************************************************************
    Internal Relaxation Oscillator commands
*******************************************************************************/
#if OCCS_HAS_RXOSC
#define OCCS_ADJUST_RELAX_OSC_FREQ  /* UWord16 value 0-1023, adjust the internal Relaxation  Oscillator frequency by changing the size of the internal capacitor. The reset value is in middle of the range. */
#define OCCS_TRIM_RELAX_OSC_8MHZ    /* NULL, adjust the Relaxation  Oscillator frequency to 8MHz using the factory settings. This command reads the factory TRIM value from the internal flash and modifies the TRIM bits in the Oscillator Control register. The standard startup code of the application created with DSP56800_EX_Quick_Start is capable of setting the required frequency and trimming value automatically, when this is enabled in the Graphical Configuration Tool and the appconfig.h file */
#endif /* OCCS_HAS_RXOSC */

/*******************************************************************************
    New Features of OCCS_VERSION_3
*******************************************************************************/
#if OCCS_VERSION == 3
#define OCCS_SELECT_EXT_CLOCK_SOURCE      /* OCCS_CLKIN_PRI/OCCS_CLKIN_ALT/OCCS_CLKIN_OSC */
#endif

#if OCCS_VERSION >= 3
#define OCCS_WPROTECT_PLL_SETTINGS        /* OCCS_ENABLE(_PERMANENT)/OCCS_DISABLE(_PERMANENT), set the write-protection of the PLL-related configuration bits. Depending on the (PERMANENT) parameter value, the protection may be activated/deactivated permanently (until next reset) or might be changed later */
#define OCCS_WPROTECT_OSC_SETTINGS        /* OCCS_ENABLE(_PERMANENT)/OCCS_DISABLE(_PERMANENT), set the write-protection of the Oscillator -related configuration bits. Depending on the (PERMANENT) parameter value, the protection may be activated/deactivated permanently (until next reset) or might be changed later */
#define OCCS_WPROTECT_CLK_SETTINGS        /* OCCS_ENABLE(_PERMANENT)/OCCS_DISABLE(_PERMANENT), set the write-protection of the Clock-related configuration bits. Depending on the (PERMANENT) parameter value, the protection may be activated/deactivated permanently (until next reset) or might be changed later */

#define OCCS_TEST_CLOCK_CHECK             /* NULL, test if clock checking function has finished.  */
#define OCCS_READ_CLOCK_CHECK_REFERENCE   /* NULL, read and return the result of clock checking function for internal reference clock as UWord16 */
#define OCCS_READ_CLOCK_CHECK_TARGET      /* NULL, read and return the result of clock checking function for external clock as UWord16 */
#endif

/*******************************************************************************
    New Features of OCCS_VERSION_4
*******************************************************************************/
#if OCCS_VERSION >= 4
#define OCCS_SELECT_EXT_CLOCK_SOURCE      /* OCCS_CLKIN_CLKIN/OCCS_CLKIN_EXTAL, select the external clock source. There are only two clock sources to be chosen from. One is direct clock input and second is crystal/resonator input. The second input can be configured as a standard EXTAL/XTAL input or as a direct clock input on the XTAL pin. The external clock source selected by OCCS_SELECT_EXT_CLOCK_SOURCE  may then become an official MSTR_OSC clock  by using the OCCS_SET_PRESCALER_CLOCK command */
#endif


/*****************************************************************
* Software Layer ioctl() commands
*
*  Word16 ioctl( OCCS_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define OCCS_INIT                   /* NULL, initialize the OCCS periheral registers using the appcongig.h _INIT values */

#define OCCS_GET_IPBUS_FREQ         /* UWord32 oscillator frequency [Hz], return the IPBus Clock frequency value in Hz as UWord32 */


/*******************************************************************************
    Compatibility registers names with previous versions
*******************************************************************************/

//New name for PLL Control Register
#if (!defined(OCCS_PLLCR_INIT) && defined(OCCS_CTRL_INIT))
#define OCCS_PLLCR_INIT OCCS_CTRL_INIT
#endif

//New name for Divide by register
#if (!defined(OCCS_PLLDB_INIT) && defined(OCCS_DIVBY_INIT))
#define OCCS_PLLDB_INIT OCCS_DIVBY_INIT
#endif

//New name for OCCS Status Register
#if (!defined(OCCS_PLLSR_INIT) && defined(OCCS_STAT_INIT))
#define OCCS_PLLSR_INIT OCCS_STAT_INIT
#endif


/*******************************************************************************
    command parameters
*******************************************************************************/

#define OCCS_DISABLE                    0
#define OCCS_ENABLE                     1

/* for permanent enable/disable */
#define OCCS_DISABLE_PERMANENT          2
#define OCCS_ENABLE_PERMANENT           3

#if OCCS_VERSION >= 2
#define OCCS_STANDBY                    -1
#endif

#if OCCS_HAS_RXOSC
#define OCCS_INTERNAL_RELAX_OSC         0
#define OCCS_CRYSTAL_OSC                1
#endif

#define OCCS_LOW_POWER                  1
#define OCCS_HIGH_POWER                 0

#define OCCS_POSTSCALER_OUTPUT          OCCS_PLLCR_ZSRC_POSTSCALER
#define OCCS_PRESCALER_OUTPUT           OCCS_PLLCR_ZSRC_PRESCALER

#if OCCS_VERSION >= 2 && OCCS_VERSION < 6
    /* alternate name for prescaler clock */
    #define OCCS_MSTR_OSC_OUTPUT        OCCS_PLLCR_ZSRC_PRESCALER
#else 
    #define OCCS_MSTR_OSC_OUTPUT        0x01
#endif

#if OCCS_VERSION >= 3 && OCCS_VERSION < 6
    /* alternate name for prescaler clock */
    #define OCCS_PLL_OSC_OUTPUT         OCCS_PLLCR_ZSRC_POSTSCALER
#else 
    #define OCCS_PLL_OSC_OUTPUT         0x00
#endif

#define OCCS_LOL1_INT                   OCCS_PLLCR_PLLIE1_MASK
#define OCCS_LOL0_INT                   OCCS_PLLCR_PLLIE0_MASK
#define OCCS_LOL1_INT_ANY_EDGE          OCCS_PLLCR_PLLIE1_ANYEDGE
#define OCCS_LOL1_INT_FALLING_EDGE      OCCS_PLLCR_PLLIE1_FALLINGEDGE
#define OCCS_LOL1_INT_RISING_EDGE       OCCS_PLLCR_PLLIE1_RISINGEDGE
#define OCCS_LOL0_INT_ANY_EDGE          OCCS_PLLCR_PLLIE0_ANYEDGE
#define OCCS_LOL0_INT_FALLING_EDGE      OCCS_PLLCR_PLLIE0_FALLINGEDGE
#define OCCS_LOL0_INT_RISING_EDGE       OCCS_PLLCR_PLLIE0_RISINGEDGE

#define OCCS_INT1                       OCCS_PLLCR_PLLIE1_MASK
#define OCCS_INT0                       OCCS_PLLCR_PLLIE0_MASK
#define OCCS_INT1_ANY_EDGE              OCCS_PLLCR_PLLIE1_ANYEDGE
#define OCCS_INT1_FALLING_EDGE          OCCS_PLLCR_PLLIE1_FALLINGEDGE
#define OCCS_INT1_RISING_EDGE           OCCS_PLLCR_PLLIE1_RISINGEDGE
#define OCCS_INT0_ANY_EDGE              OCCS_PLLCR_PLLIE0_ANYEDGE
#define OCCS_INT0_FALLING_EDGE          OCCS_PLLCR_PLLIE0_FALLINGEDGE
#define OCCS_INT0_RISING_EDGE           OCCS_PLLCR_PLLIE0_RISINGEDGE
#define OCCS_LOSS_OF_CLOCK_INT          OCCS_PLLCR_LOCIE

#define OCCS_CLOCK_OUT_DIVIDE_BY_1      OCCS_PLLDB_PLLCOD_1
#define OCCS_CLOCK_OUT_DIVIDE_BY_2      OCCS_PLLDB_PLLCOD_2
#define OCCS_CLOCK_OUT_DIVIDE_BY_4      OCCS_PLLDB_PLLCOD_4
#define OCCS_CLOCK_OUT_DIVIDE_BY_8      OCCS_PLLDB_PLLCOD_8

#if OCCS_VERSION == 1
    #define OCCS_CLOCK_IN_DIVIDE_BY_1   OCCS_PLLDB_PLLCID_1
    #define OCCS_CLOCK_IN_DIVIDE_BY_2   OCCS_PLLDB_PLLCID_2
    #define OCCS_CLOCK_IN_DIVIDE_BY_4   OCCS_PLLDB_PLLCID_4
    #define OCCS_CLOCK_IN_DIVIDE_BY_8   OCCS_PLLDB_PLLCID_8
    
#else /* OCCS_VERSION >= 2 */
    #define OCCS_CLOCK_OUT_DIVIDE_BY_16 OCCS_PLLDB_PLLCOD_16
    #define OCCS_CLOCK_OUT_DIVIDE_BY_32 OCCS_PLLDB_PLLCOD_32
    
#endif

#if OCCS_VERSION >= 4
    #define OCCS_CLOCK_OUT_DIVIDE_BY_64  OCCS_PLLDB_PLLCOD_64
    #define OCCS_CLOCK_OUT_DIVIDE_BY_128 OCCS_PLLDB_PLLCOD_128
    #define OCCS_CLOCK_OUT_DIVIDE_BY_256 OCCS_PLLDB_PLLCOD_256
#endif
    
#define OCCS_STATUS_LOCK_LOST_INT1      OCCS_PLLSR_LOLI1
#define OCCS_STATUS_LOCK_LOST_INT0      OCCS_PLLSR_LOLI0
#define OCCS_STATUS_CLOCK_LOST          OCCS_PLLSR_LOCI
#define OCCS_STATUS_LOCK_1              OCCS_PLLSR_LCK1
#define OCCS_STATUS_LOCK_0              OCCS_PLLSR_LCK0
#define OCCS_STATUS_POWER_DOWN          OCCS_PLLSR_PLLPD
#define OCCS_STATUS_ZCLOCK_PRESCALER    OCCS_PLLSR_ZSRC_PRESCALER
#define OCCS_STATUS_ZCLOCK_POSTSCALER   OCCS_PLLSR_ZSRC_POSTSCALER
#define OCCS_STATUS_ZCLOCK              OCCS_PLLSR_ZSRC_MASK

#if OCCS_VERSION == 3
#define OCCS_CLKIN_PRI                  OCCS_OSCTL_EXT_SEL_PRI
#define OCCS_CLKIN_ALT                  OCCS_OSCTL_EXT_SEL_ALT
#define OCCS_CLKIN_OSC                  OCCS_OSCTL_EXT_SEL_OSC
#endif

#if OCCS_VERSION == 4
#define OCCS_32KHZ_CRYSTAL              1
#define OCCS_1MHZ_TO_16MHZ_CRYSTAL      0
#define OCCS_STATUS_CRYSTAL_READY       OCCS_PLLSR_COSC_RDY
#endif
#if OCCS_VERSION >= 4
#define OCCS_CLKIN_CLKIN                OCCS_OSCTL_EXT_SEL_CLKIN
#define OCCS_CLKIN_EXTAL                OCCS_OSCTL_EXT_SEL_EXTAL
#endif

/*******************************************************************************
    register bit names and masks
*******************************************************************************/

/* OCCS_PLLCR register bits */
#define OCCS_PLLCR_PLLIE1_MASK          0xC000
#define OCCS_PLLCR_PLLIE1_ANYEDGE       0xC000
#define OCCS_PLLCR_PLLIE1_FALLINGEDGE   0x8000
#define OCCS_PLLCR_PLLIE1_RISINGEDGE    0x4000
#define OCCS_PLLCR_PLLIE1_DISABLED      0x0000
#define OCCS_PLLCR_PLLIE0_MASK          0x3000
#define OCCS_PLLCR_PLLIE0_ANYEDGE       0x3000
#define OCCS_PLLCR_PLLIE0_FALLINGEDGE   0x2000
#define OCCS_PLLCR_PLLIE0_RISINGEDGE    0x1000
#define OCCS_PLLCR_PLLIE0_DISABLED      0x0000
#define OCCS_PLLCR_LOCIE                0x0800
#define OCCS_PLLCR_LCKON                0x0080
#define OCCS_PLLCR_PLLPD                0x0010
#define OCCS_PLLCR_ZSRC_MASK            0x0003
#define OCCS_PLLCR_ZSRC_POSTSCALER      0x0002
#define OCCS_PLLCR_ZSRC_PRESCALER       0x0001

#if OCCS_VERSION <= 2
#define OCCS_PLLCR_CHPMPTRI             0x0040
#endif

/* OCCS_PLLCR register bits on devices with Relaxation Oscillator */
#if OCCS_HAS_RXOSC
    #define OCCS_PLLCR_PRECS            0x0004
#if OCCS_VERSION >= 5
    #define OCCS_PLLCR_PRECS_MASK       0x000C
#else
    #define OCCS_PLLCR_PRECS_MASK       0x0004
#endif
#if OCCS_VERSION >= 6
    #define OCCS_PLLCR_PRECS_RCOSC      0x0008
#else
    #define OCCS_PLLCR_PRECS_RCOSC      0x0000
#endif

#endif

/* OCCS_PLLDB register bits */
#define OCCS_PLLDB_LORTP_MASK           0xf000

#if OCCS_VERSION == 1
    #define OCCS_PLLDB_PLLCOD_MASK      0x0c00
    #define OCCS_PLLDB_PLLCOD_8         0x0c00
    #define OCCS_PLLDB_PLLCOD_4         0x0800
    #define OCCS_PLLDB_PLLCOD_2         0x0400
    #define OCCS_PLLDB_PLLCOD_1         0x0000
    #define OCCS_PLLDB_PLLCID_MASK      0x0300
    #define OCCS_PLLDB_PLLCID_8         0x0300
    #define OCCS_PLLDB_PLLCID_4         0x0200
    #define OCCS_PLLDB_PLLCID_2         0x0100
    #define OCCS_PLLDB_PLLCID_1         0x0000

/* OCCS_PLLDB register bits on fixed PLL devices (e.g. 80xx)  */
#else   /*OCCS_VERSION >= 2*/
    #define OCCS_PLLDB_PLLCOD_32        0x0500
    #define OCCS_PLLDB_PLLCOD_16        0x0400
    #define OCCS_PLLDB_PLLCOD_8         0x0300
    #define OCCS_PLLDB_PLLCOD_4         0x0200
    #define OCCS_PLLDB_PLLCOD_2         0x0100
    #define OCCS_PLLDB_PLLCOD_1         0x0000
#endif


#if OCCS_VERSION == 2 || OCCS_VERSION == 3
    #define OCCS_PLLDB_PLLCOD_MASK      0x0700
    #define OCCS_PLLDB_PLLCOD_32c       0x0700
    #define OCCS_PLLDB_PLLCOD_32b       0x0600
#endif


#if OCCS_VERSION >= 4
    #define OCCS_PLLDB_PLLCOD_MASK      0x0f00
    #define OCCS_PLLDB_PLLCOD_256h      0x0f00
    #define OCCS_PLLDB_PLLCOD_256g      0x0e00
    #define OCCS_PLLDB_PLLCOD_256f      0x0d00
    #define OCCS_PLLDB_PLLCOD_256e      0x0c00
    #define OCCS_PLLDB_PLLCOD_256d      0x0b00
    #define OCCS_PLLDB_PLLCOD_256c      0x0a00
    #define OCCS_PLLDB_PLLCOD_256b      0x0900
    #define OCCS_PLLDB_PLLCOD_256       0x0800
    #define OCCS_PLLDB_PLLCOD_128       0x0700
    #define OCCS_PLLDB_PLLCOD_64        0x0600
#endif

#if OCCS_VERSION == 1 || OCCS_VERSION == 5
    #define OCCS_PLLDB_PLLDB_MASK       0x007f
#endif

#if OCCS_VERSION >= 6
    #define OCCS_PLLDB_PLLDB_MASK           0x003f
    #define OCCS_STAT_OSC_OK_MASK           0x0080
    #define OCCS_OSCTL2_TEMP_TRIM8M_MASK    0x3C00
    #define OCCS_OSCTL2_MON_ENABLE          0x0200
#endif

/* OCCS_PLLSR register bits */
#define OCCS_PLLSR_LOLI1                0x8000
#define OCCS_PLLSR_LOLI0                0x4000
#define OCCS_PLLSR_LOCI                 0x2000
#define OCCS_PLLSR_LCK1                 0x0040
#define OCCS_PLLSR_LCK0                 0x0020
#define OCCS_PLLSR_PLLPD                0x0010
#define OCCS_PLLSR_ZSRC_MASK            0x0003
#define OCCS_PLLSR_ZSRC_SYNCA           0x0003
#define OCCS_PLLSR_ZSRC_POSTSCALER      0x0002
#define OCCS_PLLSR_ZSRC_PRESCALER       0x0001
#define OCCS_PLLSR_ZSRC_SYNCB           0x0000

#if OCCS_VERSION == 4
#define OCCS_PLLSR_COSC_RDY             0x0004
#endif

/* Oscillator Control Register */
#define OCCS_OSCTL_COHL                 0x2000

/* Oscillator Control Register on devices with Relaxation Oscillator */
#if OCCS_HAS_RXOSC
    #define OCCS_OSCTL_ROPD             0x8000
    #define OCCS_OSCTL_CLKMODE          0x1000
    #define OCCS_OSCTL_TRIM_MASK        0x03FF

    #if OCCS_VERSION >= 2
        #define OCCS_OSCTL_ROSB         0x4000
    #endif

	#if OCCS_VERSION == 6
	#define OCCS_FREQ_TRIM32K_MASK      0x01ff
	#define OCCS_OSCTL_ROPD32K          0x8000
	#endif

	#if OCCS_VERSION == 7
	#define OCCS_FREQ_TRIM200K_MASK     0x01ff
	#define OCCS_OSCTL_ROPD200K         0x8000
	#endif
#endif

#if OCCS_VERSION == 3
    #define OCCS_OSCTL_EXT_SEL_MASK     0x0c00
    #define OCCS_OSCTL_EXT_SEL_PRI      0x0000
    #define OCCS_OSCTL_EXT_SEL_ALT      0x0400
    #define OCCS_OSCTL_EXT_SEL_OSC      0x0800
#endif

#if OCCS_VERSION == 4
    #define OCCS_OSCTL_RANGE            0x0800
#endif

#if OCCS_VERSION >= 5
#if OCCS_VERSION < 7
    #define OCCS_OSCTL_OSC_DIV2         0x0800
#endif
#endif

#if OCCS_VERSION >= 6
#define OCCS_OSCTL2_COPD                0x4000
#endif

#if OCCS_VERSION == 7
#define OCCS_PLL_DIV2                   0x0040
#define OCCS_RAW_PLL 					0x0000
#endif

#if OCCS_VERSION >= 4
    #define OCCS_OSCTL_EXT_SEL_CLKIN    0x0400
    #define OCCS_OSCTL_EXT_SEL_EXTAL    0x0000
#endif

/* External Clock Check Register */

#if OCCS_VERSION == 3
    #define OCCS_CLKCHK_REF_CNT         0x7f00
    #define OCCS_CLKCHK_CHK_EN          0x8000
    #define OCCS_CLKCHK_TARGET_CNT      0x00ff
#endif

#if OCCS_VERSION == 4
    #define OCCS_CLKCHR_REF_CNT         0x7fff
    #define OCCS_CLKCHR_CHK_EN          0x8000
    #define OCCS_CLKCHT_TARGET_CNT      0x00ff
#endif

#if OCCS_VERSION >= 5
    #define OCCS_CLKCHR_REF_CNT         0x007f
    #define OCCS_CLKCHR_CHK_EN          0x8000
#endif

#if OCCS_VERSION == 5
#define OCCS_CLKCHT_TARGET_CNT      0x01ff
#endif

#if OCCS_VERSION >= 6
#define OCCS_CLKCHT_TARGET_CNT      0x07ff
#endif

/* Protection Register */
#if OCCS_VERSION >= 3
    #define OCCS_PROT_FRQEP_MASK        0x0030
    #define OCCS_PROT_FRQEP_PROT        0x0010
    #define OCCS_PROT_FRQEP_LOCK        0x0020
    #define OCCS_PROT_OSCEP_MASK        0x000c
    #define OCCS_PROT_OSCEP_PROT        0x0004
    #define OCCS_PROT_OSCEP_LOCK        0x0008
    #define OCCS_PROT_PLLEP_MASK        0x0003
    #define OCCS_PROT_PLLEP_PROT        0x0001
    #define OCCS_PROT_PLLEP_LOCK        0x0002
#endif

/*******************************************************************************
    Calculate core clock frequency (if EXTCLK is available or if using RX_OSC)
*******************************************************************************/
#if (OCCS_VERSION >= 6)
#if (!defined(OCCS_OSCTL_INIT) && defined(OCCS_OSCTL1_INIT))
#define OCCS_OSCTL_INIT OCCS_OSCTL1_INIT
#endif
#endif

#if (OCCS_VERSION >= 5)
#if (!defined(OCCS_PLLCR_INIT) && defined(OCCS_CTRL_INIT))
#define OCCS_PLLCR_INIT OCCS_CTRL_INIT
#endif

//New name for Divide by register
#if (!defined(OCCS_PLLDB_INIT) && defined(OCCS_DIVBY_INIT))
#define OCCS_PLLDB_INIT OCCS_DIVBY_INIT
#endif
#endif

/* first decide master clock (MSTR_OSC) */
#ifndef OCCS_MSTROSC_FREQ
    #if OCCS_HAS_RXOSC
        #if !((defined(OCCS_PLLCR_INIT) && (OCCS_PLLCR_INIT&OCCS_PLLCR_PRECS_MASK)))
            #if OCCS_USE_FACTORY_TRIM && defined(OCCS_RXOSC_RETRIM_CLK)
            #define OCCS_MSTROSC_FREQ (OCCS_RXOSC_RETRIM_CLK)  /* Re-trimmed RX OSC used */
            #elif (OCCS_VERSION >= 5) && defined(OCCS_OSCTL_INIT) && (OCCS_OSCTL_INIT&OCCS_OSCTL_ROSB)
            #define OCCS_MSTROSC_FREQ 400000L  /* Standby RX OSC used */
            #else
            #define OCCS_MSTROSC_FREQ 8000000L  /* Nominal RX OSC used */
            #endif
        #elif (defined(EXTCLK) && (OCCS_VERSION <= 3))
            #define OCCS_MSTROSC_FREQ (EXTCLK)  /* External clock used */
        #elif (OCCS_VERSION >= 4)
            #if (defined(OCCS_OSCTL_INIT) && (!((OCCS_OSCTL_INIT) & (OCCS_OSCTL_EXT_SEL_CLKIN))))
                #if defined(EXTAL) 
                    #if (OCCS_VERSION == 4) || (OCCS_VERSION == 7) 
                        #define OCCS_MSTROSC_FREQ (EXTAL)  /* Crystal clock used */
                    #elif !((OCCS_OSCTL_INIT) & (OCCS_OSCTL_OSC_DIV2))
                        #define OCCS_MSTROSC_FREQ (EXTAL)  /* Crystal clock used */
                    #else
                        #define OCCS_MSTROSC_FREQ ((EXTAL)/2)  /* Crystal clock divided 2 used */
                    #endif
                #endif 
             #elif (OCCS_VERSION >= 6) && defined(OCCS_PLLCR_INIT) && (OCCS_PLLCR_INIT&OCCS_PLLCR_PRECS_RCOSC)
                 #if (OCCS_VERSION == 7)
                     #define OCCS_MSTROSC_FREQ 200000L  /* 200kHz RX OSC used */
                 #else
                     #define OCCS_MSTROSC_FREQ 32000L  /* 32kHz RX OSC used */
                 #endif
             #elif defined(EXTCLK)
                #define OCCS_MSTROSC_FREQ (EXTCLK)  /* External clock used */
            #endif
        #endif
    #else
        #if (defined(EXTCLK) && (OCCS_VERSION <= 3))
            #define OCCS_MSTROSC_FREQ (EXTCLK)  /* External clock used */
        #elif (OCCS_VERSION >= 4)
            #if (defined(OCCS_OSCTL_INIT) && !(OCCS_OSCTL_INIT&OCCS_OSCTL_EXT_SEL_CLKIN))
                #if defined(EXTAL) 
                    #if OCCS_VERSION == 4 || OCCS_VERSION == 7
                        #define OCCS_MSTROSC_FREQ (EXTAL)  /* Crystal clock used */					
                    #elif !((OCCS_OSCTL_INIT) & (OCCS_OSCTL_OSC_DIV2))
                        #define OCCS_MSTROSC_FREQ (EXTAL)  /* Crystal clock used */
                    #else
                        #define OCCS_MSTROSC_FREQ ((EXTAL)/2)  /* Crystal clock divided 2 used */
                    #endif
                #endif 
            #elif (OCCS_VERSION >= 6) && defined(OCCS_PLLCR_INIT) && (OCCS_PLLCR_INIT&OCCS_PLLCR_PRECS_RCOSC)
                #if (OCCS_VERSION == 7)
                    #define OCCS_MSTROSC_FREQ 200000L  /* 200kHz RX OSC used */
                #else
                    #define OCCS_MSTROSC_FREQ 32000L  /* 32kHz RX OSC used */
                #endif
            #elif defined(EXTCLK)
                #define OCCS_MSTROSC_FREQ (EXTCLK)  /* External clock used */
            #endif
        #endif
    #endif
#endif /* OCCS_MSTROSC_FREQ */

#if !defined(OCCS_CORE_FREQ) && defined(OCCS_MSTROSC_FREQ)

    /* Standard OCCS clock calculation */
    #if OCCS_VERSION == 1

        /* when PLLDB register INIT value is not defined, we will use its reset value */
        #ifdef OCCS_PLLDB_INIT
        #define __OCCS_PLLDB_INIT OCCS_PLLDB_INIT
        #else
        #define __OCCS_PLLDB_INIT 0x201d    /* PLLDB reset value on OCCS_VERSION_1  */
        #endif

        /* PLL active */
        #if defined(OCCS_PLLCR_INIT) && ((OCCS_PLLCR_INIT & 3) == 2)
            #define OCCS_CORE_FREQ (((OCCS_MSTROSC_FREQ)*(((__OCCS_PLLDB_INIT) & 0x7f)+1)) \
                / (1<<(((__OCCS_PLLDB_INIT)>>8)&0x3))  /* prescaler  */ \
                / (1<<(((__OCCS_PLLDB_INIT)>>10)&0x3)) /* postscaler */ \
                / 4)
                
        /* PLL not active */
        #else
        
            #define OCCS_CORE_FREQ ((OCCS_MSTROSC_FREQ) \
                / (1<<(((__OCCS_PLLDB_INIT)>>8)&0x3)) /* prescaler */   \
                / 2)
                
        #endif

	#endif
    /* Fixed PLL settings (e.g. 80xx devices) */
    #if  (OCCS_VERSION >= 2) && (OCCS_VERSION <= 3)

        /* when PLLDB register INIT value is not defined, we will use its reset value */
        #ifdef OCCS_PLLDB_INIT
        #define __OCCS_PLLDB_INIT OCCS_PLLDB_INIT
        #else
        #define __OCCS_PLLDB_INIT 0x0000    /* PLLDB reset value on OCCS_VERSION_2+ */
        #endif

        /* PLL active */
        #if defined(OCCS_PLLCR_INIT) && ((OCCS_PLLCR_INIT & 3) == 2)
        
            /* postscaler */
            #if (1<<(((__OCCS_PLLDB_INIT)>>8)&0x7)) <= 32
            #define __OCCS_POSTSCALER (1<<(((__OCCS_PLLDB_INIT)>>8)&0x7))
            #else
            #define __OCCS_POSTSCALER 32
            #endif
            
            #define OCCS_CORE_FREQ (((OCCS_MSTROSC_FREQ)*24) / __OCCS_POSTSCALER / 6)
                
        /* PLL not active */
        #else
        
            #define OCCS_CORE_FREQ ((OCCS_MSTROSC_FREQ) / 2)
                
        #endif
    
    #endif

    #if  OCCS_VERSION == 4

        /* when PLLDB register INIT value is not defined, we will use its reset value */
        #ifdef OCCS_PLLDB_INIT
        #define __OCCS_PLLDB_INIT OCCS_PLLDB_INIT
        #else
        #define __OCCS_PLLDB_INIT 0x2000    /* PLLDB reset value on OCCS_VERSION_4 */
        #endif

        /* postscaler */
        #if (1<<(((__OCCS_PLLDB_INIT)>>8)&0xf)) <= 256
        #define __OCCS_POSTSCALER (1<<(((__OCCS_PLLDB_INIT)>>8)&0xf))
        #else
        #define __OCCS_POSTSCALER 256
        #endif

        /* PLL active */
        #if defined(OCCS_PLLCR_INIT) && ((OCCS_PLLCR_INIT & 3) == 2)
        
            #define OCCS_CORE_FREQ (((OCCS_MSTROSC_FREQ)*24) / __OCCS_POSTSCALER / 6)
                
        /* PLL not active */
        #else
        
            #define OCCS_CORE_FREQ ((OCCS_MSTROSC_FREQ / __OCCS_POSTSCALER) / 2)
                
        #endif
    
    #endif

    #if  OCCS_VERSION == 5

        /* when PLLDB register INIT value is not defined, we will use its reset value */
        #ifdef OCCS_PLLDB_INIT
        #define __OCCS_PLLDB_INIT OCCS_PLLDB_INIT
        #else
        #define __OCCS_PLLDB_INIT 0x201D    /* PLLDB reset value on OCCS_VERSION_4 */
        #endif

        /* postscaler */
        #if (1<<(((__OCCS_PLLDB_INIT)>>8)&0xf)) <= 256
        #define __OCCS_POSTSCALER (1<<(((__OCCS_PLLDB_INIT)>>8)&0xf))
        #else
        #define __OCCS_POSTSCALER 256
        #endif

        /* PLL active */
        #if defined(OCCS_PLLCR_INIT) && ((OCCS_PLLCR_INIT & 3) == 2)

            /* PLL Divide By */
            #define __OCCS_DIVIDE_BY (__OCCS_PLLDB_INIT&0x7f)
            #define OCCS_CORE_FREQ (((OCCS_MSTROSC_FREQ)*(__OCCS_DIVIDE_BY+1)) / __OCCS_POSTSCALER / 4)
                
        /* PLL not active */
        #else
            #define OCCS_CORE_FREQ ((OCCS_MSTROSC_FREQ / __OCCS_POSTSCALER) / 2)
                
        #endif
    
    #endif

#if  OCCS_VERSION >= 6

    /* when PLLDB register INIT value is not defined, we will use its reset value */
    #ifdef OCCS_PLLDB_INIT
    #define __OCCS_PLLDB_INIT OCCS_PLLDB_INIT
    #else
    #define __OCCS_PLLDB_INIT 0x201D    /* PLLDB reset value on OCCS_VERSION_4 */
    #endif

    /* postscaler */
    #if (1<<(((__OCCS_PLLDB_INIT)>>8)&0xf)) <= 256
    #define __OCCS_POSTSCALER (1<<(((__OCCS_PLLDB_INIT)>>8)&0xf))
    #else
    #define __OCCS_POSTSCALER 256
    #endif

    /* PLL active */
    #if defined(OCCS_PLLCR_INIT) && ((OCCS_PLLCR_INIT & 1) == 1)    // changed from ...  ((OCCS_PLLCR_INIT & 3) == 2)

        /* PLL Divide By */
        #define __OCCS_DIVIDE_BY (__OCCS_PLLDB_INIT&0x3f)  // changed from ... (__OCCS_PLLDB_INIT&0x7f)
        #define OCCS_CORE_FREQ (((OCCS_MSTROSC_FREQ)*(__OCCS_DIVIDE_BY+1)) / __OCCS_POSTSCALER / 4)
            
    /* PLL not active */
    #else
        #define OCCS_CORE_FREQ ((OCCS_MSTROSC_FREQ / __OCCS_POSTSCALER) / 2)
            
    #endif
#endif

#endif /* !OCCS_CORE_FREQ && OCCS_MSTROSC_FREQ */

/*******************************************************************************
    Function Prototypes
*******************************************************************************/

/* module initialization */
void occsInit(void);

/* Function parameters: OscFreq - oscillator frequency [Hz]
   Function returns IP Bus frequency [Hz]. */
UWord32 occsGetIPBusFreq(UWord32 oscFreq); 

/* Function parameters: OscFreq - oscillator frequency [Hz]
   Function returns Core Bus frequency [Hz]. */
#define occsGetCoreFreq occsGetIPBusFreq

/*******************************************************************************
    Implementations of OCCS ioctl() commands
*******************************************************************************/
#define ioctlOCCS_INIT(pOccsBase, param)        occsInit()

#if OCCS_VERSION == 1
#define ioctlOCCS_SET_CORE_CLOCK(pOccsBase, param) \
    { \
        periphMemWrite(OCCS_PLLCR_LCKON | OCCS_PLLCR_ZSRC_PRESCALER, &((pOccsBase)->pllcr)); \
        periphBitGrpSet(OCCS_PLLDB_PLLCOD_MASK | OCCS_PLLDB_PLLCID_MASK | OCCS_PLLDB_PLLDB_MASK, \
            ((param) & (OCCS_PLLDB_PLLCOD_MASK | OCCS_PLLDB_PLLCID_MASK)) | \
            (((param)-1) & OCCS_PLLDB_PLLDB_MASK), &((pOccsBase)->plldb)); \
        while (!periphBitTest(OCCS_PLLSR_LCK1, &((pOccsBase)->pllsr))) \
            ; \
        periphMemWrite(OCCS_PLLCR_LCKON | OCCS_PLLCR_ZSRC_POSTSCALER, &((pOccsBase)->pllcr)); \
    }

#elif OCCS_VERSION >= 2 && OCCS_VERSION <= 4 
#define ioctlOCCS_SET_CORE_CLOCK(pOccsBase, param) \
    { \
        periphMemWrite(OCCS_PLLCR_LCKON | OCCS_PLLCR_ZSRC_PRESCALER, &((pOccsBase)->pllcr)); \
        periphBitGrpSet(OCCS_PLLDB_PLLCOD_MASK, param, &((pOccsBase)->plldb)); \
        while (!periphBitTest(OCCS_PLLSR_LCK1, &((pOccsBase)->pllsr))) \
            ; \
        periphMemWrite(OCCS_PLLCR_LCKON | OCCS_PLLCR_ZSRC_POSTSCALER, &((pOccsBase)->pllcr)); \
    }

#else /* OCCS_VERSION >= 5 */
#define ioctlOCCS_SET_CORE_CLOCK(pOccsBase, param) \
    { \
        periphMemWrite(OCCS_PLLCR_LCKON | OCCS_PLLCR_ZSRC_PRESCALER, &((pOccsBase)->pllcr)); \
        periphBitGrpSet(OCCS_PLLDB_PLLCOD_MASK | OCCS_PLLDB_PLLDB_MASK, \
            ((param) & (OCCS_PLLDB_PLLCOD_MASK )) | \
            (((param)-1) & OCCS_PLLDB_PLLDB_MASK), &((pOccsBase)->plldb)); \
        while (!periphBitTest(OCCS_PLLSR_LCK1, &((pOccsBase)->pllsr))) \
            ; \
        periphMemWrite(OCCS_PLLCR_LCKON | OCCS_PLLCR_ZSRC_POSTSCALER, &((pOccsBase)->pllcr)); \
    }

#endif

#define ioctlOCCS_SET_POSTSCALER(pOccsBase, param) \
    periphBitGrpSR(OCCS_PLLDB_PLLCOD_MASK, param, &((pOccsBase)->plldb))

#ifdef OCCS_SET_PRESCALER
#define ioctlOCCS_SET_PRESCALER(pOccsBase, param) \
    periphBitGrpSR(OCCS_PLLDB_PLLCID_MASK, param, &((pOccsBase)->plldb))
#endif

#ifdef OCCS_SET_DIVIDE_BY
#define ioctlOCCS_SET_DIVIDE_BY(pOccsBase, param) \
    periphBitGrpSR(OCCS_PLLDB_PLLDB_MASK, (param) - 1, &((pOccsBase)->plldb))
#endif

#define ioctlOCCS_SET_LORTP(pOccsBase, param) \
    periphBitGrpSR(OCCS_PLLDB_LORTP_MASK, (param) << 12, &((pOccsBase)->plldb))

#ifdef OCCS_TURN_OFF_CHARGE_PUMP
#define ioctlOCCS_TURN_OFF_CHARGE_PUMP(pOccsBase, param) \
    periphBitSet(OCCS_PLLCR_CHPMPTRI, &((pOccsBase)->pllcr))
#endif

#define ioctlOCCS_INT_ENABLE(pOccsBase, param) \
    periphBitSet(param, &((pOccsBase)->pllcr))

#define ioctlOCCS_ENABLE_INT(pOccsBase, param) \
    periphBitSet(param, &((pOccsBase)->pllcr))

#define ioctlOCCS_SET_ZCLOCK_SOURCE(pOccsBase, param) \
    periphBitGrpSet(OCCS_PLLCR_ZSRC_MASK, param, &((pOccsBase)->pllcr))

#define ioctlOCCS_GET_ZCLOCK_SOURCE(pOccsBase, param) \
    periphBitTest(OCCS_PLLSR_ZSRC_SYNCA, &((pOccsBase)->pllsr))

#define ioctlOCCS_INT_DISABLE(pOccsBase, param) \
    periphBitClear(param, &((pOccsBase)->pllcr))

#define ioctlOCCS_DISABLE_INT(pOccsBase, param) \
    periphBitClear(param, &((pOccsBase)->pllcr))

#define ioctlOCCS_READ_FLAG(pOccsBase, param) \
    periphBitTest(param, &((pOccsBase)->pllsr))

#define ioctlOCCS_CLEAR_FLAG(pOccsBase, param) \
    periphSafeAckByOne(OCCS_PLLSR_LOLI1 | OCCS_PLLSR_LOLI0 | OCCS_PLLSR_LOCI, param, &((pOccsBase)->pllsr))

#define ioctlOCCS_LOCK_DETECTOR(pOccsBase, param) \
    if (param) periphBitSet(OCCS_PLLCR_LCKON, &((pOccsBase)->pllcr)); \
    else periphBitClear(OCCS_PLLCR_LCKON, &((pOccsBase)->pllcr))

#ifdef OCCS_POWER_MODE
#define ioctlOCCS_POWER_MODE(pOccsBase, param) \
    if (param) periphBitSet(OCCS_OSCTL_COHL, &((pOccsBase)->osctl)); \
    else periphBitClear(OCCS_OSCTL_COHL, &((pOccsBase)->osctl))
#endif

#ifdef OCCS_DIRECT_CLOCK_MODE
#define ioctlOCCS_DIRECT_CLOCK_MODE(pOccsBase, param) \
    if (param) periphBitSet(OCCS_OSCTL_CLKMODE, &((pOccsBase)->osctl)); \
    else periphBitClear(OCCS_OSCTL_CLKMODE, &((pOccsBase)->osctl))
#endif

#define ioctlOCCS_GET_IPBUS_FREQ(pOccsBase, param) occsGetIPBusFreq(param)

#ifdef OCCS_SELECT_FREQ_RANGE
#define ioctlOCCS_SELECT_FREQ_RANGE(pOccsBase, param) \
    if (param) periphBitSet(OCCS_OSCTL_RANGE, &((pOccsBase)->osctl)); \
    else periphBitClear(OCCS_OSCTL_RANGE, &((pOccsBase)->osctl))
#endif

/* Reading(writing) from(to) registers */
#define ioctlOCCS_WRITE_CONTROL_REG(pOccsBase, param) \
    periphMemWrite(param, &((pOccsBase)->pllcr))

#define ioctlOCCS_WRITE_DIVIDE_BY_REG(pOccsBase, param) \
    periphMemWrite(param, &((pOccsBase)->plldb))

#define ioctlOCCS_WRITE_OSC_CONTROL_REG(pOccsBase, param) \
    periphMemWrite(param, &((pOccsBase)->osctl))

#ifdef OCCS_SHUTDOWN
#define ioctlOCCS_SHUTDOWN(pOccsBase, param) { \
    periphMemWrite(0xDEAD, &((pOccsBase)->shutdown)); \
    while (1) ; }
#endif

#define ioctlOCCS_READ_CONTROL_REG(pOccsBase, param) \
    periphMemRead(&((pOccsBase)->pllcr))

#define ioctlOCCS_READ_DIVIDE_BY_REG(pOccsBase, param) \
    periphMemRead(&((pOccsBase)->plldb))

#define ioctlOCCS_READ_STATUS_REG(pOccsBase, param) \
    periphMemRead(&((pOccsBase)->pllsr))

#define ioctlOCCS_READ_OSC_CONTROL_REG(pOccsBase, param) \
    periphMemRead(&((pOccsBase)->osctl))

#if OCCS_VERSION >= 3
#define ioctlOCCS_WPROTECT_PLL_SETTINGS(pOccsBase, param) \
    periphBitGrpSet(OCCS_PROT_PLLEP_MASK, param, &((pOccsBase)->prot))
    
#define ioctlOCCS_WPROTECT_OSC_SETTINGS(pOccsBase, param) \
    periphBitGrpSet(OCCS_PROT_OSCEP_MASK, ((param) << 2), &((pOccsBase)->prot))
    
#define ioctlOCCS_WPROTECT_CLK_SETTINGS(pOccsBase, param) \
    periphBitGrpSet(OCCS_PROT_FRQEP_MASK, ((param) << 4), &((pOccsBase)->prot))
#endif /* OCCS_VERSION >= 3 */

#if OCCS_VERSION == 3
#define ioctlOCCS_SET_CLOCK_CHECK(pOccsBase, param) \
    if (param) periphBitSet(OCCS_CLKCHR_CHK_EN, &((pOccsBase)->clkchk)); \
    else periphBitClear(OCCS_CLKCHR_CHK_EN, &((pOccsBase)->clkchk))

#define ioctlOCCS_READ_CLOCK_CHECK_REFERENCE(pOccsBase, param) \
    (periphMemRead(&((pOccsBase)->clkchk)) & OCCS_CLKCHK_REF_CNT)>>8

#define ioctlOCCS_READ_CLOCK_CHECK_TARGET(pOccsBase, param) \
    (periphMemRead(&((pOccsBase)->clkchk))) & OCCS_CLKCHK_TARGET_CNT)

#define ioctlOCCS_SELECT_EXT_CLOCK_SOURCE(pOccsBase, param) \
    periphBitGrpSet(OCCS_OSCTL_EXT_SEL_MASK,param, &((pOccsBase)->osctl))

#define ioctlOCCS_TEST_CLOCK_CHECK(pOccsBase, param) \
    periphBitTest(OCCS_CLKCHR_CHK_EN, &((pOccsBase)->clkchk))

#elif OCCS_VERSION >= 4 //different name of register clkchk->clkchkr

#define ioctlOCCS_SELECT_EXT_CLOCK_SOURCE(pOccsBase, param) \
    if (param) periphBitSet(OCCS_OSCTL_EXT_SEL_CLKIN, &((pOccsBase)->osctl)); \
    else periphBitClear(OCCS_OSCTL_EXT_SEL_CLKIN, &((pOccsBase)->osctl))

#define ioctlOCCS_SET_CLOCK_CHECK(pOccsBase, param) \
    if (param) periphBitSet(OCCS_CLKCHR_CHK_EN, &((pOccsBase)->clkchkr)); \
    else periphBitClear(OCCS_CLKCHR_CHK_EN, &((pOccsBase)->clkchkr))

#define ioctlOCCS_READ_CLOCK_CHECK_REFERENCE(pOccsBase, param) \
    (periphMemRead(&((pOccsBase)->clkchkr)) & OCCS_CLKCHR_REF_CNT)

#define ioctlOCCS_READ_CLOCK_CHECK_TARGET(pOccsBase, param) \
    (periphMemRead(&((pOccsBase)->clkchkt)) & OCCS_CLKCHT_TARGET_CNT)

#define ioctlOCCS_TEST_CLOCK_CHECK(pOccsBase, param) \
    periphBitTest(OCCS_CLKCHR_CHK_EN, &((pOccsBase)->clkchkr))

#endif /* OCCS_VERSION >= 4 */

#if OCCS_VERSION >= 5
#if OCCS_VERSION < 7
#define ioctlOCCS_CRYSTAL_CLOCK_DIV2(pOccsBase, param) \
    if (param) periphBitSet(OCCS_OSCTL_OSC_DIV2, &((pOccsBase)->osctl)); \
    else periphBitClear(OCCS_OSCTL_OSC_DIV2, &((pOccsBase)->osctl))
#endif
#endif /* OCCS_VERSION >= 5 */

#if OCCS_VERSION == 6

#define ioctlOCCS_TRIM_OSC_32K(pOccsBase, param) \
  periphBitGrpSet(OCCS_FREQ_TRIM32K_MASK, ArchIO.Sim.sim_nvmopt2l, &((pOccsBase)->osctl2))

#define ioctlOCCS_RETRIM_OSC_32K(pOccsBase, param) \
  periphBitGrpSet(OCCS_FREQ_TRIM32K_MASK, param, &((pOccsBase)->osctl2))

#define ioctlOCCS_32KHZ_RC_OSCILATOR_OPERATION(pOccsBase, param) \
  if (param) periphBitClear(OCCS_OSCTL_ROPD32K, &((pOccsBase)->osctl2)); \
  else periphBitSet(OCCS_OSCTL_ROPD32K, &((pOccsBase)->osctl2))

#endif

#if OCCS_VERSION == 7

#define ioctlOCCS_TRIM_OSC_200K(pOccsBase, param) \
  periphBitGrpSet(OCCS_FREQ_TRIM200K_MASK, ArchIO.Sim.sim_nvmopt2l, &((pOccsBase)->osctl2))

#define ioctlOCCS_RETRIM_OSC_200K(pOccsBase, param) \
  periphBitGrpSet(OCCS_FREQ_TRIM200K_MASK, param, &((pOccsBase)->osctl2))

#define ioctlOCCS_200KHZ_RC_OSCILATOR_OPERATION(pOccsBase, param) \
  if (param) periphBitClear(OCCS_OSCTL_ROPD200K, &((pOccsBase)->osctl2)); \
  else periphBitSet(OCCS_OSCTL_ROPD200K, &((pOccsBase)->osctl2))

#endif

#if OCCS_VERSION >= 6
#define ioctlOCCS_READ_OSC_OK_FLAG(pOccsBase, param) \
    periphBitTest(OCCS_STAT_OSC_OK_MASK, &((pOccsBase)->divby))

#define ioctlOCCS_TRIM_RELAX_OSC_8MHZ(pOccsBase, param) \
  periphBitGrpSet(OCCS_OSCTL_TRIM_MASK, ArchIO.Sim.sim_nvmopt2h, &((pOccsBase)->osctl2))

#define ioctlOCCS_CRYSTAL_OSCILLATOR_POWER_DOWN(pOccsBase, param) \
   if (param) periphBitClear(OCCS_OSCTL2_COPD, &((pOccsBase)->osctl2)); \
   else periphBitSet(OCCS_OSCTL2_COPD, &((pOccsBase)->osctl2))

#define ioctlOCCS_TEMP_TRIM_OSC_8MHZ(pOccsBase, param) \
  periphBitGrpSet(OCCS_OSCTL2_TEMP_TRIM8M_MASK, param << 10, &((pOccsBase)->osctl2))

#define ioctlOCCS_CLOCK_MONITOR_ENABLE(pOccsBase, param) \
   if (param) periphBitSet(OCCS_OSCTL2_MON_ENABLE, &((pOccsBase)->osctl2)); \
   else periphBitClear(OCCS_OSCTL2_MON_ENABLE, &((pOccsBase)->osctl2))

#define ioctlOCCS_READ_OSC_CONTROL2_REG(pOccsBase, param) \
    periphMemRead(&((pOccsBase)->osctl2))

#define ioctlOCCS_WRITE_OSC_CONTROL2_REG(pOccsBase, param) \
    periphMemWrite(param, &((pOccsBase)->osctl2))



#endif /* OCCS_VERSION >= 6 */

#if OCCS_VERSION == 7
#define ioctlOCCS_CLOCK_SOURCE_TOPWM_NANO_EDGE(pOccsBase, param) \
    if (param) periphBitSet(OCCS_PLL_DIV2, &((pOccsBase)->divby)); \
    else periphBitClear(OCCS_PLL_DIV2, &((pOccsBase)->divby))
#endif 

/*******************************************************************************
    Internal Relaxation Oscillator commands
*******************************************************************************/

#if OCCS_HAS_RXOSC

#define ioctlOCCS_SET_PRESCALER_CLOCK(pOccsBase, param) \
  if (param) periphBitSet(OCCS_PLLCR_PRECS, &((pOccsBase)->pllcr)); \
  else periphBitClear(OCCS_PLLCR_PRECS, &((pOccsBase)->pllcr))

#define ioctlOCCS_ADJUST_RELAX_OSC_FREQ(pOccsBase, param) \
  periphBitGrpSet(OCCS_OSCTL_TRIM_MASK, param, &((pOccsBase)->osctl))

#if OCCS_VERSION <= 5
#define ioctlOCCS_TRIM_RELAX_OSC_8MHZ(pOccsBase, param) \
  periphBitGrpSet(OCCS_OSCTL_TRIM_MASK, ArchIO.Hfm.fmopt1, &((pOccsBase)->osctl))
#endif

#if OCCS_VERSION == 1
/* ENABLE/DISABLE only */
#define ioctlOCCS_INTERNAL_RELAX_OSC_OPERATION(pOccsBase, param) \
  if (param) periphBitClear(OCCS_OSCTL_ROPD, &((pOccsBase)->osctl)); \
  else periphBitSet(OCCS_OSCTL_ROPD, &((pOccsBase)->osctl))

#else /* OCCS_VERSION >= 2 */
/* ENABLE(>0)/STANDBY(<0)/DISABLE(0) modes */
#define ioctlOCCS_INTERNAL_RELAX_OSC_OPERATION(pOccsBase, param) \
  if ((param) > 0) periphBitClear(OCCS_OSCTL_ROPD | OCCS_OSCTL_ROSB, &((pOccsBase)->osctl)); \
  else if ((param) < 0) periphBitGrpRS(OCCS_OSCTL_ROPD | OCCS_OSCTL_ROSB, OCCS_OSCTL_ROSB, &((pOccsBase)->osctl)); \
  else periphBitGrpRS(OCCS_OSCTL_ROPD | OCCS_OSCTL_ROSB, OCCS_OSCTL_ROPD, &((pOccsBase)->osctl))

#endif

#endif /* OCCS_HAS_RXOSC */

#ifdef __cplusplus
}
#endif

#endif

