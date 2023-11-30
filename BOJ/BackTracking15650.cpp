/** BackTracking 15650 N과 M (2) **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 10
using namespace std;

int n, m; // 1 ~ n 까지 자연수 중 m 개를 선택한다.
int res[MAX];
bool visited[MAX];

void func(int k)
{
    // 현재 k개까지 수를 선택함
    if (k == m)
    {
        // base condition
        for (int i = 0; i < m; i++)
            cout << res[i] << ' ';
        cout << '\n';
        return;
    }
    // k가 1 이상이면 그 전단계에서 정한 수보다 하나 큰 수부터 탐색 시작
    // k가 0 이면 처음 시행하는 것이므로 1부터 탐색 시작
    int start = res[k - 1] + 1;
    if (k == 0)
        start = 1;
    for (int i = start; i <= n; i++)
    {
        if (!visited[i])
        {
            // 숫자 i가 사용되지 않았으면
            res[k] = i;
            visited[i] = true;
            func(k + 1);
            visited[i] = false; // k번째 수를 i로 정한 모든 경우를 출력했으니 다시 i를 사용해도 됨.
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}
