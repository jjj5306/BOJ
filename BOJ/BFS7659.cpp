/** BFS 7569 토마토 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int N, M, H;
int board[105][105][105];
int ans = 0, tomatoTotal = 0, tomatoRipe = 0;
bool vis[105][105][105];

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
int dz[6] = {1, -1, 0, 0, 0, 0};

queue<tuple<int, int, int>> q;

int bfs()
{
    int rt = -1;
    while (!q.empty())
    {
        int size = q.size();

        rt++;
        // 하루에 bfs가 한 번 진행되어야 함.
        for (int step = 0; step < size; step++)
        {

            int curX, curY, curZ;
            tie(curX, curY, curZ) = q.front();
            q.pop();

            for (int dir = 0; dir < 6; dir++)
            {
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                int nz = curZ + dz[dir];

                // 범위 체크
                if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
                    continue;
                // 방문한 토마토나 벽인 경우
                if (vis[nx][ny][nz] || board[nx][ny][nz] == -1)
                    continue;
                vis[nx][ny][nz] = true;
                q.push({nx, ny, nz});
                // 새로 익은 토마토 수 세기
                tomatoRipe++;
            }
        }
    }
    return rt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> H;

    for (int h = 0; h < H; h++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> board[i][j][h];
                if (board[i][j][h] == 1)
                {
                    // 익은 토마토는 미리 큐에 다 넣어놓음.
                    q.push({i, j, h});
                    vis[i][j][h] = true;
                    // 익은 토마토 수 세기
                    tomatoRipe++;
                }
                if (board[i][j][h] != -1)
                {
                    // 전체 토마토 수 세기
                    tomatoTotal++;
                }
            }
        }
    }
    // 모든 토마토가 익어있었던 경우
    if (tomatoRipe == tomatoTotal)
    {
        cout << "0\n";
        return 0;
    }
    ans = bfs();

    if (tomatoTotal != tomatoRipe)
        cout << "-1\n";
    else
        cout << ans << '\n';
}
