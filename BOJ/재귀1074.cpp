/** 재귀 1074 Z **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int Z(int N, int r, int c)
{
    if (N == 0)
        return 0; // base condition
    int half = 1 << (N - 1);
    if (r < half && c < half)
        return Z(N - 1, r, c);
    if (r < half && c >= half)
        return Z(N - 1, r, c - half) + half * half;
    if (r >= half && c < half)
        return Z(N - 1, r - half, c) + 2 * half * half;
    return Z(N - 1, r - half, c - half) + 3 * half * half;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, r, c;
    cin >> N >> r >> c;
    cout << Z(N, r, c);
}
