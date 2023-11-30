/** 정렬 7795 먹을 것인가 먹힐 것인가 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    vector<int> res;
    while (T--)
    {
        int N, M;
        cin >> N >> M;

        vector<int> A(N), B(M);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < M; i++)
            cin >> B[i];

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int p_b = 0, result = 0;
        for (int i = 0; i < N; i++)
        {
            while ((p_b < M) && A[i] > B[p_b])
            { // a[i] > b[p_b]이면 p_b가 다음 index를 가리키게 한다.
                p_b++;
            }
            // while문을 나왔을 때 p_b의 값은 a[i]보다 작은 수의 개수이다.
            result += p_b;
        }
        res.push_back(result);
    }
    for (auto x : res)
        cout << x << "\n";
}