/** 구현 2607 비슷한 단어 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, ans;
string input[103];

bool judge(int idx)
{
    // input[0]과 input[idx] 비교
    string standard = input[0], comp = input[idx];

    if (abs((long)(standard.length()) - (long)(comp.length())) > 1)
        return false;

    bool comp_visited[13] = {
        false,
    };
    bool standard_visited[13] = {
        false,
    };

    for (int i = 0; i < standard.length(); i++)
    {
        for (int j = 0; j < comp.length(); j++)
        {
            if (!comp_visited[j] && standard[i] == comp[j])
            {
                comp_visited[j] = true;
                standard_visited[i] = true;
                break;
            }
        }
    }

    int standrad_uncorrect = 0;
    for (int i = 0; i < standard.length(); i++)
        if (!standard_visited[i])
            standrad_uncorrect++;
    if (standrad_uncorrect > 1)
        return false;

    int comp_uncorrect = 0;
    for (int i = 0; i < comp.length(); i++)
        if (!comp_visited[i])
            comp_uncorrect++;
    if (comp_uncorrect > 1)
        return false;

    ans++;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input[i];

    for (int i = 1; i < n; i++)
        judge(i);

    cout << ans << '\n';
}
