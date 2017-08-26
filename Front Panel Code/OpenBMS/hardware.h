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
 * 8 Status LEDs
 * 3 User buttons
 * I2C to the BMS
 * TN LCD to show the status of the system
 */


#define MOSI (1<<4)
#define MISO (1<<5)
#define SCK  (1<<0)
#define LCD_RS (1<<6)
#define LCD_CS (1<<7)
#define LCD_RESET (1<<7)

#define ISL_INT (1<<0) /*General IRQ from the ISL*/
#define ISL_FETS_OFF (1<<1) /*If driven high turns off output*/
#define ISL_SD (1<<2) /*Shutdown - if low then output is off*/

#define BUTT1 (1<<5)
#define BUTT2 (1<<6)
#define BUTT3 (1<<7)


#endif /* HARDWARE_H_ */
