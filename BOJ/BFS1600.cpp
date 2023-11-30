/** BFS 1600 말이 되고픈 원숭이 **/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int board[202][202];
int visited[202][202][32];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dkx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dky[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int k, n, m; // n행 m열

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<pair<int, int>, int>> Q;
    cin >> k >> m >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    visited[0][0][0] = 1;
    Q.push(make_pair(make_pair(0, 0), 0));

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front().first;
        int knight = Q.front().second;

        Q.pop();

        if (knight < k)
        {
            // 나이트 이동 가능
            for (int i = 0; i < 8; i++)
            {
                int nkx = cur.first + dkx[i];
                int nky = cur.second + dky[i];

                if (nkx < 0 || nky < 0 || nkx >= n || nky >= m)
                    continue;
                if (visited[nkx][nky][knight + 1] || board[nkx][nky])
                    continue;
                visited[nkx][nky][knight + 1] = visited[cur.first][cur.second][knight] + 1;
                Q.push(make_pair(make_pair(nkx, nky), knight + 1));
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            //(nx, ny)는 cur의 상하좌우 칸이다.
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (visited[nx][ny][knight] || board[nx][ny])
                continue;
            visited[nx][ny][knight] = visited[cur.first][cur.second][knight] + 1;
            Q.push(make_pair(make_pair(nx, ny), knight));
        }
    }
    int ans = 2100000000;
    for (int i = 0; i <= k; i++)
        if (visited[n - 1][m - 1][i])
            ans = min(ans, visited[n - 1][m - 1][i]);
    if (ans != 2100000000)
        cout << ans - 1;
    else
        cout << -1;
}
