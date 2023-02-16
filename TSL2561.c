/*
 * TSL2561.c
 *
 *  Created on: Feb 11, 2023
 *      Author: acer
 */

#include "TSL2561.h"

HAL_StatusTypeDef TSL2561_Init(TSL2561* tsl, I2C_HandleTypeDef* userHandle, uint8_t sensorAddress)
{
	//Pass the I2C handle to the sensor struct
	tsl->i2cHandle = userHandle;

	//Pass the sensor address to the sensor struct
	tsl->address = sensorAddress << 1;

	//Power on sequence needs to be implemented!

	return HAL_OK;
}

HAL_StatusTypeDef TSL2561_WriteByte(TSL2561* tsl, uint8_t reg, uint8_t value)
{
	return HAL_I2C_Mem_Write(tsl->i2cHandle, tsl->address, reg, 1, &value, 1, TSL2561_MAX_DELAY);
}

HAL_StatusTypeDef TSL2561_ReadByte(TSL2561* tsl, uint8_t reg, uint8_t* value)
{
	return HAL_I2C_Mem_Read(tsl->i2cHandle, tsl->address, reg, 1, value, 1, TSL2561_MAX_DELAY);
}
