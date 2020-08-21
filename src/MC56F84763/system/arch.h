/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name: arch.h$
*
* $Date:      Oct-25-2013$
*
* $Version:   2.5.1.0$
*
* Description: Peripheral space map of the MC56F845xx device
*
*****************************************************************************/

#ifndef __ARCH_H
#define __ARCH_H

#ifndef __TYPES_H
#error types.h must be included before arch.h
#endif

/* System Integration Module */

#define SIM_VERSION 7    // for Nevis
#define SIM_VERSION_7

typedef volatile struct 
{
    ARCH_REG4(UWord16, sim_control, sim_ctrl, control, ControlReg);
    ARCH_REG4(UWord16, sim_rststs,  sim_rstat, rststs, StatusReg);
    ARCH_REG3(UWord16, sim_scr0,    sim_swc0, scr0);
    ARCH_REG3(UWord16, sim_scr1,    sim_swc1, scr1);
    ARCH_REG3(UWord16, sim_scr2,    sim_swc2, scr2);
    ARCH_REG3(UWord16, sim_scr3,    sim_swc3, scr3);
    ARCH_REG3(UWord16, sim_msh_id,  sim_mshid, msh_id);
    ARCH_REG3(UWord16, sim_lsh_id,  sim_lshid, lsh_id);
    ARCH_REG3(UWord16, sim_power,   sim_pwr, power);
    ARCH_REG1(UWord16, sim_test);
    ARCH_REG3(UWord16, sim_clkosr,  sim_clkout, clkosr);
    ARCH_REG1(UWord16, sim_pcr);
    ARCH_REG1(UWord16, sim_pce0);
    ARCH_REG1(UWord16, sim_pce1);
    ARCH_REG1(UWord16, sim_pce2);
    ARCH_REG1(UWord16, sim_pce3);
    ARCH_REG1(UWord16, sim_sd0);
    ARCH_REG1(UWord16, sim_sd1);
    ARCH_REG1(UWord16, sim_sd2);
    ARCH_REG1(UWord16, sim_sd3);
    ARCH_REG3(UWord16, sim_isalh,   sim_iosahi, isalh);
    ARCH_REG3(UWord16, sim_isall,   sim_iosalo, isall);
    ARCH_REG1(UWord16, sim_prot);
    ARCH_REG1(UWord16, sim_gpsal);
    ARCH_REG1(UWord16, sim_gpsbh);
    ARCH_REG1(UWord16, sim_gpscl);
    ARCH_REG1(UWord16, sim_gpsch);
    ARCH_REG1(UWord16, sim_gpsdl);
    ARCH_REG1(UWord16, sim_gpsel);
    ARCH_REG1(UWord16, sim_gpseh);
    ARCH_REG1(UWord16, sim_gpsfl);
    ARCH_REG1(UWord16, sim_gpsfh);
    ARCH_REG1(UWord16, sim_gpsgl);
    ARCH_REG1(UWord16, sim_gpsgh);
    ARCH_REG1(UWord16, sim_ips0);
    ARCH_REG1(UWord16, sim_misc0);
    ARCH_REG1(UWord16, sim_pswr0);
    ARCH_REG1(UWord16, sim_pswr1);
    ARCH_REG1(UWord16, sim_pswr2);
    ARCH_REG1(UWord16, sim_pswr3);
    ARCH_REG1(UWord16, sim_pwrmode);
    ARCH_REG1(UWord16, reserved2[3]);
    ARCH_REG1(UWord16, sim_nvmopt2h);
    ARCH_REG1(UWord16, sim_nvmopt2l);
    ARCH_REG1(UWord16, sim_nvmopt3h);
    

    ARCH_REG1(UWord16, reserved3[209]);

} arch_sSIM;

/* Quad Timer Module */

#define QT_VERSION 5
#define QT_VERSION_5

typedef volatile struct
{
    ARCH_REG4(UWord16, tmrcmp1,   comp1, cmp1, CompareReg1); 
    ARCH_REG4(UWord16, tmrcmp2,   comp2, cmp2, CompareReg2);
    ARCH_REG4(UWord16, tmrcap,    capt, cap, CaptureReg);
    ARCH_REG3(UWord16, tmrload,   load, LoadReg);
    ARCH_REG3(UWord16, tmrhold,   hold, HoldReg);
    ARCH_REG3(UWord16, tmrcntr,   cntr, CounterReg);
    ARCH_REG3(UWord16, tmrctrl,   ctrl, ControlReg);
    ARCH_REG4(UWord16, tmrscr,    sctrl, scr, StatusControlReg);
    ARCH_REG2(UWord16, tmrcmpld1, cmpld1);
    ARCH_REG2(UWord16, tmrcmpld2, cmpld2);
    ARCH_REG3(UWord16, tmrcomscr, csctrl, comscr);
    ARCH_REG1(UWord16, filt);
    ARCH_REG1(UWord16, dma);
    ARCH_REG1(UWord16, reserved[2]);
    ARCH_REG1(UWord16, enbl);

} arch_sTimerChannel;

typedef volatile struct
{
    ARCH_REG2(arch_sTimerChannel, ch0, Channel0);
    ARCH_REG2(arch_sTimerChannel, ch1, Channel1);
    ARCH_REG2(arch_sTimerChannel, ch2, Channel2);
    ARCH_REG2(arch_sTimerChannel, ch3, Channel3);

} arch_sTimer;

/* EFPWM Module */

#define EFPWM_VERSION 2
#define EFPWM_VERSION_2
#define EFPWM_HAS_FAULTS  0xf

typedef volatile struct
{
    ARCH_REG1(Word16, smcnt); // FlexPWM base address + 0h  read only
    ARCH_REG1(Word16, sminit); // 1h --
    ARCH_REG1(UWord16, smctrl2); // 2h --
    ARCH_REG1(UWord16, smctrl);  // 3h --
    ARCH_REG1(UWord16, reserved1); // 4h 
    ARCH_REG1(Word16, smval0); // 5h --
    ARCH_REG1(UWord16, smfracval1); // 6h --
    ARCH_REG1(Word16, smval1); // 7h --
    ARCH_REG1(UWord16, smfracval2); // 8h --
    ARCH_REG1(Word16, smval2);  //9h  --
    ARCH_REG1(UWord16, smfracval3); // Ah --
    ARCH_REG1(Word16, smval3); // Bh --
    ARCH_REG1(UWord16, smfracval4); // Ch --
    ARCH_REG1(Word16, smval4); // Dh --
    ARCH_REG1(UWord16, smfracval5); // Eh --
    ARCH_REG1(Word16, smval5); // Fh --
    ARCH_REG1(UWord16, smfrctrl); // 10h --
    ARCH_REG1(UWord16, smoctrl); // 11h --
    ARCH_REG1(UWord16, smsts); // 12h read only
    ARCH_REG1(UWord16, sminten); // 13h --
    ARCH_REG1(UWord16, smdmaen); // 14h - new reg. comparing to Anguilla Black, DMA enable
    ARCH_REG1(UWord16, smtctrl); // 15h --
    ARCH_REG2(UWord16, smdismap, smdismap0); // 16h ?????, Fault disable mapping reg 0, fault channel 0 --
    ARCH_REG1(UWord16, smdismap1); // 17h  new reg. comparing to Anguilla Black, fault channel 1 --
    ARCH_REG1(UWord16, smdtcnt0); // 18h ???? - not the same address comparing to Anguilla Black --
    ARCH_REG1(UWord16, smdtcnt1); // 19h ???? - not the same address comparing to Anguilla Black --
    ARCH_REG1(UWord16, smcaptctrla); // 1Ah ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcaptcompa); // 1Bh ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcaptctrlb); // 1Ch ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcaptcompb); // 1Dh ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcaptctrlx); // 1Eh ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcaptcompx); // 1Fh ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcval0); // 20h ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcval0cyc); // 21h ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcval1); // 22h ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcval1cyc); // 23h ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcval2); // 24h ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcval2cyc); // 25h ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcval3); // 26h ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcval3cyc); // 27h ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcval4); // 28h ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcval4cyc); // 29h ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcval5); // 2Ah ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, smcval5cyc); // 2Bh ???? - new reg. comparing to Anguilla Black
    ARCH_REG1(UWord16, reserved3[4]);//
} arch_sEFPWMSubFracCaptModule;  // structure length = 30h = 48d

