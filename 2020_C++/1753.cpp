#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>

#define INF 99999999

using namespace std;
int first;

vector < pair <int,int> > adjList[300001];
int cost[20001];

void dijkstra(int s)
{
    priority_queue < pair <int,int> > q;
    q.push(make_pair(0,s));
    cost[s] = 0;

    while(!q.empty())
    {
        int to = q.top().second;
        int value = q.top().first;

        q.pop();

        for(int i=0; i < adjList[to].size(); i++)
        {
            int next_to = adjList[to][i].second;
            int next_value = adjList[to][i].first;

            if(value + next_value < cost[next_to])
            {
                cost[next_to] = value + next_value;
                q.push(make_pair(cost[next_to], next_to));
            }
        }
    }
}

int main()
{
    int V,E;
    cin >> V >> E;
    cin >> first;

    for(int i=0; i<E; i++)
    {
        int from, to, value;

        cin >> from >> to >> value;
        adjList[from].push_back(make_pair(value, to));
    }

    for(int i=0; i<V; i++)
    {
        cost[i] = INF;
    }

    dijkstra(first);

    for(int i=1; i<=V; i++)
    {
        if(cost[i] == INF)
        {
            cout << "INF\n";
            continue;
        }
        cout << cost[i] << "\n";
    }

    return 0;
}