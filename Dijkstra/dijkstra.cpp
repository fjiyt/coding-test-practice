#include <iostream>
#include <vector>
#include <queue>

#define MAX 100

using namespace std;

int number = 6;
int INF = 10000000;

vector <int> dijkstra(int start, int V, vector <pair<int,int> > adj[])
{
    vector <int> dist(V,INF);
    priority_queue <pair<int,int>> pq;

    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(int i=0; i<adj[cur].size(); i++)
        {
            int next = adj[cur][i].second;
            int nextCost = cost + adj[cur][i].first;

            if(nextCost > dist[next]) continue;
            dist[next] = nextCost;
            pq.push({-nextCost, next});
        }
    }

    return dist;
}
int main()
{
    int V, E;
    vector <pair<int,int> > adj[MAX];
    cout << "정점의 개수 입력 : ";
    cin >> V;
    cout << "간선의 개수 입력 : ";
    cin >> E;

    for(int i=0; i<E; i++)
    {
        int from, to, cost;
        cout << "그래프 입력 [to-from-cost] : ";
        cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }

    vector <int> dist = dijkstra(0, V, adj);

    for(int i=0; i<V; i++)
    {
        cout << "0번 정점에서 %d번 정점까지 최단거리 : %d\n" <<  i << dist[i]<< "\n";
    }
}