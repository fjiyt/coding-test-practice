import java.util.*;

class Solution {
    public int mod = 1000000007;
    public long solution(int n) {
        int answer = 0;
        
        long [] dp = new long [100002];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 3;
        dp[3] = 10;
        dp[4] = 23;
        dp[5] = 62;
        dp[6] = 170;
        
        long [] sum = new long [100002];
        sum[0] = 1;
        sum[1] = 1;
        sum[2] = 3;
        sum[3] = 11;
        sum[4] = 24;
        sum[5] = 65;
        sum[6] = 181;
        
        for(int i=7; i<=n; i++)
        {
            dp[i] = dp[i-1];
            dp[i] += dp[i-2] * 2;
            dp[i] += dp[i-3] * 5;
            dp[i] += sum[i-4] * 2;
            dp[i] += sum[i-5] * 2;
            dp[i] += sum[i-6] * 4;
            dp[i] %= mod;
            
            sum[i] = dp[i] + sum[i-3];
            sum[i] %= mod;
        }
        
        return dp[n];
    }
}