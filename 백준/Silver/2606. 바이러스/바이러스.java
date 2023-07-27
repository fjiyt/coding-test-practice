import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int N, M, start;
    static boolean isVisited[];
    static ArrayList <Integer>[] a;
    static int count = 0;

    public static int dfs(int s) {
        isVisited[s] = true;
        for(int i=0; i<a[s].size(); i++)
        {
            int n = a[s].get(i);
            if(!isVisited[n]){
                count++;
                dfs(n);
            }
        }

        return count;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        start = 1;

        a = new ArrayList[N+1];
        isVisited = new boolean[N+1];
        for(int i=1; i<N+1; i++)
        {
            a[i] = new ArrayList<Integer>();
        }

        for(int i=0; i<M; i++)
        {
            int u = sc.nextInt();
            int v = sc.nextInt();

            a[u].add(v);
            a[v].add(u);
        }

        System.out.println(dfs(start));
    }
}
