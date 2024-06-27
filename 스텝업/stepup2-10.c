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
        printf("full\n");
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
    visited[n] = 1;          // 현재 노드를 방문 표시
    printf("%c ", vdata[n]); // 현재 노드 이름 출력
    for (int i = 0; i < vsize; i++)
    {
        if (adj[n][i] != 0 && visited[i] == 0)
        {
            DFS_search(i); // 방문하지 않은 인접 노드가 있으면 재귀적으로 DFS 실행
        }
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
