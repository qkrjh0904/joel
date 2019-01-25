/* Segway_usart 관련 h파일*/
#ifndef __SEGWAY_USART_H
#define __SEGWAY_USART_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Include -------------------------------------------------- */
#include "stm32f4xx.h"

/* Variable and Function ------------------------------------ */

// 변수 선언



// 함수 선언
void USART1_Config(void);
void USART_puts(USART_TypeDef* USARTx, volatile char *s);


/* ---------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif
