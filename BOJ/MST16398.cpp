/** MST 16398 행성 연결 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

long long n;
long long adj[1050][1050];
bool chk[1050];
long long cnt = 0, ans = 0;

priority_queue<tuple<long long, long long, long long>, vector<tuple<long long, long long, long long>>, greater<tuple<long long, long long, long long>>> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (long long i = 0; i < n; i++)
        for (long long j = 0; j < n; j++)
            cin >> adj[i][j];

    for (long long i = 1; i < n; i++)
    {
        pq.push({adj[0][i], 0, i});
    }
    chk[0] = true;

    while (cnt < n - 1)
    {
        long long cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();
        if (chk[b])
            continue;

        chk[b] = true;
        ans += cost;
        cnt++;

        for (long long nxt = 0; nxt < n; nxt++)
        {
            if (!chk[nxt])
                pq.push({adj[b][nxt], b, nxt});
        }
    }
    cout << ans;
}
