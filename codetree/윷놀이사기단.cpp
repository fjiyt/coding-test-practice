#include <iostream>
#include <vector>

#define MAX_POS 45
#define NUM_MOVEMENTS 10
#define NUM_PLAYER 4
#define START 0
#define END 20

using namespace std;

int MAP[MAX_POS] = {
    0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,0,
    13,16,19,0,0,
    22,24,0,0,0,
    28,27,26,0,0,
    0,0,0,0,0,
    25,30,35,40
};

int move_cnt[NUM_MOVEMENTS];
int max_score = 0;
int cur_pos[NUM_PLAYER];

bool isBlue(int pos)
{
    if(pos!=START && pos % 5 == 0)
    {
        return true;
    }

    return false;
}
int getNextPos(int cur, int length)
{
    if(length == 0) return cur;
    if(cur==END) return END;

    int next_pos = cur + 1;
    if(cur==23 || cur==27 || cur==33) next_pos = 41;
    else if(cur==19) next_pos = 44;
    else if(cur==44) next_pos = END;

    return getNextPos(next_pos, length-1);
}

bool isOverlap()
{
    for(int i=0; i<NUM_PLAYER; i++)
    {
        for(int j=i+1; j<NUM_PLAYER; j++)
        {
            if(cur_pos[i]==cur_pos[j] && cur_pos[i]!=START && cur_pos[i]!=END) return true;
        }
    }

    return false;
}
void solve(int round, int score)
{
    if(round == NUM_MOVEMENTS)
    {
        if(max_score < score)
        {
            max_score = score;
        }
        return;
    }

    for(int i=0; i<NUM_PLAYER; i++)
    {
        if(cur_pos[i]==END) continue;

        int temp = cur_pos[i];

        // 파란색 루트인 경우
        if(isBlue(cur_pos[i]))
        {
            cur_pos[i] = getNextPos(cur_pos[i]+16, move_cnt[round]-1);
        }
        // 일반 루트인 경우
        else
        {
            cur_pos[i] = getNextPos(cur_pos[i], move_cnt[round]);
        }

        // 겹치는지 확인
        if(!isOverlap())
        {
            solve(round+1, score+MAP[cur_pos[i]]);
        }

        cur_pos[i] = temp;
    }
}
int main()
{
    for(int i=0; i<NUM_MOVEMENTS; i++)
    {
        cin >> move_cnt[i];
    }

    solve(0, 0);

    cout << max_score << "\n";
}