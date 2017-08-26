/*
 * spi.c
 *
 *  Created on: 26Aug.,2017
 *      Author: ralim
 */

#include "spi.h"
#include <string.h>

void SPI_init()
{
    P3SEL |= 0x31;                            // P3.0,4,5 USCI_A0 option select
    UCA0CTL0 |= UCCKPL | UCMSB | UCMST | UCSYNC;    // 3-pin, 8-bit SPI master
    UCA0CTL1 |= UCSSEL_2;                           // SMCLK
    UCA0BR0 |= 0x01;                                // /1
    UCA0BR1 = 0;                                    //
    UCA0MCTL = 0;                                   // No modulation
    UCA0CTL1 &= ~UCSWRST;                   // **Initialize USCI state machine**
    //IE2 |= UCA0TXIE;                                //enable tx irq
}
void SPI_tx(uint8_t data)
{
    UCA0TXBUF = data;
    while ((UCA0STAT & UCBUSY));
    while (!(IFG2 & UCA0TXIFG));

}

