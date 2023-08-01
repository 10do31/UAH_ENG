#include <msp430.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define stateQmark  0x3F      // Character '?'
#define stateZero   0x30      // Character '0'
#define Dummy       0x00      // Character NULL - used for dummy write operation

#define Zero    0x00
#define Qmark   0xFF

void SPI_setup();
void SPI_Send_Character(char);
void UART_Send_Character(char);
void UART_send_String(char*);
void UART_get_word(char*, int);

char prompt[] = "\r\nHello, please enter a number: \r\n";
char invalid[] = "\r\nInvalid multiplier entered";
char num[5];
unsigned char my_char;

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;      // Stop watchdog timer
	UART_setup();                  // Setup USCI_A0 module in UART mode
	SPI_setup();                   // Setup USCI_B0 module in SPI mode
	int z, i, numit;

	for(z = 100; z>0; z--);
	UART_send_String(prompt);
	
	while(1)
	{
	    UART_get_word(num, 5);

	    switch(my_char)
	    {
	    case    '0':
	        SPI_setState(stateZero);
	        for(i = 1000; i>0; i--);
	        SPI_Send_Character(Zero);
	        UART_Send_Character(SPI_getState());
	        break;

	    case    '?':
	        SPI_setState(stateQmark);
	        for(i = 1000; i>0; i--);
	        UART_send_String("\r\nThe stored multiplier value is: ");
	        SPI_Send_Character(SPI_getState());
	        //SPI_Send_Character(num);
	        break;

	    default :
	        UART_send_String(prompt);
	        break;
	    }

	    if(num > 0 && num <= 20)
	    {
	        numit = atoi(num);
	        SPI_setState(numit);
	        for(i = 1000; i>0; i--);
	        UART_Send_Character(SPI_getState());
	    }

	    else
	    {
	        UART_send_String(invalid);
	    }

	    UART_send_String("\r\n");
	}

}

void SPI_setup(void)
{
    UCB0CTL0 = UCMSB + UCMST + UCSYNC;// Sync. mode, 3-pin SPI, Master mode, 8-bit data
    UCB0CTL1 = UCSSEL_2 + UCSWRST; // SMCLK and Software reset
    UCB0BR0 = 0x02;                // Data rate = SMCLK/2 ~= 500kHz
    UCB0BR1 = 0x00;
    P3SEL |= BIT1 + BIT2 + BIT3;   // P3.1,P3.2,P3.3 option select
    UCB0CTL1 &= ~UCSWRST;          // **Initialize USCI state machine**
}

unsigned char SPI_getState(void)
{
    while((P3IN & 0x01));          // Verifies busy flag
    IFG2 &= ~UCB0RXIFG;
    UCB0TXBUF = Dummy;     // Dummy write to start SPI
    while (!(IFG2 & UCB0RXIFG));   // USCI_B0 TX buffer ready?
    return UCB0RXBUF;
}
void SPI_setState(unsigned char State)
{
    while(P3IN & 0x01);           // Verifies busy flag
    IFG2 &= ~UCB0RXIFG;
    UCB0TXBUF = State;            // Write new state
    while (!(IFG2 & UCB0RXIFG));  // USCI_B0 TX buffer ready?
}

void SPI_Send_Character(char my_char)
{
    while(!(IFG2&UCB0TXIFG));   // Wait until can transmit.
    UCA0TXBUF = my_char;        // Tx Buffer gets my_char variable.
}

void UART_setup(void)
{
    P2SEL |= BIT4 + BIT5;          // Set UC0TXD and UC0RXD to transmit and receive data
    UCA0CTL1 |= UCSWRST;           // Software reset
    UCA0CTL0 = 0;                  // USCI_A0 control register
    UCA0CTL1 |= UCSSEL_2;          // Clock source SMCLK - 1048576 Hz
    UCA0BR0 = 18;                  // Baud rate - 1048576 Hz / 57600
    UCA0BR1 = 0;
    UCA0MCTL = 0x02;               // Modulation
    UCA0CTL1 &= ~UCSWRST;          // Software reset
    IE2 |= UCA0RXIE;               // Enable USCI_A0 RX interrupt
}

void UART_Send_Character(char my_char)
{
    while(!(IFG2&UCA0TXIFG));   // Wait until can transmit.
    UCA0TXBUF = my_char;        // Tx Buffer gets my_char variable.
}

void UART_send_String(char* string)
{
    //int i = 0;

    while(*string != '\0')  // Send character by character
    {
        UART_Send_Character(*string++);
        //i++;
    }
    UART_Send_Character('\r');
    UART_Send_Character('\n');
}

void UART_get_word(char* buffer, int limit)
{
    int counter = 0;
    my_char = 0;
    while(my_char != '\r' && counter < limit)
    {
        my_char = UCA0RXBUF;
        while(!(IFG2&UCA0RXIFG));        // Wait until character can be read from RXBUF.
        UART_Send_Character(my_char);
        *buffer = my_char;
        buffer++;
        counter++;
    }
    *buffer = '\0';
}
