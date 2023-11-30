/** 정렬 24060 알고리즘 수업 - 병합 정렬 1 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int A[500001] = {
    0,
},
    res[500001] = {
        0,
};
int N, K, cnt = 0;

// p ~ q의 왼쪽 배열과 q+1 ~ r의 오른쪽 배열을 병합한다.
void merge(int p, int q, int r)
{
    // left는 왼쪽 배열을 탐색하고 right는 오른쪽 배열을 탐색한다.
    int left = p, right = q + 1, temp = 0;
    while (left <= q && right <= r)
    {
        if (A[left] <= A[right])
        {
            res[temp++] = A[left++];
        }
        else
        {
            res[temp++] = A[right++];
        }
    }
    // 왼쪽 배열이 남는 경우
    while (left <= q)
    {
        res[temp++] = A[left++];
    }
    // 오른쪽 배열이 남는 경우
    while (right <= r)
    {
        res[temp++] = A[right++];
    }

    // 결과를 A에 저장
    left = p;
    temp = 0;
    while (left <= r)
    {
        A[left++] = res[temp++];
        cnt++;
        if (cnt == K)
        {
            cout << A[left - 1];
            return;
        }
    }
}

void merge_sort(int p, int r)
{
    if (p < r)
    {
        int q = floor((p + r) / 2);
        merge_sort(p, q);
        merge_sort(q + 1, r);
        merge(p, q, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    merge_sort(0, N - 1);
    if (cnt < K)
        cout << "-1";
}