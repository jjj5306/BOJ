/** 재귀 2630 색종이 자르기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int paper[129][129], N;
int ans[2] = {
    0,
};

bool check(int n, int a, int b)
{
    // n * n 종이의 숫자가 모두 같은지 정사각형 형태로 체크한다.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (paper[a][b] != paper[a + j][b + i])
                return false;
    return true;
}

void func(int n, int a, int b)
{
    // n * n 종이의 개수를 세는 함수이다.
    if (check(n, a, b))
    {
        ans[paper[a][b]]++;
        return;
    }
    n = n / 2;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            func(n, a + i * n, b + j * n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];
    func(N, 0, 0);
    for (auto x : ans)
        cout << x << '\n';
}
