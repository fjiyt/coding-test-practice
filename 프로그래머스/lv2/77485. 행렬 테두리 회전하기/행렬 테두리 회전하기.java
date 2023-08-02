class Solution {
    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int[queries.length];
        int[] dx = {-1,0,1,0};
        int[] dy = {0,1,0,-1};
        
        int[][] MAP = new int[rows+1][columns+1];
        int tmp = 1;
        for(int i=1; i<=rows; i++)
        {
            for(int j=1; j<=columns; j++)
            {
                MAP[i][j] = tmp;
                tmp++;
            }
        }
        for(int i=0; i<queries.length; i++)
        {
            int x1 = queries[i][0];
            int y1 = queries[i][1];
            int x2 = queries[i][2];
            int y2 = queries[i][3];
            int min_num = 10001;
            int [][] t_map = new int[rows+1][columns+1];
            
            // 이동 + 최솟값 갱신
            for(int x=x1; x<=x2; x++)
            {
                for(int y=y1; y<=y2; y++)
                {
                    // 안에 있는 경우
                    if(x!=x1 && x!=x2 && y!=y1 && y!=y2) continue;
                    //테두리인 경우 -> 회전
                    min_num = Math.min(min_num, MAP[x][y]);
                    int nx = 0, ny = 0;
                    if(x!=x1 && y==y1)
                    {
                        nx = x + dx[0];
                        ny = y + dy[0];
                    }
                    else if(x==x1 && y!=y2)
                    {
                        nx = x + dx[1];
                        ny = y + dy[1];
                    }
                    else if(x!=x2 && y==y2)
                    {
                        nx = x + dx[2];
                        ny = y + dy[2];
                    }
                    else if(x==x2 && y!=y1)
                    {
                        nx = x + dx[3];
                        ny = y + dy[3];
                    }
                    if(nx<x1 || nx>x2 || ny<y1 || ny>y2) continue;
                    t_map[nx][ny] = MAP[x][y];
                }
            }
            
            
            for(int x=x1; x<=x2; x++)
            {
                for(int y=y1; y<=y2; y++)
                {
                    if(t_map[x][y]>0)
                    {
                        MAP[x][y] = t_map[x][y];
                    }
                }
            }
            
            answer[i] = min_num;
        }
        return answer;
    }
}