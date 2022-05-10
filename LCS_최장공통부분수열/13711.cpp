#include <iostream>
#include <vector>

using namespace std;

int v[2][100001];

int main()
{
    int N;
    cin >> N;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<N; j++)
        {
            int num;
            cin >> num;
            v[i][j]=num;
        }
    }

    int DP[N+1][N+1];
    for(int i=0; i<=N; i++)
    {
        for(int j=0; j<=N; j++)
        {
            DP[i][j] = 0;
        }
    }
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(v[0][i-1] == v[1][j-1]) DP[i][j] = DP[i-1][j-1] + 1;
            else DP[i][j] = max(DP[i][j-1], DP[i-1][j]);
        }
    }

    cout << DP[N][N] << "\n";
}