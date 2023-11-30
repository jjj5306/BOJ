/** BFS 4179 불! **/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 1002
using namespace std;

string board[MAX];
int dist[MAX][MAX];
int dist2[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m; // n행 m열

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    queue<pair<int, int>> Q2;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        fill(dist[i], dist[i] + m, -1);
        fill(dist2[i], dist2[i] + m, -1);
    }

    for (int i = 0; i < n; i++)
        cin >> board[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (board[i][j] == 'F')
            {
                Q.push(make_pair(i, j));
                dist[i][j] = 0;
            }
            if (board[i][j] == 'J')
            {
                Q2.push(make_pair(i, j));
                dist2[i][j] = 0;
            }
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
            if (dist[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push(make_pair(nx, ny));
        }
    }

    while (!Q2.empty())
    {
        pair<int, int> cur = Q2.front();
        Q2.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            //(nx, ny)는 cur의 상하좌우 칸이다.
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            {
                cout << dist2[cur.first][cur.second] + 1;
                return 0;
            }
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            if (dist[nx][ny] != -1 && dist[nx][ny] <= dist2[cur.first][cur.second] + 1)
                continue;
            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
            Q2.push(make_pair(nx, ny));
        }
    }

    cout << "IMPOSSIBLE";
}
