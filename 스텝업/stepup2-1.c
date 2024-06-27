#include <stdio.h>

// 주어진 배열에서 value를 찾아 삭제하는 함수
int deleteElement(int arr[], int *size, int value)
{
    int found = 0;
    for (int i = 0; i < *size; i++)
    {
        if (arr[i] == value)
        {
            found = 1;
            // 삭제된 원소 다음부터 모든 원소를 한 칸씩 앞으로 이동
            for (int j = i; j < (*size - 1); j++)
            {
                arr[j] = arr[j + 1];
            }
            // 배열 크기 조정
            (*size)--;
            break; // 삭제 후 바로 반복문을 빠져나감
        }
    }
    return found;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5; // 배열의 초기 크기
    int value, found;

    // 삭제할 값을 입력 받음
    scanf("%d", &value);

    // deleteElement() 함수를 호출하여 삭제 작업 수행
    found = deleteElement(arr, &size, value);

    // 삭제된 원소가 존재한다면 결과 출력
    if (found)
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else
    {
        printf("Not found");
    }

    return 0;
}
