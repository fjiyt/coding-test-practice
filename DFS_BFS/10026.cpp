#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
char arr[101][101];
int N;
bool isVisited[101][101] = {{false,},};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void notColorWeakness(int x, int y)
{
    queue <pair<int,int>> q;
    q.push({x,y});
    isVisited[x][y] = true;
    char color = arr[x][y];
    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
            if(!isVisited[nx][ny] && arr[nx][ny]==color){
                isVisited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void colorWeakness(int x, int y)
{
    queue <pair<int,int>> q;
    q.push({x,y});
    isVisited[x][y] = true;
    char color = arr[x][y];
    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
            if(!isVisited[nx][ny]){
                if(color == 'R' || color == 'G')
                {
                    if(arr[nx][ny]=='B') continue;
                }
                else{
                    if(arr[nx][ny] != color) continue;
                }
                isVisited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}
int main()
{
    cin >> N;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> arr[i][j];
        }
    }

    int n1 = 0, n2 = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(!isVisited[i][j])
            {
                notColorWeakness(i,j);
                n1++;
            }
        }
    }
    
    memset(isVisited, 0, sizeof(isVisited));

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(!isVisited[i][j])
            {
                colorWeakness(i,j);
                n2++;
            }
        }
    }

    cout << n1 << " " << n2 << "\n";
}