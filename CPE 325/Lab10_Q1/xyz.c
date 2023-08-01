#include <msp430.h>
#include <math.h>

volatile long int ADCXval, ADCYval, ADCZval;
volatile float Xper, Yper, Zper, aDev;

void TimerA_setup();
void UART_setup();
void sendData();
void UART_Send_Character(char);

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer.
	TimerA_setup();             // Setup timer to send ADC data.
	ADC_setup();                // Setup ADC.
	UART_setup();               // Setup UART for RS-232.
	
	P2DIR |= BIT1 + BIT2;         // P2.1 and P2.2 set up as output
	P2OUT &= ~(BIT1 + BIT2);      // ensure LED1 and LED2 are off
	_EINT();

	while (1)
	{
	    ADC12CTL0 |= ADC12SC;               // Start conversions
	    __bis_SR_register(LPM0_bits + GIE); // Enter LPM0
	}
}

#pragma vector = ADC12_VECTOR
__interrupt void ADC12ISR(void)
{
    ADCXval = ADC12MEM0;                  // Move results, IFG is cleared
    ADCYval = ADC12MEM1;
    ADCZval = ADC12MEM2;
    __bic_SR_register_on_exit(LPM0_bits); // Exit LPM0
}
#pragma vector = TIMERA0_VECTOR
__interrupt void timerA_ISR()
{
    sendData();                           // Send data to serial app
    __bic_SR_register_on_exit(LPM0_bits); // Exit LPM0
}

// Watchdog Timer interrupt service routine
#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void)
{
    P2OUT ^= BIT2;                    // Toggle P2.2 using exclusive-OR
}

void TimerA_setup(void)
{
    TACCR0 = 3277;                      // 3277/ 32768 Hz = 0.1s
    TACTL = TASSEL_1 + MC_1;            // ACLK, up mode
    TACCTL0 = CCIE;                     // Enabled interrupt
}

void UART_setup(void)
{
    P2SEL |= BIT4 + BIT5;               // Set up Rx and Tx bits
    UCA0CTL0 = 0;                       // Set up default RS-232 protocol
    UCA0CTL1 |= BIT0 + UCSSEL_2;        // Disable device, set clock
    UCA0BR0 = 27;                       // 1048576 Hz / 38400
    UCA0BR1 = 0;
    UCA0MCTL = 0x94;
    UCA0CTL1 &= ~BIT0;                  // Start UART device
}

void sendData(void)
{
    int i;
    Xper = ((ADCXval*3.0/4095-1.5)/0.3);    // Calculate percentage outputs
    Yper = ((ADCYval*3.0/4095-1.5)/0.3);
    Zper = ((ADCZval*3.0/4095-1.5)/0.3);
    aDev = atan(Xper/Zper)*180/3.141592;

    // Use character pointers to send one byte at a time
    char *xpointer=(char *)&Xper;
    char *ypointer=(char *)&Yper;
    char *zpointer=(char *)&Zper;

    UART_Send_Character(0x55);            // Send header
    for(i = 0; i < 4; i++)
    {            // Send x percentage - one byte at a time
        UART_Send_Character(xpointer[i]);
    }
    for(i = 0; i < 4; i++)
    {            // Send y percentage - one byte at a time
        UART_Send_Character(ypointer[i]);
    }
    for(i = 0; i < 4; i++)
    {            // Send y percentage - one byte at a time
        UART_Send_Character(zpointer[i]);
    }

    if(aDev > 15)
    {
        WDTCTL = WDT_MDLY_32;           // 1 s interval timer
        //LED1 ON; LED2 OFF.
        P2OUT |= BIT2;
        P2OUT &= ~BIT1;
    }
    else if(aDev < (-1*15))
    {
        WDTCTL = WDT_MDLY_32;
        //LED2 ON; LED1 OFF.
        P2OUT |= BIT1;
        P2OUT &= ~BIT2;
    }
    else if(aDev > (-1*15) && aDev < 15)
    {
        //LED1 OFF; LED2 OFF.
        P2OUT &= ~(BIT1 + BIT2);
    }
}

void UART_Send_Character(char my_char)
{
    while(!(IFG2&UCA0TXIFG));   // Wait until can transmit.
    UCA0TXBUF = my_char;        // Tx Buffer gets my_char variable.
}

void ADC_setup(void)
{
    int i =0;

    P6DIR &= ~BIT3 + ~BIT5 + ~BIT7;     // Configure P6.4, P6.6 and P6.8 as input pins.
    P6SEL |= BIT3 + BIT5 + BIT7;        // Configure P6.4, P6.6 and P6.8 as analog pins.

    ADC12CTL0 = ADC12ON + SHT0_6 + MSC; // configure ADC converter
    ADC12CTL1 = SHP + CONSEQ_1;         // Use sample timer, single sequence
    ADC12MCTL0 = INCH_3;                // ADC A3 pin - Stick X-axis.
    ADC12MCTL1 = INCH_7;                // ADC A4 pin - Stick Y-axis.
    ADC12MCTL2 = INCH_5 + EOS;          // ADC A5 pin - Stick Z-axis.
                                        // EOS - End of Sequence for Conversions.
    ADC12IE |= 0x02;                    // Enable ADC12IFG.1
    for (i = 0; i < 0x3600; i++);       // Delay for reference start-up
    ADC12CTL0 |= ENC;                   // Enable conversions
}

