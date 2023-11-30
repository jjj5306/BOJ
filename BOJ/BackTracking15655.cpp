/** BackTracking 15655 N과 M (6) **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int arr[10];
pair<int, int> res[10];
bool visited[10];
int n, m;

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << res[i].first << ' ';
        cout << '\n';
        return;
    }
    int starting_idx = 0;
    if (k >= 1)
        starting_idx = res[k - 1].second;
    for (int i = starting_idx; i < n; i++)
    {
        if (!visited[i])
        {
            res[k] = make_pair(arr[i], i);
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
