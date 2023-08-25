class Solution {
    int [] map;
    boolean [] check;
    private int n;
    int answer = 0;

    public int solution(int n) {
        this.n = n;
        map = new int[n];
        check = new boolean[n];
        
        dfs(0);
        return answer;
    }
    public void dfs(int idx) 
    {
        if(idx==n) {
            answer++;
            return;
        }
        
        for(int i=0; i<n; i++)
        {
            if(!check[idx])
            {
                check[idx] = true;
                map[idx] = i;
                if(!isAttack(idx)) dfs(idx+1);
                check[idx] = false;
            }
        }
    }
    public boolean isAttack(int idx)
    {
        for(int i=0; i<idx; i++)
        {
            if(map[idx] == map[i]) return true;
            if(Math.abs(idx-i) == Math.abs(map[idx]-map[i])) return true;
        }
        return false;
    }
}