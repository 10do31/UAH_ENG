/*------------------------------------------------------------------------------
 * File:        Lab01_CharCounts.c
 * Function:    This C code will count the letters and digits in a given string.
 * Description: This program counts and returns the number of alphabetical characters and digits in a given string
 *              using ASCII character comparison method.
 * Input:       None.
 * Output:      Number of alphabetical characters (upper, lower case) and digits.
 * Author(s):   Dan Otieno, dpo0002@uah.edu
 * Date:        January 14th, 2022.
 * ---------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <msp430.h> 

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer.
	
	int uppers=0, lowers=0, digits=0;       // Define variables for alphabetical characters, digits and loop counter, set counters to start at 0.
	int i;                         // Define loop counter.
	char x[] = "Hello CPE325GGGkkk!";             // Define variable to hold the string characters in an array.

	for(i=0; i<x[i]; i++)                   // Start of loop; loop counter starts at 0; compare counter with length of character string.
	    {
	        if(x[i] >= 48 && x[i] <= 57)    // ASCII character #s for digits; 48-57; Program checks for characters in that range.
	        {
	            digits++;                   // If found, digit character counter is incremented by 1.
	        }
	        else if(x[i] >= 65 && x[i] <= 90)   // ASCII character #s for upper case letters; 65-90; Program checks for characters in that range.
	        {
	            uppers++;                       // If found, upper case character counter is incremented by 1.
	        }
	        else if(x[i] >= 97 && x[i] <= 122)  // ASCII character #s for lower case letters; 97-122; Program checks for characters in that range.
	        {
	            lowers++;                       // If found, lower case character counter is incremented by 1.
	        }
	    }                                   // End Loop.

	printf("Hello CPE325! contains: \n %d digits \n %d uppercase characters \n %d lowercase characters", digits, uppers, lowers);  // Print results.

	return 0;

	// i<strlen(x);
}

