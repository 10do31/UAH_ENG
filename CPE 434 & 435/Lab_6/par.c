#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#define TIMER_CLEAR (tv1.tv_sec = tv1.tv_usec = tv2.tv_sec = tv2.tv_usec = 0)
#define TIMER_START gettimeofday(&tv1, (struct timezone*)0)
#define TIMER_ELAPSED (double) (tv2.tv_usec-tv1.tv_usec)/1000000.0+(tv2.tv_sec-tv1.tv_sec)
#define TIMER_STOP gettimeofday(&tv2, (struct timezone*)0)
struct timeval tv1,tv2;

unsigned long threads, rects;
double rng, sum;
pthread_mutex_t mutx;

double func(double val)
{
	return(sqrt(1 - pow(val, 2)));
}

void* Sum(void* arg)
{
	double x, temp = 0;
	unsigned long i;
	int aStart = *(int*) arg;

	for (i = aStart; i < rects; i += threads)
	{
		x = rng * i;
		temp += rng * func(x);
	}

	pthread_mutex_lock(&mutx);
	sum += temp;
	pthread_mutex_unlock(&mutx);
	return 0;
}

int main(int argc, char* argv[])
{
	int i, j, rStatus;

	TIMER_CLEAR;
	TIMER_START;

	if(argc != 3)
	{
		printf("Three input arguments required, please try again.\n");
		printf("Program has exited!\n");
		return 1;
	}

	sum = 0;
	rects = atoi(argv[1]);
	threads = atoi(argv[2]);

	printf("\nTotal Rectangles: %ld\n", rects);
	printf("Total Threads: %ld\n", threads);

	rng = 1 / (double)rects; 
	pthread_t myThreads[threads];
	int start[threads];
	if(rects < 0)
	{
		printf("Error! Input must be a positive number, please try again.\n");
		printf("Program has exited!\n");
		return 1;
	}

    for(i = 0; i < threads; i++)
	{
		start[i] = i; 
		if(pthread_create(&myThreads[i], 0, Sum, &start[i]))
		{
			printf("Error! Thread creation failed!\n");
			printf("Program has exited!\n");
			return 1;
		}
	}
	
	for(j = 0; j < threads; j++)
	{
		rStatus = pthread_join(myThreads[j], 0);

		if(rStatus)
		{
			printf("Error encountered at thread%d.\n", j);
			printf("Error number:%d\n", rStatus);
		}
	}

    pthread_mutex_destroy(&mutx);
    sum *= 4;
	printf("Test of Rect decomposition = %1.9g\n", sum);

    TIMER_STOP;
	printf("Time elapsed = %f seconds\n", TIMER_ELAPSED);

	return 0;
}
