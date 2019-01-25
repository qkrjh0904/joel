/* Segway_PWM ���� h����*/
#ifndef __SEGWAY_PWM_H
#define __SEGWAY_PWM_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Include -------------------------------------------------- */
#include "stm32f4xx.h"

/* Variable and Function ------------------------------------ */

#define PWM1_CW()		GPIO_SetBits(GPIOD, GPIO_Pin_0)			// PIN0(DIR_�ð����)   
#define PWM1_CCW()		GPIO_ResetBits(GPIOD, GPIO_Pin_0)		// PIN0(DIR_�ݽð����)
#define PWM2_CW()		GPIO_SetBits(GPIOD, GPIO_Pin_1)			// PIN1(DIR_�ð����)   
#define PWM2_CCW()		GPIO_ResetBits(GPIOD, GPIO_Pin_1)		// PIN1(DIR_�ݽð����)

#define SEA_PWM1_CW()		GPIO_SetBits(GPIOE, GPIO_Pin_1)		// PIN1(DIR_�ð����)   
#define SEA_PWM1_CCW()		GPIO_ResetBits(GPIOE, GPIO_Pin_1)	// PIN1(DIR_�ݽð����)
#define SEA_PWM2_CW()		GPIO_SetBits(GPIOE, GPIO_Pin_2)		// PIN2(DIR_�ð����)   
#define SEA_PWM2_CCW()		GPIO_ResetBits(GPIOE, GPIO_Pin_2)	// PIN2(DIR_�ݽð����)
#define SEA_PWM3_CW()		GPIO_SetBits(GPIOE, GPIO_Pin_3)		// PIN3(DIR_�ð����)   
#define SEA_PWM3_CCW()		GPIO_ResetBits(GPIOE, GPIO_Pin_3)	// PIN3(DIR_�ݽð����)
#define SEA_PWM4_CW()		GPIO_SetBits(GPIOE, GPIO_Pin_4)		// PIN4(DIR_�ð����)   
#define SEA_PWM4_CCW()		GPIO_ResetBits(GPIOE, GPIO_Pin_4)	// PIN4(DIR_�ݽð����)

// ���� ����


// �Լ� ����
void PWM_Segway_Config(void);
void PWM_SEA_Config(void);
void PWM_GPIO_Config(void);


/* ---------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif
