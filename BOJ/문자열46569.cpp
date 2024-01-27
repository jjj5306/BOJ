/** 문자열 4659 비밀번호 발음하기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char mo[5] = {'a', 'e', 'i', 'o', 'u'};

    while (1)
    {
        string str;
        cin >> str;
        if (str.compare("end") == 0)
            break;

        bool accept = true;
        vector<int> mo_idx;

        for (int j = 0; j < 5; j++)
            if (mo[j] == str[0])
                mo_idx.push_back(0);

        for (int i = 1; i < str.length(); i++)
        {
            // 1단계로 연속된 글자인지 체크
            if (str[i] == str[i - 1] && str[i] != 'e' && str[i] != 'o')
            {
                accept = false;
                break;
            }
            // 1단계 통과 모음 있는지 체크
            for (int j = 0; j < 5; j++)
                if (mo[j] == str[i])
                    mo_idx.push_back(i);
        }

        if (!accept)
        {
            cout << '<' << str << "> is not acceptable.\n";
            continue;
        }

        // 2단계 모음 있는지 체크
        if (mo_idx.empty())
        {
            accept = false;
            cout << '<' << str << "> is not acceptable.\n";
            continue;
        }

        // 3단계 자/모 3글자 이상 있는지 체크 모음부터
        if (mo_idx.size() >= 3)
        {
            for (int i = 0; i < mo_idx.size() - 2; i++)
            {
                if (mo_idx[i] + 1 == mo_idx[i + 1] && mo_idx[i + 1] + 1 == mo_idx[i + 2])
                {
                    accept = false;
                    break;
                }
            }
        }
        if (!accept)
        {
            cout << '<' << str << "> is not acceptable.\n";
            continue;
        }

        for (int i = 1; i < mo_idx.size(); i++)
        {
            if (mo_idx[i] - mo_idx[i - 1] > 3)
            {
                accept = false;
                break;
            }
        }
        if (mo_idx[0] >= 3 || str.length() - mo_idx[mo_idx.size() - 1] > 3)
            accept = false;

        if (!accept)
            cout << '<' << str << "> is not acceptable.\n";

        else
            cout << '<' << str << "> is acceptable.\n";
    }
}
