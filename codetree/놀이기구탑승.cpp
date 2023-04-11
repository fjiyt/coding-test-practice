#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector <vector<int>> bf(20*20+1);
vector <int> order(n*n);
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int MAP[21][21]= {{0,},};
struct pos{
    int x = 21;
    int y = 21;
    int friends=0;
    int empty=0;
};
int score = 0;

void get_position(int idx)
{
    int s = order[idx];
    pos P;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(MAP[i][j]>0) continue;
            int friend_cnt=0, empty=0;
            for(int k=0; k<4; k++)
            {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                if(!MAP[nx][ny]) {empty++; continue;}
                for(int l=0; l<4; l++)
                {
                    if(MAP[nx][ny] == bf[s][l]) {
                        friend_cnt++;
                        break;
                    }
                }
            }

            if(P.friends < friend_cnt){
                P.friends = friend_cnt;
                P.empty = empty;
                P.x = i;
                P.y = j;
            }
            else if(P.friends == friend_cnt) {
                // 빈칸 많은 곳
                if(P.empty < empty)
                {
                    P.friends = friend_cnt;
                    P.empty = empty;
                    P.x = i;
                    P.y = j;
                }
                else if(P.empty == empty)
                {
                    //행번호 작은곳
                    if(P.x > i)
                    {
                        P.friends = friend_cnt;
                        P.empty = empty;
                        P.x = i;
                        P.y = j;
                    }
                    else if(P.x == i)
                    {
                        if(P.y > j)
                        {
                            P.friends = friend_cnt;
                            P.empty = empty;
                            P.x = i;
                            P.y = j;
                        }
                    }
                }
            }
        }
    }

    MAP[P.x][P.y] = s;
}
void calculate()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int s = MAP[i][j];
            int cnt = 0;
            for(int k=0; k<4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx<0 || ny<0 || nx>=n|| ny>=n) continue;
                for(int l=0; l<4; l++)
                {
                    if(MAP[nx][ny]==bf[s][l]) cnt++;
                }
            }
            if(cnt>0) score += pow(10,cnt-1);
        }
    }
}
void solve()
{
    int first = order[0];
    MAP[1][1] = first;
    for(int i=1; i<n*n; i++)
    {
        get_position(i);
    }

    calculate();
    cout << score << "\n";
}
int main()
{
    cin >> n;
    for(int i=0; i<n*n; i++)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        order.push_back(a);
        bf[a].push_back(b);
        bf[a].push_back(c);
        bf[a].push_back(d);
        bf[a].push_back(e);
    }

    solve();
}