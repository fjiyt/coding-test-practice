#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000

using namespace std;
int V,E;
vector <pair<int,int> > adjList[20001];
priority_queue <pair<int,int> > pq;
int dp[20001];

void dijkstra(int start)
{
    dp[start] = 0;
    pq.push(make_pair(0,start));

    while(!pq.empty())
    {
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        if(distance > dp[current]) continue;

        for(int i=0; i<adjList[current].size(); i++)
        {
            int next = adjList[current][i].first;
            int next_distance = distance + adjList[current][i].second;

            if(dp[next] > next_distance)
            {
                dp[next] = next_distance;
                pq.push(make_pair(-next_distance, next));
            }
        }
    }
}
int main()
{
    cin >> V >> E;
    int start;
    cin >> start;

    int u,v,w;
    for(int i=0; i<E; i++)
    {
        cin >> u >> v >> w;
        adjList[u].push_back(make_pair(v,w));
    }
    for(int i=1; i<=V; i++)
    {
        dp[i] = INF;
    }
    dijkstra(start);

    for(int i=1; i<=V; i++)
    {
        if(dp[i] == INF) cout << "INF\n";
        else cout << dp[i] << "\n";
    }
}