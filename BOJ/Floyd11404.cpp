/** 최단거리 11404 플로이드 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int dist[105][105];
const int INF = 0x3f3f3f3f;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        fill(dist[i], dist[i] + n + 1, INF);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    // k번째 원소가 중간에 거치는 원소
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "0 ";
            else
                cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}
