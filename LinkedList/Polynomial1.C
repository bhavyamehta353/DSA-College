#include <stdio.h>
#include <stdlib.h>

struct node{
    int exp, coeff;
    struct node *next;
}*start = NULL;

struct node *create(struct node *start, int c , int p)
{
    struct node *nn, *temp;
    nn = (struct node *)malloc(sizeof(struct node));
    nn -> exp = p;
    nn -> coeff = c;
    nn -> next = NULL;
    if(start == NULL)
    {
        start = nn;
        temp = start;
    }
    else
    {
      
        temp -> next = nn;
        temp = nn;
    }
    return start;
}

struct node *add(struct node *p1, struct node *p2)
{
    struct node *poly1 , *poly2;
    struct node *sum;
    struct node *temp;
    temp = sum;
    poly1 = p1;
    poly2 = p2;
    if(p1 == NULL)
        return p2;
    if(p2 == NULL)
        return p1;
    while(poly1 != NULL && poly2 != NULL)
    {
        sum = (struct node *)malloc(sizeof(struct node));
        if(start == NULL)
        {
            start = sum;
            temp = start;
        }
        else
        {
            temp -> next = sum;
            temp = sum;
        }
        
        if(poly1 -> exp > poly2 -> exp)
        {
            sum -> exp = poly1 -> exp;
            sum -> coeff = poly1 -> coeff;
            poly1 = poly1 -> next;
        }
        else if(poly1 -> exp < poly2 -> exp)
        {
            sum -> exp = poly2 -> exp;
            sum -> coeff = poly2 -> coeff;
            poly2 = poly2 -> next;
        }
        else if(poly1 -> coeff == poly2 -> coeff)
        {
            sum -> exp = poly1 -> exp;
            sum -> coeff = poly1 -> coeff + poly2 -> coeff;
            poly1 = poly1 -> next;
            poly2 = poly2 -> next;
        }
    }
    while(poly1 != NULL)
    {
         sum = (struct node *)malloc(sizeof(struct node));
         temp -> next = sum;
         temp = sum;
         sum -> coeff = poly1 -> coeff;
         sum -> exp = poly1 -> exp;
         poly1 = poly1 -> next;
    }
     while(poly2 != NULL)
    {
         sum = (struct node *)malloc(sizeof(struct node));
         temp -> next = sum;
         temp = sum;
         sum -> coeff = poly2 -> coeff;
         sum -> exp = poly2 -> exp;
         poly2 = poly2 -> next;
    }
    temp -> next = NULL;
    return start;
}
void display(struct node *start)
{
    struct node *temp;
    temp = start;
    while(temp!= NULL)
    {
        printf("%dx^%d", temp -> coeff, temp -> exp);
        if(temp -> next != NULL)
        {
            if(temp -> next -> coeff > 0)
                printf("+");
            else
                printf(" ");
        }
        temp = temp -> next;
    }
    printf("\n");
}
int main()
{
    struct node *p1 = NULL, *p2 = NULL;
    int c,p,n1, n2;
    printf("Enter number of terms in polynomial 1:");
    scanf("%d",&n1);
    for(int i = 0; i < n1 ; i++)
    {
         printf("Enter coeff and power of p1:");
         scanf("%d %d",&c, &p);
         p1 = create(p1,c,p);
    }
    printf("Enter number of terms in polynomial 2:");
    scanf("%d",&n2);
    for(int i = 0; i < n2 ; i++)
    {
         printf("Enter coeff and power of p2:");
         scanf("%d %d",&c, &p);
         p2 = create(p2,c,p);
    }
    struct node *sum = NULL;
    sum = add(p1,p2);     
    display(sum);
}