/** Two Pointer 1806 부분합 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int n, s;
int arr[100100];
int ans = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int en = 0, tmp = arr[0];
    for (int st = 0; st < n; st++)
    {
        while (en < n && tmp < s)
        {
            en++;
            if (en != n)
                tmp += arr[en];
        }
        if (en == n)
            break;
        ans = min(ans, en - st + 1);
        tmp -= arr[st];
    }
    if (ans == INT_MAX)
        ans = 0;
    cout << ans << '\n';
}
