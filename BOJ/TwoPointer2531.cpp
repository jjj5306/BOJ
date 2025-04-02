/** Two Pointer 2531 회전 초밥 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, d, k, c;
int ans = 1;
int arr[30100 * 2];
int vis[30100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }

    int end = 1, cnt = 1;
    vis[c]++;
    vis[arr[0]]++;
    if (arr[0] != c)
        cnt++;

    for (int start = 0; start < n; start++)
    {
        while (end - start + 1 <= k && end < 2 * n)
        {
            // end번 초밥을 먹음.
            if (vis[arr[end]] == 0)
                cnt++;
            vis[arr[end]]++;

            // cout << end << ' ' << cnt << '\n';
            end++;
        }

        // cout << "*********\n"
        //      << start << ' ' << end << '\n';
        // cout << cnt << '\n';

        ans = max(ans, cnt);

        // start를 다음으로 옮기기 위함
        vis[arr[start]]--;

        if (vis[arr[start]] == 0)
            cnt--;
    }
    cout << ans << '\n';
}
