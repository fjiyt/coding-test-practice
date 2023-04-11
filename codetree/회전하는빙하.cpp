#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, q;
int MAP[65][65];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
int tmp[65][65];
int total = 0;
int max_cnt = 0;
int Size = 0;

void Print()
{
    cout << "\n";
    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void Move(int s_row, int s_col, int dir, int half)
{
    for(int i=s_row; i<s_row+half; i++)
    {
        for(int j=s_col; j<s_col+half; j++)
        {
            int n_row = i + dx[dir]*half;
            int n_col = j + dy[dir]*half;

            tmp[n_row][n_col] = MAP[i][j];
        }
    }
}
void solve(int l)
{
    memset(tmp, 0, sizeof(tmp));
    
    int box = pow(2,l);
    int half = box/2;

    // 회전
    for(int i=0; i<Size; i+=box)
    {
        for(int j=0; j<Size; j+=box)
        {
            Move(i, j, 0, half);
            Move(i, j+half, 1, half);
            Move(i+half, j, 2, half);
            Move(i+half, j+half, 3, half);
        }
    }

    // 다시 배열에 넣기
    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
        {
            MAP[i][j] = tmp[i][j];
        }
    }
}

void melt()
{
    memset(tmp, 0, sizeof(tmp));

    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
        {
            int cnt=0;
            if(MAP[i][j]<=0) continue;
            for(int k=0; k<4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || ny < 0 || nx >= Size || ny >= Size) continue;
                if(MAP[nx][ny]>0) cnt++;
            }

            if(cnt<3) tmp[i][j] = MAP[i][j]-1;
            else tmp[i][j] = MAP[i][j];
        }
    }

    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
        {
            MAP[i][j] = tmp[i][j];
        }
    }
}
void total_glacier()
{
    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
        {
            total += MAP[i][j];
        }
    }

    cout << total << "\n";
}

void find_big_group()
{
    bool isVisited[Size][Size];
    memset(isVisited,0,sizeof(isVisited));

    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
        {
            if(isVisited[i][j]) continue;
            queue <pair<int,int>> q;
            q.push({i,j});
            int cnt=0;
            
            while(!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0; k<4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || ny < 0 || nx >= Size || ny >= Size) continue;
                    if(!isVisited[nx][ny])
                    {
                        isVisited[nx][ny] = true;
                        if(MAP[nx][ny]==0) continue;
                        q.push({nx,ny});
                        cnt++;
                    }
                }
            }

            max_cnt = max(max_cnt, cnt);
        }
    }

    cout << max_cnt << "\n";
}
int main()
{
    cin >> n >> q;
    Size = pow(2, n);
    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
        {
            cin >> MAP[i][j];
        }
    }
    while(q--)
    {
        int l;
        cin >> l;

        if(l) solve(l);

        melt();
    }

    total_glacier();
    find_big_group();
}