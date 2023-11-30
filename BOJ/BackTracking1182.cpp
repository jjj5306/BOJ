/** 백트래킹 1182 부분수열의 합 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 22
using namespace std;

int arr[MAX];
int N, S, res = 0;

void func(int cur, int sum)
{
    if (cur == N)
    {
        // base condition
        if (sum == S)
            res++;
        return;
    }
    func(cur + 1, sum);
    func(cur + 1, sum + arr[cur]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    func(0, 0);
    if (S == 0)
        res--;
    cout << res;
}
