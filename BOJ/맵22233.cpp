/** 맵 22233 가희와 키워드 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int n, m, ans;
set<string> pad;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    ans = n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        pad.insert(s);
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;

        // s 파싱
        string temp;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == ',')
            {
                if (pad.find(temp) != pad.end())
                {
                    ans--;
                    pad.erase(temp);
                }
                temp.clear();
            }
            else
            {
                temp.push_back(s[j]);
            }
        }

        if (pad.find(temp) != pad.end())
        {
            ans--;
            pad.erase(temp);
        }
        cout << ans << '\n';
    }
}
