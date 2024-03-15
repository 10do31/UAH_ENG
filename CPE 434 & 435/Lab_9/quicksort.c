#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <ctype.h>
#include <unistd.h>

#define TIMER_CLEAR (tv1.tv_sec = tv1.tv_usec = tv2.tv_sec = tv2.tv_usec = 0)
#define TIMER_START gettimeofday(&tv1, (struct timezone*)0)
#define TIMER_ELAPSED (double) (tv2.tv_usec-tv1.tv_usec)/1000000.0+(tv2.tv_sec-tv1.tv_sec)
#define TIMER_STOP gettimeofday(&tv2, (struct timezone*)0)
#define arrSIZE 10000000
struct timeval tv1,tv2;
int array[arrSIZE]; /* this is ok it is from global memory */

void fnSwap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int fnPartition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++;
            fnSwap(&arr[i], &arr[j]);
        }
    }

    fnSwap(&arr[i+1], &arr[high]);
    return i+1;
}

void quicksort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int p = fnPartition(arr, low, high);
        quicksort(arr, low, p-1);
        quicksort(arr, p+1, high);
    }
}

void fnRandNums(int arr[])
{
    srand(time(0));

    // generate and store random numbers in array.
    for (int i = 0; i < arrSIZE; i++) 
    {
        arr[i] = rand();
    }
}

int main() 
{
    int n = sizeof(array)/sizeof(array[0]);

    fnRandNums(array);

    TIMER_CLEAR;
    TIMER_START;

    quicksort(array, 0, n-1);

    printf("First 20 values of Sorted array: \n");
    for (int i = 0; i < 20; i++) 
    {
        printf("%d \n", array[i]);
    }
    printf("\n");

    sleep(5); //Timer will give us ~5 seconds
    TIMER_STOP;
    printf("Time elapsed = %f seconds\n", TIMER_ELAPSED);

    return 0;
}
