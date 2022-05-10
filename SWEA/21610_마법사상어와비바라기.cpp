#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector <vector<int> > arr(51, vector<int>(51,-1));
vector <pair<int,int> > Move;
vector <vector<bool> > Cloud(51, vector<bool>(51,0));
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};
void moveCloud(int dir, int total)
{
    vector <vector<bool> > tmp(51, vector<bool>(51,0));
    int x=0, y=0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(Cloud[i][j]){
                x = j+dx[dir]*total;
                y = i+dy[dir]*total;

                if(y<=0) y += N;
                if(x<=0) x += N;
                if(y>N) y-=N;
                if(x>N) x-=N;

                tmp[y][x] = 1;
                arr[y][x]++;
            }
        }
    }
    Cloud.erase();
    Cloud.assign(tmp.begin(), tmp.end());
}
void checkDiag()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(Cloud)
        }
    }
}
void isMoreTwo()
{
    vector <pair<int,int>> tmp;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            
        }
    }
}
void solve()
{
    for(int i=0; i<Move.size(); i++)
    {
        int direction = Move[i].first;
        int total = Move[i].second;

        moveCloud(direction, total);
        checkDiag();
        isMoreTwo();
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j=N; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<M; i++)
    {
        int direction, cnt;
        cin >> direction >> cnt;
        Move.push_back(make_pair(direction, cnt));
    }
    Cloud[N][1]=1;
    Cloud[N][2]=1;
    Cloud[N-1][1]=1;
    Cloud[N-1][2]=1;
    solve();
}