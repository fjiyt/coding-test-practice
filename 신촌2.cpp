#include <iostream>
#include <vector>

using namespace std;

int arr[4001][4001];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
vector <pair<int,int>> ans;
int N, M, K;

void diffDir()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(arr[i][j] == 1)
            {
                bool flag = false;
                for(int k=0; k<2; k++)
                {
                    int nx =i+dx[k];
                    int ny =j+dy[k];
        
                    if( nx>= N || ny >= M || nx < 0 || ny < 0)
                    {
                        continue;
                    }
                    else{
                        if(arr[nx][ny]==1) flag = true;
                    }
                }
                for(int k=2; k<4; k++)
                {
                    int nx =i+dx[k];
                    int ny =j+dy[k];
        
                    if( nx>= N || ny >= M || nx < 0 || ny < 0)
                    {
                        continue;
                    }
                    else{
                        if(!flag) break;
                        if(arr[nx][ny]==1) {
                            ans.push_back({i,j});
                            return;
                        }
                        else break;
                    }
                }
            }
        }
    }
    return;
}
void sameDir(int common)
{
    //시작과 끝만 알면됨
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(arr[i][j] == 1)
            {
                //세로
                if(arr[i+K-1][j]==1){
                    for(int l=0; l<common; l++)
                    {
                        ans.push_back({i+K-1-l,j});
                    }
                    return;
                }
                //가로
                else if(arr[i][j+K-1]==1){
                    for(int l=0; l<common; l++)
                    {
                        ans.push_back({i,j+K-1-l});
                    }
                    return;
                }
            }
        }
    }
}
int main() {
    int cnt =0;
    int common = 0;
     
    cin >> N >> M >> K;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j])
            {
                cnt++;
            }
        }
    }

    if(cnt==2*K)
    {
        cout << "0\n";
        return 0;
    }
    else if(cnt < 2*K)
    {
        common = 2*K - cnt;

        if(common==1)
        {
            diffDir();
            if(ans.size()==0)
            {
                sameDir(common);
            }
        }
        else if(common > 1){ //같은 방향 -> 1 이상
            sameDir(common);
        }
    }

    cout << ans.size() << "\n";
    if(ans.size() > 0 && common == ans.size())
    {
        for(int i=ans.size()-1; i>=0; i--)
        {
            cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";
        }
    }
   return 0;
}