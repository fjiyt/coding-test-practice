import java.io.*;
import java.util.*;

public class Main {
    static int N, S;
    static int[] arr;
    static int currentSum;
    static int cnt;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        arr = new int[N];
        st = new StringTokenizer(br.readLine());

        for(int i=0; i<N; i++)
        {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        solve(0);

        System.out.println(cnt);
    }

    public static void solve(int idx)
    {
        if(idx == N) return;

        if(currentSum + arr[idx] == S) cnt++;
        solve(idx+1);
        currentSum += arr[idx];
        solve(idx+1);
        currentSum -= arr[idx];
    }
}
