/** 시뮬레이션 11559 Puyo Puyo **/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

char origin_board[12][6];
char tmp_board[12][6];
bool visited[12][6];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;

bool chain(int a, int b)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    visited[a][b] = true;
    q.push({a, b});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        tmp_board[cur.first][cur.second] = '.';
        cnt++;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
                continue;
            if (origin_board[nx][ny] == '.')
                continue;
            if (visited[nx][ny] || origin_board[nx][ny] != origin_board[cur.first][cur.second])
                continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return cnt >= 4;
}

void update()
{
    // origin과 tmp 모두 아래로 끌어내릴건 끌어 내리면 됨. 새로운 배열을 만들여서 각 열별로 끌어내리기
    char res_board[12][6];
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 6; j++)
            res_board[i][j] = '.';

    for (int col = 0; col < 6; col++)
    {
        int cur = 11;
        for (int i = 11; i >= 0; i--)
        {
            if (origin_board[i][col] == '.')
                continue;
            res_board[cur--][col] = origin_board[i][col];
        }
    }

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            origin_board[i][j] = res_board[i][j];
            tmp_board[i][j] = res_board[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> origin_board[i][j];
            tmp_board[i][j] = origin_board[i][j];
        }
    }

    while (1)
    {
        // 연쇄 가능한 점 찾기, 찾았다면 chain함수가 true를 리턴할테고, chain 함수 내부에서 삭제 완료
        // chain함수가 false를 리턴한다면 해당 점은 연쇄 불가능하므로 다시 복구
        bool flag = false;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (origin_board[i][j] == '.')
                    continue;
                else if (chain(i, j))
                {
                    flag = true;
                    for (int i = 0; i < 12; i++)
                        for (int j = 0; j < 6; j++)
                            visited[i][j] = false;
                    for (int i = 0; i < 12; i++)
                        for (int j = 0; j < 6; j++)
                            origin_board[i][j] = tmp_board[i][j];
                    break;
                }
                else
                {
                    for (int i = 0; i < 12; i++)
                        for (int j = 0; j < 6; j++)
                            visited[i][j] = false;
                    for (int i = 0; i < 12; i++)
                        for (int j = 0; j < 6; j++)
                            tmp_board[i][j] = origin_board[i][j];
                }
            }
        }
        if (!flag)
            break;
        else
            ans++;
        // 맵 갱신
        update();
    }

    cout << ans << '\n';
}
