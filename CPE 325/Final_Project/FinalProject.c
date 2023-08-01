/*-------------------------------------------------------------------------------------------------*/
//*File:        FinalProject.c
//*Function:    This C code will interface the ADXL335 accelerometer using the UART and ADC components of the MSP430.
//* Description: This program detects angle of deviation relative to the y-axis, we get a buzzer sound, and LED blinks
//*              depending on whether the angle is too high, too low, LEDs stay on if normal, and buzzer stays off.
//*              We also get messages displayed into the HypTerminal via UART on deviation status.
//* Input:       None.
//* Output:      LEDs on when normal, LEDs blink when deviation is detected, HyperTerminal messages, Buzzer tone.
//* Author(s):   Dan Otieno, dpo0002@uah.edu
//* Date:        April 16th, 2022.
/*-----------------------------------------------------------------------------------------------*/
#include <msp430.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

char openMSG[] = "*****ACCELEROMETER LEVEL DISPLAY*****\n\r";
char steady[] = "\033[0;32mNormal Level :)\n\r";
char highdisp[] = "\033[0;33m---Angle Too High!---\n\r";
char lowdisp [] = "\033[0;31m---Angle Too Low!---\n\r";
char dvAngle[10];
volatile long int ADCXval, ADCYval, ADCZval;
volatile float Xper, Yper, Zper, aDev;
void UART_setup();
void sendData();
void UART_Send_Character(char);
void UART_send_String(char*, int);

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer;
/**********************************************************************************************
****WDT ISR CONFIGURATIONS********************************************************************/
    WDTCTL = WDT_ADLY_1000;         // Set interval to 1000ms/1s interval timer;
    IE1   |= WDTIE;                 // Enable WDT interrupts;
/**********************************************************************************************
****INPUT/OUTPUT CONFIGURATIONS FOR LEDs AND BUZZER*******************************************/
    P3DIR |= BIT5;                  // 3.5 for buzzer;
    P3SEL |= BIT5;                  // Special function for P2.2 (TB4 Output);
    TBCTL |= TBSSEL_2 + MC_1;       // Timer B Clock Source: SMCLK;
    TBCCTL4 |= OUTMOD_4;            // Set Timer B4 to output;
    TBCCR0 = 2000;                  // Sets buzzer frequency to 1 KHz;
    P2DIR |= BIT1 + BIT2;           // P2.1 and P2.2 set up as output;
    P2OUT &= ~(BIT1 + BIT2);        // Ensure LED1 and LED2 are off;
    P3SEL &= ~BIT5;                 // Buzzer is off in the beginning;
