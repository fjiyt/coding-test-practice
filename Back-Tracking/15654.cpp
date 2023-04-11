#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector <int> sortingNum;
int arr[9];
bool isVisited[9];

void dfs(int cnt)
{
    if(cnt==M)
    {
        for(int i=0; i<M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0; i<N; i++)
    {
        if(!isVisited[i])
        {
            isVisited[i] = true;
            arr[cnt] = sortingNum[i];
            dfs(cnt+1);
            isVisited[i] = false;
        }
    }
    
}
int main()
{
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        int a;
        cin >> a;
        sortingNum.push_back(a);
    }

    sort(sortingNum.begin(), sortingNum.end());
    dfs(0);
}