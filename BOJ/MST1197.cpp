/** MST 1197 최소 스패닝 트리 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;
int v, e;
vector<int> p(10100, -1);
tuple<int, int, int> edge[100005];

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

    // 두 집합의 크기가 같은 경우 u에 통일하기 위해 u의 사이즈를 더 늘림(--가 더 늘리는 것인 이유는 더 깊어진다는 의미)
    if (p[u] == p[v])
        p[u]--;
    // u가 더 큰 경우 v의 부모를 u로 만듬.
    if (p[u] < p[v])
        p[v] = u;
    else
        p[u] = v;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }

    sort(edge, edge + e);
    int cnt = 0, ans = 0;
    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if (!is_diff_group(a, b))
            continue;
        ans += cost;
        cnt++;
        if (cnt == v - 1)
            break;
    }
    cout << ans;
}
