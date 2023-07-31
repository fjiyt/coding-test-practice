import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int s, e;
    static List<List<Integer>> map;
    static boolean [] isVisited;
    static int cnt = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = null;

        st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        m = Integer.parseInt(br.readLine());
        isVisited = new boolean[n+1];

        isVisited[s] = true;
        map = new ArrayList<>();
        for(int i=0; i<=n; i++)
        {
            map.add(new ArrayList<>());
        }

        for(int i=0; i<m; i++)
        {
            st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            map.get(p).add(c);
            map.get(c).add(p);
        }

        System.out.println(dfs(s,0));

    }

    public static int dfs(int start, int cnt) {
        if(start == e) {
            return cnt;
        }
        for(int i: map.get(start))
        {
            if(!isVisited[i]){
                isVisited[i] = true;
                int ret = dfs(i, cnt+1);
                if(ret > 0){
                    return ret;
                }
            }
        }

        return -1;
    }
}
