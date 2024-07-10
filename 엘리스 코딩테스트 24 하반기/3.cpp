#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> pre;
vector<int> post;
int n; // '('의 수
string s;

int func(int cur)
{
    if (cur == n - 1)
    {
        // base condition
        int k = s[pre[cur] - 1] - '0';
        int result = k * (post[n - cur - 1] - pre[cur] - 1);
        return result;
    }
    int k = s[pre[cur] - 1] - '0';
    int len = func(cur + 1);
    for (int i = pre[cur] + 1; i < post[n - cur - 1]; i++)
    {
        if (cur < n - 1 && i >= pre[cur + 1] - 1 && i <= post[n - cur - 2])
            continue;
        len++;
    }
    int result = len * k;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            pre.push_back(i);
            n++;
        }
        else if (s[i] == ')')
            post.push_back(i);
    }

    if (pre.empty())
    {
        cout << s.size();
        return 0;
    }

    int ans = func(0);
    for (int i = 0; i < s.size(); i++)
    {
        if (i >= pre[0] - 1 && i <= post[n - 1])
            continue;
        ans++;
    }
    cout << ans;
}
