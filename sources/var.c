/*
 * var.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Jure
 */

#include "sysInclude.h"

#include "amclib.h"
#include "gdflib.h"
#include "gflib.h"
#include "gmclib.h"
#include "mlib.h"
#include "pclib.h"

#include "var.h"

// Phase currents as measured
GMCLIB_2COOR_ALBE_T_F16 m2IAlphaBeta;
// DQ currents from measured AB
GMCLIB_2COOR_DQ_T_F16 m2IDQ;
// Required DQ currents
GMCLIB_2COOR_DQ_T_F16 m2IDQReq;
// Current errors
GMCLIB_2COOR_DQ_T_F16 m2IDQError;

// DQ voltages as required
GMCLIB_2COOR_DQ_T_F16 m2UDQ;
// Phase voltages as required
GMCLIB_2COOR_ALBE_T_F16 m2UAlphaBeta;

// Sin/cos angles of motor
GMCLIB_2COOR_SINCOS_T_F16 mSinCosAngle;	

// Angle of motor
Frac16 f16CurrentMotorAngle;
Frac16 f16MotorAngleIncrease;

// D
GFLIB_CTRL_PID_P_AW_T_A32 mudtControllerParamId;	
bool_t bStopDIntegFlag = false;
// Q
GFLIB_CTRL_PID_P_AW_T_A32 mudtControllerParamIq;	
bool_t bStopQIntegFlag = false;

// Out values
Word16 w16APWMValue;
Word16 w16APWMNegValue;
Word16 w16BPWMValue;
Word16 w16BPWMNegValue;
