# Longest Common Subsequence (최장 공통 부분 수열)

- DP 이용
  
~~~ C++
void solve()
{
    for(int i=0; i<=first.length(); i++)
    {
        for(int j=0; j<=second.length(); j++)
        {
            if(i==0 || j==0) {
                DP[i][j] = 0;
                continue;
            }
            if(first[i-1] == second[j-1])
            {
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
}
~~~
