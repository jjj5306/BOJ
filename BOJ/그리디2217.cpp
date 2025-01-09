/** 그리디 2217 로프 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int rope[100010];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> rope[i];
    sort(rope, rope + n);

    int ans = 0;
    for (int k = 1; k <= n; k++)
        ans = max(ans, rope[n - k] * k);

    cout << ans << '\n';
}
