/** TwoPointer 1644 소수의 연속합 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, ans = 0;
int pnum[4000010];

void get_prime(int end)
{
    // end 보다 작은 소수 모두 구하기
    for (int i = 2; i * i <= end; i++)
    {
        if (pnum[i] == 1)
            continue;
        for (int j = i * i; j <= end; j += i)
        {
            pnum[j] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    get_prime(n);
    pnum[1] = pnum[0] = 1;

    // 연속 합으로 n을 찾으면 됨.
    // end는 계속 증가시키다가 합이 n 이상이 되면 st++

    int end = 2;
    long long sum = 2;
    for (int start = 2; start <= n;)
    {
        // cout << start << ' ' << end << ' ' << sum << ' ' << ans << '\n';
        while (end <= n && sum < n)
        {
            end++;
            if (pnum[end] == 0 && end <= n)
            {
                // cout << "***** " << start << ' ' << end << ' ' << sum << '\n';
                sum += end;
            }
        }
        if (end > n)
            break;
        if (sum == n)
            ans++;
        sum -= start;
        // start 갱신 다음 소수까지
        for (int iter = 0; iter < 4000000; iter++)
            if (pnum[++start] == 0)
                break;
    }

    cout << ans << '\n';
}
