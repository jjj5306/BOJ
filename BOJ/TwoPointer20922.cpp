/** TwoPointer 20922 겹치는 건 싫어 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, k;
int arr[200005];
int vis[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cnt = 0, end = 0, ans = 0;
    for (int start = 0; start < n; start++)
    {
        // start~end까지 같은 수가 K개 이하로 들어가있어야 함.
        // end번 원소를 포함할 수 있는지 체크
        while (end < n)
        {
            if (vis[arr[end]] >= k)
                break;
            vis[arr[end]]++;
            end++;
            cnt++;
        }
        // cout << start << ' ' << end << ' ' << cnt << '\n';
        ans = max(ans, cnt);
        // start번 제거
        vis[arr[start]]--;
        cnt--;
    }
    cout << ans << '\n';
}
