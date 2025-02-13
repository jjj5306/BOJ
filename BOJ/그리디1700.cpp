/** 그리디 1700 멀티탭 스케줄링링 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, k;
int ans = 0;
bool plug[105];
int order[105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        cin >> order[i];
    }

    int tmp = 0; // 현재 tmp개 꽂혀있음.

    for (int cur = 1; cur <= k; cur++)
    {
        // cur번 플래그가 이미 꽂혀있음.
        if (plug[order[cur]])
            continue;
        if (tmp < n)
        {
            // 꽂을 자리가 남음.
            plug[order[cur]] = true;
            tmp++;
        }
        else
        {
            vector<pair<int, int>> idx; // 내림차순으로 정렬해서 제일 나중에 나오는거 뽑아야하니까 first = 언제 나오는지지
            // 꽂혀있는 것 중 이제 사용하지 않거나 가장 나중에 사용하는 것 뽑기
            for (int i = 1; i <= k; i++)
            {
                // i번째 순서의 제품이 꽂혀있는지, 꽂혀있다면 다음에 언제 꽂히는지지
                if (!plug[i]) // 안꽂혀있는거
                    continue;
                // 꽂혀있는거면 cur번 다음에 언제 꽂히는지 알아야함
                bool zero = true; // 다음에 안꽂히면 zero = true
                for (int j = cur + 1; j <= k; j++)
                {
                    if (order[j] == i)
                    {
                        idx.push_back({j, i}); // j번째 순서로 i번 제품이 꽂힘
                        zero = false;
                        break;
                    }
                }
                if (zero)
                    idx.push_back({100000, i}); // 다음에 안꽂히므로 매우 큰 값 사용
            }
            sort(idx.begin(), idx.end(), greater<pair<int, int>>());
            int replace = idx[0].second;
            plug[replace] = false;
            plug[order[cur]] = true;
            // cout << "ans : " << ans << ", replace : " << replace << ", cur : " << order[cur] << '\n';
            ans++;
        }
    }
    cout << ans;
}
