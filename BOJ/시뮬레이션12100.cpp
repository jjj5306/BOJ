/** 시뮬레이션 12100 2048(Easy) **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
int board[22][22];
int max_ = 0;

void moving_upward()
{
    // 각 열을 위로 이동시키면서 풀어보자.
    int res_board[22][22];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res_board[i][j] = 0;

    for (int col = 0; col < n; col++)
    {
        int cur = 0;
        // col열을 위로 이동시키면 된다.
        for (int i = 0; i < n; i++)
        {
            if (board[i][col] == 0)
                continue;
            if (res_board[cur][col] == 0)
            {
                res_board[cur][col] = board[i][col];
            }
            else if (res_board[cur][col] == board[i][col])
            {
                res_board[cur++][col] *= 2;
            }
            else
            {
                res_board[++cur][col] = board[i][col];
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = res_board[i][j];
}

void moving_downward()
{
    // 각 열을 아래로 이동시키면서 풀어보자.
    int res_board[22][22];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res_board[i][j] = 0;

    for (int col = 0; col < n; col++)
    {
        int cur = n - 1;
        // col열을 아래로 이동시키면 된다.
        for (int i = n - 1; i >= 0; i--)
        {
            if (board[i][col] == 0)
                continue;
            if (res_board[cur][col] == 0)
            {
                res_board[cur][col] = board[i][col];
            }
            else if (res_board[cur][col] == board[i][col])
            {
                res_board[cur--][col] *= 2;
            }
            else
            {
                res_board[--cur][col] = board[i][col];
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = res_board[i][j];
}

void moving_leftward()
{
    // 각 행을 왼쪽으로 이동시키면서 풀어보자.
    int res_board[22][22];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res_board[i][j] = 0;

    for (int row = 0; row < n; row++)
    {
        int cur = 0;
        // row행을 왼쪽으로 이동시키면 된다.
        for (int i = 0; i < n; i++)
        {
            if (board[row][i] == 0)
                continue;
            if (res_board[row][cur] == 0)
            {
                res_board[row][cur] = board[row][i];
            }
            else if (res_board[row][cur] == board[row][i])
            {
                res_board[row][cur++] *= 2;
            }
            else
            {
                res_board[row][++cur] = board[row][i];
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = res_board[i][j];
}

void moving_rightward()
{
    // 각 행을 오른쪽으로 이동시키면서 풀어보자.
    int res_board[22][22];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res_board[i][j] = 0;

    for (int row = 0; row < n; row++)
    {
        int cur = n - 1;
        // row행을 오른쪽으로 이동시키면 된다.
        for (int i = n - 1; i >= 0; i--)
        {
            if (board[row][i] == 0)
                continue;
            if (res_board[row][cur] == 0)
            {
                res_board[row][cur] = board[row][i];
            }
            else if (res_board[row][cur] == board[row][i])
            {
                res_board[row][cur--] *= 2;
            }
            else
            {
                res_board[row][--cur] = board[row][i];
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = res_board[i][j];
}

void func(int k)
{
    if (k == 5)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                max_ = max(max_, board[i][j]);
        return;
    }
    // 현재 k번만큼 블럭을 이동시킴.

    // 특정 방향으로 이동시키고 func(k+1)호출, 호출이 끝나면 다시 원상복구 시키기
    int tmp_board[22][22];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp_board[i][j] = board[i][j];

    // 위쪽 방향으로 이동
    moving_upward();
    func(k + 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = tmp_board[i][j];

    // 아래 방향으로 이동
    moving_downward();
    func(k + 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = tmp_board[i][j];

    // 왼쪽 방향으로 이동
    moving_leftward();
    func(k + 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = tmp_board[i][j];
    // 오른쪽 방향으로 이동
    moving_rightward();
    func(k + 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = tmp_board[i][j];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    func(0);
    cout << max_ << '\n';
}
