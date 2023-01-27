#include <iostream>

using namespace std;
int R,C;
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int arr[21][21];
bool isVisited[21][21];
bool alphabet[26];
int max_cnt;

void solve(int x, int y, int cnt)
{
    if(max_cnt < cnt) {
        max_cnt = cnt;
    }
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || nx > R || ny < 1 || ny > C) continue;
        if(!alphabet[arr[nx][ny]-65] && !isVisited[nx][ny])
        {
            isVisited[nx][ny] = true;
            alphabet[arr[nx][ny]-65]=true;
            solve(nx,ny,cnt+1);
            isVisited[nx][ny] = false;
            alphabet[arr[nx][ny]-65]=false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for(int i=1; i<=R; i++)
    {
        string str;
        cin >> str;
        for(int j=1; j<=C; j++)
        {
            arr[i][j] = str[j-1];
        }
    }
    alphabet[arr[1][1]-65] = true;
    isVisited[1][1] = true;
    solve(1,1,1);
    cout << max_cnt << "\n";
}