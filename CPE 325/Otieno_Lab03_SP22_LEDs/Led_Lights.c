/*--------------------------------------------------------------------------------------------------
 * File:        Lab03_LEDs.c
 * Function:    This C code will interact with the MSP430 hardware by controlling LED I/Os.
 * Description: This program will interface LED 1 and LED 2 on the MSP430 board by
 *              defining input and output instructions, and using LED lights to demonstrate results.
 * Input:       Defined in code, corresponding to hardware input pins.
 * Output:      LED light states (on or off).
 * Author(s):   Dan Otieno, dpo0002@uah.edu
 * Date:        January 28th, 2022.
 * -------------------------------------------------------------------------------------------------*/
#include <msp430.h> 
#define S1 P2IN&BIT1
#define S2 P1IN&BIT1

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    // INTERFACING DIRECTION REGISTERS FOR INPUT PINS;
    P2DIR &= ~BIT1;         // Input: S1 - P2.1;
    P1DIR &= ~BIT1;         // Input: S2 - P1.1;

    // INTERFACING DIRECTION REGISTERS FOR OUTPUT PINS;
    P1DIR |= BIT0;          // Output: LED1 - P1.0;
    P4DIR |= BIT7;          // Output: LED2 - P4.7;

    // ON/OFF STATE;
    P4OUT |= BIT7;          // LED2 is ON;
    P1OUT &= ~BIT0;         // LED1 is OFF;

    // ENABLE PULL-UP RESISTOR/SET PROPER IN/OUT;
    P2REN |= BIT1;          // Enable pull-up resistor at P2.1;
    P2OUT |= BIT1;          // Required for proper IO;
    P1REN |= BIT1;          // Enable pull-up resistor at P1.1;
    P1OUT |= BIT1;          // Required for proper IO;

    unsigned int i = 0;
    for (;;)
    {
        if((S1)==0 && (S2)!=0)          // When S1 is pressed, S2 is NOT pressed;
        {
            for (i=20000; i>0; i--);    // Debounce: 20 ms = 0.02secs = (0.02*10^6) cycles = 20000 cycles;
            {
                do
                {
                    P4OUT &= ~BIT7;         // Turn off LED2;
                    P1OUT ^= BIT0;          //  Blink LED1;

                    /* 2Hz = 1/2(secs) = 0.5 secs. To determine delay parameter,
                    - we first  divide the total time by half, for ON and OFF . In this case 0.5/2 = 0.25s ON/0.25s OFF.
                    - This is equivalent to (0.25*10^6) clock cycles = 250000 cycles.*/

                    __delay_cycles(250000);

                }while((S1)==0 && (S2)!=0); // ....S1 is still pressed but S2 is not!;
            }
        }

        else if((S2)==0 && (S1)!=0)     // S2 is pressed, S1 is not pressed;
        {
            for(i=20000; i>0; i--);     // Debounce: 20ms/20000 clock cycles;
            {
                do
                {
                    P1OUT |= BIT0;      // Turn on LED1;
                    P4OUT ^= BIT7;      // Blink LED2;

                    /* 5hz = 1/5(secs) = 0.2secs.
                    - 0.2/2 = 0.1 ON/0.1 OFF.
                    - clock cycles delay parameter = (0.1*10^6) cycles = 100000.*/

                    __delay_cycles(100000);

                }while ((S2)==0 && (S1)!=0); //....S2 is still pressed but S1 is not;
            }
        }

        //(Bonus) S1 and S2 are both held, blink LED1 and LED2 alternatively;
        else if((S1)==0 && (S2)==0)     //Both switches are pressed;
        {
            for(i=20000; i>0; i--);     // Debounce: 20ms/20000 clock cycles;
            {
                do
                {
                    /* 8hz = 1/8(secs) = 0.125secs.
                    - 0.125/2 = 0.0625 ON/0.0625 OFF.
                    - clock cycles delay parameter = (0.0625*10^6) cycles = 62500.*/

                    P1OUT |= BIT0;      // Blink LED1;
                    P4OUT &= ~BIT7;     // Turn off LED2;
                    __delay_cycles(62500);

                    P1OUT &= ~BIT0;     //Turn off LED1;
                    P4OUT |= BIT7;      //Blink LED2;
                    __delay_cycles(62500);

                }while((S1)==0 && (S2)==0);
            }
        }

        else        // No switches held, back to original state;
        {
            P4OUT |= BIT7;      // Turn on LED2;
            P1OUT &= ~BIT0;     // Turn off LED1;
        }
    }

    return 0;
}
