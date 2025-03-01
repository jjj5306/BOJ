/** Binary Search 1822 차집합 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
vector<int> A;
vector<int> B;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        B.push_back(b);
    }

    sort(B.begin(), B.end());

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!binary_search(B.begin(), B.end(), A[i]))
            ans.push_back(A[i]);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}
