#include <iostream>
#define INF 10000000
using namespace std;

int n, m;
int arr[101][101];
int dp[101][101];

void floyd()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dp[i][j] = arr[i][j];
        }
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dp[i][j] > dp[i][k] + dp[k][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(dp[i][j] == INF) cout << "0 ";
            else cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }
    for(int i=0; i<m; i++)
    {
        int s,e,w;
        cin >> s >> e >> w;
        if(w < arr[s][e]) arr[s][e] = w;
    }
    floyd();
}