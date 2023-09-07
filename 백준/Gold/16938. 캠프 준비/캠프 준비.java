import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int [] arr;
    public static int N,L,R,X;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        arr = new int[16];
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++)
        {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int ret = 0;
        for(int bit = 0; bit < (1 << N); bit++)
        {
            if(check(bit)) ret++;
        }

        System.out.println(ret);
    }

    public static boolean check(int bit)
    {
        int score = 0;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        int cnt = 0;
        for(int i=0; i<N; i++)
        {
            int flag = bit & (1<<i);

            if(flag != 0)
            {
                score += arr[i];
                min = Math.min(min, arr[i]);
                max = Math.max(max, arr[i]);
                cnt++;
            }
        }

        if(cnt >= 2 && score >= L && score <= R && max-min >= X) return true;
        return false;
    }
}
