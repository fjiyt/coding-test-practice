import java.util.*;

class Solution {
    public boolean isPalindrome(String s) {
        StringBuffer sb = new StringBuffer();
        for(int i=0; i<s.length(); i++)
        {
            char c = s.charAt(i);
            if(c-'0' >=0 && c-'0'<=9)
            {
                sb.append(c);
            }
            else if(c-'A' >= 0 && c-'A' <=25)
            {
                sb.append((char)(c+32));
            }
            else if(c-'a' >= 0 && c-'a' <=25)
            {
                sb.append(c);
            }
        }

        if(sb.toString().equals(sb.reverse().toString())) return true;

        return false;
    }
}
