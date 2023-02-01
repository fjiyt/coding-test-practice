#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX 2000

using namespace std;

queue < pair <int,int> > que;
queue <int> cost;
pair <int,int> cur;
pair <int,int> tmp;
bool isVisited[2000][2000]={false,};

void screen_to_clip(int time)
{
    if(cur.first > 0)
    {
        tmp.second = cur.first;
        tmp.first = cur.first;

        que.push(tmp);
        cost.push(time+1);
    }
    return;
}
void clip_to_screen(int time)
{
    tmp.first = cur.first + cur.second;
    tmp.second = cur.second;

    if(cur.second > 0 && tmp.first < MAX)
    {
        que.push(tmp);
        cost.push(time+1);
    }
    return;
}
void delete_emo(int time)
{
    if(cur.first > 0)
    {
        tmp.first = cur.first -1;
        tmp.second = cur.second;
        
        que.push(tmp);
        cost.push(time+1);
    }
    return;
}
void BFS(int S)
{
    int time=0; 
    memset(isVisited,0,sizeof(isVisited));

    que.push(pair <int, int> (1,0));
    cost.push(0);
    while(!que.empty() && !cost.empty())
    {
        cur = que.front();
        que.pop();
        time = cost.front();
        cost.pop();
        
        if(isVisited[cur.first][cur.second]) continue;
        isVisited[cur.first][cur.second]=true;

        if(cur.first == S)
        {
            cout << time << "\n";
            return;
        }
        //화면 이모티콘 모두 클립보드로 복사
        screen_to_clip(time); 
        //클립보드 모든 이모티콘 화면에 복사
        clip_to_screen(time);
        //화면에 있는 이모티콘 삭제
        delete_emo(time);
    }
}
int main()
{
    int S;
    cin >> S;

    BFS(S);

    return 0;
}