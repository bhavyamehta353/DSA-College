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
    void dfs(int sv)
    {
        visited[sv] = 1;
        printf("%d\t",sv);
        for( int i = 0 ; i < size ; i++)
            {
                if(adj[sv][i] && !visited[i])
                    dfs(i);
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