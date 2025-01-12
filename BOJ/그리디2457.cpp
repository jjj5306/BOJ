/** 그리디 2457 공주님의 정원 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> flowers; // {피는 날짜, 지는 날짜}
int n;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)         // 피는 날짜가 같으면
        return a.second > b.second; // 더 늦게 지는 것이 앞으로
    return a.first < b.first;       // 더 일찍 피는 것이 앞으로
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;
        flowers.push_back({m1 * 100 + d1, m2 * 100 + d2});
    }

    // 현재 시간을 기준으로 피어있는 꽃 중 가장 늦게 지는 꽃 선택.
    // 선택한 꽃이 지는 시간을 현재 시간으로 변경.
    // 반복문을 종료 조건은 다음과 같음.
    // 1. 현재 피어있는 꽃이 없음. 이 경우 0이 나올 수 있음.
    // 2. 현재 날짜가 11월31일보다 뒤임. 이 경우 0이 나올 수 없음.
    // 날짜의 표시는 301 -> 3월 1일 이런식으로 표시. 월에 100을 곱함.

    sort(flowers.begin(), flowers.end(), cmp);

    int cur_time = 301; // 3월 1일부터 시작
    int ans = 0;        // 선택한 꽃의 개수

    while (cur_time < 1201)
    {
        int next_time = 0;
        for (int i = 0; i < n; i++)
        {
            // 현재 피어있는 꽃 중 가장 늦게 지는 꽃 선택택
            if (flowers[i].first <= cur_time && flowers[i].second > cur_time)
                next_time = max(next_time, flowers[i].second);
        }
        // 종료 조건 1, 현재 피어있는 꽃이 없음.
        if (next_time == 0)
        {
            cout << "0\n";
            return 0;
        }

        ans++;
        cur_time = next_time;
    }
    cout << ans << '\n';
}