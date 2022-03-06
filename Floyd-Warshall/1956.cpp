#include <iostream>
#define INF 10000000

using namespace std;
int V,E;
int arr[401][401];
int dp[401][401];

void floyd()
{
    for(int i=1; i<=V; i++)
    {
        for(int j=1; j<=V; j++)
        {
            dp[i][j] = arr[i][j];
        }
    }

    for(int k=1; k<=V; k++)
    {
        for(int i=1; i<=V; i++)
        {
            for(int j=1; j<=V; j++)
            {
                if(dp[i][j] > dp[i][k] + dp[k][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    int min_cycle=INF;
    for(int i=1; i<=V; i++)
    {
        for(int j=1; j<=V; j++)
        {
            if(i!=j)
            {
                int total = dp[i][j] + dp[j][i];
                min_cycle = min(min_cycle, total);
            }
        }
    }

    if(min_cycle==INF) cout << "-1\n";
    else cout << min_cycle << "\n";
}
int main()
{
    cin >> V >> E;
    for(int i=1; i<=V; i++)
    {
        for(int j=1; j<=V; j++)
        {
            if(i==j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }

    for(int i=0; i<E; i++)
    {
        int s,e,w;
        cin >> s >> e >> w;
        arr[s][e] = w;
    }

    floyd();
}