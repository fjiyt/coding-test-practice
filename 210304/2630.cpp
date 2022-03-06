#include <iostream>

using namespace std;
int N;
int white, blue;
int arr[129][129];

void solve(int x, int y,int size)
{
    int start = arr[x][y];
    bool flag = true;
    for(int i=x; i<x+size; i++)
    {
        for(int j=y; j<y+size; j++)
        {
            if(arr[i][j]!=start) 
            {
                flag = false;
                solve(x,y,size/2);
                solve(x+size/2, y, size/2);
                solve(x,y+size/2,size/2);
                solve(x+size/2, y+size/2, size/2);
                return;
            }
        }
    }
    if(flag)
    {
        if(start==0) white++;
        else blue++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> arr[i][j];
        }
    }
    solve(0,0,N);

    cout << white << "\n";
    cout << blue << "\n";
}