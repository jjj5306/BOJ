#include <stdio.h>

// 버블 정렬 함수
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // 현재 원소와 다음 원소를 비교하여 필요한 경우 교환
            if (arr[j] > arr[j + 1])
            {
                // 두 원소의 위치를 교환
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 버블 정렬 수행
    bubbleSort(arr, n);

    // 정렬 후 배열 출력
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
