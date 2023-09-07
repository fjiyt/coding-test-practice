import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int N;
    static int [] cnt;
    static int ret;
    static final int Goal = (1<<26)-1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        cnt = new int[N];

        for(int i=0; i<N; i++)
        {
            String str = br.readLine();

            for(int j=0; j<str.length(); j++)
            {
                int idx = str.charAt(j) - 'a';
                cnt[i] |= (1<<idx);
            }
        }

        dfs(0, 0);

        System.out.println(ret);
    }

    public static void dfs(int idx, int tmp)
    {
        if(tmp==Goal) {
            ret += 1<<(N-idx);
            return;
        }

        if(idx==N) {
            return;
        }

        int saved = tmp;
        tmp |= cnt[idx];
        dfs(idx+1, tmp);

        tmp = saved;
        dfs(idx+1, tmp);
    }
}
