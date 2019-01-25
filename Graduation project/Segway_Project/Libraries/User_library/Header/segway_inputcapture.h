/* Segway_InputCapture ���� h����*/
#ifndef __SEGWAY_INPUTCAPTURE_H
#define __SEGWAY_INPUTCAPTURE_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Include -------------------------------------------------- */
#include "stm32f4xx.h"

/* Variable and Function ------------------------------------ */

// ���� ����
#define TIMER_PRESCALER_FREQ	1000000     // timer �Է� Ŭ�� 1MHz
#define TIMER_PERIOD            0xffff      // timer base�� auto-reload



// �Լ� ����
void INPUT_CAPTURE_Config(void);


/* ---------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif