#include <iostream>
#include <vector>

using namespace std;

int arr[21][21] = {{
    0,
}};
int d[7] = {
    0,
};
int v[5][5] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int cur_x = 0, cur_y = 0; //현재 주사위의 위치

const int bottom = 6;
const int top = 1;
int N, M, order;

void dice_face(int vector)
{
    int t[7] = {
        0,
    };
    for (int i = 0; i < 7; i++)
    {
        t[i] = d[i];
    }
    switch (vector)
    {
    case 1:
        d[3] = t[1];
        d[6] = t[3];
        d[1] = t[4];
        d[4] = t[6];
        break;
    case 2:
        d[4] = t[1];
        d[1] = t[3];
        d[6] = t[4];
        d[3] = t[6];
        break;
    case 3:
        d[5] = t[1];
        d[1] = t[2];
        d[6] = t[5];
        d[2] = t[6];
        break;
    case 4:
        d[2] = t[1];
        d[6] = t[2];
        d[1] = t[5];
        d[5] = t[6];
        break;
    }
    return;
}
void dice_game(int vector)
{
    int move_x = v[vector][0];
    int move_y = v[vector][1];

    int tmp_x = cur_x + move_x;
    int tmp_y = cur_y + move_y;

    if (tmp_x < 0 || tmp_x >= N || tmp_y < 0 || tmp_y >= M)
    {
        return;
    }

    dice_face(vector);

    cur_x = tmp_x;
    cur_y = tmp_y;

    if (!arr[cur_x][cur_y])
    {
        arr[cur_x][cur_y] = d[bottom];
    }
    else
    {
        d[bottom] = arr[cur_x][cur_y];
        arr[cur_x][cur_y] = 0;
    }
    cout << d[top] << "\n";
    return;
}
int main()
{
    cin >> N >> M >> cur_x >> cur_y >> order;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < order; i++)
    {
        int vector;
        cin >> vector;

        dice_game(vector);
    }

    return 0;
}