#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 10000000;

int d[7];
vector<pair<int, int> > a[7];

void dijkstra(int start)
{
    d[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(start, 0));

    while (!pq.empty())
    {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();

        if (d[current] < distance)
            continue;
        for (int i = 0; i < a[current].size(); i++)
        {
            int next = a[current][i].first;
            int nextDistance = distance + a[current][i].second;
            if (nextDistance < d[next])
            {
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
}