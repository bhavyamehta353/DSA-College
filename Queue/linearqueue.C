#include <stdio.h>
#include <stdlib.h>
#define size 5
int front = -1;
int rear = -1;
int queue[size];
void enqueue(int x)
{
    if(rear == size - 1)
        printf("Queue full\n");
    else
    {
        front = 0;
        queue[++rear]= x;
    }
}

void dequeue()
{
    if(rear == -1 && front == -1)
        printf("Queue empty\n");
    else if(rear == front)
    {
        int x;
        x = queue[front];
        front = -1;
        rear = -1;
        printf("%d has been dequeued\n", x);
    }
    else
    {
        int b;
        b = queue[front];
        printf("%d has been dequeued\n", b);
        front++;
    }
}

void display()
{
    int i;
    for(i = front ; i <=rear ; i++)
    {
        printf("%d\t", queue[i]);
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