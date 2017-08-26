/*
 * spi.h
 *
 *  Created on: 26Aug.,2017
 *      Author: ralim
 */

#ifndef SPI_H_
#define SPI_H_
#include <msp430.h>
#include <stdint.h>
#include "hardware.h"

void SPI_init();
void SPI_tx(uint8_t data);

#endif /* SPI_H_ */
