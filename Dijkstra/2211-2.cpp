#include <iostream>
#include <vector>
#include <queue>

#define INF 10000000

using namespace std;

int N, M;
vector <pair<int,int>> adjList[1001];
int dp[1001];
int pre[1001];

void solve(int start)
{
    priority_queue <pair<int,int>> pq;
    int now = start;
    int distance = 0;
    pq.push({start, -distance});
    dp[now] = distance;

    while(!pq.empty())
    {
        now = pq.top().first;
        distance = -pq.top().second;
        pq.pop();

        if(distance > dp[now]) continue;
        for(int i=0; i<adjList[now].size(); i++)
        {
            int next = adjList[now][i].first;
            int nextDistance = distance + adjList[now][i].second;
            if(nextDistance < dp[next])
            {
                dp[next] = nextDistance;
                pq.push({next, -dp[next]});
                pre[next] = now;
            }
        }
    }

    return;
}
int main()
{
    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        adjList[a].push_back({b,l});
        adjList[b].push_back({a,l});
    }

    for(int i=0; i<M; i++)
    {
        dp[i] = INF;
    }

    solve(1);

    cout << N-1 << "\n";
    for(int i=1; i<=N; i++)
    {
        if(pre[i] > 0) cout << i << " " << pre[i] << "\n";
    }
}