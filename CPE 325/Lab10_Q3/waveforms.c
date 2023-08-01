#include <msp430.h>
#include <waves_lut_512.h>  /*512 samples are stored in this table */

#define   SW1_PRESSED ((BIT0&P1IN)==0)
#define   SW2_PRESSED ((BIT1&P1IN)==0)

void TimerA_setup(void)
{
    TACTL = TASSEL_2 + MC_1;              // SMCLK, up mode
    TACCR0 = 68;                         // Sets Timer Freq, 30Hz (1048576*0.0333sec/512)
    TACCTL0 = CCIE;                       // CCR0 interrupt enabled
}

void DAC_setup(void)
{
    ADC12CTL0 = REF2_5V + REFON;          // Turn on 2.5V internal ref voltage
    unsigned int i = 0;
    for (i = 50000; i > 0; i--);            // Delay to allow Ref to settle
    DAC12_0CTL = DAC12IR + DAC12AMP_5 + DAC12ENC;   //Sets DAC12
}

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer.
	TimerA_setup();             // Set timer to uniformly distribute the samples
	DAC_setup();               // Setup DAC
	unsigned int i = 0;
	
	while (1)
	{
	    __bis_SR_register(LPM0_bits + GIE); // Enter LPM0, interrupts enabled

	    if(SW1_PRESSED)
	    {
	        if(i>255)
	        {
	            DAC12_0DAT = (512-i);
	        }
	        else
	        {
	            DAC12_0DAT = i;
	        }
	    }
	    else
	    {
	        DAC12_0DAT = WAVELUT512[i];
	    }

	    if(SW2_PRESSED)
	    {
	        TACCR0 = 34;
	    }
	    else
	    {
	        TACCR0 = 68;
	    }

	    i=(i+1)%512;
	}
}

#pragma vector = TIMERA0_VECTOR
__interrupt void TA0_ISR(void)
{
    __bic_SR_register_on_exit(LPM0_bits);  // Exit LPMx, interrupts enabled
}
