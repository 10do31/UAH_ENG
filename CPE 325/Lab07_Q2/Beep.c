#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDT_ADLY_1000;           // WDT = 1000ms.

	_EINT();                        // Enable interrupts.
	P2DIR |= BIT2;                   // Set LED 1 dir port (P2.2)
	P2OUT |= BIT2;                  // LED 1 output.
	IE1   |= WDTIE;                  // Enable WDT interrupts
	P3DIR |= BIT5;                  // 3.5 for buzzer.
	P3SEL |= BIT5;                  // Select special function for P2.2 (TB4 Output)
	TBCTL |= TBSSEL_2 + MC_1;       // Timer B Clock Source: SMCLK
	TBCCTL4 |= OUTMOD_4;            // Set Timer B4 to output.
	TBCCR0 = 500;                   // Sets buzzer frequency to 1 KHz
	LPM0;                           // Put system in low power mode 0

	return 0;
}

#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void)
{
	    P2OUT ^= BIT2;              // Toggle LED1.
	    P3SEL ^= BIT5;              // Buzzer at P3.5.
}
