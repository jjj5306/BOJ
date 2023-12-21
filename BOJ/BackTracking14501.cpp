/** BackTracking 14501 퇴사 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
int cur_day = 1, ans = 0, mx = 0;
pair<int, int> arr[20];

void func(int cnt)
{
    // base condition 1
    if (cur_day > n + 1)
    {
        return;
    }
    // base condition 2
    if (cnt > n)
    {
        ans = max(mx, ans);
        return;
    }

    // cnt일차 작업에 대해 판단
    // cnt일의 작업을 한다면 다음 작업은 cnt+arr[cnt].second+1부터 시작 가능
    // cnt일의 작업을 할 수 있는지 체크

    // 만약 지금이 2일이라 가정하면 2~7일차 작업 가능
    // 현재 스텝에선 cnt일의 작업을 할 수 있을지 체크
    // 못한다면 백트래킹
    if (cur_day <= cnt)
    {
        // cnt일의 작업 한 경우
        int tmp_day = cur_day;
        cur_day = cnt + arr[cnt].first;
        mx += arr[cnt].second;
        func(cnt + 1);

        // 다시 cnt일의 작업을 안한 경우로 롤백
        cur_day = tmp_day;
        mx -= arr[cnt].second;
        func(cnt + 1);
    }
    else
    {
        // cnt일 할 수 없음
        func(cnt + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].first >> arr[i].second;

    func(1);
    cout << ans << '\n';
}
