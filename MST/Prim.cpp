//정점연결. sorting해야되는 간선이 너무 많을경우 사용하면 좋음
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
vector <pair<int,int> > v[1001];
priority_queue <pair<int,int> > pq;
bool isVisited[1001];

void add_road(int idx)
{
    for(int i=0; i<v[idx].size(); i++)
    {
        int next = v[idx][i].second;
        int weight = v[idx][i].first;

        pq.push({-weight, next});
    }
}
int Prim()
{
    pq.push({0,1});
    int now, weight, total =0;
    for(int i=0; i<N; i++)
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
    cin >> N >> M;
    int v1, v2, w;
    for(int i=0; i<M; i++)
    {
        cin >> v1 >> v2 >> w;
        v[v1].push_back({w,v2});
        v[v2].push_back({w,v1});
    }

    cout << Prim() << "\n";
}