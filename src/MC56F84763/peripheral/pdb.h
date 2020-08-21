/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* File Name:  pdb_8xxx.h
*
* $Date:      Mar-20-2014$
*
* $Version:   1.0.17.0$
*
* Description: Header file for the PDB low-level driver
*
*  PDB_VERSION_1 .. 56F800x devices, see MC56F8006UM.pdf
*  PDB_VERSION_2 .. 56F844xx devices, see MC56F844xxRM.pdf
*
*****************************************************************************/

#ifndef __PDB_H
#define __PDB_H

/* qs.h is a master header file, which must be included */
#if !defined(__ARCH_H) || !defined(__PERIPH_H) || !defined(__APPCONFIG_H)
#error Please include qs.h before pdb.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*
*                      General Interface Description
*
* The PDB device driver interface uses "ioctl" call to control specific PDB functions
* during operation. For details see "ioctl" call.
*
******************************************************************************/

/************************************************************
* PDB module identifiers
*************************************************************/

/* single ("anonymous") module on some devices */
#ifdef PDB_BASE
#define PDB     (&ArchIO.Pdb)
#endif

#ifdef PDB0_BASE
#define PDB_0     (&ArchIO.Pdb0)
#endif

#ifdef PDB1_BASE
#define PDB_1     (&ArchIO.Pdb1)
#endif

/*************************************************************
* arch.h should define device-specific information about PDB
**************************************************************/

#if !defined(PDB_VERSION)
#error PDB not properly described in arch.h (old Quick_Start version?)
#endif

/**************************************************************
* Configuration items for appconfig.h (init values, ...),
**************************************************************/

/* Configuration items for appconfig.h  *

    PDB_SCR_INIT         // Status and Control Register
    PDB_DELAYA_INIT      // Delay A Register
    PDB_DELAYB_INIT      // Delay B Register
    PDB_MOD_INIT         // Counter Modulus Register
*/

/***************************************************
* PDB Ioctl commands
****************************************************/
/* command                      |        Param     */

/* SCR */

#define PDB_SET_PRESCALER             /* PDB_CLOCK_DIVIDER_xxx (xxx=1/2/4/8/16/32/64/128), set the PDB clock prescaler (MCTRL->PRESCALER) */
#define PDB_SET_SW_TRIGGER            /* NULL, activate the software trigger which triggers a reset and restarts the counter. The trigger mode should be first set to SW_TRIG with the PDB_SET_INPUT_TRIGGER command. Alternatively, if TriggerA or TriggerB is bypassed the SW trigger it will propagate immediately (MCTRL->SWTRIG) */
#define PDB_SET_CONTINUOUS_MODE       /* PDB_ENABLE/PDB_DISABLE, set continuous or one-shot mode (MCTRL->CONT)*/

#define PDB_WRITE_DELAYA              /* UWord16, write the parameter value to the DelayA register, which represents the delay between the input PDB trigger and trigger A output. Note: The write is buffered.  Writing to this register writes the data into a buffer, where it is held depending on the value of LDOK and LDMOD bits. The bits are controlled by PDB_SELECT_LOAD_MODE and PDB_SET_LDOK commands (DELAYA->_) */
#define PDB_WRITE_DELAYB              /* UWord16, write the parameter value to the DelayB register, which represents the delay between the input PDB trigger and trigger B output. Note: The write is buffered.  Writing to this register writes the data into a buffer, where it is held depending on the value of LDOK and LDMOD bits. The bits are controlled by PDB_SELECT_LOAD_MODE and PDB_SET_LDOK commands (DELAYB->_) */
#define PDB_WRITE_MOD                 /* UWord16, write the parameter value to the counter modulo register, which presents the terminal value of the PDB counter. When counter reaches the modulo value, it resets to 0x0001. Note: The write is buffered.  Writing to this register writes the data into a buffer, where it is held depending on the value of LDOK and LDMOD bits. The bits are controlled by PDB_SELECT_LOAD_MODE and PDB_SET_LDOK commands (MOD->_) */
#define PDB_READ_COUNT                /* NULL, read and return the PDB Counter register value as UWord16 (CNTR->_) */

#if PDB_VERSION == 1
#define PDB_SET_TRIGGER_A_OUT         /* PDB_TRIGGER_A_xxx (xxx=BYPASS/DELAY_A/DELAY_AB/PULSE_OUT), select the trigger A output mode. In BYPASS mode the Trigger output is bypassed. In DELAY_A mode the parameter the output generates pulse when the counter value reaches the DELAY_A value. The DELAY_AB mode sets the ping-pong operation to generate pulse when the counter value reaches DELAY A and DELAY B values. The PULSE_OUT mode sets the output to Trigger Pulsed Output operation (SCR->AOS) */
#define PDB_SET_TRIGGER_B_OUT         /* PDB_TRIGGER_B_xxx (xxx=BYPASS/DELAY_B/DELAY_AB/PULSE_OUT), select the trigger B output mode. In BYPASS mode the Trigger output is bypassed. In DELAY_B mode the parameter the output generates pulse when the counter value reaches the DELAY_B value. The DELAY_AB mode sets the ping-pong operation to generate pulse when the counter value reaches DELAY A and DELAY B values. The PULSE_OUT mode sets the output to Trigger Pulsed Output operation (SCR->BOS)*/
#define PDB_SET_TRIGGER_A_ENABLE      /* NULL, enable the PDB Trigger A output. The PDB Trigger A is generated when PDB counter value reaches the DELAY A value (SCR->ENA) */
#define PDB_SET_TRIGGER_A_DISABLE     /* NULL, disable the PDB Trigger A output (SCR->ENA) */
#define PDB_SET_TRIGGER_B_ENABLE      /* NULL, enable the PDB Trigger B output. The PDB Trigger B is generated when PDB counter value reaches the DELAY B value (SCR->ENB) */
#define PDB_SET_TRIGGER_B_DISABLE     /* NULL, disable the PDB Trigger B output (SCR->ENB) */
#define PDB_SET_INPUT_TRIGGER         /* PDB_TRIG_xxx (xxx=CMP0_OUT/CMP1_OUT/CMP2_OUT/PWM_SYNC/EXTERNAL/T0/T1/SOFTWARE), set the PDB input trigger source. Select one of High Speed Comparator outputs, PWM SYNC signal, external signal or one of Dual Timer soures as a trigger. The PDB module can also be triggered by software when SWOFTWARE mode is selected. Use the PDB_SET_SW_TRIGGER command to trigger (SCR->TRIGSEL) */
#endif /* PDB_VERSION == 1 */

#if PDB_VERSION == 2
#define PDB_SET_INPUT_TRIGGER       /* PDB_TRIG_xxx (xxx=SEL0/SEL1/SEL2/SEL3/SEL4/SEL5/SEL6/SW_TRIG), select the PDB Input trigger source. Select one of seven input signals as a trigger. The PDB module can also be triggered by software when SW_TRIG mode is selected. Use the PDB_SET_SW_TRIGGER command to trigger (MCTRL->TRIGSEL)*/
#define PDB_MODULE                  /* PDB_ENABLE/PDB_DISABLE, enable/disable the PDB module. When the module is disabled all Trigger and PreTrigger outputs are low (MCTRL->PDBEN)*/

#define PDB_CNT_OVERFLOW_INT        /* PDB_ENABLE/PDB_DISABLE, enable/disable the counter overflow interrupt (MCTRL->COIE) */
#define PDB_GET_OVERFLOW            /* NULL, get the counter overflow interrupt flag (MCTRL->COF)*/
#define PDB_CLEAR_OVERFLOW          /* NULL, clear the counter overflow interrupt flag (MCTRL->COF) */

#define PDB_SET_LDOK                /* NULL, load the DELAY and MOD registers. The effect of this LDOK settings also depends on the LDMOD bit controlled by PDB_SELECT_LOAD_MODE command (MCTRL->LDOK)*/
#define PDB_TEST_LDOK               /* NULL, return the non-zero value when the LDOK bit is set. Use this command to determine if the values in the DELAY* and MOD registers are pending in buffers (non-zero) or if the write has already taken effect (zero) (MCTRL->LDOK) */
#define PDB_SELECT_LOAD_MODE        /* PDB_LOAD_IMMEDIATELY/PDB_LOAD_AFTER_ROLL_OVER, select the behavior of the PDB_SET_LDOK command. Use PDB_LOAD_IMMEDIATELY to enable the DELAY* and MOD registers to be loaded immediately after PDB_SET_LDOK command. Use PDB_LOAD_AFTER_ROLL_OVER to load registers after calling the PDB_SET_LDOK command when the counter rolls over in continuous mode or when a trigger signal is received in one-shot mode (MCTRL->LDMOD) */

#define PDB_SET_TRIGGER_A_ENABLE    /* NULL, enable the PDB Trigger A output. The PDB Trigger A is generated when PDB counter value reaches the DELAY A value (CTRLA->ENA) */
#define PDB_SET_TRIGGER_B_ENABLE    /* NULL, enable the PDB Trigger B output. The PDB Trigger B is generated when PDB counter value reaches the DELAY B value (CTRLA->ENB) */ 
#define PDB_SET_TRIGGER_C_ENABLE    /* NULL, enable the PDB Trigger C output. The PDB Trigger C is generated when PDB counter value reaches the DELAY C value (CTRLC->ENC) */
#define PDB_SET_TRIGGER_D_ENABLE    /* NULL, enable the PDB Trigger D output. The PDB Trigger D is generated when PDB counter value reaches the DELAY D value (CTRLC->END) */             

#define PDB_SET_TRIGGER_A_DISABLE   /* NULL, disable the PDB Trigger A output (CTRLA->ENA) */
#define PDB_SET_TRIGGER_B_DISABLE   /* NULL, disable the PDB Trigger B output (CTRLA->ENB) */ 
#define PDB_SET_TRIGGER_C_DISABLE   /* NULL, disable the PDB Trigger C output (CTRLC->ENC) */
#define PDB_SET_TRIGGER_D_DISABLE   /* NULL, disable the PDB Trigger D output (CTRLC->END) */

#define PDB_SET_TRIGGER_A_BYPASS    /* PDB_ENABLE/PDB_DISABLE, bypass the Trigger A Output of the PDB module (CTRLA->BYPA) */
#define PDB_SET_TRIGGER_B_BYPASS    /* PDB_ENABLE/PDB_DISABLE, bypass the Trigger B Output of the PDB module (CTRLA->BYPB) */
#define PDB_SET_TRIGGER_C_BYPASS    /* PDB_ENABLE/PDB_DISABLE, bypass the Trigger C Output of the PDB module (CTRLC->BYPC) */
#define PDB_SET_TRIGGER_D_BYPASS    /* PDB_ENABLE/PDB_DISABLE, bypass the Trigger D Output of the PDB module (CTRLC->BYPD) */

#define PDB_SET_DELAY_A_INTERRUPT   /* PDB_ENABLE/PDB_DISABLE, enable/disable the interrupt on the DELAYA successful compare request (CTRLA->DAIE) */
#define PDB_SET_DELAY_B_INTERRUPT   /* PDB_ENABLE/PDB_DISABLE, enable/disable the interrupt on the DELAYB successful compare request (CTRLA->DBIE) */
#define PDB_SET_DELAY_C_INTERRUPT   /* PDB_ENABLE/PDB_DISABLE, enable/disable the interrupt on the DELAYC successful compare request (CTRLC->DCIE) */
#define PDB_SET_DELAY_D_INTERRUPT   /* PDB_ENABLE/PDB_DISABLE, enable/disable the interrupt on the DELAYD successful compare request (CTRLC->DDIE) */

#define PDB_SET_TRIGGER_A_OUTSEL    /* PDB_xxx (xxx=SEPARATED_DELAY_A_B/COMBINED_DELAY_AB), select the triggers A and B output mode. In SEPARATED mode, the Trigger A is a function of DELAYA only and Trigger B is a function of DELAYB only. In COMBINED mode, the Trigger A and Trigger B outputs are a function of combined DELAYA and DELAYB (CTRLA->ABSEL) */
#define PDB_SET_TRIGGER_C_OUTSEL    /* PDB_xxx (xxx=SEPARATED_DELAY_C_D/COMBINED_DELAY_CD), select the triggers C and D output mode. In SEPARATED mode, the Trigger C is a function of DELAYC only and Trigger D is a function of DELAYD only. In COMBINED mode, the Trigger C and Trigger D outputs are a function of combined DELAYC and DELAYD (CTRLC->CDSEL) */

#define PDB_SET_INIT_A_VALUE        /* PDB_xxx (xxx=INIT_FALSE/INIT_TRUE), set the Trigger A output value which is forced when Fault A is active and enabled by PDB_SET_FAULT_A command. In COMBINED_DELAY_AB output mode, the specified Trigger A output value is also forced whenever the counter is reloaded (CTRLA->AINIT) */
#define PDB_SET_INIT_C_VALUE        /* PDB_xxx (xxx=INIT_FALSE/INIT_TRUE), set the Trigger C output value which is forced when Fault C is active and enabled by PDB_SET_FAULT_C command. In COMBINED_DELAY_CD output mode, the specified Trigger C output value is also forced whenever the counter is reloaded (CTRLC->CINIT) */

#define PDB_SET_FAULT_A_LENGTH      /* PDB_xxx (xxx=2_IPBUS_CYCLES/4_IPBUS_CYCLES), select the minimum width (number of IP bus clock cycles) of the input fault when it is recognized as a valid fault condition (CTRLA->FLENA) */
#define PDB_SET_FAULT_C_LENGTH      /* PDB_xxx (xxx=2_IPBUS_CYCLES/4_IPBUS_CYCLES), select the minimum width (number of IP bus clock cycles) of the input fault when it is recognized as a valid fault condition (CTRLC->FLENC) */    

#define PDB_SET_FAULT_A             /* PDB_ENABLE/PDB_DISABLE, enable/disable the Fault A. A logic 1 on the Fault A input forces TriggerA output to initial value set by PDB_SET_INIT_A_VALUE command until a counter reload occurs (CTRLA->FLTAEN) */
#define PDB_SET_FAULT_C             /* PDB_ENABLE/PDB_DISABLE, enable/disable the Fault C. A logic 1 on the Fault C input forces TriggerC output to initial value set by PDB_SET_INIT_C_VALUE command until a counter reload occurs (CTRLC->FLTCEN) */

#define PDB_SET_FAULT_A_POLARITY    /* PDB_xxx (xxx=TRUE_INDICATE_FAULT/FALSE_INDICATE_FAULT), select the Fault A polarity (CTRLA->FPOLA) */
#define PDB_SET_FAULT_C_POLARITY    /* PDB_xxx (xxx=TRUE_INDICATE_FAULT/FALSE_INDICATE_FAULT), select the Fault C polarity (CTRLC->FPOLC) */

#define PDB_TEST_DELAY_A_FLAG       /* NULL, return a non-zero value when a successful compare of the values of counter and DELAYA occured (CTRLA->DAF) */
#define PDB_TEST_DELAY_B_FLAG       /* NULL, return a non-zero value when a successful compare of the values of counter and DELAYB occured (CTRLA->DBF) */
#define PDB_TEST_DELAY_C_FLAG       /* NULL, return a non-zero value when a successful compare of the values of counter and DELAYC occured (CTRLC->DCF) */
#define PDB_TEST_DELAY_D_FLAG       /* NULL, return a non-zero value when a successful compare of the values of counter and DELAYD occured (CTRLC->DDF) */

#define PDB_CLEAR_DELAY_A_FLAG      /* NULL, clear the delay A flag (CTRLA->DAF) */
#define PDB_CLEAR_DELAY_B_FLAG      /* NULL, clear the delay B flag (CTRLA->DBF) */
#define PDB_CLEAR_DELAY_C_FLAG      /* NULL, clear the delay C flag (CTRLC->DCF) */
#define PDB_CLEAR_DELAY_D_FLAG      /* NULL, clear the delay D flag (CTRLC->DDF) */

#define PDB_TEST_FAULT_A_STATUS     /* NULL, return a non-zero value when Fault A input is set (CTRLA->FLTA) */
#define PDB_TEST_FAULT_C_STATUS     /* NULL, return a non-zero value when Fault C input is set (CTRLC->FLTC) */

#define PDB_WRITE_DELAYC            /* UWord16, write the parameter value to the DelayC register, which represents the delay between the input PDB trigger and trigger C output. Note: The write is buffered.  Writing to this register writes the data into a buffer, where it is held depending on the value of LDOK and LDMOD bits. The bits are controlled by PDB_SELECT_LOAD_MODE and PDB_SET_LDOK commands (DELAYC->_) */
#define PDB_WRITE_DELAYD            /* UWord16, write the parameter value to the DelayD register, which represents the delay between the input PDB trigger and trigger D output. Note: The write is buffered.  Writing to this register writes the data into a buffer, where it is held depending on the value of LDOK and LDMOD bits. The bits are controlled by PDB_SELECT_LOAD_MODE and PDB_SET_LDOK commands (DELAYD->_) */

#define PDB_WRITE_CTRLA_REG         /* UWord16, write the parameter value to the Control A register.  Note: an inappropriate write to register can clear Write-1-to-Clear (DAF/DBF) flags (CTRLA->_) */
#define PDB_WRITE_CTRLC_REG         /* UWord16, write the parameter value to the Control C register.  Note: an inappropriate write to register can clear Write-1-to-Clear (DCF/DDF) flags (CTRLC->_) */
#define PDB_READ_CTRLA_REG          /* NULL, read and return the value of the Control A register as UWord16 (CTRLA->_) */
#define PDB_READ_CTRLC_REG          /* NULL, read and return the value of the Control C register as UWord16 (CTRLC->_) */
#define PDB_WRITE_MCTRL_REG         /* UWord16, write to the Master Control register the parameter value. Note: an inappropriate write to register may cause accidental clear of Write-1-to-Clear flag (COF) and accidental set of the LDOK bit (MCTRL->_) */
#define PDB_READ_MCTRL_REG          /* NULL, read and return the value of the Master Control register as UWord16 (MCTRL->_) */

#endif /* PDB_VERSION == 2 */


/*****************************************************************
* Software Layer ioctl() commands
*
*  Word16 ioctl( IIC_module_identifier, Command_name, Parameter );
*
******************************************************************

 COMMAND NAME                         PARAMETERS, COMMENTS
----------------------------------------------------------------*/
#define PDB_INIT                    /* NULL, initialize the PDB periheral registers using the appconfig.h _INIT values */


/****************************************************************************
* PDB command parameters
*****************************************************************************/

#define PDB_ENABLE          1
#define PDB_DISABLE         0

/* control register (SCR) */
#define PDB_CLOCK_DIVIDER_1         PDB_SCR_PRESCALER_DIV1
#define PDB_CLOCK_DIVIDER_2         PDB_SCR_PRESCALER_DIV2
#define PDB_CLOCK_DIVIDER_4         PDB_SCR_PRESCALER_DIV4
#define PDB_CLOCK_DIVIDER_8         PDB_SCR_PRESCALER_DIV8
#define PDB_CLOCK_DIVIDER_16        PDB_SCR_PRESCALER_DIV16
#define PDB_CLOCK_DIVIDER_32        PDB_SCR_PRESCALER_DIV32
#define PDB_CLOCK_DIVIDER_64        PDB_SCR_PRESCALER_DIV64
#define PDB_CLOCK_DIVIDER_128       PDB_SCR_PRESCALER_DIV128
#define PDB_TRIGGER_A_BYPASS        PDB_SCR_AOS_BYPASS
#define PDB_TRIGGER_A_DELAY_A       PDB_SCR_AOS_DELAY_A
#define PDB_TRIGGER_A_DELAY_AB      PDB_SCR_AOS_DELAY_AB
#define PDB_TRIGGER_A_PULSE_OUT     PDB_SCR_AOS_PULSE_OUT
#define PDB_TRIGGER_B_BYPASS        PDB_SCR_BOS_BYPASS
#define PDB_TRIGGER_B_DELAY_B       PDB_SCR_BOS_DELAY_A
#define PDB_TRIGGER_B_DELAY_AB      PDB_SCR_BOS_DELAY_AB
#define PDB_TRIGGER_B_PULSE_OUT     PDB_SCR_BOS_PULSE_OUT

#if PDB_VERSION == 1
#define PDB_TRIG_CMP0_OUT           PDB_SCR_TRIGSEL_CMP0_OUT
#define PDB_TRIG_CMP1_OUT           PDB_SCR_TRIGSEL_CMP1_OUT
#define PDB_TRIG_CMP2_OUT           PDB_SCR_TRIGSEL_CMP2_OUT
#define PDB_TRIG_PWM_SYNC           PDB_SCR_TRIGSEL_PWM_SYNC
#define PDB_TRIG_EXTERNAL           PDB_SCR_TRIGSEL_EXT_TRIG
#define PDB_TRIG_T0                 PDB_SCR_TRIGSEL_T0
#define PDB_TRIG_T1                 PDB_SCR_TRIGSEL_T1
#define PDB_TRIG_SOFTWARE           PDB_SCR_TRIGSEL_SW_TRIGGER
#endif /* PDB_VERSION == 1 */

