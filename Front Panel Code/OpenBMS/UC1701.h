/*
 * UC1701.h
 *
 *  Created on: 26Aug.,2017
 *      Author: ralim
 */

#ifndef UC1701_H_
#define UC1701_H_

#include "spi.h"
#include "hardware.h"
#define LCD_CS_LOW()    (P3OUT&=~LCD_CS)
#define LCD_CS_HIGH()   (P3OUT|=LCD_CS)
#define LCD_CD_LOW()    (P3OUT&=~LCD_RS)
#define LCD_CD_HIGH()   (P3OUT|=LCD_RS)
void lcd_init();
void lcd_clear();
void lcd_sendData(uint8_t d);
void lcd_sendCommand(uint8_t d);
void lcd_printChar(char c);
void lcd_setCursor(uint8_t column, uint8_t line);
void lcd_print(char* string);
void lcd_drawNumber(uint16_t number, uint8_t places);
void lcd_drawVoltage(uint16_t mV);

#endif /* UC1701_H_ */
