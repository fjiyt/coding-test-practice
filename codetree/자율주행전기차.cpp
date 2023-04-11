#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_NUM 500

int n, m, c;
struct pos{
    int x;
    int y;
};
pos CAR;
pos PASSENGER[401];
pos DEST[401];
int MAP[22][22];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

pos n_PASSENGER;
int p_idx = -1;
int min_length=MAX_NUM;
int remain_passenger;

int BFS(pos Start, pos End)
{
    bool isVisited[n+1][n+1];
    memset(isVisited, false, sizeof(isVisited));
    queue <pair<pos, int>> q;
    q.push({Start, 0});
    isVisited[Start.x][Start.y]=true;
    while(!q.empty())
    {
        int x = q.front().first.x;
        int y = q.front().first.y;
        int cnt = q.front().second;
        q.pop();

        if(x==End.x && y==End.y)
        {
            return cnt;
        }
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
            if(!MAP[nx][ny] && !isVisited[nx][ny])
            {
                isVisited[nx][ny] = true;
                pos tmp;
                tmp.x = nx;
                tmp.y = ny;
                q.push({tmp, cnt+1});
            }
        }
    }

    return -1;
}
bool findPassenger()
{
    for(int i=0; i<m; i++)
    {
        if(PASSENGER[i].x==0 && PASSENGER[i].y ==0) continue;
        int l = BFS(CAR, PASSENGER[i]);

        if(l==-1) continue;
        if(l < min_length)
        {
            n_PASSENGER.x = PASSENGER[i].x;
            n_PASSENGER.y = PASSENGER[i].y;
            p_idx = i;
            min_length = l;
        }
        else if(l == min_length)
        {
            // 열
            if(PASSENGER[i].x < n_PASSENGER.x)
            {
                n_PASSENGER.x = PASSENGER[i].x;
                n_PASSENGER.y = PASSENGER[i].y;
                p_idx = i;
            }
            else if(PASSENGER[i].x == n_PASSENGER.x)
            {
                if(PASSENGER[i].y < n_PASSENGER.y)
                {
                    n_PASSENGER.x = PASSENGER[i].x;
                    n_PASSENGER.y = PASSENGER[i].y;
                    p_idx = i;
                }
            }
        }
    }

    // 승객 태우러 이동
    CAR.x = n_PASSENGER.x;
    CAR.y = n_PASSENGER.y;
    c -= min_length;

    if(c<0) return false;
    return true;
}
bool move()
{
    int len = BFS(n_PASSENGER, DEST[p_idx]);
    if(len==-1) return false;
    c -= len;
    if(c<0) return false;

    // 이동가능
    CAR.x = DEST[p_idx].x;
    CAR.y = DEST[p_idx].y;
    c += len * 2;
    
    n_PASSENGER.x = 0;
    n_PASSENGER.y = 0;
    PASSENGER[p_idx].x = 0;
    PASSENGER[p_idx].y = 0;
    DEST[p_idx].x = 0;
    DEST[p_idx].y = 0;
    remain_passenger--;

    return true;
}
int main()
{
    cin >> n >> m >> c;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> MAP[i][j];
        }
    }

    cin >> CAR.x >> CAR.y;
    for(int i=0; i<m; i++)
    {
        cin >> PASSENGER[i].x >> PASSENGER[i].y >> DEST[i].x >> DEST[i].y; 
    }

    remain_passenger = m;
    while(c>0)
    {
        // 가장 가까운 승객 찾기
        if(remain_passenger==0)
        {
            cout << c << "\n";
            break;
        }
        min_length = MAX_NUM;
        if(!findPassenger()){
            cout << "-1\n";
            break;
        }
        // 목적지까지 최단거리로 이동
        if(!move())
        {
            cout << "-1\n";
            break;
        }
    }
    
}