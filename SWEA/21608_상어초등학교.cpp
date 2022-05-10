#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

vector <int> Friend[402];
int arr[21][21];
int N;
int answer = 0;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool comp(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
void findBestSeat(int num)
{
    vector <pair<int,int> > v[5];
    int maxFriend = -1;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(arr[i][j] > 0) continue;
            int cnt = 0;
            for(int k=0; k<4; k++)
            {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                
                for(int l=0; l<4 ; l++)
                {
                    if(arr[nx][ny] == Friend[num][l]) cnt++;
                }
            }
            if(maxFriend <= cnt)
            {
                maxFriend = cnt;
                v[maxFriend].push_back({i, j});
            }
        }
    }
    //2번시행
    int maxEmpty = -1;
    map <int,int> m;
    if(v[maxFriend].size() > 1)
    {
        for(int i=0; i<v[maxFriend].size(); i++)
        {
            int x = v[maxFriend][i].first;
            int y = v[maxFriend][i].second;
            int cnt = 0;
            for(int k=0; k<4; k++)
            {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;;
                if(!arr[nx][ny]) cnt++;
            }
            if(maxEmpty < cnt)
            {
                maxEmpty = cnt;
                m.clear();
                m.insert({x,y});
            }
            else if(maxEmpty==cnt){
                m.insert({x,y});
            }
        }
    }
    else if(v[maxFriend].size() == 1)
    {
        int x = v[maxFriend][0].first;
        int y = v[maxFriend][0].second;
        arr[x][y] = num;
        return;
    }

    //3번시행
    vector <pair<int,int> > tmp(m.begin(), m.end());
    sort(tmp.begin(), tmp.end(), comp);
    
    int x = tmp[0].first;
    int y = tmp[0].second;
    arr[x][y] = num;
    return;
}
void calcSatisfaction()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int num = arr[i][j];
            int cnt = 0;
            for(int k=0; k<4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                for(int l=0; l<4 ; l++)
                {
                    if(arr[nx][ny] == Friend[num][l]) cnt++;
                }
            }
            if(cnt != 0)
            {
                answer += pow(10, cnt-1);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;

    for(int i=0; i<pow(N,2); i++)
    {
        int me;
        cin >> me;
        for(int j=0; j<4; j++)
        {
            int f;
            cin >> f;
            Friend[me].push_back(f);
        }
        findBestSeat(me);
    }

    calcSatisfaction();

    cout << answer << "\n";
}