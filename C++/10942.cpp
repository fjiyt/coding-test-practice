#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[2001];
bool isPalin[2001][2001];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }
    for(int i=1; i<=N; i++)
    {
        isPalin[i][i] = true;
    }
    for(int i=1; i<=N-1; i++)
    {
        if(arr[i] == arr[i+1]) isPalin[i][i+1] = true;
    }
    for(int i=N-1; i>=1; i--)
    {
        for(int j=i+2; j<=N; j++)
        {
            if(arr[i] == arr[j] && isPalin[i+1][j-1]==true)
            {
                isPalin[i][j] = true;
            }
        }
    }
    cin >> M;
    for(int i=0; i<M; i++)
    {
        int s,e;
        cin >> s >> e;
        cout << isPalin[s][e] << "\n";
    }
}