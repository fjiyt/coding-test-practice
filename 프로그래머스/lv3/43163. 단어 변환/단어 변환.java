import java.io.*;

class Solution {
    int answer = 0;
    boolean [] isVisited;
    
    public boolean isOneDiff(String start, String end)
    {
        int cnt = 0;
        for(int i=0; i<start.length(); i++)
        {
            if(start.charAt(i)!=end.charAt(i)) cnt++;
            //System.out.println(start.charAt(i) + " " + end.charAt(i));
        }
        if(cnt==1) return true;
        else return false;
    }
    public void dfs(String begin, String target, String [] words, int cnt)
    {
        if(begin.equals(target))
        {
            answer = cnt;
            return;
        }
        
        for(int i=0; i<words.length; i++)
        {
            if(isVisited[i]) continue;
            if(isOneDiff(begin, words[i]))
            {
                isVisited[i] = true;
                dfs(words[i], target, words, cnt+1);
                isVisited[i] = false;
            }
        }
        
    }
    
    public int solution(String begin, String target, String[] words) {
        isVisited = new boolean [words.length];
        dfs(begin, target, words, 0);
        return answer;
    }
}