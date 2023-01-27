/*
* DFS로 풀기
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char arr[25][25];
bool isVisited[25][25]={{false,},};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int cnt = 0;
vector <int> cntIslands;

void dfs(int x, int y)
{
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(!isVisited[nx][ny] && arr[nx][ny] == '1')
        {
            isVisited[nx][ny] = true;
            cnt++;
            dfs(nx, ny);
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

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(!isVisited[i][j] && arr[i][j] == '1')
            {
                isVisited[i][j] = true;
                cnt = 1;
                dfs(i,j);
                cntIslands.push_back(cnt);
            }
        }
    }

    cout << cntIslands.size() << "\n";
    sort(cntIslands.begin(), cntIslands.end());
    for(int i=0; i<cntIslands.size(); i++)
    {
        cout << cntIslands[i] << "\n";
    }
}