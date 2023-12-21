/** 정렬 11652 카드 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
long long card[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> card[i];

    sort(card, card + n);

    long long ans_val = card[0], cur_cnt = 1, max_cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (card[i - 1] == card[i])
            cur_cnt++;

        else
        {
            if (cur_cnt > max_cnt)
            {
                ans_val = card[i - 1];
                max_cnt = cur_cnt;
            }
            cur_cnt = 1;
        }
    }
    if (cur_cnt > max_cnt)
        ans_val = card[n - 1];

    cout << ans_val << '\n';
}
