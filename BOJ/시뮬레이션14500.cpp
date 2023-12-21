/** 시뮬레이션 14500 테트로미노 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m, ans = 0, tmp_sum = 0;
int board[510][510];
bool visited[510][510];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void func(int x, int y, int cnt)
{
    // 현재 (x, y) 방문, cnt 길이까지의 길 다 찾은 상태
    if (cnt == 4)
    {
        ans = max(ans, tmp_sum);
        return;
    }
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (visited[nx][ny])
            continue;
        //(nx, ny) 방문 처리
        tmp_sum += board[nx][ny];
        visited[nx][ny] = true;
        func(nx, ny, cnt + 1);
        // 주의!! ㅏ ㅓ ㅗ ㅜ 모양 처리를 위해 길이 3의 길까지 찾은 후
        // nx, ny의 방문 한 채로 x, y에서 다시 다음 길을 찾으면서 해결
        if (cnt == 2)
            func(x, y, cnt + 1);
        tmp_sum -= board[nx][ny];
        visited[nx][ny] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            tmp_sum = board[i][j];
            visited[i][j] = true;
            func(i, j, 1);
            visited[i][j] = false;
        }

    cout << ans << '\n';
}
