import java.util.*;

class Solution {
    public int solution(int N, int number) {
        int answer = -1;
        
        ArrayList <HashSet<Integer>> list = new ArrayList <>();
        for(int i=0; i<9; i++)
        {
            list.add(new HashSet<Integer> ());
        }
        
        list.get(1).add(N);
        
        for(int i=2; i<9; i++)
        {
            HashSet <Integer> now = list.get(i);
            for(int j=1; j<i; j++)
            {
                HashSet <Integer> pre = list.get(j);
                HashSet <Integer> post = list.get(i-j);
            
                for(int prev : pre)
                {
                    for(int next : post)
                    {
                        now.add(prev + next);
                        now.add(prev - next);
                        now.add(prev * next);
                        
                        if(prev != 0 && next != 0)
                        {
                            now.add(prev/next);
                        }
                    }
                }
                now.add(Integer.parseInt(String.valueOf(N).repeat(i)));
            }
        }
        
        for(int i=1; i<9; i++)
        {
            if(list.get(i).contains(number)) {
                answer = i;
                break;
            }
        }
        return answer;
    }
}