#include <iostream>
#define INF 10000000

using namespace std;

int V, E;
int dp[401][401];
int arr[401][401];
int ans = INF;

void floyd()
{
    for(int i=1; i<=V; i++)
    {
        for(int j=1; j<=V; j++)
        {
            dp[i][j] = arr[i][j];
        }
    }

    //거점노드
    for(int k=1; k<=V; k++)
    {
        // 출발노드
        for(int i=1; i<=V; i++)
        {
            // 도착노드
            for(int j=1; j<=V; j++)
            {
                if(dp[i][j] > dp[i][k] + dp[k][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    for(int i=1; i<=V; i++)
    {
        for(int j=1; j<=V; j++)
        {
            if(i!=j)
            {
                if(ans > dp[i][j] + dp[j][i]){
                    ans = dp[i][j] + dp[j][i];
                }
            }
        }
    }

    if(ans==INF) cout << "-1\n";
    else cout << ans << "\n";
}
int main()
{
    cin >> V >> E;
    for(int i=1; i<=V; i++)
    {
        for(int j=1; j <=V; j++)
        {
            if(i==j) arr[i][j]=0;
            else arr[i][j] = INF;
        }
    }
    for(int i=0; i<E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
    }

    floyd();
}