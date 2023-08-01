#include <msp430.h> 


int Bright[5] = {100, 300, 500, 700, 1000};
static int level = 2;

int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;      // Stop WDT
    _EINT();                      // Enable interrupts
    P2DIR &= ~(BIT1+BIT2);          // Ensure LED1 and LED2 are off.
    P2DIR |= BIT2;                  // Set P2.2 to output.
    P2SEL |= BIT2;                  // LED1 PWM.
    TBCTL |= TBSSEL_2 + MC_1;        // Timer B Clock Source: SMCLK
    TBCCTL1 |= OUTMOD_7;            //
    TBCCR1 = Bright[2];             //
    TBCCR0 = 1000;                  //10ms delay.


    P1IES |= BIT1+BIT0;                 // Falling edge triggers interrupt
    P1IFG &= ~(BIT1+BIT0);                  // Clear any pending interrupts
    P1IE |= BIT1+BIT0;                  // Enable interrupts on P1.0 and P1.1
    _BIS_SR(LPM0_bits + GIE);                      // Put system in low power mode 3


}

// Port 1 interrupt service routine
#pragma vector = PORT1_VECTOR
__interrupt void Port1_ISR (void)
{
    while(1)
    {
        if(P2IN&BIT0 == 0)
        {
            __delay_cycles(20000);
            if(level < 4)
            {
                level++;
            }
            P1IFG &= ~BIT0;               // P1IFG.BIT0 is cleared
        }

        if(P2IN&BIT1 == 0)
        {
            __delay_cycles(20000);
            if(level > 0)
            {
                level--;
            }
            P1IFG &= ~BIT1;               // P1IFG.BIT0 is cleared
        }
    }
}

#pragma vector = TIMERB1_VECTOR
__interrupt void timerISR(void)
{

    TBCCR1 ^= Bright[level];
    TBCCTL1 &= ~TBIFG;            // Clear interrupt flag.
}

/*#pragma vector = TIMERB0_VECTOR
__interrupt void timerISR(void)
{
    P2OUT ^= BIT1;                // Toggle LED2
}

#pragma vector = TIMERB1_VECTOR
__interrupt void timerISR2(void)
{
    P2OUT ^= BIT2;                // Toggle LED1
    TBCCTL1 &= ~BIT0;            // Clear interrupt flag
}*/










/*WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer

    // Setup Ports and Registers
    _EINT(); // Set GIE bit in SR
    P1DIR &= ~(BIT1+BIT2);          // Ensure LED1 and LED2 are off.
    P2DIR |= BIT2;                  // Set P2.2 to output
    P2SEL |= BIT2;                  // Select special function for P2.2 (TB1 Output)
    //TBCTL = MC_0;                 // Stop timer B while configuring
    TBCTL |= TBSSEL_2 + MC_1;        // Timer B Clock Source: SMCLK
    TBCCTL1 |= OUTMOD_7;            // Set Timer B1 to toggle reset/set output mode
    TBCCR1 = Bright[2];             // Set Timer B1 compare value
    TBCCR0 = 1000;                  //10ms delay.


    P1IES |= BIT1+BIT0; // Falling edge triggers interrupt
    P1IFG &= ~(BIT1+BIT0); // Clear any pending interrupts
    P1IE |= BIT1+BIT0; // Enable interrupts on P1.0 and P1.1
    _BIS_SR(LPM3); // Put system in low power mode 3

    //while(1)
    //{

       //TBCCR1 = Bright[level];
    //}*/
/*




    static unsigned int level = 2;
	static unsigned int SW1SW2 = 0;
    int i;

	for (i=10000;i>0;i--)// 100 ms delay allows both buttons to be pressed at "same" time
	{
	    //switch (P1IFG & (BIT1+BIT0))
	    //{
	        //case BIT0: // SW1 pressed, brightness increases
	    //for (i=10000;i>0;i--)
	    if (BIT0 == 0 && level < 4)
	    {
	        level++;
	        //TBCCR1 = brightness[level];
	        P1IFG &= ~BIT0;
	    }
	     // Clear P1.0 interrupt flag
	       // break;

	        //case BIT1: // SW2 pressed, brightness decreases
	    else if (BIT1 == 0 && level > 0)
	    {
	        level--;
	        //TBCCR1 = brightness[level];
	        P1IFG &= ~BIT1;
	    }
	     // Clear P1.1 interrupt flag
	    //for (int i=10000;i>0;i--)
	            //{
	                //if (SW2 == 0 && level > 0)
	                //{
	                    //if (level > 0) level--;
	                //}
	                //P1IFG &= ~BIT1; // Clear P1.1 interrupt flag
	            //break;
	        //case (BIT1+BIT0):
	     if (!(SW1SW2) && BIT0+BIT1 == 0)
	     {
	                //for (int i=10000;i>0;i--)
	                //{
	                    //if (SW1+SW2 == 0)
	                    //{
	         SW1SW2 = 1; // Set flag
	         WDTCTL ^= (WDT_ADLY_1000 ^ (WDTPW | WDTHOLD)); // Toggle necessary bits in WDTCTL to switch between stop mode and 1000 ms interval mode
	         P1IES &= ~(BIT1+BIT0); // Change interrupt trigger to rising edge to catch button release
	     }
	     else if ((SW1SW2) && BIT1+BIT0)
	     {
	                        //for (int i=10000;i>0;i--)
	                        //{
	                            //if ()
	                            //{
	         SW1SW2 = 0; // Clear flag
	         WDTCTL ^= (WDT_ADLY_1000 ^ (WDTPW | WDTHOLD)); // Toggle necessary bits in WDTCTL to switch between stop mode and 1000 ms interval mode
	         P1IES |= BIT1+BIT0; // Restore interrupt trigger to falling edge
	         P1IFG &= ~(BIT1+BIT0); // Clear interrupts
	     }
	                        //}
	                    //}
	                //}
	            //}
	         //P1IFG &= ~(BIT1+BIT0); // Clear interrupts
	            //break;
	    }
	    TBCCR1 = brightness[level];
}

#pragma vector=WDT_VECTOR
__interrupt void wdt_isr(void)
{
    TBCTL^= BIT4; // Toggling bit 4 switches timer B between stop mode and up mode
}*/

