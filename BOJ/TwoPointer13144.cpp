/** Two Pinter 13144: List of Unique Numbers **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int n;
long long ans = 0;

int arr[100100];
bool vis[100100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // 다음 수가 중복된 수일 때까지 en 증가
    int end = 0;
    vis[arr[end]] = 1;
    for (int start = 0; start < n; start++)
    {
        while (end < n - 1 && !vis[arr[end + 1]])
        {
            end++;
            vis[arr[end]] = 1;
        }
        ans += (end - start + 1);
        vis[arr[start]] = 0;
    }

    cout << ans << '\n';
}
