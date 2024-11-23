/** 백트래킹 15664 N과 M (10) **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int arr[10];
int res[10];
bool visited[10];
int n, m;

void func(int k, int start)
{
    // k번째 수를 찾음. res 배열은 오름차순이 되어야 하므로 start <= index 선택
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << res[i] << ' ';
        cout << '\n';
        return;
    }
    int prev = -1;
    for (int i = start; i < n; i++)
    {
        if (!visited[i] && prev != arr[i])
        {
            prev = arr[i];
            res[k] = arr[i];
            visited[i] = true;
            func(k + 1, i + 1);
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

    func(0, 0);
}
