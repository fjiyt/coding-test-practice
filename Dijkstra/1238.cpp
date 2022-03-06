//다 시작장소가 다르기 때문에 다익스트라를 여러번 해야됨
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int> > adjList[1002];
int d[1002] = {
    0,
};
int goParty[1002] = {
    0,
}; //파티가는 최소 거리
int goHome[1002] = {
    0,
}; //집 오는 최소 거리
int INF = 10000000;

void dijkstra(int s)
{
    d[s] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(s, 0));

    while (!pq.empty())
    {
        int current = pq.top().first;
        int distance = -pq.top().second;

        pq.pop();

        if (d[current] < distance)
            continue;
        for (int i = 0; i < adjList[current].size(); i++)
        {
            int next = adjList[current][i].first;
            int nextDistance = distance + adjList[current][i].second;

            if (nextDistance < d[next])
            {
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
}
int main()
{
    int N, M, X;
    cin >> N >> M >> X;

    int start, end, value;
    for (int i = 0; i < M; i++)
    {
        cin >> start >> end >> value;
        adjList[start].push_back(make_pair(end, value));
    }

    //각 마을에서 파티장까지 최소거리
    for (int i = 1; i <= N; i++)
    {
        for (int i = 1; i <= N; i++)
        {
            d[i] = INF;
        }
        dijkstra(i);

        if (i == X) //파티장에서 각 마을까지 최소거리
        {
            for (int i = 1; i <= N; i++)
            {
                goHome[i] = d[i];
            }
        }
        else
        {
            goParty[i] = d[X];
        }
    }

    int max_time = 0;
    for (int i = 1; i <= N; i++)
    {
        max_time = max(max_time, goHome[i] + goParty[i]);
    }

    cout << max_time << "\n";

    return 0;
}