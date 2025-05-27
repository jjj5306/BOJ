/** BST 21939 문제 추천 시스템 Version 1 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int n, m;
int arr[100005];
set<int> prob[105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 문제 번호, 난이도 순으로 입력
    // set 배열에 난이도를 오름차순으로 저장.
    // 하나의 set에는 문제 번호를 오름차순으로 저장.
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p, l;
        cin >> p >> l;
        arr[p] = l;
        prob[l].insert(p);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string command;
        cin >> command;
        if (command == "recommend")
        {
            int flag;
            cin >> flag;
            if (flag == 1)
            {
                // 가장 어려운 문제 중 가장 문제 번호가 큰 것 출력
                for (int k = 100; k >= 0; k--)
                {
                    if (prob[k].empty())
                        continue;
                    cout << *--(prob[k].end()) << '\n';
                    break;
                }
            }
            else
            {
                // 가장 쉬운 문제 중 가장 문제 번호가 작은 것 출력
                for (int k = 1; k <= 100; k++)
                {
                    if (prob[k].empty())
                        continue;
                    cout << *prob[k].begin() << '\n';
                    break;
                }
            }
        }
        else if (command == "add")
        {
            int p, l;
            cin >> p >> l;
            prob[l].insert(p);
            arr[p] = l;
        }
        else
        {
            // 문제 P 제거. 문제 번호만 주어지기에 해당 문제가 어떤 난이도인지 알아야 함.
            int p;
            cin >> p;
            prob[arr[p]].erase(p);
        }
    }
}