typedef volatile struct
{
  ARCH_REG1(Word16, smcnt); // FlexPWMB base address + 0h  read only
  ARCH_REG1(Word16, sminit); // 1h --
  ARCH_REG1(UWord16, smctrl2); // 2h --
  ARCH_REG1(UWord16, smctrl);  // 3h --
  ARCH_REG1(UWord16, reserved1); // 4h 
  ARCH_REG1(Word16, smval0); // 5h --
  ARCH_REG1(UWord16, reserved2); // 6h --
  ARCH_REG1(Word16, smval1); // 7h --
  ARCH_REG1(UWord16, reserved3); // 8h --
  ARCH_REG1(Word16, smval2);  //9h  --
  ARCH_REG1(UWord16, reserved4); // Ah --
  ARCH_REG1(Word16, smval3); // Bh --
  ARCH_REG1(UWord16, reserved5); // Ch --
  ARCH_REG1(Word16, smval4); // Dh --
  ARCH_REG1(UWord16, reserved6); // Eh --
  ARCH_REG1(Word16, smval5); // Fh --
  ARCH_REG1(UWord16, reserved7); // 10h --
  ARCH_REG1(UWord16, smoctrl); // 11h --
  ARCH_REG1(UWord16, smsts); // 12h read only
  ARCH_REG1(UWord16, sminten); // 13h --
  ARCH_REG1(UWord16, smdmaen); // 14h - new reg. comparing to Anguilla Black, DMA enable
  ARCH_REG1(UWord16, smtctrl); // 15h --
  ARCH_REG2(UWord16, smdismap, smdismap0); // 16h ?????, Fault disable mapping reg 0, fault channel 0 --
  ARCH_REG1(UWord16, smdismap1); // 17h  new reg. comparing to Anguilla Black, fault channel 1 --
  ARCH_REG1(UWord16, smdtcnt0); // 18h ???? - not the same address comparing to Anguilla Black --
  ARCH_REG1(UWord16, smdtcnt1); // 19h ???? - not the same address comparing to Anguilla Black --
  ARCH_REG1(UWord16, smcaptctrla); // 1Ah ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcaptcompa); // 1Bh ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcaptctrlb); // 1Ch ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcaptcompb); // 1Dh ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcaptctrlx); // 1Eh ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcaptcompx); // 1Fh ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcval0); // 20h ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcval0cyc); // 21h ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcval1); // 22h ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcval1cyc); // 23h ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcval2); // 24h ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcval2cyc); // 25h ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcval3); // 26h ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcval3cyc); // 27h ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcval4); // 28h ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcval4cyc); // 29h ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcval5); // 2Ah ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, smcval5cyc); // 2Bh ???? - new reg. comparing to Anguilla Black
  ARCH_REG1(UWord16, reserved8[4]);//
} arch_sEFPWMBSubCaptModule;

//Debug LP
typedef volatile struct
{
    ARCH_REG1(Word16, smcnt);
    ARCH_REG1(Word16, sminit);
    ARCH_REG1(UWord16, smctrl2);
    ARCH_REG1(UWord16, smctrl);
    ARCH_REG1(UWord16, reserved1);
    ARCH_REG1(Word16, smval0);
    ARCH_REG1(UWord16, reserved10);
    ARCH_REG1(Word16,  smval1);
    ARCH_REG1(UWord16, reserved11);
    ARCH_REG1(Word16, smval2); // 10
    ARCH_REG1(UWord16, reserved12);
    ARCH_REG1(Word16, smval3);
    ARCH_REG1(UWord16, reserved13);
    ARCH_REG1(Word16, smval4);
    ARCH_REG1(UWord16, reserved14);
    ARCH_REG1(Word16, smval5);
    ARCH_REG1(UWord16, reserved15);
    ARCH_REG1(UWord16, smoctrl);
    ARCH_REG1(UWord16, smsts);
    ARCH_REG1(UWord16, sminten); //20
    ARCH_REG1(UWord16, reserved2);
    ARCH_REG1(UWord16, smtctrl);
    ARCH_REG1(UWord16, smdismap);
    ARCH_REG1(UWord16, smdtcnt0);
    ARCH_REG1(UWord16, smdtcnt1);
    ARCH_REG1(UWord16, reserved3);
    ARCH_REG1(UWord16, smcaptctrla);
    ARCH_REG1(UWord16, smcaptcompa);
    ARCH_REG1(UWord16, smcaptctrlb);
    ARCH_REG1(UWord16, smcaptcompb); // 30
    ARCH_REG1(UWord16, smcaptctrlx);
    ARCH_REG1(UWord16, smcaptcompx);
    ARCH_REG1(Word16, smcval0);
    ARCH_REG1(UWord16, reserved4);
    ARCH_REG1(Word16, smcval1);
    ARCH_REG1(UWord16, reserved5);
    ARCH_REG1(Word16, smcval2);
    ARCH_REG1(UWord16, reserved6);
    ARCH_REG1(Word16, smcval3);
    ARCH_REG1(UWord16, reserved7); // 40
    ARCH_REG1(Word16, smcval4);
    ARCH_REG1(UWord16, reserved8);
    ARCH_REG1(Word16, smcval5); // 43
    ARCH_REG1(UWord16, reserved9[5]); //48
} arch_sEFPWMSubCaptModule;

typedef volatile struct
{
    ARCH_REG2(arch_sEFPWMSubFracCaptModule, Sub0, Submodule0);
    ARCH_REG2(arch_sEFPWMSubFracCaptModule, Sub1, Submodule1);
    ARCH_REG2(arch_sEFPWMSubFracCaptModule, Sub2, Submodule2);
    ARCH_REG2(arch_sEFPWMSubFracCaptModule, Sub3, Submodule3);
    ARCH_REG1(UWord16, outen); // FlexPWM base address + C0h
    ARCH_REG1(UWord16, mask); // C1h
    ARCH_REG1(UWord16, swcount); //C2h
    ARCH_REG1(UWord16, dtsrcsel); // C3h
    ARCH_REG1(UWord16, mctrl); // C4h
    ARCH_REG1(UWord16, mctrl2); // C5h
    ARCH_REG2(UWord16, fctrl, fctrl0); // LP C6h - old reg but new name due to multiple ctrl regs
    ARCH_REG2(UWord16, fsts, fsts0); // C7h - old reg but new name due to multiple sts regs
    ARCH_REG2(UWord16, ffilt, ffilt0); // C8h - old reg but new name due to multiple filt regs
    ARCH_REG1(UWord16, ftst0); // C9h - new register comparing to Anguilla Black
    ARCH_REG1(UWord16, fctrl1); // CAh - new register comparing to Anguilla Black
    ARCH_REG1(UWord16, fsts1); // CBh - new register comparing to Anguilla Black
    ARCH_REG1(UWord16, ffilt1); // CCh - new register comparing to Anguilla Black 
    ARCH_REG1(UWord16, ftst1); // CDh - new register comparing to Anguilla Black
    ARCH_REG1(UWord16, reserved3[50]); //0x32 
} arch_sEFPWM;

