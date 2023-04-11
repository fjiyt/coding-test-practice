#include <iostream>
#include <vector>

using namespace std;

int V, E;
struct network {
    int v1;
    int v2;
    int weight;
};
int parent[100001];
bool comp(network v1, network v2)
{
    return v1.weight < v2.weight;
}
int Find(int num)
{
    if(parent[num] == num) return num;
    return parent[num] = Find(parent[num]);
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
int kruskal(vector <network> &route)
{
    int total = 0, cnt =0;
    for(int i=0; i<E; i++)
    {
        if(cnt==V-1) break;
        int v1 = route[i].v1;
        int v2 = route[i].v2;
        int weight = route[i].weight;

        if(Union(v1,v2))
        {
            total += weight;
            cnt++;
        }
    }

    return total;
}
void solve(vector <network> &route)
{
    sort(route.begin(), route.end(), comp);
    for(int i=0; i<V; i++)
    {
        parent[i] = i;
    }
    cout << kruskal(route) << "\n";
}
int main()
{
    cin >> V >> E;
    vector <network> route(E);
    for(int i=0; i<E; i++)
    {
        cin >> route[i].v1 >> route[i].v2 >> route[i].weight;
    }    

    solve(route);
}