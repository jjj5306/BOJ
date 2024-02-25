/** DFS 20125 쿠키의 신체 측정 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N;
char board[1020][1020];
// dir 차례대로 왼 오 위 아래
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
pair<int, int> heart;

int dfs(int dir)
{
    int rt = 0;
    int nx = heart.first + dx[dir], ny = heart.second + dy[dir];

    while (board[nx][ny] == '*')
    {
        rt++;
        nx = nx + dx[dir];
        ny = ny + dy[dir];
    }

    return rt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    pair<int, int> head = {-1, -1};
    int left_arm, right_arm, back, left_leg, right_leg;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (head.first == -1 && board[i][j] == '*')
                head = {i, j};
        }
    }

    heart = {head.first + 1, head.second};
    pair<int, int> ans_heart = heart;

    // 왼팔 심장에서 왼쪽으로 DFS
    left_arm = dfs(0);

    // 오른팔 심장에서 오른쪽으로 DFS
    right_arm = dfs(1);

    // 허리
    back = dfs(3);

    // 왼쪽 다리를 위해 heart 허리 왼쪽 아래로 갱신
    heart = {heart.first + back, heart.second - 1};
    left_leg = dfs(3);

    // 오른쪽 다리를 위해 heart 오른쪽으로 두칸 옮기기
    heart.second += 2;
    right_leg = dfs(3);

    cout << ans_heart.first + 1 << ' ' << ans_heart.second + 1 << '\n';
    cout << left_arm << ' ' << right_arm << ' ' << back << ' ' << left_leg << ' ' << right_leg;
}
