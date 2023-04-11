#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push({3,4});
    pq.push({2,3});
    pq.push({2,5});
    pq.push({1,3});

    pq.pop();
    pq.pop();

    cout << "pq top : " << pq.top().first << " " << pq.top().second << "\n";
    
    if(!pq.empty()) cout << "pq size : " << pq.size() << "\n";

    while(!pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second << "\n";
        pq.pop();
    }

    cout << "\n";
    return 0;
}