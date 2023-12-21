/** DP 9084 동전 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        int coin[25], dp[10040];

        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> coin[i];
        cin >> m;

        fill(dp, dp + m + 1, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = coin[i]; j <= m; j++)
            {
                if (coin[i] == j)
                    dp[j]++;
                dp[j] += dp[j - coin[i]];
            }
        }

        cout << dp[m] << '\n';
    }
}
