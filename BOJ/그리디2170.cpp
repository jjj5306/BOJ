/** 그리디 2170 선 긋기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int ans = 0;
int n;
vector<pair<int, int>> lines;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        lines.push_back({a, b});
    }

    sort(lines.begin(), lines.end());

    int start = lines[0].first;
    int end = lines[0].second;

    for (int i = 1; i < n; i++)
    {
        // 겹치는 선분
        if (lines[i].first <= end)
        {
            end = max(end, lines[i].second);
        }
        else
        {
            // 새로운 선분
            ans += end - start;
            start = lines[i].first;
            end = lines[i].second;
        }
    }
    ans += end - start;

    cout << ans << '\n';
}
