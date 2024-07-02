/** 트리 4803 트리 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int n, m, tc = 0, ans = 0;
bool visited[520];
bool flag = true;
vector<int> g[510];

void dfs(int cur, int prev)
{
    for (int next : g[cur])
    {
        if (next == prev)
            continue;
        // dfs 도중 next가 부모가 아닌데 방문한 적 있다면 사이클이 있는 것이다.
        if (visited[next])
        {
            flag = false;
            // 해당 연결 요소가 트리가 아님을 알아도 dfs는 마저 끝내서 방문 표시를 마쳐야함
            continue;
        }
        visited[next] = true;
        dfs(next, cur);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        fill(visited, visited + n + 1, false);
        for (int i = 1; i <= n; i++)
            g[i].clear();
        ans = 0;

        int u, v;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // 방문하지 않은 정점에 대해 dfs를 돌려서 연결 요소로 분리
        for (int node = 1; node <= n; node++)
        {
            if (visited[node])
                continue;
            flag = true;
            visited[node] = true;
            dfs(node, 0);
            ans += flag;
        }

        cout << "Case " << ++tc << ": ";
        if (!ans)
            cout << "No trees." << '\n';
        else if (ans == 1)
            cout << "There is one tree." << '\n';
        else
            cout << "A forest of " << ans << " trees." << '\n';
    }
}
