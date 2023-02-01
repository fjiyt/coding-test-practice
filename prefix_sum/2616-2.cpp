#include <iostream>
#include <vector>

using namespace std;

int N, X;
vector <int> v;
int dp[4][50001];

void solve()
{
    for(int i=1; i<4; i++)
    {
        for(int j=i*X; j<=N; j++)
        {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-X]+(v[j] - v[j-X]));
        }
    }
}
int main()
{
    cin >> N;
    v.push_back(0);
    int total = 0;
    for(int i=1; i<=N; i++)
    {
        int num;
        cin >> num;
        total += num;
        v.push_back(total);
    }
    cin >> X;

    solve();

    cout << dp[3][N] << "\n";
}