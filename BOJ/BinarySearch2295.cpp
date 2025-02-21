/** BinarySearch 2295 세 수의 합 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int U[1050];
vector<int> sum2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> U[i];
    }
    sort(U, U + n);

    // a + b를 저장한 배열 sum2 계산 및 정렬렬
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum2.push_back(U[i] + U[j]);
    sort(sum2.begin(), sum2.end());

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (binary_search(sum2.begin(), sum2.end(), U[i] - U[j]))
            {
                cout << U[i];
                return 0;
            }
        }
    }
}
