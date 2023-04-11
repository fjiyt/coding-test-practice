#include <iostream>
#include <vector>

using namespace std;

int m, t;
// 몬스터 저장, 방향 입력
vector<int> MAP[4][4];
// 알 저장, 방향 입력
vector<int> baby[4][4];
// 시체 저장, 턴수를 입력
vector<int> ghost[4][4];

struct pos{
    int x, y;
};

pos pacman;
int p_dx[] = {-1,0,1,0};
int p_dy[] = {0,-1,0,1};

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};

void copy_monster()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(MAP[i][j].size())
            {
                for(int k=0; k<MAP[i][j].size(); k++)
                {
                    baby[i][j].push_back(MAP[i][j][k]);
                }
            }
        }
    }
}
void move_monster()
{
    //복사본
    vector <int> tmp[4][4];

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(MAP[i][j].size()>0){
                for(int p=0; p<MAP[i][j].size(); p++)
                {
                    bool isMove = false;
                    int cnt = 0;
                    int d_idx = MAP[i][j][p];
                    while(cnt<8)
                    {
                        if(d_idx >= 8) d_idx = 0;
                        int nx = i + dx[d_idx];
                        int ny = j + dy[d_idx];
                        //격자 벗어나는 경우
                        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {d_idx++; cnt++; continue;}
                        //시체 있는 경우
                        if(ghost[nx][ny].size() > 0) {d_idx++; cnt++; continue;}
                        //팩맨 있는 경우
                        if(pacman.x == nx && pacman.y == ny) {d_idx++; cnt++; continue;}

                        //몬스터 이동
                        tmp[nx][ny].push_back(d_idx);
                        isMove = true;

                        break;
                    }

                    // 8번 동안 이동 못하면
                    if(!isMove)
                    {
                        tmp[i][j].push_back(MAP[i][j][p]);
                    }
                }
            }
        }
    }

    //원본에 복사
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            MAP[i][j].clear();
            if(tmp[i][j].size() > 0)
            {
                for(int k=0; k<tmp[i][j].size(); k++)
                {
                    MAP[i][j].push_back(tmp[i][j][k]);
                    cout << i << " " << j << " " << tmp[i][j][k] << "\n";
                }
            }
        }
    }
}

void eat(int d_arr[3])
{
    int x = pacman.x,  y = pacman.y;
    for(int i=0; i<3; i++)
    {
        x += p_dx[i];
        y += p_dy[i];
        if(MAP[x][y].size() > 0) {
            for(int i=0; i<MAP[x][y].size(); i++)
            {
                ghost[x][y].push_back(1);
            }
        }
        MAP[x][y].clear();
    }
}
void move_pacman()
{
    int ghosts = 0;
    int x, y;
    int max_num = 0;

    int s_x = -1, s_y = -1;
    // 이동 방향 저장
    int d_arr[3];

    for(int i=0; i<4; i++)
    {
        //첫번째 이동
        x = pacman.x + p_dx[i];
        y = pacman.y + p_dy[i];
        ghosts = MAP[x][y].size();
        for(int j=0; j<4; j++)
        {
            x += p_dx[j];
            y += p_dy[j];
            ghosts += MAP[x][y].size();
            for(int k=0; k<4; k++)
            {
                x += p_dx[k];
                y += p_dy[k];
                ghosts += MAP[x][y].size();

                if(max_num < ghosts){
                    s_x = x;
                    s_y = y;
                    max_num = ghosts;
                    d_arr[0] = i;
                    d_arr[1] = j;
                    d_arr[2] = k;
                }
            }
        }
    }

    eat(d_arr);
}
void remove_ghost()
{
    vector <int> tmp[4][4];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(ghost[i][j].size() > 0)
            {
                for(int k=0; k<ghost[i][j].size(); k++)
                {
                    if(ghost[i][j][k]==2) {
                        continue;
                    }
                    else if(ghost[i][j][k]==1){
                        tmp[i][j].push_back(ghost[i][j][k]+1);
                    }
                }
            }
        }
    }

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            ghost[i][j].clear();
            if(tmp[i][j].size() > 0)
            {
                for(int k=0; k<tmp[i][j].size(); k++){
                    ghost[i][j].push_back(tmp[i][j][k]);
                }
            }
        }
    }
}

void birth_monster()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(baby[i][j].size() > 0)
            {
                for(int k=0; k<baby[i][j].size(); k++)
                {
                    MAP[i][j].push_back(baby[i][j][k]);
                }
            }
            baby[i][j].clear();
        }
    }
}

int count_monster()
{
    int cnt = 0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cnt += MAP[i][j].size();
        }
    }

    return cnt;
}
void solve()
{
    int cnt = 0;
    while(cnt < t)
    {
        //1. 몬스터 복제 시도
        copy_monster();
        //2. 몬스터 이동
        move_monster();
        //3. 팩맨 이동
        move_pacman();
        //4. 몬스터 시체 소멸
        remove_ghost();
        //5. 몬스터 복제 완성
        birth_monster();
        cnt++;
    }

    // 몬스터 개수 세기
    cout << count_monster() << "\n";

}
int main()
{
    cin >> m >> t;
    cin >> pacman.x >> pacman.y;
    for(int i=0; i<m; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        MAP[x-1][y-1].push_back(d-1);
    }

    solve();
}