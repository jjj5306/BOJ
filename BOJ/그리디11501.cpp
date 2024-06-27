#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<long long> stock(N);
        for (int i = 0; i < N; i++)
        {
            cin >> stock[i];
        }

        long long ans = 0, maxPrice = 0;
        for (int i = N - 1; i >= 0; i--)
        {
            if (stock[i] > maxPrice)
                maxPrice = stock[i];
            else
                ans += maxPrice - stock[i];
        }
        cout << ans << '\n';
    }
}
