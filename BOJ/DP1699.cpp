/** DP 1699 제곱수의 합 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

long long n, cur = 1;
long long number[100010];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(number, number + n + 1, 10010);
    // 주어진 범위까지의 제곱수 모두 기록
    for (long long i = 1; i * i <= 100000; i++)
        number[i * i] = 1;

    for (long long i = 1; i <= n; i++)
        // i가 제곱수인 경우 cur 갱신
        for (long long j = 1; j * j <= i; j++)
            number[i] = min(number[i], number[i - j * j] + 1);

    cout << number[n];
}
