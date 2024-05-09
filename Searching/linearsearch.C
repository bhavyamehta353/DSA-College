#include <stdio.h>

int linearsearch(int arr[], int x)
{
    int key;
    scanf("%d", &key);
    for(int i = 0; i < 10 ; i++)
    {
        if(key == arr[i])
        {
            return 1;
        }
    } 
    return 0;
}
int main()
{
    int arr[10]= {1,4,5,6,3,2,7,8,9,10};
    int a = linearsearch(arr,10);
    a > 0 ? printf("Found") : printf("Not found");
    return 0;
}