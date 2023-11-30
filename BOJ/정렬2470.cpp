/** 정렬 2470 두 용액 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> solve(N);
    for (int i = 0; i < N; i++)
        cin >> solve[i];

    sort(solve.begin(), solve.end());

    int point_start = 0, point_end = N - 1;
    int min = abs(solve[point_start] + solve[point_end]);
    int min_idx_st = 0, min_idx_end = N - 1;
    while (point_start < point_end)
    {
        int add = solve[point_start] + solve[point_end];
        if (abs(add) < min)
        {
            min = abs(add);
            min_idx_st = point_start;
            min_idx_end = point_end;
        }
        if (add > 0)
            point_end--;
        else
            point_start++;
    }
    cout << solve[min_idx_st] << " " << solve[min_idx_end];
}