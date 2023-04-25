// 0 : 벽이 있는 자리, 1 : 벽이 없는 자리
import java.util.Queue;
import java.util.LinkedList;
import java.io.*;

class Solution {
    int[] dx = {1,-1,0,0};
    int[] dy = {0,0,1,-1};
    boolean[][] isVisited;
    
    static class Node {
        int x, y, dist;
        Node (int x, int y, int dist)
        {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }
    public int solution(int[][] maps) {
        int answer = 0;
        
        int p = maps.length;
        int q = maps[0].length;
        
        isVisited = new boolean[p][q];
        
        Queue <Node> queue = new LinkedList <>();
        queue.add(new Node(0,0,1));
        isVisited[0][0] = true;
        while(!queue.isEmpty())
        {
            Node n = queue.poll();
            if(n.x == maps.length-1 && n.y == maps[0].length-1)
            {
                return n.dist;
            }
            
            for(int i=0; i<4; i++)
            {
                int nx = n.x + dx[i];
                int ny = n.y + dy[i];
                if(nx < 0 || nx >= maps.length || ny < 0 || ny >= maps[0].length){
                    continue;
                }
                if(isVisited[nx][ny]) continue;
                if(maps[nx][ny]==1)
                {
                    isVisited[nx][ny] = true;
                    queue.add(new Node(nx,ny,n.dist+1));
                }
            }
        }
        
        return -1;
    }
}