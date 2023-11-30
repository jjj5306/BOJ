/** BFS 13549 숨바꼭질 3 **/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 100002
using namespace std;

int dist[MAX];
int N, K;
queue<int> Q;

void tp(int x)
{
    int temp = x;
    if (x == 0)
        return;
    while (temp < MAX)
    {
        if (dist[temp] == -1)
        {
            dist[temp] = dist[x];
            Q.push(temp);
            if (temp == K)
                return;
        }
        temp *= 2;
    }
}
int bfs()
{
    dist[N] = 0;
    Q.push(N);
    tp(N);
    while (dist[K] == -1)
    {
        int cur = Q.front();
        Q.pop();
        for (int next : {cur + 1, cur - 1})
        {
            if (next < 0 || next >= MAX)
                continue;
            if (dist[next] != -1)
                continue;
            dist[next] = dist[cur] + 1;
            Q.push(next);
            tp(next);
        }
    }
    return dist[K];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < MAX; i++)
        dist[i] = -1;
    cout << bfs();
}
