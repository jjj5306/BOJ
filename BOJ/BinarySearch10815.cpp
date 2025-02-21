/** BinarySearch 10815 숫자 카드 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int a[500100];
int b[500100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    for (int i = 0; i < m; i++)
        cout << binary_search(a, a + n, b[i]) << ' ';
}