typedef volatile struct
{
    ARCH_REG2(arch_sEFPWMBSubCaptModule, Sub0, Submodule0);
    ARCH_REG2(arch_sEFPWMBSubCaptModule, Sub1, Submodule1);
    ARCH_REG2(arch_sEFPWMBSubCaptModule, Sub2, Submodule2);
    ARCH_REG2(arch_sEFPWMBSubCaptModule, Sub3, Submodule3);
    ARCH_REG1(UWord16, outen); // FlexPWM base address + C0h
    ARCH_REG1(UWord16, mask); // C1h
    ARCH_REG1(UWord16, swcount); //C2h
    ARCH_REG1(UWord16, dtsrcsel); // C3h
    ARCH_REG1(UWord16, mctrl); // C4h
    ARCH_REG1(UWord16, reserved3); // C5h
    ARCH_REG2(UWord16, fctrl, fctrl0); // LP C6h - old reg but new name due to multiple ctrl regs
    ARCH_REG2(UWord16, fsts, fsts0); // C7h - old reg but new name due to multiple sts regs
    ARCH_REG2(UWord16, ffilt, ffilt0); // C8h - old reg but new name due to multiple filt regs
    ARCH_REG1(UWord16, ftst0); // C9h - new register comparing to Anguilla Black
    ARCH_REG1(UWord16, fctrl1); // CAh - new register comparing to Anguilla Black
    ARCH_REG1(UWord16, fsts1); // CBh - new register comparing to Anguilla Black
    ARCH_REG1(UWord16, ffilt1); // CCh - new register comparing to Anguilla Black 
    ARCH_REG1(UWord16, ftst1); // CDh - new register comparing to Anguilla Black
    ARCH_REG1(UWord16, reserved4[50]); //0x32 
} arch_sEFPWMB;

/* Interrupt Controller */

#define INTC_VERSION 6  // For nevis 844,854,827
#define INTC_VERSION_6
#define INTC_HAS_IRQPINS 0
typedef volatile struct
{
    ARCH_REG2(UWord16, ipr[13],     PriorityReg[13]);
    ARCH_REG2(UWord16, vba,        VecBaseReg);
    ARCH_REG2(UWord16, fim0,       FastInt0MatchReg);
    ARCH_REG2(UWord16, fival0,     FastInt0AddrLReg);
    ARCH_REG2(UWord16, fivah0,     FastInt0AddrHReg);
    ARCH_REG2(UWord16, fim1,       FastInt1MatchReg);
    ARCH_REG2(UWord16, fival1,     FastInt1AddrLReg);
    ARCH_REG2(UWord16, fivah1,     FastInt1AddrHReg);
    ARCH_REG2(UWord16, irqp[7],    IntPendingReg[7]);
    ARCH_REG3(UWord16, ictl,       ControlReg, ctrl);
    ARCH_REG1(UWord16, reserved1[4]);

} arch_sIntc;

/* A/D Converter */

#define ADC_VERSION 6
#define ADC_VERSION_6

typedef volatile struct
{

    ARCH_REG4(UWord16, adctl1,    ctrl1, adcr1, Control1Reg); // offset - 0x0000, module base address - 0xE500, module size - from 0xE500 to 0xE57F
    ARCH_REG4(UWord16, adctl2,    ctrl2, adcr2, Control2Reg); // 0x0001
    ARCH_REG3(UWord16, adzcc,     zxctrl1, ZeroCrossControlReg1); // 0x0002, new reg name, orig names - zxctrl, ZeroCrossControlReg
    ARCH_REG2(UWord16, zxctrl2,   ZeroCrossControlReg2); // 0x0003, new reg
    ARCH_REG3(UWord16, adlst1,    clist1, ChannelList1Reg); // 0x0004
    ARCH_REG3(UWord16, adlst2,    clist2, ChannelList2Reg); // 0x0005
    ARCH_REG3(UWord16, adlst3,    clist3, ChannelList3Reg); // 0x0006
    ARCH_REG3(UWord16, adlst4,    clist4, ChannelList4Reg); // 0x0007
    ARCH_REG3(UWord16, adsdis,    sdis, DisableReg); // 0x0008
    ARCH_REG3(UWord16, adstat,    stat, StatusReg); // 0x0009
    ARCH_REG2(UWord16, cnrdy, rdy); // 0x000A, new reg name
    ARCH_REG1(UWord16, lolimstat); // 0x000B, new reg
    ARCH_REG1(UWord16, hilimstat); // 0x000C, new reg
    ARCH_REG3(UWord16, adzcstat,  zxstat, ZeroCrossStatusReg); // 0x000D
    ARCH_REG3(UWord16, adrslt[16], rslt[16], ResultReg[16]); //0x000E - 0x001D, 16 registers -> rslt0 - rslt15
    ARCH_REG3(UWord16, adllmt[16], lolim[16], LowLimitReg[16]); //0x001E - 0x002D, 16 registers -> lolim0 - lolim15, more lolim registers
    ARCH_REG3(UWord16, adhlmt[16], hilim[16], HighLimitReg[16]); //0x002E - 0x003D, 16 registers -> hilim0 - hilim15, more hilim registers
    ARCH_REG3(UWord16, adofs[16],  offst[16], OffsetReg[16]); //0x003E - 0x004D, 16 registers -> offst0 - offst15, more offst registers
    ARCH_REG2(UWord16, adcpower,  pwr); // 0x004E
    ARCH_REG2(UWord16, adc_cal,   cal); // 0x004F
    ARCH_REG2(UWord16, adc_gc1,   gc1); // 0x0050
    ARCH_REG2(UWord16, adc_gc2,   gc2); // 0x0051
    ARCH_REG2(UWord16, adc_sctrl,   sctrl); // 0x052
    ARCH_REG2(UWord16, adc_pwr2,   pwr2); // 0x0053
    ARCH_REG1(UWord16, ctrl3); // 0x0054, new reg
    ARCH_REG2(UWord16, schlten, adc_schlten);
    ARCH_REG1(UWord16, reserved[42]); // 42 words reserved   
} arch_sADC;
/* Queued Serial Communication Interface */

#define SCI_VERSION 5
#define SCI_VERSION_5       // for 56f845xx, 56f844xx, 56f827xx

typedef volatile struct
{
    ARCH_REG3(UWord16, scibr,    BaudRateReg, rate);
    ARCH_REG3(UWord16, scicr,    ControlReg, ctrl1);
    ARCH_REG3(UWord16, scicr2,   ControlReg2, ctrl2); /* VERSION_2,3-specific */
    ARCH_REG3(UWord16, scisr,    StatusReg, stat);
    ARCH_REG3(UWord16, scidr,    DataReg, data);
    ARCH_REG1(UWord16, ctrl3);                        /* VERSION_5-specific */
    ARCH_REG1(UWord16, reserved2[10]);
} arch_sSCI;

#define SPI_VERSION 5
#define SPI_VERSION_5


