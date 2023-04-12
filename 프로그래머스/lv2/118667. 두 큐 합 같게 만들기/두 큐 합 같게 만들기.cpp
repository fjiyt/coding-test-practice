#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long answer = -2;
    long long sum1 = 0, sum2 =0;
    
    for(int i=0; i<queue1.size(); i++)
    {
        sum1 += queue1[i];
    }
    for(int j=0; j<queue2.size(); j++)
    {
        sum2 += queue2[j];
    }
    
    int cnt1 = queue1.size();
    int cnt2 = queue2.size();
    int s1 = 0, e1 = cnt1-1;
    int s2 = 0, e2 = cnt2-1;
    answer = 0;
    
    while(1)
    {
        if(answer > cnt1 * 4) {answer = -1; break;}
        if(sum1==sum2) break;
        if(sum1 < sum2) {
            queue1.push_back(queue2[s2]);
            sum1 += queue2[s2];
            sum2 -= queue2[s2];
            queue2[s2] = 0;
            s2++;
            e1++;
        }
        else if(sum1 > sum2)
        {
            queue2.push_back(queue1[s1]);
            sum2 += queue1[s1];
            sum1 -= queue1[s1];
            queue1[s1] = 0;
            s1++;
            e2++;
        }
        answer++;
    }
    
    return answer;
}