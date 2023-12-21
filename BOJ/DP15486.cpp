/** DP 15486 퇴사2 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int t[1500010];
int p[1500010];
int dp[1500010];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];

    fill(dp, dp + n + 3, 0);

    // dp[i] = i일차에 상담 시작 i는 n부터 시작
    for (int i = n; i > 0; i--)
    {
        // i일차의 상담을 할 수 있는 경우
        if (i + t[i] - 1 <= n)
        {
            // i일차의 상담을 한다면 dp[i+t[i]]부터 상담을 할 수 있다.
            // 따라서 i일차의 상담을 한다면 dp[i]는 p[i]+dp[i+t[i]]가 된다.
            // i일차의 상담을 하지 않는다면 dp[i+1]
            dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
        }
        else
        {
            // i일차의 상담을 할 수 없다면 dp[i+1] 그대로 가져오기
            dp[i] = dp[i + 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(dp[i], ans);

    cout << ans << '\n';
}
