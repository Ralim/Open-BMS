/*
 * i2c.h
 *
 *  Created on: 11Jun.,2017
 *      Author: Ben V. Brown
 *      Nicer I2C wrapper for dealing with devices that use 8 bits for internal address (such as small EEPROMs)
 */

#ifndef I2C_H_
#define I2C_H_
#include <msp430.h>
#include "hardware.h"
#include <stdint.h>
#include "TI_USCI_I2C_master.h"
#define PRESCALER 20

void setup_I2C();

uint8_t I2C_readReg8(uint8_t slave, uint8_t add);
uint16_t I2C_readReg16(uint8_t slave, uint8_t add);
void I2C_readMany(uint8_t slave, uint8_t startAddress, uint8_t count,
                  uint8_t* buffer);

void I2C_writeReg8(uint8_t slave, uint8_t add, uint8_t data);
void I2C_writeReg16(uint8_t slave, uint8_t add, uint16_t data);

#endif /* I2C_H_ */
