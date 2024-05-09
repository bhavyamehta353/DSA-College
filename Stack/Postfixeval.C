#include <stdio.h>
#include <stdlib.h>
#define size 20
int top = -1;
int stack[size];
char postfix[size];

void push(int ch)
{
    if (top == size - 1)
    {
        printf("Stack full\n");
        exit(1);
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack empty\n");
        exit(1);
    }
    else
    {
        int item = stack[top];
        top--;
        return item;
    }
}

int main()
{
    printf("Enter postfix: ");
    scanf("%s", &postfix);
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        int x = postfix[i];
        if (x >= '0' && x <= '9')
            push(x - '0');
        else
        {
            int op2 = pop();
            int op1 = pop();
            switch (x)
            {
            case '+':
                push(op1 + op2);
                break;

            case '-':
                push(op1 - op2);
                break;

            case '/':
                if (op2 == 0)
                {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                push(op1 / op2);
                break;

            case '*':
                push(op1 * op2);
                break;
            }
        }
    }
    int ans = stack[top];
    printf("Result: %d\n", ans);
    return 0;
}
