/* segway_timer 과련 헤더파일 */
#ifndef __SEGWAY_TIMER_H
#define __SEGWAY_TIMER_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Include -------------------------------------------------- */
#include "stm32f4xx.h"

/* Variable and Function ------------------------------------ */


// 변수 선언



// 함수 선언
void TIM5_Config(void);		// TIM5 설정
void TIM_Dt(int16_t Prescaler, int16_t Period);	// 제어주기 계산


/* ---------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif
