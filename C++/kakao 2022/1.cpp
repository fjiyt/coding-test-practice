#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;

    vector<pair<string, string>> pairs;
    vector<pair<string, int>> num;

    for (int i = 0; i < id_list.size(); i++)
    {
        pairs.push_back(make_pair(id_list[i], 0));
    }

    return answer;
}