#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int top = - 1;
int stack[20];
char prefix[20];

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    int x = stack[top];
    top --;
    return x;
}
int main()
{
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    int i;
    int len = strlen(prefix);
    for(i = len -1 ; i >= 0 ; i--)
    {
        int x = prefix[i];
        if(isdigit(x))
            push(x-'0');
        else 
        {
            int op1 = pop();
            int op2 = pop();
            switch(x)
            {
                case '+':
                push(op1 + op2);
                break;

                case '-':
                push(op1 - op2);
                break;

                case '*':
                push(op1 * op2);
                break;

                case '/':
                push(op1 / op2);
                break;

                case '^':
                push(pow(op1, op2));
                break;

                case '%':
                push(op1%op2);
                break;
            }
        }
    }
    if(top == 0)
        printf("Ans : %d", stack[top]);
    else
        printf("Not a valid prefix expression");
    return 0;
}
