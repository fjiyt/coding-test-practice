#include <iostream>
#include <queue>

using namespace std;

int arr[10][10];
int tmp_arr[10][10];
queue<

    pair<int, int>

    >
    que;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int N, M;
int max_cnt = 0;

void safe_count()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!tmp_arr[i][j])
            {
                cnt++;
            }
        }
    }

    max_cnt = max(max_cnt, cnt);
}
void BFS()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            tmp_arr[i][j] = arr[i][j];
        }
    }

    queue<
        pair<int, int>

        >
        tmp_que;
    tmp_que = que;
    //전염시키기
    while (!tmp_que.empty())
    {
        int x = tmp_que.front().first;
        int y = tmp_que.front().second;
        tmp_que.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < N && ny < M && nx >= 0 && ny >= 0 && !tmp_arr[nx][ny])
            {
                tmp_arr[nx][ny] = 2;
                tmp_que.push(make_pair(nx, ny));
            }
        }
    }
    //안전한 곳 찾기
    safe_count();
    return;
}
void make_wall(int cnt)
{
    if (cnt == 3)
    {
        BFS();
        return;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][j] = 1;
                make_wall(cnt + 1);
                arr[i][j] = 0;
            }
        }
    }
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                que.push(make_pair(i, j));
            }
        }
    }

    make_wall(0);
    cout << max_cnt << "\n";
}