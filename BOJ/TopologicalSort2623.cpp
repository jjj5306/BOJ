/** 위상정렬 2623 음악프로그램 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n, m;
int degree[1050];
vector<int> child[1050];
queue<int> q;
vector<int> res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (m--)
    {
        int k;
        cin >> k;
        vector<int> temp;
        while (k--)
        {
            int node;
            cin >> node;
            temp.push_back(node);
        }
        for (int i = 0; i < temp.size() - 1; i++)
        {
            child[temp[i]].push_back(temp[i + 1]);
            degree[temp[i + 1]]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for (int next : child[cur])
        {
            if (--degree[next] == 0)
                q.push(next);
        }
    }
    if (res.size() != n)
        cout << "0";
    else
    {
        for (auto x : res)
            cout << x << '\n';
    }
}
