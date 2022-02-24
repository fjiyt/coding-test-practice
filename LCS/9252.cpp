#include <iostream>
#include <stack>

using namespace std;

int DP[1001][1001];
stack <char> res;
string first;
string second;

void findString(int x, int y)
{
    if(x==0 || y==0) return;
    if(DP[x][y]==DP[x][y-1]){
        findString(x, y-1);
    }
    else if(DP[x][y] == DP[x-1][y])
    {
        findString(x-1,y);
    }
    else{
        res.push(first[x-1]);
        findString(x-1,y-1);
    }
}
void solve()
{
    for(int i=1; i<=first.length(); i++)
    {
        for(int j=1; j<=second.length(); j++)
        {
            if(first[i-1]==second[j-1])
            {
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else{
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
            
        }
    }

    findString(first.length(), second.length());
}
int main()
{
    cin >> first >> second;
    solve();

    cout << DP[first.length()][second.length()] << "\n";
    while(!res.empty())
    {
        cout << res.top();
        res.pop();
    }
    cout << "\n";
}