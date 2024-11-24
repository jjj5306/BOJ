/** BackTracking 13023 ABCDE **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n, m;
vector<int> edge[2010];
bool vis[2010];
bool ans = false;

bool dfs(int cur, int size)
{
    if (size >= 5)
    {
        // base condition
        return true;
    }

    for (auto next : edge[cur])
    {

        if (vis[next])
            continue;

        vis[next] = true;
        if (dfs(next, size + 1))
            return true;
        vis[next] = false;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        vis[i] = true;
        if (dfs(i, 1))
        {
            cout << "1\n";
            return 0;
        }
        fill(vis, vis + n, false);
    }
    cout << "0\n";
}
