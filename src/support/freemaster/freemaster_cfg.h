/******************************************************************************
*
* freemaster_cfg.h
*
* FreeMASTER Serial Communication Driver configuration file. This is the 
* placeholder file which further includes the main application configuration
* header file (appconfig.h) and enables the FreeMATSER driver is configured 
* in the Graphical Configuration Tool
*
* See all FreeMASTER configuration options in the "appconfig.h" file 
*
*******************************************************************************/

#ifndef __FREEMASTER_CFG_H
#define __FREEMASTER_CFG_H

#include "types.h"      /* ITU types defined here (required in arch.h) */
#include "arch.h"       /* SCI base address is defined in this file */
#include "appconfig.h"  /* FreeMASTER driver is configured by GCT */

/*
 * The GCT selects the communication channel using an enumeration constant,
 *  we need to convert it into USE_SCI or USE_JTAG settings 
 */

/* SCI_0 (or single SCI) */
#if (FMSTR_COMM_INTERFACE) == 1 
    #define FMSTR_USE_SCI  1
    #if defined(SCI0_BASE)
    #define FMSTR_SCI_BASE SCI0_BASE
    #elif defined(SCI_BASE)
    #define FMSTR_SCI_BASE SCI_BASE
    #else
    #error SCI_0 base address not specified in arch.h
    #endif

/* SCI_1 */
#elif (FMSTR_COMM_INTERFACE) == 2 
    #define FMSTR_USE_SCI  1
    #if defined(SCI1_BASE)
    #define FMSTR_SCI_BASE SCI1_BASE
    #else
    #error SCI_1 base address not specified in arch.h
    #endif
    
/* JTAG without (3) or with (4) the TDF bug workaround */
#elif (FMSTR_COMM_INTERFACE) == 3 || (FMSTR_COMM_INTERFACE) == 4 
    #define FMSTR_USE_JTAG 1
    #if defined(EONCE_BASE)
    #define FMSTR_JTAG_BASE EONCE_BASE
    #endif

    #if (FMSTR_COMM_INTERFACE) == 4
        #define FMSTR_USE_JTAG_TXFIX 1
    #else
        #define FMSTR_USE_JTAG_TXFIX 0
    #endif

/* MSCAN/FCAN interface */
#elif (FMSTR_COMM_INTERFACE) == 5 
    #if defined(CAN_BASE)
    #define FMSTR_CAN_BASE CAN_BASE
    #endif
    #if MSCAN_VERSION
        #define FMSTR_USE_MSCAN 1
    #elif FCAN_VERSION
		#if FCAN_VERSION <= 1
        #define FMSTR_USE_FLEXCAN 1
		#else
        #define FMSTR_USE_FLEXCAN32 1
        #endif
        /* Define default FlexCAN RX and TX Message Buffers*/
        #define FMSTR_FLEXCAN_TXMB 0
        #define FMSTR_FLEXCAN_RXMB 1
    #endif  

/* FCAN_2 interface */
#elif (FMSTR_COMM_INTERFACE) == 6
    #if defined(CAN2_BASE)
    #define FMSTR_CAN_BASE CAN2_BASE
    #endif
    #if MSCAN_VERSION
        #define FMSTR_USE_MSCAN 1
    #elif FCAN_VERSION
        #define FMSTR_USE_FLEXCAN 1
        /* Define default FlexCAN RX and TX Message Buffers*/
        #define FMSTR_FLEXCAN_TXMB 0
        #define FMSTR_FLEXCAN_RXMB 1
    #endif   
/* SCI_2 */
#elif (FMSTR_COMM_INTERFACE) == 7 
    #define FMSTR_USE_SCI  1
    #if defined(SCI2_BASE)
    #define FMSTR_SCI_BASE SCI2_BASE
    #else
    #error SCI_2 base address not specified in arch.h
    #endif

#else
    #define FMSTR_DISABLE 1
#endif /* COMM_INTERFACE */

//to reduce code size without change key functionality
#define FMSTR_LIGHT_VERSION 1

//use this macro, when FreeMASTER Recorder is not configured correctly to see the right response error code, Application code size will by increaset by 10W of Flash
//#define FMSTR_REC_COMMON_ERR_CODES 0

//use this macro, when your application is using Serial Single wire comunication, Application code size will be increased by 19W of Flash
//#define FMSTR_SCI_TWOWIRE_ONLY 0

//use this macro, when you do not need to control pretrigger samples by PC,Application code size will be reduced 12W in Flash and 2W in RAM
//The value in macro represent post trigger samples (1 .. 65535), Keep this value less than "Recorded samples" configured in PC
#define FMSTR_REC_STATIC_POSTTRIG 0

//Use this macro to disable recorder divisor or to set divisor value staticly
//#define FMSTR_REC_STATIC_DIVISOR 1 //this disables the recorder divisor, in fast recorder saves 7W + 25W of Flash and 3W of RAM, in normal recorder saves 21W of flash and 3W of RAM
//#define FMSTR_REC_STATIC_DIVISOR 2 //sets the recorder divisor to static value (2..65535), in fast recorder saves 5W of flash and 2W of RAM, in normal recorder saves 10W of flash and 2W of RAM

//This macro active fast recorder, where is not trigger value controlled by PC
#define FMSTR_USE_FASTREC 0

//enable/disable float point triggering
#define FMSTR_REC_FLOAT_TRIG  0     

#define FMSTR_USE_EX_CMDS 0

#endif /* __FREEMASTER_CFG_H */
