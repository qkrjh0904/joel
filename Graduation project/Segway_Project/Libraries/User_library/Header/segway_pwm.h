/* Segway_PWM 관련 h파일*/
#ifndef __SEGWAY_PWM_H
#define __SEGWAY_PWM_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Include -------------------------------------------------- */
#include "stm32f4xx.h"

/* Variable and Function ------------------------------------ */

#define PWM1_CW()		GPIO_SetBits(GPIOD, GPIO_Pin_0)			// PIN0(DIR_시계방향)   
#define PWM1_CCW()		GPIO_ResetBits(GPIOD, GPIO_Pin_0)		// PIN0(DIR_반시계방향)
#define PWM2_CW()		GPIO_SetBits(GPIOD, GPIO_Pin_1)			// PIN1(DIR_시계방향)   
#define PWM2_CCW()		GPIO_ResetBits(GPIOD, GPIO_Pin_1)		// PIN1(DIR_반시계방향)

#define SEA_PWM1_CW()		GPIO_SetBits(GPIOE, GPIO_Pin_1)		// PIN1(DIR_시계방향)   
#define SEA_PWM1_CCW()		GPIO_ResetBits(GPIOE, GPIO_Pin_1)	// PIN1(DIR_반시계방향)
#define SEA_PWM2_CW()		GPIO_SetBits(GPIOE, GPIO_Pin_2)		// PIN2(DIR_시계방향)   
#define SEA_PWM2_CCW()		GPIO_ResetBits(GPIOE, GPIO_Pin_2)	// PIN2(DIR_반시계방향)
#define SEA_PWM3_CW()		GPIO_SetBits(GPIOE, GPIO_Pin_3)		// PIN3(DIR_시계방향)   
#define SEA_PWM3_CCW()		GPIO_ResetBits(GPIOE, GPIO_Pin_3)	// PIN3(DIR_반시계방향)
#define SEA_PWM4_CW()		GPIO_SetBits(GPIOE, GPIO_Pin_4)		// PIN4(DIR_시계방향)   
#define SEA_PWM4_CCW()		GPIO_ResetBits(GPIOE, GPIO_Pin_4)	// PIN4(DIR_반시계방향)

// 변수 선언


// 함수 선언
void PWM_Segway_Config(void);
void PWM_SEA_Config(void);
void PWM_GPIO_Config(void);


/* ---------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif
