/** 트리 14267 회사 문화 1 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int p[100100];
int score[100100];
vector<int> adj[100100];
int n, m;

void dfs(int cur)
{
    score[cur] += score[p[cur]];
    for (auto next : adj[cur])
        dfs(next);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        int k, w;
        cin >> k >> w;
        score[k] += w;
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
        cout << score[i] << ' ';
}
