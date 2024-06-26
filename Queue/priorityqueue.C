#include <stdio.h>
#include <conio.h>
#include <malloc.h>

#define sn struct Node

sn {
	int data;
	int priority;
	sn *next;
} *front = NULL;

void create() {
	sn *temp, *newnode;
	int data, priority, n, i;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("Enter the data and priority: ");
		scanf("%d %d", &data, &priority);
		newnode = (sn *)malloc(sizeof(sn));
		newnode->data = data;
		newnode->priority = priority;
		if (!front || priority <= front->priority) {
			newnode->next = front;
			front = newnode;
		}
		else {
			temp = front;
			while (temp->next && temp->next->priority <= priority)
				temp = temp->next;
			newnode->next = temp->next;
			temp->next = newnode;
		}
	}
}

void display() {
	sn *temp;
	if (!front)
		printf("Queue is empty\n");
	else {
		temp = front;
		while (temp) {
			printf("%d with priority %d\n", temp->data, temp->priority);
			temp = temp->next;
		}
	}
}

void enqueue() {
	sn *temp, *newnode = (sn *)malloc(sizeof(sn));
	int data, priority;
	printf("Enter the data and priority: ");
	scanf("%d %d", &data, &priority);
	newnode->data = data;
	newnode->priority = priority;
	newnode->next = NULL;
	if (!front)
		front = newnode;
	else {
		temp = front;
		while (temp->next && temp->next->priority <= priority)
			temp = temp->next;
		newnode->next = temp->next;
		temp->next = newnode;
	}
}

void dequeue() {
	sn *temp;
	if (!front)
		printf("Queue is empty\n");
	else {
		temp = front;
		front = front->next;
		printf("%d with priority %d is deleted\n", temp->data, temp->priority);
		free(temp);
	}
}

int main() {
	int ch;
	create();
	do {
		printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
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