/** BFS 2573 빙산 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
const int MAX = 302;
int arr[MAX][MAX];
int visited[MAX][MAX];
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void one_year_later()
{
    int zero[MAX][MAX] = {
        0,
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                continue;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0)
                    zero[i][j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = max(0, arr[i][j] - zero[i][j]);
        }
    }
    return;
}

int bfs()
{
    int x, y, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j])
            {
                x = i;
                y = j;
                cnt++;
            }
        }
    }
    if (cnt == 0)
        return 0;

    int cnt2 = 0;
    queue<pair<int, int>> Q;

    visited[x][y] = 1;
    Q.push(make_pair(x, y));
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        cnt2++;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (!(nx >= 0 && nx < n && ny >= 0 && ny < m))
                continue;
            if (visited[nx][ny] == 1)
                continue;
            if (arr[nx][ny] == 0)
                continue;

            visited[nx][ny] = 1;
            Q.push(make_pair(nx, ny));
        }
    }
    if (cnt == cnt2) // 빙산이 아직 한 덩어리인 경우
        return 1;
    else
        return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int res = 0;
    while (1)
    {
        res++;
        one_year_later();
        for (int i = 0; i < n; i++)
            fill(visited[i], visited[i] + m, 0);
        int flag = bfs();
        if (flag == 0)
        {
            cout << 0;
            return 0;
        }
        else if (flag == 1)
            continue;
        else
        {
            cout << res;
            return 0;
        }
    }
}
