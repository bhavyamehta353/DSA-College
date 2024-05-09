#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define size 10000
int a[size];

void Maxsearch(int low, int high, int *max, int *min) 
{
    if (low == high) 
    {
        *max = *min = a[low];
    } 
    else if (low == high - 1) 
    {
        if (a[low] < a[high]) 
        {
            *min = a[low];
            *max = a[high];
        } 
        else 
        {
            *min = a[high];
            *max = a[low];
        }
    } 
    else 
    {
        int mid = (low + high) / 2;
        int max1, min1, max2, min2;
        Maxsearch(low, mid, &max1, &min1);
        Maxsearch(mid + 1, high, &max2, &min2);

        if (max1 > max2) 
        {
            *max = max1;
        } 
        else 
        {
            *max = max2;
        }
        if (min1 < min2) 
        {
            *min = min1;
        } else 
        {
            *min = min2;
        }
    }
}

int main() 
{
    int max, min;
    clock_t start, end;
    double timetaken;
    //printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) 
    {
        a[i] = rand();
    }
    start = clock();
    Maxsearch(0, size - 1, &max, &min);
    end = clock();
    timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken : %.7f", timetaken);
    printf("\nMaximum: %d\n", max);
    printf("Minimum: %d\n", min);
    return 0;
}
