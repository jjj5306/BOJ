/** 시뮬레이션 20006 랭킹전 대기열 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int p, m;
pair<int, string> player[600];
vector<vector<pair<int, string>>> room;

bool cmp(pair<int, string> &a, pair<int, string> &b)
{
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> p >> m;
    for (int i = 0; i < p; i++)
        cin >> player[i].first >> player[i].second;

    room.resize(500);
    room[0].push_back(player[0]);
    for (int i = 1; i < p; i++)
    {
        for (int j = 0; j < room.size(); j++)
        {
            if (room[j].empty())
            {
                room[j].push_back(player[i]);
                break;
            }
            else if ((room[j].size() < m) &&
                     (room[j][0].first <= player[i].first + 10 &&
                      room[j][0].first >= player[i].first - 10))
            {
                room[j].push_back(player[i]);
                break;
            }
        }
    }

    for (int j = 0; j < room.size(); j++)
    {
        if (room[j].empty())
            break;
        sort(room[j].begin(), room[j].end(), cmp);
    }

    for (int j = 0; j < room.size(); j++)
    {
        if (room[j].empty())
            break;
        if (room[j].size() == m)
            cout << "Started!\n";
        else
            cout << "Waiting!\n";
        for (int k = 0; k < room[j].size(); k++)
            cout << room[j][k].first << ' ' << room[j][k].second << '\n';
    }
}
