#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
#define TIMER_CLEAR (tv1.tv_sec = tv1.tv_usec = tv2.tv_sec = tv2.tv_usec = 0)
#define TIMER_START gettimeofday(&tv1, (struct timezone*)0)
#define TIMER_ELAPSED (double) (tv2.tv_usec-tv1.tv_usec)/1000000.0+(tv2.tv_sec-tv1.tv_sec)
#define TIMER_STOP gettimeofday(&tv2, (struct timezone*)0)
struct timeval tv1,tv2;

/******* These are function prototypes ****************/
double fnWidth(double, double, int);
double fnHeight(double, int);
/*****************************************************/

int main(int argc, char* argv[])
{
	double sum=0, somew;
	int i; 
	unsigned long rects = atoi(argv[1]);

	TIMER_CLEAR;
	TIMER_START;

	if(argc != 2)
	{
		printf("Two input arguments required, please try again.\n");
		printf("Program has exited!\n");
	}
	
	
	if(rects < 0)
	{
		printf("Error! Input must be a positive number, please try again.\n");
		printf("Program has exited!\n");
		return 1;
	}
	
    somew = fnWidth(1, 0, rects);
    
    for(i = 0; i < rects; i++)
    {
        sum += somew * fnHeight(somew, i);
    }
    
    sum *= 4;
    printf("Test of Rect decomposition = %1.9g\n", sum);
    TIMER_STOP;
	printf("Time elapsed = %f seconds\n", TIMER_ELAPSED);
	return 0;
}

/*****************.....and these are the functions******************/
double fnWidth(double uplimit, double lolimit, int num)
{
    double width;

    width = ((uplimit - lolimit) / num);

    return width;
}

double fnHeight(double width, int i)
{
	double x, h;

	x = width * i;
    h = (sqrt(1 - pow(x, 2)));

    return h;
}