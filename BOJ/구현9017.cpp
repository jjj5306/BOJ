/** 구현 9017 크로스 컨트리 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m = 0, team[1050];
        vector<int> valid_team(250, 0);
        vector<pair<int, int>> team_score(250, {0, 0}); // 팀 점수와 몇 명의 점수를 합했는지 저장
        vector<int> fifth_personal_score(250, 0);
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> team[i];
            valid_team[team[i]]++;
            if (m < team[i])
                m = team[i];
        }

        // valid_team[i]가 6인 팀은 팀 점수를 받을 수 있다.
        int cur_score = 1;
        for (int i = 0; i < n; i++)
        {
            if (valid_team[team[i]] == 6)
            {
                if (team_score[team[i]].second < 4)
                    // 유효한 팀이고 4명 이하의 합을 구했으면 팀 점수 계산
                    team_score[team[i]] = {team_score[team[i]].first + cur_score++, team_score[team[i]].second + 1};
                else if (fifth_personal_score[team[i]] == 0)
                    // 5번째 선수라면 기록
                    fifth_personal_score[team[i]] = cur_score++;
                else
                    // 6번째 선수라면 기록은 하지 않음
                    cur_score++;
            }
        }

        // 순위 계산, 팀 점수가 가장 낮은 팀들 구하기
        int min_idx = 0;
        valid_team[0] = 6;
        team_score[0] = {99999, 4};
        fifth_personal_score[0] = 99999;

        for (int i = 1; i <= m; i++)
        {
            if (valid_team[i] == 6)
            {
                if (team_score[min_idx].first > team_score[i].first)
                    min_idx = i;
                else if (team_score[min_idx].first == team_score[i].first && fifth_personal_score[min_idx] > fifth_personal_score[i])
                    min_idx = i;
            }
        }

        cout << min_idx << '\n';
    }
}
