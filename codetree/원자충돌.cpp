#include <iostream>
#include <vector>

using namespace std;

struct pos
{
    // 질량, 속력, 방향
    int m;
    int s;
    int d;
};

int n, m, k;
vector<pos> MAP[51][51];
vector<pos> tmp[51][51];
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

int total = 0;

void Print()
{
    cout << "\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << MAP[i][j].size() << " ";
        }
        cout << "\n";
    }
}
void tmp_init()
{
    // tmp 초기화
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            tmp[i][j].clear();
        }
    }
}
void Move()
{
    tmp_init();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int s = MAP[i][j].size();
            for(int k=0; k<s; k++)
            {
                int weight = MAP[i][j][k].m;
                int speed = MAP[i][j][k].s;
                int dir = MAP[i][j][k].d;

                int nx = (((i + dx[dir]*speed)%n)+n)%n;
                int ny = (((j + dy[dir]*speed)%n)+n)%n;

                tmp[nx][ny].push_back({weight, speed, dir});
            }
        }
    }

    // 복사
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            MAP[i][j].clear();
            int s = tmp[i][j].size();
            for(int k=0; k<s; k++)
            {
                MAP[i][j].push_back(tmp[i][j][k]);
            }
        }
    }
}
void Combine()
{
    tmp_init();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int s = MAP[i][j].size();
            if(s>=2)
            {
                // 합성
                int total_weight = 0;
                int total_speed = 0;
                bool isDiagonal = (MAP[i][j][0].d)%2 ? true : false;
                bool setDiagonal = false;
                for(int k=0; k<s; k++)
                {
                    total_weight += MAP[i][j][k].m;
                    total_speed += MAP[i][j][k].s;
                    
                    if(!setDiagonal)
                    {
                        if(isDiagonal == MAP[i][j][k].d % 2) setDiagonal = false;
                        else setDiagonal = true;
                    }
                }

                //분해
                int weight = total_weight/5;
                int speed = total_speed/s;
                if(weight > 0) {
                    // 상하좌우
                    if(!setDiagonal)
                    {
                        for(int k=0; k<=6; k+=2)
                        {
                            pos p;
                            p.m = weight;
                            p.s = speed;
                            p.d = k;
                            tmp[i][j].push_back(p);
                        }
                    }
                    else{
                        for(int k=1; k<=7; k += 2)
                        {
                            pos p;
                            p.m = weight;
                            p.s = speed;
                            p.d = k;
                            tmp[i][j].push_back(p);
                        }
                    }
                } 
            }
            else if(s==1)
            {
                tmp[i][j].push_back(MAP[i][j][0]);
            }
        }
    }

    // 복사
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            MAP[i][j].clear();
            int s = tmp[i][j].size();
            for(int k=0; k<s; k++)
            {
                MAP[i][j].push_back(tmp[i][j][k]);
            }
        }
    }

}
void Calculate()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int s = MAP[i][j].size();
            for(int k=0; k<s; k++)
            {
                total += MAP[i][j][k].m;
            }
        }
    }

    return;
}
void solve()
{
    while(k--)
    {
        //각 원소 이동
        Move();
        //2개 이상의 원자 합성 & 나누기
        Combine();
    }

    //질량 합 구하기
    Calculate();
    cout << total << "\n";

    return;
}
int main()
{
    cin >> n >> m >> k;
    for(int i=0; i<m; i++)
    {
        int x, y, m, s, d;
        cin >> x >> y >> m >> s >> d;
        pos p;
        p.m = m;
        p.s = s;
        p.d = d;
        MAP[x-1][y-1].push_back(p);
    }

    solve();
}