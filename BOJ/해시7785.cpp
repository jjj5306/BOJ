/** 해시 7785 회사에 있는 사람 **/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    set<string, greater<string>> s;

    for (int i = 0; i < N; i++)
    {
        string name, status;
        cin >> name >> status;
        if (status == "enter")
        {
            s.insert(name);
        }
        else
        {
            if (s.find(name) != s.end())
                s.erase(name);
        }
    }

    for (auto x : s)
        cout << x << "\n";
}
