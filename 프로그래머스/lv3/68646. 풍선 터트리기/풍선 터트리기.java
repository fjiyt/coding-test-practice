import java.util.*;

class Solution {
    public int solution(int[] a) {
        int answer = 0;
        
        HashSet <Integer> hs = new HashSet <> ();
        int min1 = Integer.MAX_VALUE;
        int min2 = Integer.MAX_VALUE;
        
        for(int i=0; i<a.length; i++)
        {
            min1 = Math.min(min1, a[i]);
            min2 = Math.min(min2, a[a.length-1-i]);
            
            hs.add(min1);
            hs.add(min2);
        }
        return hs.size();
    }
}