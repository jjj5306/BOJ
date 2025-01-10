/** 그리디 1541 잃어버린 괄호 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string s;
int ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;

    //-가 나오면 그 뒤 +는 모두 -로 처리
    int temp = 0;
    bool minus = false; // minus가 true이면 -로 처리
    for (auto x : s)
    {
        if (x == '+')
        {
            if (minus)
                ans -= temp;
            else
                ans += temp;
            temp = 0;
        }
        else if (x == '-')
        {
            if (minus)
                ans -= temp;
            else
                ans += temp;
            temp = 0;
            minus = true;
        }
        else
        {
            // 숫자인 경우
            temp *= 10;
            temp += (x - '0');
        }
    }

    if (minus)
        ans -= temp;
    else
        ans += temp;

    cout << ans << '\n';
}
