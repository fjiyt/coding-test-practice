#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int N, total;
int dp[101][100001]={0,};
vector < pair <int, int> > v;

void backpack()
{
    int remain;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=total; j++)
        {
            dp[i][j] = dp[i-1][j];

            if(j - v[i].first >= 0) //더 넣을 수 있다면
            {
                dp[i][j] = max(v[i].second+dp[i-1][j-v[i].first], dp[i-1][j]);
            }
        }        
    }

    return ;
}

int main()
{
    cin >> N >> total;

    int W, V;

    v.push_back(make_pair(0,0));
    for(int i=0; i<N; i++)
    {
        cin >> W >> V;
        v.push_back(make_pair(W,V));
    }

    backpack();
    
    cout << dp[N][total] << "\n";
    return 0;
}