#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
// -1 : 검은색 돌, 0 : 빨간색 폭탄, 1~m : 빨간색과 다른 색 폭탄
int MAP[21][21];
bool isVisited[21][21];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
struct bomb{
    int x = -1;
    int y = 21;
    int red;
    int notRed;
    vector <pair<int,int>> bomb;
};
bomb B[401];
int cnt = 0;
bomb Remove;
int score = 0;

void Print()
{
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
void init_set()
{
    for(int i=0; i<401; i++)
    {
        B[i].notRed = 0;
        B[i].red = 0;
        B[i].x = -1;
        B[i].y = 21;
        B[i].bomb.clear();
    }
}
void find_set()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            isVisited[i][j] = false;
        }
    }

    // 폭탄묶음 초기화
    init_set();

    cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(isVisited[i][j]) continue;
            int color = MAP[i][j];
            if(color == -1 || color == -2){ isVisited[i][j] = true; continue; }
            if(color==0)
            {
                isVisited[i][j] = true;
                B[cnt].red++;
                B[cnt].bomb.push_back({i,j});
            }
            else if(color>=1){
                B[cnt].notRed++;
                isVisited[i][j] = true;
                B[cnt].x = i;
                B[cnt].y = j;
                B[cnt].bomb.push_back({i,j});
            }

            queue <pair<int,int>> q;
            q.push({i,j});

            while(!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                // cout << x << " " << y << "\n";
                for(int k=0; k<4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    // 빨간색이거나 같은색
                    if(!isVisited[nx][ny])
                    {
                        if(MAP[nx][ny]==-1 || MAP[nx][ny]==-2) { isVisited[nx][ny] = true; continue; }

                        if(color == 0){
                            if(MAP[nx][ny] >= 1)
                            {
                                // 기준점 찾기
                                if(B[cnt].x < nx)
                                {
                                    B[cnt].x = nx;
                                    B[cnt].y = ny;
                                }
                                else if(B[cnt].x == nx)
                                {
                                    if(B[cnt].y > ny)
                                    {
                                        B[cnt].y = ny;
                                    }
                                }
                                B[cnt].notRed++;
                                B[cnt].bomb.push_back({nx,ny});
                                color=MAP[nx][ny];
                                isVisited[nx][ny] = true;
                                q.push({nx,ny});
                            }
                            else if(MAP[nx][ny] == 0)
                            {
                                B[cnt].red++;
                                B[cnt].bomb.push_back({nx,ny});
                                q.push({nx,ny});
                                isVisited[nx][ny] = true;
                            }
                        }
                        else{
                            if(MAP[nx][ny] == color)
                            {
                                // 기준점 찾기
                                if(B[cnt].x < nx)
                                {
                                    B[cnt].x = nx;
                                    B[cnt].y = ny;
                                }
                                else if(B[cnt].x == nx)
                                {
                                    if(B[cnt].y > ny)
                                    {
                                        B[cnt].y = ny;
                                    }
                                }
                                B[cnt].notRed++;
                                B[cnt].bomb.push_back({nx,ny});

                                isVisited[nx][ny] = true;
                                q.push({nx,ny});
                            }
                            else if(MAP[nx][ny] == 0)
                            {
                                B[cnt].red++;
                                B[cnt].bomb.push_back({nx,ny});

                                q.push({nx,ny});
                                isVisited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
            // 폭탄 묶음 조건 성립 여부 확인

            // cout << cnt << " " <<  B[cnt].red << " + " << B[cnt].notRed <<  " " << B[cnt].bomb.size() << " " <<  B[cnt].x  <<" " << B[cnt].y<< "\n";
            if(B[cnt].x == -1 || B[cnt].y == 21 || B[cnt].notRed == 0 || B[cnt].red+B[cnt].notRed<2) 
            {
                B[cnt].x = -1;
                B[cnt].y = 21;
                B[cnt].notRed = 0;
                B[cnt].red = 0;
                B[cnt].bomb.clear();
                // cout << cnt << " " << B[cnt].red << " / " << B[cnt].notRed <<  " " << B[cnt].bomb.size() << "\n";

            }
            else cnt++;

            for(int l=0; l<n; l++)
            {
                for(int p=0; p<n; p++)
                {
                    if(MAP[l][p]==0 && isVisited[l][p])
                    {
                        isVisited[l][p] = false;
                    }
                }
            }
        }
    }  
}
void copy_set(bomb O)
{
    Remove.notRed = O.notRed;
    Remove.red = O.red;
    Remove.x = O.x;
    Remove.y = O.y;
    Remove.bomb.clear();

    // cout << "size : " << Remove.bomb.size()<< "\n";

    for(int i=0; i<O.bomb.size(); i++)
    {
        Remove.bomb.push_back({O.bomb[i].first, O.bomb[i].second});
    }

    // cout << "size2 : " << Remove.bomb.size()<< "\n";
}
void delete_set()
{
    for(int i=0; i<cnt; i++)
    {
        if(Remove.bomb.size() < B[i].bomb.size())
        {
            copy_set(B[i]);
        }
        else if(Remove.bomb.size() == B[i].bomb.size())
        {
            if(Remove.red > B[i].red)
            {
                copy_set(B[i]);
            }
            else if(Remove.red == B[i].red)
            {
                if(Remove.x < B[i].x)
                {
                    copy_set(B[i]);
                }
                else if(Remove.x == B[i].x)
                {
                    if(Remove.y > B[i].y)
                    {
                        copy_set(B[i]);
                    }
                }
            }
        }
    }

    // 삭제하기
    int tmp[n][n];
    
    for(int i=0; i<Remove.bomb.size(); i++)
    {
        int x = Remove.bomb[i].first;
        int y = Remove.bomb[i].second;
        tmp[x][y] = -2;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(tmp[i][j] == -2)
            {
                MAP[i][j] = tmp[i][j];
            }

        }
    }

    score += (Remove.notRed + Remove.red) * (Remove.notRed + Remove.red);

    // Remove 초기화
    Remove.x = -1;
    Remove.y = 21;
    Remove.notRed = 0;
    Remove.red = 0;
    Remove.bomb.clear();
}
void gravity()
{
    int tmp[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            tmp[i][j] = -2;
        }
    }
    // 바닥이거나 돌이랑 부딪히는 순간 멈춤
    for(int j=0; j<n; j++)
    {
        int empty = 0;
        for(int i=n-1; i>=0; i--)
        {
            if(MAP[i][j]==-2)
            {
                empty++;
            }
            else if(MAP[i][j] == -1)
            {
                empty = 0;
                tmp[i][j] = -1;
            }
            else if(MAP[i][j]>=0)
            {
                tmp[i+empty][j] = MAP[i][j];
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            MAP[i][j] = tmp[i][j];
        }
    }
}
void rotate()
{
    int tmp[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            tmp[i][j] = -2;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            tmp[n-1-j][i] = MAP[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            MAP[i][j] = tmp[i][j];
        }
    }

}
void solve()
{
    while(1)
    {
        // cout << "#0\n";
        // Print();
        //1. 묶음 폭탄 찾기 -> 없으면 종료
        find_set();
        // cout << "#1\n";
        // Print();
        if(cnt==0) break;
        //2. 폭탄 묶음에 해당되는 폭탄 제거
        delete_set();
        // cout << "#2\n";
        // Print();
        //3. 중력으로 폭탄 떨어짐
        gravity();
        // cout << "#3\n";
        // Print();
        //4. 반시계 90 회전
        rotate();
        // cout << "#4\n";
        // Print();
        //5. 중력으로 폭탄 떨어짐 
        gravity();
        // cout << "#5\n";
        // Print();

        // cout << "score : " << score << "\n";
    }

    cout << score << "\n";
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