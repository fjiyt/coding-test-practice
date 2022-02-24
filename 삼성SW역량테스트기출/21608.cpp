// 실패..
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N;
vector <int> v[404];
queue <int> order;
int maxFriendCnt;
int arr[22][22];
int score[22][22]; //친한친구 + 빈자리에 대한 점수
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int total;

void findFriend(int num, int x, int y)
{
    for(int i=0; i<4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if(newX < 1 || newX > N || newY < 1 || newY > N) continue;
        for(int j=0; j<v[num].size(); j++)
        {
            if(v[num][j] == arr[newX][newY])
            {
                score[x][y] += 100000;
            }
            else if(arr[newX][newY] == 0)
            {
                score[x][y] += 10000;
            }
        }
    }
}
void solve()
{
    while(!order.empty())
    {
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                score[i][j] = 0;
            }
        }
        int num = order.front();
        order.pop();

        //빈자리 찾기
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(arr[i][j]==0)
                {
                    findFriend(num, i, j);
                }
            }
        }

        //친구 많은 애들 중에 행,열 작은 애 고르기
        int maxScore=-1;
        int rx=0, ry=0;
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(score[i][j] > maxScore && arr[i][j] == 0)
                {
                    maxScore = score[i][j];
                    rx = i;
                    ry = j;
                }
            }
        }

        arr[rx][ry] = num;
    }

    //만족도 구하기
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            int num = arr[i][j];
            int cnt = 0;
            for(int k=0; k<4; k++)
            {
                int newX = i + dx[k];
                int newY = j + dy[k];

                if(newX < 1 || newX > N || newY < 1 || newY > N) continue;
                for(int l=0; l<v[num].size(); l++)
                {
                    if(v[num][l] == arr[newX][newY])
                    {
                        cnt++;
                    }
                }
            }
            if(cnt>0) total += pow(10, cnt-1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for(int i=0; i<pow(N,2); i++)
    {
        int num;
        cin >> num;
        order.push(num);

        for(int j=0; j<4; j++)
        {
            int node;
            cin >> node;
            v[num].push_back(node);
        }
    }

    solve();

    cout << total << "\n";
}