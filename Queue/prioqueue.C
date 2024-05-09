#include <stdio.h>
#include <stdlib.h>
struct node {
    int data, priority;
    struct node *next;
}*start = NULL;
void create()
{
    int nodes , data , p;
    struct node *nn, *temp;
    printf("Enter nodes :");
    scanf("%d", &nodes);
    for(int i = 0; i < nodes; i++)
    {
        printf("Enter data and priority: ");
        scanf("%d %d", &data , &p);
        nn = (struct node *)malloc(sizeof(struct node));
        nn -> data = data;
        nn -> priority = p;
        if(start == NULL || nn->priority <= start -> priority)
        {
            nn -> next = start;
            start = nn;
        }
        else
        {
            temp = start;
            while(temp-> next != NULL && temp -> next -> priority <= nn -> priority)
            {
                temp = temp -> next;
            }
            nn -> next = temp -> next;
            temp -> next = nn;
        }
    }
}

void enqueue()
{
    struct node *nn , *temp;
    nn = (struct node *)malloc(sizeof(struct node));
    int data, p;
    printf("Enter data and priority: ");
    scanf("%d %d", &data , &p);
    nn -> data = data;
    nn -> priority = p;
    nn -> next = NULL;
    if(start == NULL)
    {
        start = nn;
    }
    else
    {
        temp = start;
        while(temp -> next != NULL && temp -> next -> priority <= nn -> priority)
        {
            temp = temp -> next;
        }
        nn -> next = temp -> next;
        temp -> next = nn;
    }
}

void dequeue()
{
    struct node* temp;
    temp = start;
    if(!start)
        printf("Queue is empty");
    else
    {
        printf("Deleting %d with priority %d", temp -> data, temp -> priority);
        start = start -> next;
        free(temp);
    }    
}

void display()
{
    struct node *temp;
    temp = start;
    while(temp -> next)
    {
        printf("%d with priority %d\n", temp -> data, temp -> priority);
        temp = temp -> next;
    }
    printf("%d with priority %d", temp -> data, temp -> priority);
}
int main() {
	int ch;
	create();
	do {
		printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
		scanf("%d", &ch);
		switch (ch) {
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("Invalid choice\n");
		}
	} while (ch != 4);
	return 0;
}