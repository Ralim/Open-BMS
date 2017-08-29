#include "main.h"

volatile uint32_t twoHzTimer = 0;
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;                 // Stop watchdog timer

    setup();
    //__bis_SR_register(LPM4_bits | GIE);       // Enter LPM4, interrupts enabled
    lcd_init();
    lcd_setCursor(0, 0);
    lcd_print("Open BMS by Ralim\r\n");
    TACTL = TASSEL_2 | ID_3 | MC_2 | TAIE;

    for (;;)
    {

        ISL94202_updateReadings();					//load in new I2C data
        volatile uint8_t i;   // volatile to prevent optimization
        P4OUT = ISL94202_getBalancingCells();//light an led if that cell is being balanced
        for (i = 0; i < 8; i++)
        {
            lcd_setCursor((i%2)*64, i/2+2);
            lcd_drawVoltage(ISL94202_getCellVoltageMV(i));
        }
        lcd_setCursor(0, 2);

        //we now have the voltages, print them to the lcd
        __bis_SR_register(LPM0_bits | GIE);    // Enter LPM0, interrupts enabled
        //We will wakup here once per second to update the display

    }

}

#pragma vector=PORT2_VECTOR
__interrupt void P2_IRQ(void)
{
    P4OUT ^= (~P2IN) & (BUTT1 | BUTT2 | BUTT3);
    P2IFG &= ~(BUTT1 | BUTT2 | BUTT3);
}

// Timer_A3 Interrupt Vector (TAIV) handler
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer_A(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A1_VECTOR))) Timer_A (void)
#else
#error Compiler not supported!
#endif
{
    switch (TAIV)
    // Efficient switch-implementation
    {
    case 2:
        break;                         // TACCR1 not used
    case 4:
        break;                         // TACCR2 not used
    case 10:
    {
        twoHzTimer++;                       // overflow
        if (twoHzTimer & 0x0001)
        {
            _BIC_SR(LPM0_EXIT);
        }
    }
        break;
    }
}

