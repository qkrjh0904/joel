/* Segway_I2c 관련 c파일*/
#include "stm32f4xx.h"
#include "segway_header.h"
#include <stdio.h>
#include <math.h>

extern int8_t SLAVE_ADDRESS; // the slave address 
int16_t Data;       // data 값
int16_t Stop;       // stop bit

void I2C1_Config(void)
{   
	GPIO_InitTypeDef GPIO_InitStruct;
	I2C_InitTypeDef I2C_InitStruct;

	/* Peripheral Clock Config */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);		// I2C1 사용
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);		// BPORT 사용
   
	/* Gpio Config */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_I2C1);		// SCL사용
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_I2C1);		// SDA사용
   	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;			// PIN6,PIN7 설정
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;					// AF모드로 사용
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;				// 스피드 50MHz
	GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;					// OPEN_DRAIN사용
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;					// PULL UP 사용
	GPIO_Init(GPIOB, &GPIO_InitStruct);               
	
	/* I2c Config */
	I2C_InitStruct.I2C_ClockSpeed = 100000;						// 통신 속도 100kHz
	I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;						// I2C mode 사용
	I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2;				// duty cycle 50% 사용(standard)
	I2C_InitStruct.I2C_OwnAddress1 = 0x00;						// 자신의 주소, 마스터 모드에서는 필요 없음
	I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;					// ACK 사용 여부 설정
	I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit; // address 길이 설정 
	I2C_Init(I2C1, &I2C_InitStruct);            
   
	I2C_Cmd(I2C1, ENABLE);
}

uint16_t i2c_read_register(uint8_t address)
{ 
	/* write */
	while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1, ENABLE);
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));					// EV5 start condition을 실행한 후 start 상태인지를 확인.
	I2C_Send7bitAddress(I2C1, SLAVE_ADDRESS, I2C_Direction_Transmitter); 
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));	// EV6 체크 및 클리어 (Busy, MSL, ADDR, TXE and TRA Flags --> SR1, SR2 레지스터)
	I2C_SendData(I2C1, address); 
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));			// EV8_2 체크 (TRA, BUSY, BTF Flags check)
	I2C_GenerateSTOP(I2C1, ENABLE);
  
	/* read */
	I2C_GenerateSTART(I2C1, ENABLE);
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));					// EV5 start condition을 실행한 후 start 상태인지를 확인.
	I2C_Send7bitAddress(I2C1, SLAVE_ADDRESS, I2C_Direction_Receiver);  
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));		// EV6 체크
	I2C_AcknowledgeConfig(I2C1, DISABLE);										// NACK
	I2C_GenerateSTOP(I2C1, ENABLE);
	while((I2C_GetLastEvent(I2C1) & 0x0040) != 0x0040);
	Data = I2C_ReceiveData(I2C1) & 0x00FF;
	I2C_AcknowledgeConfig(I2C1, ENABLE);
 
	return Data;
}

void i2c_write_register(uint8_t address, uint8_t data)
{
	while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1, ENABLE);
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));					// EV5 start condition을 실행한 후 start 상태인지를 확인.
	I2C_Send7bitAddress(I2C1, SLAVE_ADDRESS, I2C_Direction_Transmitter);  
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));	// EV6 체크 및 클리어 (Busy, MSL, ADDR, TXE and TRA Flags --> SR1, SR2 레지스터)
	I2C_SendData(I2C1, address); // 
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));			// EV8_2 체크 (TRA, BUSY, BTF Flags check)
	I2C_SendData(I2C1, data);
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));			// EV8_2 체크 (TRA, BUSY, BTF Flags check)
	I2C_GenerateSTOP(I2C1, ENABLE);
}