#if PDB_VERSION == 2
#define PDB_TRIG_SEL0               PDB_SCR_TRIGSEL_SEL0
#define PDB_TRIG_SEL1               PDB_SCR_TRIGSEL_SEL1
#define PDB_TRIG_SEL2               PDB_SCR_TRIGSEL_SEL2
#define PDB_TRIG_SEL3               PDB_SCR_TRIGSEL_SEL3
#define PDB_TRIG_SEL4               PDB_SCR_TRIGSEL_SEL4
#define PDB_TRIG_SEL5               PDB_SCR_TRIGSEL_SEL5
#define PDB_TRIG_SEL6               PDB_SCR_TRIGSEL_SEL6
#define PDB_TRIG_SW_TRIG            PDB_SCR_TRIGSEL_SW_TRIGGER
#endif /* PDB_VERSION == 2 */

/****************************************************************************
* register and bit names used in the ioctl functions below
*****************************************************************************/

/* control register (SCR) */
#define PDB_SCR_PRESCALER_MASK          0xE000
#define PDB_SCR_PRESCALER_DIV1          0x0000
#define PDB_SCR_PRESCALER_DIV2          0x2000
#define PDB_SCR_PRESCALER_DIV4          0x4000
#define PDB_SCR_PRESCALER_DIV8          0x6000
#define PDB_SCR_PRESCALER_DIV16         0x8000
#define PDB_SCR_PRESCALER_DIV32         0xA000
#define PDB_SCR_PRESCALER_DIV64         0xC000
#define PDB_SCR_PRESCALER_DIV128        0xE000

#if PDB_VERSION == 1
#define PDB_SCR_SWTRIG                  0x0020
#define PDB_SCR_TRIGSEL_MASK            0x001C
#define PDB_SCR_TRIGSEL_CMP0_OUT        0x0000
#define PDB_SCR_TRIGSEL_CMP1_OUT        0x0004
#define PDB_SCR_TRIGSEL_CMP2_OUT        0x0008
#define PDB_SCR_TRIGSEL_PWM_SYNC        0x000C
#define PDB_SCR_TRIGSEL_EXT_TRIG        0x0010
#define PDB_SCR_TRIGSEL_T0              0x0014
#define PDB_SCR_TRIGSEL_T1              0x0018
#define PDB_SCR_TRIGSEL_SW_TRIGGER      0x001C
#define PDB_SCR_AOS_MASK                0x0C00
#define PDB_SCR_AOS_BYPASS              0x0000
#define PDB_SCR_AOS_DELAY_A             0x0400
#define PDB_SCR_AOS_DELAY_AB            0x0800
#define PDB_SCR_AOS_PULSE_OUT           0x0C00
#define PDB_SCR_BOS_MASK                0x0180
#define PDB_SCR_BOS_BYPASS              0x0000
#define PDB_SCR_BOS_DELAY_A             0x0080
#define PDB_SCR_BOS_DELAY_AB            0x0100
#define PDB_SCR_BOS_PULSE_OUT           0x0180
#define PDB_SCR_CONT                    0x0040
#define PDB_SCR_ENA                     0x0002
#define PDB_SCR_ENB                     0x0001
#endif  /* PDB_VERSION == 1 */

#if PDB_VERSION == 2

#define PDB_SCR_SWTRIG                  0x0080
#define PDB_SCR_TRIGSEL_MASK            0x0070
#define PDB_SCR_TRIGSEL_SEL0            0x0000
#define PDB_SCR_TRIGSEL_SEL1            0x0010
#define PDB_SCR_TRIGSEL_SEL2            0x0020
#define PDB_SCR_TRIGSEL_SEL3            0x0030
#define PDB_SCR_TRIGSEL_SEL4            0x0040
#define PDB_SCR_TRIGSEL_SEL5            0x0050
#define PDB_SCR_TRIGSEL_SEL6            0x0060
#define PDB_SCR_TRIGSEL_SW_TRIGGER      0x0070
#define PDB_SCR_CONT                    0x0400
#define PDB_SCR_PDBEN                   0x0001
#define PDB_SCR_COIE                    0x0100
#define PDB_SCR_LDOK                    0x0800
#define PDB_SCR_LDMOD                   0x1000
#define PDB_SCR_COF                     0x0200
#define PDB_CTRLA_ENA                   0x0002
#define PDB_CTRLA_ENB                   0x0001
#define PDB_CTRLC_ENC                   0x0002
#define PDB_CTRLC_END                   0x0001
#define PDB_CTRLA_BYPA                  0x0008
#define PDB_CTRLA_BYPB                  0x0004
#define PDB_CTRLC_BYPC                  0x0008
#define PDB_CTRLC_BYPD                  0x0004
#define PDB_CTRLA_ABSEL                 0x0010
#define PDB_CTRLA_AINIT                 0x0020
#define PDB_CTRLA_DBIE                  0x0100
#define PDB_CTRLA_DBF                   0x0200
#define PDB_CTRLA_DAIE                  0x0400
#define PDB_CTRLA_DAF                   0x0800
#define PDB_CTRLC_CDSEL                 0x0010
#define PDB_CTRLC_CINIT                 0x0020
#define PDB_CTRLC_DDIE                  0x0100
#define PDB_CTRLC_DDF                   0x0200
#define PDB_CTRLC_DCIE                  0x0400
#define PDB_CTRLC_DCF                   0x0800
#define PDB_CTRLA_FLTA                  0x8000
#define PDB_CTRLA_FLTAEN                0x4000
#define PDB_CTRLA_FPOLA                 0x2000
#define PDB_CTRLA_FLENA                 0x1000
#define PDB_CTRLC_FLTC                  0x8000
#define PDB_CTRLC_FLTCEN                0x4000
#define PDB_CTRLC_FPOLC                 0x2000
#define PDB_CTRLC_FLENC                 0x1000
#define PDB_LOAD_IMMEDIATELY            0x0000
#define PDB_LOAD_AFTER_ROLL_OVER        0x0001
#define PDB_TRUE_INDICATE_FAULT         0x0001
#define PDB_FALSE_INDICATE_FAULT        0x0000
#define PDB_2_IPBUS_CYCLES              0x0000
#define PDB_4_IPBUS_CYCLES              0x0001
#define PDB_SEPARATED_DELAY_C_D         0x0000
#define PDB_COMBINED_DELAY_CD           0x0001
#define PDB_SEPARATED_DELAY_A_B         0x0000
#define PDB_COMBINED_DELAY_AB           0x0001
#define PDB_INIT_FALSE                  0x0000
#define PDB_INIT_TRUE                   0x0001

