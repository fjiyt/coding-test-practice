#include <iostream>
#define MAX 5

using namespace std;

int N, M;
int arr[MAX][MAX];
bool isVisited[MAX][MAX];
int ans;

int rightUp(int y, int x)
{
    return arr[y+1][x] + 2 * arr[y][x] + arr[y][x-1];
}
int rightDown(int y, int x)
{
    return arr[y-1][x] + 2 * arr[y][x] + arr[y][x-1];
}
int leftDown(int y, int x)
{
    return arr[y-1][x] + 2 * arr[y][x] + arr[y][x+1];
}
int leftUp(int y, int x)
{
    return arr[y+1][x] + 2 * arr[y][x] + arr[y][x+1];
}
void dfs(int y, int x, int sum)
{
    if(x==M)
    {
        x = 0;
        y++;
    }
    if(y==N)
    {
        ans = max(ans, sum);
        return;
    }
    if(!isVisited[y][x])
    {
        if(y+1 < N && x-1 >= 0 && !isVisited[y+1][x] && !isVisited[y][x-1])
        {
            isVisited[y][x] = true;
            isVisited[y+1][x] = true;
            isVisited[y][x-1] = true;
            int nsum = sum + rightUp(y,x);
            dfs(y,x+1,nsum);
            isVisited[y][x] = false;
            isVisited[y+1][x] = false;
            isVisited[y][x-1] = false;
        }
        if(y-1>=0 && x-1>=0 && !isVisited[y-1][x] && !isVisited[y][x-1])
        {
            isVisited[y][x] = true;
            isVisited[y-1][x] = true;
            isVisited[y][x-1] = true;
            int nsum = sum + rightDown(y,x);
            dfs(y,x+1,nsum);
            isVisited[y][x] = false;
            isVisited[y-1][x] = false;
            isVisited[y][x-1] = false;
        }
        if(y-1>=0 && x+1<M && !isVisited[y-1][x] && !isVisited[y][x+1])
        {
            isVisited[y][x] = true;
            isVisited[y-1][x] = true;
            isVisited[y][x+1] = true;
            int nsum = sum + leftDown(y,x);
            dfs(y,x+1,nsum);
            isVisited[y][x] = false;
            isVisited[y-1][x] = false;
            isVisited[y][x+1] = false;
        }
        if(y+1<N && x+1<M && !isVisited[y+1][x] && !isVisited[y][x+1])
        {
            isVisited[y][x] = true;
            isVisited[y+1][x] = true;
            isVisited[y][x+1] = true;
            int nsum = sum + leftUp(y,x);
            dfs(y,x+1,nsum);
            isVisited[y][x] = false;
            isVisited[y+1][x] = false;
            isVisited[y][x+1] = false;
        }
    }
    dfs(y,x+1,sum);
}
int main()
{
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> arr[i][j];
        }
    }

    if(N<2 && M<2)
    {
        cout << "0\n";
    }
    else{
        dfs(0,0,0);
        cout << ans << "\n";
    }
}