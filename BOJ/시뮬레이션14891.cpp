/** 시뮬레이션 14891 톱니바퀴 **/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

string gear[4];
int k;

void rotate(int idx, int dir)
{
    // idx번 기어를 회전시키면 되는데, dir이 1이면 시계 -1이면 반시계
    char new_gear[8];
    if (dir == 1)
        // 시계
        for (int i = 0; i < 8; i++)
            new_gear[i] = gear[idx][(i + 7) % 8];
    else
        // 반시계
        for (int i = 0; i < 8; i++)
            new_gear[i] = gear[idx][(i + 1) % 8];

    for (int i = 0; i < 8; i++)
        gear[idx][i] = new_gear[i];
}

void check_gear(int idx, int dir)
{
    // idx번 기어를 dir방향으로 회전시키고 양 옆 확인
    bool visited[4] = {
        false,
    };
    queue<pair<int, int>> q;

    q.push({idx, dir});
    visited[idx] = true;

    while (!q.empty())
    {
        int cur_idx = q.front().first;
        int cur_dir = q.front().second;
        q.pop();
        //  cur_idx를 cur_dir 방향으로 회전시키고 양 옆을 확인하자.
        //  회전시키기 전에 양 옆을 확인해야 한다.
        int right_idx = cur_idx + 1;
        if (right_idx < 4 && !visited[right_idx])
        {
            // 오른쪽 기어가 있고, 방문하지 않았다면 체크
            if (gear[cur_idx][2] != gear[right_idx][6])
            {
                q.push({right_idx, cur_dir * -1});
                visited[right_idx] = true;
            }
        }
        int left_idx = cur_idx - 1;
        if (left_idx >= 0 && !visited[left_idx])
        {
            // 왼쪽 기어가 있고, 방문하지 않았다면 체크
            if (gear[cur_idx][6] != gear[left_idx][2])
            {
                q.push({left_idx, cur_dir * -1});
                visited[left_idx] = true;
            }
        }
        rotate(cur_idx, cur_dir);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++)
        cin >> gear[i];

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int gear_index, dir;
        cin >> gear_index >> dir;
        // dir이 1이면 시계 -1이면 반시계 회전
        check_gear(gear_index - 1, dir);
    }

    int ans = 0;
    ans += gear[0][0] - '0';
    ans += (gear[1][0] - '0') * 2;
    ans += (gear[2][0] - '0') * 4;
    ans += (gear[3][0] - '0') * 8;
    cout << ans << '\n';
}