/***********************************************************************************************/
/*******************************ADC & UART SETUP IN MAIN***************************************/
    ADC_setup();                // Setup ADC;
    UART_setup();               // Setup UART for RS-232;
    _EINT();                    // Enable Global interrupts;

    while (1)
    {
        ADC12CTL0 |= ADC12SC;               // Start conversions
        __bis_SR_register(LPM0_bits + GIE); // Enter LPM0
    }
}/*-----------------------------------------------------------------------------------------*/
/*-----------------------UART CONFIGURATIONS------------------------------------------------*/
void UART_setup(void)
{
    UCA0CTL1 |= UCSWRST;                // Software reset during initialization;
    P2SEL |= BIT4 + BIT5;               // Set Rx and Tx bits (Transmit&Receive);
    UCA0CTL0 = 0;                       // Set up default RS-232 protocol;
    UCA0CTL1 |= UCSSEL_2;               // Set clock source: SMCLK;
    UCA0BR0 = 0x09;                     // 1048576Hz/115200 - Baud Rate;
    UCA0BR1 = 0;
    UCA0MCTL = 0x02;                    //Modulation(CBRS0=0x02, UCOS16=0);
    UCA0CTL1 &= ~UCSWRST;               // Clear software reset;
}/*----------------------------------------------------------------------------------------*/
void sendData(void)
{
    int i;
    Xper = ((ADCXval*3.0/4095-1.5)/0.3);    // Calculate percentage outputs;
    Yper = ((ADCYval*3.0/4095-1.5)/0.3);
    Zper = ((ADCZval*3.0/4095-1.5)/0.3);
    aDev = atan(Yper/Zper)*180/3.14;

    // Use character pointers to send one byte at a time;
    char *xpointer=(char *)&Xper;
    char *ypointer=(char *)&Yper;
    char *zpointer=(char *)&Zper;
    char *dvpointer=(char *)&aDev;

    UART_Send_Character(0x55);            // Send header;
    for(i = 0; i < 4; i++)
    {            // Send x percentage - one byte at a time;
        UART_Send_Character(xpointer[i]);
    }
    for(i = 0; i < 4; i++)
    {            // Send y percentage - one byte at a time;
        UART_Send_Character(ypointer[i]);
    }
    for(i = 0; i < 4; i++)
    {            // Send z percentage - one byte at a time;
        UART_Send_Character(zpointer[i]);
    }

    for(i = 0; i < 4; i++)
    {            // Send deviation - one byte at a time;
        UART_Send_Character(dvpointer[i]);
    }
}/*---------------------------------------------------------------------------------------*/
void UART_Send_Character(char my_char)
{
    while(!(IFG2&UCA0TXIFG));           // Wait until can transmit.
    UCA0TXBUF = my_char;                // Tx Buffer gets my_char variable.
}/*--------------------------------------------------------------------------------------*/
void UART_send_String(char* string, int wrdlen)
{
    int i;
    //
    for(i = 0; i<wrdlen; i++)       // Send character by character;
    {
        if(string[i]== '\0')
        {
            break;
        }
        UART_Send_Character(string[i]);
    }
    UART_Send_Character('\n');
    UART_Send_Character('\r');
}/*-------------------------------------------------------------------------------------*/
/*--------------------ADC CONFIGURATION-------------------------------------------------*/
void ADC_setup(void)
{
    int i =0;

    P6DIR &= ~BIT3 + ~BIT5 + ~BIT7;     // Configure P6.4, P6.6 and P6.8 as input pins;
    P6SEL |= BIT3 + BIT5 + BIT7;        // Configure P6.4, P6.6 and P6.8 as analog pins;

    ADC12CTL0 = ADC12ON + SHT0_6 + MSC; // configure ADC converter;
    ADC12CTL1 = SHP + CONSEQ_1;         // Use sample timer, single sequence;
    ADC12MCTL0 = INCH_3;                // ADC A3 pin - Stick X-axis;
    ADC12MCTL1 = INCH_7;                // ADC A4 pin - Stick Y-axis;
    ADC12MCTL2 = INCH_5 + EOS;          // ADC A5 pin - Stick Z-axis;
                                        // EOS - End of Sequence for Conversions;
    ADC12IE |= 0x02;                    // Enable ADC12IFG.1;
    for (i = 0; i < 0x3600; i++);       // Delay for reference start-up;
    ADC12CTL0 |= ENC;                   // Enable conversions;
}/*-------------------------------------------------------------------------------------*/
/*--------------------ADC12 ISR---------------------------------------------------------*/
#pragma vector = ADC12_VECTOR
__interrupt void ADC12ISR(void)
{
    ADCXval = ADC12MEM0;                  // Move results, IFG is cleared;
    ADCYval = ADC12MEM1;
    ADCZval = ADC12MEM2;
    __bic_SR_register_on_exit(LPM0_bits); // Exit LPM0;
}/*--------------------------------------------------------------------------------------*/
/*-------------------------WDT ISR-------------------------------------------------------*/
#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void)
{
    sendData();
    UART_send_String(openMSG, sizeof(openMSG));

    if(aDev > 15)
    {
        sprintf(dvAngle, "%d.%04u",round(aDev)); // Prints angle of deviation to a string;
        P2OUT ^= BIT2;                          // Toggle LED1;
        P3SEL ^= BIT5;                          // Buzzer at P3.5;
        P2OUT &= ~BIT1;
        UART_send_String(dvAngle, sizeof(dvAngle));
        UART_send_String(highdisp, sizeof(highdisp));
    }
    else if(aDev < (-1*15))
    {
        sprintf(dvAngle, "%d.%04u",round(aDev));
        P2OUT ^= BIT1;                          // Toggle LED2;
        P3SEL ^= BIT5;                          // Buzzer at P3.5;
        P2OUT &= ~BIT2;
        UART_send_String(dvAngle, sizeof(dvAngle));
        UART_send_String(lowdisp, sizeof(lowdisp));
    }
    else if(aDev > (-1*15) && aDev < 15)
    {
        //LED1 OFF; LED2 OFF.
        sprintf(dvAngle, "%d.%04u",round(aDev));
        P2OUT |= (BIT1 + BIT2);
        P3SEL &= ~BIT5;                         // Buzzer is OFF;
        UART_send_String(dvAngle, sizeof(dvAngle));
        UART_send_String(steady, sizeof(steady));
    }
    __bic_SR_register_on_exit(LPM0_bits);       // Exit LPM0;
}/*--------------------------------------------------------------------------------------*/

