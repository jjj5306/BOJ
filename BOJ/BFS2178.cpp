/** BFS 2178 미로탐색 **/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 102
using namespace std;

string board[MAX];
int dist[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m; // n행 m열

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        fill(dist[i], dist[i] + m, -1);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    dist[0][0] = 1;
    Q.push(make_pair(0, 0));

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
            if (dist[nx][ny] != -1 || board[nx][ny] != '1')
                continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push(make_pair(nx, ny));
        }
    }
    cout << dist[n - 1][m - 1];
}
