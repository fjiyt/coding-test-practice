import java.util.*;

class Solution {
    public String solution(String number, int k) {
        String answer = "";
        Stack <Character> st = new Stack <> ();
        int i = 0;
        st.push(number.charAt(i));
        i++;
        while(i<number.length())
        {
            int next = number.charAt(i)-'0';
            while(!st.isEmpty() && k>0)
            {
                int num = st.peek()-'0';
                if(num < next)
                {
                    st.pop();
                    k--;
                }
                else break;
            }
            
            st.push(number.charAt(i));
            i++;
        }
        // 다 삭제가 안됐을경우
        while(k-->0)
        {
            st.pop();
        }

        while(!st.isEmpty())
        {
            answer += st.pop();
        }
        
        StringBuffer sb = new StringBuffer(answer);
        answer = sb.reverse().toString();
        return answer;
    }
}