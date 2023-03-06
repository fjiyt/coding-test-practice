#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
/* 
    1. 중복 순열으로 순서쌍 만들기
    2. 퍼센티지 확인
    3. 최소 금액 이상인지 확인 후 멤버십 전환 -> 값 저장
    4. 대소 비교
*/
using namespace std;

vector <vector<int>> perm;
int percentage[4] = {10,20,30,40};

void repeated_permutation(vector<int> tmp, int depth)
{
    if(depth == tmp.size()) {
        perm.push_back(tmp);
        return;
    } 
    for(int i=0; i<4; i++)
    {
        tmp[depth] = percentage[i];
        repeated_permutation(tmp, depth+1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector <int> tmp(emoticons.size());
    repeated_permutation(tmp, 0);
    
    int max_money = 0;
    int max_member = 0;
    
    for(int i=0; i<perm.size(); i++)
    {
        int member = 0;
        int money = 0;
        for(int j=0; j<users.size(); j++)
        {
            int user_money = 0;
            for(int k=0; k<emoticons.size(); k++)
            {
                if(perm[i][k] < users[j][0]) continue;
                int price = emoticons[k] * (100-perm[i][k])/100;
                user_money += price;                
                if(user_money >= users[j][1]) {member++; user_money = 0; break;}
            }
            money += user_money;
            
        }
        
        if(max_member < member)
        {
            max_money = money;
            max_member = member;
        }
        else if (max_member == member)
        {
            if(max_money < money)
            {
                max_money = money;
            }
        }
    }
    answer.push_back(max_member);
    answer.push_back(max_money);
    return answer;
}