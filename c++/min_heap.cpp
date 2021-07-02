#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int num;
priority_queue<int, vector<int>, greater<int> > pq;

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> num;

    while(num--)
    {
        int n;
        cin >> n;
        if(n==0)
        {
            if(pq.empty())
            {
                printf("0\n");
            }
            else{
                printf("%d\n",pq.top());
                pq.pop();
            }
        }
        else pq.push(n);
    }

    return 0;
}