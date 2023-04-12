// bfs -> 아님
// dfs -> 아님
// 한 루트에서는 최댓값, 전체 루트에서는 최솟값 -> 이어지는 루트에서 최댓값을 어떻게 구하지?
// -> 다익스트라 이용. 한정점에서 다른 모든 정점으로의 최단거리를 구한다

#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX_N 50001

using namespace std;

vector <pair<int,int> > adjList[MAX_N];
bool isSummit[MAX_N];
int intensity[MAX_N];

// 각 좌표에 최소 intensity 저장
pair <int,int> findRoute(vector <int> gates)
{
    priority_queue <pair<int,int>, vector <pair<int,int>>, greater <pair<int,int>> > pq;
    priority_queue <pair<int,int>, vector <pair<int,int>>, greater <pair<int,int>>> s_route;
    for(int i=0; i<MAX_N; i++)
    {
        intensity[i] = -1;
    }
    for(int i=0; i<gates.size(); i++)
    {
        pq.push({0,gates[i]});
        intensity[gates[i]] = 0;
    }
    
    while(!pq.empty())
    {
        int now = pq.top().second;
        int now_weight = pq.top().first;
        pq.pop();
        
        if(now_weight > intensity[now]) continue;
        
        if(isSummit[now])
        {
            s_route.push({now_weight, now});
            continue;
        }
        
        for(int i=0; i<adjList[now].size(); i++)
        {
            int next = adjList[now][i].first;
            int next_weight = adjList[now][i].second;
            
            if(intensity[next]==-1 || max(now_weight , next_weight) < intensity[next])
            {
                intensity[next] = max(now_weight, next_weight);
                pq.push({intensity[next], next});
            }
        }
    }
    
    return s_route.top();
}
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    int min_i = 1e9;
    int min_s = 0;
    for(int i=0; i<paths.size(); i++)
    {
        adjList[paths[i][0]].push_back({paths[i][1], paths[i][2]});
        adjList[paths[i][1]].push_back({paths[i][0], paths[i][2]});
    }
    for(int i=0; i<summits.size(); i++)
    {
        isSummit[summits[i]] = true;
    }
    
    pair <int,int> p = findRoute(gates);
    answer.push_back(p.second);
    answer.push_back(p.first);
    
    return answer;
}