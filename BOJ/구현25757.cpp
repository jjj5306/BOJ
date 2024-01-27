/** 구현 25757 임스와 함께하는 미니게임 **/
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
set<string> s;

int Y()
{
    // 1
    return s.size();
}

int F()
{
    // 2
    return s.size() / 2;
}

int O()
{
    // 3
    return s.size() / 3;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    char game;
    cin >> N >> game;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        if (s.find(str) == s.end())
            s.insert(str);
    }
    switch (game)
    {
    case 'Y':
        cout << Y();
        break;
    case 'F':
        cout << F();
        break;
    case 'O':
        cout << O();
        break;
    }
}
