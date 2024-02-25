/** 그리디 13305 주유소 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
long long n, ans = 0;
long long dist[100100];
bool visited[100100];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> cost;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (long long i = 0; i < n - 1; i++)
        cin >> dist[i];
    for (long long i = 0; i < n; i++)
    {
        long long cost_;
        cin >> cost_;
        cost.push({cost_, i});
    }
    // dist[i] : i -> i+1 거리
    // cost[i] : i번 도시의 기름값

    while (!cost.empty())
    {
        auto min = cost.top();
        cost.pop();
        // min_idx에서 살 수 있는만큼 다 사기
        for (long long i = min.second; i < n - 1; i++)
        {
            if (visited[i])
                break;
            ans += min.first * dist[i];
            visited[i] = true;
        }
    }

    cout << ans << '\n';
}
