/** Two Pointer 2230: 수 고르기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int n, m;
long long arr[100100];
long long ans = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int en = 0;
    for (int st = 0; st < n; st++)
    {
        while (en < n && arr[en] - arr[st] < m)
            en++;
        // en을 찾음, en = n-1 일 때 en++을 하고 종료하므로 en == n인지 체크해야 함.
        if (en == n)
            break;
        ans = min(ans, arr[en] - arr[st]);
    }
    cout << ans << '\n';
}
