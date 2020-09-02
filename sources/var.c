/*
 * var.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Jure
 */

#include "var.h"

// Phase currents as measured
GMCLIB_2COOR_ALBE_T_F16 m2IAlphaBeta;
// DQ currents from measured AB
GMCLIB_2COOR_DQ_T_F16 m2IDQ;
// Required DQ currents
GMCLIB_2COOR_DQ_T_F16 m2IDQReq;

// DQ voltages as required
GMCLIB_2COOR_DQ_T_F16 m2UDQ;
// Phase voltages as required
GMCLIB_2COOR_ALBE_T_F16 m2UAlphaBeta;


// Sin/cos angles of motor
GMCLIB_2COOR_SINCOS_T_F16 mSinCosAngle;	
