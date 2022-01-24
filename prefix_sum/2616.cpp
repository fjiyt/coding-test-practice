//누적합의 탈을 쓴 dp ..
#include <iostream>

using namespace std;
int N, M;
int arr[50001];
int dp[4][50002];

void solve()
{
    for(int i=1; i<4; i++)
    {
        for(int j=i*M; j<=N; j++)
        {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-M] + (arr[j]-arr[j-M]));
        }
    }
}
int main()
{
    cin >> N;
    int total = 0;
    for(int i=1; i<=N; i++)
    {
        int num;
        cin >> num;
        total += num;
        arr[i] = total;
    }
    cin >> M;

    solve();
    cout << dp[3][N] << "\n";
}