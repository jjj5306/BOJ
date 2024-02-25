/** 매개변수탐색 2512 예산 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m, sum = 0;
int cost[100100];

int func(int mid)
{
    int rt = 0;
    for (int i = 0; i < n; i++)
        if (mid < cost[i])
            rt += mid;
        else
            rt += cost[i];
    return rt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    cin >> m;

    sort(cost, cost + n);

    // 1번 조건 판단
    for (int i = 0; i < n; i++)
        sum += cost[i];
    if (sum <= m)
    {
        cout << cost[n - 1] << '\n';
        return 0;
    }

    // k값 이분 탐색으로 정하기
    int left = 1, right = cost[n - 1], mid, max_k;
    max_k = 1;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (func(mid) <= m)
        {
            // 현재 l~r의 합이 m보다 작으면 mid 오른쪽 구간 탐색
            left = mid + 1;
            max_k = max(max_k, mid);
        }
        else
        {
            // 현재 l~r의 합이 m보다 크다면 mid 왼쪽 구간 탐색
            right = mid - 1;
        }
    }
    cout << max_k << '\n';
}
