/** 시뮬레이션 18808 스티커 붙이기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m, k;
int labtop[50][50];
int r, c;
int sticker[12][12];

void rotate()
{
    int tmp[12][12];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            tmp[i][j] = sticker[i][j];

    int tmp_r = r;
    r = c;
    c = tmp_r;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            sticker[i][j] = tmp[c - 1 - j][i];
}

bool paste(int x, int y)
{
    // labtop(x, y)에 현재 스티커(0, 0)을 붙일 수 있는지 체크
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (sticker[i][j] == 1 && labtop[x + i][y + j] == 1)
                return false;

    // 붙일 수 있다고 판단. 바로 붙이기
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (sticker[i][j] == 1)
                labtop[x + i][y + j] = 1;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    while (k--)
    {
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> sticker[i][j];

        for (int dir = 0; dir < 4; dir++)
        {
            bool flag = false;
            // 붙일 수 있는 칸에 붙여보기. 못붙인다면 방향 회전
            for (int i = 0; i <= n - r; i++)
            {
                if (flag)
                    break;
                for (int j = 0; j <= m - c; j++)
                {
                    if (paste(i, j))
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
                break;
            rotate();
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (labtop[i][j])
                cnt++;
    cout << cnt << '\n';
}
