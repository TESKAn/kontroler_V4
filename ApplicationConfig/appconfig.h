/*******************************************************************************
*
* File Name: appconfig.h
*
* Description: file for static configuration of the application
*              (initial values, interrupt vectors)
*
*****************************************************************************/

#ifndef __APPCONFIG_H
#define __APPCONFIG_H

/*.*************************************************************************
*
*  File generated by Graphical Configuration Tool Fri, 21/Aug/2020, 23:11:05
*
****************************************************************************.*/

#define MC56F84763
#define EXTCLK 8000000L
#define EXTAL 8000000L
#define APPCFG_DFLTS_OMITTED 1
#define APPCFG_GCT_VERSION 0x02061f00L

/*.
    OCCS Configuration
--------------------------------------------
    Use Factory Trim Value: No 
    Temperature trim value for 8 MHz oscillator: 0
    Enable internal 32 kHz oscillator: No 
    Power Down crystal oscillator: No 
    Core frequency: 100 MHz 
    VCO frequency: 400 MHz 
    Loss of lock interrupt 0: Disable 
    Loss of lock interrupt 1: Disable 
    Loss of reference clock Interrupt: Disable
.*/
#define OCCS_CTRL_INIT                    0x0085U
#define OCCS_DIVBY_INIT                   0x2031U
#define OCCS_OSCTL1_INIT                  0x2220U
#define OCCS_USE_FACTORY_TRIM             1
#define OCCS_OSCTL2_INIT                  0x8100U

/*.
    COP Configuration
--------------------------------------------
    COP clock source: Relaxation oscilator 
    COP operation: Enable 
    COP timeout: 8.38848 sec 
    COP Runs in Stop Mode: No 
    COP Runs in Wait Mode: No 
    COP Write Protect: No 
    Enable Loss of Clock COP: No 
    Enable COP Warning Interrupt: No 
    COP Warning Interrupt Timeout: 32.64 ms
.*/
#define COP_COPCTL_INIT                   0x0302U

