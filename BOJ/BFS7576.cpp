/** BFS 7576 토마토 **/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 1001
using namespace std;

int board[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m; // n행 m열

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        fill(board[i], board[i] + m, 0);
        fill(dist[i], dist[i] + m, 0);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                // 익은 토마토가 들어오는 경우
                Q.push(make_pair(i, j));
            }
            if (board[i][j] == 0)
            {
                // 토마토가 없는 칸은 0으로 그냥 둬서 이미 방문한것과 같게 처리한다.
                dist[i][j] = -1;
            }
        }

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            //(nx, ny)는 cur의 상하좌우 칸이다.
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (dist[nx][ny] >= 0)
                continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push(make_pair(nx, ny));
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == -1)
            {
                cout << -1;
                return 0;
            }
            res = max(res, dist[i][j]);
        }
    cout << res;
}
