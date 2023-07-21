/*
 * GAS_Pwm.h
 *
 * Created: Jan 5th, 2023
 * Author: Terry
 * yoonsb@hanyang.ac.kr
 *
 * */

#ifndef INC_GAS_BUILDCONFIG_H_
#define INC_GAS_BUILDCONFIG_H_

#define __USE_ADC1__
#define __USE_ADC2__

/*
 * Select Timer Peripheral employed to receive PWM input.
 * Default: Use TIM2 and TIM3
 * */
//#define __USE_TIM1__
//#define __USE_TIM2__
#define __USE_TIM3__
#define __USE_TIM15__

/*
 * Select the install position to get different binary for each side.
 * */
#define __THIS_SENSORHUB_IS_FOR_FRONT__
//#define __THIS_SENSORHUB_IS_FOR_REAR__

#endif /* INC_GAS_BUILDCONFIG_H_ */
