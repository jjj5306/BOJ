/** BFS 1926 그림**/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 502
using namespace std;

int board[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m; // n행 m열
int cnt = 0;

int BFS(int x, int y)
{
    queue<pair<int, int>> Q;
    int res = 0;
    cnt++;

    visited[x][y] = 1;
    Q.push(make_pair(x, y));

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        res++;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            //(nx, ny)는 cur의 상하좌우 칸이다.
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (visited[nx][ny] == 1 || board[nx][ny] == 0)
                continue;
            visited[nx][ny] = 1;
            Q.push(make_pair(nx, ny));
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        fill(board[i], board[i] + m, 0);
        fill(visited[i], visited[i] + m, 0);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int max = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != 0 && visited[i][j] != 1)
            {
                int temp = BFS(i, j);
                max = (max < temp) ? temp : max;
            }
        }

    cout << cnt << "\n" << max;
}
