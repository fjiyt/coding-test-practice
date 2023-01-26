#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, V;
vector <int> adjList[1001];
stack <int> st;
queue <int> que;
bool isVisited[1001]={false,};

void dfs()
{
    st.push(V);
    while(!st.empty())
    {
        int x = st.top();
        st.pop();
        if(isVisited[x]) continue;
        isVisited[x] = true;

        cout << x << " ";
        for(int i=adjList[x].size()-1; i>=0; i--)
        {
            st.push(adjList[x][i]);
        }
    }

    cout << "\n";
}

void bfs()
{
    que.push(V);
    isVisited[V] = true;
    while(!que.empty())
    {
        int x = que.front();
        que.pop();
        cout << x << " ";
        for(int i=0; i<adjList[x].size(); i++)
        {
            int y = adjList[x][i];
            if(!isVisited[y])
            {
                isVisited[y] = true;
                que.push(y);
            }
        }
    }

    cout << "\n";
}
int main()
{
    cin >> N >> M >> V;
    for(int i=0; i<M; i++)
    {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    //간선 크기순 정리
    for(int i=1; i<=N; i++)
    {
        sort(adjList[i].begin(), adjList[i].end());
    }
    
    dfs();

    for(int i=0; i<=N; i++)
    {
        isVisited[i] = false;
    }

    bfs();
}