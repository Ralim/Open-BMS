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
    BCSCTL1 = CALBC1_1MHZ;               // Set DCO
    DCOCTL = CALDCO_1MHZ;
    //System should now be running with SMCLK=DCO=1MHz
    setup_GPIO();
    //Sets up the GPIO to the correct directions and states
    //setup_UART();
    //Sets up the UART at 115200 baud 8N1
    setup_I2C();
    _EINT();
}

void setup_GPIO()
{
    //Setting up all the GPIO pins
    P1DIR = 0xFF;
    P1OUT = 0x00;
    P2DIR = 0xFF;
    P2OUT = 0x00;
    P3DIR = 0xFF;
    P3OUT = 0x00;
    P4DIR = 0xFF;
    P4OUT = 0x00;
    //Enable the outputs for the LEDs
    LED1_DIR;
    LED2_DIR;
    LED3_DIR;
    LED4_DIR;
    LED5_DIR;
    LED1_OFF;
    LED2_OFF;
    LED3_OFF;
    LED4_OFF;
    LED5_ON;        //red led on while starting up

    //GPIO setup done
}
