#include <stdio.h> 
#include <stdlib.h> 
#define size 8
int adj[8][8] = {
                  {0, 1, 1, 1, 0, 0, 0, 0},
                {1, 0, 0, 0, 1, 0, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 1, 0, 0},
                {0, 1, 0, 0, 0, 0, 1, 0},
                {0, 0, 0, 1, 0, 0, 1, 0},
                {0, 0, 0, 0, 1, 1, 0, 1},
                {0, 1, 0, 0, 0, 0, 1, 0},
                };
int visited[10] = {0};
int queue[10];
int rear = -1;
int front = -1;

void enqueue(int x)
{
    if(rear == size - 1)
        printf("FULL");
    else
    {
        if(front == -1)
            front = 0;
        queue[++rear] = x;
    }
}
int dequeue()
{
    if(front == -1 && rear == -1)
        printf("EMPTY");
    else if(front == rear)
    {
        int x = queue[front];
        front = -1;
        rear = -1;
        return x;
    }
    return queue[front++];
}
void bfs(int sv)
{
    int v;
    enqueue(sv);
    visited[sv] = 1;
    while(front !=-1)
    {
        v = dequeue();
        printf("%d\t", v);
        for(int i = 0; i < size; i++)
        {
            if(adj[v][i] && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    int sv;
    printf("Enter starting vertex:");
    scanf("%d",&sv);
    bfs(sv);
    return 0;
}