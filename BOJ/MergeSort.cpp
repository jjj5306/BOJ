#include <iostream>
#include <algorithm>
using namespace std;

int n = 10;
int input_arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};
int temp_arr[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수

// mid = (start+end)/2라고 할 때 input_arr[start:mid], input_arr[mid:end]은 이미 정렬이 되어있는 상태일 때 input_arr[start:mid]와 input_arr[mid:end]을 합친다.
void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int left_idx = start;
    int right_idx = mid;
    for (int i = start; i < end; i++)
    {
        if (right_idx == end)
            temp_arr[i] = input_arr[left_idx++];
        else if (left_idx == mid)
            temp_arr[i] = input_arr[right_idx++];
        else if (input_arr[left_idx] <= input_arr[right_idx])
            temp_arr[i] = input_arr[left_idx++];
        else
            temp_arr[i] = input_arr[right_idx++];
    }
    for (int i = start; i < end; i++)
        input_arr[i] = temp_arr[i];
}

void merge_sort(int start, int end)
{
    if (start + 1 == end)
        return; // 길이 1인 경우
    int mid = (start + end) / 2;
    merge_sort(start, mid); // input_arr[start:mid]을 정렬한다.
    merge_sort(mid, end);   // input_arr[mid:end]을 정렬한다.
    merge(start, end);      // input_arr[start:mid]와 input_arr[mid:end]을 합친다.
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    merge_sort(0, n);
    for (int i = 0; i < n; i++)
        cout << input_arr[i] << ' '; // -53 3 12 15 16 22 23 25 46 357
}