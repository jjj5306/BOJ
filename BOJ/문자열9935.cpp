/** 문자열 9935 문자열 폭발 **/
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str, explo;
    cin >> str >> explo;

    stack<char> s;
    reverse(explo.begin(), explo.end());

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);

        // 스택의 탑에 있는 단어가 폭발 문자열 마지막 단어와 일치하면 꺼내서 점검한다.
        if (s.top() == explo[0] && s.size() >= explo.length())
        {
            string extracted;
            for (int j = 0; j < explo.length(); j++)
            {
                extracted.push_back(s.top());
                s.pop();
            }

            // 스택에서 꺼낸 문자열이 explo와 다르다면 다시 넣는다.
            if (extracted != explo)
            {
                for (int i = extracted.length() - 1; i >= 0; i--)
                    s.push(extracted[i]);
            }
        }
    }

    if (!s.empty())
    {
        string ans;
        // 스택에 남은 문자열 처리
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    else
        cout << "FRULA";
}
