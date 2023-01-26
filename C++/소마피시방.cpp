#include <iostream>
#include <vector>

using namespace std;

vector <int> v[101];
int p, n, h;
int remain[101];
bool isVisited[101][25]= {false,};
int max_cost[101] = {0,};

void dfs(int num, vector <int> &p)
{
    unsigned long int tmp = p.size();
    if(remain[num]<=0)
    {
        int cost=0;
        for(int i=0; i<tmp; i++)
        {
            cost += p[i];
        }
        max_cost[num] = max(max_cost[num], cost);
    }
    
    for(int i=0; i<v[num].size(); i++)
    {
        if(!isVisited[num][i])
        {
            if(remain[num] < v[num][i]) continue;
            remain[num] -= v[num][i];
            isVisited[num][i] = true;
            p.push_back(v[num][i]);

            dfs(num,p);

            remain[num] += v[num][i];
            isVisited[num][i] = false;
            p.pop_back();
        }
    }

    return;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> p >> n >> h;
    
    for(int i=0; i<n; i++)
    {
        int n1, n2;
        cin >> n1;
        cin >> n2;
        
        if(n2 > h) continue;

        v[n1].push_back(n2);
    }

    for(int i=1; i<=p; i++)
    {
        vector <int> p;
        remain[i] = h;
        dfs(i,p);
        cout << i << " " << max_cost[i]*1000 << "\n";
    }
    return 0;
}