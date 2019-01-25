/* Omniwheel_Usart 관련 c파일*/
#include "stm32f4xx.h"

#include <stdio.h>
#include <math.h>

//  Delay 관련  //
void delay_us(unsigned long us);
void delay_ms(unsigned long ms);

int Imu_Count=0;

char buf[100];

uint16_t All_Data[22];		// IMU 전체 데이터 [SOP][SOP][Roll_H][Roll_L][Pitch_H][Pitch_L][Yaw_H][Yaw_L][CHK][CHK]
int16_t Yaw_data;
int16_t Roll_data;
int16_t Pitch_data;

int16_t X;
int16_t Y;
int16_t Z;

double Acc_X;
double Acc_Y;
double Acc_Z;

double Distance_X;
double Distance_Y;
double Distance_Z;

double Position_X;
double Position_Y;
double Position_Z;

void USART_Config(void);
void USART_PutString(USART_TypeDef* USARTx, volatile char *s);
void USART_PutChar(USART_TypeDef* USARTx, uint8_t Data);
char USART_ReceiveChar(USART_TypeDef* USARTx);
void IMU_Read(void);

int16_t complement(int16_t NUM);

int16_t n = 2;

void TIM5_Config(void);

int main(void)
{
	USART_Config();
        TIM5_Config();

	while(1)
	{
		
	}
}

void TIM5_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;					// TIMEBASE Type 재정의
	NVIC_InitTypeDef NVIC_InitStructure;							// NVIC Type 재정의
    
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);			// TIM5 Clock 설정
  
	TIM_TimeBaseStructure.TIM_Prescaler = 84-1;						// 84MHz/84 = 1MHz
	TIM_TimeBaseStructure.TIM_Period = 10000-1;						// 0.000001 * 1000 = 0.001 = 1ms
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		// 업카운트 모드
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;					// 디지털 필터 및 dead band에 사용
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);              
	TIM_ITConfig(TIM5,TIM_IT_Update, ENABLE);						// TIM5 인터럽트 업데이트 사용
	TIM_Cmd(TIM5,ENABLE);    

	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;					// TIM5 인터럽트 핸들러 사용
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	// 우선순위 0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;			// 서브 우선순위 0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					// IRQHandler사용+

	NVIC_Init(&NVIC_InitStructure);
}
//////////////////////////// 제어 타이머 (1ms) /////////////////////////////
void TIM5_IRQHandler()
{
	if(TIM_GetITStatus(TIM5, TIM_IT_Update) == SET)
	{
		TIM_ClearITPendingBit(TIM5, TIM_IT_Update);
		IMU_Read();
                
//                sprintf(buf,"%d %d %d\n", Roll_data, Pitch_data, Yaw_data);		// UART 사용법
//                USART_PutString(USART1, buf);
//                delay_ms(1);
//                
//                sprintf(buf,"%f %f %f\n", Acc_X, Acc_Y, Acc_Z);		// UART 사용법
//                USART_PutString(USART1, buf); 
//                delay_ms(1);
//                
//                sprintf(buf,"%f %f %f\n", Distance_X, Distance_Y, Distance_Z);		// UART 사용법
//                USART_PutString(USART1, buf); 
//                delay_ms(1);
	}
}

