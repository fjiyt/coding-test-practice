import java.io.*;
import java.sql.Array;
import java.util.*;

public class Main {
    static int N, K, R;
    static ArrayList <Node> [][]map;
    static ArrayList <Node> list;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        map = new ArrayList [N+1][N+1];
        for(int i=0; i<=N; i++) {
            for (int j = 0; j <= N; j++) {
                map[i][j] = new ArrayList<Node>();
            }
        }

        list = new ArrayList <Node> ();
        for(int i=0; i<R; i++)
        {
            // 길인걸 표시해야됨
            st = new StringTokenizer(br.readLine());
            int r1 = Integer.parseInt(st.nextToken());
            int c1 = Integer.parseInt(st.nextToken());
            int r2 = Integer.parseInt(st.nextToken());
            int c2 = Integer.parseInt(st.nextToken());

            map[r1][c1].add(new Node(r2,c2));
            map[r2][c2].add(new Node(r1,c1));
        }
        for(int i=0; i<K; i++)
        {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            list.add(new Node(x,y));
        }

        int cnt = 0;
        for(int i=0; i<list.size(); i++)
        {
            for(int j=i+1; j<list.size(); j++)
            {
                if(!isPass((Node)list.get(i), (Node)list.get(j))) {
                    cnt++;
                }
            }
        }

        System.out.println(cnt);
    }

    public static boolean isPass(Node s, Node e)
    {
        int [] dx = {1,0,-1,0};
        int [] dy = {0,1,0,-1};
        boolean [][] isVisited = new boolean[N+1][N+1];
        Queue <Node> q = new LinkedList<>();
        q.add(s);
        isVisited[s.x][s.y] = true;

        while(!q.isEmpty())
        {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();

            if(x==e.x && y==e.y) return true;

            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
                boolean flag = false;
                // 길이 있는지 확인 -> 길이 없는 길로 가야됨
                for(int j=0; j<map[x][y].size(); j++)
                {
                    if(map[x][y].get(j).x == nx && map[x][y].get(j).y == ny) {
                        flag = true;
                        break;
                    }
                }
                if(!isVisited[nx][ny] && !flag)
                {
                    isVisited[nx][ny] = true;
                    q.add(new Node(nx,ny));
                }
            }
        }

        return false;
    }
}

class Node{
    int x, y;
    Node(int x, int y)
    {
        this.x = x;
        this.y = y;
    }
}