// union-find
import java.io.*;
import java.util.*;

class Solution {
    int[] Parent;
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        Parent = new int[n+1];
        
        for(int i=1; i<=n; i++)
        {
            Parent[i] = i;
        }
        
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(computers[i][j]==1)
                {
                    int x= find(j+1);
                    int y = find(i+1);
                    if(x!=y)
                    {
                        Parent[x] = y;
                    }
                }
            }
        }
        
        ArrayList <Integer> arr = new ArrayList <>();
        for(int i=1; i<=n; i++)
        {
            if(!arr.contains(find(i)))
            {
                arr.add(find(i));
            }
        }
        answer = arr.size();
        return answer;
    }
    
    int find(int x)
    {
        if(Parent[x] == x){
            return x;
        }
        else{
            return Parent[x] = find(Parent[x]);
        }
    }
}