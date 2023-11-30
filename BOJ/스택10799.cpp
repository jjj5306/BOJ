/** 스택 10799 쇠막대기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int stack = 0, flag = 0, res = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            if (s[i + 1] == ')')
            {
                // 레이저인 경우
                res += stack + flag;
                i++;
                flag = 0;
            }
            else
            {
                // (만 들어온 경우
                stack++;
                flag++;
            }
        }
        else
        {
            // ) 들어온 경우
            stack--;
        }
    }
    cout << res;
}
