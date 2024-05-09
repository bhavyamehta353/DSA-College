#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void selectionSort(int arr[], int n)
{
	int i,j,min;
	for(i = 0 ; i < n-1 ; i++)
	{
		min = i;
		for(j = i+1 ; j < n ; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
	clock_t start, end;
	int n = 10000;
	int arr[n];
	for(int i = 0 ; i < n; i++)
	{
		arr[i] = rand();
	}
	start = clock();
	selectionSort(arr, n);
	end = clock();
	double tt = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Time taken : %.9f", tt);
	//printf("\nSorted array: \n");
	//printArray(arr, n);
	return 0;
}
