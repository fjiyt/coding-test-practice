#include <iostream>
#include <queue>

using namespace std;
int N;
int sum =0;
priority_queue <int, vector<int>, greater<int>> min_pq;

int main()
{
    cin >> N;
    for(int i=0; i<N ; i++)
    {
        int num;
        cin >> num;
        min_pq.push(num);
    }
    while(!min_pq.empty())
    {
        if(min_pq.size() < 2) break;
        int add = min_pq.top();
        min_pq.pop();
        add += min_pq.top();
        min_pq.pop();

        sum += add;
        min_pq.push(add);
    }

    cout << sum << "\n";
}