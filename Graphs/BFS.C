#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 8

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {
                {0, 1, 1, 1, 0, 0, 0, 0},
                {1, 0, 0, 0, 1, 0, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 1, 0, 0},
                {0, 1, 0, 0, 0, 0, 1, 0},
                {0, 0, 0, 1, 0, 0, 1, 0},
                {0, 0, 0, 0, 1, 1, 0, 1},
                {0, 1, 0, 0, 0, 0, 1, 0},
                };      

int queue[MAX_VERTICES];
int front = -1, rear = -1;

int visited[MAX_VERTICES];

void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        vertex = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return vertex;
    }
}

void bfs(int startVertex, int numVertices) {
    int i, currentVertex;

    // Mark all vertices as not visited
    for (i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    // Enqueue the start vertex and mark it as visited
    enqueue(startVertex);
    visited[startVertex] = 1;

    // Process vertices in the queue
    while (front != -1) {
        // Dequeue a vertex and print it
        currentVertex = dequeue();
        printf("%d\t", currentVertex);

        // Enqueue adjacent vertices of the dequeued vertex that are not visited
        for (i = 0; i < numVertices; i++) {
            if (adjacencyMatrix[currentVertex][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main() {
    int startVertex;

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("BFS Traversal starting from vertex %d:\n", startVertex);
    bfs(startVertex, MAX_VERTICES);

    return 0;
}
