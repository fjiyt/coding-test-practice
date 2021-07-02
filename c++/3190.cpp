#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N; // 보드의 크기
int arr[102][102] = {
    0,
}; // 몸이 있으면 : 1, 사과 있으면 : 2, 둘다 아니면 : 0

int movingTime = 0; //걸리는 시간
pair<int, int> d;   //현재 방향
queue<pair<int, char>

      >
    rotation; //회전에 대한 시간과 방향
queue<pair<int, int>

      >
    location; //뱀이 있는 위치

void rotateDirection(char direction)
{
    //rotation이 있으면 이동하는 축이 바뀜
    if (direction == 'L') //left
    {
        if (d.first == 1 || d.first == -1)
        {
            d.second = d.first;
            d.first = 0;
        }
        else if (d.second == 1 || d.second == -1)
        {
            d.first = d.second * (-1);
            d.second = 0;
        }
    }
    else if (direction == 'D') //right
    {
        if (d.first == 1 || d.first == -1)
        {
            d.second = d.first * (-1);
            d.first = 0;
        }
        else if (d.second == 1 || d.second == -1)
        {
            d.first = d.second;
            d.second = 0;
        }
    }
    return;
}
void snailMoving(int x, int y)
{
    location.push(make_pair(x, y));
    while (!location.empty())
    {
        if (movingTime != 0)
        {
            int t = rotation.front().first;
            if (t == movingTime)
            {
                int d = rotation.front().second;
                rotation.pop();
                rotateDirection(d);
            }
        }
        movingTime++;
        x += d.first;
        y += d.second;
        if ((arr[x][y] == 1) || x > N || y > N || x <= 0 || y <= 0)
        {
            cout << movingTime << "\n";
            return;
        }
        location.push(make_pair(x, y));
        //사과 있을경우
        if (arr[x][y] == 2)
        {
            arr[x][y] = 1;
        }
        //사과 없을경우
        else if (arr[x][y] == 0)
        {
            arr[x][y] = 1;
            int t_x = location.front().first;
            int t_y = location.front().second;
            location.pop();
            arr[t_x][t_y] = 0; //꼬리 없애기
        }
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, L;
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 2; //사과있으면 2
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int time;
        char direction;
        cin >> time >> direction;
        rotation.push(make_pair(time, direction));
    }
    //처음에는 y 좌표만 증가
    d.first = 0;  // x
    d.second = 1; // y
    snailMoving(1, 1);

    return 0;
}