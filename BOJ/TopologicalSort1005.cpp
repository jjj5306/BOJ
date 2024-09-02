/** 위상정렬 1005 ACM Craft **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        int job[10100] = {0};
        int indegree[10100] = {0};
        int dp[10100] = {0};
        vector<int> adj[10100];
        // adj[k]={2, 3} -> k->2, k->3
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            cin >> job[i];
        }

        for (int j = 0; j < m; j++)
        {
            int a, b;
            cin >> a >> b;
            // a -> b
            adj[a].push_back(b);
            indegree[b]++;
        }

        int w;
        cin >> w;

        // indegree가 0인걸 똑같이 간선을 제거하면서 방문을 수행하면 됨.
        // 단, dp의 값은 제거하는 노드와 연결된 노드의 값 갱신
        // 점화식 dp[k] = max(dp[i]) + job[k]

        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                dp[i] = job[i];
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int cur = q.front();
            if (cur == w)
                break;
            q.pop();
            for (int nxt : adj[cur])
            {
                dp[nxt] = max(dp[nxt], dp[cur] + job[nxt]);
                // dp[nxt]의 계산이 끝났다면, nxt의 건물을 지은 것

                indegree[nxt]--;
                if (indegree[nxt] == 0)
                    q.push(nxt);
            }
        }

        cout << dp[w] << '\n';
    }
}
