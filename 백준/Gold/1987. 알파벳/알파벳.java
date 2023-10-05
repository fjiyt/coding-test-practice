import java.util.*;
import java.io.*;

public class Main {
    static int R, C;
    static char[][] map;
    static boolean[] isExist;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static int cnt;
    static int answer;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        map = new char[R][C];
        isExist = new boolean[26];
        for(int j=0; j<R; j++)
        {
            String tmp = br.readLine();
            for(int i=0; i<C; i++)
            {
                map[j][i] = tmp.charAt(i);
            }
        }
        isExist[map[0][0]-'A']= true;
        cnt++;
        solve(0,0);

        System.out.println(answer);
    }
    public static void solve(int x, int y)
    {
        if(cnt > answer) answer = cnt;

        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(!isExist[map[nx][ny]-'A'])
            {
                isExist[map[nx][ny]-'A'] = true;
                cnt++;
                solve(nx, ny);
                isExist[map[nx][ny]-'A'] = false;
                cnt--;
            }
        }
    }
}
