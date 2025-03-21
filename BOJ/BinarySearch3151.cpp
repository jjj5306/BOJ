/** bs 3151 합이 0 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int arr[10005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    long long ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            //(i+j) 값의 lower bound -> 합이 0이 될 수 있는 후보
            long long k = lower_bound(arr + j + 1, arr + n, -(arr[i] + arr[j])) - arr;
            if (arr[i] + arr[j] + arr[k] != 0)
                continue;
            // k번째 값을 더하면 0이 되는 것을 확인. 하지만 여러 개 있을 수 있으므로 upper bound로 확인해야 함.
            long long u = upper_bound(arr + j + 1, arr + n, -(arr[i] + arr[j])) - arr;
            ans += u - k;
        }
    }
    cout << ans << '\n';
}
