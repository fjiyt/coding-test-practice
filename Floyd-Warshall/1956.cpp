//다익스트라는 시작노드가 확실히 정해져있지만, 플로이드는 시작노드가 정해져있지 않고 최솟값을 찾는 형태이다
//플로이드의 범위가 더 작은 느낌도 있음. 배열로 해결가능하도록
#include <iostream>
#define INF 10000000
using namespace std;
int V, E;
int dp[401][401];
int arr[401][401];
int ans=INF;

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
        //출발노드
        for(int i=1; i<=V; i++)
        {
            //도착노드
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
                int total = dp[i][j] + dp[j][i];
                ans = min(ans, total);
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
        for(int j=1; j<=V; j++)
        {
            if(i==j) arr[i][j]=0;
            else arr[i][j] = INF;
        }
    }
    int a,b,c;
    for(int i=0; i<E; i++)
    {
        cin >> a >> b >> c;
        arr[a][b] = c;
    }

    floyd();
}