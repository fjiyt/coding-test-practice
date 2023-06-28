// backtracking -> 경로가 여러갈래로 나누어져서 안됨
// 1. 조합으로 경우의 수 구하기
// 2. 서로 연결되어있는지 확인
// 3. 이다솜파가 4명이상인지 확인
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>

#define N 5
#define DIR_NUM 4

using namespace std;

string MAP[N];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int pos[25] = {
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,1,1,
    1,1,1,1,1};
bool isVisited[N][N];
bool isSeat[N][N];

bool bfs()
{
    memset(isVisited, false, sizeof(isVisited));
    int x = -1, y = -1;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(isSeat[i][j]) {
                x = i, y = j;
                break;
            }
        }
        if(x!=-1 && y!=-1) break;
    }

    queue <pair<int,int>> que;
    que.push({x,y});
    isVisited[x][y] = true;

    bool flag = false;
    int cnt = 1;

    while(!que.empty())
    {
        x = que.front().first;
        y = que.front().second;
        que.pop();

        if(cnt==7) {flag=true; break;}

        for(int i=0; i<DIR_NUM; i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(isVisited[nx][ny]) continue;
            if(isSeat[nx][ny]==true)
            {
                isVisited[nx][ny] = true;
                que.push({nx,ny});
                cnt++;
            }
        }
    }

    if(flag) return true;
    return false;

}
bool count()
{
    int som=0;
    int total = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(isSeat[i][j])
            {
                if(MAP[i][j]=='S') som++;
            }
        }
    }
    if(som<4) return false;
    return true;
}
int main()
{
    int ans = 0;
    for(int i=0; i<N; i++)
    {
        cin >> MAP[i];
    }

    do{
        memset(isSeat, false, sizeof(isSeat));
        for(int i=0; i<N*N; i++)
        {
            int x = i/N, y=i%N;
            if(pos[i]==1)
            {
                isSeat[x][y] = true;
            }
            else isSeat[x][y] = false;
        }

        if(bfs()==1) {
            if(count()) { ans++;}
        }
    }while(next_permutation(pos, pos+25));

    cout << ans << "\n";
}