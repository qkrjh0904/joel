/* Segway_Delay 관련 h파일*/
#ifndef __SEGWAY_DELAY_H
#define __SEGWAY_DELAY_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Include -------------------------------------------------- */
#include "stm32f4xx.h"

/* Variable and Function ------------------------------------ */

// 변수 선언


// 함수 선언
void delay_us(unsigned long us);
void delay_ms(unsigned long ms);


/* ---------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif