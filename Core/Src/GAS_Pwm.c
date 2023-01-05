/*
 * GAS_Pwm.c
 *
 * Created: Jan 5th, 2023
 * Author: Terry
 * yoonsb@hanyang.ac.kr
 *
 * ref: https://www.youtube.com/watch?v=P6211ic2N_s
 * */

#include "GAS_Pwm.h"
SensorHubPWM_t SensorHubPWM;

const double dutyLowerBound = 0.0;
const double dutyUpperBound = 1.0;

void HAL_TIM_IC_Capture_Callback(TIM_HandleTypeDef *htim)
{
#ifdef __USE_TIM1__
	if(htim->Instance == TIM1) {
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) {
			SensorHubPWM.Interval1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			SensorHubPWM.DutyCycle1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			if(SensorHubPWM.Interval1 > 0) {
				SensorHubPWM.DutyRatio1 = ((double)SensorHubPWM.DutyCycle1) /SensorHubPWM.Interval1;
			}
		}
	}
#endif
#ifdef __USE_TIM2__
	if(htim->Instance == TIM2) {
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) {
			SensorHubPWM.Interval2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			SensorHubPWM.DutyCycle2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			if(SensorHubPWM.Interval2 > 0) {
				SensorHubPWM.DutyRatio2 = ((double)SensorHubPWM.DutyCycle2) /SensorHubPWM.Interval2;
			}
		}
	}
#endif
#ifdef __USE_TIM3__
	if(htim->Instance == TIM3) {
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) {
			SensorHubPWM.Interval3 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			SensorHubPWM.DutyCycle3 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			if(SensorHubPWM.Interval3 > 0) {
				SensorHubPWM.DutyRatio3 = ((double)SensorHubPWM.DutyCycle3) /SensorHubPWM.Interval3;
			}
		}
	}
#endif
#ifdef __USE_TIM15__
	if(htim->Instance == TIM15) {
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) {
			SensorHubPWM.Interval15 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			SensorHubPWM.DutyCycle15 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			if(SensorHubPWM.Interval15 > 0) {
				SensorHubPWM.DutyRatio15 = ((double)SensorHubPWM.DutyCycle15) /SensorHubPWM.Interval15;
			}
		}
	}
#endif
}
