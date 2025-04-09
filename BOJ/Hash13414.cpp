/** Hash 13414 수강신청 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int k, l;
unordered_map<string, int> m; // student, order

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> l;
    int cur = 0;
    for (int i = 0; i < l; i++)
    {
        string stu;
        cin >> stu;
        if (m.find(stu) != m.end())
            m.erase(stu);
        m.insert({stu, cur++});
    }

    vector<pair<string, int>> ans(m.begin(), m.end());

    sort(ans.begin(), ans.end(), [](auto &a, auto &b)
         { return a.second < b.second; });
    // 참고로 C++에서 sort 함수는 비교 함수가 true를 반환하면 첫 번째 인자가 더 앞에 오게 한다.
    // 즉 comp(a, b)가 true를 반환하면 a가 앞에 오는 것이다.
    // 따라서 a > b를 비교 함수로 설정하면 a가 더 클 때 true이고 더 큰게 앞으로 오니까 내림차순이 된다.

    // ans 배열보다 k가 더 클 수 있음. k가  더 크다면 ans에 있는걸 다 출력하면 됨.
    k = min(k, (int)ans.size());
    for (int i = 0; i < k; i++)
        cout << ans[i].first << '\n';
}
