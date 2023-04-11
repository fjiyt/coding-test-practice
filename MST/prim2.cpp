#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int V, E;
vector <pair<int,int> > route[100001];
priority_queue <pair<int,int>> pq;
bool isVisited[100001];

void add_road(int n)
{
    for(int i=0; i<route[n].size(); i++)
    {
        int next = route[n][i].first;
        int weight = route[n][i].second;

        pq.push({-weight, next});
    }
}
int Prim()
{
    int total = 0;
    int now, weight;
    pq.push({0,1});
    for(int i=0; i<V; i++)
    {
        while(!pq.empty())
        {
            now = pq.top().second;
            weight = -pq.top().first;
            pq.pop();

            if(!isVisited[now])
            {
                isVisited[now] = true;
                total += weight;
                break;
            }
        }
        add_road(now);
    }    
    return total;
}
int main()
{
    cin >> V >> E;
    for(int i=0; i<E; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        route[v1].push_back(make_pair(v2,w));
        route[v2].push_back(make_pair(v1,w));
    }

    cout << Prim() << "\n";
}