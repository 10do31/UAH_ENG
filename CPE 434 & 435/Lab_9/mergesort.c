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

void fnMerge(int arr[], int left, int mid, int right) 
{
    int i, j, k;
    int m = mid - left + 1;
    int n = right - mid;
    int temp1[m], temp2[n];
 
    for (i = 0; i < m; i++)
        temp1[i] = arr[l + i];
    for (j = 0; j < n; j++)
        temp2[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = left;
    while (i < m && j < n) 
    {
        if (temp1[i] <= temp2[j]) 
        {
            arr[k] = temp1[i];
            i++;
        }
        else 
        {
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }

    while (i < m) 
    {
        arr[k] = temp1[i];
        i++;
        k++;
    }

    while (j < n) 
    {
        arr[k] = temp2[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        fnMerge(arr, left, mid, right);
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
    int n = sizeof(array) / sizeof(array[0]);

    fnRandNums(array);

    TIMER_CLEAR;
    TIMER_START;
 
    mergeSort(array, 0, n-1);
 
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
