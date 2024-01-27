/** 정렬 8979 올림픽 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, k, res = 0;

int arr[1020][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        cin >> arr[idx][0] >> arr[idx][1] >> arr[idx][2];
    }

    vector<int> gold_same_idx;
    for (int i = 1; i <= n; i++)
    {
        if (i == k)
            continue;
        if (arr[i][0] > arr[k][0])
            res++;
        else if (arr[i][0] == arr[k][0])
            gold_same_idx.push_back(i);
    }

    if (gold_same_idx.empty())
        cout << res + 1 << '\n';
    else
    {
        vector<int> silver_same_idx;
        for (auto i : gold_same_idx)
            if (arr[i][1] > arr[k][1])
                res++;
            else if (arr[i][1] == arr[k][1])
                silver_same_idx.push_back(i);

        if (silver_same_idx.empty())
            cout << res + 1 << '\n';
        else
        {
            for (auto i : silver_same_idx)
                if (arr[i][2] > arr[k][2])
                    res++;

            cout << res + 1 << '\n';
        }
    }
}
