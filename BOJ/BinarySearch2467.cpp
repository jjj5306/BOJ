/** BS 2467 용액 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int arr[100100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // arr[i]와 합이 0에 가장 가까운 index를 찾아보자.
    //-arr[i] 이상인 값 중 가장 작은 값을 k라 하면
    // k, k-1, k+1 중에 답이 될 수 있는데, arr[i] == k 면 안된다.

    int ans1 = 1e9 + 1, ans2 = 1e9 + 1;
    for (int i = 0; i < n; i++)
    {
        // arr[i]에 대해 답이 될 수 있는 후보 체크
        int k = lower_bound(arr, arr + n, -arr[i]) - arr;
        // arr[i], arr[k-1] 체크
        if (i != k - 1 && k - 1 >= 0 && abs(arr[i] + arr[k - 1]) < abs(ans1 + ans2))
        {
            ans1 = arr[i];
            ans2 = arr[k - 1];
        }
        // arr[i], arr[k] 체크
        if (i != k && k < n && abs(arr[i] + arr[k]) < abs(ans1 + ans2))
        {
            ans1 = arr[i];
            ans2 = arr[k];
        }
        // arr[i], arr[k+1] 체크
        if (i != k + 1 && k + 1 < n && abs(arr[i] + arr[k + 1]) < abs(ans1 + ans2))
        {
            ans1 = arr[i];
            ans2 = arr[k + 1];
        }
    }
    if (ans1 > ans2)
        cout << ans2 << ' ' << ans1 << '\n';
    else
        cout << ans1 << ' ' << ans2 << '\n';
}
