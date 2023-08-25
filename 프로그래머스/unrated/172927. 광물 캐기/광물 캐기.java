import java.util.*;

class Solution {
    public int [][] set = {{1,1,1},{5,1,1},{25,5,1}};
    public int total;
    private String[] minerals;
    public int minSum = Integer.MAX_VALUE;
    public HashMap <String, Integer> hm;
    
    public int solution(int[] picks, String[] minerals) {
        int answer = 0;
        total = minerals.length;
        this.minerals = minerals;
        
        hm = new HashMap <> ();
        hm.put("diamond",0);
        hm.put("iron",1);
        hm.put("stone",2);
        
        dfs(0, picks, 0);
        return minSum;
    }
    
    public void dfs(int cnt, int [] picks, int sum)
    {
        if(cnt>=total) 
        {
            minSum = Math.min(sum, minSum);
            return;
        }
        int c = 0;
        for(int i=0; i<picks.length; i++)
        {
            if(picks[i]==0) c++;
        }
        if(c==picks.length) {
            minSum = Math.min(sum, minSum);
            return;
        }
        
        for(int i=0; i<picks.length; i++)
        {
            if(picks[i] > 0) {
                picks[i]--;
                // 피로도 구하기
                int s = sum;
                int idx = cnt;
                for(int j=0; j<5; j++)
                {
                    idx = cnt + j;
                    if(idx >= total) break;
                    int from = hm.get(minerals[idx]);
                    s += set[i][from];
                    
                }
                dfs(idx+1, picks, s);
                picks[i]++;
            }
        }
    }
}