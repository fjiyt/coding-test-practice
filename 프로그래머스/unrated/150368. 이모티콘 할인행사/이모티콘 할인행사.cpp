#include <string>
#include <vector>
#include <cmath>

using namespace std;
int sales[] = {10,20,30,40};
int max_sign = 0;
int max_sale = 0;

void getSale(vector<vector<int>> users, vector <int> emoticons, vector <int> now)
{
    int sign = 0;
    int sale = 0;
    for(int i=0; i<users.size(); i++)
    {
        int sum = 0;
        int min_sales = users[i][0];
        int min_money = users[i][1];
        for(int j=0; j<emoticons.size(); j++)
        {
            if(min_sales > sales[now[j]]) continue;
            sum += emoticons[j] - (emoticons[j] * sales[now[j]]/100);
            if(sum >= min_money) {
                sum = 0;
                sign++;
                break;
            }
        }
        sale += sum;
    }
    
    // 최댓값 갱신
    if(max_sign < sign)
    {
        max_sign = sign;
        max_sale = sale;
    }
    else if (max_sign==sign)
    {
        if(max_sale < sale)
        {
            max_sale = sale;
        }
    }
}
void permutation(vector <int> emoticons, vector <int> now, vector<vector<int>> users)
{
    if(now.size()==emoticons.size())
    {
        getSale(users, emoticons, now);
        return;
    }
    
    for(int i=0; i<4; i++)
    {
        vector <int> tmp = now;
        now.push_back(i);
        permutation(emoticons, now, users);
        now = tmp;
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    vector <int> tmp;
    permutation(emoticons, tmp, users);

    answer.push_back(max_sign);
    answer.push_back(max_sale);
    return answer;
}