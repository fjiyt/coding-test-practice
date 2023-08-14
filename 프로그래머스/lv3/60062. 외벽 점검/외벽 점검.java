class Solution {
    private int [][] rotateWeak;
    private int n;
    private int[] weak, dist, choice;
    private boolean finish = false;
    private int num;
    
    public int solution(int n, int[] weak, int[] dist) {
        this.n = n;
        rotateWeak = new int [weak.length][weak.length];
        this.weak = weak;
        this.dist = dist;
        
        setWeak();
        
        for(int i=1; i<=dist.length; i++)
        {
            num=i;
            choice = new int [num];
            permutation(0, new boolean [dist.length]);
            if(finish) {
                break;
            }
        }
        
        
        return (finish) ? num : -1;
    }
    public void permutation(int depth, boolean[] visit) {
        if (finish) return;
        if (depth == num) {
            check();
            return;
        }

        for (int i = 0; i < dist.length; i++) {
            if (!visit[i]) {
                choice[depth] = dist[i];
                visit[i] = true;
                permutation(depth + 1, visit);
                visit[i] = false;
            }
        }
    }
    
    public void check() {
        for (int[] weak : rotateWeak) {
            int idx = 0, start = 0;
            boolean[] visit = new boolean[weak.length];

            while (idx != num) {
                int i = start;
                int value = choice[idx++];

                for (int j = start; j < weak.length; j++) {
                    if (!(weak[i] <= weak[j] && weak[j] <= weak[i] + value)) break;
                    visit[j] = true;
                    start++;
                }
            }

            if (isFinish(visit)) {
                finish = true;
                return;
            }
        }
    }
    
    public boolean isFinish(boolean [] visit)
    {
        for(boolean v : visit)
        {
            if(!v) return false;
        }
        return true;
    }
    public void setWeak()
    {
        int cnt = 0;
        
        for(int i=0; i<weak.length; i++)
        {
            for(int j=0; j<weak.length; j++)
            {
                int idx = i+j;
                if(idx >= weak.length)
                {
                    rotateWeak[i][j] = weak[idx-weak.length] + n;
                }
                else {
                    rotateWeak[i][j] = weak[idx];
                }
            }
        }
    }
}