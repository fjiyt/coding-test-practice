#include <iostream>
#include <cstring>

using namespace std;

int n;
int MAP[500][500];
int r[4][5][5] =
{
    {
        {0,0,2,0,0},
        {0,10,7,1,0},
        {5,0,0,0,0},
        {0,10,7,1,0},
        {0,0,2,0,0}
    },
    {
        {0,0,0,0,0},
        {0,1,0,1,0},
        {2,7,0,7,2},
        {0,10,0,10,0},
        {0,0,5,0,0}
    },
    {
        {0,0,2,0,0},
        {0,1,7,10,0},
        {0,0,0,0,5},
        {0,1,7,10,0},
        {0,0,2,0,0}
    },
    {
        {0,0,5,0,0},
        {0,10,0,10,0},
        {2,7,0,7,2},
        {0,1,0,1,0},
        {0,0,0,0,0}
    }
};
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int answer = 0;

void Print()
{
    cout << "\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool InRange(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}
void clean(int x, int y, int dir)
{
    int total_dust = MAP[x][y];
    int remain_dust = MAP[x][y];
    MAP[x][y] = 0;

    // % 배열 상 좌표
    // 실제 MAP 좌표
    for(int i=-2; i<=2; i++)
    {
        for(int j=-2; j<=2; j++)
        {
            if(i==0 && j==0) continue;
            int px = i+2;
            int py = j+2;

            int mx = x+i;
            int my = y+j;

            int move_dust = total_dust * r[dir][px][py]/100;
            remain_dust -= move_dust;
            if(!InRange(mx,my)) {
                answer += move_dust;
                continue;
            }
            
            MAP[mx][my] = MAP[mx][my] + move_dust;
        }
    }
    int mx = x + dx[dir];
    int my = y + dy[dir];
    if(!InRange(mx,my)) {
        answer += remain_dust;
        return;
    }
    MAP[mx][my] += remain_dust;

}
void solve()
{
    int x = n/2;
    int y = n/2;

    int dir = 0;
    int total = 1;
    while(x || y)
    {
        if(x==0 && y==0) break;
        for(int i=0; i<total; i++)
        {
            x += dx[dir];
            y += dy[dir];
            clean(x,y,dir);
            if(x==0 && y==0) break;
        }

        dir = (dir+1) % 4;
        if(dir%2==0) total ++;
    }
    cout << answer << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> MAP[i][j];
        }
    }

    solve();
}