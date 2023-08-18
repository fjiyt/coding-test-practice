import java.util.*;

class Solution {
    public int [] dx = {-1,1,0,0};
    public int [] dy = {0,0,-1,1};
    public boolean[][] isVisited;

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        Queue <Position> q = new LinkedList <> ();
        isVisited = new boolean[image.length][image[0].length];

        int origin = image[sr][sc];
        q.add(new Position(sr,sc));
        image[sr][sc] = color;
        isVisited[sr][sc] = true;

        while(!q.isEmpty())
        {
            Position cur = q.poll();

            for(int i=0; i<4; i++)
            {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if(nx < 0 || nx >= image.length || ny < 0 || ny>=image[0].length) continue;
                if(isVisited[nx][ny] || image[nx][ny] != origin) continue;

                isVisited[nx][ny] = true;
                q.add(new Position(nx,ny));
                image[nx][ny] = color;
            }
        }

        return image;
    }
}

class Position {
    int x, y;

    Position(int x, int y)
    {
        this.x = x;
        this.y = y;
    }
}
