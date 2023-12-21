#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n = 10;
int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};

void quick_sort(int start, int end)
{
    if (end <= start + 1)
        return;
    int pivot = arr[start];
    int left_p = start + 1; // 왼쪽부터 시작하는 포인터, 결과물은 얘 오른쪽에 있는건 pivot 보다 커야함
    int right_p = end - 1;
    while (1)
    {
        while (left_p <= right_p && arr[left_p] <= pivot)
            left_p++;
        while (left_p <= right_p && arr[right_p] >= pivot)
            right_p--;
        if (left_p > right_p)
            break;
        swap(arr[left_p], arr[right_p]);
    }
    swap(arr[start], arr[right_p]);
    quick_sort(start, right_p);
    quick_sort(right_p + 1, end);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    quick_sort(0, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}
