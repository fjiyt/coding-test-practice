#include <iostream>
#include <stdbool.h>
#include <queue>
#include <utility>
#include <cstdlib>

using namespace std;

int d[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int arr[21][21] = {
    0,
};
int N;
int total_fish;
int move_time;
queue<
    pair<int, int>

    >
    q;

struct shark
{
    int x;
    int y;
    int size;
};

void bfs(shark s, int cnt)
{
    q.push(make_pair(s.x, s.y));
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        //cout << s.x << s.y << "\n";
        q.pop();
        // if (arr[s.x][s.y] != 9)
        //   move_time++;
        if (arr[x][y] > 0 && arr[x][y] != 9)
        {
            cnt++;
            total_fish--;
            move_time += abs(s.x - x) + abs(s.y - y);
            s.x = x;
            s.y = y;
            arr[s.x][s.y] = 0;
        } // 물고기 먹기
        if (cnt == s.size)
        {
            cnt = 0;
            s.size++;
        }
        if (total_fish == 0)
        {
            cout << move_time << "\n";
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + d[i][0];
            int new_y = y + d[i][1];

            if (new_x < N && new_y < N && new_x >= 0 && new_y >= 0 && arr[new_x][new_y] < s.size)
            {
                q.push(make_pair(new_x, new_y));
            }
        }
    }
}
int main()
{
    cin >> N;
    shark s;
    total_fish = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 9)
            {
                s.x = i;
                s.y = j;
                s.size = 2;
            }
            else if (arr[i][j] > 0)
            {
                total_fish++;
            }
        }
    }

    move_time = 0;
    int cnt = 0;
    bfs(s, cnt);

    return 0;
}

//bfs
