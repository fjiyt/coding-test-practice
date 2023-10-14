import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int [][] dp;
    public static void main(String[] args) throws IOException{
        int T;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());

        dp = new int[31][31];
        for(int i=0; i<T; i++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            System.out.println(combine(M,N));
        }
    }

    public static int combine(int n, int r)
    {
        if(dp[n][r] > 0)
        {
            return dp[n][r];
        }
        if(r==0 || n==r)
        {
            dp[n][r] = 1;
            return dp[n][r];
        }
        return dp[n][r] = combine(n-1, r-1) + combine(n-1, r);
    }
}
