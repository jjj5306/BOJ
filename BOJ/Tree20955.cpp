/** Tree 20955 민서의 응급 수술 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> adj[100100];
bool vis[100100];
int n, m;

void dfs(int cur)
{
    if (vis[cur])
        return;
    vis[cur] = true;
    for (auto next : adj[cur])
        dfs(next);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int graph_count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        dfs(i);
        graph_count++;
    }
    // graph_count개의 그래프가 있음. 각 그래프를 연결하는 연산 graph_count-1번 수행
    int ans = graph_count - 1;

    // 각 그래프를 트리로 만들기 위해 간선 제거 연산 수행
    // 어떤 간선을 제거할지는 몰라도 되고 몇 번 수행하는지만 알면 됨
    // 현재 간선이 graph_count-1 + m개 있는데, 트리가 되려면 총 n-1개의 간선만 존재해야 함.
    // 따라서 graph_count-1 + m - n-1 번의 제거 연산 수행

    ans += m + graph_count - 1;
    ans -= n - 1;
    cout << ans;
}
