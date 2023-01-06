/*
 * GAS_Pwm.h
 *
 * Created: Jan 5th, 2023
 * Author: Terry
 * yoonsb@hanyang.ac.kr
 *
 * ref: https://www.youtube.com/watch?v=P6211ic2N_s
 * */

#ifndef INC_GAS_PWM_H_
#define INC_GAS_PWM_H_

#include "stm32f3xx_hal.h"
#include "GAS_BuildConfig.h"


typedef struct {
#ifdef __USE_TIM1__
	//16bit Counter
	uint16_t Interval1;
	uint16_t DutyCycle1;
	double DutyRatio1;
#endif
#ifdef __USE_TIM2__
	//32bit Counter
	uint32_t Interval2;
	uint32_t DutyCycle2;
	double DutyRatio2;
#endif
#ifdef __USE_TIM3__
	//16bit Counter
	uint16_t Interval3;
	uint16_t DutyCycle3;
	double DutyRatio3;
#endif
#ifdef __USE_TIM15__
	//16bit Counter
	uint16_t Interval15;
	uint16_t DutyCycle15;
	double DutyRatio15;
#endif
}SensorHubPWM_t;

extern SensorHubPWM_t SensorHubPWM;
extern const double dutyLowerBound;
extern const double dutyUpperBound;

extern uint32_t PCLK1TIM(void);
extern uint32_t PCLK2TIM(void);

#ifdef __USE_TIM1__
#endif

#ifdef __USE_TIM2__
extern uint16_t TickToRPM_TIM2(uint32_t);
#endif

#ifdef __USE_TIM3__
extern uint16_t TickToRPM_TIM3(uint16_t);
#endif

#ifdef __USE_TIM15__
#endif
#endif /* INC_GAS_PWM_H_ */
