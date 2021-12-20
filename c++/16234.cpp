#include <iostream>
#include <vector>
#include <stdbool.h>
#include <queue>
#include <stdlib.h>
#include <string.h>

#define MAX 50

using namespace std;

int A[MAX][MAX] = {
    0,
};
bool isVisited[MAX][MAX] = {
    false,
};
int days = 0;
int N, L, R;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool check = true; // 인구이동 가능여부

void bfs(int a, int b)
{
    queue<pair<int, int>> que, new_que;
    isVisited[a][b] = true;
    que.push(make_pair(a, b));
    new_que.push(make_pair(a, b));

    int total = 0;
    int cnt = 0;

    while (!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        total += A[x][y];
        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
                if (!isVisited[nx][ny] && abs(A[x][y] - A[nx][ny]) >= L && abs(A[x][y] - A[nx][ny]) <= R)
                {
                    que.push(make_pair(nx, ny));
                    new_que.push(make_pair(nx, ny));
                    isVisited[nx][ny] = true;
                }
            }
        }
    }

    int value = total / cnt;

    while (!new_que.empty())
    {
        int x = new_que.front().first;
        int y = new_que.front().second;
        new_que.pop();
        A[x][y] = value;
    }

    return;
}
bool canMove(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N)
        {
            if (L <= abs(A[x][y] - A[nx][ny]) && abs(A[x][y] - A[nx][ny]) <= R)
                return true;
        }
    }

    return false;
}
void solve()
{
    while (check)
    {
        check = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!isVisited[i][j] && canMove(i, j))
                {
                    check = true;
                    bfs(i, j);
                }
            }
        }
        if (check)
        {
            days++;
        }
        memset(isVisited, false, sizeof(isVisited));
    }

    cout << days << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    solve();
    return 0;
}