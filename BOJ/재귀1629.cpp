/** 재귀 1629 곱셈 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

ll pow(ll a, ll b, ll c)
{
    if (b == 1)
        return a % c;
    ll val = pow(a, b / 2, c);
    if (b % 2 == 0)
        return val * val % c;
    return (val * val % c) * a % c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c);
}
