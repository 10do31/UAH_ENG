/*------------------------------------------------------------------------------
 * File:        Lab01_PowerLoop.c
 * Function:    This C code will calculate the power of a given base.
 * Description: This program calculates the power of a given
 *              base using iterative "For" loop.
 * Input:       None.
 * Output:      Base raised to the given power.
 * Author(s):   Dan Otieno, dpo0002@uah.edu
 * Date:        January 14th, 2022.
 * ---------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include "msp430.h"

long int exponential(int, int); // Prototype of exponential

int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;   // Stop watchdog timer.
    int base = 4;              // Set base value.
    int power = 10;              // Set power value.

    long int answer = exponential(base, power);     // Call exponential function in main to calculate exponent by referencing variables.

    printf("%d raised to the power %d is %ld", base, power, answer);    // Print output.

    return 0;                                   // End program.
}

// This function uses an iterative loop to calculate the exponential of given base and power values.
long int exponential(int base, int power)
{
    long int answer = 1, i;

    for(i = 1; i<=power; i++)           //Loop to calculate exponent; condition is counter must be less than or equal to power variable.
    {
        answer = answer*base;           // If condition is met, calculation is completed inside of loop.
    }

    return answer;
}
