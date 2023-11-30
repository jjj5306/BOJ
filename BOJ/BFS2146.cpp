/** BFS 2146 다리 만들기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

const int MAX = 102;
int arr[MAX][MAX];
int island[MAX][MAX];
int dist[MAX][MAX];
int island_number = 1;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
int res = 999999;

void numbering_island(int x, int y)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(x, y));
    island[x][y] = island_number;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (!(nx >= 0 && ny >= 0 && nx < n && ny < n))
                continue;
            if (island[nx][ny] != 0)
                continue;
            if (arr[nx][ny] == 0)
                continue;
            island[nx][ny] = island_number;
            Q.push(make_pair(nx, ny));
        }
    }
}

void bfs()
{
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (island[i][j] != 0)
            {
                Q.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    }
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (!(nx >= 0 && ny >= 0 && nx < n && ny < n))
                continue;
            if (island[nx][ny] == island[cur.first][cur.second])
                continue;
            if (island[nx][ny] != 0)
            {
                // 섬 만나면 다리 길이 구하기
                res = min(res, dist[cur.first][cur.second] + dist[nx][ny]);
            }
            else
            {
                // 바다 만나는 경우 해당 바다를 섬과 같은 영역으로 만들어 줘야 한다.
                // 1 0 1 과 같은 예시에서 꼬일 수 있다.
                island[nx][ny] = island[cur.first][cur.second];
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                Q.push(make_pair(nx, ny));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            island[i][j] = 0;
            dist[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0 && island[i][j] == 0)
            {
                numbering_island(i, j);
                island_number++;
            }
        }
    }

    bfs();

    cout << res;
}
