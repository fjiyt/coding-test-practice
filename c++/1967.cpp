#include <iostream>
#include <stack>
#include <vector>

#define MAX 10001
using namespace std;

vector <int> adjList[MAX];
vector <int> route[MAX];
stack <int> st;
bool isVisited[MAX] = {false,};
int weightList[MAX] = {0,};

void write_route(int s)
{
    
}
void dfs(int s)
{
    int sum=0;

    int cnt=0;
    st.push(s);
    while(!st.empty())
    {
        int cur = st.top();
        st.pop();

        if(isVisited[cur]) continue;
        isVisited[cur]=true;

        sum += weightList[cur];

        if(adjList[cur].size() == 0) //마지막 leaf 노드
        {

        }
        for(int i=0; i<adjList[cur].size(); i++)
        {
            st.push(adjList[cur][i]);
        }
    }
}
int main(void)
{
    int n;
    cin >> n;

    int parent, child, weight;

    for(int i=0; i<n-1; i++)
    {
        cin >> parent >> child >> weight;
        adjList[parent].push_back(child);
        weightList[child] = weight;
    }

    dfs(1);

    return 0;
}