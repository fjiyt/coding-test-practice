#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
queue <pair<int,int>> que;
int cnt; // 대각선 이용횟수
int dx[] = {1,0};
int dy[] = {0,1};

int solution(int width, int height, vector<vector<int>> diagonals) {
    int answer = 0;
    que.push({0,0});
    while(!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        if(x==width && y==height){
            answer++;
            continue;
        }
        //대각선 확인
        int nx,ny;
        for(int i=0; i<diagonals.size(); i++)
        {
            if(cnt > 0) break;
            if(x==diagonals[i][0] && y==diagonals[i][1]) break;
            else if (x!=diagonals[i][0] && y!=diagonals[i][1]) continue;
            else if(x==diagonals[i][0]){
                ny = y+1;
                nx = x-1;
            }
            else if(y==diagonals[i][1])
            {
                nx=x+1;
                ny=y-1;
            }
            cnt++;
            que.push({nx,ny});
        }
        //dx, dy
        for(int i=0; i<2; i++)
        {
            nx = x+dx[i];
            ny = y+dy[i];
            if(nx<0 || nx>width || ny<0 || ny>height) continue;
            que.push({nx,ny});
        }
    }

    answer %= 10000019;
    return answer;
}
int main()
{
    int width, height;
    vector<vector<int>> diagonals;
    cin >> width >> height;
    for(int i=0; i<2; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        diagonals.push_back({n1, n2});
    }
    cout << solution(width, height, diagonals) << "\n";
}