/** BackTracking N과 M (5) **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
int arr[10];
int res[10];
bool visited[10];

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << res[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            res[k] = arr[i];
            visited[i] = true;
            func(k + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    func(0);
}
