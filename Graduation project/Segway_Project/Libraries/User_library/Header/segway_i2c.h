/* Segway_I2c 관련 h파일*/
#ifndef __SEGWAY_I2C_H
#define __SEGWAY_I2C_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Include -------------------------------------------------- */
#include "stm32f4xx.h"

/* Variable and Function ------------------------------------ */

// 변수 선언


// 함수 선언
void I2C1_Config(void);
void i2c_write_register(uint8_t address, uint8_t data);
uint16_t i2c_read_register(uint8_t address);


/* ---------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif