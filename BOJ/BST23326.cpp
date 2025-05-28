/** BST 233326 홍익 투어리스트 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int n, q, cur = 1;
set<int> s; // 명소 저장

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
            s.insert(i);
    }

    while (q--)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int k;
            cin >> k;
            // k 번째가 s에 존재하면 제거, 아니라면 삽입
            if (s.find(k) != s.end())
                s.erase(k);
            else
                s.insert(k);
        }
        else if (query == 2)
        {
            int k;
            cin >> k;
            // k 만큼 시계 방향으로 이동, 배열에 0 index가 존재하므로 조심할 것
            cur = (cur + k - 1) % n + 1;
        }
        else
        {
            // 가장 가까운 명소 찾기
            if (s.empty())
                cout << "-1" << '\n';
            else
            {
                auto it = s.lower_bound(cur);
                if (it != s.end())
                    cout << (*it) - cur << '\n';
                else
                    // s가 비어있지도 않은데 lower_bound에 없다면 한 시계 바퀴를 돌아야 함
                    cout << n - cur + (*s.begin()) << '\n';
            }
        }
    }
}
