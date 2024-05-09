#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[], int low , int high)
{
    int pivot = arr[high];
    int i = low;
    for(int j = low ; j < high ; j++)
    {
        if(arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;    
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}
void quicksort_rec(int arr[], int low , int high)
{
    if(low < high)
    {
        int pivot = partition(arr,low, high);
        quicksort_rec(arr,low,pivot - 1);
        quicksort_rec(arr,pivot + 1 , high);
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
    quicksort_rec(arr,0,n-1);
    end = clock();
    double tt = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.7f", tt); 
    /*for(int i = 0 ; i < n ; i++)
    {
        printf("%d\t",arr[i]);
    }*/
    return 0;
}