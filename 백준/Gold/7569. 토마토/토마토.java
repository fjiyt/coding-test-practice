import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class tomato {
    int x;
    int y;
    int h;

    tomato(int x, int y, int h)
    {
        this.x = x;
        this.y = y;
        this.h = h;
    }
}
public class Main {
    static int M, N, H;
    static int [][][] MAP;
    static int dh[] = {0,0,0,0,1,-1};
    static int dx[] = {1,-1,0,0,0,0};
    static int dy[] = {0,0,1,-1,0,0};
    static Queue<tomato> q = new LinkedList<>();

    public static void bfs()
    {
        while(!q.isEmpty()){
            tomato tmp = q.poll();
            int x = tmp.x;
            int y = tmp.y;
            int h = tmp.h;

            for(int i=0; i<6; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nh = h + dh[i];

                if(nx>=0 && nx<N && ny>=0 && ny<M && nh>=0 && nh<H)
                {
                    if(MAP[nh][nx][ny]==0)
                    {
                        q.add(new tomato(nx,ny,nh));
                        MAP[nh][nx][ny] = MAP[h][x][y] + 1;
                    }
                }
            }
        }
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        M = sc.nextInt();
        N = sc.nextInt();
        H = sc.nextInt();

        MAP = new int[H][N][M];

        for(int i=0; i<H; i++)
        {
            for(int j=0; j<N; j++)
            {
                for(int k=0; k<M; k++)
                {
                    MAP[i][j][k] = sc.nextInt();
                    if(MAP[i][j][k]==1) {
                        q.add(new tomato(j,k,i));
                    }
                }
            }
        }

        bfs();

        int max_days = Integer.MIN_VALUE;
        for(int i=0; i<H; i++)
        {
            for(int j=0; j<N; j++)
            {
                for(int k=0; k<M; k++)
                {
                    if(MAP[i][j][k] == 0) {
                        System.out.println("-1");
                        return;
                    }
                    max_days = Math.max(max_days, MAP[i][j][k]);
                }
            }
        }

        System.out.println(max_days-1);
    }
}
