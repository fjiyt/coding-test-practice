#include <iostream>
#include <vector>
#include <queue>
#define INF 100000
using namespace std;

int N, D;
vector <pair<int,int> > v[10001];
int min_time=100000;
int dp[10001];
vector <int> s;
int first, last;
int idx = 0;
void solve(int start)
{
    if(v[start].size()==0) return;
    
    for(int i=0; i<v[start].size(); i++)
    {
        int next = v[start][i].first;
        int time = v[start][i].second;

        if(dp[next] > dp[start]+time)
        {
            dp[next] = dp[start]+time;
        }
        solve(next);
    }
}
int main()
{
    cin >> N >> D;
    int start, end, length;
    for(int i=0; i<N; i++)
    {
        cin >> start >> end >> length;
        s.push_back(start);
        v[start].push_back({end, length});
    }

    for(int i=0; i<N; i++)
    {
        dp[i] = INF;
    }

    s.erase(unique(s.begin(),s.end()),s.end());
    sort(s.begin(), s.end());
    first = s[0];
    last = s[s.size()-1];
    dp[first] = first - 0;
    solve(first);
}