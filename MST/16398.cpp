#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isVisited[1001];
vector <pair<int,int> > v[1001];
priority_queue < pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > dist;

void add_dist(int now)
{
    for(int i=0; i<v[now].size(); i++)
    {
        dist.push(make_pair(v[now][i].first,v[now][i].second));
    }
}
long long Prim(int N)
{
    int now,weight=0;
    long long total=0;
    dist.push(make_pair(0,1));
    for(int i=1; i<=N; i++)
    {
        while(!dist.empty())
        {
            now = dist.top().second;
            weight = dist.top().first;
            dist.pop();

            if(!isVisited[now])
            {
                isVisited[now]=true;
                break;
            }
        }
        total += weight;
        add_dist(now);
    }

    return total;
}
int main()
{
    int N;
    cin >> N;
    int weight=0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> weight;
            v[i].push_back(make_pair(weight, j));
        }
    }

    cout << Prim(N) << "\n";
}