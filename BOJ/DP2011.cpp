/** DP 2011 암호코드 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int MOD = 1000000;
string s;
int dp[5050];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int n = s.size();

    // n자리수
    // dp[i] = i자리까지 체크한 암호코드 수 0 index 주의
    if (s[0] - '0' <= 0)
        cout << "0\n";
    else
    {
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] - '0' > 0)
                dp[i] = (dp[i] + dp[i - 1]) % MOD;
            int x = stoi(s.substr(i - 1, 2));
            if (x >= 10 && x <= 26)
            {
                if (i - 2 < 0)
                    dp[i] = (dp[i] + 1) % MOD;
                else
                    dp[i] = (dp[i] + dp[i - 2]) % MOD;
            }
        }
        cout << dp[n - 1] << '\n';
    }
}
