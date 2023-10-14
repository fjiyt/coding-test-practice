import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int [][] dp;
    public static void main(String[] args) throws IOException{
        int T;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for(int i=0; i<T; i++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            dp = new int[M+1][N+1];

            System.out.println(combine(M,N));
        }
    }

    public static int combine(int M, int N)
    {
        if(dp[M][N] > 0)
        {
            return dp[M][N];
        }
        if(N==0 || M==N)
        {
            dp[M][N] = 1;
            return dp[M][N];
        }
        return dp[M][N] = combine(M-1, N-1) + combine(M-1, N);
    }
}
