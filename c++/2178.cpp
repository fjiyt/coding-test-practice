#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    char saved[N][M];
    
    for(int i=0; i<N; i++)
    {
        cin >> saved[i];
    }
    
    queue < pair<int,int> > que;
    bool isVisited[N][M];
    int cost[N][M];

    vector < pair<int, int> > v; //방향을 나타내는 벡터
    v.push_back(pair <int, int> (0,1));
    v.push_back(pair <int, int> (1,0));
    v.push_back(pair <int, int> (-1,0));
    v.push_back(pair <int, int> (0,-1));
 
    pair <int, int> p;
    pair <int, int> n;

    std::fill(&isVisited[0][0],&isVisited[0][0]+sizeof(isVisited),0);
    
    que.push(make_pair(0,0));
    cost[0][0]=1;

    while(!que.empty())
    {
        p= que.front();
        que.pop();

        if(isVisited[p.first][p.second]) continue;
        isVisited[p.first][p.second]=true;

        if(p.first == N-1 && p.second == M-1) {
            cout << cost[p.first][p.second] << "\n";
            break;
        }

        for(int i=0; i<4; i++)
        {
            n.first = p.first + v[i].first;
            n.second = p.second + v[i].second;
            if(n.first >=0 && n.second >=0 && n.first < N && n.second < M && saved[n.first][n.second]=='1')
            {
                que.push(n);
                cost[n.first][n.second]= cost[p.first][p.second]+1;
            }
        }
    }

    return 0;
}