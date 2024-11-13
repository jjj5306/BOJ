/** 재귀 1914 하노이 탑 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

void hanoi(long long a, long long b, long long n)
{
    if (n == 1)
    {
        cout << a << ' ' << b << '\n';
        return;
    }
    hanoi(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    hanoi(6 - a - b, b, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long N;
    cin >> N;

    // 2^N - 1 계산을 문자열로 처리
    string result = "1";
    for (int i = 0; i < N; i++)
    {
        int carry = 0;
        for (int j = result.length() - 1; j >= 0; j--)
        {
            int digit = (result[j] - '0') * 2 + carry;
            result[j] = (digit % 10) + '0';
            carry = digit / 10;
        }
        if (carry)
            result = "1" + result;
    }

    // 1을 빼줌
    int lastIdx = result.length() - 1;
    result[lastIdx]--;

    cout << result << '\n';

    if (N <= 20)
    {
        hanoi(1, 3, N);
    }
}