/*.
    SYS Configuration
--------------------------------------------
    SIM: Power Saving Modes: Stop enabled 
    Wait enabled 
         OnCE clock to processor core: Enabled when core TAP enabled 
    DMA Enable in RUN and WAIT modes: DMA enabled in all power modes 
    Enable External Reset Input Filter : No , SIM - Clock on GPIO: Enable CLKO_0: No 
    SIM - Clock on GPIO: Enable CLKO_1: Yes
    Source: Continuous System Clock 
    Divide by: 1 
    SIM - Peripheral Clock Enable: GPIO G: No , GPIO F: Yes, GPIO E: Yes, GPIO D: Yes, GPIO C: Yes, GPIO B: Yes, GPIO A: Yes, TMR A0: Yes
                                   TMR A1: Yes, TMR A2: No , TMR A3: No , TMR B0: No , TMR B1: No , TMR B2: No , TMR B3: No , DAC: No 
                                   SCI0: No , SCI1: No , QSPI0: No , QSPI1: No , IIC0: No , IIC1: No , FLEXCAN: No 
                                   CMP A: No , CMP B: No , CMP C: No , CMP D: No , SAR ADC: No , CYC ADC: No , CRC: No , PIT0: No , PIT1: No , PDB0: No , PDB1: No 
                                   PWMCH0: No , PWMCH1: No , PWMCH2: No , PWMCH3: No 
    SIM - Modules Enabled in Stop: GPIO G: No 
                                   GPIO F: No , GPIO E: No , GPIO D: No , GPIO C: No , GPIO B: No , GPIO A: No 
                                   TMR A0: No , TMR A1: No , TMR A2: No , TMR A3: No , TMR B0: No , TMR B1: No , TMR B2: No , TMR B3: No , DAC: No 
                                   SCI0: No , SCI1: No , QSPI0: No , QSPI1: No , IIC0: No , IIC1: No , FLEXCAN: No 
                                   CMP A: No , CMP B: No , CMP C: No , CMP D: No , SAR ADC: No , CYC ADC: No , CRC: No , PIT0: No , PIT1: No , PDB0: No , PDB1: No 
                                   PWMCH0: No , PWMCH1: No , PWMCH2: No , PWMCH3: No 
    Protection of IPS and GPSxx  : Registers not protected 
    Protection of PCE, SD and PCR: Registers not protected 
    Protection of GPIO Port D: Registers not protected 
    Protection of PWRMODE: Registers not protected 
    GPIO Peripheral select registers (GPSn): ANA0/CMPA3 
                                             ANC13 
                                             ANC14 
                                             ANC15 
                                             EXTAL 
                                             TXD0 
                                             RXD0 
                                             TA1 
                                             DACO 
                                             TA2 
                                             SS0_B 
                                             MISO0 
                                             SCLK0 
                                             XB_IN5 
                                             CANTX 
                                             CANRX 
                                             TA3 
                                             SDA0 
                                             SCL0 
                                             RXD2 
                                             TXD2 
                                             XB_OUT11 
                                             PWMA_2B 
                                             PWMA_2A 
                                             PWMA_3B 
                                             PWMA_3A 
                                             PWMB_2B 
                                             PWMB_2A 
                                             XB_IN6 
                                             XB_IN7 
                                             SCL1 
                                             SDA1 
                                             TXD1 
                                             RXD1 
                                             XB_IN2 
                                             XB_IN3 
                                             RXD0 
                                             RXD2 
                                             TXD2 
                                             TXD0 
                                             MISO1 
                                             MOSI1 
                                             SCLK1 
                                             RXD0 
                                             PWMB_1B 
                                             PWMB_1A 
                                             PWMB_0B 
                                             PWMB_0A 
                                             PWMB_3B 
                                             PWMB_3A 
                                             PWMA_FAULT4 
                                             PWMA_FAULT5 
                                             PWMB_0X 
                                             PWMB_1X 
                                             PWMB_2X 
                                             TB3 
    Internal Peripheral Select Register 0 (IPS0): XB_OUT49 
                                                  XB_OUT50 
                                                  XB_OUT51 
                                                  XB_OUT52 
                                                  GPIO C2 
                                                  GPIO F8 
                                                  GPIO F6/F0/G6 
                                                  GPIO F7/G11 
                                                  FAULT0 input pin (GPIO E8) 
                                                  FAULT1 input pin (GPIO E9) 
                                                  FAULT2 input pin (GPIO G4) 
                                                  FAULT3 input pin (GPIO G5) 
    Miscellaneous Register 0 (SIM_MISC0): CLKIN0 (GPIOC0 alt1) 
                                          PIT0 master, PIT1 slave 
    SIM - Interrupts: Low voltage 2.2V: Disable
                      Low voltage 2.7V: Disable
                      High voltage 2.2V: Disable
                      High voltage 2.7V: Disable
    Enable Voltage Reference Buffer: No 
    Bandgap trim: 7, Use Factory Trim Value: No 
    Power Control: Large Regulator Standby mode: Normal 
                   Small Regulator 2.7 V Supply Standby mode: Normal 
                   Small Regulator 2.7 V Supply Powerdown mode: Normal 
                   Small Regulator 1.2 V Supply Standby mode: Normal
.*/
#define SIM_GPSCL_INIT                    0x0080U
#define SIM_GPSCH_INIT                    0x0010U
#define SIM_GPSFL_INIT                    0xF004U
#define SIM_PCE0_INIT                     0xC07EU
#define SIM_PCE1_INIT                     0x0002U
#define SIM_PCE2_INIT                     0x0000U
#define SIM_PCE3_INIT                     0x0000U
#define SIM_IPS0_INIT                     0x0F00U

/*.
    INTC Configuration
--------------------------------------------
.*/
#define INTC_ICTL_INIT                    0x0000U

