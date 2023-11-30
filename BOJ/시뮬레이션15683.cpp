/** 시뮬레이션 15683 감시 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int space[10][10];
bool visited[10][10];
int cctv = 0;
int min_res = 1000;

// 왼쪽 방향 감시 표시
void checkLeftward(int x, int y)
{
    for (int ny = y - 1; ny >= 0; ny--)
    {
        if (space[x][ny] == 6)
            break;
        if (space[x][ny] >= 1 && space[x][ny] <= 5)
            continue;
        space[x][ny] = -1;
    }
}

// 오른쪽 방향 감시 표시
void checkRightward(int x, int y)
{
    for (int ny = y + 1; ny < m; ny++)
    {
        if (space[x][ny] == 6)
            break;
        if (space[x][ny] >= 1 && space[x][ny] <= 5)
            continue;
        space[x][ny] = -1;
    }
}

// 위쪽 방향 감시 표시
void checkUpward(int x, int y)
{
    for (int nx = x - 1; nx >= 0; nx--)
    {
        if (space[nx][y] == 6)
            break;
        if (space[nx][y] >= 1 && space[nx][y] <= 5)
            continue;
        space[nx][y] = -1;
    }
}

// 아래쪽 방향 감시 표시
void checkDownward(int x, int y)
{
    for (int nx = x + 1; nx < n; nx++)
    {
        if (space[nx][y] == 6)
            break;
        if (space[nx][y] >= 1 && space[nx][y] <= 5)
            continue;
        space[nx][y] = -1;
    }
}

void turn1(int dir, int a, int b)
{
    //(a, b)의 1번 cctv를 dir 방향으로 켠다. dir은 상하좌우 차례로 0 1 2 3 이다.
    switch (dir)
    {
    case 0:
        // 윗 방향으로 켜기
        checkUpward(a, b);
        break;
    case 1:
        // 아랫 방향
        checkDownward(a, b);
        break;
    case 2:
        // 왼쪽
        checkLeftward(a, b);
        break;
    case 3:
        // 오른쪽
        checkRightward(a, b);
        break;
    }
}

void turn2(int dir, int a, int b)
{
    //(a, b)의 2번 cctv를 dir 방향으로 켠다. dir은 상하/좌우 차례로 0, 1이다.
    switch (dir)
    {
    case 0:
        // 상하
        checkUpward(a, b);
        checkDownward(a, b);
        break;
    case 1:
        // 좌우
        checkLeftward(a, b);
        checkRightward(a, b);
        break;
    }
}

void turn3(int dir, int a, int b)
{
    //(a, b)의 3번 cctv를 dir 방향으로 켠다. dir은 상하좌우 차례로 0 1 2 3 이다.
    switch (dir)
    {
    case 0:
        // 상 우
        checkUpward(a, b);
        checkRightward(a, b);
        break;
    case 1:
        // 하 좌
        checkDownward(a, b);
        checkLeftward(a, b);
        break;
    case 2:
        // 좌 상
        checkLeftward(a, b);
        checkUpward(a, b);
        break;
    case 3:
        // 우 하
        checkRightward(a, b);
        checkDownward(a, b);
        break;
    }
}

void turn4(int dir, int a, int b)
{
    //(a, b)의 4번 cctv를 dir을 제외한 방향으로 켠다. dir은 상하좌우 차례로 0 1 2 3 이다.
    switch (dir)
    {
    case 0:
        // 상 제외
        checkDownward(a, b);
        checkLeftward(a, b);
        checkRightward(a, b);
        break;
    case 1:
        // 하 제외
        checkUpward(a, b);
        checkLeftward(a, b);
        checkRightward(a, b);
        break;
    case 2:
        // 좌 제외
        checkDownward(a, b);
        checkUpward(a, b);
        checkRightward(a, b);
        break;
    case 3:
        // 우 제외
        checkDownward(a, b);
        checkLeftward(a, b);
        checkUpward(a, b);
        break;
    }
}

void turn5(int a, int b)
{
    //(a, b)의 5번 cctv를 켠다.
    checkUpward(a, b);
    checkDownward(a, b);
    checkLeftward(a, b);
    checkRightward(a, b);
}

void func(int a, int b, int cnt)
{
    // a, b의 cctv를 켠다. 현재 cnt만큼의 cctv를 켰다.
    if (cnt == cctv)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (space[i][j] == 0)
                    res++;
        if (res < min_res)
            min_res = res;
       }

    // cctv를 끈 후 space를 원상복구하기 위해 임시로 저장
    int tmp_arr[10][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tmp_arr[i][j] = space[i][j];

    visited[a][b] = true;

    int nX = -1, nY = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (space[i][j] >= 1 && space[i][j] <= 5 && visited[i][j] == 0)
            {
                nX = i;
                nY = j;
                break;
            }
        if (nX != -1)
            break;
    }

    switch (space[a][b])
    {
    case 1:
        // (a, b)의 cctv를 켠다.
        // func(nX, nY, cnt+1) 호출 이후 다시 space를 복구시킨다. 모든 방향에 대해 반복한다.
        for (int k = 0; k < 4; k++)
        {
            turn1(k, a, b);
            func(nX, nY, cnt + 1);
            visited[nX][nY] = false;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    space[i][j] = tmp_arr[i][j];
        }
        break;
    case 2:
        for (int k = 0; k < 2; k++)
        {
            turn2(k, a, b);
            func(nX, nY, cnt + 1);
            visited[nX][nY] = false;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    space[i][j] = tmp_arr[i][j];
        }
        break;
    case 3:
        for (int k = 0; k < 4; k++)
        {
            turn3(k, a, b);
            func(nX, nY, cnt + 1);
            visited[nX][nY] = false;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    space[i][j] = tmp_arr[i][j];
        }
        break;
    case 4:
        for (int k = 0; k < 4; k++)
        {
            turn4(k, a, b);
            func(nX, nY, cnt + 1);
            visited[nX][nY] = false;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    space[i][j] = tmp_arr[i][j];
        }
        break;
    case 5:
        turn5(a, b);
        func(nX, nY, cnt + 1);
        visited[nX][nY] = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                space[i][j] = tmp_arr[i][j];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> space[i][j];
            if (space[i][j] != 0 && space[i][j] != 6)
                cctv++;
        }

    int x = -1, y = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (space[i][j] >= 1 && space[i][j] <= 5)
            {
                x = i;
                y = j;
                break;
            }
        }
        if (x != -1)
            break;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;
    func(x, y, 0);

    cout << min_res;
}
