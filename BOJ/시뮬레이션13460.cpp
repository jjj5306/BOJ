/** 시뮬레이션 13460 구슬 탈출 2 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m, ans_min = 100;
char board[11][11];
pair<int, int> r, b;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int move(int dir)
{
    int n_rx = r.first, n_ry = r.second, n_bx = b.first, n_by = b.second;
    // 파란색부터 이동
    while (board[n_bx + dx[dir]][n_by + dy[dir]] == '.')
    {
        // 다음 칸이 점인 동안만 이동
        n_bx += dx[dir];
        n_by += dy[dir];
    }
    // 파란색 다음 칸이 구멍이라면 탙출 실패, false 리턴
    // 파란색 칸만 보고 구멍에 들어갈 수 있다면 바로 실패로 판정해도 되는 이유는
    // 어차피 dir 방향으로 굴렸을 때 빨, 파가 같은 라인에 있어도 빨간색 때문에 파란색이 못 들어가는 경우가 없기 때문이다.
    if (board[n_bx + dx[dir]][n_by + dy[dir]] == 'O')
        return -1;

    // 빨간색 이동
    while (board[n_rx + dx[dir]][n_ry + dy[dir]] == '.')
    {
        // 다음 칸이 점인 동안만 이동
        n_rx += dx[dir];
        n_ry += dy[dir];
    }
    // 빨간색 다음 칸이 구멍이라면 탈출 성공
    if (board[n_rx + dx[dir]][n_ry + dy[dir]] == 'O')
        return 1;

    // 두 공이 겹쳐져있다면 늦게 온 칸 dir 반대 방향으로 이동
    if ((n_rx == n_bx) && (n_ry == n_by))
    {
        if (dir == 0)
            // 원래 b의 x좌표가 더 크다면 b가 늦게 온 것
            // 현재 dir 방향이 행 감소, 즉 위쪽이므로 늦게 온 것 아래로 이동
            r.first < b.first ? n_bx++ : n_rx++;
        else if (dir == 1) // 현재 dir 방향 아래
            r.first > b.first ? n_bx-- : n_rx--;
        else if (dir == 2) // 현재 dir 방향 왼쪽
            r.second < b.second ? n_by++ : n_ry++;
        else // 왼쪽
            r.second > b.second ? n_by-- : n_ry--;
    }
    r = {n_rx, n_ry};
    b = {n_bx, n_by};
    return 0;
}

void func(int cnt)
{
    // 현재 cnt번의 이동까지 구현 완료, cnt 10이면 10번 이동 완료인데 통과가 안됐으므로 종료
    if (cnt >= 10)
        return;

    for (int dir = 0; dir < 4; dir++)
    {
        auto tmp_r = r, tmp_b = b;
        int flag = move(dir);
        if (flag == -1)
            continue;
        else if (flag == 1)
        {
            ans_min = min(ans_min, cnt + 1);
            continue;
        }
        else
            func(cnt + 1);
        r = tmp_r;
        b = tmp_b;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                board[i][j] = '.';
                r = {i, j};
            }

            if (board[i][j] == 'B')
            {
                board[i][j] = '.';
                b = {i, j};
            }
        }
    }

    func(0);
    if (ans_min == 100)
        cout << "-1\n";
    else
        cout << ans_min << '\n';
}
