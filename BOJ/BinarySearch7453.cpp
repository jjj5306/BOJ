/** BS 7453: 합이 0인 네 정수 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int arr[4][4003];
int sum[2][4003 * 4003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int j = 0; j < n; j++)
        cin >> arr[0][j] >> arr[1][j] >> arr[2][j] >> arr[3][j];

    // 배열을 두 개씩 합을 구한다.
    for (int step = 0; step < 4; step += 2)
    {
        int tmp = 1;
        if (step == 0)
            tmp = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                // step 배열의 i번째 수 + (step+1) 배열의 j번째 수 -> sum[(step+4)%4][i*n+j]에 저장.
                sum[tmp][i * n + j] = arr[step][i] + arr[step + 1][j];
    }

    sort(sum[0], sum[0] + n * n);
    sort(sum[1], sum[1] + n * n);

    // 두 배열에 대해 각 수의 합이 0인 쌍을 찾으면 됨.
    long long ans = 0;
    for (int i = 0; i < n * n; i++)
    {
        // sum[0][i]와 합이 0인 수 찾기
        ans += upper_bound(sum[1], sum[1] + n * n, -sum[0][i]) - lower_bound(sum[1], sum[1] + n * n, -sum[0][i]);
    }

    cout << ans << '\n';
}
