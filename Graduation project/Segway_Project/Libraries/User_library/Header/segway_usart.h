/* Segway_usart ���� h����*/
#ifndef __SEGWAY_USART_H
#define __SEGWAY_USART_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Include -------------------------------------------------- */
#include "stm32f4xx.h"

/* Variable and Function ------------------------------------ */

// ���� ����



// �Լ� ����
void USART1_Config(void);
void USART_puts(USART_TypeDef* USARTx, volatile char *s);


/* ---------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif
