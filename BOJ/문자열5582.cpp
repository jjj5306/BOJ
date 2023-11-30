/** 문자열 5582 공통 부분 문자열 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;

    vector<vector<int>> dp(s2.length(), vector<int>(s1.length(), 0));
    for (int i = 0; i < s2.length(); i++)
    {
        for (int j = 0; j < s1.length(); j++)
        {
            if (s2[i] == s1[j])
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}
