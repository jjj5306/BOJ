/** Two Pointer 2003 수들의 합 2 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m, ans = 0;
int arr[10100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // st ~ en 의 합이 m 이상이 되면 st 증가
    int end = 0, sum = arr[0];
    for (int start = 0; start < n; start++)
    {
        while (end < n && sum < m)
        {
            end++;
            if (end < n)
                sum += arr[end];
        }
        if (sum == m)
            ans++;
        sum -= arr[start];
    }

    cout << ans << '\n';
}
