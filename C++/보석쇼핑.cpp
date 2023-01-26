#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;
vector<string> name;

void findGemsKind(vector<string> gems)
{
    for (int i = 0; i < gems.size(); i++)
    {
        for (int j = 0; j < name.size(); j++)
        {
            if (gems[i] != name[j])
            {
                name.push_back(gems[i]);
            }
        }
    }

    return;
}
vector<int> solution(vector<string> gems)
{
    vector<int> answer;

    findGemsKind(gems);
    int size = 0;
    int start = 100001;
    int end = 0;
    for (int i = 0; i < gems.size(); i++)
    {
        if (size == name.size())
        {
            break;
        }
        if (m.find(gems[i]) != m.end())
        {
            if (m.find(gems[i])->second == start)
            {
                start = 100001;
            }
            else if (m.find(gems[i])->second == end)
            {
                start = 0;
            }
            m.erase(m.find(gems[i]));
        }
        else
        { //처음 등장
            size++;
        }
        m.insert(make_pair(gems[i], i));
        start = min(start, i + 1);
        end = max(end, i + 1);
    }
    answer[0] = start;
    answer[1] = end;
    return answer;
}

int main()
{
    vector<string> gems;

    for (int i = 0; i < 8; i++)
    {
        string str;
        cin >> str;
        gems.push_back(str);
    }

    vector<int> ret = solution(gems);
    for (int i = 0; i < 2; i++)
    {
        cout << ret[i];
    }
    cout << "\n";
    return 0;
}