#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, X;
vector <int> adjList[300001];
bool isVisited[300001];
int total = 0;

void solve(int start, int cnt)
{
    vector <int> result;
    queue <pair<int,int> > que;

    que.push({start,cnt});
    while(!que.empty())
    {
        int now = que.front().first;
        int weight = que.front().second;
        que.pop();

        if(weight == K) {
            result.push_back(now);
        }
        for(int i=0; i<adjList[now].size(); i++)
        {
            int next = adjList[now][i];
            if(!isVisited[next])
            {
                que.push({next, weight+1});
                isVisited[next] = true;
            }
        }
    }

    if(result.size() == 0)
    {
        cout << "-1\n";
        return;
    }
    sort(result.begin(), result.end());
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K >> X;
    int s,e;
    for(int i=0; i<M; i++)
    {
        cin >> s >> e;
        adjList[s].push_back(e);
    }
    isVisited[X] = true;
    solve(X,0);
}