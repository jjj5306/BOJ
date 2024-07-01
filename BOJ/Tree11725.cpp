/** 트리 11725 트리의 부모 찾기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
vector<int> adj[100200];
int p[100200];

void dfs(int cur)
{
    for (int next : adj[cur])
    {
        if (p[cur] == next)
            continue;
        p[next] = cur;
        dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    for (int i = 2; i <= n; i++)
        cout << p[i] << '\n';
}
