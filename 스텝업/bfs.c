#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 20

int adj_matrix[MAX_VERTICES + 1][MAX_VERTICES + 1];
int visited[MAX_VERTICES + 1];

void graph_init()
{
    int vi, vo;
    for (vi = 0; vi < MAX_VERTICES; vi++)
    {
        for (vo = 0; vo < MAX_VERTICES; vo++)
        {
            adj_matrix[vi][vo] = 0;
        }
        visited[vi] = 0;
    }
}

void insert_edge(int u, int v)
{
    adj_matrix[u][v] = 1;
}

typedef int element;
int front, rear;
element queue[MAX_VERTICES + 2];

void init()
{
    front = rear = 0;
}

int is_empty()
{
    return (front == rear);
}

void enqueue(element item)
{
    rear++;
    queue[rear] = item;
}

element dequeue()
{
    front++;
    return queue[front];
}

// BFS를 인접 행렬로 구현
void bfs_list(int v)
{
    init();
    enqueue(v);
    visited[v] = true;
    printf("%d ", v);

    while (!is_empty())
    {
        int cur = dequeue();
        for (int ny = MAX_VERTICES; ny >= 0; ny--)
        {
            if (adj_matrix[cur][ny] && !visited[ny])
            {
                printf("%d ", ny);
                enqueue(ny);
                visited[ny] = 1;
            }
        }
    }
}

int main()
{
    int i;
    graph_init();
    insert_edge(1, 9);
    insert_edge(1, 5);
    insert_edge(1, 2);
    insert_edge(2, 3);
    insert_edge(3, 4);
    insert_edge(5, 8);
    insert_edge(5, 6);
    insert_edge(6, 7);
    insert_edge(9, 10);

    bfs_list(1);
}