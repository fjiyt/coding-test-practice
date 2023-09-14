import java.io.*;
import java.util.*;

public class Main {
    static ArrayList <Node> [] map;
    static int start = 0;
    static int end = 0;
    static int N;
    static int M;
    public static void main(String [] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        map = new ArrayList[N+1];
        for(int i=0; i<=N; i++)
        {
            map[i] = new ArrayList <Node> ();
        }
        for(int i=0; i<M; i++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            map[a].add(new Node(b,c));
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());

        solve();
    }
    public static void solve()
    {
        PriorityQueue <Node> pq = new PriorityQueue<>(Node::compareTo);
        pq.add(new Node(start, 0));

        int [] dist = new int[N+1];
        boolean [] checked = new boolean[N+1];
        for(int i=0; i<=N; i++)
            dist[i] = Integer.MAX_VALUE;

        dist[start] = 0;
        while(!pq.isEmpty())
        {
            int cur = pq.peek().x;
            int cost = pq.peek().cost;
            pq.poll();
            if(!checked[cur])
            {
                checked[cur] = true;
                for(int i=0; i<map[cur].size(); i++)
                {
                    int next = map[cur].get(i).x;
                    int nextCost = cost + map[cur].get(i).cost;

                    if(!checked[next]) {
                        if (nextCost >= dist[next]) continue;
                        dist[next] = nextCost;
                        pq.add(new Node(next, nextCost));
                    }
                }
            }
        }

        System.out.println(dist[end]);
    }
}

class Node {
    int x;
    int cost;
    Node(int x, int cost)
    {
        this.x = x;
        this.cost = cost;
    }

    public static int compareTo(Node n1, Node n2)
    {
        if(n1.cost==n2.cost) return n1.x - n2.x;
        return n1.cost-n2.cost;
    }
}
