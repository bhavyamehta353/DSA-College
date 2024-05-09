#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int binarysearch(int arr[],int x)
{
    int l = 0;
    int r = x-1;
    int key;
    printf("Enter key :");
    scanf("%d", &key);
    while(l<=r)
    {
         int mid = l + (r-l)/2;
        if(key < arr[mid])
        {
            r = mid - 1;
        }
        else if(key > arr[mid])
        {
            l = mid + 1;
        }
        else if(key == arr[mid])
            return 1;
    }
    return 0; 
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
    int a = binarysearch(arr,10);
    end = clock();
    double tt = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.7f", tt); 
   // a > 0 ? printf("Found") : printf("Not found");
    return 0;
}