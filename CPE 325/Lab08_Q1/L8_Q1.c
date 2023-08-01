#include <msp430xG46x.h>
#include <stdio.h>
#include <string.h>

char wlcm[60] = "\033[0;33mWelcome to typing practice! Are you ready to start?";
char StrOne[45] = "The quick brown fox jumps over the lazy dog.";
char StrTwo[25] = "This is a second string.";
char cmpstr[10] = "Let's go!";
//char match[35] = "Type in the following strings\r\n";

void UART_setup();
void compare(char*, char*, int);
void UART_Send_Character(char);
void UART_send_String(char*);
void UART_get_word(char*, int);
void Incorrect(char*, char*, int);

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	            // stop watchdog timer
	UART_setup();

	int limit1 = 10, limit2 = 45, limit3 = 25;
	char* respone, resptwo;

	while(1)
	{
	    char go[10];
	    UART_send_String(wlcm);
	    UART_get_word(go, limit1);
	    compare(cmpstr, go, limit1);

	    UART_send_String("Type in the following strings\r\n");

	    char str1cmp[45];
	    UART_send_String(StrOne);
	    UART_get_word(str1cmp, limit2);
	    compare(StrOne, str1cmp, limit2);

	    //UART_send_String("\r\n");
	    char str2cmp[25];
	    UART_send_String(StrTwo);
	    UART_get_word(str2cmp, limit3);
	    compare(StrOne, str2cmp, limit3);


	    /*if(compare = 0)
	    {
	        UART_send_String(StrOne);
	        UART_get_word(respone, limit2);
	        comparetwo = strcmp(respone, StrOne);

	        if(comparetwo != 0)
	        {
	            Incorrect(StrOne, respone, limit2);
	        }
	    }
	    UART_send_String("\r\n");

	    if(comparetwo = 0)
	    {
	        UART_send_String(StrTwo);
	        UART_get_word(resptwo, limit3);             // Get user's entries.
	        comparethree = strcmp(resptwo, StrTwo);

	        if(comparethree != 0)
	        {
	            Incorrect(StrTwo, resptwo, limit3);
	        }
	        else
	        {
	            UART_send_String("\033[0;32mCorrect!");
	            //new_line();
	        }
	    }*/
	}
}

void UART_setup(void)
{
    P2SEL |= BIT4 + BIT5;   // Set USCI_A0 RXD/TXD to receive/transmit data
    UCA0CTL1 |= UCSWRST;    // Set software reset during initialization
    UCA0CTL0 = 0;           // USCI_A0 control register
    UCA0CTL1 |= UCSSEL_2;   // Clock source SMCLK
    UCA0BR0 = 18;         // 1048576 Hz  / 57600 lower byte
    UCA0BR1 = 0;            // upper byte
    UCA0MCTL = 0x02;        // Modulation (UCBRS0=0x01, UCOS16=0)
    UCA0CTL1 &= ~UCSWRST;   // Clear software reset to initialize USCI state
}

void UART_Send_Character(char my_char)
{
    while(!(IFG2&UCA0TXIFG));   // Wait until can transmit.
    UCA0TXBUF = my_char;        // Tx Buffer gets my_char variable.
}

void UART_send_String(char* string)
{
    int i = 0;

    while(string[i] != '\0')  // Send character by character
    {
        UART_Send_Character(string[i++]);
    }
    UART_Send_Character('\r');
    UART_Send_Character('\n');
}

void UART_get_word(char* buffer, int limit)
{
    int counter = 0;
    char my_char = UCA0RXBUF;
    while(my_char != '\r' && counter<limit)
    {
        //my_char = UCA0RXBUF;
        while(!(IFG2&UCA0RXIFG));        // Wait until character can be read from RXBUF.
        buffer[counter++] = my_char;
        UART_Send_Character(my_char);
        my_char = UCA0RXBUF;
        //buffer++;
        //counter++;
    }
    buffer[counter] = '\0';
}
void compare(char* str1, char* str2, int limit)
{

    int i;

    for(i = 0; i<limit-1; i++)
    {
        while(str1[i] != str2[i])
        {
            //while(!(IFG2&UCA0RXIFG));        // Wait until character can be read from RXBUF.
            UART_send_String("\r\n");         // Send carriage, new line.
            UART_send_String(wlcm);
            UART_get_word(str1[i], limit);
        }
    }
    //while(!(IFG2&UCA0TXIFG));   // Wait until can transmit.

    UART_Send_Character('\r');
    UART_Send_Character('\n');
}

void Incorrect(char* buffer, char* msg, int length)
{
    int count = 0, i;

    for(i=0; i<length-1; i++)
    {
        if(buffer[i] != msg[i])
            count++;
    }
    //return count;
    snprintf(buffer, 15, "%d", count);
}
