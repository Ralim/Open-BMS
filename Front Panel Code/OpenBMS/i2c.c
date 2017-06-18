/*
 * i2c.c
 *
 *  Created on: 11Jun.,2017
 *      Author: Ben V. Brown
 */

#include "i2c.h"

//Setup the hardware for I2C communications
void setup_I2C()
{

}
uint8_t I2C_readReg8(uint8_t slave, uint8_t add)
{
    uint8_t ret = 0;
    TI_USCI_I2C_transmitinit(slave, PRESCALER);  // init transmitting with USCI
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
                  // initialization
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
    TI_USCI_I2C_transmit(1, &add);       // start transmitting
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free

    TI_USCI_I2C_receiveinit(slave, PRESCALER);   // init receiving with USCI
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
    TI_USCI_I2C_receive(1, &ret);
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free

    return ret;
}

uint16_t I2C_readReg16(uint8_t slave, uint8_t add)
{
    uint16_t ret = 0;
    TI_USCI_I2C_transmitinit(slave, PRESCALER);  // init transmitting with USCI
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
                  // initialization
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
    TI_USCI_I2C_transmit(1, &add);       // start transmitting
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free

    TI_USCI_I2C_receiveinit(slave, PRESCALER);   // init receiving with USCI
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
    TI_USCI_I2C_receive(2, &ret);
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free

    return ret;
}
void I2C_readMany(uint8_t slave, uint8_t add, uint8_t count, uint8_t* buffer)
{
    uint16_t ret = 0;
    TI_USCI_I2C_transmitinit(slave, PRESCALER);  // init transmitting with USCI
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
                  // initialization
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
    TI_USCI_I2C_transmit(1, &add);       // start transmitting
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free

    TI_USCI_I2C_receiveinit(slave, PRESCALER);   // init receiving with USCI
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
    TI_USCI_I2C_receive(count, buffer);
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free

}

void I2C_writeReg8(uint8_t slave, uint8_t add, uint8_t data)
{
    TI_USCI_I2C_transmitinit(slave, PRESCALER);  // init transmitting with USCI
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
                  // initialization
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
    TI_USCI_I2C_transmit(1, &add);       // start transmitting
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
    TI_USCI_I2C_transmit(1, &data);       // start transmitting

}
void I2C_writeReg16(uint8_t slave, uint8_t add, uint16_t data)
{
    TI_USCI_I2C_transmitinit(slave, PRESCALER);  // init transmitting with USCI
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
                  // initialization
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
    TI_USCI_I2C_transmit(1, &add);       // start transmitting
    while (TI_USCI_I2C_notready())
        ;         // wait for bus to be free
    TI_USCI_I2C_transmit(2, &data);       // start transmitting

}
