import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String s1 = s.next();
        String s2 = s.next();

        int maxLength = 0;
        int [][] dp = new int[s1.length()+1][s2.length()+1];
        for(int i=0; i<=s1.length(); i++)
        {
            for(int j=0; j<=s2.length(); j++)
            {
                if(i==0 || j==0) {dp[i][j] = 0; continue;}
                if(s1.charAt(i-1) == s2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxLength = Math.max(maxLength, dp[i][j]);
                }
            }
        }
        
        System.out.println(maxLength);
    }
}
