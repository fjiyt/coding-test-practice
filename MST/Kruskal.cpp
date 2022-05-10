#include <iostream>
#include <vector>

using namespace std;

int V, E;
int parent[10001];
struct network
{
    int v1;
    int v2;
    int weight;
};
bool comp(network &a, network &b)
{
    return a.weight < b.weight;
}
int Find(int a)
{
    if(parent[a] == a)
    {
        return a;
    }
    else{
        return parent[a] = Find(parent[a]);
    }
}
bool Union(int a, int b)
{
    if(Find(a)!=Find(b))
    {
        parent[b] = a;
        return true;
    }
    return false;
}
int kruskal(vector <network> &v)
{
    int cnt = 0, total = 0;
    for(int i=0; i<E; i++)
    {
        if(cnt==V-1) break;
        int v1 = v[i].v1;
        int v2 = v[i].v2;
        int weight = v[i].weight;

        if(Union(v1, v2))
        {
            total += weight;
            cnt++;
        }
    }
    return total;
}
void solve(vector <network> &v)
{
    for(int i=1; i<=V; i++)
    {
        parent[i] = i;
    }
    sort(v.begin(), v.end(), comp);
    cout << kruskal(v) << "\n";
}
int main()
{
    cin >> V >> E;
    vector <network> v(E);

    for(int i=0; i<E; i++)
    {
        cin >> v[i].v1 >> v[i].v2 >> v[i].weight;
    }

    solve(v);
}