/** 정렬 2910 빈도 정렬 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, c;

bool cmp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
{
    if (a.second.first != b.second.first)
        return a.second.first > b.second.first;
    return a.first < b.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    vector<pair<int, pair<int, int>>> num; // order, cnt, value 순으로 저장
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        int k;
        for (k = 0; k < num.size(); k++)
            // num안에 val이 있다면 cnt만 증가
            if (num[k].second.second == val)
            {
                num[k].second.first++;
                break;
            }

        if (k == num.size())
            // 못 찾았으므로 num에 삽입, 순서는 i번째 삽입이다.
            num.push_back({i, {1, val}});
    }
    // num을 cnt 기준으로 내림차순 정렬하면 되는데, cnt가 같으면 order 기준 오름차순 정렬
    sort(num.begin(), num.end(), cmp);
    // 정렬 완료, 차례대로 cnt만큼 val을 출력하면 된다.
    for (auto x : num)
        while (x.second.first--)
            cout << x.second.second << ' ';
}
