#include <iostream>

using namespace std;

int n,m,k;
int MAP[21][21];
int team[21][21];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

struct pos{
    int x;
    int y;
};
pos head[6];
pos tail[6];

struct queue {
    pos pool[4001];
    int r,l;

    void init(){r=l=0;}
    void push(pos p){pool[r++]=p;}
    pos pop(){return pool[l++];}
    bool empty() {return r==l;}
};

queue q;

void set_team(int idx) {
    q.init();
    q.push(head[idx]);
    team[head[idx].x][head[idx].y] = idx;
    while(!q.empty()){
        pos cur = q.pop();
        for(int i=0; i<4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if(team[nx][ny]!=-1) continue;
            if(MAP[nx][ny]==1 || MAP[nx][ny] == 0) continue;
            if(MAP[nx][ny]==3) tail[idx]={nx,ny};
            team[nx][ny] = idx;
            q.push({nx,ny});
        }
    }
}

void move()
{
    for(int i=0; i<m; i++)
    {
        pos curh = head[i];
        for(int j=0; j<4; j++)
        {
            int nx = curh.x + dx[j];
            int ny = curh.y + dy[j];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(MAP[nx][ny] < 3) continue;
            else{
                head[i] = {nx,ny};
                MAP[curh.x][curh.y] = 2;
                break;
            }
        }

        pos curt = tail[i];
        for(int i=0; i<4; i++)
        {
            int nx = curt.x + dx[i];
            int ny = curt.y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(MAP[nx][ny] != 2) continue;
            if(nx == curh.x && ny == curh.y) continue;
            tail[i] = {nx, ny};
            MAP[curt.x][curt.y] = 4;
            break;
        }

        MAP[head[i].x][head[i].y] = 1;
        MAP[tail[i].x][tail[i].y] = 3;
    }
}

void shoot(int round)
{
    int dir = ((round/n) + 3)%4;
    if(round % n != 0) {
        arr = {arr.x + dx[dir],}
    }
}
int main() {
    // Please write your code here.
    cin >> n >> m >> k;

    int idx = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> MAP[i][j];
            if(MAP[i][j] == 1) {
                head[idx++] = {i,j};
            }
            team[i][j] = -1;
        }
    }

    for(int i=0; i<m; i++)
    {
        set_team(i);
    }
    
    for(int i=0; i<k; i++)
    {
        move();
        shoot(i);
    }
    return 0;
}