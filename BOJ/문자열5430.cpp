/** 문자열 5430 AC **/
#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        // 수행할 함수 입력받기
        string p;
        cin >> p;

        int n;
        cin >> n;
        deque<int> arr;
        bool reverse_flag = false, error_flag = false;
        string full_str, token = "";
        cin >> full_str; //[1,2,3]의 형식으로 저장되어 있다.
        for (int i = 0; i < full_str.length(); i++)
        {
            if (isdigit(full_str[i]))
                token += full_str[i];
            else
            {
                if (!token.empty())
                {
                    arr.push_back(stoi(token));
                    token = "";
                }
            }
        }
        for (auto x : p)
        {
            if (x == 'R')
            {
                if (reverse_flag)
                    reverse_flag = false;
                else
                    reverse_flag = true;
            }
            else
            {
                if (!error_flag)
                {
                    if (arr.empty())
                    {
                        error_flag = true;
                        break;
                    }
                    if (reverse_flag)
                        // 배열이 뒤집힌 상태라면 맨 뒤 삭제
                        arr.pop_back();

                    else
                        arr.pop_front();
                }
            }
        }
        if (error_flag)
            cout << "error\n";
        else
        {
            if (arr.empty())
                cout << "[]\n";
            else
            {
                if (reverse_flag)
                    reverse(arr.begin(), arr.end());
                cout << "[";
                for (int i = 0; i < arr.size() - 1; i++)
                    cout << arr[i] << ",";
                cout << arr.back() << "]\n";
            }
        }
    }
}
