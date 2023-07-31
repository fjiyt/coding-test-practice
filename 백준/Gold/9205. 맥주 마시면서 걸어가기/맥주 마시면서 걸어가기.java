import java.io.*;
import java.util.*;

class Position {
    int x, y;
    Position(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
public class Main {
    static int t, n;
    static List<List<Integer>> map;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = null;
        StringBuilder sb = new StringBuilder();

        t = Integer.parseInt(br.readLine());

        while(t-- > 0) {
            // 편의점 개수
            n = Integer.parseInt(br.readLine());
            Position [] nodes = new Position[n+2];
            for(int i=0; i<n+2; i++)
            {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());

                nodes[i] = new Position(x,y);
            }

            map = new ArrayList<>();
            for(int i=0; i<n+2; i++) map.add(new ArrayList<>());

            for(int i=0; i<n+1; i++)
            {
                for(int j=i+1; j<n+2; j++)
                {
                    int diff = Math.abs(nodes[i].x - nodes[j].x) + Math.abs(nodes[i].y - nodes[j].y);
                    if(diff <= 1000) {
                        map.get(i).add(j);
                        map.get(j).add(i);
                    }
                }
            }

            sb.append(bfs()).append("\n");
        }

        System.out.println(sb);
    }

    public static String bfs()
    {
        Queue <Integer> q = new LinkedList<>();
        q.add(0);

        boolean[] isVisited = new boolean[n+2];
        isVisited[0] = true;

        while(!q.isEmpty())
        {
            int cur = q.poll();
            if(cur==n+1) return "happy";

            for(int i: map.get(cur))
            {
                if(!isVisited[i])
                {
                    isVisited[i] = true;
                    q.add(i);
                }
            }
        }

        return "sad";
    }
}
