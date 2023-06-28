import java.util.Stack;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        Stack <Integer> stack = new Stack <> ();
        for(int i=0; i<s.length(); i++)
        {
            char c = s.charAt(i);
            if(c=='(')
            {
                stack.push(c);
            }
            else if(c==')')
            {
                if(stack.empty()) {
                    answer=false;
                    break;
                }
                stack.pop();
            }
        }
        if(!stack.empty())
        {
            answer = false;
        }
        return answer;
    }
}