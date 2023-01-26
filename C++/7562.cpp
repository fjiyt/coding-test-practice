#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

queue < pair <int,int> > que;
queue <int> cost;
pair <int, int> start;
pair <int, int> goal;
pair <int, int> now;
pair <int, int> child;

int chess_size;
int v[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{-1,2},{-1,-2},{1,2},{1,-2}};
bool isVisited[302][302]={{false,}};

void BFS()
{
    int cnt=0;
    memset(isVisited,0,sizeof(isVisited));

    que.push(start);
    cost.push(0);

    while(!que.empty() && !cost.empty())
    {
        now = que.front();
        que.pop();
        cnt=cost.front();
        cost.pop();

        if(isVisited[now.first][now.second]) continue;
        isVisited[now.first][now.second]=true;

        if(now == goal)
        {
            cout << cnt << "\n";
            return;
        }

        for(int i=0; i<8; i++)
        {
            child.first = now.first + v[i][0];
            child.second = now.second + v[i][1];
            if(child.first >=0 && child.second >= 0 && child.first < chess_size && child.second < chess_size )
            {
                que.push(child);
                cost.push(cnt+1);
            }
        }
    }

    return ;
}
int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    for(int i=0; i<N; i++)
    {
        cin >> chess_size;
        cin >> start.first >> start.second;
        cin >> goal.first >> goal.second;
        
        while(!que.empty())
        {
            que.pop();
        }

        while(!cost.empty())
        {
            cost.pop();
        }
        BFS();
    }

    return 0;
}