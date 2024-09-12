/** MST 1368 물대기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
using namespace std;
int n;
int adj[400][400];
int water[400];
bool chk[400];
int cnt = 0, ans = 0;

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> water[i];
        pq.push({water[i], i, i});
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> adj[i][j];

    int cost_, a_, b_;
    tie(cost_, a_, b_) = pq.top();
    pq.pop();
    chk[a_] = true;
    ans += cost_;

    for (int nxt = 1; nxt <= n; nxt++)
    {
        if (nxt == a_)
            continue;
        pq.push({adj[a_][nxt], a_, nxt});
    }

    while (cnt < n - 1)
    {
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();
        if (chk[b])
            continue;

        chk[b] = true;
        ans += cost;
        cnt++;

        for (int nxt = 1; nxt <= n; nxt++)
        {
            if (!chk[nxt] && nxt != b)
                pq.push({adj[b][nxt], b, nxt});
        }
    }
    cout << ans;
}
