import java.util.*;

public class Main {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Queue <Integer> q = new LinkedList<>();
        for(int i=1; i<=N; i++)
        {
            q.add(i);
        }

        int idx = 0;
        while(!q.isEmpty())
        {
            if(q.size()==1) {
                System.out.println(q.poll());
                return;
            }
            int now = q.poll();
            if(idx%2==1) q.add(now);
            idx++;
        }
    }
}
