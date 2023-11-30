/** 정렬 1744 수 묶기 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> arr(N);
    int count_zero = 0, count_neg = 0, count_one = 0, count_rem;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
            count_zero++;
        else if (arr[i] == 1)
            count_one++;
        else if (arr[i] < 0)
            count_neg++;
    }
    sort(arr.begin(), arr.end());

    // 정렬된 배열의 음수 숫자들은 0 ~ count_neg - 1의 index까지 있다.
    // 0은 count_neg ~ count_neg + count_zero - 1의 index까지 있다.
    // 1은 count_neg + count_zero ~ count_neg + count_zero + count_one - 1의 index까지 있다.
    // 1초과의 양수는 count_neg + count_zero + count_one ~ N - 1의 index까지 있다.

    // *규칙 1) 음수는 음수끼리 묶어야한다. 작은 수 끼리 묶는게 우선이다.
    if (count_neg > 1)
    {
        for (int i = 0; i < count_neg - 1; i += 2)
        {
            arr[i] = arr[i] * arr[i + 1];
            arr[i + 1] = 0;
        }
    }
    // 묶이지 못한 음수의 수는 count_rem이다.
    // arr[count_neg - 1]은 0이 시작되는 배열의 바로 전이다. 이 수가 0이면 음수끼리 모두 묶은 것이고 아니면 음수 하나가 남은 것이다.
    if (arr[count_neg - 1] == 0)
        count_rem = 0;
    else
        count_rem = 1;

    // *규칙 2) 음수끼리 묶지 못한 수가 존재한다면 0과 묶는다.
    if (count_rem == 1 && count_zero >= 1)
        arr[count_neg - 1] = 0;

    // *규칙 3) 1은 무조건 묶지 않는다. 그리고 2이상의 양수는 모두 묶는데, 큰 수끼리 묶어야 한다.
    for (int i = N - 1; i > count_neg + count_zero + count_one; i -= 2)
    {
        arr[i] = arr[i] * arr[i - 1];
        arr[i - 1] = 0;
    }

    int res = 0;
    for (auto x : arr)
        res += x;
    cout << res;
}