/** 시뮬레이션 17484 진우의 달 여행 (Small)  **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m, ans = 3000;
int board[10][10];
int dx[3] = {1, 1, 1};
int dy[3] = {-1, 0, 1};

// func : 이전 칸에서 dir 방향으로 진행했고, 현재 (x, y) (x, y) 포함해서 든 비용이 cost
void func(int dir, int x, int y, int cost)
{
    // base condition
    if (x == n)
    {
        ans = min(ans, cost);
        return;
    }

    for (int d = 0; d < 3; d++)
    {
        if (dir == d)
            continue;
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (ny < 0 || ny >= m)
            continue;
        func(d, nx, ny, cost + board[nx][ny]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int j = 0; j < m; j++)
        board[0][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < m; i++)
    {
        for (int d = 0; d < 3; d++)
        {
            int nx = dx[d];
            int ny = i + dy[d];
            if (ny < 0 || ny >= m)
                continue;
            func(d, nx, ny, board[nx][ny]);
        }
    }

    cout << ans << '\n';
}
