/** 정렬 5648 역원소 정렬 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const long long MAX = 1000005;
long long n;
string numS[MAX];
vector<long long> numL;

long long func(string str)
{
    string tmp;
    long long i;
    for (i = str.length() - 1; i >= 0; i--)
        if (str[i] != '0')
            break;

    for (; i >= 0; i--)
        tmp.push_back(str[i]);

    return stoll(tmp);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (long long i = 0; i < n; i++)
        cin >> numS[i];

    for (long long i = 0; i < n; i++)
        // numS[i]를 뒤집어서 저장
        numL.push_back(func(numS[i]));

    sort(numL.begin(), numL.end());
    for (long long i = 0; i < n; i++)
        cout << numL[i] << '\n';
}
