/** DP 17485 진우의 달 여행 (Large) **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m, ans = 9999999;
int board[1030][1030];
int dp[1030][1030][3];
int dx[3] = {-1, -1, -1};
int dy[3] = {1, 0, -1};

bool check(int x, int y, int dir)
{
    //(i,j)에 dir로 도달할 수 있었는지 체크
    int bx = x + dx[dir];
    int by = y + dy[dir];
    if (by >= 0 && by < m)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    // 초기값 세팅
    // dp[i][j][dir] = (i, j)에 dir로 도달하였을 때 최소 비용 (i, j) 포함
    for (int j = 0; j < m; j++)
        for (int dir = 0; dir < 3; dir++)
            if (check(0, j, dir))
                dp[0][j][dir] = board[0][j];
            else
                dp[0][j][dir] = 99999;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int dir = 0; dir < 3; dir++)
                if (check(i, j, dir))
                    dp[i][j][dir] = min(dp[i + dx[dir]][j + dy[dir]][(dir + 1) % 3],
                                        dp[i + dx[dir]][j + dy[dir]][(dir + 2) % 3]) +
                                    board[i][j];
                else
                    dp[i][j][dir] = 99999;

    for (int j = 0; j < m; j++)
        for (int dir = 0; dir < 3; dir++)
            ans = min(dp[n - 1][j][dir], ans);

    cout << ans << '\n';
}
