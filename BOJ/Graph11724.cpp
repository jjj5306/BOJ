#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int arr[1050][1050] = {0}; // 초기화
bool visited[1050] = {false};
int ans = 0;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        { // 1부터 n까지 확인
            if (arr[cur][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
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
        arr[u][v] = arr[v][u] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
            ans++;
        }
    }

    cout << ans << '\n';
}
