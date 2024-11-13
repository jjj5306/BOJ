/** 재귀 5904 Moo 게임 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
long long len[1000];
// n이 10^9으로 n번째 수열을 구하는 것은 불가능함.
// n번째 문자가 무엇인지를 구하는 것이 가장 핵심
// S(k-1)의 길이를 안다면 n번째 문자가 무엇인지 알 수 있음!
// S(k-1)의 길이를 l이라 한다면 S(k)의 0~l-1 까지의 수열은 S(k-1), l ~ l+k+3 까지는 moooo..o, 그 뒤부터는 S(k-1)

// n번째 문자가 S(k-1)에 속했다면 S(k-1)에서 어디에 속했는지 구하기
// n번째 문자가 mo...o에 속했다면 바로 구하기

char solve(int k, long long n)
{
    // base condition
    if (k == 0)
        if (n == 0)
            return 'm';
        else
            return 'o';

    // 재귀식
    if (n < len[k - 1])
    {
        // n이 S(n-1)에 속함
        return solve(k - 1, n);
    }
    else if (n < len[k - 1] + k + 3)
    {
        // n이 가운데에 속함
        if (n == len[k - 1])
            return 'm';
        return 'o';
    }
    else
    {
        // n이 마지막 S(n-1)에 속함
        // 마지막에 속해있다는 것은 그 n을 앞으로 땡겨서 제일 처음에 속한것과 똑같이 처리할 수 있음
        return solve(k - 1, n - (len[k - 1] + k + 3));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    n--; // 0 based index
    len[0] = 3;
    int k = 0;
    while (len[k] <= n)
    {
        k++;
        len[k] = len[k - 1] * 2 + k + 3;
    }

    cout << solve(k, n) << '\n';
}
