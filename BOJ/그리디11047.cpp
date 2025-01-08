/** 그리디 11047 동전 0 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, k;
int ans = 0;
int coins[15];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int cnt = n - 1;
    while (k != 0 && cnt >= 0)
    {
        if (coins[cnt] > k)
        {
            cnt--;
            continue;
        }
        ans += k / coins[cnt];
        k = k % coins[cnt];
        cnt--;
    }

    cout << ans << '\n';
}