/*.
    QT_A0 Configuration
--------------------------------------------
    Count mode: Signed mode, count primary source rising edges, secondary source is direction 
    Timer Channel Enabled (counter starts counting immediatelly after initialized): Yes
    Primary source: Counter #2 input pin , Secondary: Counter #3 input pin 
    Input polarity: True , Output polarity: True 
    Input capture mode: Capture disabled, Input Edge Flag disabled 
    Output mode: Asserted while counter is active 
    Count stop mode: Count repeatedly , Count length: Roll over , Count direction: Count up 
    Output enable (OFLAG to pin): No 
    Force OFLAG output at startup: No , Forced OFLAG value: 0
    Master mode (broadcast compare event): Disable
    Enable external OFLAG force (on broadcasted event): No 
    Co-channel initialization (on broadcasted event): No 
    Preload Control: 1: Never , Load Reg: 0
                     2: Never , Load Reg: 0
    Interrupts: Overflow: Disabled
                Input edge: Disabled
                Compare: Disabled
                Cmp 1: Disabled
                Cmp 2: Disabled
    Input Filter: Input Signal Sampling [timer clocks] : 0
                  Consecutive Samples Required to Agree: 3 
                  Input Signal Latency: OFF 
    Fault function: No 
    Alternative Load: No 
    Reload on Capture: No 
    Debug action: Continue 
    Enable DMA write for Comparator Preload Register CMPLD1: No 
    Enable DMA write for Comparator Preload Register CMPLD2: No 
    Enable DMA read for Input Edge Flag: No
.*/
#define QT_A0_CTRL_INIT                   0xA580U

/*.
    QT_A1 Configuration
--------------------------------------------
    Count mode: Cascaded Counter mode (up/down) 
    Timer Channel Enabled (counter starts counting immediatelly after initialized): Yes
    Primary source: Counter #0 output , 
    Input polarity: True , Output polarity: True 
    Input capture mode: Capture disabled, Input Edge Flag disabled 
    Output mode: Asserted while counter is active 
    Count stop mode: Count repeatedly , Count length: Roll over , 
    Output enable (OFLAG to pin): No 
    Force OFLAG output at startup: No , Forced OFLAG value: 0
    Master mode (broadcast compare event): Disable
    Enable external OFLAG force (on broadcasted event): No 
    Co-channel initialization (on broadcasted event): No 
    Preload Control: 1: Never , Load Reg: 0
                     2: Never , Load Reg: 0
    Interrupts: Overflow: Disabled
                Input edge: Disabled
                Compare: Disabled
                Cmp 1: Disabled
                Cmp 2: Disabled
    Input Filter: Input Signal Sampling [timer clocks] : 0
                  Consecutive Samples Required to Agree: 3 
                  Input Signal Latency: OFF 
    Fault function: No 
    Alternative Load: No 
    Reload on Capture: No 
    Debug action: Continue 
    Enable DMA write for Comparator Preload Register CMPLD1: No 
    Enable DMA write for Comparator Preload Register CMPLD2: No 
    Enable DMA read for Input Edge Flag: No
.*/
#define QT_A1_CTRL_INIT                   0xE800U

/*.
    QT_A2 Configuration
--------------------------------------------
    Count mode: Quadrature mode, uses primary and secondary sources 
    Timer Channel Enabled (counter starts counting immediatelly after initialized): Yes
    Primary source: Counter #0 input pin , Secondary: Counter #1 input pin 
    Input polarity: True , Output polarity: True 
    Input capture mode: Capture disabled, Input Edge Flag disabled 
    Output mode: Asserted while counter is active 
    Count stop mode: Count repeatedly , Count length: Roll over , Count direction: Count up 
    Output enable (OFLAG to pin): No 
    Force OFLAG output at startup: No , Forced OFLAG value: 0
    Master mode (broadcast compare event): Disable
    Enable external OFLAG force (on broadcasted event): No 
    Co-channel initialization (on broadcasted event): No 
    Preload Control: 1: Never , Load Reg: 0
                     2: Never , Load Reg: 0
    Interrupts: Overflow: Disabled
                Input edge: Disabled
                Compare: Disabled
                Cmp 1: Disabled
                Cmp 2: Disabled
    Input Filter: Input Signal Sampling [timer clocks] : 0
                  Consecutive Samples Required to Agree: 3 
                  Input Signal Latency: OFF 
    Fault function: No 
    Alternative Load: No 
    Reload on Capture: No 
    Debug action: Continue 
    Enable DMA write for Comparator Preload Register CMPLD1: No 
    Enable DMA write for Comparator Preload Register CMPLD2: No 
    Enable DMA read for Input Edge Flag: No
.*/
#define QT_A2_CTRL_INIT                   0x8080U

