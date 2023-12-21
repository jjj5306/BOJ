/** 시뮬레이션 14502 연구소 **/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int n, m, ans = 0;
int board[10][10];
int tmp_board[10][10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> virus;

int bfs()
{
    int rt = 0;
    // tmp_baord에 바이러스를 확산시킨 후 안전 지역 계산
    queue<pair<int, int>> q;
    for (auto x : virus)
        q.push(x);

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (tmp_board[nx][ny] != 0)
                continue;
            tmp_board[nx][ny] = 2;
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (tmp_board[i][j] == 0)
                rt++;
    return rt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                virus.push_back({i, j});
        }

    vector<bool> combination(n * m);
    fill(combination.begin(), combination.begin() + 3, false);
    fill(combination.begin() + 3, combination.end(), true);
    do
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tmp_board[i][j] = board[i][j];
        // 해당 순열에 관한 작업은 모두 tmp_board에서 이루어진다.

        bool flag = false;
        for (int k = 0; k < combination.size(); k++)
        {
            if (!combination[k])
            {
                if (board[k / m][k % m] != 0)
                {
                    // 해당 순열이 빈 공간이 아닌 곳에 벽을 세우려 한다면 해당 순열 패스
                    flag = true;
                    break;
                }
                else
                    tmp_board[k / m][k % m] = 1;
            }
        }
        if (flag)
            continue;

        // 해당 조합의 안전 지역 계산
        ans = max(ans, bfs());
    } while (next_permutation(combination.begin(), combination.end()));
    cout << ans << '\n';
}
