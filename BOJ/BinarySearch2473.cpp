/** BS 2473: 세 용액 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int n;
long long arr[5030];
long long ans[3] = {LLONG_MAX / 3, LLONG_MAX / 3, LLONG_MAX / 3};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // (i, j)를 선택하고 그 용액과 합이 0과 가장 가까운 용액을 찾아야 함. 0과 가장 가까우려면 찾은 idx와 idx-1만 생각하면 된다.
            int idx = lower_bound(arr, arr + n, -(arr[i] + arr[j])) - arr;
            // lower_bound가 i, j와 같을 수 있다. 원래 찾은 idx가 j와 같다면 idx+1을 봐야 한다.
            // idx가 i와 같고 그 다음에 j가 바로 오는 경우도 있으므로 idx+2도 봐야 한다.
            // idx-1도 생각해보면 idx-1이 i, j와 같을 수 있으므로 idx -2, -3까지 봐야 한다.
            for (int k = -3; k <= 2; k++)
            {
                // idx+k가 범위를 벗어나는 경우
                if (idx + k < 0 || idx + k >= n)
                    continue;
                // idx + k가 i, j와 겹치는 경우
                if (idx + k == i || idx + k == j)
                    continue;
                if (abs(ans[0] + ans[1] + ans[2]) > abs(arr[i] + arr[j] + arr[idx + k]))
                {
                    ans[0] = arr[i];
                    ans[1] = arr[j];
                    ans[2] = arr[idx + k];
                }
            }
        }
    }

    sort(ans, ans + 3);
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
}
