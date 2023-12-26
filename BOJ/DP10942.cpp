/** DP 10942 팰린드롬? **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int num[2023];
int dp[2023][2023];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    cin >> m;

    // dp 초기값 세팅 [i][i]는 당연히 팰린드롬
    // [i][i+1]은 두 값이 같으면 팰린드롬
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
        if (num[i] == num[i + 1])
            dp[i][i + 1] = 1;
    }

    for (int col = 3; col <= n; col++)
        for (int row = 1; row <= col - 2; row++)
            if (num[col] == num[row] && dp[row + 1][col - 1])
                dp[row][col] = 1;

    while (m--)
    {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }
}
