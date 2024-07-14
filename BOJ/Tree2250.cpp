/** Tree 2250 트리의 높이와 너비 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, root = 1, col_idx = 1, depth_max_idx = 0;
// adj[i][0] : left child, adj[i][1] : right child
vector<int> adj[10002];
vector<int> depth[10002];
int node_col[10002];

void inorder(int cur, int d)
{
    if (cur == -1)
        return;
    inorder(adj[cur][0], d + 1);

    node_col[cur] = col_idx++;

    depth[d].push_back(cur);
    depth_max_idx = max(depth_max_idx, d);

    inorder(adj[cur][1], d + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<bool> isRoot(n + 1, true);

    for (int i = 1; i <= n; i++)
    {
        int cur, l, r;
        cin >> cur >> l >> r;
        adj[cur].push_back(l);
        adj[cur].push_back(r);

        if (l != -1)
            isRoot[l] = false;
        if (r != -1)
            isRoot[r] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        if (isRoot[i])
        {
            root = i;
            break;
        }
    }

    inorder(root, 1);

    int ans = 0, level = 0;
    for (int i = 1; i <= depth_max_idx; i++)
    {
        int min_col = n, max_col = 0;
        for (auto x : depth[i])
        {
            min_col = min(min_col, node_col[x]);
            max_col = max(max_col, node_col[x]);
        }
        if (ans < max_col - min_col + 1)
        {
            ans = max_col - min_col + 1;
            level = i;
        }
    }
    cout << level << ' ' << ans;
}
