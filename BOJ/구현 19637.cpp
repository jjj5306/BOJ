/** 구현 19637 IF문 좀 대신 써줘 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    map<int, string> input;

    for (int i = 0; i < n; i++)
    {
        string str;
        int num;
        cin >> str >> num;

        if (input.find(num) == input.end())
            input.insert({num, str});
    }

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        auto it = input.lower_bound(num);

        if (it != input.end())
            cout << it->second << '\n';
    }
}
