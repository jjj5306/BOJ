/** 그래프 1043 거짓말 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int n, m, k, start, ans = 0;
vector<int> g[500];
vector<int> party[500];
vector<int> input;
bool visited[500];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> k;
    if (k == 0)
    {
        cout << m << '\n';
        return 0;
    }
    vector<int> temp;
    while (k--)
    {
        int p;
        cin >> p;
        temp.push_back(p);
    }

    start = temp[0];
    // temp에 있는 사람들 서로 연결
    for (int i = 0; i < temp.size() - 1; i++)
    {
        g[temp[i]].push_back(temp[i + 1]);
        g[temp[i + 1]].push_back(temp[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        while (t--)
        {
            int p;
            cin >> p;
            party[i].push_back(p);
        }

        // party[i]에 있는 사람들 서로 연결
        for (int j = 0; j < party[i].size() - 1; j++)
        {
            g[party[i][j]].push_back(party[i][j + 1]);
            g[party[i][j + 1]].push_back(party[i][j]);
        }
    }

    // start부터 bfs
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (visited[cur])
            continue;

        visited[cur] = true;

        for (auto next : g[cur])
        {
            q.push(next);
        }
    }

    for (int i = 0; i < m; i++)
    {
        bool flag = true;
        for (int j = 0; j < party[i].size(); j++)
        {
            if (visited[party[i][j]])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            ans++;
    }
    cout << ans << '\n';
}
