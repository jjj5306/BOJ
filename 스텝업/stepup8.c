#include <stdio.h>
#include <stdlib.h>
#define NODE 100

int adj[NODE][NODE];
int vsize;
char vdata[NODE];
int visited[NODE];

void init()
{
    vsize = 0;
    for (int i = 0; i < NODE; i++)
        for (int j = 0; j < NODE; j++)
            adj[i][j] = 0;
}

int is_full()
{
    if (vsize > NODE)
        return 1;
    else
        return 0;
}

void insert_vertex(char name)
{
    if (is_full() == 1)
    {
        printf("ful\n");
    }
    else
        vdata[vsize++] = name;
}

void insert_edge(int u, int v, int value)
{
    adj[u][v] = value;
    adj[v][u] = value;
}

void DFS_search(int n)
{
    if (visited[n])
        return;
    printf("%c ", vdata[n]);
    visited[n] = 1;

    // vertex는 n행 col열 중 가장 가까운 곳으로 dfs 호출
    for (int col = 0; col < NODE; col++)
    {
        if (!visited[col] && adj[n][col])
            DFS_search(col);
    }
}

int main(void)
{
    int node;
    init();
    for (int i = 0; i < 8; i++)
        insert_vertex('A' + i);
    insert_edge(0, 1, 1);
    insert_edge(0, 2, 1);
    insert_edge(1, 3, 1);
    insert_edge(2, 3, 1);
    insert_edge(2, 4, 1);
    insert_edge(3, 5, 1);
    insert_edge(4, 6, 1);
    insert_edge(4, 7, 1);
    insert_edge(6, 7, 1);
    scanf("%d", &node);
    DFS_search(node);
    printf("\n");
    return 0;
}
