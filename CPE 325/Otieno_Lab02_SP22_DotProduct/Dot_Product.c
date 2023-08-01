/*------------------------------------------------------------------------------
 * File:        Lab02_Dot_Product.c
 * Function:    This C code will calculate sums and dot products.
 * Description: This program will add the values of corresponding indices in two arrays,
 *              hold and print result in a third array, and also calculate the dot product of the two arrays.
 * Input:       Manual inputs for Arrays A and B.
 * Output:      Sums and dot product results.
 * Author(s):   Dan Otieno, dpo0002@uah.edu
 * Date:        January 21st, 2022.
 * ---------------------------------------------------------------------------*/

#include <msp430.h> 
#include <stdio.h>
#include <string.h>
#include <math.h>

void printarray(int array[], const int);    //Print function prototype;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	    // stop watchdog timer
	
	int A[4] = {-1, 2, 5, 3};       // Declare first array, set size of array;
	int B[4] = {20, -8, 4, 1};      // Declare second array, set size to match the first array;
	char name1 = 'A';               // Declare char type variable to name first array;
	char name2 = 'B';               // Declare second char type variable to name the second array;
	int i;                          // Declare int i for loop index;
	int sums[10];                   // Array variable sums to hold addition results.
	int dotresult = 0;              // Variable to hold dot product result;

	printf("Input Array %c: [", name1);     //Print first array name;
	printarray(A,4);                        // Call Print function to print array 1;

	printf("Input Array %c: [", name2);     //Print second array name;
	printarray(B,4);                        // Call Print function again to print array 2;

	printf("Sum of the arrays: [");

	// Loop to calculate and print sum results;
	    for(i=0;i<4;i++)
	    {
	        sums[i] = A[i]+B[i];
	        printf("%d ",sums[i]);
	    }

	    printf( "]\n");

	    // Loop to calculate and print dot product result;
	    for(i=0;i<4;i++)
	    {
	        dotresult = dotresult + A[i]*B[i];
	    }
	    printf("Dot Product of the arrays: [%d]\n", dotresult);

	return 0;
}

// Function to print arrays, will be called in main;
void printarray(int array[], const int size)
{
    int i;

    for(i=0; i<size-1; i++)
    {
        printf(" %d ",array[i]);
    }
    printf("%d]\n", array[i]);
}


