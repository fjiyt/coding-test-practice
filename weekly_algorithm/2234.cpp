#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;
int arr[51][51];
int cost[51][51];
int roomSize[2501];
int cnt = 1;
int maxRoomSize;
int maxSum;

void countRoom(int s1, int s2)
{
    queue <pair<int,int>> que;

    que.push({s1,s2});
    cost[s1][s2] = cnt;
    while(!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        roomSize[cnt]++;
        que.pop();

        // 왼쪽 벽
        if((arr[x][y] & 1) == 0 && !(cost[x][y-1]))
        {
            que.push({x,y-1});
            cost[x][y-1] = cnt;
        }
        // 위쪽 벽
        if((arr[x][y] & 2) == 0 && !(cost[x-1][y]))
        {
            que.push({x-1, y});
            cost[x-1][y] = cnt;
        }
        // 오른쪽 벽
        if((arr[x][y] & 4) == 0 && !(cost[x][y+1]))
        {
            que.push({x, y+1});
            cost[x][y+1] = cnt;
        }
        // 아래 벽
        if((arr[x][y] & 8) == 0 && !(cost[x+1][y]))
        {
            que.push({x+1, y});
            cost[x+1][y] = cnt;
        }
    }
}
void solve()
{
    // 이 성에 있는 방의 개수 (cnt-1)
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(!cost[i][j]) {
                countRoom(i,j);
                cnt++;
            }
        }
    }

    //가장 넓은 방의 넓이(maxRoomSize)
    for(int i=1; i<cnt; i++)
    {
        maxRoomSize = max(maxRoomSize, roomSize[i]);
    }

    //하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N-1; j++)
        {
            if(cost[i][j] != cost[i][j+1])
            {
                int sum = roomSize[cost[i][j]] + roomSize[cost[i][j+1]];
                maxSum = max(maxSum, sum);
            }
        }
    }

    for(int j=0; j<N; j++)
    {
        for(int i=0; i<M-1; i++)
        {
            if(cost[i][j] != cost[i+1][j])
            {
                int sum = roomSize[cost[i][j]] + roomSize[cost[i+1][j]];
                maxSum = max(maxSum, sum);
            }
        }
    }

    cout << cnt-1 << "\n";
    cout << maxRoomSize << "\n";
    cout << maxSum << "\n";
}
int main()
{
    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> arr[i][j];
        }
    }

    solve();
}