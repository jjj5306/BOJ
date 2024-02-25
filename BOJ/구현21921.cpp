/** 구현 21921 블로그 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, x, ans_max = 0, ans_cnt = 0;
int cost[250100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    // 초기값 세팅
    int sum = 0;
    for (int i = 0; i <= x - 1; i++)
    {
        sum += cost[i];
    }
    ans_max = sum;
    ans_cnt = 1;

    for (int i = 1; i <= n - x; i++)
    {
        sum -= cost[i - 1];
        sum += cost[i + x - 1];
        if (ans_max == sum)
            ans_cnt++;
        else if (ans_max < sum)
        {
            ans_cnt = 1;
            ans_max = sum;
        }
    }
    if (ans_max == 0)
    {
        cout << "SAD" << '\n';
        return 0;
    }
    cout << ans_max << '\n';
    cout << ans_cnt;
}
