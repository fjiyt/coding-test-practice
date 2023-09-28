import java.io.*;
import java.util.*;

public class Main {
    static String input1, input2, output;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        for(int i=1; i<=n; i++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            input1 = st.nextToken();
            input2 = st.nextToken();
            output = st.nextToken();

            if(solve())
            {
                System.out.println("Data set " + i + ": yes");
            }
            else System.out.println("Data set " + i + ": no");

        }
    }

    public static boolean solve()
    {
        boolean [][] dp = new boolean [input1.length()+1][input2.length()+1];
        dp[0][0] = true;
        for(int i=0; i<=input1.length(); i++)
        {
            for(int j=0; j<=input2.length(); j++)
            {
                if(i==0 && j==0) continue;
                if(i==0)
                {
                    if(input2.charAt(j-1) == output.charAt(j-1)) dp[i][j] = true;
                }
                else if(j==0)
                {
                    if(input1.charAt(i-1) == output.charAt(i-1)) dp[i][j] = true;
                }
                else{
                    int idx = i+j-1;
                    if(output.charAt(idx)==input1.charAt(i-1)) dp[i][j] = dp[i-1][j];
                    if(!dp[i][j] && output.charAt(idx)==input2.charAt(j-1)) dp[i][j] = dp[i][j-1];
                }

            }
        }

        if(dp[input1.length()][input2.length()]) return true;
        else return false;
    }
}
