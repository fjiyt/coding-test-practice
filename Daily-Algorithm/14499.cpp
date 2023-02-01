#include <iostream>
#include <vector>
using namespace std;

int arr[20][20] = {{
    0,
}};
int dice[6] = {
    0,
};
int v[5][5] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int top_x = 0, top_y = 0;
int bottom_x = 0, bottom_y = -2;
int cur_x = 0, cur_y = 0; //현재 주사위의 위치

int bottom = 1;
int top = 3;

void dice_face(int vector) //주사위의 위아래 면 설정
{
    int move_x = v[vector][0];
    int move_y = v[vector][1];

    if (move_x != 0 && !bottom_x)
    {
        bottom_y = 0;
    }
    if (move_y != 0 && !bottom_y)
    {
        bottom_x = 0;
    }
    bottom_x += move_x;
    bottom_y += move_y;

    //주사위의 범위를 넘을경우
    if (bottom_y < -2)
    {
        bottom_y = 1;
    }
    if (bottom_y > 1)
    {
        bottom_y = -2;
    }
    if (bottom_x < -1)
    {
        bottom_x = 1;
    }
    if (bottom_x > 1)
    {
        bottom_x = -1;
    }

    //top면 설정
    if (bottom_x != 0)
    {
        top_x = -1 * bottom_x;
    }
    if (bottom_y != 0)
    {
        top_y = -1 * bottom_y;
    }
    if (!bottom_x && !bottom_y)
    {
        top_x = 0;
        top_y = -2;
    }
}

void dice_game(int vector)
{
    int move_x = v[vector][0];
    int move_y = v[vector][1];
    dice_face(vector);

    //주사위 바닥면 숫자 설정
    int tmp_x = cur_x + move_x;
    int tmp_y = cur_y + move_y;

    if (arr[tmp_x][tmp_y] == -1) //지도 범위 벗어난 경우
    {
        return;
    }

    cur_x = tmp_x;
    cur_y = tmp_y;

        cout << arr[top_x][top_y] << "\n";
}
int main()
{
    int N, M, order;

    cin >> N >> M >> cur_x >> cur_y >> order;

    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < M + 1; j++)
        {
            if (j == M || i == N) //지도 바깥 처리
            {
                arr[i][j] = -1;
            }
            else
            {
                cin >> arr[i][j];
            }
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