/** 정렬 20920 영단어 암기는 괴로워 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;

int n, m;
map<string, int> input_words;
struct cmp
{
    bool operator()(pair<int, string> str1, pair<int, string> str2)
    {
        if (str1.first == str2.first)
        {
            // 빈도가 같다면
            if (str1.second.length() == str2.second.length())
            {
                // 사전순으로 더 작은게 우선순위가 높음
                return str1.second > str2.second;
            }
            else
                // 길이가 긴게 우선순위가 높음
                return str1.second.length() < str2.second.length();
        }
        else
            // 빈도가 큰게 우선순위가 높음
            return str1.first < str2.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s.length() >= m)
        {
            if (input_words.find(s) == input_words.end())
                input_words.insert({s, 1});
            else
                input_words[s]++;
        }
    }
    // 맵에 string, 빈도 순으로 삽입 완료
    // 이 맵의 정렬 기준을 현재는 사전 오름차순인데 빈도 내림차순으로 새로 생성
    for (auto x : input_words)
    {
        pq.push({x.second, x.first});
    }

    while (!pq.empty())
    {
        cout << pq.top().second << '\n';
        pq.pop();
    }
}
