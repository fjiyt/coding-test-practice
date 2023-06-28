#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

string str1;
string str2;
int length;
int DP[1001][1001];
stack <char> ans;

void findString(int s1, int s2)
{
    if(s1==0 || s2==0) return;
    if(DP[s1][s2]==DP[s1][s2-1])
    {
        findString(s1, s2-1);
    }
    else if(DP[s1][s2] == DP[s1-1][s2])
    {
        findString(s1-1, s2);
    }
    else
    {
        ans.push(str1[s1-1]);
        findString(s1-1, s2-1);
    }
}
void solve()
{
    for(int i=1; i<=str1.length(); i++)
    {
        for(int j=1; j<=str2.length(); j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                DP[i][j] = DP[i-1][j-1]+1;
            }
            else{
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
    findString(str1.length(), str2.length());
}
int main()
{
    cin >> str1 >> str2;
    solve();

    cout << DP[str1.length()][str2.length()] << "\n";
    while(!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }
    cout << "\n";
}