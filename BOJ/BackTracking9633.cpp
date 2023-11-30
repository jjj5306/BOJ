/** BacKTracKing 9663 N-Queen **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 15
using namespace std;

int n;
int res = 0;
bool visited_vertical[40];
bool visited_diagonal1[40];
bool visited_diagonal2[40];

void func(int Q)
{
    // Q번째 퀸을 놓으면 된다.
    if (Q == n)
    {
        // base condition
        res++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // Q행 i열에 퀸을 놓을 수 있는지 체크
        if (visited_vertical[i])
            continue;
        if (visited_diagonal1[Q + i])
            continue;
        if (visited_diagonal2[Q - i + n - 1])
            continue;
        // 놓을 수 있으므로 놓고 방문 체크
        visited_vertical[i] = true;
        visited_diagonal1[Q + i] = true;
        visited_diagonal2[Q - i + n - 1] = true;
        func(Q + 1);

        // Q번째 퀸을 다 놓아 봤으므로 다시 초기화
        visited_vertical[i] = false;
        visited_diagonal1[Q + i] = false;
        visited_diagonal2[Q - i + n - 1] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0);
    cout << res;
}
