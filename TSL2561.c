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

	//Power on sequence
	return TSL2561_WriteByte(tsl, TSL2561_COMMAND_STATE_CMD | TSL2561_REG_CONTROL, TSL2561_POWER_ON_STATE);

}

HAL_StatusTypeDef TSL2561_BasicRead(TSL2561* tsl, uint16_t* value)
{
	uint8_t data0Low, data0High;
	TSL2561_ReadByte(tsl, (TSL2561_COMMAND_STATE_CMD|TSL2561_REG_DATA0LOW),	&data0Low);
	TSL2561_ReadByte(tsl, (TSL2561_COMMAND_STATE_CMD|TSL2561_REG_DATA0HIGH), &data0High);

	*value = data0High * 256 + data0Low;

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
