import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.next();
        int [] location = new int[26];
        for(int i=0; i<26; i++)
        {
            location[i] = -1;
        }

        for(int i=0; i<str.length(); i++)
        {
            int idx = str.charAt(i)-'a';
            if(location[idx]==-1) location[idx] = i;
        }

        for(int val : location)
        {
            System.out.print(val + " ");
        }
    }
}
