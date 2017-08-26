/*
 * setup.c
 *
 *  Created on: 11Jun.,2017
 *      Author: Ben V. Brown
 */

#include "setup.h"
void setup_GPIO();
//Setup all hardware peripherals as required
void setup()
{
    //Setup clock to 1MHz for lower power usage

    DCOCTL = 0;                          // Select lowest DCOx and MODx settings
    //BCSCTL1 = CALBC1_1MHZ;                    // Set DCO to 8MHz
    //DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = 0x87;
    DCOCTL = 0x20;
    //System should now be running with SMCLK=DCO=1MHz
    setup_GPIO();
    //Sets up the GPIO to the correct directions and states
    //Sets up the UART at 115200 baud 8N1
    setup_I2C();
    _EINT();
}

void setup_GPIO()
{
    //Setting up all the GPIO pins
    P2SEL &= ~(BIT6 | BIT7);    //enable XIN,XOUT as normal GPIO instead

    P1DIR = LCD_RESET;
    P1OUT = LCD_RESET;
    P2DIR = 0x00;
    P2DIR |= ISL_FETS_OFF;
    P2OUT = 0x00;
    P3DIR = MOSI | SCK | LCD_CS | LCD_RS;
    P3OUT = 0x00;
    P4DIR = 0xFF;
    P4OUT = 0x01;
    P2IES = BUTT1 | BUTT2 | BUTT3;    //falling edge
    P2IFG = 0x00;    //ensure irq flags are reset first
    P2IE |= BUTT1 | BUTT2 | BUTT3;
    P2OUT |= BUTT1 | BUTT2 | BUTT3;    //set to pullup
    P2REN |= BUTT1 | BUTT2 | BUTT3;    //enable pullup/down
}
