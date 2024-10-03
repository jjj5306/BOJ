/** MST 1647 도시 분할 계획 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int n, m;
vector<int> p(100010, -1);
tuple<int, int, int> edge[1000010];

int find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v)
{
    u = find(u);
    v = find(v);
    // 같은 그룹
    if (u == v)
        return false;

    if (p[u] == p[v])
        p[u]--;
    // u가 더 깊은 경우(p가 작아야 함.)
    if (p[u] < p[v])
        p[v] = u;
    else
        p[u] = v;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }

    sort(edge, edge + m);
    int cnt = 0, ans = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v, cost;
        tie(cost, u, v) = edge[i];
        if (!is_diff_group(u, v))
            continue;
        cnt++;
        if (cnt == n - 1)
        {
            // 마지막 iteration
            break;
        }
        ans += cost;
    }

    cout << ans;
}
