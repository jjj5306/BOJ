/** 구현 17266 어두운 굴다리 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m, ans;
vector<int> light;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        light.push_back(x);
    }

    ans = light[0];
    for (int i = 1; i < m; i++)
        ans = max(ans, ((light[i] - light[i - 1]) + 1) / 2);
    ans = max(ans, n - light.back());

    cout << ans << '\n';
}
