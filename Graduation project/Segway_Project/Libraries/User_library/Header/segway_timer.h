/* segway_timer ���� ������� */
#ifndef __SEGWAY_TIMER_H
#define __SEGWAY_TIMER_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Include -------------------------------------------------- */
#include "stm32f4xx.h"

/* Variable and Function ------------------------------------ */


// ���� ����



// �Լ� ����
void TIM5_Config(void);		// TIM5 ����
void TIM_Dt(int16_t Prescaler, int16_t Period);	// �����ֱ� ���


/* ---------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif
