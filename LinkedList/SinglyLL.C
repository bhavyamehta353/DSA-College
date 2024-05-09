#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*start = NULL;

void create()
{
     int nodes;
    printf("Enter the number of nodes:");
    scanf("%d", &nodes);
    int i;
    struct node * nn, *temp;
    for(i = 0; i < nodes; i++)
    {
        int data;
        nn = (struct node *)malloc(sizeof(struct node));
        printf("Enter value :");
        scanf("%d", &data);
        nn -> data = data;
        nn -> next = NULL;
        if(start == NULL)
        {
            start = nn;
            temp = start;
        }
        else
        {
            temp -> next = nn;
            temp = temp-> next;
        }
    }
}

void insertbeg()
{
    int data;
    printf("Enter value to be inserted at beginning:");
    scanf("%d", &data);
    struct node* nn = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    temp = start;
    nn -> data = data;
    nn -> next = start;
    start = nn;
}

void insertbefore()
{
    struct node* nn, *temp, *pre;
    temp = start;
    int data;
    printf("Enter value before you want to insert a new node:");
    scanf("%d", &data);
    while(temp -> data != data)
    {
        pre = temp;
        temp = temp -> next;
    }
    nn = (struct node *)malloc(sizeof(struct node));
    printf("Enter value of new node :");
    int value;
    scanf("%d", &value);
    nn -> data = value;
    if(temp == start)
    {
        nn -> next = start;
        start = nn;
    }
    else
    {
        pre -> next = nn;
        nn -> next = temp;
    }
}

void insertafter()
{
    struct node* nn, *temp, *post;
    nn = (struct node*)malloc(sizeof(struct node));
    printf("Enter value of new node :");
    int value;
    scanf("%d", &value);
    temp = start;
    nn->data = value;
    int data1;
    printf("Enter value after which you want to insert a new node:");
    scanf("%d", &data1);
    while(temp -> data != data1)
    {
        temp = temp -> next;
    }
    post = temp -> next;
    temp -> next = nn;
    nn -> next = post; 
}

void deletell()
{
    struct node *temp, *pre, *post;
    int data;
    printf("Enter data you want to delete:");
    scanf("%d", &data);
    temp = start;
    while(temp -> data != data)
    {
        pre = temp;
        temp = temp -> next;
    }
    post = temp -> next;
    if(temp == NULL)
        printf("Value not found");
    else if(temp == start)
    {
        start = start -> next;
        free(temp);
    }
    else
    {
        pre -> next = post;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp = start;
    while(temp != NULL)
    {
        printf("%d\n", temp -> data);
        temp = temp -> next;
    }
}

int main()
{
    create();
    display();
    insertbeg();
    display();
    insertbefore();
    display();
    insertafter();
    display();
    deletell();
    display();
}