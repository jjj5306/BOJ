/**  **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int arr[10010];
int n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    while (m--)
    {
        int i, j, k;
        cin >> i >> j >> k;

        int temp_arr[10010];
        for (int i = 1; i <= n; i++)
            temp_arr[i] = arr[i];

        sort(temp_arr + i, temp_arr + j + 1);

        cout << temp_arr[i + k - 1] << '\n';
    }
}
