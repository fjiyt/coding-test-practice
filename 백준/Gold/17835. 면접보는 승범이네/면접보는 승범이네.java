import java.util.*;
import java.io.*;

public class Main {
    static int N, M, K;
    static ArrayList <Road> [] graph;
    static long [] dist;
    static PriorityQueue <Road> pq;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        graph = new ArrayList [N+1];
        dist = new long [N+1];
        for(int i=0; i<N+1; i++)
        {
            graph[i] = new ArrayList<>();
        }
        for(int i=0; i<M; i++)
        {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            graph[v].add(new Road(u,c));
        }
        // dist 초기화
        for(int i=0; i<N+1; i++)
        {
            dist[i] = Long.MAX_VALUE;
        }

        pq = new PriorityQueue <Road> (Road::compare);
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<K; i++)
        {
            int n = Integer.parseInt(st.nextToken());
            dist[n] = 0;
            pq.add(new Road(n,0));
        }

        solve();
    }

    public static void solve()
    {
        // 다익스트라
        while(!pq.isEmpty())
        {
            Road now = pq.poll();

            // now에 대한 거리가 갱신됨
            if(dist[now.x] < now.dist) continue;
            for(Road next : graph[now.x])
            {
                if(dist[next.x] < now.dist + next.dist) continue;
                dist[next.x] = now.dist + next.dist;
                pq.add(new Road(next.x, dist[next.x]));
            }
        }

        // 거리가 가장 먼 도시와 그 거리
        int city = 0;
        long far = 0;
        for(int i=1; i<N+1; i++)
        {
            if(far < dist[i]) {
                far = dist[i];
                city = i;
            }
        }

        System.out.println(city);
        System.out.println(far);
    }

}
class Road {
    int x;
    long dist;

    Road(int x, long dist)
    {
        this.x = x;
        this.dist = dist;
    }

    public int compare(Road r)
    {
        return Long.compare(this.dist, r.dist);
    }
}
