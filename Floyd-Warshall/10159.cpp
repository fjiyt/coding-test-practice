#include <iostream>
#define INF 1000000
using namespace std;

int N, M;
int dp[101][101];

void floyd()
{
    for(int k=1; k<=N; k++)
    {
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(dp[i][j] > dp[i][k] + dp[k][j]) dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }

    for(int i=1; i<=N; i++)
    {
        int cnt = 0;
        for(int j=1; j<=N; j++)
        {
            if(dp[i][j]==INF && dp[j][i]==INF) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
int main()
{
    cin >> N >> M;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(i==j) dp[i][j]=0;
            else dp[i][j] = INF;
        }
    }

    for(int i=0; i<M; i++)
    {
        int s,e;
        cin >> s >> e;
        dp[s][e] = 1;
    }

    floyd();
}