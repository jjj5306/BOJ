#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> emp;
int emp_size;
bool solved = false;

// check : a, b에 k를 채울 수 있는지 체크
bool check(int a, int b, int k)
{
    // 1. a행 / b열 체크
    for (int i = 0; i < 9; i++)
    {
        if (board[a][i] == k || board[i][b] == k)
            return false;
    }
    // 2. 3x3 크기의 정사각형 체크
    // x의 시작 위치 : 0, 3, 6 y도 마찬가지. 즉, a에 3을 나누고 다시 곱하면 정사각형 시작점이 됨.
    int x = a / 3;
    int y = b / 3;
    x *= 3;
    y *= 3;
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            if (board[i][j] == k)
                return false;
        }
    }
    return true;
}

// func : cur 번째 빈칸을 채움
// base condition : cur == emp_size
// 재귀식 : cur 번째 빈칸을 1, 2, 3 숫자들로 채울 수 있다면 하나씩 채우고 func(na, nb, cur+1) 지우고 채우고 호출 지우고를 반복
void func(int cur)
{
    if (solved)
        return;
    if (cur == emp_size)
    {
        solved = true;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
        return;
    }
    // cur 번째 빈 칸 채우기
    for (int k = 1; k <= 9; k++)
    {
        if (!check(emp[cur].first, emp[cur].second, k))
            continue;
        // k로 채우기
        int temp = board[emp[cur].first][emp[cur].second];
        board[emp[cur].first][emp[cur].second] = k;
        func(cur + 1);
        // 다시 복원
        board[emp[cur].first][emp[cur].second] = temp;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                emp.push_back({i, j});
        }
    }
    // cout << "\n\n\n\n\n";

    emp_size = emp.size();
    func(0);
}