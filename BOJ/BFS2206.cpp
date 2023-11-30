/** BFS 2206 벽 부수고 이동하기 **/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 1002
using namespace std;

string board[MAX];
int dist[MAX][MAX][2]; // dist[x][y][0]은 벽을 부수지 않았을 때 (x, y)까지의 dist이다.

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /* 초기화 부분 */
    cin >> n >> m;
    queue<pair<pair<int, int>, int>> Q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dist[i][j][0] = dist[i][j][1] = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    dist[0][0][0] = dist[0][0][1] = 1;
    Q.push(make_pair(make_pair(0, 0), 0));
    /******************************************************************************************************/

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front().first;
        int flag = Q.front().second;
        if (cur.first == n - 1 && cur.second == m - 1)
        {
            cout << dist[n - 1][m - 1][flag];
            return 0;
        }
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            //(nx, ny)는 cur의 상하좌우 칸이다.
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (dist[nx][ny][flag] >= 0)
                continue;
            if (board[nx][ny] == '1')
            {
                if (flag)
                    continue;
                else
                {
                    // 벽을 부순 경우
                    dist[nx][ny][1] = dist[cur.first][cur.second][flag] + 1;
                    Q.push(make_pair(make_pair(nx, ny), 1));
                }
            }
            else
            {
                // 벽이 아닌 경우
                dist[nx][ny][flag] = dist[cur.first][cur.second][flag] + 1;
                Q.push(make_pair(make_pair(nx, ny), flag));
            }
        }
    }
    cout << -1;
}
