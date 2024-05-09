#include <stdio.h>
#include <stdlib.h>
#define size 5
int front = -1;
int rear = -1;
int queue[size];

void enqueue(int x)
{
    if((rear+1)%size == front )
        printf("Queue is full\n");
    else
    {
        front = 0;
        rear = (rear + 1)%size;
        queue[rear] = x;    
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
        printf("Queue is empty\n");
    else if(front == rear)
    {
        int x = queue[front];
        printf("%d has been dequeued\n",x);
        front = -1;
        rear = -1;
    }
    else
    {
        int b = queue[front];
        printf("%d has been dequeued\n",b);
        front = (front + 1)%size;
    }
}

void display()
{
    int i = front;
    while(i!=rear)
    {
        printf("%d\t",queue[i]);
        i = (i+1)%size;
    }
    printf("%d",queue[i]);
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