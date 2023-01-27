/*
* BFS로 풀기
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
char arr[25][25];
vector <int> countIslands;
bool isVisited[25][25] = {{false,},};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void BFS(int x, int y)
{
    queue <pair<int,int>> que;
    int houses = 0;

    que.push({x,y});
    isVisited[x][y] = true;

    while(!que.empty()){
        x = que.front().first;
        y = que.front().second;
        que.pop();
        houses++;

        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(arr[nx][ny]=='1' && !isVisited[nx][ny])
            {
                isVisited[nx][ny] = true;
                que.push({nx,ny});
            }
        }
    }

    countIslands.push_back(houses);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
            if(!isVisited[i][j] && arr[i][j] == '1'){
                BFS(i,j);
            }
        }
    }

    sort(countIslands.begin(), countIslands.end());
    cout << countIslands.size() << "\n";
    for(int i=0; i<countIslands.size(); i++)
    {
        cout << countIslands[i] << "\n";
    }
}