typedef volatile struct
{
    ARCH_REG3(UWord16, spscr,    sctrl, ControlReg);
    ARCH_REG4(UWord16, spdsr,    dsctrl, spdscr, DataSizeReg);
    ARCH_REG3(UWord16, spdrr,    drcv, DataRxReg);
    ARCH_REG3(UWord16, spdtr,    dxmit, DataTxReg);
    ARCH_REG2(UWord16, fifo, spfifo);
    ARCH_REG2(UWord16, delay, spwait);
    ARCH_REG1(UWord16, spctl2);
    ARCH_REG1(UWord16, reserved1[9]);

} arch_sSPI;

//* IIC Interface */

#define IIC_VERSION 5
#define IIC_VERSION_5

typedef volatile struct
{
	ARCH_REG2(UWord16, iica1, addr1);
	ARCH_REG3(UWord16, iicf,  ibfd,  fdiv);
	ARCH_REG3(UWord16, iicc1, ctrl1, cr1);
	ARCH_REG3(UWord16, iics,  stat,  ibsr);
	ARCH_REG3(UWord16, iicd,  data, ibdr);
	ARCH_REG3(UWord16, iicc2, ctrl2, cr2);
	ARCH_REG2(UWord16, iicfilt, iic_filt);
	ARCH_REG1(UWord16, iicra);
	ARCH_REG2(UWord16, iicsmb, iic_smbcsr);
	ARCH_REG2(UWord16, iica2, addr2);
	ARCH_REG1(UWord16, iicslth);
	ARCH_REG1(UWord16, iicsltl);
	ARCH_REG1(UWord16, reserved1[4]);
	
} arch_sIIC;


/* Watchdog Module */

#define COP_VERSION 4 // for 844,854
#define COP_VERSION_4

typedef volatile struct
{
    ARCH_REG3(UWord16, copctl,   ControlReg, ctrl);
    ARCH_REG3(UWord16, copto,    TimeoutReg, tout);
    ARCH_REG3(UWord16, copctr,   ServiceReg, cntr);
    ARCH_REG1(UWord16, intval);
    ARCH_REG1(UWord16, reserved1[12]);

} arch_sCOP;


/* PLL/OCCS Module */

#define OCCS_VERSION 6 // for 56f845xx, 56f844xx
#define OCCS_VERSION_6
#define OCCS_HAS_RXOSC 1

typedef volatile struct
{
    ARCH_REG3(UWord16, pllcr,   ctrl, ControlReg);  //0x00
    ARCH_REG3(UWord16, plldb,   divby, DivideReg);  //0x01
    ARCH_REG3(UWord16, pllsr,   stat, StatusReg);   //0x02
    ARCH_REG1(UWord16, testr);                      //0x03 
    ARCH_REG3(UWord16, osctl,   octrl,   osctl1);   //0x04 
    ARCH_REG1(UWord16, osctl2);                     //0x05 
    ARCH_REG1(UWord16, clkchkr);                    //0x06
    ARCH_REG1(UWord16, clkchkt);                    //0x07
    ARCH_REG1(UWord16, prot);                       //0x08
    ARCH_REG1(UWord16, reserved1[7]);

} arch_sPLL;

/* General Purpose I/O */

#define GPIO_VERSION 4  // for 56f845xx, 56f844xx
#define GPIO_VERSION_4

typedef volatile struct
{
    ARCH_REG3(UWord16, pur,      pupen, PullUpReg);
    ARCH_REG3(UWord16, dr,       data, DataReg);
    ARCH_REG3(UWord16, ddr,      ddir, DataDirectionReg);
    ARCH_REG3(UWord16, per,      peren, PeripheralReg);
    ARCH_REG3(UWord16, iar,      iassrt, IntAssertReg);
    ARCH_REG3(UWord16, ienr,     ien, IntEnableReg);
    ARCH_REG3(UWord16, ipolr,    iepol, IntPolarityReg);
    ARCH_REG3(UWord16, ipr,      ipend, IntPendingReg);
    ARCH_REG3(UWord16, iesr,     iedge, IntEdgeSensReg);
    ARCH_REG3(UWord16, ppmode,   ppoutm, PushPullModeReg);
    ARCH_REG3(UWord16, rawdata,  rdata, RawInputReg);
    ARCH_REG2(UWord16, drive,    DriveStrengthReg); /* VERSION_2,3-specific */
    ARCH_REG1(UWord16, pus);                              /*  VERSION_4-specific*/
    ARCH_REG3(UWord16, slew,     SlewRateControlReg, sre); /*  VERSION_3-specific*/
    ARCH_REG1(UWord16, reserved1[2]);

} arch_sPort;

/* Crossbar switch */

#define XBAR_VERSION 2  // for 56f844, 56f845
#define XBAR_VERSION_2

typedef volatile struct 
{
    ARCH_REG3(UWord16, xb_xbc0, xbc0, xbara_sel0);
    ARCH_REG3(UWord16, xb_xbc1, xbc1, xbara_sel1);
    ARCH_REG3(UWord16, xb_xbc2, xbc2, xbara_sel2);
    ARCH_REG3(UWord16, xb_xbc3, xbc3, xbara_sel3);
    ARCH_REG3(UWord16, xb_xbc4, xbc4, xbara_sel4);
    ARCH_REG3(UWord16, xb_xbc5, xbc5, xbara_sel5);
    ARCH_REG3(UWord16, xb_xbc6, xbc6, xbara_sel6);
    ARCH_REG3(UWord16, xb_xbc7, xbc7, xbara_sel7);
    ARCH_REG3(UWord16, xb_xbc8, xbc8, xbara_sel8);
    ARCH_REG3(UWord16, xb_xbc9, xbc9, xbara_sel9);
    ARCH_REG3(UWord16, xb_xbc10, xbc10, xbara_sel10);
    ARCH_REG3(UWord16, xb_xbc11, xbc11, xbara_sel11);
    ARCH_REG3(UWord16, xb_xbc12, xbc12, xbara_sel12);
    ARCH_REG3(UWord16, xb_xbc13, xbc13, xbara_sel13);
    ARCH_REG3(UWord16, xb_xbc14, xbc14, xbara_sel14);
    ARCH_REG1(UWord16, xbara_sel15);
    ARCH_REG1(UWord16, xbara_sel16);
    ARCH_REG1(UWord16, xbara_sel17);
    ARCH_REG1(UWord16, xbara_sel18);
    ARCH_REG1(UWord16, xbara_sel19);
    ARCH_REG1(UWord16, xbara_sel20);
    ARCH_REG1(UWord16, xbara_sel21);
    ARCH_REG1(UWord16, xbara_sel22);
    ARCH_REG1(UWord16, xbara_sel23);
    ARCH_REG1(UWord16, xbara_sel24);
    ARCH_REG1(UWord16, xbara_sel25);
    ARCH_REG1(UWord16, xbara_sel26);
    ARCH_REG1(UWord16, xbara_sel27);
    ARCH_REG1(UWord16, xbara_sel28);
    ARCH_REG1(UWord16, xbara_sel29);
    ARCH_REG1(UWord16, xbara_ctrl0);
    ARCH_REG1(UWord16, xbara_ctrl1);

} arch_sXBARA;

