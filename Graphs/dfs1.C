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
    int stack[10];
    int top = -1;

    void push(int x)
    {
        if(top == size - 1)
            printf("Full");
        else
            stack[++top] = x;
    }

    int pop()
    {
        int x;
        if(top == -1)
            printf("Empty");
        else
        {
            x = stack[top];
            top --;
        }
        return x;
    }

    void dfs(int sv)
    {
        int v;
        push(sv);
        visited[sv] = 1; 
        while(top>=0)
        {
            v = pop();
            printf("%d\t", v);
            for( int i = size - 1; i>=0; i--)
            {
                if(adj[v][i] && !visited[i])
                {
                    push(i);
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
        dfs(sv);
        return 0;
    }