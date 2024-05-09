#include<stdio.h>   
#include <stdlib.h>
#include <time.h> 
 void print(int a[], int n)  
    {  
    int i;  
    for(i = 0; i < n; i++)    
    {    
        printf("%d ",a[i]);    
    }        
    }  
 void bubble(int a[], int n) 
 {  
   int i, j, temp;  
   for(i = 0; i < n; i++)    
    {    
      for(j = i+1; j < n; j++)    
        {    
            if(a[j] < a[i])    
            {    
                temp = a[i];    
                a[i] = a[j];    
                a[j] = temp;     
            }     
        }     
    }     
 }  
int main()    
{    
    int i, j,temp;     
    clock_t start, end;
    int n = 10000;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = rand();
    }
    start = clock();
    bubble(arr, n); 
    end = clock();
    double tt = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.7f", tt); 
    //printf("\nAfter sorting array elements are - \n");    
    //print(a, n);  
}    