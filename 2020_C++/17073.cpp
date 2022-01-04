#include <iostream>

using namespace std;

int N;
double W;
int adjList[500001]={0,};

int main(void)
{
    cin >> N >> W;

    int s,e;
    for(int i=0; i < N-1; i++)
    {
        cin >> s >> e;
        adjList[s]++;
        adjList[e]++;
    }
    
    int cnt=0;

    for(int i=0; i<500001; i++)
    {
        if(adjList[i] == 1) cnt++;
    }
    
    cout << W / cnt << "\n";

    return 0;
}