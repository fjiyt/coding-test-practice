#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    int max_c = 0;
    for(int i=0; i<citations.size(); i++)
    {
        max_c = max(max_c, citations[i]);
    }
    
    for(int i=max_c; i>=0; i--)
    {
        int cnt = 0;
        for(int j=0; j<citations.size(); j++)
        {
            if(citations[j] >= i) cnt++;
        }
        if(cnt>=i) {
            answer = i;
            break;
        }
    }
    return answer;
}