#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char infix[50];
char prefix[50];
char stack[50];
int top = -1;
int getpriority(char x)
{
    if(x == '^')
        return 3;
    if(x == '*' || x == '/' || x == '%')
        return 2;
    if(x == '+' || x == '-')
        return 1; 
    return 0;
}

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    char c = stack[top];
    top --;
    return c;
}
int main()
{
    printf("Enter infix : ");
    scanf("%s", infix);
    int len = strlen(infix);
    int i;
    int j = 0;
    for(i = len-1 ; i >= 0 ; i--)
    {
        char x = infix[i];
        if(isalpha(x) || isdigit(x))
            prefix[j++] = x;
        else if(x == ')')
            push(x);
        else if(x == '(')
        {
            while(stack[top]!=')')
            {
                char b = pop();
                prefix[j++] = b;
            }
            pop();
        }
        else if(top == -1 || getpriority(x) >= getpriority(stack[top]))
            push(x);
        else
        {
            while(getpriority(x) < getpriority(stack[top]))
            {
                char c = pop(); 
                prefix[j++] = c;
            }
            push(x);
        }
    }
    while(top >= 0)
    {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    printf("\n%s", strrev(prefix));
    return 0;
}
