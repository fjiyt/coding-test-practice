//deque 사용. 삽입시에 성능이 저하되는 단점이 있는 vector와 달리 중간에 삽입이 가능하다.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
int T;
vector <int> out[1001];
deque <int> dq;

int main()
{
    cin >> T;
    int total;
    for(int i=0; i<T; i++)
    {
        cin >> total;
        dq.clear();
        for(int j=1; j<=total; j++)
        {
            int num;
            cin >> num;
            int position = lower_bound(dq.begin(), dq.end(), num) - dq.begin();
            dq.insert(dq.begin() + position,num);
    
            if(j%2==1) //홀수
            {
                int idx = j/2;
                out[i].push_back(dq[idx]);
            }
        }
    }

    for(int i=0; i<T; i++)
    {
        int S = out[i].size();
        cout << S << "\n";
        for(int j=0; j<S; j++)
        {
            cout << out[i][j] << " ";
        }
        cout << "\n";
    }
}