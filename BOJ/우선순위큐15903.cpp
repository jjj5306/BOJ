/** 우선순위 큐 15903 카드 합체 놀이  **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> cards;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        cards.push(temp);
        sum += temp;
    }

    for (int i = 0; i < m; i++)
    {
        long long a = cards.top();
        cards.pop();
        long long b = cards.top();
        cards.pop();
        // a, b에 각각 우선순위 큐의 가장 작은 값 2개 저장
        sum += a + b;
        cards.push(a + b);
        cards.push(a + b);
    }

    cout << sum << "\n";
}