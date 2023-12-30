/** DP 9655 돌 게임 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if (n % 2)
        cout << "SK\n";
    else
        cout << "CY\n";
}
