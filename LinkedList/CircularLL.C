#include <stdio.h>
#include <stdlib.h>
int nodes;
struct node {
    int data;
    struct node *next;
}*start = NULL , *tail = NULL;

void create()
{
    struct node *nn, *temp;
    int data;
    int choice = 1;
    do
    {
        printf("Enter data :");
        scanf("%d", &data);
        nn = (struct node *)malloc(sizeof(struct node));
        nn -> data = data;
        nn -> next = NULL;
        if(start == NULL)
        {
            start = tail = nn;
        }
        else
        {
            tail -> next = nn;
            tail =  tail -> next; 
        }
        tail -> next = start;
        printf("Enter 1 to continue and 0 to stop :");
        scanf("%d", &choice);
    }while(choice == 1);
}

void display()
{
    struct node *temp;
    if(tail == NULL)
        printf("List is empty");
    else
    {
        temp = start;
        while(temp!=tail)
        {
            printf("%d\t", temp -> data);
            temp = temp -> next;
        }
        printf("%d\n",temp -> data);
    }
}

void insertbeg()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("Enter data you want to insert :");
    scanf("%d", &data);
    nn -> data = data;
    if(tail == NULL)
    {
        tail == nn;
    }
    else
    {
        nn -> next = tail -> next;
        tail -> next = nn;
        start = nn;
    }
}

void insertend()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("Enter data you want to insert :");
    scanf("%d", &data);
    nn -> data = data;
    if(tail == NULL)
    {
        tail = nn;
    }
    else
    {
        tail -> next = nn;
        nn -> next = start;
        tail = nn;
    }
}

void insert()
{
    int find , choice;
    struct node *nn, *temp, *pre, *post;
    printf("Enter the data before or after which you want to insert:");
    scanf("%d", &find);
    printf("Enter 1 for before and 2 for after:");
    scanf("%d", &choice);
    
    temp = start;
    while(temp -> data != find)
    {            
        pre = temp;
        temp = temp -> next;
    }
    post = temp -> next;
    
    int data;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to insert:");
    scanf("%d", &data);
    nn -> data = data;
    
    if(choice == 1) // before
    {
        if(tail == NULL)
        {
            tail = nn;
        }
        else if(temp == start)
        {
            nn -> next = tail -> next;
            tail -> next = nn;
            start = nn;
        }
        else
        {
            pre -> next = nn;
            nn -> next = temp;
        }
    }
    else
    {
        if(tail == NULL)
        {
            tail = nn;
            tail -> next = nn;
        }
        else if(temp == tail)
        {
            tail -> next = nn;
            tail = nn;
            tail -> next = start;
        }
        else
        {
            temp -> next = nn;
            nn -> next = post;
        }
    }
}

void deletell()
{
    int find;
    struct node *temp, *pre, *post;
    printf("Enter the data you want to delete:");
    scanf("%d", &find);
    temp = start;
    while(temp -> data != find)
    {            
        pre = temp;
        temp = temp -> next;
    }
    post = temp -> next;
    if(temp == start)
    {
        start = post;
        tail -> next = start;
        free(temp);
    }    
    else if(temp == tail)
    {
        tail = pre;
        tail -> next = start;
        free(temp);
    }
    else
    {
        pre -> next = post;
        free(temp);
    }
}
int main()
{
    create();
    display();
    insertbeg();
    display();
    insertend();
    display();
    insert();
    display();
    deletell();
    display();
    insert();
    display();
    return 0;
}