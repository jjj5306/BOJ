/** 시뮬레이션 14503 로봇 청소기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m, r, c, dir, ans = 0;
int board[55][55];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r >> c >> dir;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    while (1)
    {
        if (board[r][c] == 0)
        {
            // 현재 칸 청소 가능하다면 청소
            board[r][c] = -1;
            ans++;
        }
        bool flag = false;
        for (int i = 0; i < 4; i++)
        {
            dir = (dir + 3) % 4;
            if (board[r + dx[dir]][c + dy[dir]] == 0)
            {
                r += dx[dir];
                c += dy[dir];
                flag = true;
                break;
            }
        }
        if (flag)
            continue;

        // 후진할 수 있으면 후진
        if (board[r - dx[dir]][c - dy[dir]] == 1)
        {
            cout << ans << '\n';
            break;
        }
        r -= dx[dir];
        c -= dy[dir];
    }
}
