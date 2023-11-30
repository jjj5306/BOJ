/** 시뮬레이션 15686 치킨 배달 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
int city[55][55];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> city[i][j];
            if (city[i][j] == 1)
                house.push_back({i, j});
            if (city[i][j] == 2)
                chicken.push_back({i, j});
        }
    // m개의 치킨집 조합을 구하기 위한 초기 설정
    vector<bool> permutation(chicken.size(), true);
    fill(permutation.begin(), permutation.begin() + chicken.size() - m, false);
    int res = 999999;

    do
    {
        int res_cur = 0;
        for (auto cur_house : house)
        {
            // cur_house와 permutation 배열의 값이 1인 index의 치킨집간의 거리 중 최소값을 구해보자.
            int min_cur = 999999;
            for (int i = 0; i < permutation.size(); i++)
            {
                if (!permutation[i])
                    continue;
                // chicken[i]와 cur_house의 거리 중 최소값을 구하면 된다.
                min_cur = min(min_cur, abs(chicken[i].first - cur_house.first) + abs(chicken[i].second - cur_house.second));
            }
            res_cur += min_cur;
        }
        res = min(res, res_cur);
    } while (next_permutation(permutation.begin(), permutation.end()));
    cout << res << '\n';
}
