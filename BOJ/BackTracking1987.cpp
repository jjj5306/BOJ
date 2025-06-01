/* 백트래킹 1987 알파벳 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int r, c;
int board[25][25];
bool vis_alpha[30];
bool vis[25][25];
int ans = 0, temp_sum = 1;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

// func(i, j) : i, j에서 이동
void func(int i, int j)
{

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        // nx, ny로 이동할 수 있는지 체크
        if (nx >= r || nx < 0 || ny >= c || ny < 0 || vis_alpha[board[nx][ny]] || vis[nx][ny])
        {
            // cout << i << ' ' << j << ' ' << nx << ' ' << ny << ' ' << temp_sum << '\n';
            ans = max(ans, temp_sum);
            continue;
        }
        // nx, ny로 이동
        vis_alpha[board[nx][ny]] = true;
        vis[nx][ny] = true;
        temp_sum++;
        func(nx, ny);
        // nx, ny 미방문 처리
        vis_alpha[board[nx][ny]] = false;
        vis[nx][ny] = false;
        temp_sum--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    cin.ignore();
    for (int i = 0; i < r; i++)
    {
        string s;
        getline(cin, s);
        for (int j = 0; j < c; j++)
            board[i][j] = s[j] - 'A';
    }

    // 0, 0 방문 처리
    vis[0][0] = true;
    vis_alpha[board[0][0]] = true;

    func(0, 0);

    cout << ans;
}