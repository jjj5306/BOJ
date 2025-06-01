/* MST 6497 전력난 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

tuple<int, int, int> edge[200005];
vector<int> p(200005, -1);
int n, m;

// find
int find(int u)
{
    if (p[u] < 0)
        return u;
    return p[u] = find(p[u]);
}

// union
bool is_diff(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;

    if (p[u] == p[v])
        p[u]--;
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

    while (1)
    {
        cin >> m >> n;
        if (m == 0 && n == 0)
            return 0;

        int ans = 0, cnt = 0, total = 0;
        fill(p.begin(), p.end(), -1);

        for (int i = 0; i < n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edge[i] = {c, a, b};
            total += c;
        }

        sort(edge, edge + n);

        // MST 구하기
        for (int i = 0; i < n; i++)
        {
            int u, v, cost;
            tie(cost, u, v) = edge[i];
            if (!is_diff(u, v))
                continue;
            ans += cost;
            cnt++;
            if (cnt == m - 1)
                break;
        }
        cout << total - ans << '\n';
    }
}