/* W1C_BITS_MASK is the same for both CTRLA and CTRLC registers */
#define PDB_CTRL_W1C_BITS_MASK          (PDB_CTRLA_DAF | PDB_CTRLA_DBF)
/* MCTRL register contains the w1c COF flag and LDOK bit */
#define PDB_MCTRL_W1C_BITS_MASK         (PDB_SCR_COF | PDB_SCR_LDOK)

#endif /* PDB_VERSION == 2 */


/****************************************************************************
* PDB ioctl macro implementation
*****************************************************************************/

/***********************************************************************
* PDB init
***********************************************************************/

void pdbInit(arch_sPDB *pPdbBase);
#define ioctlPDB_INIT(pPdbBase, param) pdbInit(pPdbBase)

/***********************************************************************
* PDB Control Register
***********************************************************************/

/* writing to Delay A register */
#define ioctlPDB_WRITE_DELAYA(pPdbBase, param) \
  periphMemWrite(param, &((pPdbBase)->delaya))

/* writing to Delay B register */
#define ioctlPDB_WRITE_DELAYB(pPdbBase, param) \
  periphMemWrite(param, &((pPdbBase)->delayb))

/* writing to MOD register */
#define ioctlPDB_WRITE_MOD(pPdbBase, param) \
  periphMemWrite(param, &((pPdbBase)->mod))

/* read PDB Counter Register */
#define ioctlPDB_READ_COUNT(pPdbBase, param) \
  periphMemRead(&((pPdbBase)->cnt))


#if PDB_VERSION == 1

/* SCR */
/* select Clock Prescaler Select */
#define ioctlPDB_SET_PRESCALER(pPdbBase, param)        \
  periphBitGrpSet(PDB_SCR_PRESCALER_MASK, param, &((pPdbBase)->scr))

/* Set Continuous Mode */
#define ioctlPDB_SET_CONTINUOUS_MODE(pPdbBase, param) \
if (param) periphBitSet(PDB_SCR_CONT, &((pPdbBase)->scr)); \
 else periphBitClear(PDB_SCR_CONT, &((pPdbBase)->scr))

/* Software Trigger */
#define ioctlPDB_SET_SW_TRIGGER(pPdbBase, param) \
  periphBitSet(PDB_SCR_SWTRIG, &((pPdbBase)->scr)); \

/* select Input Trigger */
#define ioctlPDB_SET_INPUT_TRIGGER(pPdbBase, param)        \
  periphBitGrpSet(PDB_SCR_TRIGSEL_MASK, param, &((pPdbBase)->scr))

/* select Trigger A Output */
#define ioctlPDB_SET_TRIGGER_A_OUT(pPdbBase, param)        \
  periphBitGrpSet(PDB_SCR_AOS_MASK, param, &((pPdbBase)->scr))

/* select Trigger B Output */
#define ioctlPDB_SET_TRIGGER_B_OUT(pPdbBase, param)        \
  periphBitGrpSet(PDB_SCR_BOS_MASK, param, &((pPdbBase)->scr))

/* Trigger A Enable */
#define ioctlPDB_SET_TRIGGER_A_ENABLE(pPdbBase, param) \
  periphBitSet(PDB_SCR_ENA, &((pPdbBase)->scr))

/* Trigger A Disable */
#define ioctlPDB_SET_TRIGGER_A_DISABLE(pPdbBase, param) \
  periphBitClear(PDB_SCR_ENA, &((pPdbBase)->scr))

/* Trigger B Enable */
#define ioctlPDB_SET_TRIGGER_B_ENABLE(pPdbBase, param) \
  periphBitSet(PDB_SCR_ENB, &((pPdbBase)->scr))

/* Trigger B Disable */
#define ioctlPDB_SET_TRIGGER_B_DISABLE(pPdbBase, param) \
  periphBitClear(PDB_SCR_ENB, &((pPdbBase)->scr))

#endif /* PDB_VERSION == 1 */

#if PDB_VERSION == 2

/* SCR */
/* PDB version 2 contains w1c COF flag and LDOK bit */

/* select Clock Prescaler Select */
#define ioctlPDB_SET_PRESCALER(pPdbBase, param)        \
  if (param) {periphSafeBitGrpSet(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_PRESCALER_MASK, (param), &((pPdbBase)->scr));} \
  else periphSafeBitClear(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_PRESCALER_MASK, &((pPdbBase)->scr))

