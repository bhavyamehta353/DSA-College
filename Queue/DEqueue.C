#include <stdio.h>
#include <stdlib.h>
#define size 5
int dequeue[size];
int front = -1;
int rear = -1;

void insertrear(int x)
{
    if((rear+1)%size == front)
        printf("Queue is full");
    else if(front == -1 && rear == -1)
    {
            front = rear = 0;
            dequeue[rear] = x;
    }
    else if(rear == size - 1)
    { 
        rear = 0;
        dequeue[rear] = x; 
    }
    else
    {
        rear++;
        dequeue[rear] = x;
    }
}

void insertfront(int x)
{
    if((front == 0 && rear == size - 1) || (rear+1)%size == front)
        printf("Queue is full");
    else if(front == -1 && rear == -1)
    {
            front = rear = 0;
            dequeue[front] = x;
    }
    else if(front == 0)
    {
        front = size - 1;
        dequeue[front] = x;
    }
    else
    {
        front--;
        dequeue[front] = x;
    }
}

void deleterear()
{
    if(front == -1 && rear == -1)
        printf("Queue is empty");
    else if(front == rear)
    {
        printf("Dequeued element is %d", dequeue[rear]);
        front = rear = -1;
    }
    else if(rear == 0)
    {
         printf("Dequeued element is %d", dequeue[rear]);
         rear = size-1;
    }
    else
    {
        printf("Dequeued element is %d", dequeue[rear]);
        rear--;
    }
}

void deletefront()
{
    if(front == -1 && rear == -1)
        printf("Queue is empty");
    else if(front == rear)
    {
        printf("Dequeued element is %d", dequeue[front]);
        front = rear = -1;
    }
    else if(front == size - 1)
    {
        printf("Dequeued element is %d", dequeue[front]);
        front = 0;
    }
    else
    {
         printf("Dequeued element is %d", dequeue[front]);
         front ++;
    }
}
void display()
{
    int i = front;
    printf("\n");
    while(i!=rear)
    {
        printf("%d\t",dequeue[i]);
        i = (i+1)%size;
    }
    printf("%d",dequeue[rear]);
}

int main()
{
    printf("1.INPUT RESTRICTED\n2.OUTPUT RESTRICTED\n");
    int n;
    scanf("%d", &n);
    do
    {
        int ch;
        printf("\n1.Insert from rear\n2.Delete from front\n3.Delete from rear\n4.Display");
        printf("\nEnter your choice :");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            int num;
            printf("Enter number to insert :");
            scanf("%d", &num);
            insertrear(num);
            break;

            case 2:
            deletefront();
            break;

            case 3:
            deleterear(); 
            break; 

            case 4:
            display();
            break;

            default:
            printf("Enter valid choice :");
            break;
        }
    }  while(n = 1);

    do
    {
       int ch;
        printf("\n1.Insert from rear\n2.Insert from front\n3.Delete from front\n4.Display");
        printf("\nEnter your choice :");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            int num;
            printf("Enter number to insert :");
            scanf("%d", &num);
            insertrear(num);
            break;

            case 2:
            int num1;
            printf("Enter number to insert :");
            scanf("%d", &num1);
            insertfront(num1);
            break;

            case 3:
            deletefront(); 
            break; 

            case 4:
            display();
            break;

            default:
            printf("Enter valid choice :");
            break;
        }
    }while(n = 2);
    return 0;
}