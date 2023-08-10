class Solution {
    public static int answer = 0;
    public static boolean [] isVisited;
    
    public int solution(int k, int[][] dungeons) {
        isVisited = new boolean [dungeons.length];
        
        dfs(k, 0, dungeons);
        
        return answer;
    }
    public void dfs(int total, int cnt, int[][] dungeons)
    {
        for(int i=0; i<dungeons.length; i++)
        {
            int a = dungeons[i][0];
            int b = dungeons[i][1];
            
            if(!isVisited[i])
            {
                if(a > total) continue;
                isVisited[i] = true;
                dfs(total-b, cnt+1, dungeons);
                isVisited[i] = false;
            }
        }
        
        answer = Math.max(answer, cnt);
    }
}