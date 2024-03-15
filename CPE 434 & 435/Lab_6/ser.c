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

unsigned long rects;

double func(double val)
{
	return (sqrt(1 - pow(val, 2)));
}

double Width(double upper, double lower, int num)
{
    double width;

    width = ((upper - lower) / num);

    return width;
}

double Height(double width, int i)
{
	double x, height;

	x = width * i;
    height = func(x);

    return height;
}

int main(int argc, char* argv[])
{
	double sum=0, w;
	int i; 

	TIMER_CLEAR;
	TIMER_START;

	if(argc != 2)
	{
		printf("Two input arguments required, please try again.\n");
		printf("Program has exited!\n");
	}
	
	rects = atoi(argv[1]);
	
	if(rects < 0)
	{
		printf("Error! Input must be a positive number, please try again.\n");
		printf("Program has exited!\n");
		return 1;
	}
	
    w = Width(1, 0, rects);
    
    for(i = 0; i < rects; i++)
    {
        sum += w * Height(w, i);
    }
    
    sum *= 4;
    printf("\nTotal Rectangles: %ld\n", rects);
    printf("Test of Rect decomposition = %1.9g\n", sum);
    TIMER_STOP;
	printf("Time elapsed = %f seconds\n", TIMER_ELAPSED);
	return 0;
}