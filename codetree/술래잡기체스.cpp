#include <iostream>
#include <tuple>

using namespace std;

#define N 4
#define CATCHER make_pair(-2,-2)
#define BLANK make_pair(-1,-1)

int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,-1,-1,-1,0,1,1,1};

pair<int,int> MAP[N][N]; // -1 : 빈공간, -2 : 술래있는 경우
int max_score = 0;

void Print()
{
    cout << "-----------------\n";
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << MAP[i][j].first << " ";
        }

        cout << "\n";
    }
    cout << "\n";

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << MAP[i][j].second << " ";
        }

        cout << "\n";
    }
    cout << "-----------------\n";
}
bool isDone(int x, int y, int dir)
{
    bool flag = true;
    
    for(int i=1; i<=N; i++)
    {
        int nx = x+dx[dir]*i;
        int ny = y+dy[dir]*i;
        if(nx >= 0 && ny >= 0 && nx < N && ny < N){
            if(MAP[nx][ny]!=BLANK)
            {
                flag = false;
                return flag;
            }
        }
    }
    return flag;
}
bool isFind(int x, int y, int dir)
{
    bool flag = false;
    if(x >= 0 && y >= 0 && x < N && y < N)
    {
        if(MAP[x][y]!=BLANK)
        {
            flag = true;
        }
    }
    return flag;
}
void move(int x, int y, int score, int dir)
{
    // 이동할수있는지 판단
    for(int i=0; i<8; i++)
    {
        int n_dir = (dir + i)%8;
        int nx = x + dx[n_dir];
        int ny = y + dy[n_dir];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(MAP[nx][ny]==CATCHER) continue;
        
        // swap
        MAP[x][y].second = n_dir;
        pair<int,int> tmp = MAP[nx][ny];

        MAP[nx][ny] = MAP[x][y];
        MAP[x][y] = tmp;
        return;
    }
    return;
}
tuple <int,int> findPos(int num)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(MAP[i][j].first == num)
            {
                return make_tuple(i,j);
            }
        }
    }
    return make_tuple(-1,-1);
}
void moveAll()
{
    for(int i=1; i<=N*N; i++)
    {
        int p,q;
        tie(p,q) = findPos(i);
        if(p==-1 && q==-1) continue;

        move(p,q,i,MAP[p][q].second);
    }
}
void DFS(int x, int y, int score, int dir)
{
    if(isDone(x,y,dir))
    {
        if(max_score < score)
        {
            max_score = score;
            return;
        }
    }

    for(int i=1; i<=N; i++)
    {
        int nx = x + dx[dir]*i;
        int ny = y + dy[dir]*i;
        if(!isFind(nx,ny,dir)) continue;

        pair<int,int> tmp[N][N];
        for(int j=0; j<N; j++)
        {
            for(int k=0; k<N; k++)
            {
                tmp[j][k] = MAP[j][k];
            }
        }

        int next_score, next_dir;
        tie(next_score, next_dir) = MAP[nx][ny];
        MAP[nx][ny] = CATCHER;
        MAP[x][y] = BLANK;
        // 도망자 이동
        moveAll();

        // 다음 탐색
        DFS(nx, ny, score+next_score, next_dir);

        for(int j=0; j<N; j++)
        {
            for(int k=0; k<N; k++)
            {
                MAP[j][k] = tmp[j][k];
            }
        }
    }
}
int main()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin >> MAP[i][j].first >> MAP[i][j].second;
            MAP[i][j].second--;
        }
    }

    // (0,0)에 있는 도둑말 잡기
    int num = MAP[0][0].first;
    int dir = MAP[0][0].second;
    MAP[0][0] = CATCHER;

    moveAll();

    DFS(0, 0, num, dir);

    cout << max_score << "\n";
}