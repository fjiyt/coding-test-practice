#include <iostream>

using namespace std;
int N, M;
bool isVisited[9];
int arr[9];

void dfs(int cnt)
{
    if(cnt == M)
    {
        for(int i=0; i<M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1; i<=N; i++)
    {
        if(!isVisited[i])
        {
            if(cnt > 0 && arr[cnt-1] > i)
            {
                continue;
            }
            isVisited[i] = true;
            arr[cnt] = i;
            dfs(cnt+1);
            isVisited[i] = false;
        }
    }
}
int main()
{
    cin >> N >> M;
    
    dfs(0);
}