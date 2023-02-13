/*
 LIS3DH Basic Example Code
 */

#pragma once

#include <I2c.h>
#include "Utilities.h"
#include <cmath>
#include <chrono>

// Define registers per LIS3DH

#define LIS3DH_DEFAULT_ADDRESS (0x18)

#define STATUS_REG_AUX   0x07
#define OUT_ADC1_L       0x08
#define OUT_ADC1_H       0x09
#define OUT_ADC2_L       0x0A
#define OUT_ADC2_H   	 0x0B
#define OUT_ADC3_L		 0x0C
#define OUT_ADC3_H       0x0D
#define INT_COUNTER_REG  0x0E
#define WHO_AM_I         0x0F

#define TEMP_CFG_REG     0x1F  
#define CTRL_REG1        0x20  
#define CTRL_REG2        0x21  
#define CTRL_REG3        0x22 
#define CTRL_REG4        0x23
#define CTRL_REG5        0x24
#define CTRL_REG6        0x25
#define REFERENCE        0x26
#define STATUS_REG2      0x27
#define OUT_X_L          0x28
#define OUT_X_H          0x29
#define OUT_Y_L          0x2A
#define OUT_Y_H          0x2B
#define OUT_Z_L          0x2C
#define OUT_Z_H          0x2D
#define FIFO_CTRL_REG    0x2E
#define FIFO_SRC_REG     0x2F
#define INT1_CFG         0x30
#define INT1_SRC         0x31
#define INT1_THS         0x32
#define INT1_DURATION    0x33

#define CLICK_CFG        0x38
#define CLICK_SRC        0x39  
#define CLICK_THS        0x3A
#define TIME_LIMIT       0x3B
#define TIME_LATENCY     0x3C
#define TIME_WINDOW      0x3D
#define ACT_THS          0x3E
#define INACT_DUR        0x3F

// /** A structure to represent scales **/
// typedef enum {
//   LIS3DH_RANGE_16_G = 0b11, // +/- 16g
//   LIS3DH_RANGE_8_G = 0b10,  // +/- 8g
//   LIS3DH_RANGE_4_G = 0b01,  // +/- 4g
//   LIS3DH_RANGE_2_G = 0b00   // +/- 2g (default value)
// } lis3dh_range_t;

// /** A structure to represent axes **/
// typedef enum {
//   LIS3DH_AXIS_X = 0x0,
//   LIS3DH_AXIS_Y = 0x1,
//   LIS3DH_AXIS_Z = 0x2,
// } lis3dh_axis_t;

// /** Used with register 0x2A (LIS3DH_REG_CTRL_REG1) to set bandwidth **/ //WHAT THE FUVK
// typedef enum {
//   LIS3DH_DATARATE_400_HZ = 0b0111, //  400Hz
//   LIS3DH_DATARATE_200_HZ = 0b0110, //  200Hz
//   LIS3DH_DATARATE_100_HZ = 0b0101, //  100Hz
//   LIS3DH_DATARATE_50_HZ = 0b0100,  //   50Hz
//   LIS3DH_DATARATE_25_HZ = 0b0011,  //   25Hz
//   LIS3DH_DATARATE_10_HZ = 0b0010,  // 10 Hz
//   LIS3DH_DATARATE_1_HZ = 0b0001,   // 1 Hz
//   LIS3DH_DATARATE_POWERDOWN = 0,
//   LIS3DH_DATARATE_LOWPOWER_1K6HZ = 0b1000,
//   LIS3DH_DATARATE_LOWPOWER_5KHZ = 0b1001,
// } lis3dh_dataRate_t;


class I2C_LIS3DH : public I2c {
public:
	// Hardware I2C
	I2C_LIS3DH();

	bool begin(uint8_t bus = 1, uint8_t i2caddr = LIS3DH_DEFAULT_ADDRESS);

	uint16_t readX();
	uint16_t readY();
	uint16_t readZ();

//	void readAccelData(int16_t * destination);

	// void readAccelData(int16_t * destination);
	
	// int16_t readTempData();
	// void LowPowerAccelOnlyLIS3DH();
	// void initLIS3DH();


	// // Set initial input parameters
	// enum Ascale {
	// 	AFS_2G = 0,
	// 	AFS_4G,
	// 	AFS_8G,
	// 	AFS_16G
	// };
	

private:
	int _i2c_address;

	uint8_t readRegister8(uint8_t reg);
	uint16_t readRegister16(uint8_t reg);
    void writeRegister(uint8_t reg, uint8_t value);

	// Specify sensor full scale

	// uint8_t Ascale = AFS_2G;
	// float aRes; // scale resolutions per LSB for the sensors

	// int16_t accelCount[3];  // Stores the 16-bit signed accelerometer sensor output

	// float accelBias[3] = {0,0,0};      // Bias corrections for gyro and accelerometer

	// float pitch, yaw, roll;
	// float deltat = 0.0f;        // integration interval for both filter schemes

	// // Time of last update
	// std::chrono::time_point<std::chrono::high_resolution_clock> lastUpdateTime;

	// float ax, ay, az; // variables to hold latest sensor data values
};




