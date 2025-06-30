/* 1477 Binary Search 휴게소 세우기 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, l, ans = 0x7f7f7f7f;
vector<int> arr;
int dist[55];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> l;

    // 고속도로 시작 위치
    arr.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    // 고속도로 끝 위치
    arr.push_back(l);

    sort(arr.begin(), arr.end());

    // m개의 휴게소를 지어야 한다. 이를 간격을 기준으로 지으면 된다.
    // 간격을 1로 짓는다면 굉장히 촘촘히 지어져 m개 이상의 휴게소가 지어진다.
    // 간격을 큰 값으로 짓는다면 적게 지어져 m개 보다 적은 수의 휴게소가 지어진다.
    // 그 중간 값을 찾아서 m개의 휴게소를 지어야 한다.
    int start = 1, end = l - 1, mid;
    // start와 end가 같아지면 간격이 0인 것이므로 종료(휴게소에 휴게소를 지으려 하는 경우)
    while (start < end)
    {
        // cout << start << ' ' << end << ' ' << mid << '\n';
        mid = (start + end) / 2;
        // mid 간격으로 지었을 때 몇 개 지을 수 있는지 계산
        int cur = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            int dif = arr[i] - arr[i - 1];
            // dif : i번과 i-1번 휴게소 사이의 간격
            cur += dif / mid;
            // 딱 나눠떨어지는 경우 하나의 휴게소가 겹치게 됨.
            if (dif % mid == 0)
                cur--;
        }
        if (cur > m)
        {
            // m 보다 많은 개수의 휴게소를 지었다면 간격 늘리기
            start = mid + 1;
        }
        else
        {
            // m 보다 같거나 적게 지은 경우 간격 줄이기
            end = mid;
            ans = min(ans, mid);
        }
    }
    cout << ans << '\n';
}