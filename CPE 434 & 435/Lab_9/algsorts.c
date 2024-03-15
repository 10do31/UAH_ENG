#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

#define TIMER_CLEAR (tv1.tv_sec = tv1.tv_usec = tv2.tv_sec = tv2.tv_usec = 0)
#define TIMER_START gettimeofday(&tv1, (struct timezone*)0)
#define TIMER_ELAPSED (double) (tv2.tv_usec-tv1.tv_usec)/1000000.0+(tv2.tv_sec-tv1.tv_sec)
#define TIMER_STOP gettimeofday(&tv2, (struct timezone*)0)
struct timeval tv1,tv2;
long int array1[50000000]; /* this is ok it is from global memory */
long int array2[35000000];
long int array3[250000];

/* Function declarations */
void quick_sort(long int arr[], int left, int right);
void q_verify(long int arr[], int n);
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void m_verify(int arr[], int n);
void insertion_sort(long arr[], long n);
int i_verify(int arr[], int n);

void quick_sort_top_level(long int n) 
{
    array1[n];
    int i;
    srand(time(NULL)); // seed the random number generator with the current time
    for (i = 0; i < n; i++) 
    {
        array1[i] = rand();
    }

    TIMER_CLEAR;
    TIMER_START;
    quick_sort(array1, 0, n-1);
    q_verify(array1, n);
    TIMER_STOP;
    printf("Time elapsed = %f seconds\n", TIMER_ELAPSED);
}

/* Top level function */
void merge_sort_top_level(long int n) 
{
    array2[n];
    int i;
    /* Generate n random integers */
    srand(time(NULL));
    for (i = 0; i < n; i++) 
    {
        array2[i] = rand();
    }
    TIMER_CLEAR;
    TIMER_START;
    merge_sort(array2, 0, n - 1);
    m_verify(array2, n);
    TIMER_STOP;
    printf("Time elapsed = %f seconds\n", TIMER_ELAPSED);
}

void insertion_sort_top_level(long int n) 
{
    long int i;
    srand(time(NULL));

    // Generate n random integers
    for (i = 0; i < n; i++) 
    {
        array3[i] = rand();
    }

    TIMER_CLEAR;
    TIMER_START;
    insertion_sort(array3, n);
    i_verify(array3, n);
    TIMER_STOP;
    printf("Time elapsed = %f seconds\n", TIMER_ELAPSED);
}

void quick_sort(long int arr[], int left, int right) 
{
    if (left < right) 
    {
        long int pivot = arr[(left + right) / 2];
        int i = left, j = right;
        while (i <= j) 
        {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) 
            {
                long int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
        }
        quick_sort(arr, left, j);
        quick_sort(arr, i, right);
    }
}

void q_verify(long int arr[], int n) 
{
    int i;
    for (i = 0; i < n-1; i++) 
    {
        if (arr[i] > arr[i+1]) 
        {
            printf("Sorting failed at index %d\n", i);
            return;
        }
    }
    printf("Sorting succeeded!\n");
}


/* Merge sort implementation */
void merge_sort(int arr[], int l, int r) 
{
    if (l < r) 
    {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/* Merge two sorted subarrays into a larger sorted array */
void merge(int arr[], int l, int m, int r) 
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    //int L[n1], R[n2];
    int* L = (int*)malloc(sizeof(long int) * n1);
    int* R = (int*)malloc(sizeof(long int) * n2);

    for (i = 0; i < n1; i++) 
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) 
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        } 
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* Verify if the array is sorted */
void m_verify(int arr[], int n) 
{
    int i;
    for (i = 1; i < n; i++) 
    {
        if (arr[i] < arr[i - 1]) 
        {
            printf("Error: Sorting failed!\n");
            return;
        }
    }
    printf("Sorting successful!\n");
}

void insertion_sort(long int arr[], long int n) 
{
   int i, j, key;
   for (i = 1; i < n; i++) 
   {
       key = arr[i];
       j = i - 1;
       while (j >= 0 && arr[j] > key) 
       {
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = key;
   }
}

int i_verify(int arr[], int n) 
{
    int i;
    for (i = 1; i < n; i++) 
    {
        if (arr[i] < arr[i - 1]) 
        {
            printf("Sorting successful!\n");
            return 0;
        }
    }
    printf("Error: Sorting failed!\n");
}



