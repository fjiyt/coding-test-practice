import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        if(n%2==1) {
            System.out.println(0);
            return;
        }

        int [] dp = new int [n+1];
        dp[1] = 0;
        dp[2] = 3;
        for(int i=4; i<=n; i+=2)
        {
            dp[i] = dp[i-2] * dp[2] + 2;
            for(int j=4; j<i; j+=2)
            {
                dp[i] += dp[i-j] * 2;
            }
        }

        System.out.println(dp[n]);
    }
}
