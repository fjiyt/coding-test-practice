#include <iostream>

using namespace std;
string s1;
string s2;
int dp[1001][1001];

void solve()
{
    for(int i=0; i<=s1.length(); i++)
    {
        for(int j=0; j<=s2.length(); j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
                continue;
            }
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] =dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}
int main()
{
    cin >> s1 >> s2;
    solve();
    cout << dp[s1.length()][s2.length()] << "\n";
}