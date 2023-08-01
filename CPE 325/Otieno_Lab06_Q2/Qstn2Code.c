#include <msp430.h>
#define   SW1_PRESSED ((BIT0&P1IN)==0)
#define   SW2_PRESSED ((BIT1&P1IN)==0)

void main(void)
{
    WDTCTL = WDTPW+WDTHOLD;         // Stop WDT

    FLL_CTL0 |= XCAP18PF;          // Set load capacitance for xtal
    SCFI0 |= FN_2;                 // DCO range control
    SCFQCTL = 63;                  // (63+1) x 32768 = ~2Mhz
    P2DIR |= BIT1;                  // Set LED1 as output

    _EINT();                        // enable interrupts
    P1IE |= BIT0+BIT1;                   // P1.0 interrupt enabled
    P1IES |= BIT0+BIT1;                  // P1.0 hi/low edge
    P1IFG &= ~BIT0+BIT1;                 // P1.0 IFG cleared


    for(;;)
    {
        __delay_cycles(1048576);
        P2OUT ^= BIT1;             // LED1 is turned off
    }
}

//Port 1 interrupt service routine
#pragma vector = PORT1_VECTOR
__interrupt void Port1_ISR (void)
{
    P1IFG &= ~(BIT0+BIT1);               // P1.0 IFG cleared
    if(SW1_PRESSED)
    {
        SCFQCTL = 127;               // (127+1) x 32768 = ~4Mhz
    }
    else if(SW2_PRESSED)
    {
        SCFQCTL = 255;              // (255+1) x 32768 = ~8Mhz
    }
}
