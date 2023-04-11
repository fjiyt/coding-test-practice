#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[30][30];
int MAP[30][30];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int group_cnt[1000];
int group_num[1000];
int neighbors[1000][1000];

//그룹으로 나누기. 그룹 내 멤버개수, 그룹을 이루는 숫자
int setMap() {
    int idx = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(MAP[i][j] == -1)
            {
                MAP[i][j] = idx;
                group_num[idx] = arr[i][j];
                group_cnt[idx] = 1;

                //같은 그룹 찾기
                queue <pair<int,int>> q;
                q.push({i,j});
                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0; k<4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if((arr[nx][ny] == group_num[idx]) && MAP[nx][ny] == -1 ){
                            MAP[nx][ny] = idx;
                            group_cnt[idx]++;
                        }
                    }
                }

                idx++;
            }
        }
    }

    return idx;
}
void findNeighbors() {
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int s = MAP[i][j];
            for(int k=0; k<4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                int e = MAP[nx][ny];
                if(s!=e){
                    neighbors[s][e]++;
                }
            }
        }
    }
}
int cal(int cnt)
{
    int sum = 0;
    for(int i=0; i<cnt-1; i++)
    {
        for(int j=i+1; j<=cnt-1; j++) // j=i+1
        {
            if(i > j) continue;
            if(neighbors[i][j] > 0) {
                sum += (group_cnt[i] + group_cnt[j]) * group_num[i] * group_num[j] * neighbors[i][j];
                neighbors[j][i] = 0;
            }
        }
    }

    return sum;
}

void rotate()
{
    int new_arr[30][30];
    memset(new_arr, 0, sizeof(new_arr));
    int half = n/2;

    //가로
    int k = 0;
    for(int i=n-1; i>=0; i--)
    {
        new_arr[k++][half] = arr[half][i];
    }

    //세로 짜야됨


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==half || j==half) continue;
            new_arr[j][half-1-i] = arr[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            arr[i][j] = new_arr[i][j];
        }
    }

}
int main() {
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int total = 0;
    for(int i=0; i<3; i++)
    {
        //배열 초기화
        memset(MAP, -1, sizeof(MAP));
        memset(group_cnt,-1,sizeof(group_cnt));
        memset(group_num,0,sizeof(group_num));
        memset(neighbors,0,sizeof(neighbors));
        //구간 나누기
        int cnt = setMap();
        //인접 찾기
        findNeighbors();
        //계산
        total += cal(cnt);
        cout << i << " : " << total << "\n";
        //회전
        rotate();
    }

    cout << total << "\n";
    return 0;
}