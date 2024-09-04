#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];

int main() {
    for(int i=0;i<3;i++) //입력받기
        cin >> arr[i];
    
    sort(arr,arr+3); //오름차순 정렬

    cout << arr[1]; //두번째로 큰 값 출력
}
