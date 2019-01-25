/* Segway_Imu ���� c����*/
#include "stm32f4xx.h"
#include "segway_header.h"
#include <stdio.h>
#include <math.h>

int8_t SLAVE_ADDRESS = 0xD0; // the slave address 

int16_t Acc_x_H;	// ���ӵ� x�� H��
int16_t Acc_x_L;	// ���ӵ� x�� L��
int16_t Acc_y_H;	// ���ӵ� y�� H��
int16_t Acc_y_L;	// ���ӵ� y�� L��
int16_t Acc_z_H;	// ���ӵ� z�� H��
int16_t Acc_z_L;	// ���ӵ� z�� L��
int16_t Gyro_x_H;	// ���̷� x�� H��
int16_t Gyro_x_L;	// ���̷� x�� L��
int16_t Gyro_y_H;	// ���̷� y�� H��
int16_t Gyro_y_L;	// ���̷� y�� L��
int16_t Gyro_z_H;	// ���̷� z�� H��
int16_t Gyro_z_L;	// ���̷� z�� L��
int16_t ACC_X;		// ���ӵ� X��
int16_t ACC_Y;		// ���ӵ� Y��
int16_t ACC_Z;		// ���ӵ� Z��
int16_t GYRO_X;		// ���̷� X��
int16_t GYRO_Y;		// ���̷� Y��
int16_t GYRO_Z;		// ���̷� Z��

extern float Tim_Dt;	// ���� �ֱ�, ���� ��

float Accel_Pitch;		// Degree�� ��ȯ�� ���ӵ� Pitch��
float Accel_Roll;		// Degree�� ��ȯ�� ���ӵ� Roll��
float Gyro_Pitch;		// ���̷� ��°��� ���ӵ��� ��ȯ�� Pitch��
float Gyro_Roll;		// ���̷� ��°��� ���ӵ��� ��ȯ�� Roll��
float Gyro_Angle_X;		// ���� ���̷� ��
float Gyro_Angle_Y;		// ���� ���̷� ��
float Angle_Pitch;		// Pitch ���� ��
float Angle_Roll;		// Roll ���� ��

void MPU9250_Config(void)
{
	if(i2c_read_register(0x75) == 0x71)	// MPU6050 Connection Ȯ�� Who I AM = 0x71
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
	read_acc();		// ���ӵ� �� �б�
	read_gyro();	// ���̷� �� �б�
	cal_roll();		// Roll ���� ���
	cal_pitch();	// Pitch ���� ���
}

/* MPU6050�����Ͱ� read */
void read_acc(void)
{
	SLAVE_ADDRESS = 0xD0;	// MPU6050 ADDRESS 0x01101000 SHIFT 0x11010000		
	Acc_x_H = i2c_read_register(ACCEL_XOUT_H)<<8;	// 0x3B -> ���ӵ� ���� 8��Ʈ
	Acc_x_L = i2c_read_register(ACCEL_XOUT_L);		// 0x3C -> ���ӵ� ���� 8��Ʈ
	Acc_y_H = i2c_read_register(ACCEL_YOUT_H)<<8;	// 0x3D -> ���ӵ� ���� 8��Ʈ
	Acc_y_L = i2c_read_register(ACCEL_YOUT_L);		// 0x3E -> ���ӵ� ���� 8��Ʈ
	Acc_z_H = i2c_read_register(ACCEL_ZOUT_H)<<8;	// 0x3F -> ���ӵ� ���� 8��Ʈ
	Acc_z_L = i2c_read_register(ACCEL_ZOUT_L);		// 0x40 -> ���ӵ� ���� 8��Ʈ

	ACC_X=Acc_x_H | Acc_x_L;     // ���ӵ� X �� ,�ϳ��� �����ͷ� ��ħ
	ACC_Y=Acc_y_H | Acc_y_L;     // ���ӵ� Y �� ,�ϳ��� �����ͷ� ��ħ
	ACC_Z=Acc_z_H | Acc_z_L;     // ���ӵ� Z �� ,�ϳ��� �����ͷ� ��ħ
}

void read_gyro(void)
{
	SLAVE_ADDRESS = 0xD0;	// MPU6050 ADDRESS 0x01101000 SHIFT 0x11010000		
	Gyro_x_H = i2c_read_register(GYRO_XOUT_H)<<8; // 0x43 -> ���̷� ���� 8��Ʈ
	Gyro_x_L = i2c_read_register(GYRO_XOUT_L);    // 0x44 -> ���̷� ���� 8��Ʈ
	Gyro_y_H = i2c_read_register(GYRO_YOUT_H)<<8; // 0x45 -> ���̷� ���� 8��Ʈ
	Gyro_y_L = i2c_read_register(GYRO_YOUT_L);    // 0x46 -> ���̷� ���� 8��Ʈ
	Gyro_z_H = i2c_read_register(GYRO_ZOUT_H)<<8; // 0x47 -> ���̷� ���� 8��Ʈ
	Gyro_z_L = i2c_read_register(GYRO_ZOUT_L);    // 0x48 -> ���̷� ���� 8��Ʈ

	GYRO_X=Gyro_x_H | Gyro_x_L;  // ���̷� X �� ,�ϳ��� �����ͷ� ��ħ
	GYRO_Y=Gyro_y_H | Gyro_y_L;  // ���̷� Y �� ,�ϳ��� �����ͷ� ��ħ
	GYRO_Z=Gyro_z_H | Gyro_z_L;  // ���̷� Z �� ,�ϳ��� �����ͷ� ��ħ
}

void cal_roll(void)
{
	Accel_Roll = (atan2(ACC_X, ACC_Z) * 180 / PI);			// ������ ǥ��� Y��(=Roll�� ���), ���� ���� Degree�� ��ȯ
	Gyro_Roll = (GYRO_Y/131.0);								// ���̷� -32767~+32768�� ���� 250degree/s�� ��ȯ
	Gyro_Angle_Y = Angle_Roll + (Tim_Dt*Gyro_Roll);			// ��ȭ���� ���� 
	Angle_Roll  = (0.95*Gyro_Angle_Y + 0.05*Accel_Roll);	// ������,���̷ο� ���ӵ� ���� ���ϴ� ���� �Ѵ� ���� 1�� ���� �ʾƾ� ��

}

void cal_pitch(void)
{
	Accel_Pitch = (atan2(ACC_Y, ACC_Z) * 180 / PI);			// ������ ǥ��� x��(=Pitch�� ���)
	Gyro_Pitch = (GYRO_X/131.0);							// ���̷� -32767~+32768�� ���� 250degree/s�� ��ȯ
	Gyro_Angle_X = Angle_Pitch + (Tim_Dt*Gyro_Pitch);		// ��ȭ���� ���� 
	Angle_Pitch = (0.95*Gyro_Angle_X + 0.05*Accel_Pitch);	// ������,���̷ο� ���ӵ� ���� ���ϴ� ���� �Ѵ� ���� 1�� ���� �ʾƾ� ��
}
