/** 수학 9375 패션왕 신해빈  **/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    vector<int> res;
    while (T--)
    {
        int n;
        cin >> n;
        map<string, int> m;

        for (int i = 0; i < n; i++)
        {
            string str1, str2;
            cin >> str1 >> str2;
            // 맵에 str2 키가 없다면 추가
            if (m.find(str2) == m.end())
            {
                m.insert({str2, 1});
            }
            else
            {
                m[str2]++;
            }
        }
        int result = 1;
        for (auto x = m.begin(); x != m.end(); x++)
        {
            result *= (x->second + 1);
        }
        res.push_back(result - 1);
    }
    for (auto x : res)
        cout << x << "\n";
}