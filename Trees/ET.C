#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define sn struct node
char postfix[20];
struct node {
    char data;
    struct node *left, *right;
    struct node *next;
}*root = NULL;

sn *stack[20] = {NULL};
void push(struct node *x)
{
    if(!root)
        root = x;
    else
    x -> next = root;
    root = x;
}

struct node *pop()
{
    sn * pop = root;
    root = root -> next;
    return pop;
}

void inorder(struct node *root)
{
    if(root)
    {
        inorder(root -> left);
        printf("%c", root -> data);
        inorder(root -> right);
    }
}
int main()
{
    printf("Enter postfix expression :");
    scanf("%s", postfix);
    char ch;
    struct node *x, *y, *z;
    for(int i = 0; postfix[i] != '\0' ; i++)
    {
        ch = postfix[i];
        if(isalnum(ch))
        {   
            x = (sn *)malloc(sizeof(sn));
            x -> data = ch;
            x -> right = x -> left = NULL;
            x -> next = NULL;
            push(x);
        }
        else
        {
             x = (sn *)malloc(sizeof(sn));
             x -> data = ch;
             y = pop();
             z = pop();
             x -> right = y;
             x -> left = z;
             push(x);
        }
    }
    inorder(root);
}