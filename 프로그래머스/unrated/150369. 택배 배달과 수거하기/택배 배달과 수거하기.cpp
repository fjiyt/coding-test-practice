#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int cnt = 0;
    int give = 0;
    int get = 0;
    
    for(int i=n-1; i>=0; i--)
    {
        while(give < deliveries[i] || get < pickups[i])
        {
            cnt++;
            give += cap;
            get += cap;
        }
        
        give -= deliveries[i];
        get -= pickups[i];
        answer += (i+1) * 2 * cnt;
        cnt = 0;
    }
    return answer;
}