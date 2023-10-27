class Solution {
    public int solution(int n) {
        int answer = 0;
        int [] sum = new int[n+1];
        
        for(int i=1; i<=n; i++)
        {
            sum[i] = sum[i-1] + i;
        }
        
        int start = 0;
        int end = 1;
        
        while(start < end && end < n+1)
        {
            int tmp = sum[end] - sum[start];
            
            if(tmp==n) {
                answer++;
                start++;
            }
            else if(tmp > n)
            {
                start++;
            }
            else{
                end++;
            }
        }
        
        return answer;
    }
}