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
    {0, 1, 0, 0, 0, 0, 1, 0}
};

int stack[MAX_VERTICES];
int top = -1;

int visited[MAX_VERTICES];

void push(int vertex) {
    if (top == MAX_VERTICES - 1) {
        printf("Stack is full. Cannot push.\n");
    } else {
        top++;
        stack[top] = vertex;
    }
}

int pop() {
    int vertex;
    if (top == -1) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    } else {
        vertex = stack[top];
        top--;
        return vertex;
    }
}

void dfs(int startVertex, int numVertices) {
    int i, currentVertex;

    // Mark all vertices as not visited
    for (i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    // Push the start vertex onto the stack and mark it as visited
    push(startVertex);

    // Process vertices in the stack
    while (top != -1) {
        // Pop a vertex and print it if not visited
        currentVertex = pop();
        if (!visited[currentVertex]) {
            printf("%d\t", currentVertex);
            visited[currentVertex] = 1;
        }

        // Push adjacent vertices of the popped vertex that are not visited
        for (i = numVertices - 1; i >= 0; i--) {
            if (adjacencyMatrix[currentVertex][i] && !visited[i]) {
                push(i);
                break;
            }
        }
    }

    printf("\n");
}

int main() {
    int startVertex;

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal starting from vertex %d:\n", startVertex);
    dfs(startVertex, MAX_VERTICES);

    return 0;
}
