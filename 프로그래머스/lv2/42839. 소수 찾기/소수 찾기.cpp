#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isVisited[7];
bool isCheck[10000000];
int cnt = 0;

bool isPrime(string now)
{
    int num = stoi(now);
    
    if(num==0 || num==1) return false;
    for(int i=2; i<=sqrt(num); i++)
    {
        if(num%i==0) return false;
    }
    return true;
    
}
void dfs(string numbers, string now)
{
    if(now.size() > 0 && !isCheck[stoi(now)])
    {
        isCheck[stoi(now)] = true;
        if(isPrime(now)) cnt++;
    }
    for(int i=0; i<numbers.size(); i++)
    {
        if(isVisited[i]) continue;
        isVisited[i] = true;
        dfs(numbers, now+numbers[i]);
        isVisited[i] = false;
    }
}
int solution(string numbers) {
    int answer = 0;
    dfs(numbers, "");
    
    answer = cnt;
    return answer;
}