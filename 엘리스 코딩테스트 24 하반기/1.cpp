/**  **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int arr[10] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for (auto x : s)
    {
        arr[(int)((int)x - '0')]++;
    }

    while (1)
    {
        bool flag = true;
        int n = stoi(s);
        n++;
        s = to_string(n);

        int temp_arr[10] = {
            0,
        };

        for (auto x : s)
        {
            temp_arr[(int)((int)x - '0')]++;
        }

        for (int i = 0; i <= 9; i++)
        {
            if (arr[i] != temp_arr[i])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << s << '\n';
            break;
        }
    }
}
