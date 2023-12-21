/** DP 11726 2xn 타일링 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
int dp[1002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp[0] = 1;
    dp[1] = 3;
    for (int i = 2; i < n; i++)
        dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
    cout << dp[n - 1];
}
