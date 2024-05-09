#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *next;
    struct node *prev;
    int data;
}*start = NULL;

void create()
{
    struct node *nn, *temp;
    int n,i;
    printf("Enter number of nodes :");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        nn = (struct node *)malloc(sizeof(struct node));
        int data;
        printf("Enter data :");
        scanf("%d", &data);
        nn -> data = data;
        nn -> next = NULL;
        nn -> prev = NULL;
        if(start == NULL)
        {
            start = nn;
            temp = start;
        }
        else
        {
            temp -> next = nn;
            nn -> prev = temp;
            temp = temp -> next;
        }
    }
}

void insertbeg(int x)
{
       struct node *nn;
       nn = (struct node *)malloc(sizeof(struct node));
       nn -> data = x ;
       if(start == NULL)
       {
            start = nn;
       }
       else
       {
            start -> prev = nn; 
            nn -> next = start;
            start = nn;
       }  
}

void insertbefore()
{
    struct node *nn, *temp,*pre;
    int data;
    printf("\nEnter data before which you want to insert :");
    scanf("%d", &data);
    int insert;
    printf("Enter data you want to insert :");
    scanf("%d", &insert);
    nn = (struct node *)malloc(sizeof(struct node));
    nn ->data = insert;
    nn -> next = NULL;
    nn -> prev = NULL;
    temp = start;
    while(temp -> data != data)
    {
        pre = temp;
        temp = temp -> next;
    }
    pre -> next = nn;
    temp -> prev = nn;
    nn -> prev = pre;
    nn-> next = temp;
}

void insertafter()
{
    struct node *nn, *temp,*post;
    int data;
    printf("\nEnter data after which you want to insert :");
    scanf("%d", &data);
    int insert;
    printf("Enter data you want to insert :");
    scanf("%d", &insert);
    nn = (struct node *)malloc(sizeof(struct node));
    nn ->data = insert;
    nn -> next = NULL;
    nn -> prev = NULL;
    temp = start;
    while(temp -> data != data)
    {
        temp = temp -> next;
    }
    post = temp -> next;
    temp -> next = nn;
    post -> prev = nn;
    nn-> next = post;
    nn-> prev = temp;
}

void deletell()
{
    struct node *nn, *temp,*post, *pre;
    int data;
    printf("\nEnter data to delete:");
    scanf("%d", &data);
    temp = start;
    while(temp -> data != data)
    {
        pre = temp;
        temp = temp -> next;
    }
    post = temp -> next;
    pre -> next = post;
    post -> prev = pre;
    free(temp);
}

void display()
{
    struct node *temp;
    temp = start;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d\t", temp -> data);
        temp = temp -> next;
    }
}

int main()
{
    create();
    display();
    insertbeg(5);
    display();
    insertbefore();
    display();
    insertafter();
    display();
    deletell();
    display();
}