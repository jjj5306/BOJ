/** DP 11055 가장 큰 증가하는 부분 수열 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int dp[1004], board[1004];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        dp[i] = board[i];
        // 이 부분이 상당히 중요함.
        // dp[i]를 board[i]로 초기화하지 않으면 dp[i]를 시작으로 하는 부분 수열을 체크할 수 없음.
    }
    for (int i = 1; i < n; i++)
    {
        // dp[i]를 채우면 되는데, dp[i]는 board[i]를 사용했을 때 최대값
        for (int j = 0; j < i; j++)
        {
            // j번째 원소와 비교 중인 상태
            if (board[i] > board[j])
                dp[i] = max(dp[i], dp[j] + board[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans;
}
