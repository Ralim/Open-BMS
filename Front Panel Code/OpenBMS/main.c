#include "main.h"
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;                 // Stop watchdog timer

    setup();
    //__bis_SR_register(LPM4_bits | GIE);       // Enter LPM4, interrupts enabled
    lcd_init();
    lcd_setCursor(0, 0);
    lcd_print("Open BMS by Ralim\r\n");

    for (;;)
    {

        P4OUT++;
        ISL94202_updateReadings();					//load in new I2C data
        volatile uint16_t voltages[8];
        volatile uint8_t i;   // volatile to prevent optimization

        for (i = 0; i < 8; i++)
        {
            voltages[i] = ISL94202_getCellVoltageMV(i);
        }
        //we now have the voltages, print them to the lcd
        volatile uint32_t d = 5000;                    // SW Delay
        do
            d--;
        while (d != 0);
    }

}

#pragma vector=PORT2_VECTOR
__interrupt void P2_IRQ(void)
{
    P4OUT ^= (~P2IN) & (BUTT1 | BUTT2 | BUTT3);
    P2IFG &= ~(BUTT1 | BUTT2 | BUTT3);
}
