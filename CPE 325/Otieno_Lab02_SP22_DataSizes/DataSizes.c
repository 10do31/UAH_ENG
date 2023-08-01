/*------------------------------------------------------------------------------
 * File:        Lab02_DataSizes.c
 * Function:    This C code will display sizes of some data types in the c library.
 * Description: This program will print the byte, Minimum and Maximum sizes of various data types
 *              contained in the c Library.
 * Input:       None.
 * Output:      Data type sizes from c library.
 * Author(s):   Dan Otieno, dpo0002@uah.edu
 * Date:        January 21st, 2022.
 * ---------------------------------------------------------------------------*/
#include <msp430.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>

hyphens(char, int);    //Function prototype for hyphens print function;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer;

	// Declare variables to define datatypes;
	char dash = '-';
	signed char schar;
	int SomeInt;
	unsigned int SomeUint;
	short SomeshortInt;
	unsigned short SomeUshortInt;
	long SomelongInt;
	long long SomeLLint;
	unsigned long SomeUlongInt;
	unsigned long long SomeULLint;
	float SomeFloat;
	double SomeDouble;

	hyphens(dash, 92);     //Call function to print dashes; first line of hyphens to create table headers;
	printf("| %-20s | %-20s | %-20s | %-20s|\n","Data Type","Size (in bytes)","Minimum","Maximum");
	hyphens(dash, 92);      //Call function to print dashes, last line of hyphens to create table headers;

	printf("| %-20s | %-20d | %-20d | %-20d|\n","signed char",sizeof(schar),SCHAR_MIN,SCHAR_MAX);     //Sizes of signed char data type;

	printf("| %-20s | %-20d | %-20d | %-20d|\n","char",sizeof(dash),0,UCHAR_MAX);     //Sizes of unsigned char data type;

	printf("| %-20s | %-20d | %-20d | %-20d|\n","int",sizeof(SomeInt),INT_MIN,INT_MAX);     // Sizes of int data type;

	printf("| %-20s | %-20d | %-20d | %-20u|\n","unsigned int",sizeof(SomeUint),0,UINT_MAX);    //Sizes unsigned int data type;

	printf("| %-20s | %-20d | %-20d | %-20d|\n","short int",sizeof(SomeshortInt),SHRT_MIN,SHRT_MAX);  // Sizes of short int data type;

	printf("| %-20s | %-20d | %-20d | %-20hu|\n","unsigned short int",sizeof(SomeUshortInt),0,USHRT_MAX);  //Sizes of unsigned short int data type;

	printf("| %-20s | %-20d | %-20ld | %-20ld|\n","long int",sizeof(SomelongInt),LONG_MIN,LONG_MAX);  // Sizes of long int data type;

	printf("| %-20s | %-20d | %-20d | %-20lu|\n","unsigned long int",sizeof(SomeUlongInt),0,ULONG_MAX);  //Sizes of unsigned long int data type;

	printf("| %-20s | %-20d | %-20lld | %-20lld|\n","long long int",sizeof(SomeLLint),LLONG_MIN,LLONG_MAX);    //Sizes of long long int data type;

	printf("| %-20s | %-20d | %-20d | %-20llu|\n","unsigned long long",sizeof(SomeULLint),0,ULLONG_MAX);    //Sizes of unsigned long long int;

	printf("| %-20s | %-20d | %-20e | %-20e|\n","float",sizeof(SomeFloat),FLT_MIN,FLT_MAX);     //Sizes of float;

	printf("| %-20s | %-20d | %-20e | %-20e|\n","double",sizeof(SomeDouble),DBL_MIN ,DBL_MAX);  //Sizes of double;

	hyphens(dash, 92);  //Call function to print dashes; last line of hyphens for the bottom line of the table;
	
	return 0;
}

// Hyphens print function.
hyphens(char dash, int num)
{
    int i;

    for(i=0;i<num;i++)
    {
        printf("%c",dash);
    }
    printf("\n");
}
