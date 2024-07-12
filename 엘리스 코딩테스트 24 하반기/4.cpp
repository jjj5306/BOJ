#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> adj[100100];
int dp[100100];

// dp[cur] : cur에서 시작했을 때 선공, 후공의 점수 차이

void dfs(int cur, int par)
{
    bool is_leaf = true;

    for (auto next : adj[cur])
    {
        if (next == par)
            continue;
        is_leaf = false;
    }
    if (is_leaf)
    {
        dp[cur] = cur;
        return;
    }

    bool is_first = false;
    for (int next : adj[cur])
    {
        if (next == par)
            continue;
        dfs(next, cur);
        if (!is_first)
        {
            is_first = true;
            dp[cur] = cur + dp[next] * -1;
        }
        else
        {

            dp[cur] = max(dp[cur], cur + dp[next] * -1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++)
        cout << (dp[i] >= 0) << '\n';

    return 0;
}
