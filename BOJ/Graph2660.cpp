/** 그래프 2660 회장뽑기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

vector<int> g[100];
int ans[100];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (1)
    {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1)
            break;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        // i번 회원의 점수 계산 with bfs
        queue<int> q;
        q.push(i);

        int visited[100];
        fill(visited, visited + 100, -1);
        // visited[k] = i번 회원이 k번 회원까지 몇 번 간선을 거쳐야 도달하는지
        visited[i] = 0;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto x : g[cur])
            {
                if (visited[x] != -1)
                    continue;
                visited[x] = visited[cur] + 1;
                q.push(x);
            }
        }

        int score = 0;
        for (int k = 1; k <= n; k++)
            score = max(score, visited[k]);

        ans[i] = score;
        if (ans[i] == 0)
            ans[i] = 20000;
    }

    int output_sc = 200000, output_num = 0;

    for (int i = 1; i <= n; i++)
    {
        if (output_sc == ans[i])
        {
            output_num++;
        }
        else if (output_sc > ans[i])
        {
            output_num = 1;
            output_sc = ans[i];
        }
    }

    cout << output_sc << ' ' << output_num << '\n';
    for (int i = 1; i <= n; i++)
        if (ans[i] == output_sc)
            cout << i << ' ';
    cout << '\n';
}
