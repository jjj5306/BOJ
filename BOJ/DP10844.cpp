/** DP 10844 쉬운 계단 수 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

long long n;
long long dp[120][10];
const long long MOD = 1000000000;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // dp[i][j] = i자리 j로 시작하는 계단 수 개수
            if (j != 0)
                dp[i][j] += dp[i - 1][j - 1];
            if (j != 9)
                dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] %= MOD;
        }
    }

    long long ans = 0;
    for (int j = 1; j < 10; j++)
    {
        ans += dp[n][j];
        ans %= MOD;
    }
    cout << ans;
}
