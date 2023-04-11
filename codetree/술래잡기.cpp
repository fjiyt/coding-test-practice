/*
    1. 도망자 이동 -> runner에 저장
    2. 술래 이동 -> catcher에 저장
    3. 잡기 -> 술래 위치 포함 3칸내에 도망자가 있는지 runner에서 확인
    -> 그 도망자가 있는 위치에 나무도 있는지 확인 tree

    한칸에 도망자 여러명 가능
*/
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int n, m, h, k;
struct position{
    int x, y, d;
    bool reverse = false;
};

position catcher;
int length = 1;
int turn = 0;
int cur_length = 0;

// 상 우 하 좌
int c_dx[] = {-1,0,1,0};
int c_dy[] = {0,1,0,-1};
// 하 우 상 좌
int rc_dx[] = {1,0,-1,0};
int rc_dy[] = {0,1,0,-1};

vector <int> runner[101][101]; //catcher : 1 , runner : 2
vector <int> copy_runner[101][101];
int tree[101][101];

// 도망자 우 : 0, 좌 : 1, 상 : 2, 하 : 3
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};


void runner_move()
{
    //복사 배열 초기화
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            copy_runner[i][j].clear();
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            // 술래와의 거리가 3이하인지 확인
            if(abs(catcher.x-i) + abs(catcher.y-j) > 3) continue;
            if(runner[i][j].size())
            {
                for(int k=0; k<runner[i][j].size(); k++)
                {
                    int d = runner[i][j][k];
                    if(d==-1) continue;

                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    //격자 안벗어나는 경우
                    if(nx>0 && nx<=n && ny>0 && ny<=n)
                    {
                        if(catcher.x == nx && catcher.y == ny) continue;
                        else{
                            runner[i][j][k] = -1;
                            copy_runner[nx][ny].push_back(d);

                            // cout << nx << " " << ny << " " << d << "\n";
                        }
                    }
                    else{
                        if(d==0) d=1;
                        else if(d==1) d=0;
                        else if(d==2) d=3;
                        else if(d==3) d=2;

                        int nx = i + dx[d];
                        int ny = j + dy[d];

                        if(catcher.x == nx && catcher.y == ny) continue;
                        else{
                            runner[i][j][k] = -1;
                            copy_runner[nx][ny].push_back(d);

                            // cout << nx << " " << ny << " " << d << "\n";

                        }
                    }
                }
            }
        }
    }

    // cout << "---------\n";
    //복사
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(copy_runner[i][j].size() > 0)
            {
                for(int k=0; k<copy_runner[i][j].size(); k++)
                {
                    if(copy_runner[i][j][k]==-1) continue;
                    runner[i][j].push_back(copy_runner[i][j][k]);
                    // cout << "(i,j) : " << i << " " << j << "\n";
                }
            }
        }
    }
}

// 달팽이 모양
void catcher_move()
{
    //방향 바로바꾸기
    int d = catcher.d;
    if(catcher.reverse == 0) // 정방향
    {
        int nx = catcher.x + c_dx[d];
        int ny = catcher.y + c_dy[d];

        catcher.x = nx;
        catcher.y = ny;
        cur_length++;
    }
    else {
        int nx = catcher.x + rc_dx[d];
        int ny = catcher.y + rc_dy[d];

        catcher.x = nx;
        catcher.y = ny;
        cur_length++;
    }

    if(length == cur_length) { cur_length = 0; turn++; catcher.d++;}
    if(turn==2) {
        length++;
        turn = 0;
    }
    if(catcher.d == 4) catcher.d = 0;

    // cout << "catcher : " << catcher.x << " " << catcher.y << " " << catcher.d << "\n";
}

int touch()
{
    int cnt = 0;
    //술래 정방향
    if(catcher.reverse==0)
    {
        for(int i=0; i<3; i++)
        {
            int nx = catcher.x + c_dx[catcher.d]*i;
            int ny = catcher.y + c_dy[catcher.d]*i; 

            if(runner[nx][ny].size() > 0)
            {
                for(int j=0; j<runner[nx][ny].size(); j++)
                {
                    if(runner[nx][ny][j]!=-1) {
                        if(tree[nx][ny]==1) continue;
                        // cout << "catch1 : " << nx << " " << ny << "\n";
                        runner[nx][ny][j] = -1;
                        cnt++;
                    }
                }
            }
        }
    }
    //술래 역방향
    else{
        for(int i=1; i<=3; i++)
        {
            int nx = catcher.x + rc_dx[catcher.d]*i;
            int ny = catcher.y + rc_dx[catcher.d]*i; 

            if(runner[nx][ny].size() > 0)
            {
                for(int j=0; j<runner[nx][ny].size(); j++)
                {
                    if(runner[nx][ny][j]!=-1) {
                        if(tree[nx][ny]==1) continue;
                        // cout << "catch2 : " << nx << " " << ny << "\n";
                        runner[nx][ny][j] = -1;
                        cnt++;
                    }
                }
            }
        
        }
    }

    return cnt;
}

int solve()
{
    int cnt = 0;
    int cur_length = 0;
    int score = 0;
    while(cnt < k)
    {
        runner_move();

        //역방향으로 전환
        if(catcher.x == 1 && catcher.y == 1 && catcher.reverse == 0)
        {
            catcher.reverse = 1;
        } 
        //정방향으로 전환
        if(catcher.x == n/2 + 1 && catcher.y == n/2 + 1 && catcher.reverse == 1)
        {
            catcher.reverse = 0;
            length = 1;
            turn = 0;
            catcher.d = 0;
        }
        catcher_move();
        int people = touch();
        score += people * (cnt+1);

        // cout << people << " " << cnt << "\n";
        // cout << "--------\n";
        cnt++;
    }

    return score;
}
int main()
{
    cin >> n >> m >> h >> k;
    for(int i=0; i<m; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        if(d==1) runner[x][y].push_back(0);
        else runner[x][y].push_back(3);
    }
    for(int i=0; i<h; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x][y] = 1;
    }

    catcher.x = n/2 + 1;
    catcher.y = n/2 + 1;
    catcher.d = 0;

    cout << solve() << "\n";
}