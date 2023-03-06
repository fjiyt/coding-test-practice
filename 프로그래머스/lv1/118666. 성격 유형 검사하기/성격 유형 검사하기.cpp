#include <string>
#include <vector>
#include <map>

using namespace std;

int score[7] = {3,2,1,0,1,2,3};
char p[4][2] = {
    {'R', 'T'},
    {'C', 'F'},
    {'J', 'M'},
    {'A', 'N'}
};

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map <char, int> m;
    
    for(int i=0; i<survey.size(); i++)
    {
        if(choices[i] < 4)
        {
            m[survey[i][0]] += score[choices[i]-1];
        }
        else if(choices[i] > 4)
        {
            m[survey[i][1]] += score[choices[i]-1];
        }
    }
    
    for(int i=0; i<4; i++)
    {
        if(m[p[i][0]] >= m[p[i][1]]) {
            answer += p[i][0];
        }
        else{
            answer += p[i][1];
        }
    }
    
    return answer;
}