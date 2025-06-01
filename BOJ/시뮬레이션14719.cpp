/* 시뮬레이션 14719 빗물 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w, h;
int arr[502];
int ans = 0;

// 빗물이 고이는 기준은 좌우 블럭의 최대치까지 고인다.
// 만약 한 블록 좌우가 비어있어도 그 좌우가 또 차있다면 고이게 된다.
// func(k) : k 번째 블록에 고이는 빗물을 계산한다.
// k번째 블록에 빗물이 채워지는 과정은 좌 우 중 가장 높이 차가 낮은 블록 까지 고임
void func(int k)
{
    // cout << "k : " << k << '\n';

    // k번째 블록의 왼쪽 블록 계산
    int left;
    left = k - 1;
    // cout << "left : " << left << '\n';

    // base condition
    if (arr[left] <= arr[k])
        return;

    // k번째 블록의 오른쪽 블록 중 자신보다 높은 블록 찾기
    int right = k;
    for (int r = k; r < w; r++)
    {
        if (arr[r] > arr[k])
        {
            right = r;
            break;
        }
    }
    // cout << "right :" << right << '\n';

    // base condition
    if (arr[right] <= arr[k])
        return;

    // left ~ right 까지 둘 중 더 낮은 블록만큼 물이 채워짐
    int min_block = min(arr[left], arr[right]);
    // cout << "min_block : " << min_block << '\n';

    for (int i = left + 1; i < right; i++)
    {
        // i번째 물 채우기
        ans += min_block - arr[i];
        arr[i] = min_block;
    }
    // cout << "ans : " << ans << '\n';

    for (int i = 0; i < w; i++)
    {
        // cout << "i : " << i << " arr[i] : " << arr[i] << '\n';
        func(i);
    }
    // cout << "*********\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;
    for (int i = 0; i < w; i++)
        cin >> arr[i];

    // 높이가 가장 낮으면서 왼쪽인 블록으로 func 호출
    for (int i = 0; i < w; i++)
    {
        func(i);
    }

    cout << ans;
}