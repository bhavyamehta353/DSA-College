#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
}*top = NULL;

void push(int x)
{    
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn -> data = x;
    nn -> next = top;
    top = nn;
}

void pop()
{
    struct node *temp;
    if(top == NULL)
        printf("Stack underflow");
    else
    {
        temp = top;
        top = top -> next;
        free(temp);
    }
}

void peek()
{
    if(top == NULL)
        printf("Stack underflow");
    else
        printf("%d", top -> data);
}

void display()
{
    struct node *temp;
    temp = top;
    while(temp != NULL)
    {
        printf("\n%d", temp ->data);
        temp = temp -> next;
    }
}

int main()
{
    while(1)
    {
        int choice;
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit");
        printf("\nYour choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            int num;
            printf("Enter number: ");
            scanf("%d", &num);
            push(num);
            break;

            case 2:
            pop();
            break;
            
            case 3:
            peek();
            break;

            case 4:
            display();
            break;

            case 5:
            exit(0);
            break;

            default:
            printf("Enter a valid choice:");
            break;
        }
    }
    return 0;
}