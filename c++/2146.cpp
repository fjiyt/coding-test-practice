#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <stdio.h>

using namespace std;

int arr[101][101]={0,};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool isVisited[101][101]={false,};
queue < pair <int,int> > que;
queue <int> cost;
pair <int,int> cur;
pair <int,int> tmp;

int N;

void checkIsland (int x, int y, int idx)
{
    isVisited[x][y]=true;
    arr[x][y] = idx;
    int nx,ny;

    for(int i=0; i<4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];

        if(nx < N && ny < N && nx >= 0 && ny >= 0)
        {
            if(arr[nx][ny] && !isVisited[nx][ny]) checkIsland(nx,ny,idx);
        }
    }
}

int BFS()
{
    memset(isVisited,0,sizeof(isVisited));
    int length=0;
    int min_length = N*N;

    que.push(pair <int,int> (0,0));
    cost.push(length);

    while(!que.empty())
    {
        cur = que.front();
        que.pop();
        length = cost.front();
        cost.pop();

        if(isVisited[cur.first][cur.second]) continue;
        isVisited[cur.first][cur.second]=true;

        for(int i=0; i<4; i++)
        {
            tmp = make_pair(cur.first+dx[i],cur.second+dy[i]);
            if(tmp.first > N || tmp.second > N || tmp.first < 0 || tmp.second < 0) continue;
            if(arr[tmp.first][tmp.second]>0) 
            {
                if(arr[tmp.first][tmp.second]!=arr[cur.first][cur.second]) //서로 다른 섬일때
                {
                    if(length>0 && min_length>0) {
                        min_length = min(min_length,length);
                        printf("min: %d, len : %d, x: %d, y: %d\n",min_length,length, tmp.first,tmp.second);
                    }
                    length=0;
                }
            }
            else if(!arr[tmp.first][tmp.second])
            {
                arr[tmp.first][tmp.second] = arr[cur.first][cur.second];
                length++;
            }
            que.push(tmp);
            cost.push(length);
        }
    }

    return min_length;
}
int main()
{
    cin >> N;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    int idx=1;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(arr[i][j] && !isVisited[i][j]) checkIsland(i,j,idx++);
        }
    }

    cout << "\n";

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << arr[i][j] <<" ";
        }

        cout << "\n";
    }

    while(!que.empty())
    {
        que.pop();
    }
    int length = BFS();

    cout << length << "\n";
    return 0;
}