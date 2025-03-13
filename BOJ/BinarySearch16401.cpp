/** BS 16401 과자 나눠주기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int m, n;
long long L[1000005];

// X로 잘랐을 때 만들어지는 과자의 개수
long long getans(int X)
{
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // L[i]를 길이 X로 자른다.
        cnt += L[i] / X;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < n; i++)
        cin >> L[i];

    sort(L, L + n);

    // 1부터 L[n] 까지 파라미터 서치
    long long left = 0;
    long long right = L[n - 1];

    while (left < right)
    {
        long long mid = (left + right + 1) / 2;

        // mid개로 잘랐을 때 m개 이상의 조각이 나온다면 mid ~ m 조사
        if (getans(mid) >= m)
            left = mid;
        // m개 이상이 나오지 않으면 mid보다 작게 잘라야함.
        else
            right = mid - 1;
    }
    cout << left << '\n';
}
