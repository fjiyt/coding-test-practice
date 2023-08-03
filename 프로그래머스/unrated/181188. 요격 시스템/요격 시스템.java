import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        Arrays.sort(targets, (o1,o2) -> (o1[0]!=o2[0] ? o1[0] - o2[0] : o1[1] - o2[1]));
        int last = -1;
        for(int i=0; i<targets.length; i++)
        {
            int s = targets[i][0];
            int e = targets[i][1];
            
            // 새로 만드는 경우
            if(s >= last)
            {
                last = e;
                answer++;
            }
            else if(e <= last)
            {
                last = e;
            }
        }
        
        return answer;
    }
}