/**  **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> list(n);
        for (auto &x : list)
            cin >> x;
        sort(list.begin(), list.end());

        bool flag = true;
        for (int i = 0; i < n - 1; i++)
        { // list[n-1]은 마지막 원소이므로 확인할 필요가 없다.
            if (list[i] == list[i + 1].substr(0, list[i].length()))
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
