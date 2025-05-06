/** 20166 문자열 지옥에 빠진 호석 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int n, m, k;
string board[10];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
unordered_map<string, int> cnt;

void dfs(int i, int j, string s)
{
    // board[i][j]를 시작점으로 dfs 했을 때 결과가 s
    cnt[s]++;
    if (s.size() == 5)
        return;

    for (int dir = 0; dir < 8; dir++)
    {
        int nx = (i + dx[dir] + n) % n;
        int ny = (j + dy[dir] + m) % m;
        dfs(nx, ny, s + board[nx][ny]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> board[i];

    // 모든 점을 시작으로 길이 5만큼의 dfs를 해서 나올 수 있는 모든 문자열의 경우의 수 체크
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dfs(i, j, string(1, board[i][j]));
    while (k--)
    {
        string s;
        cin >> s;
        cout << cnt[s] << '\n';
    }
}
