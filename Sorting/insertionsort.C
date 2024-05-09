#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertionsort(int arr[], int n)
{
    int i,j,key;
    for(i = 1 ; i <n ; i++)
    {
        key = arr[i];
        j = i-1;
        while(j >= 0  && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    clock_t start, end;
    int n = 10000;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = rand();
    }
    start = clock();
    insertionsort(arr, n);
    end = clock();
    double tt = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.7f", tt);
   /* for(int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    } */
    return 0;
}