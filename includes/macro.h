/*
 * macro.h
 *
 *  Created on: Sep 2, 2020
 *      Author: Jure
 */

#ifndef MACRO_H_
#define MACRO_H_

// Default settings
#define DEFAULT_MOTOR_RUN_CURRENT	FRAC16(0.1)
#define DEFAULT_MOTOR_IDLE_CURRENT	DEFAULT_MOTOR_RUN_CURRENT >> 1

#define D_KP_ACC32					ACC32(5.5)
#define D_KI_ACC32					ACC32(1.2)
#define D_KD_ACC32					ACC32(0.0)

#define Q_KP_ACC32					ACC32(5.5)
#define Q_KI_ACC32					ACC32(1.2)
#define Q_KD_ACC32					ACC32(0.0)

#define PWM_MODULO					2500


#endif /* MACRO_H_ */
