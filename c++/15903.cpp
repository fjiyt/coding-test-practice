#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    int num, combine;
    long long min_sum=0;
    long long card_num=0;

    cin >> num; // 카드의 개수
    cin >> combine; // 합체 횟수

    for(int i=0; i<num; i++)
    {
        cin >> card_num;
        pq.push(card_num);
    }

    while(combine--){
        min_sum=0;
        for(int i=0; i<2; i++)
        {
            min_sum+=pq.top();
            pq.pop();
        }
        pq.push(min_sum);
        pq.push(min_sum);
    }

    min_sum=0;  
    for(int i=0; i<num; i++)
    {
        min_sum+=pq.top();
        pq.pop();
    }
    printf("%lld\n",min_sum);
    return 0;
}