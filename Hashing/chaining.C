#include <stdio.h>
#include <stdlib.h>
#define size 10

struct node
{
    int data;
    struct node *next;
};

struct node *HashTable[size] = {NULL};    

void insert(int key)
{
    int index;
    index = key % size;
    struct node *nn, *temp;
    nn = (struct node*)malloc(sizeof(struct node));
    nn -> data = key;
    nn -> next = NULL;
    if(HashTable[index]==NULL)
    {
        HashTable[index] = nn;
    }
    else
    {
        temp = HashTable[index];
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = nn;
    }
}

void display()
{
    struct node* temp;
    for(int i = 0 ; i < size ; i++)
    {
        temp = HashTable[i];
        while(temp!=NULL)
        {
            printf("%d\t",temp -> data);
            temp = temp -> next;
        }
    }
}


int main()
{
  
    int flag = 1;
    int key, choice;
    while(flag == 1)
    {
        printf("Enter the key you want to insert:");
        scanf("%d", &key);
        insert(key);
        printf("Enter 1 to continue and 0 to exit: ");
        scanf("%d", &choice);
        if(choice == 1)
            flag = 1;
        else
            flag = 0;
    }
    display();
    return 0; 
}