import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int s, e;
    static List<List<Integer>> map;
    static boolean [] isVisited;
    static int res = -1;
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
        dfs(s,0);
        System.out.println(res);

    }

    public static void dfs(int start, int cnt) {
        if(start == e) {
            res = cnt;
            return;
        }
        isVisited[start] = true;
        for(int i: map.get(start))
        {
            if(!isVisited[i]){
                dfs(i, cnt+1);
            }
        }
    }
}
