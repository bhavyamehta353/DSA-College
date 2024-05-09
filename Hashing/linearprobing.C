#include <stdio.h>
#include <stdlib.h>
#define size 10
int hashtable[size] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

void probe(int index, int key)
{
    int probe;
    int i;
    for(i = 0 ; i < size ; i++)
        {
            probe = (index + i)%10;
            if(hashtable[probe] == -1)
            {
                hashtable[probe] = key;
                break;
            }
        }
    if(i == size)
        printf("Hash table is full, cannot insert");
}
void insert(int key)
{
    int index;
    index = key % size;
    if(hashtable[index] == -1)
        hashtable[index] = key;
    else
        probe(index, key);
}

void display()
{
    for(int i = 0; i < size; i++)
    {
        printf("%d\t", hashtable[i]);
    }
}

int main()
{
    int key, choice;
    do
    {
        printf("Enter the key you want to insert:");
        scanf("%d", &key);
        insert(key);
        printf("Enter 1 to continue and 0 to exit: ");
        scanf("%d", &choice);
    } while(choice == 1);
    display();
    return 0; 
}