import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        PriorityQueue <Node> pq = new PriorityQueue <> (Node::compareTo);
        for(int i=0; i<N; i++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            pq.add(new Node(a,t));
        }

        int start = 0;
        int time = 0;
        int now = 0;
        while(!pq.isEmpty())
        {
            start = pq.peek().arrive;
            time = pq.peek().time;
            pq.poll();

            if(now < start)
            {
                now = start+time;
            }
            else {
                now += time;
            }
        }

        System.out.println(now);
    }
}

class Node{
    int arrive, time;
    Node (int arrive, int time)
    {
        this.arrive = arrive;
        this.time = time;
    }

    int compareTo(Node n)
    {
        if(this.arrive == n.arrive) return this.time - n.time;
        return this.arrive - n.arrive;
    }
}