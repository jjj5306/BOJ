/** 우선순위 큐 7662 이중 우선순위 큐  **/
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        multiset<int, greater<int>> se;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            string s;
            int x;
            cin >> s >> x;

            // 삽입인 경우
            if (s == "I")
            {
                se.insert(x);
            }
            // 삭제인 경우
            else
            {
                if (!se.empty())
                {
                    if (x == 1)
                        // 최댓값 삭제
                        se.erase(se.begin());
                    else
                        // 최솟값 삭제
                        se.erase(--se.end());
                }
            }
        }
        if (se.empty())
            cout << "EMPTY\n";
        else
        {
            cout << *se.begin() << " " << *--se.end() << "\n";
        }
    }
}