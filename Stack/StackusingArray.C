#include <stdio.h>
#include <stdlib.h>
#define size 5
int stack[size];
int top = -1;

void push(int x)
{
    if(top == size - 1)
        printf("Stack is full");
    else {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if(top == -1)
        printf("Stack underflow");
    else{
        printf("\n%d has been popped",stack[top]);
        top --;
    }
}

void peek()
{
     if(top == -1)
        printf("Stack underflow");
    else
        printf("%d",stack[top]);
}

void display()
{
    int i;
     if(top == -1)
        printf("Stack underflow");
    else{
        for(i = top ; i >= 0 ; i--)
        {
            printf("\n%d", stack[i]);
        }
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