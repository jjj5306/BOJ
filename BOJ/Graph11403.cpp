/** 그래프 11403 경로 찾기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;
int n;
int arr[102][102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int start = 0; start < n; start++)
    {
        for (int target = 0; target < n; target++)
        {
            bool visited[102] = {
                false,
            };
            bool flag = false;
            stack<int> s;
            s.push(start);

            while (!s.empty())
            {
                int cur = s.top();
                s.pop();

                if (visited[cur])
                    continue;
                if (cur != target)
                    visited[cur] = true;

                for (int next = 0; next < n; next++)
                {
                    if (arr[cur][next] == 1 && !visited[next])
                    {
                        if (next == target)
                        {
                            cout << "1 ";
                            flag = true;
                            break;
                        }
                        else
                        {
                            s.push(next);
                        }
                    }
                }
                if (flag)
                    break;
            }
            if (!flag)
                cout << "0 ";
        }
        cout << '\n';
    }
}
