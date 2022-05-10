#include <iostream>

using namespace std;
int N;
long long dp[1000001];

int main()
{
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    for(int i=1; i<=N-2; i++)
    {
        dp[i+2] = (dp[i] + dp[i+1]) % 15746;
    }

    cout << dp[N] << "\n";
}