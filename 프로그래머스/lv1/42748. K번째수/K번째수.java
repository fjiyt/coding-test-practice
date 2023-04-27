import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        for(int i=0; i<commands.length; i++)
        {
            int s = commands[i][0];
            int e = commands[i][1];
            int idx = commands[i][2];
            
            int [] tmp = new int[e-s+1];
            int p = 0;
            for(int j=s-1; j<=e-1; j++)
            {
                tmp[p]=array[j];
                p++;
            }
            
            Arrays.sort(tmp);
            
            answer[i] = tmp[idx-1];
            
        }
        return answer;
    }
}