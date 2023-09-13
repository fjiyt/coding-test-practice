import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int [] dx = {1,0,-1,0};
    static int [] dy = {0,1,0,-1};
    static ArrayList <Node> list;
    static int cctvCnt;
    static int min = Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int [][] map = new int[N][M];
        list = new ArrayList<>();

        for(int i=0; i<N; i++)
        {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<M; j++)
            {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] > 0 && map[i][j] < 6){
                    list.add(new Node(i,j,map[i][j]));
                    cctvCnt++;
                }
            }
        }
        solve(0, map);

        System.out.println(min);
    }
    public static void solve(int idx, int [][] map) {
        if (idx == cctvCnt) {
            //총 개수 세기
            int cnt = 0;
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<M; j++)
                {
                    if(map[i][j]==0) {
                        cnt++;
                    }
                }
            }
            min = Math.min(min, cnt);
            return;
        }

        int x = list.get(idx).x;
        int y = list.get(idx).y;
        int num = list.get(idx).num;

        ArrayList<Integer> dirs = new ArrayList<>();

        switch (num)
        {
            case 1:
                dirs.add(0);
                break;
            case 2:
                dirs.add(0);
                dirs.add(2);
                break;
            case 3:
                dirs.add(0);
                dirs.add(1);
                break;
            case 4:
                dirs.add(0);
                dirs.add(1);
                dirs.add(2);
                break;
            case 5:
                dirs.add(0);
                dirs.add(1);
                dirs.add(2);
                dirs.add(3);
                break;
        }
        for(int i=0; i<4; i++)
        {
            int [][] tmp = new int [N][M];
            for(int j=0; j<N; j++){
                tmp[j] = map[j].clone();
            }

            for(int j=0; j<dirs.size(); j++)
            {
                int dir = (dirs.get(j) + i) % 4;
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                while(nx >= 0 && nx < N && ny >= 0 && ny < M)
                {
                    if(map[nx][ny]==0) map[nx][ny] = -1;
                    else if(map[nx][ny] == 6) break;

                    nx += dx[dir];
                    ny += dy[dir];
                }
            }

            solve(idx+1, map);

            if(dirs.size()==4) {
                break;
            }

            map = tmp;
        }
    }
}

class Node {
    int x, y, num;
    Node(int x, int y, int num)
    {
        this.x = x;
        this.y = y;
        this.num = num;
    }
}