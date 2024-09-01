/** 위상정렬 2056 작업 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n;
int job[10100];
int indegree[10100];
int dp[10100];
vector<int> adj[10100];
// adj[k]={2, 3} -> k->2, k->3

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> job[i] >> m;
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            // temp -> i
            adj[temp].push_back(i);
            indegree[i]++;
        }
    }

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
        q.pop();
        for (int nxt : adj[cur])
        {
            dp[nxt] = max(dp[nxt], dp[cur] + job[nxt]);
            indegree[nxt]--;
            if (indegree[nxt] == 0)
                q.push(nxt);
        }
    }

    int ans = 0;
    for (auto x : dp)
        ans = max(ans, x);
    cout << ans;
}
