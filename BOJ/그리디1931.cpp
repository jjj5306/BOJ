/** 그리디 1931 회의실 배정정 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
pair<int, int> c[100005]; // end time, start time
int ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int e, s;
        cin >> s >> e;
        c[i] = {e, s};
    }

    sort(c, c + n);

    int cur = c[0].first;
    ans++;

    for (int i = 1; i < n; i++)
    {
        // i번째 회의의 start time이 현재 선택한 회의의 end time 보다 같거나 크면 바로 선택
        if (c[i].second < cur)
            continue;
        ans++;
        cur = c[i].first;
    }

    cout << ans << '\n';
}
