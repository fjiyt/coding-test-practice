#include <iostream>
#include <algorithm>
#include <stdbool.h>
#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 101

int arr[MAX][MAX] = {0,};
bool isVisited[MAX][MAX] = {false,};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int N;

void labeling(int a, int b, int rain)
{
    queue < pair <int, int> > que;
    que.push(make_pair(a,b));
    isVisited[a][b] = true;

    while (!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if(!isVisited[nx][ny] && arr[nx][ny] > rain)
                {
                    que.push(make_pair(nx,ny));
                    isVisited[nx][ny]=true;
                }
            }
        }
    }

}

int isSafeArea(int rain)
{
    memset(isVisited,0,sizeof(isVisited));

    int label = 1;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(!isVisited[i][j] && arr[i][j]>rain)
            {
                labeling(i,j,rain);
                label ++;
            }
        }
    }

    return label-1;
}

int main()
{
    cin >> N;

    int max_rain=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> arr[i][j];
            max_rain = max(max_rain, arr[i][j]);
        }
    }

    int max_area = 0;

    for(int i=0; i<=max_rain; i++)
    {
        max_area = max(max_area,isSafeArea(i));
    }

    cout << max_area << "\n";

    return 0;
}