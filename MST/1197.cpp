/*
@author jy111099
@date 2021-03-02
@question BOJ-1197 [최소 스패닝 트리]
@solution Kruskal algorithm
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V,E;
int parent[10001];
int total;
struct network
{
    int v1;
    int v2;
    int weight;
};

bool comp( network &a,  network &b)
{
    return a.weight < b.weight;
}
int Find(int x)
{
    if(parent[x] == x){
        return x;
    } else {
        return parent[x] = Find(parent[x]);
    }
}
bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if(x!=y)
    {
        parent[y] = x;
        return true;
    }
    else return false;
}
int main()
{
    cin >> V >> E;
    vector <network> v(E);
    for(int i=0; i<E; i++)
    {
        cin >> v[i].v1 >> v[i].v2 >> v[i].weight;
    }

    for(int i=1; i<=V; i++)
    {
        parent[i] = i;
    }

    sort(v.begin(), v.end(), comp);

    int cnt = 0;
    int start, end;
    for(int i=0; i<E; i++)
    {
        if(cnt == V-1) break;
        start = v[i].v1;
        end = v[i].v2;

        if(Union(start,end)){
            cnt++;
            total += v[i].weight;
        }
    }

    cout << total << "\n";
}