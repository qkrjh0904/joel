/* Segway_InputCapture 관련 h파일*/
#ifndef __SEGWAY_INPUTCAPTURE_H
#define __SEGWAY_INPUTCAPTURE_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Include -------------------------------------------------- */
#include "stm32f4xx.h"

/* Variable and Function ------------------------------------ */

// 변수 선언
#define TIMER_PRESCALER_FREQ	1000000     // timer 입력 클력 1MHz
#define TIMER_PERIOD            0xffff      // timer base의 auto-reload



// 함수 선언
void INPUT_CAPTURE_Config(void);


/* ---------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif