/*
 * var.h
 *
 *  Created on: Sep 2, 2020
 *      Author: Jure
 */

#ifndef VAR_H_
#define VAR_H_

// Phase currents as measured
extern GMCLIB_2COOR_ALBE_T_F16 m2IAlphaBeta;
// DQ currents from measured AB
extern GMCLIB_2COOR_DQ_T_F16 m2IDQ;
// Required DQ currents
extern GMCLIB_2COOR_DQ_T_F16 m2IDQReq;
// Current errors
extern GMCLIB_2COOR_DQ_T_F16 m2IDQError;

// DQ voltages as required
extern GMCLIB_2COOR_DQ_T_F16 m2UDQ;
// Phase voltages as required
extern GMCLIB_2COOR_ALBE_T_F16 m2UAlphaBeta;

// Sin/cos angles of motor
extern GMCLIB_2COOR_SINCOS_T_F16 mSinCosAngle;	

// Angle of motor
extern Frac16 f16CurrentMotorAngle;
extern Frac16 f16MotorAngleIncrease;

// D
extern GFLIB_CTRL_PID_P_AW_T_A32 mudtControllerParamId;		
extern bool_t bStopDIntegFlag;
// Q
extern GFLIB_CTRL_PID_P_AW_T_A32 mudtControllerParamIq;	
extern bool_t bStopQIntegFlag;

// Out values
extern Word16 w16APWMValue;
extern Word16 w16APWMNegValue;
extern Word16 w16BPWMValue;
extern Word16 w16BPWMNegValue;

#endif /* VAR_H_ */
