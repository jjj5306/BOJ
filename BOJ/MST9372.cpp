/** MST 9327 상근이의 여행 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> p(1010, -1);

int find(int x)
{
    // x가 대표 노드인 경우
    if (p[x] < 0)
        return x;
    // 경로 압축
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return 0;

    p[v] = u;

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {

        int v, e;
        cin >> v >> e;
        fill(p.begin(), p.end(), -1);
        vector<pair<int, int>> edge;

        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            edge.push_back({a, b});
        }

        int cnt = 0, ans = 0;
        for (int i = 0; i < e; i++)
        {
            int a, b;
            a = edge[i].first;
            b = edge[i].second;
            if (!is_diff_group(a, b))
                continue;
            ans += 1;
            cnt++;
            if (cnt == v - 1)
                break;
        }

        cout << ans << '\n';
    }
}
