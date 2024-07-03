/** 트리 15681 트리와 쿼리 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, r, q;
vector<int> adj[100500];
int p[100500];
int size_[100500];

void countSubtreeNodes(int cur)
{
    // end node의 size_는 1
    size_[cur] = 1;
    for (auto next : adj[cur])
    {
        if (p[cur] == next)
            continue;
        p[next] = cur;
        countSubtreeNodes(next);
        size_[cur] += size_[next];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    countSubtreeNodes(r);

    while (q--)
    {
        int root;
        cin >> root;
        cout << size_[root] << '\n';
    }
}
