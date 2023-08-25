import java.util.*;

class Solution {
    public int solution(int[][] scores) {
        int answer = 0;
        
        int a = scores[0][0];
        int b = scores[0][1];
        int total = a+b;
        
        Arrays.sort(scores, (o1,o2) -> {
            if(o1[0]==o2[0])
                return o1[1]-o2[1];
            return o2[0]-o1[0];
        });
        
        int max = scores[0][1];
        
        for(int i=1; i<scores.length; i++)
        {
            if(max > scores[i][1])
            {
                if(a==scores[i][0] && b==scores[i][1]) return -1;
                
                scores[i][0] = -1;
                scores[i][1] = -1;
            }
            else {
                max = scores[i][1];
            }
        }
        
        // 순위 구하기
        Arrays.sort(scores, (o1,o2) -> {
            return (o2[0]+o2[1]) - (o1[0]+o1[1]);
        });
        
        for(int i=0; i<scores.length; i++)
        {
            if(total < scores[i][0] + scores[i][1]) answer++;
        }
        return answer+1;
    }
}