typedef volatile struct 
{
    ARCH_REG1(UWord16, xbarb_sel0);
    ARCH_REG1(UWord16, xbarb_sel1);
    ARCH_REG1(UWord16, xbarb_sel2);
    ARCH_REG1(UWord16, xbarb_sel3);
    ARCH_REG1(UWord16, xbarb_sel4);
    ARCH_REG1(UWord16, xbarb_sel5);
    ARCH_REG1(UWord16, xbarb_sel6);
    ARCH_REG1(UWord16, xbarb_sel7);
    UWord16 reserved45[0x18];
} arch_sXBARB;

/* CRC generator */

#define CRC_VERSION 2
#define CRC_VERSION_2

typedef volatile struct {
    ARCH_REG1(UWord32, crc);
    ARCH_REG1(UWord32, gpoly);
    ARCH_REG1(UWord32, ctrl);
    ARCH_REG1(UWord32, reserved1[5]);
    
} arch_sCRC;

/* Periodic Interrupt Timer */

#define PIT_VERSION 2
#define PIT_VERSION_2

typedef volatile struct 
{
    ARCH_REG1(UWord16, ctrl);   // new functionality added to PIT_CTRL in version 2
    ARCH_REG1(UWord16, mod);
    ARCH_REG1(UWord16, cntr);
    UWord16 reserved[0xD];

} arch_sPIT;

/* Crossbar AND/OR/INVERT (AOI) Module */

#define AOI_VERSION 1
#define AOI_VERSION_1
typedef volatile struct 
{
    ARCH_REG1(UWord16, bfcrt010);
    ARCH_REG1(UWord16, bfcrt230);
    ARCH_REG1(UWord16, bfcrt011);
    ARCH_REG1(UWord16, bfcrt231);
    ARCH_REG1(UWord16, bfcrt012);
    ARCH_REG1(UWord16, bfcrt232);
    ARCH_REG1(UWord16, bfcrt013);
    ARCH_REG1(UWord16, bfcrt233);
    UWord16 reserved[0x18];

} arch_sAOI;

/* Power Management Controller (PMC) */

#define PMC_VERSION 2
#define PMC_VERSION_2
typedef volatile struct 
{
    ARCH_REG1(UWord16, ctrl);
    ARCH_REG1(UWord16, sts);
    UWord16 reserved[0x0E];
} arch_sPMC;

/* Analog Comparator */

#define HSCMP_VERSION 3
#define HSCMP_VERSION_3

typedef volatile struct 
{
    ARCH_REG1(UWord16, cr0);
    ARCH_REG1(UWord16, cr1);
    ARCH_REG1(UWord16, fpr);
    ARCH_REG1(UWord16, scr);
    ARCH_REG1(UWord16, daccr);
    ARCH_REG1(UWord16, muxcr);
    ARCH_REG1(UWord16, reserved1[2]);

} arch_sHSCMP;

/* Programmable Delay Block */

#define PDB_VERSION 2
#define PDB_VERSION_2

typedef volatile struct 
{
    ARCH_REG2(UWord16, scr, mctrl);
    ARCH_REG1(UWord16, ctrla);
    ARCH_REG1(UWord16, ctrlc);
    ARCH_REG1(UWord16, delaya);
    ARCH_REG1(UWord16, delayb);
    ARCH_REG1(UWord16, delayc);
    ARCH_REG1(UWord16, delayd);
    ARCH_REG1(UWord16, mod);
    ARCH_REG1(UWord16, cnt);
    ARCH_REG1(UWord16, reserved[7]);

} arch_sPDB;

/* Digital to Analog Converter */

#define DAC_VERSION 2
#define DAC_VERSION_2

typedef volatile struct {
    ARCH_REG2(UWord16, ctrl, ctrl0);
    ARCH_REG1(UWord16, data);
    ARCH_REG1(UWord16, step);
    ARCH_REG1(UWord16, minval);
    ARCH_REG1(UWord16, maxval);
    ARCH_REG1(UWord16, status);
    ARCH_REG1(UWord16, ctrl1);
    ARCH_REG1(UWord16, reserved1[9]);

} arch_sDAC;


/* Direct memory aces module  */

#define DMA_VERSION 1
#define DMA_VERSION_1

typedef volatile struct {
    ARCH_REG1(UWord32, sar);
    ARCH_REG1(UWord32, dar);
    ARCH_REG1(UWord32, dsr_bcr);
    ARCH_REG1(UWord32, dcr);
} arch_sDMAchannel;

typedef volatile struct {
    ARCH_REG1(UWord32, reqc);
    ARCH_REG1(UWord16, reserved1[126]);
    ARCH_REG1(arch_sDMAchannel, channel_0);
    ARCH_REG1(arch_sDMAchannel, channel_1);
    ARCH_REG1(arch_sDMAchannel, channel_2);
    ARCH_REG1(arch_sDMAchannel, channel_3);
    ARCH_REG1(UWord16, reserved2[5472]);
} arch_sDMA;

#define ADC16_VERSION 1
#define ADC16_VERSION_1

typedef volatile struct
{
    ARCH_REG1(UWord32, adcsc1a);
    ARCH_REG1(UWord32, reserved1);
    ARCH_REG1(UWord32, adccfg1);
    ARCH_REG1(UWord32, adccfg2);
    ARCH_REG1(UWord32, adcra);
    ARCH_REG1(UWord32, reserved2);
    ARCH_REG1(UWord32, adccv1);
    ARCH_REG1(UWord32, adccv2);
    ARCH_REG1(UWord32, adcsc2);
    ARCH_REG1(UWord32, adcsc3);
    ARCH_REG1(UWord32, adcofs);
    ARCH_REG1(UWord32, adcpg);
    ARCH_REG1(UWord32, reserved3);
    ARCH_REG1(UWord32, adcclpd);
    ARCH_REG1(UWord32, adcclps);
    ARCH_REG1(UWord32, adcclp4);
    ARCH_REG1(UWord32, adcclp3);
    ARCH_REG1(UWord32, adcclp2);
    ARCH_REG1(UWord32, adcclp1);
    ARCH_REG1(UWord32, adcclp0);
    ARCH_REG1(UWord32, reserved4[44]);

} arch_sADC16;


/* Quadrature Encoder/Decoder */

#define ENC_VERSION 1
#define ENC_VERSION_1

typedef volatile struct
{
    ARCH_REG3(UWord16, deccr,  ControlReg, ctrl);
    ARCH_REG3(UWord16, fir,    FilterIntervalReg, filt );
    ARCH_REG2(UWord16, wtr,    WatchdogTimeoutReg);
    ARCH_REG2(UWord16, posd,   PositionDifferenceReg);
    ARCH_REG2(UWord16, posdh,  PositionDifferenceHoldReg);
    ARCH_REG2(UWord16, rev,    RevolutionCounterReg);
    ARCH_REG2(UWord16, revh,   RevolutionHoldReg);
    ARCH_REG2(UWord16, upos,   UpperPositionCounterReg);
    ARCH_REG2(UWord16, lpos,   LowerPositionCounterReg);
    ARCH_REG2(UWord16, uposh,  UpperPositionHoldReg);
    ARCH_REG2(UWord16, lposh,  LowerPositionHoldReg);
    ARCH_REG3(UWord16, uir,    UpperInitializationReg, uinit);
    ARCH_REG3(UWord16, lir,    LowerInitializationReg, linit);
    ARCH_REG2(UWord16, imr,    InputMonitorReg);
    ARCH_REG1(UWord16, tst);
    ARCH_REG1(UWord16, ctrl2);
    ARCH_REG1(UWord16, umod);
    ARCH_REG1(UWord16, lmod);
    ARCH_REG1(UWord16, ucomp);
    ARCH_REG1(UWord16, lcomp);

    ARCH_REG1(UWord16, reserved[12]);

} arch_sENC;


/* FlexCAN Module */

#define FCAN_VERSION 2
#define FCAN_VERSION_2

typedef volatile struct 
{
    ARCH_REG1(UWord32, cs);
    ARCH_REG1(UWord32, id);
    ARCH_REG1(UWord32, data[2]);
    //ARCH_REG1(UWord32, word1);
    //ARCH_REG1(UWord32, reserved1);
                   
} arch_sFlexCAN_MB;

/* number of FlexCAN Message Buffers available */
#define ARCH_FCAN_MBCOUNT 16
#define ARCH_FCAN_EMPTY_MBCOUNT (32-ARCH_FCAN_MBCOUNT)

typedef volatile struct 
{
    ARCH_REG2(UWord32, fcmcr,        mcr);
    ARCH_REG1(UWord32, ctrl1);
    ARCH_REG3(UWord32, fctmr,        tmr,        timer);
    ARCH_REG1(UWord32, reserved1);
    ARCH_REG1(UWord32, rxmgmask);
    ARCH_REG1(UWord32, rx14mask);
    ARCH_REG1(UWord32, rx15mask);
    ARCH_REG1(UWord32, ecr);
    ARCH_REG1(UWord32, esr1);
    ARCH_REG1(UWord32, reserved2);
    ARCH_REG1(UWord32, imask1);
    ARCH_REG1(UWord32, reserved3);
    ARCH_REG1(UWord32, iflag1);
    ARCH_REG1(UWord32, ctrl2);
    ARCH_REG1(UWord32, esr2);
    ARCH_REG1(UWord32, reserved4[2]);

    ARCH_REG1(UWord32, crcr);
    ARCH_REG1(UWord32, rxfgmask);
    ARCH_REG1(UWord32, rxfir);
    
    ARCH_REG1(UWord32, reserved5[12]);
    ARCH_REG1(arch_sFlexCAN_MB, mb[ARCH_FCAN_MBCOUNT]);
    ARCH_REG1(arch_sFlexCAN_MB, mb_unused[ARCH_FCAN_EMPTY_MBCOUNT]);

    ARCH_REG1(UWord32, reserved6[384]);
    ARCH_REG1(UWord32, rximr0);
    ARCH_REG1(UWord32, rximr1);
    ARCH_REG1(UWord32, rximr2);
    ARCH_REG1(UWord32, rximr3);
    ARCH_REG1(UWord32, rximr4);
    ARCH_REG1(UWord32, rximr5);
    ARCH_REG1(UWord32, rximr6);
    ARCH_REG1(UWord32, rximr7);
    ARCH_REG1(UWord32, rximr8);
    ARCH_REG1(UWord32, rximr9);
    ARCH_REG1(UWord32, rximr10);
    ARCH_REG1(UWord32, rximr11);
    ARCH_REG1(UWord32, rximr12);
    ARCH_REG1(UWord32, rximr13);
    ARCH_REG1(UWord32, rximr14);
    ARCH_REG1(UWord32, rximr15);
    ARCH_REG1(UWord32, reserved7[464]);

} arch_sFlexCAN;

/* External Watchdog Monitor */

#define EWM_VERSION 1 
#define EWM_VERSION_1

typedef volatile struct
{
    ARCH_REG2(UWord16, ctrl         , ewm_ctrl             );
    ARCH_REG2(UWord16, serv         , ewm_serv             );
    ARCH_REG2(UWord16, cmpl         , ewm_cmpl             );
    ARCH_REG2(UWord16, cmph         , ewm_cmph             );
    ARCH_REG2(UWord16, clkctrl      , ewm_clkctrl          );
    ARCH_REG2(UWord16, clkprescaler , ewm_clkprescaler     );
    ARCH_REG1(UWord16, reserved1[10]);
} arch_sEWM;


/* Flash Memory Controller  */

#define FMC_VERSION 1 
#define FMC_VERSION_1

