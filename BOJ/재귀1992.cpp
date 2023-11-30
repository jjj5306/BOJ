/** 재귀 1992 쿼드트리 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int video[64][64], N;

bool check(int n, int a, int b)
{
    // n * n 비디오의 숫자가 모두 같은지 정사각형 형태로 체크한다.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (video[a][b] != video[a + j][b + i])
                return false;
    return true;
}

void func(int n, int a, int b)
{
    if (check(n, a, b))
    {
        cout << video[a][b];
        return;
    }
    cout << "(";
    func(n / 2, a, b);
    func(n / 2, a, b + n / 2);
    func(n / 2, a + n / 2, b);
    func(n / 2, a + n / 2, b + n / 2);

    cout << ")";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++)
            video[i][j] = str[j] - '0';
    }
    func(N, 0, 0);
}
