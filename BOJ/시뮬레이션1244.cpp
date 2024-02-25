/** 시뮬레이션 1244 스위치 켜고 끄기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
int switch_[120];

void man(int num)
{
    // num의 배수 모두 바꾸기
    for (int mul = num; mul <= n; mul += num)
    {
        switch_[mul] += 1;
        switch_[mul] %= 2;
    }
}

void woman(int num)
{
    // num 기준 대칭 구간 찾아서 바꾸기
    int l = num, r = num;
    // 초기값 세팅
    switch_[num] += 1;
    switch_[num] %= 2;
    l--;
    r++;

    while ((l >= 1 && r <= n) && switch_[l] == switch_[r])
    {
        // 스위치 바꾸기
        switch_[l] += 1;
        switch_[l] %= 2;
        switch_[r] += 1;
        switch_[r] %= 2;

        // 다음 대칭 찾기
        l--;
        r++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    switch_[0] = -9999;
    for (int i = 1; i <= n; i++)
        cin >> switch_[i];

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int gender, num;
        cin >> gender >> num;

        if (gender == 1)
            man(num);

        else
            woman(num);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << switch_[i] << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }
}
