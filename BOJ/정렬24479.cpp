/** 정렬 24479 깊이 우선 탐색 1 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 정점의 수 N, 간선의 수 M, 정답을 마킹할 때 쓸 cnt 변수 선언
int cnt = 2, N, M;
// 정답 및 그래프 벡터 구현
vector<int> res(100001, 0), G[100001];
// 방문 여부 확인 벡터 구현
vector<bool> visited(100001, false);

void dfs(int R)
{
    visited[R] = true;
    for (int i = 0; i < G[R].size(); i++)
    {
        // 정점 R의 i번째 간선이 방문하지 않았다면 방문.
        if (!visited[G[R][i]])
        {
            visited[G[R][i]] = true;
            res[G[R][i]] = cnt++;
            dfs(G[R][i]);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M, R;
    cin >> N >> M >> R;

    // 그래프 구현 후 간선 오름차순으로 정렬
    while (M--)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i < N + 1; i++)
        sort(G[i].begin(), G[i].end());

    res[R] = 1;

    // dfs 수행
    dfs(R);

    for (int i = 1; i < N + 1; i++)
        cout << res[i] << "\n";
}