/*.
    QT_A3 Configuration
--------------------------------------------
    Count mode: Cascaded Counter mode (up/down) 
    Timer Channel Enabled (counter starts counting immediatelly after initialized): Yes
    Primary source: Counter #2 output , 
    Input polarity: True , Output polarity: True 
    Input capture mode: Capture disabled, Input Edge Flag disabled 
    Output mode: Asserted while counter is active 
    Count stop mode: Count repeatedly , Count length: Roll over , 
    Output enable (OFLAG to pin): No 
    Force OFLAG output at startup: No , Forced OFLAG value: 0
    Master mode (broadcast compare event): Disable
    Enable external OFLAG force (on broadcasted event): No 
    Co-channel initialization (on broadcasted event): No 
    Preload Control: 1: Never , Load Reg: 0
                     2: Never , Load Reg: 0
    Interrupts: Overflow: Disabled
                Input edge: Disabled
                Compare: Disabled
                Cmp 1: Disabled
                Cmp 2: Disabled
    Input Filter: Input Signal Sampling [timer clocks] : 0
                  Consecutive Samples Required to Agree: 3 
                  Input Signal Latency: OFF 
    Fault function: No 
    Alternative Load: No 
    Reload on Capture: No 
    Debug action: Continue 
    Enable DMA write for Comparator Preload Register CMPLD1: No 
    Enable DMA write for Comparator Preload Register CMPLD2: No 
    Enable DMA read for Input Edge Flag: No
.*/
#define QT_A3_CTRL_INIT                   0xEC00U

/*.
    GPIO_B Configuration
--------------------------------------------
    Pin  0: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  1: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  2: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  3: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  4: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  5: Function: ANB5/ANC13/CMPC_IN2 , PullUp: Disable , 
    Pin  6: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  7: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high ,
.*/
#define GPIO_B_PER_INIT                   0x0020U

/*.
    GPIO_C Configuration
--------------------------------------------
    Pin  0: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  1: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  2: Function: TXD0 , PullUp: Disable , 
    Pin  3: Function: RXD0 , PullUp: Disable , 
    Pin  4: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  5: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  6: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  7: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  8: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  9: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin 10: Function: XB_IN5 , PullUp: Disable , 
    Pin 11: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin 12: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin 13: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin 14: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin 15: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high ,
.*/
#define GPIO_C_PER_INIT                   0x040CU

/*.
    GPIO_F Configuration
--------------------------------------------
    Pin  0: Function: XB_IN6 , PullUp: Disable , 
    Pin  1: Function: XB_IN7 , PullUp: Disable , 
    Pin  2: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  3: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  4: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  5: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high , 
    Pin  6: Function: XB_IN2/XB_IN14 , PullUp: Disable , 
    Pin  7: Function: XB_IN3/XB_IN15 , PullUp: Disable , 
    Pin  8: Function: GPIO , Direction: Input , PullUp: Disable , Interrupt: Disable, Int.Polarity: Active high ,
.*/
#define GPIO_F_PER_INIT                   0x00C3U

