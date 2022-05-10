/*
@author jy111099
@date 2021-03-03
@question BOJ-1922 [네트워크 연결]
@solution Prim algorithm
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isVisited[100001];
queue <int> que;
vector <pair<int,int> > network[100001];
priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > road;

void add_road(int num)
{
    for(int i=0; i<network[num].size(); i++)
    {
        int next = network[num][i].second;
        int weight = network[num][i].first;

        road.push(make_pair(weight, next));
    }
}
int Prim(int N)
{
    int now,weight,total=0;
    road.push(make_pair(0,1));
    for(int i=1; i<=N; i++)
    {
        while(!road.empty())
        {
            now = road.top().second;
            weight = road.top().first;
            road.pop();
            if(!isVisited[now])
            {
                isVisited[now] = true;
                break;
            }
        }
        total += weight;
        //now와 연결된 간선 추가
        add_road(now);
    }

    return total;
}
int main()
{
    int N, M;
    cin >> N >> M;
    
    int v1, v2, weight;
    for(int i=0; i<M; i++)
    {
        cin >> v1 >> v2 >> weight;
        network[v1].push_back(make_pair(weight, v2));
        network[v2].push_back(make_pair(weight, v1));
    }

    cout << Prim(N) << "\n";
}