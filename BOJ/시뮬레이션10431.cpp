/** 시뮬레이션 10431 줄세우기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int idx, cnt = 0;
        cin >> idx;

        int arr[20];
        cin >> arr[0];

        for (int cur = 1; cur < 20; cur++)
        {
            // cur번째 학생이 줄 설 차례
            cin >> arr[cur];
            int taller_idx = -1;
            for (int front = cur - 1; front >= 0; front--)
                if (arr[front] > arr[cur])
                    taller_idx = front;

            if (taller_idx != -1)
            {
                // 자기보다 키 큰 학생을 찾은 경우
                // taller_idx부터 cur-1까지 학생들을 뒤로 한 칸 물리면 된다.
                int cur_h = arr[cur];
                for (int change = cur; change > taller_idx; change--)
                    arr[change] = arr[change - 1];
                arr[taller_idx] = cur_h;

                cnt += cur - taller_idx;
            }
        }
        cout << idx << ' ' << cnt << '\n';
    }
}