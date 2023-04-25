import java.util.LinkedList;
import java.util.Queue;
import java.util.ArrayList;

class Solution {
    public ArrayList <Integer> solution(int[] progresses, int[] speeds) {
        ArrayList <Integer> answer = new ArrayList<> ();
        Queue <Integer> q = new LinkedList<>();
        // 각각 얼마나 걸리는지 계산
        for(int i=0; i<progresses.length; i++)
        {
            int tmp = 100 - progresses[i];
            int days = tmp / speeds[i];
            if(tmp % speeds[i] != 0)
            {
                days++;
            }
            q.add(days);
        }
        
        int now = q.peek();
        int cnt = 0;
        
        while(!q.isEmpty())
        {
            int days = q.peek();
            if(days <= now)
            {
                cnt++;
                q.remove();
            }
            else
            {
                answer.add(cnt);
                cnt = 0;
                now = days;
            }
        }
        if(cnt>0)
        {
            answer.add(cnt);
        }
        return answer;
    }
}