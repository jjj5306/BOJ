#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int arr[1010][3];
int dp[1003][3];
int ans = 1000001;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    // 완전 탐색 -> 1000^3
    // -> 메모이제이션, dp[k][0] : k번째 집을 R로 칠했을 때 최소값
    // 점화식 : dp[k][0] : k-1 번째 집은 R이 아닌 다른 색으로 칠해야 함. 따라서 dp[k-1][1] or dp[k-1][2] + arr[k][0]
    // 첫 번째 집은 마지막 집의 색과 달라야 함. 만약 마지막 집을 계산할 때 dp[n-1][0] -> 첫 번째 집이 0으로 시작하는 경우가 dp[n-2][]에 포함될 수 있음.
    // 그렇다면 첫 번째 집을 R로 해서 dp 계산, G로 해서 dp 계산을 반복

    // 1. 첫 번째 집을 R로 칠하는 경우만 계산하기 위해 첫 번째 집을 G, B로 색칠하는 경우는 매우 큰 값으로 두어 경로에서 선택되는 일이 없게 보장
    dp[0][0] = arr[0][0];
    dp[0][1] = 1000001;
    dp[0][2] = 1000001;
    for (int k = 1; k < n; k++)
    {
        // k번째 집 칠하기
        for (int i = 0; i < 3; i++)
        {
            // k번째 집을 i 색으로 칠하려면 k-1의 i 색은 못칠함
            dp[k][i] = min(dp[k - 1][(i + 1) % 3], dp[k - 1][(i + 2) % 3]) + arr[k][i];
        }
    }
    ans = min(dp[n - 1][1], dp[n - 1][2]);

    // 2. 첫 번째 집을 G로 칠하는 경우
    dp[0][0] = 0x3f3f3f3f;
    dp[0][1] = arr[0][1];
    dp[0][2] = 0x3f3f3f3f;
    for (int k = 1; k < n; k++)
    {
        // k번째 집 칠하기
        for (int i = 0; i < 3; i++)
        {
            // k번째 집을 i 색으로 칠하려면 k-1의 i 색은 못칠함
            dp[k][i] = min(dp[k - 1][(i + 1) % 3], dp[k - 1][(i + 2) % 3]) + arr[k][i];
        }
    }
    ans = min(ans, min(dp[n - 1][0], dp[n - 1][2]));

    // 3. 첫 번째 집을 B로 칠하는 경우
    dp[0][0] = 0x3f3f3f3f;
    dp[0][1] = 0x3f3f3f3f;
    dp[0][2] = arr[0][2];
    for (int k = 1; k < n; k++)
    {
        // k번째 집 칠하기
        for (int i = 0; i < 3; i++)
        {
            // k번째 집을 i 색으로 칠하려면 k-1의 i 색은 못칠함
            dp[k][i] = min(dp[k - 1][(i + 1) % 3], dp[k - 1][(i + 2) % 3]) + arr[k][i];
        }
    }
    ans = min(ans, min(dp[n - 1][1], dp[n - 1][0]));

    cout << ans << '\n';
}