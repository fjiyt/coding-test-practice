#include <iostream>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <cstring>

using namespace std;

string wheel[4];

queue<
    pair<int, int> >
    moves;

void move_wheel()
{
    while (!moves.empty())
    {
        int order = moves.front().first;
        int direction = moves.front().second;

        moves.pop();

        char tmp;
        switch (direction)
        {
        case 1:

            tmp = wheel[order][7];
            for (int i = 7; i > 0; i--)
            {
                wheel[order][i] = wheel[order][i - 1];
            }
            wheel[order][0] = tmp;

            break;

        case -1:
            tmp = wheel[order][0];
            for (int i = 0; i < 7; i++)
            {
                wheel[order][i] = wheel[order][i + 1];
            }
            wheel[order][7] = tmp;
            break;
        }
    }
}
void solution(int order, int direction)
{
    //앞 톱니바퀴
    int prev = order - 1;
    int now = order;
    int now_vector = direction;
    while (prev >= 0)
    {
        if (wheel[prev][2] == wheel[now][6])
        {
            break;
        }
        else
        {
            now_vector *= -1;
            moves.push(make_pair(prev, now_vector));
            now = prev;
            prev--;
        }
    }
    //뒤 톱니바퀴
    int next = order + 1;
    now = order;
    now_vector = direction;
    while (next < 4)
    {
        if (wheel[now][2] == wheel[next][6])
        {
            break;
        }
        else
        {
            now_vector *= -1;
            moves.push(make_pair(next, now_vector));
            now = next;
            next++;
        }
    }

    move_wheel();
}
int main()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> wheel[i];
    }
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int order, direction;

        cin >> order >> direction;

        moves.push(make_pair(order - 1, direction));
        solution(order - 1, direction);
    }

    int score = 0;
    for (int i = 0; i < 4; i++)
    {
        if (wheel[i][0] == '1')
        {
            score += pow(2, i);
        }
    }

    cout << score << "\n";
    return 0;
}