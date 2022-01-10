#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;
int INF = 10000000;

vector<pair<int, int> > a[20002];
int d[20002] = {
    0,
};

void dijkstra(int start)
{
    d[start] = 0;
}
int main()
{
    cin >> V >> E;
    int start;
    cin >> start;
    for (int i = 0; i < E; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        a[from].push_back(make_pair(to, weight));
    }
    for (int i = 1; i <= E; i++)
    {
        d[i] = INF;
    }
    dijkstra(start);

    return 0;
}