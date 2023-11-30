/** 시뮬레이션 3190 뱀 **/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

int n, k, l, cur_sec = 0, cur_dir = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[102][102];
deque<pair<int, int>> snake;
vector<pair<int, char>> dir;

bool simulate()
{
    // cur_dir 방향으로 1초 진행
    // 방향에 따라 머리를 한 칸 옮긴다. 머리는 snake.end에 있다.
    // 옮긴 곳이 벽이거나 뱀이면 종료
    int nx = snake.back().first + dx[cur_dir];
    int ny = snake.back().second + dy[cur_dir];
    cur_sec++;
    if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 1)
        return false;

    // 옮긴 곳이 사과던 아니던 공통적으로 수행
    snake.push_back({nx, ny});

    // 옮긴 곳이 사과면 그냥 종료
    if (board[nx][ny] == 2)
    {
        board[nx][ny] = 1;
        return true;
    }

    // 옮긴 곳이 사과가 아니면 꼬리 하나 삭제. 꼬리는 snake.front에 있다.
    board[nx][ny] = 1;
    board[snake.front().first][snake.front().second] = 0;
    snake.pop_front();
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        // 사과의 위치를 2로 저장
        board[x - 1][y - 1] = 2;
    }

    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int sec;
        char str;
        cin >> sec >> str;
        // 방향 전환 정보 저장
        dir.push_back({sec, str});
    }

    // 뱀 위치를 1로 저장
    board[0][0] = 1;
    snake.push_back({0, 0});
    int dir_index = 0;
    // cur_sec == dir[dir_index].first 라면 방향전환 해주기

    while (1)
    {
        // 방향 전환해야하는지 확인
        if (cur_sec == dir[dir_index].first)
        {
            if (dir[dir_index].second == 'L')
            {
                cur_dir = (cur_dir + 3) % 4;
                dir_index++;
            }
            else
            {
                // 오른쪽으로 90도 회전
                cur_dir = (cur_dir + 1) % 4;
                dir_index++;
            }
        }
        // 1초 진행
        if (!simulate())
        {
            cout << cur_sec << '\n';
            break;
        }
    }
}
