#include <iostream>
#include <vector>

using namespace std;
int n, m, k;
// MAP에 대한 정보
struct info{
    int player;
    int days=0;
};
//각 player에 대한 정보
struct pos {
    int x;
    int y;
    int num;
    int dir;
};

// 각각의 플레이어가 존재하는 곳 저장
vector <pos> Player(402);

info MAP[21][21];
info tmp[21][21];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int p_dir[402][4][4];

void Print()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << MAP[i][j].player << " ";
        }
        cout << "\n";
    }
    cout << "\n";

}
void move(int x, int y, int num)
{
    int now_d = Player[num].dir;
    int final_x = x;
    int final_y = y;
    int final_dir = now_d;
    // 아무도 독점하지 않은 땅 찾기
    for(int i=0; i<4; i++)
    {
        int new_d = p_dir[num][now_d][i];
        int nx = x+dx[new_d];
        int ny = y+dy[new_d];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(MAP[nx][ny].player==0 && MAP[nx][ny].days==0) {
            final_x = nx;
            final_y = ny;
            final_dir = new_d;
            break;
        }
    }
    // 위에서 못찾아서 이제 주위에 내가 독점한 땅 찾기
    if(final_x == x && final_y == y)
    {
        for(int i=0; i<4; i++)
        {
            int new_d = p_dir[num][now_d][i];
            int nx = x+dx[new_d];
            int ny = y+dy[new_d];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(MAP[nx][ny].player==num && MAP[nx][ny].days > 0)
            {
                final_x = nx;
                final_y = ny;
                final_dir = new_d;
                break;
            }
        }
    }

    //tmp 갱신
    if(tmp[final_x][final_y].player>0 && tmp[final_x][final_y].player!=num)
    {
        if(num > tmp[final_x][final_y].player) {
            Player[num].x = -1;
            Player[num].y = -1;
            return;
        }
        else{
            int before = tmp[final_x][final_y].player;
            // 죽음
            Player[before].x = -1;
            Player[before].y = -1;
        }
    }
    tmp[final_x][final_y].days = k;
    tmp[final_x][final_y].player = num;
    //최종 이동
    Player[num].x = final_x;
    Player[num].y = final_y;
    Player[num].num = num;
    Player[num].dir = final_dir;
}
void copy()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(MAP[i][j].days > 1)
            {
                MAP[i][j].days--;
            }
            else if(MAP[i][j].days==1)
            {
                MAP[i][j].days = 0;
                MAP[i][j].player = 0;
            }
            
            if(tmp[i][j].days > 0 && tmp[i][j].player > 0)
            {
                MAP[i][j].days = tmp[i][j].days;
                MAP[i][j].player = tmp[i][j].player;
            }
            
        }
    }
}
void solve()
{
    int total_days = 0;
    while(1)
    {
        total_days++;
        // tmp 초기화
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                tmp[i][j].days = 0;
                tmp[i][j].player = 0;
            }
        }
        
        //Player 이동
        int p = m;
        for(int i=1; i<=p; i++)
        {
            move(Player[i].x, Player[i].y, Player[i].num);
        }

        //tmp -> MAP 복사
        copy();

        if(Player[1].x == -1 && Player[1].y == -1)
        {
            cout << -1 << "\n";
            return;
        }
        else {
            bool flag = false;
            for(int i=2; i<=p; i++)
            {
                if(Player[i].x!=-1 || Player[i].y!=-1)
                {
                    flag = true;
                }
            }
            if(!flag) {
                cout << total_days << "\n";
                return;
            }
        }

        if(total_days>1000)
        {
            cout << -1 << "\n";
            return;
        }

    }
}
int main()
{
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int num;
            cin >> num;
            if(num==0)
            {
                MAP[i][j].player = 0;
            }
            else{
                MAP[i][j].player = num;
                MAP[i][j].days = k;

                pos P;
                P.num = num;
                P.x = i;
                P.y = j;

                Player[num] = P;
            }
        }
    }

    for(int i=1; i<=m; i++)
    {
        int d;
        cin >> d;
        Player[i].dir = d-1;
    }
    
    for(int i=1; i<=m; i++)
    {
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<4; k++)
            {
                int d;
                cin >> d;
                p_dir[i][j][k] = d-1;
            }
            
        }
    }

    solve();
}