/*.
    XBAR_A Configuration
--------------------------------------------
    0. DMARequest0.: Logic0 
    1. DMARequest1.: Logic0 
    2. DMARequest2.: Logic0 
    3. DMARequest3.: Logic0 
    4. PackagePinGPIO_C14.: Logic0 
    5. PackagePinGPIO_C15.: Logic0 
    6. PackagePinGPIO_F2.: Logic0 
    7. PackagePinGPIO_F3.: Logic0 
    8. PackagePinGPIO_F4.: Logic0 
    9. PackagePinGPIO_F5.: Logic0 
    10. PackagePinGPIO_G8/GPIO_F10.: Logic0 
    11. PackagePinGPIO_G9/GPIO_F9.: Logic0 
    12. ADCA(CyclicADC)Trigger.: Logic0 
    13. ADCB(CyclicADC)Trigger.: Logic0 
    14. ADCC(SARADC)Trigger.: Logic0 
    15. 12-bitDACSYNC_IN.: Logic0 
    16. ComparatorAWindow/Sample.: Logic0 
    17. ComparatorBWindow/Sample.: Logic0 
    18. ComparatorCWindow/Sample.: Logic0 
    19. ComparatorDWindow/Sample.: Logic0 
    20. PWMA0andPWMB0externalinput.: Logic0 
    21. PWMA1andPWMB2externalinput.: Logic0 
    22. PWMA2andPWMB2externalinput.: Logic0 
    23. PWMA3andPWMB3externalinput.: Logic0 
    24. PWMA0ExternalSynchronizationsignal.: Logic0 
    25. PWMA1ExternalSynchronizationsignal.: Logic0 
    26. PWMA2ExternalSynchronizationsignal.: Logic0 
    27. PWMA3ExternalSynchronizationsignal.: Logic0 
    28. PWMAandPWMBExternalClocksignal.: Logic0 
    29. PWMAandPWMBmoduleFAULT0.: Logic0 
    30. PWMAandPWMBmoduleFAULT1.: Logic0 
    31. PWMAandPWMBmoduleFAULT2.: Logic0 
    32. PWMAandPWMBmoduleFAULT3.: Logic0 
    33. PWMAExternalOutputForcesignal.: Logic0 
    34. QuadTimerB0Input.: Logic0 
    35. QuadTimerB1Input.: Logic0 
    36. QuadTimerB2Input.: Logic0 
    37. QuadTimerB3Input.: Logic0 
    38. PDB0InputTrigger.: Logic0 
    39. PDB0FaultA.: Logic0 
    40. PDB0FaultC.: Logic0 
    41. PDB1InputTrigger.: Logic0 
    42. PDB1FaultA.: Logic0 
    43. PDB1FaultC.: Logic0 
    44. QuadratureDecoderPhaseA.: Logic0 
    45. QuadratureDecoderPhaseB.: Logic0 
    46. QuadratureDecoderIndex.: Logic0 
    47. QuadratureDecoderHome.: Logic0 
    48. QuadratureDecoderCapture.: Logic0 
    49. QuadTimerA0Input.: GPIO_C10/GPIO_E7 
    50. QuadTimerA1Input.: GPIO_C13/GPIO_F0 
    51. QuadTimerA2Input.: GPIO_C2/GPIO_E4/GPIO_F6 
    52. QuadTimerA3Input.: GPIO_C6/GPIO_E5/GPIO_F7 
    53. PWMB0ExternalSynchronizationsignal.: Logic0 
    54. PWMB1ExternalSynchronizationsignal.: Logic0 
    55. PWMB2ExternalSynchronizationsignal.: Logic0 
    56. PWMB3ExternalSynchronizationsignal.: Logic0 
    57. PWMBExternalOutputForcesignal.: Logic0 
    58. ExternalWatchdogMonitor.: Logic0 
    Edge Detection: Never 
    Enable DMA: No 
    Enable Interrupt Out0: No 
    Edge Detection: Never 
    Enable DMA: No 
    Enable Interrupt Out1: No 
    Edge Detection: Never 
    Enable DMA: No 
    Enable Interrupt Out2: No 
    Edge Detection: Never 
    Enable DMA: No 
    Enable Interrupt Out3: No
.*/
#define XBAR_A_SEL24_INIT                 0x0500U
#define XBAR_A_SEL25_INIT                 0x0206U
#define XBAR_A_SEL26_INIT                 0x0003U

/*.
    FMSTR Configuration
--------------------------------------------
.*/
#define FMSTR_COMM_INTERFACE              1
#define FMSTR_LONG_INTR                   0
#define FMSTR_SHORT_INTR                  0
#define FMSTR_POLL_DRIVEN                 1
#define FMSTR_USE_SCOPE                   1
#define FMSTR_USE_RECORDER                1
#define FMSTR_REC_BUFF_SIZE               8192


/*.         End of autogenerated code
********************************************************************** ..*/

#endif
