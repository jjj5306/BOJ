/** DP 12865 평범한 배낭 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, k;
int w[104];
int v[104];
int dp[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    for (int j = 0; j < n; j++)
    { // 각 물건마다 한 번씩
        for (int i = k; i >= w[j]; i--)
        {

            dp[i] = max(dp[i], dp[i - w[j]] + v[j]);
        }
    }

    cout << dp[k] << '\n';
}