typedef volatile struct
{
  ARCH_REG2(UWord32,  pfapr      , fmc_pfapr );
  ARCH_REG2(UWord32,  pfb0cr     , fmc_pfb0cr);
  ARCH_REG2(UWord32,  pfb1cr     , fmc_pfb1cr);
  ARCH_REG1(UWord16, reserved1[122]);
  ARCH_REG2(UWord32,  tagvdw0s0  , fmc_tagvdw0s0);
  ARCH_REG2(UWord32,  tagvdw0s1  , fmc_tagvdw0s1);
  ARCH_REG2(UWord32,  tagvdw0s2  , fmc_tagvdw0s2);
  ARCH_REG2(UWord32,  tagvdw0s3  , fmc_tagvdw0s3);
  ARCH_REG2(UWord32,  tagvdw0s4  , fmc_tagvdw0s4);
  ARCH_REG2(UWord32,  tagvdw0s5  , fmc_tagvdw0s5);
  ARCH_REG2(UWord32,  tagvdw0s6  , fmc_tagvdw0s6);
  ARCH_REG2(UWord32,  tagvdw0s7  , fmc_tagvdw0s7);
  ARCH_REG2(UWord32,  tagvdw1s0  , fmc_tagvdw1s0);
  ARCH_REG2(UWord32,  tagvdw1s1  , fmc_tagvdw1s1);
  ARCH_REG2(UWord32,  tagvdw1s2  , fmc_tagvdw1s2);
  ARCH_REG2(UWord32,  tagvdw1s3  , fmc_tagvdw1s3);
  ARCH_REG2(UWord32,  tagvdw1s4  , fmc_tagvdw1s4);
  ARCH_REG2(UWord32,  tagvdw1s5  , fmc_tagvdw1s5);
  ARCH_REG2(UWord32,  tagvdw1s6  , fmc_tagvdw1s6);
  ARCH_REG2(UWord32,  tagvdw1s7  , fmc_tagvdw1s7);
  ARCH_REG2(UWord32,  tagvdw2s0  , fmc_tagvdw2s0);
  ARCH_REG2(UWord32,  tagvdw2s1  , fmc_tagvdw2s1);
  ARCH_REG2(UWord32,  tagvdw2s2  , fmc_tagvdw2s2);
  ARCH_REG2(UWord32,  tagvdw2s3  , fmc_tagvdw2s3);
  ARCH_REG2(UWord32,  tagvdw2s4  , fmc_tagvdw2s4);
  ARCH_REG2(UWord32,  tagvdw2s5  , fmc_tagvdw2s5);
  ARCH_REG2(UWord32,  tagvdw2s6  , fmc_tagvdw2s6);
  ARCH_REG2(UWord32,  tagvdw2s7  , fmc_tagvdw2s7);
  ARCH_REG2(UWord32,  tagvdw3s0  , fmc_tagvdw3s0);
  ARCH_REG2(UWord32,  tagvdw3s1  , fmc_tagvdw3s1);
  ARCH_REG2(UWord32,  tagvdw3s2  , fmc_tagvdw3s2);
  ARCH_REG2(UWord32,  tagvdw3s3  , fmc_tagvdw3s3);
  ARCH_REG2(UWord32,  tagvdw3s4  , fmc_tagvdw3s4);
  ARCH_REG2(UWord32,  tagvdw3s5  , fmc_tagvdw3s5);
  ARCH_REG2(UWord32,  tagvdw3s6  , fmc_tagvdw3s6);
  ARCH_REG2(UWord32,  tagvdw3s7  , fmc_tagvdw3s7);
  ARCH_REG1(UWord16, reserved2[64]);
  ARCH_REG2(UWord32,  dataw0s0u  , fmc_dataw0s0u);
  ARCH_REG2(UWord32,  dataw0s0l  , fmc_dataw0s0l);
  ARCH_REG2(UWord32,  dataw0s1u  , fmc_dataw0s1u);
  ARCH_REG2(UWord32,  dataw0s1l  , fmc_dataw0s1l);
  ARCH_REG2(UWord32,  dataw0s2u  , fmc_dataw0s2u);
  ARCH_REG2(UWord32,  dataw0s2l  , fmc_dataw0s2l);
  ARCH_REG2(UWord32,  dataw0s3u  , fmc_dataw0s3u);
  ARCH_REG2(UWord32,  dataw0s3l  , fmc_dataw0s3l);
  ARCH_REG2(UWord32,  dataw0s4u  , fmc_dataw0s4u);
  ARCH_REG2(UWord32,  dataw0s4l  , fmc_dataw0s4l);
  ARCH_REG2(UWord32,  dataw0s5u  , fmc_dataw0s5u);
  ARCH_REG2(UWord32,  dataw0s5l  , fmc_dataw0s5l);
  ARCH_REG2(UWord32,  dataw0s6u  , fmc_dataw0s6u);
  ARCH_REG2(UWord32,  dataw0s6l  , fmc_dataw0s6l);
  ARCH_REG2(UWord32,  dataw0s7u  , fmc_dataw0s7u);
  ARCH_REG2(UWord32,  dataw0s7l  , fmc_dataw0s7l);
  ARCH_REG2(UWord32,  dataw1s0u  , fmc_dataw1s0u);
  ARCH_REG2(UWord32,  dataw1s0l  , fmc_dataw1s0l);
  ARCH_REG2(UWord32,  dataw1s1u  , fmc_dataw1s1u);
  ARCH_REG2(UWord32,  dataw1s1l  , fmc_dataw1s1l);
  ARCH_REG2(UWord32,  dataw1s2u  , fmc_dataw1s2u);
  ARCH_REG2(UWord32,  dataw1s2l  , fmc_dataw1s2l);
  ARCH_REG2(UWord32,  dataw1s3u  , fmc_dataw1s3u);
  ARCH_REG2(UWord32,  dataw1s3l  , fmc_dataw1s3l);
  ARCH_REG2(UWord32,  dataw1s4u  , fmc_dataw1s4u);
  ARCH_REG2(UWord32,  dataw1s4l  , fmc_dataw1s4l);
  ARCH_REG2(UWord32,  dataw1s5u  , fmc_dataw1s5u);
  ARCH_REG2(UWord32,  dataw1s5l  , fmc_dataw1s5l);
  ARCH_REG2(UWord32,  dataw1s6u  , fmc_dataw1s6u);
  ARCH_REG2(UWord32,  dataw1s6l  , fmc_dataw1s6l);
  ARCH_REG2(UWord32,  dataw1s7u  , fmc_dataw1s7u);
  ARCH_REG2(UWord32,  dataw1s7l  , fmc_dataw1s7l);
  ARCH_REG2(UWord32,  dataw2s0u  , fmc_dataw2s0u);
  ARCH_REG2(UWord32,  dataw2s0l  , fmc_dataw2s0l);
  ARCH_REG2(UWord32,  dataw2s1u  , fmc_dataw2s1u);
  ARCH_REG2(UWord32,  dataw2s1l  , fmc_dataw2s1l);
  ARCH_REG2(UWord32,  dataw2s2u  , fmc_dataw2s2u);
  ARCH_REG2(UWord32,  dataw2s2l  , fmc_dataw2s2l);
  ARCH_REG2(UWord32,  dataw2s3u  , fmc_dataw2s3u);
  ARCH_REG2(UWord32,  dataw2s3l  , fmc_dataw2s3l);
  ARCH_REG2(UWord32,  dataw2s4u  , fmc_dataw2s4u);
  ARCH_REG2(UWord32,  dataw2s4l  , fmc_dataw2s4l);
  ARCH_REG2(UWord32,  dataw2s5u  , fmc_dataw2s5u);
  ARCH_REG2(UWord32,  dataw2s5l  , fmc_dataw2s5l);
  ARCH_REG2(UWord32,  dataw2s6u  , fmc_dataw2s6u);
  ARCH_REG2(UWord32,  dataw2s6l  , fmc_dataw2s6l);
  ARCH_REG2(UWord32,  dataw2s7u  , fmc_dataw2s7u);
  ARCH_REG2(UWord32,  dataw2s7l  , fmc_dataw2s7l);
  ARCH_REG2(UWord32,  dataw3s0u  , fmc_dataw3s0u);
  ARCH_REG2(UWord32,  dataw3s0l  , fmc_dataw3s0l);
  ARCH_REG2(UWord32,  dataw3s1u  , fmc_dataw3s1u);
  ARCH_REG2(UWord32,  dataw3s1l  , fmc_dataw3s1l);
  ARCH_REG2(UWord32,  dataw3s2u  , fmc_dataw3s2u);
  ARCH_REG2(UWord32,  dataw3s2l  , fmc_dataw3s2l);
  ARCH_REG2(UWord32,  dataw3s3u  , fmc_dataw3s3u);
  ARCH_REG2(UWord32,  dataw3s3l  , fmc_dataw3s3l);
  ARCH_REG2(UWord32,  dataw3s4u  , fmc_dataw3s4u);
  ARCH_REG2(UWord32,  dataw3s4l  , fmc_dataw3s4l);
  ARCH_REG2(UWord32,  dataw3s5u  , fmc_dataw3s5u);
  ARCH_REG2(UWord32,  dataw3s5l  , fmc_dataw3s5l);
  ARCH_REG2(UWord32,  dataw3s6u  , fmc_dataw3s6u);
  ARCH_REG2(UWord32,  dataw3s6l  , fmc_dataw3s6l);
  ARCH_REG2(UWord32,  dataw3s7u  , fmc_dataw3s7u);
  ARCH_REG2(UWord32,  dataw3s7l  , fmc_dataw3s7l);
  ARCH_REG1(UWord16, reserved3[128]);
} arch_sFMC;

/* Miscellaneous Control Module */

#define MCM_VERSION 1 
#define MCM_VERSION_1

typedef volatile struct
{
  UWord16 reserved1[4];
  UWord16 plasc ;
  UWord16 plamc;
  UWord32 cpcr;
  UWord32 cfadr;
  UWord8 cfatr;
  UWord8 cfloc;
  UWord8 cfier;
  UWord8 cfisr;
  UWord32 cfdtr;
  UWord16 reserved2[1];
  UWord32 rpcr ;
  UWord32 uflashbar;
  UWord32 uprambar;
  UWord16 reserved3[2];
  UWord32 srposp;
  UWord32 srpipc;
  UWord32 srpmpc;
  UWord16 reserved4[28];
} arch_sMCM;

/* Flash Status Register */

#define FTFL_VERSION 1 
#define FTFL_VERSION_1

