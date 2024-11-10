/** MST 10423 전기가 부족해 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int n, m, k, cnt = 0;
vector<int> p(1002, -1);
vector<int> bal;
tuple<int, int, int> edge[100005];

int find(int x)
{
    if (p[x] < 0)
        return x;
    return find(p[x]);
}

int merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return 0;

    if (p[u] == p[v])
        p[u]--;
    if (p[u] < p[v])
        // v의 부모를 u로
        p[v] = u;
    else
        p[u] = v;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int b;
        cin >> b;
        bal.push_back(b);
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = {w, u, v};
    }

    // 발전소가 있는 도시는 같은 그룹으로 묶음
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (merge(bal[i], bal[j]))
                cnt++;
        }
    }

    sort(edge, edge + m);

    int ans = 0;
    for (auto cur : edge)
    {
        int w, u, v;
        tie(w, u, v) = cur;
        if (merge(u, v) == 0)
            continue;
        cnt++;
        ans += w;
        if (cnt == n - 1)
            break;
    }

    cout << ans << '\n';
}
