/** 재귀 2448 별 찍기 - 11 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 3 * 1024;
char star[MAX][MAX * 2 - 1];

void func(int n, int x, int y)
{
    //(x,y)에 n크기의 패턴을 찍는다.
    if (n == 3)
    {
        star[x][y] = '*';
        star[x + 1][y - 1] = '*';
        star[x + 1][y + 1] = '*';

        for (int i = y - 2; i <= y + 2; i++)
            star[x + 2][i] = '*';
        return;
    }
    n = n / 2;
    func(n, x, y);
    func(n, x + n, y - n);
    func(n, x + n, y + n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        fill(star[i], star[i] + 2 * n - 1, ' ');
    func(n, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            cout << star[i][j];
        }
        cout << '\n';
    }
}
