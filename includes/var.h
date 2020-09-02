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

// DQ voltages as required
extern GMCLIB_2COOR_DQ_T_F16 m2UDQ;
// Phase voltages as required
extern GMCLIB_2COOR_ALBE_T_F16 m2UAlphaBeta;


// Sin/cos angles of motor
extern GMCLIB_2COOR_SINCOS_T_F16 mSinCosAngle;	

#endif /* VAR_H_ */
