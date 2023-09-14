import java.sql.Array;
import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static int m;
    static ArrayList <Node> [] bus;
    static int start;
    static int end;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        bus = new ArrayList [n+1];
        for(int i=0; i<=n; i++)
        {
            bus[i] = new ArrayList <Node>();
        }
        for(int i=0; i<m; i++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            bus[a].add(new Node(b,c));
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());

        solve();
    }

    public static void solve()
    {
        int [] dist = new int [n+1];
        int [] history = new int [n+1];
        for(int i=0; i<=n; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        boolean [] checked = new boolean [n+1];

        PriorityQueue <Node> pq = new PriorityQueue<>(Node::compareTo);
        pq.add(new Node(start, 0, start));
        dist[start] = 0;
        while(!pq.isEmpty())
        {
            Node cur = pq.peek();
            pq.poll();

            if(!checked[cur.x])
            {
                checked[cur.x] = true;
                history[cur.x] = cur.prev;
                for(int i=0; i<bus[cur.x].size(); i++)
                {
                    Node next = bus[cur.x].get(i);
                    if(!checked[next.x] && dist[next.x] > cur.cost + next.cost)
                    {
                        pq.add(new Node(next.x, cur.cost + next.cost, cur.x));
                        dist[next.x] = cur.cost + next.cost;
                    }
                }
            }
        }

        Stack <Integer> st = new Stack <Integer> ();
        st.push(end);
        int n = st.peek();
        while(true)
        {
            int prev = history[n];
            st.push(prev);
            n = prev;
            if(n==start) break;
        }
        System.out.println(dist[end]);
        System.out.println(st.size());
        while(!st.empty())
        {
            System.out.print(st.peek() + " ");
            st.pop();
        }
    }
}

class Node {
    int x;
    int cost;
    int prev;

    Node(int x, int cost)
    {
        this.x = x;
        this.cost = cost;
    }
    Node(int x, int cost, int prev)
    {
        this.x = x;
        this.cost = cost;
        this.prev = prev;
    }
    public static int compareTo(Node n1, Node n2)
    {
        if(n1.cost==n2.cost) return n1.x - n2.x;
        return n1.cost - n2.cost;
    }
}
