#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct position
{
   int x;
   int y;
};

position dir;

int n, m;
int MAP[21][21];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int x = 0;
int y = 0;

int total = 0;

int u = 1;
int f = 2;
int r = 3;

void move()
{
    int nx = x + dx[dir.x];
    int ny = y + dy[dir.y];

    if(nx < 0 || ny < 0 || nx >= n || ny >= n){
        // 방향이 반대로 바뀜 -> 각각의 방향 * (-1)
        dir.x = (dir.x + 2)%4;
        dir.y = (dir.y + 2)%4;

        nx = x + dx[dir.x];
        ny = y + dy[dir.y];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) return;
    }

    x = nx;
    y = ny;

    // 주사위도 이동
    int idx = dir.x;

    //위
    int nu,nf,nr;
    if(idx==3)
    {
        nu = f;
        nf = 7-u;
        nr = r;
    }
    //아래
    else if (idx==1)
    {
        nu = 7-f;
        nf = u;
        nr = r;
    }
    //오른쪽
    else if(idx==0)
    {
        nu = 7-r;
        nr = u;
        nf = f;
    }
    //왼쪽
    else if(idx==2)
    {
        nu = r;
        nr = 7-u;
        nf = f;
    }

    u = nu; r = nr; f = nf;

    return;
}

int calculate() //bfs
{
    bool isVisited[n][n];
    memset(isVisited,false,n*n);

    queue <pair<int,int>> q;
    q.push({x,y});
    isVisited[x][y] = true;

    int cnt = 1;
    int value = MAP[x][y];
    while(!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(MAP[nx][ny] == value) {
                if(isVisited[nx][ny]) continue;
                q.push({nx,ny});
                isVisited[nx][ny] = true;
                cnt++;
            }
        }
    }

    int sum =  value * cnt;
    return sum;
}

void spin()
{
    int dice_number = 7-u;

    if(MAP[x][y] < dice_number){ //시계방향으로 회전
        dir.x = (dir.x + 1)%4;
        dir.y = (dir.y + 1)%4;
    }
    else if(MAP[x][y] > dice_number){
        dir.x = (dir.x - 1 + 4)%4;
        dir.y = (dir.y - 1 + 4)%4;
    }
}
void solve()
{
    dir.x = 0;
    dir.y = 0;

    x = 0;
    y = 0;

    while(m--)
    {
        //이동
        move();

        //점수계산
        total += calculate();

        //값 비교 후 방향전환
        spin();
    }

    cout <<total << "\n";
}
int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> MAP[i][j];
        }
    }

    solve();
}