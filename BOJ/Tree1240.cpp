/** 트리 1240 : 노드사이의 거리 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int n, m;
vector<pair<int, int>> adj[1050];
int p[1050];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    while (m--)
    {
        int start, target, rt = 0;
        cin >> start >> target;

        bool visited[1050] = {
            false,
        };

        queue<pair<int, int>> q;
        q.push({start, 0});
        visited[start] = true;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            if (cur.first == target)
                cout << cur.second << '\n';

            for (auto next : adj[cur.first])
            {
                if (visited[next.first])
                    continue;
                visited[next.first] = true;
                q.push({next.first, next.second + cur.second});
            }
        }
    }
}
