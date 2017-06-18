/*
 * uart.c
 *
 *  Created on: 11Jun.,2017
 *      Author: Ben V. Brown
 */
#include "uart.h"

void setup_UART()
{
    P3SEL = 0x30;                             // P3.4,5 = USCI_A0 TXD/RXD

    UCA0CTL1 |= UCSSEL_2;                     // SMCLK
    UCA0BR0 = 8;                              // 1MHz 115200
    UCA0BR1 = 0;                              // 1MHz 115200
    UCA0MCTL = UCBRS2 | UCBRS0;               // Modulation UCBRSx = 5
    UCA0CTL1 &= ~UCSWRST;                   // **Initialize USCI state machine**
    IE2 |= UCA0RXIE;                          // Enable USCI_A0 RX interrupt
}
#ifdef DISABLED
// Echo back RXed character, confirm TX buffer is ready first
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(USCIAB0RX_VECTOR))) USCI0RX_ISR (void)
#else
#error Compiler not supported!
#endif
{
    while (!(IFG2 & UCA0TXIFG))
        ;                // USCI_A0 TX buffer ready?
    UCA0TXBUF = UCA0RXBUF;                    // TX -> RXed character
}

#endif
