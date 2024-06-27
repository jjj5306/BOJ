#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n)
{
    // j번과 j+1번을 계속 비교하면서 정렬
    for (int i = 0; i + 1 < n; i++)
    {
        for (int j = 0; j + 1 < n; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    // 버블 정렬 수행
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    { // 정렬 후 배열 출력
        printf("%d ", arr[i]);
    }
    return 0;
}