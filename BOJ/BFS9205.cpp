/* 9205번 BFS 맥주 마시면서 걸어가기 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        int n;
        vector<pair<int, int>> list;

        cin >> n;
        int a, b;
        for (int i = 0; i < n + 2; i++)
        {
            cin >> a >> b;
            list.push_back({a, b});
        }

        // 그래프로 만들기
        // 모든 노드들을 대상으로 거리가 1000보다 같거나 작으면 간선 추가
        vector<int> adj[105];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = i + 1; j < n + 2; j++)
            {
                // i, j가 연결될 수 있는지
                if (abs(list[j].first - list[i].first) + abs(list[j].second - list[i].second) <= 1000)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // 그래프 BFS로 target 까지 도달할 수 있는지
        bool vis[105] = {
            false,
        };
        queue<int> q;
        q.push(0);
        vis[0] = true;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for (auto next : adj[cur])
            {
                if (vis[next])
                    continue;
                vis[next] = true;
                q.push(next);
            }
        }

        if (vis[n + 1])
            cout << "happy\n";
        else
            cout << "sad\n";
    }
}