void USART_Config(void)
{
	/*
		PORTA_Pin_8   USART3_TX   MCU1과 통신
		PORTA_Pin_9	  USART3_RX 
		PORTC_Pin_10  UART4_TX    IMU
		PORTC_Pin_11  UART4_RX                    
									*/

	GPIO_InitTypeDef GPIO_InitStructure;                    // GPIO  Type 재정의     
	USART_InitTypeDef USART_InitStructure;                  // USART Type 재정의
	
	/* Peripheral Clock Config */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);   // PORTA  사용
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);   // PORTC  사용
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);  // USART1 사용
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);   // UART4  사용

	/* Gpio Config */  
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);  // Tx 
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1); // Rx 
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_UART4);  // Tx 
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_UART4);  // Rx 

   
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9;           // USART1_TX 핀설정
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;         // 대체기능 사용
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;         // 내부풀업 사용
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        // 출력 타입 Push Poll
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;    // 출력 스피드 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;          // USART1_RX 핀설정
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;         // 대체기능 사용
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;         // 내부풀업 사용
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        // 출력 타입 Push Poll
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;    // 출력 스피드 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;          // USART4_TX 핀설정
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;         // 대체기능 사용
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;         // 내부풀업 사용
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        // 출력 타입 Push Poll
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;    // 출력 스피드 50MHz
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_11;          // USART4_RX 핀설정
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;         // 대체기능 사용
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;         // 내부풀업 사용
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        // 출력 타입 Push Poll
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;    // 출력 스피드 50MHz
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* USART Config */
	USART_InitStructure.USART_BaudRate   = 115200;                                   // 보레이트 설정
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;                      // 길이 8bit
	USART_InitStructure.USART_StopBits   = USART_StopBits_1;                         // stop bit 1
	USART_InitStructure.USART_Parity     = USART_Parity_No ;                         // parity 사용안함
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  // 흐름제어 사용안함
	USART_InitStructure.USART_Mode       = USART_Mode_Rx | USART_Mode_Tx;            // 모드 Rx/Tx 설정

	USART_Init(USART1, &USART_InitStructure);  // USART3에 설정 저장                                           
	USART_Init(UART4, &USART_InitStructure);   // UART4에 설정 저장                                       

	/* USART Enable */
	USART_Cmd(USART1, ENABLE);
	USART_Cmd(UART4, ENABLE);

}  

void USART_PutString(USART_TypeDef* USARTx, volatile char *s)
{
	while(*s)	// wait until data register is empty
	{
		while(!(USARTx->SR & 0x00000040));
		USART_SendData(USARTx, *s);
		*s++;
	}
}

void USART_PutChar(USART_TypeDef* USARTx, uint8_t Data)  
{  
	USART_SendData(USARTx, Data);  
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET){}  
}

char USART_ReceiveChar(USART_TypeDef* USARTx)
{
	char data;
	data=USART_ReceiveData(USARTx);
	return data;
}

void IMU_Read(void)
{
	USART_PutChar(UART4,'*');					// IMU에 데이터 요철
	for(Imu_Count=0;Imu_Count<22;Imu_Count++)	// IMU의 데이터 수신 
	{
		while(USART_GetFlagStatus(UART4, USART_FLAG_RXNE) == RESET){}
		All_Data[Imu_Count]=USART_ReceiveData(UART4);
	}
	Roll_data = (All_Data[n]<<8 | All_Data[n+1]);
	Pitch_data = (All_Data[n+2]<<8 | All_Data[n+3]);
	Yaw_data = (All_Data[n+4]<<8 | All_Data[n+5]);
        X = (All_Data[n+6]<<8 | All_Data[n+7]);
	Y = (All_Data[n+8]<<8 | All_Data[n+9]);
        Z = (All_Data[n+10]<<8 | All_Data[n+11]);
        Distance_X = (All_Data[n+12]<<8 | All_Data[n+13]);
        Distance_Y = (All_Data[n+14]<<8 | All_Data[n+16]);
        Distance_Z = (All_Data[n+17]<<8 | All_Data[n+18]);
        
	Roll_data /=100;
	Pitch_data /= 100;
	Yaw_data /=100;
        
        Acc_X = (double)X / 1000;
        Acc_Y = (double)Y / 1000;
        Acc_Z = (double)Z / 1000;
        
        Distance_X /= 1000;
        Distance_Y /= 1000;
        Distance_Z /= 1000;
        
//        USART_PutChar(UART4,'/');
        
//        sprintf(buf,"%c%c%c%c%c%c", '<', 'p', 'o', 's', 'z', '>');
//        USART_PutString(UART4, buf);
        
        Position_X += Acc_X*0.01;
        Position_Y += Acc_Y*0.01;
        Position_Z += Acc_Z*0.01;
        
}

int16_t complement(int16_t NUM)
{
    while(NUM & 0x80)
    {
        NUM = ~NUM;
        NUM += 1;
    }
    return NUM;
}

/////////////////////////// Delay 관련 함수 ///////////////////////////////
static void _delay_tick(unsigned long ulCount)
{
    __asm("    subs    r0, #1\n"
          "    bne.n   _delay_tick\n"
          "    bx      lr");
}
// micro second 단위로 delay
void delay_us(unsigned long us)
{
    _delay_tick(us * (168000000 / 3 / 1000000));
}
// mili second 단위로 delay
void delay_ms(unsigned long ms)
{
    delay_us(ms * 1000);
}