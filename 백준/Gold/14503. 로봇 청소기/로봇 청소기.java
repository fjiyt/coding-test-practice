import java.util.Scanner;

class Position {
    int x;
    int y;
    int d;

    Position(int x,int y,int d) {
        this.x = x;
        this.y = y;
        this.d = d;
    }
}
public class Main {
    static int N, M;
    static int [][] MAP;
    static int [] dx = {-1,0,1,0};
    static int [] dy = {0,1,0,-1};
    static Position p;
    static int cnt = 0;

    public static void solve()
    {
        while(true)
        {
            // 현재칸 청소
            int x = p.x;
            int y = p.y;
            int d = p.d;

            if(MAP[x][y]==0)
            {
                MAP[x][y] = -1;
                cnt++;
            }

            // 빈칸찾기 -> 이동
            boolean isFind = false;
            for(int i=1; i<=4; i++)
            {
                int nd = (d - i + 4) % 4;
                int nx = x + dx[nd];
                int ny = y + dy[nd];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if(MAP[nx][ny]==0) {
                    isFind = true;
                    p.x = nx;
                    p.y = ny;
                    p.d = nd;

                    break;
                }
            }
            // 빈칸없을경우 -> 이동 / 멈춤
            if(!isFind)
            {
                int nd = (d + 2) % 4;
                int nx = x + dx[nd];
                int ny = y + dy[nd];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M) break;
                if(MAP[nx][ny] == 1) break;

                p.x = nx;
                p.y = ny;
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        MAP = new int[N][M];

        int x, y, d;
        x = sc.nextInt();
        y = sc.nextInt();
        d = sc.nextInt();

        p = new Position(x,y,d);

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                MAP[i][j] = sc.nextInt();
            }
        }

        solve();

        System.out.println(cnt);
    }
}
