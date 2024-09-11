int v, e;
vector<pair<int, int>> adj[10005];
bool chk[10005];
int cnt = 0;

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

chk[1] = true;
for (auto nxt : adj[1])
    pq.push({nxt.first, 1, nxt.second});

while (cnt < v - 1)
{
    int cost, a, b;
    tie(cost, a, b) = pq.top();
    pq.pop();
    if (chk[b])
        continue;
    cout << cost << ' ' << a << ' ' << b << '\n';
    chk[b] = 1;
    cnt++;
    for (auto nxt : adj[b])
    {
        if (!chk[nxt.second])
            pq.push({nxt.first, b, nxt.second});
    }
}