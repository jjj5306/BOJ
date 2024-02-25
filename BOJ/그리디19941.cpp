/** 그리디 19941 햄버거 분배 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, k, p = 0, ans = 0, p_size = 0;
bool visited[20100];
char table[20100];

void nxtP()
{
    while (p <= n)
    {
        p++;
        if (table[p] == 'P')
            break;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    table[0] = 'n';
    for (int i = 1; i <= n; i++)
    {
        cin >> table[i];
        if (table[i] == 'P')
            p_size++;
    }

    // 초기값 세팅
    nxtP();
    while (p_size--)
    {
        for (int h = max(p - k, 0); h <= min(p + k, n); h++)
        {
            if (table[h] == 'H' && !visited[h])
            {
                // 아직 먹지 않았고 먹을 수 있는 햄버거 중 가장 왼쪽 햄버거 먹기
                ans++;
                visited[h] = true;
                break;
            }
        }
        nxtP();
    }

    cout << ans << '\n';
}
