#include "main.h"
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer
    setup();
    //__bis_SR_register(LPM4_bits | GIE);       // Enter LPM4, interrupts enabled

    for (;;)
    {
        volatile unsigned int i;	// volatile to prevent optimization

        P2OUT ^= 1 << 5 | 1 << 0 | 1 << 1 | 1 << 2;	// Toggle P1.0 using exclusive-OR
        P3OUT ^= 1 << 0;
        i = 10000;					// SW Delay
        do
            i--;
        while (i != 0);

        ISL94202_updateReadings();					//load in new I2C data
        volatile uint16_t voltages[9];
        for (i = 0; i < 8; i++)
            voltages[i] = ISL94202_getCellVoltageMV(i);

        DEBUG_BREAK;

    }

}

