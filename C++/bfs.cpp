#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> adjList[1001];
bool isVisited[1001] = {false,};
queue <int> que;

void bfs(int V)
{
    que.push(V);

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();

        if(isVisited[cur]) continue;
        isVisited[cur] = true;

        cout << cur << " ";
        
        for(int i=0; i<adjList[cur].size(); i++)
        {
            que.push(adjList[cur][i]);
        }
    }
    cout << "\n";
}
int main(void)
{
    int N, M, V;
    cin >> N >> M >> V;

    for(int i=0; i<M; i++)
    {
        int s,e;
        cin >> s >> e;
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }

    for(int i=0; i<M; i++)
    {
        sort(adjList[i].begin(),adjList[i].end());
    }

    fill_n(isVisited,M,false);
    bfs(V);
    return 0;
}