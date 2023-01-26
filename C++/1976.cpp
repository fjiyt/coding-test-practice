#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdbool.h>
#include <cstring>

#define C_MAX 201
#define P_MAX 1001
using namespace std;

vector <int> adjList[C_MAX];
bool isVisited[C_MAX][C_MAX] = {false,};
queue <int> que;
queue <int> route; // 루트 저장하는 큐

int bfs(int start, int end)
{
    memset(isVisited,false,sizeof(isVisited));
    route.push(start);
    while(!route.empty())
    {
        int now = route.front();
        route.pop();

        if(now == end)
        {
            return 1;
        }

        for(int i=0; i<adjList[now].size(); i++)
        {
            int tmp = adjList[now][i];
            if(!isVisited[now][tmp])
            {
                route.push(tmp);
                isVisited[now][tmp] = true;
            }
        }
    }

    return -1;
}
int main()
{
    int N, M;
    cin >> N >> M;

    int num;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> num;
            if(num) 
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    for(int i=0; i<M; i++)
    {
        cin >> num;
        que.push(num-1);
    }

    int start = que.front();
    que.pop();
    int end = 0;

    for(int i=0; i<M-1 && !que.empty() ; i++)
    {
        end = que.front();
        que.pop();

        if(bfs(start, end) == -1) // 도저히 경로가 나오지 않을 경우
        {
            cout << "NO\n";
            return 0;
        }

        start = end;
    }

    cout << "YES\n";
    return 0;
}