/* Set Continuous Mode */
#define ioctlPDB_SET_CONTINUOUS_MODE(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_CONT, &((pPdbBase)->scr)); \
  else periphSafeBitClear(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_CONT, &((pPdbBase)->scr))

/* Software Trigger */
#define ioctlPDB_SET_SW_TRIGGER(pPdbBase, param) \
  periphSafeBitSet(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_SWTRIG, &((pPdbBase)->scr)); \

/* select Input Trigger */
#define ioctlPDB_SET_INPUT_TRIGGER(pPdbBase, param)        \
  if (param) {periphSafeBitGrpSet(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_TRIGSEL_MASK, (param), &((pPdbBase)->scr));} \
  else periphSafeBitClear(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_TRIGSEL_MASK, &((pPdbBase)->scr))

/* Enable PDB module */
#define ioctlPDB_MODULE(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_PDBEN, &((pPdbBase)->scr)); \
  else periphSafeBitClear(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_PDBEN, &((pPdbBase)->scr))

/* Enable overflow interrupt */
#define ioctlPDB_CNT_OVERFLOW_INT(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_COIE, &((pPdbBase)->scr)); \
  else periphSafeBitClear(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_COIE, &((pPdbBase)->scr))

/* Select load mode */
#define ioctlPDB_SELECT_LOAD_MODE(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_LDMOD, &((pPdbBase)->scr)); \
  else periphSafeBitClear(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_LDMOD, &((pPdbBase)->scr))

/* Load OK */
#define ioctlPDB_SET_LDOK(pPdbBase, param) \
  periphSafeAckByOne(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_LDOK, &((pPdbBase)->scr))

#define ioctlPDB_TEST_LDOK(pPdbBase, param) \
  periphBitTest(PDB_SCR_LDOK, &((pPdbBase)->scr))


/* Clear overflow  */
#define ioctlPDB_CLEAR_OVERFLOW(pPdbBase, param) \
  periphSafeAckByOne(PDB_MCTRL_W1C_BITS_MASK, PDB_SCR_COF, &((pPdbBase)->scr))

/* get counter overflow flag */
#define ioctlPDB_GET_OVERFLOW(pPdbBase, param) \
  periphBitTest(PDB_SCR_COF, &((pPdbBase)->scr))

/* CTRLA and CTRLC registers contain Write-1-to-Clear DxxxF (xxx =A/B/C/D) bits */

#define ioctlPDB_SET_TRIGGER_A_ENABLE(pPdbBase, param) \
  periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_ENA, &((pPdbBase)->ctrla))

#define ioctlPDB_SET_TRIGGER_B_ENABLE(pPdbBase, param) \
  periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_ENB, &((pPdbBase)->ctrla)) 

#define ioctlPDB_SET_TRIGGER_C_ENABLE(pPdbBase, param) \
  periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_ENC, &((pPdbBase)->ctrlc)) 

#define ioctlPDB_SET_TRIGGER_D_ENABLE(pPdbBase, param) \
  periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_END, &((pPdbBase)->ctrlc)) 

#define ioctlPDB_SET_TRIGGER_A_DISABLE(pPdbBase, param) \
  periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_ENA, &((pPdbBase)->ctrla)) 

#define ioctlPDB_SET_TRIGGER_B_DISABLE(pPdbBase, param) \
  periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_ENB, &((pPdbBase)->ctrla)) 

#define ioctlPDB_SET_TRIGGER_C_DISABLE(pPdbBase, param) \
  periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_ENC, &((pPdbBase)->ctrlc)) 

#define ioctlPDB_SET_TRIGGER_D_DISABLE(pPdbBase, param) \
  periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_END, &((pPdbBase)->ctrlc)) 

#define ioctlPDB_SET_TRIGGER_A_BYPASS(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_BYPA, &((pPdbBase)->ctrla)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_BYPA, &((pPdbBase)->ctrla))

#define ioctlPDB_SET_TRIGGER_B_BYPASS(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_BYPB, &((pPdbBase)->ctrla)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_BYPB, &((pPdbBase)->ctrla))

#define ioctlPDB_SET_TRIGGER_C_BYPASS(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_BYPC, &((pPdbBase)->ctrlc)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_BYPC, &((pPdbBase)->ctrlc))

#define ioctlPDB_SET_TRIGGER_D_BYPASS(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_BYPD, &((pPdbBase)->ctrlc)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_BYPD, &((pPdbBase)->ctrlc))

#define ioctlPDB_SET_TRIGGER_A_OUTSEL(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_ABSEL, &((pPdbBase)->ctrla)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_ABSEL, &((pPdbBase)->ctrla))
 
#define ioctlPDB_SET_INIT_A_VALUE(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_AINIT, &((pPdbBase)->ctrla)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_AINIT, &((pPdbBase)->ctrla))
 
#define ioctlPDB_SET_DELAY_B_INTERRUPT(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_DBIE, &((pPdbBase)->ctrla)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_DBIE, &((pPdbBase)->ctrla))
 
#define ioctlPDB_TEST_DELAY_B_FLAG(pPdbBase, param) \
  periphBitTest(PDB_CTRLA_DBF, &((pPdbBase)->ctrla))  
      
#define ioctlPDB_SET_DELAY_A_INTERRUPT(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_DAIE, &((pPdbBase)->ctrla)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_DAIE, &((pPdbBase)->ctrla))
 
