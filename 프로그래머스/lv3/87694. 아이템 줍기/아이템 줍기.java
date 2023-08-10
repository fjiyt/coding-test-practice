import java.io.*;
import java.util.*;

class Solution {
    public static int[][] MAP;
    public static int[][] cnt;
    public static int[] dx = {1,-1,0,0};
    public static int[] dy = {0,0,1,-1};
    
    public class Node
    {
        int x, y;
        
        Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY)
{
        int answer = 0;
        MAP = new int [101][101];
        cnt = new int [101][101];
        // 구역 나누기
        makeBox(rectangle);
        
        //bfs
        answer = bfs(2*characterX, 2*characterY, 2*itemX, 2*itemY);
        
        return answer/2;
    }
    public int bfs(int cx, int cy, int ix, int iy)
    {
        Queue <Node> q = new LinkedList<> ();
        q.add(new Node(cx,cy));
        
         while(!q.isEmpty())
         {
             Node n = q.poll();
             int x = n.x;
             int y = n.y;
            
             //System.out.println(y + " " + x);
            if(x==ix && y==iy) {
                return cnt[y][x];
            }
            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || nx > 100 || ny < 0 || ny > 100) continue;
                if(MAP[ny][nx]!=1 || cnt[ny][nx]!=0) continue;
                
                cnt[ny][nx] = cnt[y][x] + 1;
                q.add(new Node(nx, ny));
            }
        }
        
        return -1;
    }
    public void makeBox(int [][] r)
    {
        for(int i=0; i<r.length; i++)
        {
            int x1 = r[i][0] * 2;
            int y1 = r[i][1] * 2;
            int x2 = r[i][2] * 2;
            int y2 = r[i][3] * 2;
            
            for(int p=y1; p<=y2; p++)
            {
                for(int q=x1; q<=x2; q++)
                {
                    if(p==y1 || p==y2 || q==x1 || q==x2)
                    {
                        if(MAP[p][q] == 0) MAP[p][q] = 1;
                    }
                    else {
                        if(MAP[p][q] == 1 || MAP[p][q] == 0) {
                            MAP[p][q] = 2;
                        }
                    }
                }
            }
        }
    }
}