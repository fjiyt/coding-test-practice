class Solution {
    public int solution(int[] a) {
        int answer = 0;
        int [] left = new int [a.length];
        int [] right = new int [a.length];
        
        left[0] = a[0];
        for(int i=1; i<a.length; i++)
        {
            left[i] = Math.min(left[i-1],a[i]);
        }
        
        right[a.length-1] = a[a.length-1];
        for(int i=a.length-2; i>=0; i--)
        {
            right[i] = Math.min(right[i+1], a[i]);
        }
        
        for(int i=0; i<a.length; i++)
        {
            int cnt = 0;
            if(left[i] < a[i]) cnt++;
            if(right[i] < a[i]) cnt++;
            
            if(cnt<2) answer++;
        }
        return answer;
    }
}