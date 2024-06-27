/** 그래프 5567 결혼식 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int n, m;
bool visited[520];
int ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<int> g[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    visited[1] = true;
    for (auto x : g[1])
    {
        visited[x] = true;
        q.push(x);
        ans++;
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto x : g[cur])
        {
            if (!visited[x])
            {
                visited[x] = true;
                ans++;
            }
        }
    }
    cout << ans;
}
