/** MST 13418 학교 탐방하기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;
long long v, e;
vector<long long> p(5000000, -1);
tuple<long long, long long, long long> edge[5000000];

long long find(long long x)
{
    // x가 대표 노드인 경우
    if (p[x] < 0)
        return x;
    // 경로 압축
    return p[x] = find(p[x]);
}

bool is_diff_group(long long u, long long v)
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
    e++;
    for (long long i = 0; i < e; i++)
    {
        long long a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {!cost, a, b};
    }

    // 최적의 경로 계산
    long long cnt = 0, ans = 0;

    sort(edge, edge + e);

    for (long long i = 0; i < e; i++)
    {
        long long a, b, cost;
        tie(cost, a, b) = edge[i];
        if (!is_diff_group(a, b))
            continue;
        ans += cost;
        cnt++;
        if (cnt == v)
            break;
    }
    long long bestAns = ans * ans;

    // 최악의 경로 계산
    cnt = ans = 0;
    fill(p.begin(), p.end(), -1);
    reverse(edge, edge + e);
    for (long long i = 0; i < e; i++)
    {
        long long a, b, cost;
        tie(cost, a, b) = edge[i];
        if (!is_diff_group(a, b))
            continue;
        ans += cost;
        cnt++;
        if (cnt == v)
            break;
    }

    cout << ans * ans - bestAns << '\n';
}