typedef volatile struct
{
  UWord8 fstat ;
  UWord8 fcnfg ;
  UWord8 fsec  ;
  UWord8 fopt  ;
  UWord8 fccob3;
  UWord8 fccob2;
  UWord8 fccob1;
  UWord8 fccob0;
  UWord8 fccob7;
  UWord8 fccob6;
  UWord8 fccob5;
  UWord8 fccob4;
  UWord8 fccobb;
  UWord8 fccoba;
  UWord8 fccob9;
  UWord8 fccob8;
  UWord8 fprot3;
  UWord8 fprot2;
  UWord8 fprot1;
  UWord8 fprot0;
  UWord8 reserved1[3];
  UWord8 feprot;
  UWord8 fdprot;
  UWord8 reserved3[103];
} arch_sFTFL;


#define  MCM_BASE     0xC000
#define  DMA_BASE     0xC800 
#define  FMC_BASE     0xDE00
#define  DAC_BASE     0xE000 
#define  HSCMPA_BASE  0xE020 
#define  HSCMPB_BASE  0xE028 
#define  HSCMPC_BASE  0xE030 
#define  HSCMPD_BASE  0xE038 
#define  SCI0_BASE    0xE080 
#define  SCI1_BASE    0xE090 
#define  SPI0_BASE    0xE0B0 
#define  SPI1_BASE    0xE0C0  
#define  IIC0_BASE    0xE0E0 
#define  IIC1_BASE    0xE0F0 
#define  PIT0_BASE    0xE100 
#define  PIT1_BASE    0xE110 
#define  PDB0_BASE    0xE120 
#define  PDB1_BASE    0xE130 
/*****************************/
#define  TMRA_BASE    0xE140 
#define  TMRB_BASE    0xE180 
#define  CRC_BASE     0xE1C0 
#define  GPIO_A_BASE  0xE200 
#define  GPIO_B_BASE  0xE210 
#define  GPIO_C_BASE  0xE220 
#define  GPIO_D_BASE  0xE230 
#define  GPIO_E_BASE  0xE240 
#define  GPIO_F_BASE  0xE250 
#define  GPIO_G_BASE  0xE260 
#define  PMC_BASE     0xE2A0 
#define  OCCS_BASE    0xE2B0 
#define  INTC_BASE    0xE300 
#define  COP_BASE     0xE320 
#define  EWM_BASE     0xE330 
#define  XBARA_BASE   0xE340 
#define  XBARB_BASE   0xE360 
#define  AOI_BASE     0xE380 
#define  FTFL_BASE    0xE3C0 
#define  SIM_BASE     0xE400 
#define  ADC1_BASE    0xE500 
#define  ADC16_BASE   0xE580 
#define  EFPWMA_BASE  0xE600
#define  CAN_BASE     0xE800 


typedef volatile struct
{
	arch_sMCM           Mcm; 					/* MCM_BASE     0xC000 */
    UWord16             reserved0[0x7C6];       /* Reserved      */
    arch_sDMA           Dma;                    /* DMA_BASE     0xC800 */
    arch_sFMC           Fmc;                    /* FMC_BASE     0xDE00 */
    arch_sDAC           Dac;                    /* DAC_BASE     0xE000 */
    UWord16             reserved02[0x10];       /* Reserved     0xE010 */
    arch_sHSCMP         HscmpA;                 /* HSCMPA_BASE  0xE020 */
    arch_sHSCMP         HscmpB;                 /* HSCMPB_BASE  0xE028 */
    arch_sHSCMP         HscmpC;                 /* HSCMPC_BASE  0xE030 */
    arch_sHSCMP         HscmpD;                 /* HSCMPD_BASE  0xE038 */
    UWord16             reserved07[0x40];       /* Reserved     0xE040 */
    arch_sSCI           Sci0;                   /* SCI0_BASE    0xE080 */
    arch_sSCI           Sci1;                   /* SCI1_BASE    0xE090 */
    UWord16             reserved16[0x10];       /* Reserved     0xE0A0 */
    arch_sSPI           Spi0;                   /* SPI0_BASE    0xE0B0 */
    arch_sSPI           Spi1;                   /* SPI1_BASE    0xE0C0 */
    UWord16             reserved19[0x10];       /* Reserved     0xE0D0 */
    arch_sIIC           Iic0;                   /* I2C0_BASE    0xE0E0 */
    arch_sIIC           Iic1;                   /* I2C1_BASE    0xE0F0 */
    arch_sPIT           Pit0;                   /* PIT0_BASE    0xE100 */
    arch_sPIT           Pit1;                   /* PIT1_BASE    0xE110 */
    arch_sPDB           Pdb0;                   /* PDB0_BASE    0xE120 */
    arch_sPDB           Pdb1;                   /* PDB1_BASE    0xE130 */
    arch_sTimer         TimerA;                 /* TMRA_BASE    0xE140 */
    arch_sTimer         TimerB;                 /* TMRB_BASE    0xE180 */
    arch_sCRC           Crc;                    /* CRC_BASE     0xE1C0 */
    UWord16             reserved29[0x10];       /* Reserved     0xE1D0 */
    UWord16             reserved30[0x20];       /* Reserved     0xE1E0 */
    arch_sPort          PortA;                  /* GPIO_A_BASE  0xE200 */
    arch_sPort          PortB;                  /* GPIO_B_BASE  0xE210 */
    arch_sPort          PortC;                  /* GPIO_C_BASE  0xE220 */
    arch_sPort          PortD;                  /* GPIO_D_BASE  0xE230 */
    arch_sPort          PortE;                  /* GPIO_E_BASE  0xE240 */
    arch_sPort          PortF;                  /* GPIO_F_BASE  0xE250 */
    arch_sPort          PortG;                  /* GPIO_G_BASE  0xE260 */
    UWord16             reserved38[0x30];       /* Reserved     0xE270 */
    arch_sPMC           Pmc;                    /* PMC_BASE     0xE2A0 */
    arch_sPLL           Pll;                    /* OCCS_BASE    0xE2B0 */
    UWord16             reserved41[0x40];       /* Reserved     0xE2C0 */
    arch_sIntc          Intc;                   /* INTC_BASE    0xE300 */
    arch_sCOP           Cop;                    /* COP_BASE     0xE320 */
    arch_sEWM           Ewm;                    /* EWM_BASE     0xE330 */
    arch_sXBARA         XbarA;                  /* XBARA_BASE   0xE340 */
    arch_sXBARB         XbarB;                  /* XBARB_BASE   0xE360 */
    arch_sAOI           Aoi;                    /* AOI_BASE     0xE380 */
    UWord16             reserved48[0x20];       /* Reserved     0xE3A0 */
    arch_sFTFL          Ftfl;                   /* FTFL_BASE    0xE3C0 */ 
    arch_sSIM           Sim;                    /* SIM_BASE     0xE400 */
    arch_sADC           Adc1;                   /* ADC1_BASE    0xE500 */
    arch_sADC16         Adc16;                  /* ADC16_BASE   0xE580 */ 
    arch_sEFPWM         EfpwmA;                 /* EFPWMA_BASE  0xE600 */
    UWord16             reserved54[0x100];       /* Reserved    0xE800 */
    arch_sFlexCAN       FCan;                   /* CAN_BASE     0xE800 */
    UWord16             reserved56[0x1000];     /* Reserved     0xF000 */
    
} arch_sIO;

/* The location of the following structure is defined in linker.cmd */
extern arch_sIO    ArchIO;

/* you can try to use direct address access too */
//#define ArchIO (*(volatile arch_sIO*) 0xf000)

#endif

