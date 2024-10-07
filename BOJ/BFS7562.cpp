/** BFS 7562 나이트의 이동 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int t;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        int l, destX, destY, curX, curY;
        int board[305][305];
        int dist[305][305]; // 아직 방문하지 않으면 -1, 방문 했다면 해당 칸을 방문하는데까지 걸린 이동 수

        cin >> l;

        for (int i = 0; i < l; i++)
        {
            fill(board[i], board[i] + l, 0);
            fill(dist[i], dist[i] + l, -1);
        }

        cin >> curX >> curY >> destX >> destY;

        // BFS
        dist[curX][curY] = 0;
        queue<pair<int, int>> q;
        q.push({curX, curY});

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            if (cur.first == destX && cur.second == destY)
                break;

            for (int dir = 0; dir < 8; dir++)
            {
                int nX = cur.first + dx[dir];
                int nY = cur.second + dy[dir];

                if (nX < 0 || nX >= l || nY < 0 || nY >= l)
                    continue;
                if (dist[nX][nY] != -1)
                    continue;

                dist[nX][nY] = dist[cur.first][cur.second] + 1;
                q.push({nX, nY});
            }
        }
        cout << dist[destX][destY] << '\n';
    }
}
