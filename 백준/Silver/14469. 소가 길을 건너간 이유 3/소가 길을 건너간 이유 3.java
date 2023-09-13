import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Node[] arr = new Node[N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            arr[i] = new Node(a, t);
        }

        Arrays.sort(arr,(n1,n2) -> {
            if(n1.arrive == n2.arrive) return n1.time-n2.time;
            return n1.arrive - n2.arrive;
        });

        int now = 0;

        for (int i = 0; i < N; i++) {
            if (now < arr[i].arrive) {
                now = arr[i].time + arr[i].arrive;
            } else {
                now += arr[i].time;
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
}