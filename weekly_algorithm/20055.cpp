#include <string>
#include <vector>
#include <iostream>

using namespace std;
int dollar[6] = {1,5,10,50,100,500};
//가장 큰 수부터 배정. 점점 줄여나가기
bool check(int money, int idx, vector<int> costs)
{
    int value = dollar[idx];
    for(int i=idx-1; i>=0; i--)
    {
        if(costs[i] * (value / dollar[i]) < costs[idx])
        {
            return false;
        }
    }
    return true;
}
int solution(int money, vector<int> costs) {
    int answer = 0;
    
    for(int i=5; i>=0; i--)
    {
        if(!check(money, i, costs))
        {
            costs[i] = 0;
            dollar[i] = 0;
        }
    }

    for(int i=5; i>=0; i--)
    {
        if(costs[i] > 0 && dollar[i] > 0)
        {
            answer += costs[i] * (money / dollar[i]);
            money -= dollar[i] * (money / dollar[i]);
        }
    }

    return answer;
}

int main()
{
    int money;
    cin >> money;

    vector<int> cost;
    for(int i=0; i<6; i++)
    {
        int num;
        cin >> num;
        cost.push_back(num);
    }

    cout << solution(money, cost) << "\n";
}