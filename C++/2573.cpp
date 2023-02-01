#include <iostream>
#include <cstring>
#include <queue>
#define MAX 300

using namespace std;

int N, M;
int arr[MAX][MAX];
int new_arr[MAX][MAX];
bool isVisited[MAX][MAX] = {false,};
int year = 0;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int melt(int x, int y)
{
    int cnt = 0;
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx > N || ny < 0 || ny > M) continue;
        if(arr[nx][ny] == 0) cnt++;
    }
    return cnt;
}
void BFS(int a, int b)
{
    queue <pair<int,int>> q;
    q.push({a,b});
    isVisited[a][b] = true;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > N || ny < 0 || ny > M) continue;
            if(isVisited[nx][ny] == false && arr[nx][ny] != 0)
            {
                q.push({nx,ny});
                isVisited[nx][ny] = true;
            }
        }
    }
}
void solve()
{
    while(1)
    {
        memset(new_arr, 0, sizeof(new_arr));
        memset(isVisited, false, sizeof(isVisited));
        int islands = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if((arr[i][j] != 0) && isVisited[i][j] == false)
                {
                    BFS(i, j);
                    islands++;
                }
            }
        }
        if(islands >= 2){
            cout << year << "\n";
            break;
        }
        if(islands == 0){
            cout << "0\n";
            break;
        }
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(arr[i][j] > 0)
                {
                    new_arr[i][j] = arr[i][j] - melt(i,j);
                    if(new_arr[i][j] < 0) new_arr[i][j]=0;
                }
            }
        }
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                arr[i][j] = new_arr[i][j];
            }
        }
        year++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> arr[i][j];
        }
    }
    solve();
}