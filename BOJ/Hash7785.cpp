/** 해시 7785 회사에 있는 사람 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int n;
unordered_set<string> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string who, status;
        cin >> who >> status;

        if (status == "enter")
            s.insert(who);
        else
            s.erase(who);
    }
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for (auto x : ans)
        cout << x << '\n';
}
