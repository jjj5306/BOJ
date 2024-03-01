/** 그리디 20310 타노스 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string input;
int cnt_zero = 0;
int cnt_one = 0;
vector<char> output;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> input;
    for (auto x : input)
    {
        if (x == '0')
            cnt_zero++;
        else
            cnt_one++;
    }

    cnt_zero /= 2;
    cnt_one /= 2;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[input.length() - i - 1] == '0' && cnt_zero > 0)
        {
            input[input.length() - i - 1] = 'n';
            cnt_zero--;
        }
        if (input[i] == '1' && cnt_one > 0)
        {
            input[i] = 'n';
            cnt_one--;
        }
    }
    for (auto x : input)
        if (x != 'n')
            output.push_back(x);

    for (auto x : output)
        cout << x;
}
