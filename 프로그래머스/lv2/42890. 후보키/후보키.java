import java.util.*;

class Solution {
    public HashSet <String> ansList;
    public int attributes;
    public int tuples;
    public boolean [] isVisited;
    public int answer = 0;
    private String[][] relation;
    public int solution(String[][] relation) {
        attributes = relation[0].length;
        tuples = relation.length;
        ansList = new HashSet <String> ();
        isVisited = new boolean [attributes];
        this.relation = relation;
        
        for(int i=1; i<=attributes; i++)
        {
            dfs(relation, 0, i);
        }
        
        answer = ansList.size();
        return answer;
    }
    
    public void dfs(String[][] relation, int start, int r)
    {
        if(r==0)
        {
            String result = "";
            for(int i=0; i<attributes; i++)
            {
                if(isVisited[i]) result += i;
            }
            
            // 최소성 확인
            for(String ans: ansList) {
                int count = 0;
                for(int i=0; i<ans.length(); i++)
                {
                    if(result.contains(String.valueOf(ans.charAt(i)))) count++;
                }
                
                if(ans.length()==count) return;
            }
            
            //유일성 확인
            if(unique(result)) ansList.add(result);
        }
        
        for(int i=start; i<attributes; i++)
        {
            isVisited[i] = true;
            dfs(relation, i+1, r-1);
            isVisited[i] = false;
        }
    }
    
    
    public boolean unique(String indexs) {
        HashSet <String> hs = new HashSet <> ();
        
        for(String[] str: relation)
        {
            String tmp = "";
            for(int i=0; i<indexs.length(); i++)
            {
                int idx = indexs.charAt(i)-'0';
                tmp += str[idx] + "/";
            }
            
            if(hs.contains(tmp)) return false;
            else hs.add(tmp);
        }
        
        return true;
    }
}