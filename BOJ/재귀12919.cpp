/* 재귀 12919 A와 B 2 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string start, target;
bool ans = false;

// base condition 1 : start, target 길이가 같음. 아예 같으면 return 1 아니면 return 0
// 점화식 1 : 맨 뒤 A 제거
// 점화식 2 : 뒤집고 맨 뒤 B 제거
void func(string t)
{
    if (start.length() == t.length())
    {
        if (start == t)
        {
            ans = true;
            return;
        }
    }
    string temp = t;

    // 점화식 1
    if (temp.back() == 'A')
    {
        temp.erase(temp.end() - 1);
        // cout << "case1 " << temp << '\n';

        func(temp);
    }

    // 점화식 2
    temp = t;
    reverse(temp.begin(), temp.end());
    if (temp.back() == 'B')
    {
        temp.erase(temp.end() - 1);
        // cout << "case2 " << temp << '\n';
        func(temp);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> start >> target;

    func(target);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
}