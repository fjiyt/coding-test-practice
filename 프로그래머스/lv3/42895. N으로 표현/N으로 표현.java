import java.util.*;

class Solution {
    public int solution(int N, int number) {
        int answer = 0;
        List <Set<Integer>> countList = new ArrayList<> ();
        
        for(int i=0; i<9; i++)
        {
            countList.add(new HashSet<>());
        }
        
        countList.get(1).add(N);
        
        for(int i=2; i<9; i++)
        {
            Set <Integer> countSet = countList.get(i);
            
            for(int j=1; j<=i; j++)
            {
                Set <Integer> preSet = countList.get(i-j);
                Set <Integer> postSet = countList.get(j);
                
                for(int preNum : preSet) 
                {
                    for(int postNum : postSet)
                    {
                        countSet.add(preNum + postNum);
                        countSet.add(preNum - postNum);
                        countSet.add(preNum * postNum);
                        
                        if(preNum != 0 && postNum != 0)
                        {
                            countSet.add(preNum / postNum);
                        }
                    }
                }
            }
            countSet.add(Integer.parseInt(String.valueOf(N).repeat(i)));
        }
        
        for(Set <Integer> s : countList)
        {
            if(s.contains(number)) {
                return countList.indexOf(s);
            }
        }
        return -1;
    }
}