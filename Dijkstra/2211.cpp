/*
@author jy111099
@date 2021-01-12
@question BOJ-2211 [네트워크 복구]
@solution Dijkstra / BFS
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 10000000;
int N, M;
int d[1001] = {
    0,
};
vector<pair<int, int> > a[1001];
int pre[1001] = {
    0,
};

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
                pre[next] = current;
            }
        }
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int city1, city2, time;
    for (int i = 0; i < M; i++)
    {
        cin >> city1 >> city2 >> time;
        a[city1].push_back(make_pair(city2, time));
        a[city2].push_back(make_pair(city1, time));
    }

    for (int i = 1; i <= N; i++)
    {
        d[i] = INF;
    }

    dijkstra(1);

    cout << N - 1 << endl;

    for (int i = 1; i <= N; i++)
    {
        if (pre[i] > 0)
        {
            cout << i << " " << pre[i] << "\n";
        }
    }

    return 0;
}