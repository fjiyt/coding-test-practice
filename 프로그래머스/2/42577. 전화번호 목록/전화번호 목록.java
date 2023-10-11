import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        HashSet <String> hs = new HashSet <> ();
        
        Arrays.sort(phone_book);
        for(int i=0; i<phone_book.length; i++)
        {
            String str = "";
            for(int j=0; j<phone_book[i].length(); j++)
            {
                str += phone_book[i].charAt(j);
                if(hs.contains(str)) {
                    return false;
                }
            }
            
            hs.add(str);
        }
        return true;
    }
}