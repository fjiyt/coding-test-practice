#include <iostream>

using namespace std;

int N,S;
int arr[21];
bool isVisited[21];
int cnt=0;

void solve(int num, int sum)
{
    if(num>0 && sum==S)
    {
        cnt++;
    }

    if(num>=N) return;

    for(int i=num; i<N; i++)
    {
        if(!isVisited[i])
        {
            isVisited[i] = true;
            solve(i+1, sum+arr[i]);
            isVisited[i] = false;
        }
    }
}
int main()
{
    cin >> N >> S;
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    solve(0,0);

    cout << cnt << "\n";
}