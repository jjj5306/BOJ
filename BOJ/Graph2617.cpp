/** 그래프 2617 : 그래프 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int n, m;
int ans = 0;

vector<int> g[150];
vector<int> g_invert[150];

int bfs(int start)
{
    // start 부터 방문하는 노드의 수 리턴
    bool visited[150] = {false};
    int rt = 0;
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto next : g[cur])
        {
            if (visited[next])
                continue;
            q.push(next);
            visited[next] = true;
            rt++;
        }
    }
    return rt;
}

int bfs_invert(int start)
{
    // start 부터 방문하는 노드의 수 리턴
    bool visited[150] = {false};
    int rt = 0;
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto next : g_invert[cur])
        {
            if (visited[next])
                continue;
            q.push(next);
            visited[next] = true;
            rt++;
        }
    }
    return rt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        g_invert[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (bfs(i) >= (n + 1) / 2)
            ans++;
        else if (bfs_invert(i) >= (n + 1) / 2)
            ans++;
    }
    cout << ans;
}
