#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, ans = 0;
pair<int, int> arr[200005];
priority_queue<int, vector<int>, greater<int>> q;
// 최소 힙, 큐에 넣는다는 것은 수업을 강의실에 배정함을 뜻함.

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(arr, arr + n);
    // 빨리 시작하는 수업을 먼저 큐에 넣어야 함. 즉, 빨리 시작하는 수업을 먼저 넣을 수 있는 강의실에 넣어버려야지만 꽉 꽉 채워서 수업을 하게 됨.

    ans++;
    q.push(arr[0].second);
    for (int i = 1; i < n; i++)
    {
        if (q.top() <= arr[i].first)
        {
            q.pop();
        }
        else
        {
            ans++;
        }
        q.push(arr[i].second);
    }

    cout << q.size();
}