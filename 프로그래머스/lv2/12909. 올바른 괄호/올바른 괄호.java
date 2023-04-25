import java.util.Stack;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Stack <Character> st = new Stack<> ();
        for(int i=0; i<s.length(); i++)
        {
            char c = s.charAt(i);
            if(c=='(')
            {
                st.push(c);
            }
            else if(c==')')
            {
                if(st.empty()) {
                    answer = false;
                    break;
                }
                char tmp = st.peek();
                st.pop();
                if(tmp==')')
                {
                    answer = false;
                    break;
                }
            }
        }
        
        if(!st.empty())
        {
            answer = false;
        }

        return answer;
    }
}