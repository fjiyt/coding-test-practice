#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10010

using namespace std;

int gender[1001];
int Parent[1001];
int N, M;
struct network
{
    int v1;
    int v2;
    int weight;
};
bool compare(network &v1, network &v2)
{
    return v1.weight < v2.weight;
}
int Find(int a)
{
    if(Parent[a]==a) return a;
    else{
        return Parent[a] = Find(Parent[a]);
    }
}
bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a != b) {
        Parent[b] = a;
        return true;
    }
    else return false;
}
int Kruskal(vector <network> &v)
{
    int cnt=0,total=0;
    for(int i=0; i<M; i++)
    {
        if(cnt==N-1) break;
        int v1 = v[i].v1;
        int v2 = v[i].v2;
        int weight = v[i].weight;

        if(weight >= INF) return -1;

        if(Union(v1,v2)) {
            
            total += weight;
            cnt++;
        }
    }
    return total;
}
void solve(vector <network> &v)
{
    for(int i=1; i<=N; i++)
    {
        Parent[i] = i;
    }
    sort(v.begin(), v.end(), compare);

    cout << Kruskal(v) << "\n";
}
int main()
{
    cin >> N >> M;
    vector <network> v(M);
    for(int i=1; i<=N; i++)
    {
        char s;
        cin >> s;
        if(s == 'W') gender[i] = 0;
        else gender[i] = 1;
    }
    int v1, v2, weight;
    int idx = 0;
    for(int i=0; i<M; i++)
    {
        cin >> v[i].v1 >> v[i].v2 >> v[i].weight;
        if(gender[v[i].v1] == gender[v[i].v2]) v[i].weight = INF;
    }
    solve(v);
}