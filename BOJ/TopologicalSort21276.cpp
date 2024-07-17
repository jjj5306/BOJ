/** 위상 정렬 21276 계보 복원가 호석 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;

int n, m;

string name[1002];
// 고유번호에 해당하는 name 찾기 : name string 배열 사용

int degree[1050];
vector<int> adj[1050];

map<string, int> list;
// name에 해당하는 고유번호 찾기 map 사용

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> name[i];

    sort(name + 1, name + n + 1);

    for (int i = 1; i <= n; i++)
        list[name[i]] = i;

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string a, b;
        cin >> a >> b;

        adj[list[b]].push_back(list[a]);
        degree[list[a]]++;
    }

    vector<int> k;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
        {
            k.push_back(i);
        }
    }

    cout << k.size() << '\n';
    for (auto x : k)
        cout << name[x] << ' ';
    cout << '\n';

    // 트리에 존재하는 모든 사람에 대해 직계 자식을 출력하면 되는데, 직계 자식과 indegree 차이는 1이다.
    // 또, 직계 자식들 또한 사전순으로 출력해야하기에 1번부터 adj를 정렬해야 한다.
    vector<int> child[1050];
    for (int i = 1; i <= n; i++)
    {
        // i번 노드에 대해 직계 자식을 구하기
        for (int child_index : adj[i])
        {
            if (degree[child_index] == degree[i] + 1)
                child[i].push_back(child_index);
        }
        sort(child[i].begin(), child[i].end());
    }

    for (int i = 1; i <= n; i++)
    {
        cout << name[i] << ' ' << child[i].size() << ' ';
        for (int x : child[i])
            cout << name[x] << ' ';
        cout << '\n';
    }
}
