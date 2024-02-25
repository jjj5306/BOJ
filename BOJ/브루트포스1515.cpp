/** 브루트포스 1515 수 이어 쓰기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string input_num;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> input_num;

    // 초기 세팅
    int n = 1, k = 0;

    while (1)
    {
        // 입력된 숫자의 k자리 탐색중
        string n_str = to_string(n);
        for (int i = 0; i < n_str.length(); i++)
        {
            // 입력의 k자리와 현재 n의 i자리가 같다면 매핑시킬 수 있다.
            // 다만 매핑시킨 후 바로 다음 n을 탐색해선 안된다. 22와 같은 예제를 놓칠 수 있다.
            if (input_num[k] == n_str[i])
                k++;
            if (k == input_num.length())
            {
                cout << n_str;
                return 0;
            }
        }
        n++;
    }
}
