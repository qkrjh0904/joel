/* Segway_Imu 관련 c파일*/
#include "stm32f4xx.h"
#include "segway_header.h"
#include <stdio.h>
#include <math.h>

int8_t SLAVE_ADDRESS = 0xD0; // the slave address 

int16_t Acc_x_H;	// 가속도 x의 H값
int16_t Acc_x_L;	// 가속도 x의 L값
int16_t Acc_y_H;	// 가속도 y의 H값
int16_t Acc_y_L;	// 가속도 y의 L값
int16_t Acc_z_H;	// 가속도 z의 H값
int16_t Acc_z_L;	// 가속도 z의 L값
int16_t Gyro_x_H;	// 자이로 x의 H값
int16_t Gyro_x_L;	// 자이로 x의 L값
int16_t Gyro_y_H;	// 자이로 y의 H값
int16_t Gyro_y_L;	// 자이로 y의 L값
int16_t Gyro_z_H;	// 자이로 z의 H값
int16_t Gyro_z_L;	// 자이로 z의 L값
int16_t ACC_X;		// 가속도 X값
int16_t ACC_Y;		// 가속도 Y값
int16_t ACC_Z;		// 가속도 Z값
int16_t GYRO_X;		// 자이로 X값
int16_t GYRO_Y;		// 자이로 Y값
int16_t GYRO_Z;		// 자이로 Z값

extern float Tim_Dt;	// 제어 주기, 적분 값

float Accel_Pitch;		// Degree로 변환된 가속도 Pitch값
float Accel_Roll;		// Degree로 변환된 가속도 Roll값
float Gyro_Pitch;		// 자이로 출력값을 각속도로 변환한 Pitch값
float Gyro_Roll;		// 자이로 출력값을 각속도로 변환한 Roll값
float Gyro_Angle_X;		// 최종 자이로 값
float Gyro_Angle_Y;		// 최종 자이로 값
float Angle_Pitch;		// Pitch 각도 값
float Angle_Roll;		// Roll 각도 값

void MPU9250_Config(void)
{
	if(i2c_read_register(0x75) == 0x71)	// MPU6050 Connection 확인 Who I AM = 0x71
	{	
		USART_puts(USART1, "Connetion\n");
	}
	i2c_write_register(PWR_MGMT_1,0x00);	// 0x6B -> Clear Sleep Mode
	i2c_write_register(CONFIG,0x03);		// 0x1A -> Configuration 1KHz Both
	i2c_write_register(SMPLRT_DIV,0x04);	// 0x19 -> Sample Rate Divider 200Hz Rate
	i2c_write_register(GYRO_CONFIG,0x00);	// 0x1B -> Gyro Configuration Scale +250dps
	i2c_write_register(ACCEL_CONFIG,0x00);	// 0x1C -> Accelerometer Configuration +-2g
	delay_us(10);
}

void IMU_Read(void)
{
	read_acc();		// 가속도 값 읽기
	read_gyro();	// 자이로 값 읽기
	cal_roll();		// Roll 각도 계산
	cal_pitch();	// Pitch 각도 계산
}

/* MPU6050데이터값 read */
void read_acc(void)
{
	SLAVE_ADDRESS = 0xD0;	// MPU6050 ADDRESS 0x01101000 SHIFT 0x11010000		
	Acc_x_H = i2c_read_register(ACCEL_XOUT_H)<<8;	// 0x3B -> 가속도 상위 8비트
	Acc_x_L = i2c_read_register(ACCEL_XOUT_L);		// 0x3C -> 가속도 하위 8비트
	Acc_y_H = i2c_read_register(ACCEL_YOUT_H)<<8;	// 0x3D -> 가속도 상위 8비트
	Acc_y_L = i2c_read_register(ACCEL_YOUT_L);		// 0x3E -> 가속도 하위 8비트
	Acc_z_H = i2c_read_register(ACCEL_ZOUT_H)<<8;	// 0x3F -> 가속도 상위 8비트
	Acc_z_L = i2c_read_register(ACCEL_ZOUT_L);		// 0x40 -> 가속도 하위 8비트

	ACC_X=Acc_x_H | Acc_x_L;     // 가속도 X 값 ,하나의 데이터로 합침
	ACC_Y=Acc_y_H | Acc_y_L;     // 가속도 Y 값 ,하나의 데이터로 합침
	ACC_Z=Acc_z_H | Acc_z_L;     // 가속도 Z 값 ,하나의 데이터로 합침
}

void read_gyro(void)
{
	SLAVE_ADDRESS = 0xD0;	// MPU6050 ADDRESS 0x01101000 SHIFT 0x11010000		
	Gyro_x_H = i2c_read_register(GYRO_XOUT_H)<<8; // 0x43 -> 자이로 상위 8비트
	Gyro_x_L = i2c_read_register(GYRO_XOUT_L);    // 0x44 -> 자이로 하위 8비트
	Gyro_y_H = i2c_read_register(GYRO_YOUT_H)<<8; // 0x45 -> 자이로 상위 8비트
	Gyro_y_L = i2c_read_register(GYRO_YOUT_L);    // 0x46 -> 자이로 하위 8비트
	Gyro_z_H = i2c_read_register(GYRO_ZOUT_H)<<8; // 0x47 -> 자이로 상위 8비트
	Gyro_z_L = i2c_read_register(GYRO_ZOUT_L);    // 0x48 -> 자이로 하위 8비트

	GYRO_X=Gyro_x_H | Gyro_x_L;  // 자이로 X 값 ,하나의 데이터로 합침
	GYRO_Y=Gyro_y_H | Gyro_y_L;  // 자이로 Y 값 ,하나의 데이터로 합침
	GYRO_Z=Gyro_z_H | Gyro_z_L;  // 자이로 Z 값 ,하나의 데이터로 합침
}

void cal_roll(void)
{
	Accel_Roll = (atan2(ACC_X, ACC_Z) * 180 / PI);			// 센서에 표기된 Y축(=Roll로 사용), 라디안 값을 Degree로 변환
	Gyro_Roll = (GYRO_Y/131.0);								// 자이로 -32767~+32768을 실제 250degree/s로 변환
	Gyro_Angle_Y = Angle_Roll + (Tim_Dt*Gyro_Roll);			// 변화량을 적분 
	Angle_Roll  = (0.95*Gyro_Angle_Y + 0.05*Accel_Roll);	// 상보필터,자이로와 가속도 값에 곱하는 값은 둘다 합쳐 1을 넘지 않아야 함

}

void cal_pitch(void)
{
	Accel_Pitch = (atan2(ACC_Y, ACC_Z) * 180 / PI);			// 센서에 표기된 x축(=Pitch로 사용)
	Gyro_Pitch = (GYRO_X/131.0);							// 자이로 -32767~+32768을 실제 250degree/s로 변환
	Gyro_Angle_X = Angle_Pitch + (Tim_Dt*Gyro_Pitch);		// 변화량을 적분 
	Angle_Pitch = (0.95*Gyro_Angle_X + 0.05*Accel_Pitch);	// 상보필터,자이로와 가속도 값에 곱하는 값은 둘다 합쳐 1을 넘지 않아야 함
}
