/** 위상정렬 2637 장난감 조립 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n, m;
int indegree[103];
int dp[103][103];
int basic[103];
vector<pair<int, int>> adj[103];
queue<int> q;
// adj[i]={a, b} : i를 만드는데 a가 b개 필요함.

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[b].push_back({a, c});
        indegree[a]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            basic[i] = 1;
            q.push(i);
            dp[i][i] = 1;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto next : adj[cur])
        {
            indegree[next.first]--;
            if (indegree[next.first] == 0)
                q.push(next.first);

            for (int j = 1; j <= n; j++)
            {
                dp[next.first][j] += dp[cur][j] * next.second;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (basic[i])
            cout << i << ' ' << dp[n][i] << '\n';
    }
}
