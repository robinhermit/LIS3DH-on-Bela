#include "I2C_LIS3DH.h"
#include <iostream>
#include <sys/ioctl.h>


// --------------------------------------------------------------------------------------- //
// ------------------------------ I2C_LIS3DH -------------------------------------------- //
// --------------------------------------------------------------------------------------- //
I2C_LIS3DH::I2C_LIS3DH(){

}

bool I2C_LIS3DH::begin(uint8_t bus, uint8_t i2caddr){

	_i2c_address = i2caddr;

	if(initI2C_RW(bus, i2caddr, 0) > 0) return false;
	
	// Read the WHO_AM_I register, this is a good test of communication
	uint8_t c = readRegister8(WHO_AM_I);  // 
	rt_printf("LIS3DH: I AM 0x%X, I Should Be 0x33\n",c);
	
	if(c != 0x33){ //the response is got in this register
	    rt_printf("Could not connect to LIS3DH: 0x%X\n",c);
		return false;
	}

	writeRegister(CTRL_REG1, 0b10010111); // [3] is 0 (check appnote)
	writeRegister(CTRL_REG4, 0b10001000); // ODR3, 1, ODR2, 0, ODR1, 0, ODR0, 1, [3], 1 
	
	// display.display();
	usleep(1000000); 	
	rt_printf("LIS3DH initialized for active data mode....\n"); // Initialize device for active mode read of acclerometer, gyroscope, and temperature

	return true;
}

/*********************************************************************/

uint8_t I2C_LIS3DH::readRegister8(uint8_t reg) {
	i2c_char_t value;
	readRegisters(reg, (i2c_char_t*)&value, sizeof(value));
	return value;
}

uint16_t I2C_LIS3DH::readRegister16(uint8_t reg) {
	i2c_char_t inbuf[2];
	readRegisters(reg, inbuf, sizeof(inbuf));
	return (uint16_t)inbuf[0] | (((uint16_t)inbuf[1]) << 8);
}

/**************************************************************************/
/*!
    @brief  Writes 8-bits to the specified destination register
*/
/**************************************************************************/
void I2C_LIS3DH::writeRegister(uint8_t reg, uint8_t value) {
	writeRegisters(reg, (i2c_char_t*)&value, sizeof(value));
}

uint16_t I2C_LIS3DH::readX() {
	uint8_t L = readRegister8(OUT_X_L | 0x80);
	uint8_t H = readRegister8(OUT_X_H | 0x80);
	return (uint16_t)L | (((uint16_t)H) << 8);
}
uint16_t I2C_LIS3DH::readY() {
	uint8_t L = readRegister8(OUT_Y_L | 0x80);
	uint8_t H = readRegister8(OUT_Y_H | 0x80);
	return (uint16_t)L | (((uint16_t)H) << 8);
}
uint16_t I2C_LIS3DH::readZ() {
	uint8_t L = readRegister8(OUT_Z_L | 0x80);
	uint8_t H = readRegister8(OUT_Z_H | 0x80);
	return (uint16_t)L | (((uint16_t)H) << 8);
}

/*
void I2C_LIS3DH::readAccelData(int16_t * destination){
	uint8_t rawData[6];  // x/y/z accel register data stored here
	readRegisters(OUT_X_H, 6, &rawData[0]);  // Read the six raw data registers into data array
	destination[0] = (((int16_t)rawData[0]) << 8) | rawData[1];
	destination[1] = (((int16_t)rawData[2]) << 8) | rawData[3];
	destination[2] = (((int16_t)rawData[4]) << 8) | rawData[5];
}
*/