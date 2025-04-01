/** Two Pointer 22862 가장 낀 짝수 연속한 부분 수열 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, k, ans = 0;
int arr[1000100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cur = 0; // st~en 까지의 홀수 개수
    if (arr[0] % 2 == 1)
        cur++;
    int end = 0;

    // end는 홀수를 최대한 제거하면서 전진
    // 최대한 다 제거했으면 start 증가, 단 start + 1이 홀수인지 아닌지 추적해야 함.
    for (int start = 0; start < n; start++)
    {
        while (end < n - 1)
        {
            // end 다음 수가 홀수인데 제거할 수 없는 경우 종료
            if (cur + arr[end + 1] % 2 > k)
                break;
            // end 다음 수 체크
            cur += arr[end + 1] % 2;
            end++;
        }
        ans = max(ans, end - start + 1 - cur);
        cur -= arr[start] % 2;
    }
    cout << ans << '\n';
}
