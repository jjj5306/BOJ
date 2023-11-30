/** BackTracking 1941 소문난 칠공주 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
string stu[5];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool princess[25];
int res = 0;

void bfs()
{
    queue<pair<int, int>> Q;
    bool visited[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            visited[i][j] = false;

    int doyeon_num = 0, cnt = 0;
    for (int i = 0; i < 25; i++)
    {
        if (!princess[i])
        {
            // 처음으로 방문한 공주를 시작으로 bfs 시작
            int x = i / 5;
            int y = i % 5;
            visited[x][y] = true;
            Q.push({x, y});
            while (!Q.empty())
            {
                auto cur = Q.front();
                Q.pop();
                cnt++;
                if (stu[cur.first][cur.second] == 'Y')
                    doyeon_num++;
                if (doyeon_num >= 4)
                    break;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || ny < 0 || nx > 4 || ny > 4)
                        continue;
                    if (visited[nx][ny])
                        continue;
                    if (princess[nx * 5 + ny])
                        continue;
                    visited[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
            if (cnt != 7 || doyeon_num >= 4)
                // cnt는 한 번의 bfs로 센 공주의 수이다. 7이 아니라면 공주들이 인접한게 아니다.
                return;
            res++;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        cin >> stu[i];

    // 초기설정 [0,0] ~ [1,0]을 공주로 선택하고 시작한다.
    // next_permutation 함수는 정렬된 배열에 한해서만 작동하기에 false가 앞에 나와야 한다. 따라서 선택한 공주는 false로 표시한다.
    fill(princess + 7, princess + 25, true);

    do
    {
        bfs();

    } while (next_permutation(princess, princess + 25));
    cout << res;
}
