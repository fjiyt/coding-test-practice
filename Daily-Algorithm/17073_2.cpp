#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,s,e;
double W, cnt = 0;
vector <int> adjList[500001];

int main(void)
{
    cin >> N >> W;

    for(int i=0; i < N-1; i++)
    {
        cin >> s >> e;
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }
    
    cnt=0;
    for(int i=0; i<500001; i++)
    {
        if(adjList[i].size() == 1) {
            cnt++;
        }

    }

    double ans = W / cnt;
    cout.precision(10);
    cout << fixed << ans << "\n";

    return 0;
}