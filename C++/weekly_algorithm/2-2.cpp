#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[] = {1,0};
int dy[] = {0,1};
bool isVisited[251][251];
bool isUsedDia = false;
int width, height;
int total = width * height + 1;
long long answer = 0;
vector <vector<int>> diagonals;

void dfs(int x, int y, int cnt)
{
    if(x==width && y==height)
    {
        answer++;
        return;
    }
        for(int i=0; i<2; i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || nx>width || ny<0 || ny>height) continue;
            if(!isVisited[nx][ny])
            {
                isVisited[nx][ny] = true;
                dfs(nx,ny,cnt+1);
                isVisited[nx][ny] = false;
            }
        }
        //대각선 확인
        for(int i=0; i<diagonals.size(); i++)
        {
            int nx=0,ny=0;
            if(isUsedDia) break;
            if(x==diagonals[i][0] && y==diagonals[i][1]) break;
            else if (x!=diagonals[i][0] && y!=diagonals[i][1]) continue;
            else if(x==diagonals[i][0] && y==diagonals[i][1]-1){
                ny = y+1;
                nx = x-1;
            }
            else if(x == diagonals[i][0]-1 && y==diagonals[i][1])
            {
                nx=x+1;
                ny=y-1;
            }
            if(nx>0 && ny>0 && !isVisited[nx][ny])
            {
                isUsedDia = true;
                isVisited[nx][ny] = true;
                dfs(nx,ny,cnt+1);
                isUsedDia = false;
                isVisited[nx][ny] = false;
            }
            
        }
}
int solution() {
    dfs(0,0,0);
    answer %= 10000019;
    return answer;
}
int main()
{
    cin >> width >> height;
    for(int i=0; i<2; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        diagonals.push_back({n1, n2});
    }

    cout << solution() << "\n";
}