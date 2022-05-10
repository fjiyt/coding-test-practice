#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int DP[101][101][101];
string first, second, third;

void solve()
{
    for(int i=1; i<=first.length(); i++)
    {
        for(int j=1; j<=second.length(); j++)
        {
            for(int k=1; k<=third.length(); k++)
            {
                if(first[i-1] == second[j-1] && second[j-1] == third[k-1])
                {
                    DP[i][j][k] = DP[i-1][j-1][k-1] + 1;
                }
                else{
                    DP[i][j][k] = max({DP[i-1][j][k], DP[i][j-1][k], DP[i][j][k-1]});
                }
            }
        }
    }
}
int main()
{
    cin >> first >> second >> third;
    solve();
    cout << DP[first.length()][second.length()][third.length()] << "\n";
}