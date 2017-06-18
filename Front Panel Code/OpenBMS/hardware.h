/*
 * hardware.h
 *
 *  Created on: 11Jun.,2017
 *      Author: Ben V. Brown
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_
/*
 * Defines the hardware details such as IO pins etc
 * The hardware consists of :
 * 4 Green LEDs
 * 1 Red LED
 * 1 User button
 * I2C to the BMS
 * UART to computer (for upgrades and monitoring later on)
 * TN LCD to show the status of the system
 */

#define LED1_PIN (1<<5)
#define LED1_DIR (P2DIR|=LED1_PIN)
#define LED1_ON (P2OUT|=LED1_PIN)
#define LED1_OFF (P2OUT&=~LED1_PIN)

#define LED2_PIN (1<<0)
#define LED2_DIR (P2DIR|=LED2_PIN)
#define LED2_ON (P2OUT|=LED2_PIN)
#define LED2_OFF (P2OUT&=~LED2_PIN)

#define LED3_PIN (1<<1)
#define LED3_DIR (P2DIR|=LED3_PIN)
#define LED3_ON (P2OUT|=LED3_PIN)
#define LED3_OFF (P2OUT&=~LED3_PIN)

#define LED4_PIN (1<<2)
#define LED4_DIR (P2DIR|=LED4_PIN)
#define LED4_ON (P2OUT|=LED4_PIN)
#define LED4_OFF (P2OUT&=~LED4_PIN)

#define LED5_PIN (1<<0)
#define LED5_DIR (P3DIR|=LED5_PIN)
#define LED5_ON (P3OUT|=LED5_PIN)
#define LED5_OFF (P2OUT&=~LED5_PIN)



#endif /* HARDWARE_H_ */
