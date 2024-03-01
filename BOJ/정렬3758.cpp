/** 정렬 3758 KCPC **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int score[101][101] = {}; // score[팀id][문제id] = 점수
        int cnt[101] = {};        // 팀별 제출 회수
        int idx[101] = {};        // 팀별 마지막 제출 시간
        int n, k, t, m;
        cin >> n >> k >> t >> m;
        t--;

        for (int i = 0; i < m; i++)
        {
            int tid, pid, score_;
            cin >> tid >> pid >> score_;
            tid--;
            pid--;

            score[tid][pid] = max(score[tid][pid], score_);
            cnt[tid]++;
            idx[tid] = i;
        }

        vector<pair<pair<int, int>, pair<int, int>>> result;
        // first = {최종 점수, cnt}, second = {마지막 제출 시간, tid}
        
        for (int tid = 0; tid < n; tid++)
        {
            int sum = 0;
            for (int j = 0; j < k; j++)
                sum += score[tid][j];
            result.push_back({{sum, -cnt[tid]}, {-idx[tid], tid}});
        }

        sort(result.begin(), result.end());

        for (int i = 0; i < n; i++)
            if (result[i].second.second == t)
                cout << n - i << '\n';
    }
}
