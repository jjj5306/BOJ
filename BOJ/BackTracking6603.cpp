/** BackTracking 6603 로또 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int k;
int arr[15];
int res[8];

void func(int cnt, int cur)
{
    if (cnt == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << res[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = cur; i < k; i++)
    {
        res[cnt] = arr[i];
        func(cnt + 1, i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> k;
        if (!k)
            break;

        for (int i = 0; i < k; i++)
            cin >> arr[i];

        func(0, 0);
        cout << '\n';
    }
}
