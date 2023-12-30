/** DP 1520 내리막 길 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int board[700][700], dp[700][700];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int func(int x, int y)
{
    // base condition 1 : 현재 방문한 곳이 이미 dp값을 구한 곳이면 그 값 쓰면 됨.
    // 방문 배열을 따로 쓰지 않고 방문하지 않은 곳은 -1로 갈 수 없는 곳은 0으로 기록
    if (dp[x][y] != -1)
        return dp[x][y];
    // base condition 2 : 목적지 도달
    if (x == n - 1 && y == m - 1)
        return 1;

    // (x, y)에서 아무곳도 갈 수 없으면 그것도 알려줘야 함.
    dp[x][y] = 0;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (board[x][y] > board[nx][ny])
            dp[x][y] += func(nx, ny);
    }
    // for문 다 돌았으면 x, y에서 가능한 방문이 다 끝났다는 뜻이다.
    // 그럼 x, y를 호출한 함수에서 현재 x, y가 nx, ny가 된다.
    // 거기서의 nx, ny에서 목적지까지 경우의 수를 리턴해주면 된다.
    return dp[x][y];
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
            dp[i][j] = -1;
        }

    cout << func(0, 0);
}
