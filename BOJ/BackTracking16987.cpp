/** BackTracking 16987 계란으로 계란치기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
int table_hp[10];
int table_weight[10];
int res = 0;
int cnt = 0; // 깨진 계란 수

void func(int k)
{
    // k번째 계란으로 내려칠 차례이다.
    if (k == n)
    {
        res = max(res, cnt);
        return;
    }
    if (table_hp[k] <= 0 || cnt == n - 1)
    {
        func(k + 1);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == k || table_hp[i] <= 0)
            continue;
        table_hp[k] -= table_weight[i];
        table_hp[i] -= table_weight[k];
        if (table_hp[k] <= 0)
            cnt++;
        if (table_hp[i] <= 0)
            cnt++;
        func(k + 1);
        // 테이블 및 깨진 계란 수 복원
        if (table_hp[k] <= 0)
            cnt--;
        if (table_hp[i] <= 0)
            cnt--;
        table_hp[k] += table_weight[i];
        table_hp[i] += table_weight[k];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> table_hp[i] >> table_weight[i];
    }
    func(0);
    cout << res;
}
