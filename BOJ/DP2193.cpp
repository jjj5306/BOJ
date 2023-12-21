/** DP 2193 이친수 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

long long dp[100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    fill(dp, dp + n + 1, 0);
    dp[1] = dp[2] = 1;

    // dp[k] = dp[k-2] + dp[k-3] + ... + dp[1]
    // => 피보나치
    for (long long i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[n];
}
