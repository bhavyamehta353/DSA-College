#include <stdio.h>
int indegree[8], visited[8] = {0};
int a[8][8] = {
    {0 ,1, 1, 0, 0, 0, 0, 0},
    {0, 0, 1 ,1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 1, 0}, 
};
int queue[8];
int front = -1;
int rear = -1;
void indeg()
{
    int i, j, count;
    for (i = 0; i < 8; i++)
    {
        count = 0;
        for (j = 0; j < 8; j++)
            count += a[j][i];
        indegree[i] = count;
    }
}
void enqueue(int x)
{
    if(rear == 7)
        printf("Queue full");
    else
    {
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = x;
    }
}

int dequeue()
{   
    if(rear == -1 && front == -1)
        printf("Queue is empty");
    else if(front == rear)
    {
        int value = queue[front];
        front = -1;
        rear = -1;
        return value;
    }
    return queue[front++];
}
void topological_sort()
{
    int v; //vertex
    for(int i = 0; i < 8; i++)
    {  
        if(indegree[i] == 0 && !visited[i])
        {
            enqueue(i);
            visited[i] = 1;
        }
    }  
    while(front != -1)
    {
        v = dequeue();
        for(int j = 0 ; j < 8 ; j++)
        {
            if(a[v][j] == 1)
            {
                indegree[j]--;
            }
            if(indegree[j] == 0 && !visited[j])
            {
                enqueue(j);
                visited[j] = 1;
            }
        }
        printf("%d\t", v);
    }
}

int main()
{
    indeg();
    printf("Topological Sorting(one of the output):\n");
    topological_sort();
    return 0;
}