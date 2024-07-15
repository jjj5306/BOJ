/* 위상정렬 2252 줄 세우기 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
vector<int> adj[32001];
int degree[32001];
int n, m;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        degree[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int next : adj[cur])
        {
            degree[next]--;
            if (degree[next] == 0)
                q.push(next);
        }
    }
}
