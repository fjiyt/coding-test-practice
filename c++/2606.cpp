#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> adjList[100];
stack<int> st;
bool isVisited[100];

void dfs(int V)
{
    int cnt = -1;
    st.push(V);

    while(!st.empty())
    {
        int cur = st.top();
        st.pop();

        if(isVisited[cur]) continue;
        isVisited[cur] = true;

        cnt++;

        for(int i = adjList[cur].size()-1; i>=0; i--)
        {
            int next = adjList[cur][i];
            st.push(next);
        }
    }

    cout<< cnt << "\n";
    return;
}
int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int num, pair;
    cin >> num >> pair;

    int s,e;
    for(int i=0; i<pair; i++)
    {
        cin >> s >> e;
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }

    fill_n(isVisited,100,false);
    dfs(1);

    return 0;
}