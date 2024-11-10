/** MST 1774 우주신과의 교감 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <cmath>
using namespace std;
int n, m, cnt = 0;
int p[1002];
pair<int, int> coord[1002];
vector<tuple<long long, int, int>> edge; // 점 사이의 거리는 21억인 넘을 수 있음.

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

    cin >> n >> m;
    fill(p, p + n + 2, -1);
    for (int i = 1; i <= n; i++)
    {
        // n개의 줄에 좌표 입력
        int a, b;
        cin >> a >> b;
        coord[i] = {a, b};
    }

    for (int i = 0; i < m; i++)
    {
        // m개의 줄에 연결된 두 점 입력
        int a, b;
        cin >> a >> b;
        if (is_diff_group(a, b))
            cnt++;
    }

    // 모든 점이 서로 연결되어있다고 생각하고 거리를 구함.
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            // i번 점과 j번 점 거리 계산
            int dx = coord[i].first - coord[j].first;
            int dy = coord[i].second - coord[j].second;
            long long len = ((long long)dx) * dx + ((long long)dy) * dy;
            edge.push_back({len, i, j});
        }
    }

    sort(edge.begin(), edge.end());

    double ans = 0.0;
    for (auto cur : edge)
    {
        long long len;
        int x, y;
        tie(len, x, y) = cur;

        if (is_diff_group(x, y) == 0)
            continue;
        ans += sqrt(len);
        cnt++;
        if (cnt == n - 1)
            break;
    }

    cout << fixed;
    cout.precision(2);
    cout << ans << '\n';
}
