/** 시뮬레이션 14499 주사위 굴리기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m, x, y;
int top, bottom, l, r, up, down; // 주사위 육면도 저장
int board[25][25];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int simulate(int dir)
{
    // dir방향으로 주사위를 굴린다.
    // 다음에 굴릴 곳이 board를 넘어가면 -1 리턴
    int nx = x + dx[dir - 1];
    int ny = y + dy[dir - 1];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        return -1;

    int tmp_top, tmp_bottom, tmp_l, tmp_r, tmp_up, tmp_down;
    switch (dir)
    {
    case 1:
        // 오른쪽으로 굴리기
        tmp_top = l;
        tmp_r = top;
        tmp_l = bottom;
        tmp_bottom = r;

        top = tmp_top;
        bottom = tmp_bottom;
        r = tmp_r;
        l = tmp_l;
        break;
    case 2:
        // 왼쪽으로 굴리기
        tmp_top = r;
        tmp_r = bottom;
        tmp_l = top;
        tmp_bottom = l;

        top = tmp_top;
        bottom = tmp_bottom;
        r = tmp_r;
        l = tmp_l;
        break;
    case 3:
        // 위로 굴리기
        tmp_top = down;
        tmp_bottom = up;
        tmp_up = top;
        tmp_down = bottom;

        top = tmp_top;
        bottom = tmp_bottom;
        up = tmp_up;
        down = tmp_down;
        break;
    case 4:
        // 아래로 굴리기
        tmp_top = up;
        tmp_bottom = down;
        tmp_up = bottom;
        tmp_down = top;

        top = tmp_top;
        bottom = tmp_bottom;
        up = tmp_up;
        down = tmp_down;
        break;
    }

    // 아랫면 확인
    x = nx;
    y = ny;
    if (board[x][y] == 0)
    {
        board[x][y] = bottom;
        return top;
    }
    else
    {
        bottom = board[x][y];
        board[x][y] = 0;
        return top;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    top = 0;
    r = 0;
    l = 0;
    up = 0;
    down = 0;
    bottom = 0;

    while (k--)
    {
        int dir;
        cin >> dir;
        int ans = simulate(dir);
        if (ans == -1)
            continue;
        else
            cout << ans << '\n';
    }
}
