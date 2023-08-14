import java.util.*;

class Solution {
    public String answer;
    public String solution(String p) {
        answer = "";
        dfs(p);
        return answer;
    }
    public void dfs(String str)
    {
        int l = 0;
        int r = 0;
        String u ="";
        String v ="";
        
        if(str=="") return;
        for(int i=0; i<str.length(); i++)
        {
            if(str.charAt(i)=='(') l++;
            else if(str.charAt(i)==')') r++;
            if(l==r) {
                u = str.substring(0,i+1);
                v = str.substring(i+1,str.length());
                break;
            }
        }
                
        //u가 올바른 괄호인지 확인
        boolean alright = true;
        Stack <Integer> s = new Stack<>();
        for(int i=0; i<u.length(); i++)
        {
            if(u.charAt(i)=='(') s.add(0);
            else if(u.charAt(i)==')'){
                if(s.isEmpty()) {
                    alright = false;
                    break;
                }
                else {
                    s.pop();
                }
            }
        }

        if(alright) // 올바른 괄호 문자열
        {
            answer += u;
            dfs(v);
        }
        else{
            answer += "(";
            dfs(v);
            answer += ")";
            String tmp = u.substring(1, u.length()-1);
            for(int i=0; i<tmp.length(); i++)
            {
                if(tmp.charAt(i)=='(') answer += ")";
                else if(tmp.charAt(i)==')') answer += "(";
            }
        }
    }
}