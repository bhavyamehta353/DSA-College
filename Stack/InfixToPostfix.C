#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int top = -1;
char infix[20];
char postfix[20];
char stack[20];
int getPriority(char c)
{
    if(c == '^')
        return 3;
    if(c == '/' || c == '*' || c == '%')
        return 2;
    if(c == '+' || c == '-')
        return 1;
    if(c == '(' || c == ')')
        return 0;
    return -1;
}

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    char x = stack[top];
    top --;
    return x;
}

int main()
{
    printf("Enter infix :");
    scanf("%s", &infix);
    int i=0,j=0;
    char x;
    while(infix[i] != '\0')
    {
        x = infix[i];
        if(x == '(')
        {
            push(x);
        }
        else if((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x>= '0' && x<='9'))
        {
            postfix[j++] = x;
        } 
        else if(x == ')')
        {
            while(stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else if(isalnum(x) == 0 && getPriority(x) > getPriority(stack[top]))
        {
            push(x);
        }
        else {
        while(isalnum(x) == 0 && getPriority(x) <= getPriority(stack[top]))
        {
            char b = pop();
            postfix[j] = b;
            j++;
        }
            push(x);
        }
        i++;
    }
    while(top >= 0)
        {
            postfix[j] = pop();
            j++;
        }
    postfix[j] = '\0';
    printf("\n%s", postfix);
    return 0;
}