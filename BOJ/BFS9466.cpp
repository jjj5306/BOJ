/** BFS 9466 텀 프로젝트 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int stu[100005];
int visited[100005]; //-1은 사이클 안, 0은 방문한 적 없음.
int n;

void bfs(int start)
{
    int cur = start;
    while (1)
    {
        // cur 방문
        visited[cur] = start;
        // cur 다음 단계로
        cur = stu[cur];
        if (visited[cur] == start)
        {
            // 이번 start에서 시작된 방문에서 방문된 곳을 들리면 사이클을 찾은 것
            while (visited[cur] != -1)
            {
                visited[cur] = -1;
                cur = stu[cur];
            }
            return;
        }
        // 이번 방문이 아닌 지난 방문에서 방문된 곳을 들리면 지금까지 들린곳 전부 사이클이 아니다.
        else if (visited[cur] != 0)
            return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i < n + 1; i++)
        {
            cin >> stu[i];
            visited[i] = 0;
        }

        for (int i = 1; i < n + 1; i++)
        {
            if (visited[i] == 0)
                bfs(i);
        }

        int res = 0;

        for (int i = 1; i < n + 1; i++)
        {
            if (visited[i] != -1)
                res++;
        }

        cout << res << '\n';
    }
}
