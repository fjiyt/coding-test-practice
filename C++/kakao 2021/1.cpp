#include <string>
#include <vector>

using namespace std;
vector<char> v;
string tmp;
int solution(string s)
{
    int answer = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (97 <= s[i])
        {
            tmp.push_back(s[i]);
            tmp.erase(tmp.find(i));
        }
    }
    return answer;
}