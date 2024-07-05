/** BackTracking 14889 스타트와 링크 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
int board[30][30];
int ans = 999999999;

int solve(vector<bool> &permutation)
{
    int t_start = 0, t_link = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (permutation[i])
            {
                // t_start 계산
                if (!permutation[j])
                    continue;
                t_start += board[i][j];
            }
            else
            {
                if (permutation[j])
                    continue;
                t_link += board[i][j];
            }
        }
    }
    return abs(t_start - t_link);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    // board에서 2/n개의 조합을 구하기 위한 초기 설정
    vector<bool> permutation(n, true);
    fill(permutation.begin(), permutation.begin() + n / 2, false);

    do
    {
        // permutation의 값이 같은 index 끼리 선수의 합을 모두 더하면 된다.
        ans = min(ans, solve(permutation));

    } while (next_permutation(permutation.begin(), permutation.end()));
    cout << ans << '\n';
}
