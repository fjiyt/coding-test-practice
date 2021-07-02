#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
vector<int> adjList[1001]; //연결 노드 표현
bool isVisited[1001] = {false,}; //각 노드가 방문했는지 여부
stack <int> st; // 방문해야할 노드를 stack에 저장

//stack 이용
void dfs(int V)
{
    st.push(V);

    while(!st.empty())
    {
        int cur = st.top();
        st.pop();

        if(isVisited[cur]) continue;
        isVisited[cur]=true;

        cout << cur <<" ";

        for(int i=adjList[cur].size()-1; i>=0; i--)
        {
            int next = adjList[cur][i];
            st.push(next);
        }
    }
    cout << "\n";
}
//재귀함수 이용
void dfs2(int V)
{
    if(isVisited[V]) return ;
    isVisited[V] = true;
    cout << V << " ";

    for(int i=0; i<adjList[V].size(); i++)
    {
        int next = adjList[V][i];
        dfs2(next);
    }
}
int main(void)
{
    int N, M, V;
    cin >> N >> M >> V;

    int s,e;
    
    for(int i=0; i<M; i++)
    {
        cin >> s >> e;
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }

    for(int i=0; i<1001; i++)
    {
        sort(adjList[i].begin(),adjList[i].end());
    }

    fill_n(isVisited,1001,false);
    dfs(V);

    fill_n(isVisited, 1001, false);
    dfs2(V);

    cout << "\n";
    return 0;
}