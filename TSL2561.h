/*
 * TSL2561.h
 *
 *  Created on: 11 February 2023
 *      Author: Emre Dur
 */

#ifndef TSL2561_I2C_DRIVER_H_
#define TSL2561_I2C_DRIVER_H_

//Include HAL Library by including the main header from the created project
#include "main.h"
#include "math.h"

/*
 * Defines
 */
// 8 bit address format

#define TSL2561_COMMAND_STATE_CMD   		0x80
#define TSL2561_COMMAND_STATE_CLEAR  		0x40
#define TSL2561_COMMAND_STATE_WORD  		0x20
#define TSL2561_COMMAND_STATE_BLOCK  		0x10
#define TSL2561_POWER_ON_STATE				0x03

#define TSL2561_MAX_DELAY 					HAL_MAX_DELAY

/*
 * Register Map
 */
#define TSL2561_REG_CONTROL					0x00
#define TSL2561_REG_TIMING					0x01
#define TSL2561_REG_THRESHLOWLOW			0x02
#define TSL2561_REG_THRESHLOWHIGH			0x03
#define TSL2561_REG_THRESHHIGHLOW			0x04
#define TSL2561_REG_THRESHHIGHHIGH			0x05
#define TSL2561_REG_INTERRUPT				0x06
#define TSL2561_REG_CRC						0x08
#define TSL2561_REG_ID						0x0A
#define TSL2561_REG_DATA0LOW				0x0C
#define TSL2561_REG_DATA0HIGH				0x0D
#define TSL2561_REG_DATA1LOW				0x0E
#define TSL2561_REG_DATA1HIGH				0x0F

/*
 * Sensor Struct
 */
typedef struct
{
	//I2C Handle used for the sensor
	I2C_HandleTypeDef* i2cHandle;

	//Sensor address
	uint8_t address;

} TSL2561;

/*
 * Library Functions
 */
HAL_StatusTypeDef TSL2561_Init(TSL2561* tsl, I2C_HandleTypeDef* userHandle, uint8_t sensorAddress);
HAL_StatusTypeDef TSL2561_GetLux(TSL2561* tsl, float* luxValue);

/*
 * Low Level Functions
 */
HAL_StatusTypeDef TSL2561_WriteByte(TSL2561* tsl, uint8_t reg, uint8_t value);
HAL_StatusTypeDef TSL2561_ReadByte(TSL2561* tsl, uint8_t reg, uint8_t* value);
HAL_StatusTypeDef TSL2561_ReadData(TSL2561* tsl, uint16_t* data0Val, uint16_t* data1Val);

#endif /* TSL2561_I2C_DRIVER_H_ */
