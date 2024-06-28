/** 그래프 1707 이분 그래프 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int K, v, e;
int group[20100];
vector<int> g[20100];

string solve()
{
    fill(group, group + v + 1, -1);

    // 첫 번째 점을 시작으로 인접한 점의 집합을 1로, 본인은 0으로 만든다.
    // 첫 번째 점과 인접한 점을 큐에 넣는다.
    // 큐에서 뺀 점에 대해 인접한 점의 집합을 0으로 만드는데, 1이 있으면 이분 그래프가 아닌 것이다.

    for (int i = 1; i <= v; i++)
    {
        if (group[i] != -1)
            continue;

        queue<int> q;
        q.push(i);
        group[i] = 0;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto next : g[cur])
            {
                if (group[next] != -1)
                {
                    if (group[next] == group[cur])
                        return "NO\n";
                    else
                        continue;
                }

                group[next] = 1 - group[cur];
                q.push(next);
            }
        }
    }
    return "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;
    while (K--)
    {
        cin >> v >> e;
        for (int i = 1; i <= v; i++)
            g[i].clear();

        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        cout << solve();
    }
}
