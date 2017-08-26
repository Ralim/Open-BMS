/*
 * UC1701.c
 *
 *  Created on: 26Aug.,2017
 *      Author: ralim
 */
#include "UC1701.h"
#include "font.h"
uint8_t lcd_column, lcd_line;
const uint8_t lcd_height = 64;
const uint8_t lcd_width = 128;
void lcd_init()
{
    SPI_init();
    LCD_CS_HIGH();
    LCD_CD_HIGH();
    // Set the LCD parameters...
    lcd_sendCommand(0xE2);  //System Reset
    lcd_sendCommand(0x40); // Set display start line to 0
    lcd_sendCommand(0xA1); //Set SEG Direction
    lcd_sendCommand(0xC0); //Set COM Direction
    lcd_sendCommand(0xA2); //Set Bias = 1/9
    lcd_sendCommand(0x2C);  //Boost ON
    lcd_sendCommand(0x2E); //Voltage Regular On
    lcd_sendCommand(0x2F); //Voltage Follower On
    lcd_sendCommand(0xF8); //Set booster ratio to
    lcd_sendCommand(0x00); //4x
    lcd_sendCommand(0x23); //Set Resistor Ratio = 3
    lcd_sendCommand(0x81);
    lcd_sendCommand(50); //Set Electronic Volume = 40
    lcd_sendCommand(0xAC); //Set Static indicator off
    lcd_sendCommand(0x00);
    lcd_sendCommand(0XA6); // Disable inverse
    lcd_sendCommand(0xAF); //Set Display Enable
    __delay_cycles(100000);
    lcd_sendCommand(0xA5); //display all points
    __delay_cycles(100000);
    __delay_cycles(100000);
    lcd_sendCommand(0xA4); //normal display

    lcd_clear();
}

void lcd_setCursor(uint8_t column, uint8_t line)
{
    uint8_t i, j;
    column = column + 4;
    lcd_column = column;
    lcd_line = line;

    i = (column & 0xF0) >> 4;
    j = column & 0x0F;

    lcd_sendCommand(0xb0 + line);
    lcd_sendCommand(0x10 + i);
    lcd_sendCommand(j);
}

void lcddrawColumn(unsigned char lines, unsigned char value)
{
    unsigned char scolumn = lcd_column;
    unsigned char sline = lcd_line;

    // Keep "value" within range...
    if (value > lines * 8)
    {
        value = lines * 8;
    }

    // Find the line where "value" resides...
    unsigned char mark = (lines * 8 - 1 - value) / 8;

    // Clear the lines above the mark...
    for (unsigned char line = 0; line < mark; line++)
    {
        lcd_setCursor(scolumn, sline + line);
        lcd_sendData(0x00);
    }

    // Compute the byte to draw at the "mark" line...
    unsigned char b = 0xff;
    for (unsigned char i = 0; i < lines * 8 - mark * 8 - value; i++)
    {
        b <<= 1;
    }

    lcd_setCursor(scolumn, sline + mark);
    lcd_sendData(b);

    // Fill the lines below the mark...
    for (unsigned char line = mark + 1; line < lines; line++)
    {
        lcd_setCursor(scolumn, sline + line);
        lcd_sendData(0xff);
    }

    // Leave the cursor in a consistent position...
    lcd_setCursor(scolumn + 1, sline);
}
void lcd_clear()
{
    uint8_t i, j;
    for (j = 0; j < 8; j++)
    {
        lcd_setCursor(0, j);
        for (i = 0; i < 132; i++)
        {
            lcd_sendData(0x00);
        }
    }

    lcd_setCursor(0, 0);
}

void lcd_sendData(uint8_t d)
{
    LCD_CS_LOW();
    LCD_CD_HIGH();
    SPI_tx(d);
    //LCD_CS_HIGH();

}
void lcd_sendCommand(uint8_t d)
{
    LCD_CS_LOW();
    LCD_CD_LOW();
    SPI_tx(d);
    //LCD_CS_HIGH();
}
void lcd_printChar(char chr)
{
    // ASCII 7-bit only...
    if (chr >= 0x80)
    {
        return;
    }
    if (chr == '\r')
    {
        lcd_setCursor(0, lcd_line);
        return;
    }
    else if (chr == '\n')
    {
        lcd_setCursor(lcd_column, lcd_line + 1);
        return;
    }
    // Output one column at a time...
    for (unsigned char i = 0; i < 5; i++)
    {
        lcd_sendData(charset[chr - ' '][i]);
    }

    // One column between characters...
    lcd_sendData(0x00);

    // Update the cursor position...
    lcd_column = (lcd_column + 6) % lcd_width;

    if (lcd_column == 0)
    {
        lcd_line = (lcd_line + 1) % (lcd_height / 9 + 1);
    }

}
void lcd_print(char* string)
{
    while (string[0])
    {
        lcd_printChar (string[0]);
        string++;
    }
}