#define ioctlPDB_TEST_DELAY_A_FLAG(pPdbBase, param) \
  periphBitTest(PDB_CTRLA_DAF, &((pPdbBase)->ctrla))  
      
#define ioctlPDB_SET_TRIGGER_C_OUTSEL(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_CDSEL, &((pPdbBase)->ctrlc)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_CDSEL, &((pPdbBase)->ctrlc))
 
#define ioctlPDB_SET_INIT_C_VALUE(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_CINIT, &((pPdbBase)->ctrlc)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_CINIT, &((pPdbBase)->ctrlc))
 
#define ioctlPDB_SET_DELAY_D_INTERRUPT(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_DDIE, &((pPdbBase)->ctrlc)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_DDIE, &((pPdbBase)->ctrlc))

#define ioctlPDB_TEST_DELAY_D_FLAG(pPdbBase, param) \
  periphBitTest(PDB_CTRLC_DDF, &((pPdbBase)->ctrlc))  
      
#define ioctlPDB_SET_DELAY_C_INTERRUPT(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_DCIE, &((pPdbBase)->ctrlc)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_DCIE, &((pPdbBase)->ctrlc))
 
#define ioctlPDB_TEST_DELAY_C_FLAG(pPdbBase, param) \
  periphBitTest(PDB_CTRLC_DCF, &((pPdbBase)->ctrlc))   
  
#define ioctlPDB_TEST_FAULT_A_STATUS(pPdbBase, param) \
  periphBitTest(PDB_CTRLA_FLTA, &((pPdbBase)->ctrla))   

#define ioctlPDB_CLEAR_DELAY_A_FLAG(pPdbBase, param) \
  periphSafeAckByOne(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_DAF, &((pPdbBase)->ctrlc))   

#define ioctlPDB_CLEAR_DELAY_B_FLAG(pPdbBase, param) \
  periphSafeAckByOne(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_DBF, &((pPdbBase)->ctrlc)) 

#define ioctlPDB_CLEAR_DELAY_C_FLAG(pPdbBase, param) \
  periphSafeAckByOne(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_DCF, &((pPdbBase)->ctrlc)) 

#define ioctlPDB_CLEAR_DELAY_D_FLAG(pPdbBase, param) \
  periphSafeAckByOne(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_DDF, &((pPdbBase)->ctrlc)) 

#define ioctlPDB_SET_FAULT_A(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_FLTAEN, &((pPdbBase)->ctrla)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_FLTAEN, &((pPdbBase)->ctrla))
 
#define ioctlPDB_SET_FAULT_A_POLARITY(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_FPOLA, &((pPdbBase)->ctrla)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_FPOLA, &((pPdbBase)->ctrla))
 
#define ioctlPDB_SET_FAULT_A_LENGTH(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_FLENA, &((pPdbBase)->ctrla)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLA_FLENA, &((pPdbBase)->ctrla))

#define ioctlPDB_TEST_FAULT_C_STATUS(pPdbBase, param) \
  periphBitTest(PDB_CTRLC_FLTC, &((pPdbBase)->ctrlc))               

#define ioctlPDB_SET_FAULT_C(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_FLTCEN, &((pPdbBase)->ctrlc)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_FLTCEN, &((pPdbBase)->ctrlc))
 
#define ioctlPDB_SET_FAULT_C_POLARITY(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_FPOLC, &((pPdbBase)->ctrlc)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_FPOLC, &((pPdbBase)->ctrlc))

#define ioctlPDB_SET_FAULT_C_LENGTH(pPdbBase, param) \
  if (param) periphSafeBitSet(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_FLENC, &((pPdbBase)->ctrlc)); \
  else periphSafeBitClear(PDB_CTRL_W1C_BITS_MASK, PDB_CTRLC_FLENC, &((pPdbBase)->ctrlc))

/* writing to Delay C register */
#define ioctlPDB_WRITE_DELAYC(pPdbBase, param) \
  periphMemWrite(param, &((pPdbBase)->delayc))

/* writing to Delay D register */
#define ioctlPDB_WRITE_DELAYD(pPdbBase, param) \
  periphMemWrite(param, &((pPdbBase)->delayd))

/* writing to Ctrl A register */
#define ioctlPDB_WRITE_CTRLA_REG(pPdbBase, param) \
  periphMemWrite(param, &((pPdbBase)->ctrla))

/* writing to Ctrl C register */
#define ioctlPDB_WRITE_CTRLC_REG(pPdbBase, param) \
  periphMemWrite(param, &((pPdbBase)->ctrlc))

/* writing to Master Ctrl register */
#define ioctlPDB_WRITE_MCTRL_REG(pPdbBase, param) \
  periphMemWrite(param, &((pPdbBase)->mctrl))

/* read Ctrl A Register */
#define ioctlPDB_READ_CTRLA_REG(pPdbBase, param) \
  periphMemRead(&((pPdbBase)->ctrla))

/* read Ctrl C Register */
#define ioctlPDB_READ_CTRLC_REG(pPdbBase, param) \
  periphMemRead(&((pPdbBase)->ctrlc))

/* read Master Ctrl Register */
#define ioctlPDB_READ_MCTRL_REG(pPdbBase, param) \
  periphMemRead(&((pPdbBase)->mctrl))

#endif /* PDB_VERSION == 2 */


#ifdef __cplusplus
}
#endif

#endif
