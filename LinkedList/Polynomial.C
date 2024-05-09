#include <stdio.h>
#include <stdlib.h>
struct node{
    int exp, coeff;
    struct node *next;
} *start3 = NULL, *start2 = NULL;

struct node *create(struct node *start, int c , int e)
{
    struct node *nn, *temp;
    nn = (struct node *)malloc(sizeof(struct node));
    nn -> exp = e;
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
        temp = temp -> next;
    }
    return start;
}

struct node *polyadd(struct node *p1, struct node *p2, struct node *sum)
{
    struct node *poly1 = p1;
    struct node *poly2 = p2;
    struct node *temp;
    if(poly1 == NULL)
    {
        sum = poly2;
        return sum;
    }
    else if(poly2 == NULL)
    {
        sum = poly1;
        return sum;
    }
    else
    {
        while(poly1 != NULL && poly2 != NULL)
        {
           sum = (struct node *)malloc(sizeof(struct node));
            if(start3 == NULL)
            {
                start3 = sum;
                temp = start3;
            }
            else
            {
                temp -> next = sum;
                temp = temp -> next;
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
            else if(poly1 -> exp == poly2 -> exp)
            {
                sum -> exp = poly2 -> exp;
                sum -> coeff = poly2 -> coeff + poly1 -> coeff;
                poly1 = poly1 -> next;
                poly2 = poly2 -> next;
            }
        }
        while(poly1 != NULL)
        {
            sum = (struct node *)malloc(sizeof(struct node));
            temp -> next = sum;
            temp = temp -> next;
            sum -> exp = poly1 -> exp;
            sum -> coeff = poly1 -> coeff;
           poly1 = poly1 -> next;
        }
         while(poly2 != NULL)
        {
            sum = (struct node *)malloc(sizeof(struct node));
            temp -> next = sum;
            temp = temp -> next;
            sum -> exp = poly2 -> exp;
            sum -> coeff = poly2 -> coeff;
            poly2 = poly2 -> next;
        }
        temp -> next = NULL;
            return start3;
    }
}

struct node *polysub(struct node *p1, struct node *p2, struct node *diff)
{
    struct node *poly1 = p1;
    struct node *poly2 = p2;
    struct node *temp;
    if(poly1 == NULL)
    {
        diff = poly2;
        return diff;
    }
    else if(poly2 == NULL)
    {
        diff = poly1;
        return diff;
    }
    else
    {
        while(poly1 != NULL && poly2 != NULL)
        {
            diff = (struct node *)malloc(sizeof(struct node));
            if(start2 == NULL)
            {
                start2 = diff;
                temp = start2;
            }
            else
            {
                temp -> next = diff;
                temp = temp -> next;
            }
            if(poly1 -> exp > poly2 -> exp)
            {
                diff -> exp = poly1 -> exp;
                diff -> coeff = poly1 -> coeff;
                poly1 = poly1 -> next;
            }
            else if(poly1 -> exp < poly2 -> exp)
            {
                diff -> exp = poly2 -> exp;
                diff -> coeff = -(poly2 -> coeff);
                poly2 = poly2 -> next;
            }
            else
            {
                diff -> exp = poly1 -> exp;
                diff -> coeff = poly1 -> coeff - (poly2 -> coeff);
                poly1 = poly1 -> next;
                poly2 = poly2 -> next;
            }
        }
        while(poly1 != NULL)
        {
            diff = (struct node *)malloc(sizeof(struct node));
            temp -> next = diff;
            temp = temp -> next;
            diff -> exp = poly1 -> exp;
            diff -> coeff = poly1 -> coeff;
            poly1 = poly1 -> next;
        }
         while(poly2 != NULL)
        {
            diff = (struct node *)malloc(sizeof(struct node));
            temp -> next = diff;
            temp = temp -> next;
            diff -> exp = poly2 -> exp;
            diff -> coeff = -(poly2 -> coeff);
            poly2 = poly2 -> next;
        }
        temp -> next = NULL;
        return start2;
    }
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
    struct node *p1 = NULL;
    struct node *p2 = NULL;
    p1 = create(p1,3,2);
    p1 = create(p1,5,1);
    p1 = create(p1,2,0);
    p2 = create(p2,6,3);
    p2 = create(p2,6,1);
    struct node *sum = NULL;
    struct node *diff = NULL;
    sum = polyadd(p1, p2, sum);
    display(sum);
    diff = polysub(p1,p2,diff);
    display(diff);
    return 0;
}