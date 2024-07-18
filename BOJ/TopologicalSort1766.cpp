/** 위상 정렬 1766 문제집 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int n, m;
int degree[32100];
vector<int> child[32100];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        child[a].push_back(b);
        degree[b]++;
    }

    // 위상 정렬을 수행하는데, 우선순위는 번호가 작은 것.
    // indegree가 0인 노드를 큐에 넣을 때 정렬을 해서 번호가 가장 작은 노드부터 넣거나 우선순위 큐를 사용하면 된다.
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
            pq.push(i);
    }

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        cout << cur << ' ';

        for (auto next : child[cur])
        {
            if (--degree[next] == 0)
                pq.push(next);
        }
    }
}
