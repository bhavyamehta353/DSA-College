#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn -> data = x;
    nn -> next = NULL;
    if(front == NULL && rear == NULL)
    {
        front = rear = nn;
    }
    rear -> next = nn;
    rear = nn;
}

void dequeue()
{   
    struct node* temp = front;
    if(front == NULL && rear == NULL)
        printf("Queue is empty\n");
    else if(front == rear)
    {
        printf("%d is dequeued\n", temp->data);
        front = NULL;
        rear = NULL;
    }
    else
    {
        printf("%d is dequeued",temp->data);
        front = front->next;
    }
    free(temp);
}

void display()
{
    if(front == NULL && rear == NULL)
        printf("Queue is empty\n");
    else
    {
        struct node *temp = front;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp = temp -> next;
        }
    }
}
int main()
{
    while(1)
    {
        printf("\n1.Enque\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nYour choice :");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            printf("\nEnter number :");
            int num;
            scanf("%d", &num);
            enqueue(num);
            break;

            case 2:
            dequeue();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
            break;
    
            default:
            printf("Enter valid choice :");
            break;
        }
    }
}
