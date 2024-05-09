#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
char input[20];
char stack[20];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

void pop()
{
    top --;
}
int main()
{
    printf("Input :");
    scanf("%s", input);
    int i;
    for(i = 0; i <strlen(input); i++)
    {
        char x = input[i];
        if(top == -1)
            push(x);
        else if((stack[top] == '(' && x == ')') || ((stack[top] == '{' && x == '}')) || ((stack[top] == '[' && x == ']')))
            pop();
        else 
            push(x);
    }

    if(top == -1)
        printf("Balanced");
    else
        printf("Not Balanced");
    return 0;
}