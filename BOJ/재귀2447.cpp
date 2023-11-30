/** 재귀 2447 별 찍기 - 10 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char star[2300][2300];

void func(int n, int a, int b)
{
    // (a, b)에 n 크기의 패턴을 찍는 함수이다.
    if (n == 3)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (i != 1 || j != 1)
                    star[a + i][b + j] = '*';
        return;
    }
    // 정사각형을 9등분 했을떄 왼쪽 위부터 오른쪽 아래 순서로 1 ~ 9 번 섹션
    func(n / 3, a, b);             // 1번 섹션
    func(n / 3, a + n / 3, b);     // 2번 섹션
    func(n / 3, a + n / 3 * 2, b); // 3번 섹션
    func(n / 3, a, b + n / 3);     // 4번 섹션
    // 5번 섹션 공백 출력
    func(n / 3, a + n / 3 * 2, b + n / 3);     // 6번 섹션
    func(n / 3, a, b + n / 3 * 2);             // 7번 섹션
    func(n / 3, a + n / 3, b + n / 3 * 2);     // 8번 섹션
    func(n / 3, a + n / 3 * 2, b + n / 3 * 2); // 9번 섹션
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        fill(star[i], star[i] + N, ' ');
    func(N, 0, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << star[i][j];
        }
        cout << '\n';
    }
}
