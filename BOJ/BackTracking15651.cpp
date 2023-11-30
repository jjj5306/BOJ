/** BackTracking 15650 N과 M (3) **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 10
using namespace std;

int n, m; // 1 ~ n 까지 자연수 중 m 개를 선택한다.
int res[MAX];

void func(int k)
{
    // 현재 k개까지 수를 선택함
    if (k == m)
    {
        // base condition
        for (int i = 0; i < m; i++)
            cout << res[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        res[k] = i;
        func(k + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}
