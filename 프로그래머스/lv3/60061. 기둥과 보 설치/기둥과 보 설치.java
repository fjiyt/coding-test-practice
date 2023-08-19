import java.util.*;

class Solution {
    public int[][] c_map;
    public int[][] b_map;
    private int n;
    
    public int[][] solution(int n, int[][] build_frame) {
        c_map = new int [n+1][n+1];
        b_map = new int [n+1][n+1];
        this.n = n;
        int count = 0;
        
        for(int i=0; i<build_frame.length; i++)
        {
            int x = build_frame[i][0];
            int y = build_frame[i][1];
            int a = build_frame[i][2];
            int b = build_frame[i][3];
            
            if(a==0) // 기둥
            {
                if(b==0) //삭제
                {
                    c_map[x][y] = 0;
                    
                    if(!isCheck()) c_map[x][y] = 1; 
                    else count--;
                }
                else { // 설치
                    if(okayC(x,y))
                    {
                        c_map[x][y] = 1;
                        count++;
                    }
                    
                }
            }
            else{ // 보
                if(b==0) { // 삭제
                    b_map[x][y]=0;
                    
                    if(!isCheck()) b_map[x][y] = 1;
                    else count--;
                }
                else{ // 설치
                    if(okayB(x,y)){
                        b_map[x][y] = 1;
                        count++;
                    }
                }
            }
        }
        
        int idx = 0;
        int [][] answer = new int[count][3];
        
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(c_map[i][j] == 1) {
                    answer[idx][0] = i;
                    answer[idx][1] = j;
                    answer[idx][2] = 0;
                    idx++;
                }
                if(b_map[i][j] == 1) {
                    answer[idx][0] = i;
                    answer[idx][1] = j;
                    answer[idx][2] = 1;
                    idx++;
                }
            }
        }
        
        return answer;
    }
    
    public boolean isCheck()
    {
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(c_map[i][j] == 1 && okayC(i,j) == false) return false;
                if(b_map[i][j] == 1 && okayB(i,j) == false) return false; 
            }
        }
        
        return true;
    }
//     public boolean okayC(int x, int y)
//     {
//         if(y==0 || (x>0 && b_map[x-1][y]==1) || (y>0 && c_map[x][y-1]==1)) return true;
        
//         return false;
//     }
    
//     public boolean okayB(int x, int y)
//     {
//         if((y>0 && c_map[x][y-1]==1)||(x<n && y>0 && c_map[x+1][y-1]==1)|| (x>0 && x<n && b_map[x-1][y]==1 && b_map[x+1][y]==1)) return true;
        
//         return false;
//     }
    
    public boolean okayC(int x, int y) {
        if(y == 0) return true; //바닥에 설치하는 경우
        else if(y > 0 && c_map[x][y - 1]==1) return true; //아래 기둥이 있는 경우
        else if(x > 0 && b_map[x - 1][y]==1|| b_map[x][y]==1) return true;
        return false;
    }
    
    public boolean okayB(int x, int y) {
        if(y > 0 && c_map[x][y - 1]==1 || c_map[x + 1][y - 1]==1) return true; // 한쪽 끝에 기둥이 있는 경우
        else if(x > 0 && b_map[x - 1][y]==1 && b_map[x + 1][y]==1) return true; //양쪽 끝이 보와 동시에 연결되어 있는 경우
        return false;
    }
}