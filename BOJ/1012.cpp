/** 1012 유기농 배추 BFS **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int T;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[70][70];
bool vis[70][70];
int m, n, k, ans;

void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    vis[a][b] = true;
    q.push({a, b});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (vis[nx][ny] == 1 || board[nx][ny] == false)
                continue;

            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        m = 0;
        n = 0;
        k = 0;
        ans = 0;

        for (int i = 0; i < 70; i++)
            fill(board[i], board[i] + 70, 0);
        for (int i = 0; i < 70; i++)
            fill(vis[i], vis[i] + 70, false);

        cin >> m >> n >> k;

        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            board[b][a] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == false && board[i][j])
                {
                    bfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}
