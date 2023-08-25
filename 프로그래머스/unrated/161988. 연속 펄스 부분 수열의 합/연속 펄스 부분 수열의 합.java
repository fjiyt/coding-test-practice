class Solution {
    public long solution(int[] sequence) {
        long answer = 0;
        
        int l = sequence.length;
        int [] s1 = new int[l];
        int [] s2 = new int[l];
        int n = 1;
        for(int i=0; i<l; i++)
        {
            s1[i] = sequence[i] * n;
            n *= -1;
            s2[i] = sequence[i] * n;
        }
        
        long [] dp1 = new long[l];
        long [] dp2 = new long[l];
        
        dp1[0] = s1[0];
        dp2[0] = s2[0];
        answer = Math.max(dp1[0], dp2[0]);
        for(int i=1; i<l; i++)
        {
            dp1[i] = Math.max(dp1[i-1] + s1[i], s1[i]);
            dp2[i] = Math.max(dp2[i-1] + s2[i], s2[i]);
            
            long max = Math.max(dp1[i], dp2[i]);
            answer = Math.max(max, answer);
        }
        return answer;
    }
}