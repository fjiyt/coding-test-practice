#include <iostream>
#include <stack>

using namespace std;
int arr[17][17] = {
    0,
};
bool isVisited[17][17] = {
    false,
};
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};
int N;
int cnt = 0;
void dfs(int x, int y, int d)
{
    // d -> 0: 가로, 1: 세로, 2: 대각선
    if (x == N - 1 && y == N - 1)
    {
        cnt++;
        return;
    }

    isVisited[x][y] = true;
    for (int i = 0; i < 3; i++)
    {
        if (d == 0 && i == 1)
            continue;
        else if (d == 1 && i == 0)
            continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= N || ny >= N || nx < 0 || ny < 0)
            continue;
        if (i < 2) //가로세로일 경우
        {
            if (!arr[nx][ny] && !isVisited[nx][ny])
            {
                dfs(nx, ny, i);
                isVisited[nx][ny] = false;
            }
        }
        else
        {
            if (!arr[nx][ny] && !arr[nx][ny - 1] && !arr[nx - 1][ny] && !isVisited[nx][ny])
            {
                dfs(nx, ny, i);
                isVisited[nx][ny] = false;
            }
        }
    }
    return;
}
int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    dfs(0, 1, 0);
    cout << cnt << "\n";
}