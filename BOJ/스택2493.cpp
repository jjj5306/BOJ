/** 스택 2493 탑 **/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> res;
    res.push_back(0);

    stack<pair<int, int>> s;
    // 초기값 설정, 맨 처음 들어온 높이는 어차피 수신 못하고 스택에 저장해야 한다.
    int x;
    cin >> x;
    s.push(make_pair(1, x));

    for (int i = 1; i < N; i++)
    {
        int height;
        cin >> height;
        // 이제 스택을 탐색하면서 현재 높이보다 작은건 다 pop하고 큰거 나오면 그거 답으로 하면 된다.
        // 작은건 다 pop해도 되는 이유는 어차피 현재 높이보다 작으면 이후의 입력에서 안쓰기 때문이다.
        while (!s.empty())
        {
            if (s.top().second > height)
            {
                res.push_back(s.top().first);
                break;
            }
            else
            {
                s.pop();
            }
        }
        if (s.empty())
            res.push_back(0);
        s.push(make_pair(i + 1, height));
    }

    for (auto x : res)
        cout << x << " ";
}