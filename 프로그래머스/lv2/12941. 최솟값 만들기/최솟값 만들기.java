import java.util.*;

class Solution
{
    public double solution(int []A, int []B)
    {
        double answer = 0;
        
        Arrays.sort(A);
        Arrays.sort(B);
        
        for(int i=0; i<A.length; i++)
        {
            answer += A[i] * B[B.length-1-i];
        }
        
        return answer;
    }
}